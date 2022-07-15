#include <stdio.h>
#include <string.h>
int minOperations(char * s){
    //所幸0101...和1010...就2种情况
    int len=strlen(s);
    int count01=0;
    int count10=0;
    for(int a=0;a<len;a++){
        if((a&1)==1){
            if(s[a]!='1')count01++;
            if(s[a]!='0')count10++;
        }else{
            if(s[a]!='0')count01++;
            if(s[a]!='1')count10++;
        }
    }

    return count01<count10?count01:count10;
}
int main(){
    char* s="0100";
    printf("%d",minOperations(s));
    return 0;
}