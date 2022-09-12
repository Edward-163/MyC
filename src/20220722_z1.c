#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include "securec.h"
/*
 题目描述
假设一个简易的变长编码规则XUTF：每个字符有一个唯一编号值 unicodeVal（如汉字“华”的编号十进制值是21326），使用1~6个字节进行编码，编码规则如下：
编码格式：
编号值范围
编码后字节长度n
二进制格式（x 表示有效位，其它为固定位）
[0, 2^7)
1字节
1xxxxxxx
[2^7, 2^11)
2字节
001xxxxx 01xxxxxx
[2^11, 2^16)
3字节
0001xxxx 01xxxxxx 01xxxxxx
[2^16, 2^21)
4字节
00001xxx 01xxxxxx 01xxxxxx 01xxxxxx
[2^21, 2^26)
5字节
000001xx 01xxxxxx 01xxxxxx 01xxxxxx 01xxxxxx
[2^26, 2^31)
6字节
0000001x 01xxxxxx 01xxxxxx 01xxxxxx 01xxxxxx 01xxxxxx
单字节字符 (即 n = 1)：字节的第一位（bit）为 1 ，其余位为有效位。
多字节字符 (即 n > 1)：第一个字节的前 n 位都为 0，第 n+1 位为 1，后面字节的前两位都为 01，其余位为有效位。
编码过程：参考编号值范围，根据 unicodeVal 值判断需要几个字节进行编码，然后依次把 unicodeVal 的二进制比特填充到二进制格式中的有效位上：右侧对齐、左侧补 0 ；注意：固定位不变。
现给定某个字符的十进制编号值 unicodeVal，请按XUTF编码规则对该字符进行编码，输出编码后的十六进制字符串（大写）。
解答要求时间限制：1000ms, 内存限制：256MB
输入
一个十进制整数 unicodeVal，表示某字符的编号值，0 <= unicodeVal < 2^31
输出
一个十六进制字符串，表示该字符的XUTF编码
仅由字符0~9 和 A~F组成，每个长度范围为[2,12]且为偶数（长度奇数时前面补充一个前导字符0）
样例
输入样例 1
21326
输出样例 1
154D4E
提示样例 1
字符编号值 21326 按XUTF编码表示范围，需要3个字节； 把21326的二进制101001101001110比特依次填充到有效位：填充时右侧对齐，左侧有1个有效位未填充，补为 0，示意如下图：
http://oj.rnd.huawei.com/public/upload/478c60f6fb.png
转换为十六进制为154D4E
 
输入样例 2
34
输出样例 2
A2
提示样例 2
编号值34的二进制为 100010，需要一个字节，编码后二进制为 10100010，十六进制为 A2
 
输入样例 3
1225859
输出样例 3
0C6B5243
提示样例 3
编码后的十六进制字符串，长度为奇数，因此前面补充一个前导字符 0
 */
#define MAX_OUTPUT_LEN 13
// 待实现函数，在此函数中填入答题代码
// 生成的信息列表存于outBuf中，outBufLen是最大数组长度
#define MAX_CODE_LEN 6
#define CODE_BITS_PER_BYTE 6
#define CUR_ENCODE_MASK 0x3F
static void XutfEncoding(unsigned int unicodeVal, char outBuf[], int outBufLen)
{
    uint32_t step[] = {0x80, 0x800, 0x10000, 0x200000, 0x4000000, 0x80000000};
    uint8_t firstByteMask[] = {0x80, 0x20, 0x10, 0x8, 0x4, 0x2};
    uint8_t otherByteMask = 0x40;
    int i = 0;
    for (; i < sizeof(step)/sizeof(uint32_t); i++) {
        if (unicodeVal < step[i]) {
            break;
        }
    }
    int len = i + 1;
    uint8_t code[MAX_CODE_LEN] = {0};
    for (int j = len - 1; j > 0; j--) {
        uint32_t tmp = unicodeVal & CUR_ENCODE_MASK;
        code[j] = (uint8_t)tmp | otherByteMask;
        unicodeVal >>= CODE_BITS_PER_BYTE;
    }
    code[0] = firstByteMask[i] | unicodeVal;
    for (i = 0; i < len; i++) {
        sprintf_s(outBuf + i * 2, outBufLen - i, "%02X", code[i]);
    }
    outBuf[i * 2 + 1] = '\0';
    return;
}
int main(void)
{
    unsigned int unicodeVal;
    if (scanf_s("%u", &unicodeVal) != 1) { return -1; }
    char outBuf[MAX_OUTPUT_LEN] = { 0 };
    XutfEncoding(unicodeVal, outBuf, MAX_OUTPUT_LEN);
    printf("%s", outBuf);
    return 0;
}