#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N "Neither"
#define V4 "IPv4"
#define V6 "IPv6"

#define NEITHER    "Neither"
#define IPV4       "IPv4"
#define IPV6       "IPv6"

typedef enum {
    M_IPV4,
    M_IPV6,
    M_NEITHER
} MTYPE;

int CheckIpNode(char * IP, int ipLen) {
    int sum1 = 0;
    int sum2 = 0;
    int num= 0;
    for(int i = 0; i < ipLen; i++) {
        if(isdigit(IP[i])) {
            continue;
        }
        if(IP[i] =='.' ) {
            sum1 ++;
        }
        else if(IP[i] ==':' ) {
            sum2 ++;
        }
        else if(isalpha(IP[i])) {
            if((IP[i] <= 'F' && IP[i] >= 'A') || (IP[i] <= 'f' && IP[i] >= 'a')) {
                num ++;
            }
            else {
                return M_NEITHER;
            }

        }
        else {
            return M_NEITHER;
        }
    }

    if(sum1 == 3 && sum2 == 0 && num == 0) {
        return M_IPV4;
    }
    if(sum1 == 0 && sum2 == 7) {
        return M_IPV6;
    }
    return M_NEITHER;
}

char * validIPAddress(char * IP){
    int ipLen = strlen(IP);
    MTYPE type = CheckIpNode(IP, ipLen);
    int num = 0;
    if(type == M_IPV4) {
        char* p = strtok(IP, ".");
        while(p != NULL) {
            if(p[0] == '0' && strlen(p) > 1) {
                break;
            }
            int value = 0;
            sscanf(p, "%d", &value);

            if(value < 0 || value >= 256) {
                break;
            }
            num ++;
            p = strtok(NULL, ".");
        }
        if(num == 4)
            return IPV4;
    }
    else if(type == M_IPV6) {
        char* p = strtok(IP, ":");
        while(p != NULL) {
            int len = strlen(p);
            if(len > 4) {
                break;
            }
            int value = 0;
            sscanf(p, "%x", &value);
            num ++;
            p = strtok(NULL, ":");
        }
        if(num == 8)
            return IPV6;
    }

    return NEITHER;
}

/**
 strtok
    1. 尽量使用可重入版的strtok，Windows平台下为strtok_s，Linux平台下为strtok_r。
    2. 牢记strtok函数族的分隔规则：忽略字符串前后的分隔符，连续的分隔符被当做一个处理。
    3. 在使用strtok前，请对源字符串进行备份，除非你可以接受字符串被修改这一事实。
 */
char * validIPAddress2(char * queryIP){
    if(strchr(queryIP,'.')!=NULL && strchr(queryIP,':')!=NULL)return N;
    char* queryCpy=queryIP;
    char* split=strtok(queryIP,".");//strtok会改变原指针
    int rightNumCount=0;
    while(split!=NULL){
        ///bug c语言的这么判断都不行??!!
        if(strcmp(split,"")==0)return N;
        int slen=strlen(split);
        if(slen>1 && split[0]=='0')break;
        if(slen>3)break;
        int num=atoi(split);
        if(num>255)break;
        rightNumCount++;
        if(rightNumCount>4)break;
        split=strtok(NULL,".");
    }

    if(rightNumCount==4)return V4;

    int count6=0;
    char* sp6=strtok(queryCpy,":");
    while(sp6!=NULL){
        if(strcmp(sp6,"")==0)return N;
        int slen=strlen(sp6);
        if(slen>4)break;
        int num=atoi(sp6);
        if(num>16*16*16*16-1)break;
        count6++;
        if(count6>8)break;
        sp6=strtok(NULL,":");

//        int len = strlen(sp6);
//        if(len > 4) {
//            break;
//        }
//        int value = 0;
//        sscanf(sp6, "%x", &value);
//        count6 ++;
//        sp6 = strtok(NULL, ":");
    }
    if(count6==8)return V6;

    return N;
}

int main(){
//    char* str="1..";
//    char str[]="1.1..";
//    char str[]="2001:0db8:85a3:0:0:8A2E:0370:7334::1";
    char str[]="7334::1";
//    printf("%s",validIPAddress(str));

    char* sp=strtok(str,":");
    while(sp!=NULL){
//        if(*sp=='')printf("666");
        printf("-%s\n",sp);
//        if(*sp=="")printf("666\n");
        fflush(stdout);
        sp = strtok(NULL, ":");
    }
    return 0;
}