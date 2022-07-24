#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
/*
 
 */
#define MAX_N 10001
#define BUF_LEN 32
// 待实现函数，在此函数中填入答题代码
int RouterSearch(char *dstIp, char **ipTable, int ipTableCnt, char *outputStr, int outputLen) {
    int dst[4];
    int ip[4];
    int m;
    int max_m = -1;
    int x = 0;
    int y = 0;
    outputStr[0] = '\0';
//    sscanf_s(dstIp, "%d.%d.%d.%d", &dst[0], &dst[1], &dst[2], &dst[3]);
    /**
     char str[]="hh yy jj";
     sscanf(str,"%s %s %s",&hyj,&hyj2,&hyj3);//从str中安格式读取数据
     返回成功匹配和赋值的个数。如果到达文件末尾或发生读错误，则返回 EOF
     */
    sscanf(dstIp, "%d.%d.%d.%d", &dst[0], &dst[1], &dst[2], &dst[3]);
    for (int i = 0; i < 4; i++) {
        x = (x << 8) + dst[i];
    }
    for (int i = 0; i < ipTableCnt; i++) {
        sscanf_s(ipTable[i], "%d.%d.%d.%d/%d", &ip[0], &ip[1], &ip[2], &ip[3], &m);
        for (int i = 0; i < 4; i++) {
            y = (y << 8) + ip[i];
        }
        int mask = m ? -1 << (32 - m) : 0;
        int a = x & mask;
        int b = y & mask;
        if (a == b && m > max_m) {
//            sprintf_s(outputStr, BUF_LEN, "%s", ipTable[i]);
            sprintf(outputStr,  "%s", ipTable[i]);
            max_m = m;
        }
    }
    if (outputStr[0] == '\0') {
//        sprintf_s(outputStr, BUF_LEN, "empty");
        sprintf(outputStr,  "empty");
    }
    return -1;
}
/* 代码仅供参考，注意避免圈复杂度过大 */
int main(void) {
    static char dstIp[BUF_LEN];
//    if (gets_s(dstIp, sizeof(dstIp)) == NULL) { return -1; }//undefined reference to `gets_s'
    /// 从stdin读一行并存入char* buffer中
    if (gets(dstIp) == NULL) { return -1; }
    int n;
//    if (scanf_s("%d\n", &n) != 1) { return -1; }
    /**
     从stdin中按格式读取数据
     返回成功匹配和赋值的个数。如果到达文件末尾或发生读错误，则返回 EOF
     */
    if (scanf("%d\n", &n) != 1) { return -1; }//
    static char ipTableBuf[MAX_N][BUF_LEN];
    static char *ipTable[MAX_N];
    int i;
    for (i = 0; i < n; i++) {
        char *buf = ipTableBuf[i];
        int bufLen = sizeof(ipTableBuf[i]);
//        if (gets_s(buf, bufLen) == NULL) { return -1; }
        if (gets(buf) == NULL) { return -1; }
        ipTable[i] = buf;
    }
    char outputStr[BUF_LEN] = {0};
    int ret = RouterSearch(dstIp, ipTable, n, outputStr, BUF_LEN);
    (void) printf("%s", outputStr);
    return 0;
}