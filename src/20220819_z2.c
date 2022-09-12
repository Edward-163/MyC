#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include "securec.h"
/*
 
 */
#define MAX_THREAD_NUM 10
#define MAX_STR_LEN 18
#define MAX_COMMAND_SIZE 100
#define MAX_OUTPUT_SIZE 1000 // 每个线程的每个数据块都存在竞争,虽然不可能,但直接10*100拉倒
typedef struct {
    // 表示每个线程的指令长度
    int size;
    // 例：指令为 read(para)，则解析后 data[i][0] = "read", data[i][1] = "para"；write 命令类似
    // 例：指令为 lock，则解析后 data[i][0] = "lock", data[i][1]值无效；unlock 命令类似
    char data[MAX_COMMAND_SIZE][2][MAX_STR_LEN];
} ThreadCommand;
bool IfSatify(int threadNum, const ThreadCommand *allIns, char *memory, int threadIndex, bool isLock)
{
    bool otherLock = false;
    for (int k = 0; k < threadNum; k++) {
        if (k == threadIndex) {
            continue;
        }
        for (int j = 0; j < allIns[k].size; j++) {
            if (strcmp(allIns[k].data[j][0], "lock") == 0) {
                otherLock = true;
            } else if (strcmp(allIns[k].data[j][0], "unlock") == 0) {
                otherLock = false;
            }
            if (strcmp(allIns[k].data[j][1], memory) == 0) {
                if (!isLock) {
                    return true;
                }
                if (!otherLock) {
                    return true;
                }
            }
        }
    }
    return false;
}
int MyCmp(const void *a, const void *b)
{
    return (strcmp((char *)a, (char *)b));
}
bool IsExit(char *memory, int size, char outBuf[][MAX_STR_LEN]) // 判断该数据库是不是已经在outBuf中了
{
    for (int k = 0; k < size; k++) {
        if (strcmp(memory, outBuf[k]) == 0) {
            return true;
        }
    }
    return false;
}
// 待实现函数，请在此填入答题代码。
// 生成的信息列表存于outBuf中，outBufLen是最大数组长度，返回值为实际长度。   应该传入int*,感觉outBufLen是在挖坑呀
static int GetDataRaces(int threadNum, const ThreadCommand *allIns, char outBuf[][MAX_STR_LEN], int outBufLen)
{
    int outPutSize = 0;
    bool isLock = false;
    for (int i = 0; i < threadNum; i++) {
        for (int j = 0; j < allIns[i].size; j++) {
            if (strcmp(allIns[i].data[j][0], "lock") == 0) {
                isLock = true;
            } else if (strcmp(allIns[i].data[j][0], "unlock") == 0) {
                isLock = false;
            }
            if (strcmp(allIns[i].data[j][0], "write") == 0 && !IsExit(allIns[i].data[j][1], outPutSize, outBuf)) {
                if (IfSatify(threadNum, allIns, allIns[i].data[j][1], i, isLock)) {
                    (void)sprintf_s(outBuf[outPutSize], MAX_STR_LEN, "%s", allIns[i].data[j][1]);
                    outPutSize++;
                }
            }
        }
    }
    qsort(outBuf, outPutSize, MAX_STR_LEN, MyCmp);
    return outPutSize;
}
// 以下为考题输入输出框架，此部分代码不建议改动
static int GetDataPara(const char *inputStr, char *para1, char *para2)
{
    // lock and unlock
    if (inputStr[0] == 'l' || inputStr[0] == 'u') {
        if (strncpy_s(para1, MAX_STR_LEN, inputStr, strlen(inputStr)) != EOK) { return -1; } // succ返0,其他返非0
        return 0;
    }
    static char *cmd[] = {"read", "write"};
    if (inputStr[0] == 'r') {
        if (strncpy_s(para1, MAX_STR_LEN, cmd[0], strlen(cmd[0])) != EOK) { return -1; }
        if (strncpy_s(para2, MAX_STR_LEN, inputStr + 5, strlen(inputStr) - 6) != EOK) { return -1; }
    } else {
        if (strncpy_s(para1, MAX_STR_LEN, cmd[1], strlen(cmd[1])) != EOK) { return -1; }
        if (strncpy_s(para2, MAX_STR_LEN, inputStr + 6, strlen(inputStr) - 7) != EOK) { return -1; }
    }
    return 0;
}
int main(void)
{
    int threadNum;
    if (scanf_s("%d", &threadNum) != 1) { return -1; } // 返回的同时检验,简洁
    static ThreadCommand allIns[MAX_THREAD_NUM]; // 我刚开始用3维数组,后来自己都写蒙了,参数解析这块就死掉了,
    for (int i = 0; i < threadNum; i++) {
        if (scanf_s("%d", &allIns[i].size) != 1) { return -1; }
        for (int j = 0; j < allIns[i].size; ++j) {
            char inputStr[MAX_STR_LEN];
            if (scanf_s("%s", inputStr, sizeof(inputStr)) != 1) { return -1; } // scanf_s对于数组要追加读取其字节长度,sizeof稳妥
            if (GetDataPara(inputStr, allIns[i].data[j][0], allIns[i].data[j][1]) == -1) {
                return -1;
            }
        }
    }
    static char outBuf[MAX_OUTPUT_SIZE][MAX_STR_LEN] = { 0 };
    int outBufSize = GetDataRaces(threadNum, allIns, outBuf, MAX_OUTPUT_SIZE);
    printf("[");
    for (int i = 0; i < outBufSize; i++) {
        printf("%s%s", (i == 0 ? "" : " "), outBuf[i]);
    }
    printf("]");
    return 0;
}
/*
2
4 read(para) write(msg) read(para) write(port)
7 write(port) lock read(msg) unlock write(buff) read(buff) read(para)
输出样例 1
[msg port]

3
7 read(apple) lock write(banana) unlock lock write(banana) unlock
5 read(orange) lock read(banana) write(orange) unlock
4 lock read(orange) unlock read(apple)
输出样例 2
[]

3
4 lock read(a) write(a) unlock
6 lock read(a) unlock read(a) write(b) read(b)
3 lock write(a) unlock
输出样例 3
[a]
 */