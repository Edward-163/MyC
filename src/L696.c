#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int countBinarySubstrings(char * s){
    int len=strlen(s);
    int* arr=(int*)malloc(sizeof(int)*len);
    int aidx=0;

    for(int a=0;a<len;a++){
        int count=1;
        int aa=a;
        while(aa+1<len && s[aa+1]==s[a]){
            count++;
            aa++;
        }
        a=a+count-1;
        arr[aidx++]=count;
    }

    int res=0;
    for(int a=0;a<aidx-1;a++){
        res+=arr[a]<arr[a+1]?arr[a]:arr[a+1];
    }
    return res;
}
int main(){
    char* s="00110011";
    printf("%d",    countBinarySubstrings(s));
    return 0;
}