#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 合法 mac 地址以字符串表示时，由 12 位十六进制字符组成，由 12 位个连续的十六进制字符组成，每两个字符之间被用-或:分割
合法的十六进制字符包括 0-9, a-f, A-F，；同一个 mac 中出现的字母可以大小写混用-字母不区分大小写
一个 mac 地址中，- 与 : 不能混用
相同 mac 地址需去重统计；注意，仅大小写、分割符不同的两个mac地址字符串视为相同，如 aa-bb-12-cc-dd-ee 与 Aa:bB:12:CC:dd:ee 视为相同。
例如下面都不是合法的mac地址：
aa-bb-2-cc-dd-ee-11 // 不是，因为2不是两个字符
aa-bb-22-cc-dd-eG-11 // 不是，字符G不在十六进制字符范围内
aa-bb-22-09808980-12-12 // 不是，09808980超过两个字符了
    输入 01-02-03-04-05-06-07
    输出 2
包含2个合法的 mac 地址01-02-03-04-05-06和02-03-04-05-06-07
    输入 0a-0a-0a-0a-0a-0a-0A
    输出  1
包含 mac 地址0a-0a-0a-0a-0a-0a和0a-0a-0a-0a-0a-0A, 去重后返回为1
 */

#define BUF_LEN 1001
typedef struct{
    char* key;
    UT_hash_handle hh;
}Hash;
Hash* g_hash;
int GetMacNum(char *str)
{
    // 在此添加你的代码
    g_hash=NULL;

    int len=strlen(str);
    str[len]='.';
    str[len+1]='\0';
    len++;
    int arr[len];//val代表合法的段数
    for(int a=0;a<len;a++){
        arr[a]=0;
    }

    for(int a=0;a<len && a+1<len && a+2<len;a+=3){
        bool legal=true;
        for(int b=a;b<=a+1;b++){
            if('A'<=str[b] && str[b]<='F'){
                str[b]=str[b]-'A'+'a';
            }else if('a'<=str[b] && str[b]<='f'){
                continue;
            }else if('0'<=str[b] && str[b]<='9'){
                continue;
            }else{
                legal=false;
                break;
            }
        }
        if(str[a+2]!='-' && str[a+2]!=':'){
            legal=false;
        }
        if(legal==true){
            if(a-1<0){//开头,若合法算一段
                arr[a]=1;
                arr[a+1]=1;
                arr[a+2]=1;
            }else{
                //非开头,后段与前段同分隔符,此后段段数==前段段数+1,or后段最后一个字符是. 就当它是通配吧
                if(str[a+2]==str[a-1] || str[a+2]=='.'){
                    arr[a]=arr[a-1]+1;
                    arr[a+1]=arr[a-1]+1;
                    arr[a+2]=arr[a-1]+1;
                }else{
                    arr[a]=1;
                    arr[a+1]=1;
                    arr[a+2]=1;
                }
            }
        }
    }

    for(int a=17;a<len && arr[a]>=6;a+=3){
        char* substr=(char*)malloc(sizeof(char)*18);
        memcpy(substr,str+(a-17),sizeof(char)*18);
        Hash* tmp=NULL;
        HASH_FIND_STR(g_hash, substr, tmp);
        if(tmp==NULL){
            tmp=(Hash*)malloc(sizeof(Hash));
            tmp->key=substr;
            HASH_ADD_STR(g_hash, key, tmp);
        }
    }

    return HASH_COUNT(g_hash);
}

/* 代码仅供参考，注意避免圈复杂度过大 */
int main(void)
{
//    fix2
//    char ch[20];
//    printf("请输入你的名字：\n");
//    //gets_s用法：gets_s(buffer,size);
//    //推荐用字符数组长度-1作为size（留空'\0'）
//    gets_s(ch,20-1);
//    printf("这是你的名字：%s\n", ch);
//
//    static char buf[BUF_LEN];
//    if (gets_s(buf, sizeof(buf)) == NULL) { return -1; }

    char buf[]="0a-0a-0a-0a-0a-0a-0A";
    int ret = GetMacNum(buf);
    (void)printf("%d", ret);
    return 0;
}