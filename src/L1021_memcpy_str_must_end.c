#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

char * removeOuterParentheses(char * s){
    int len=strlen(s);
    int lidx=-1;
    int ridx=-1;
    int stacknum=0;
    char * res=(char*)malloc(sizeof(char)*len);

    int rescopyidx=0;
    char* rescopy=res;
    for(int a=0;a<len;a++){
        if(s[a]=='(')stacknum--;
        if(s[a]==')')stacknum++;
        if(stacknum==0){
            ridx=a;
            // l    r
            // -1 0 1
            //    ( )
            //strcpy(*desc,*src);//
            int newlen=ridx-lidx;
            memcpy(&rescopy[rescopyidx],&s[lidx+2],sizeof(char)*(newlen-2));
            rescopyidx+=newlen-2;
            lidx=ridx;
        }
    }

    ///bug:没写str的结尾符
    ///bug:自己设定respcopyidx从0开始,假设第一个新增长度为2,说明下标为2的时候就是\0
    //res[rescopyidx + 1] = '\0';
    res[rescopyidx] = '\0';
    return res;
}

int main(){
//    char g_arr[]="(())(())";
//    char g_arr[]="()()";
    char arr[]="(()())(())";
    char * res=removeOuterParentheses(arr);
    printf("%s",res);
    return 0;
}