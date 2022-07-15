#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include <regex.h>

/*
 
 */
/**
 *
 * @return 最长匹配长度
 */

int fn(char* ip,char* route){
    char *string = strrchr(route, '/');
    int count = atoi(string + 1);

    *string='\0';
    char *rsplit = strtok(route, ".");
    /// bug:牢记C语言的str末尾需要\0
    char* routebinary=(char*)malloc(sizeof(char)*33);
    routebinary[32]='\0';
    int routebidx=0;
    while(rsplit != NULL){
        int i1 = atoi(rsplit);
        char* buf=(char*)malloc(sizeof(char)*8);
        char *string2 = itoa(i1, buf, 2);
        int len2=strlen(string2);
        for (int i = 0; i < 8 -len2 ; ++i){
            routebinary[routebidx++]='0';
        }
        memcpy(routebinary+routebidx,string2,sizeof(char)*len2);
        routebidx+=len2;
        /// bug忘掉了不会写
        rsplit= strtok(NULL,".");
    }
    printf("%s \n", routebinary);fflush(stdout);

    char *ipsplit = strtok(ip, ".");
    char* ipbinary=(char*)malloc(sizeof(char)*33);
    ipbinary[32]='\0';
    int ipbidx=0;
    while(ipsplit != NULL){
        int i1 = atoi(ipsplit);
        char* buf=(char*)malloc(sizeof(char)*8);
        char *string2 = itoa(i1, buf, 2);
        int len2=strlen(string2);
        for (int i = 0; i < 8 -len2 ; ++i){
            ipbinary[ipbidx++]='0';
        }
        memcpy(ipbinary+ipbidx,string2,sizeof(char)*len2);
        ipbidx+=len2;

        ipsplit= strtok(NULL,".");
    }
    printf("%s \n", ipbinary);fflush(stdout);

    int c=0;
    for (; c < count; ++c){
        /// bug:当下面条件永远不成立时,怎么打断点都不会进内部(这是最坑的,光看现象十分诡异,c从0直接跳到count,让我一度怀疑for循环也能写错??!!),c会直接累加到count
//        if(routebinary[c] != routebinary[c]){
        if(ipbinary[c] != routebinary[c]){
            break;
        }
    }

    return c;
}
int main() {
    /*
        192.168.0.3
        6
        10.166.50.0/23
        192.0.0.0/8
        10.255.255.255/32
        192.168.0.1/24
        127.0.0.0/8
        192.168.0.0/24
     */
    /// bug:写成指针就sig
//    char* ip="192.168.0.3";
//    char* route="192.168.0.1/24";
    char ip[]="192.168.0.3";
    char route[]="192.168.0.1/24";
//    char route[]="192.168.0.0/24";
//    char route[]="10.166.50.0/23";
    char *string = strrchr(route, '/');///     /24
    printf("%s ", string);fflush(stdout);
    printf("%d \n", fn(ip,route));fflush(stdout);
    return 0;
}