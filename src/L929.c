#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"


/*

 */
typedef struct{
    char* key;
    UT_hash_handle hh;
}Hash;
int numUniqueEmails(char ** emails, int emailsSize){
    Hash* hash=NULL;
    for (int a = 0; a < emailsSize; ++a){
        int mailLen = strlen(emails[a]);
        char str[100];
        int slen=0;
        for (int b = 0; b < mailLen; ++b) {
            if(emails[a][b]=='+' || emails[a][b]=='@')break;

            if(emails[a][b]!='.'){
                str[slen++]=emails[a][b];
            }

        }
        //第三参数是多参,如sprintf(char* "%s%s",char* p1,char* p2)
        sprintf(str+slen,"%s",strchr(emails[a],'@'));
        Hash* tmp=NULL;
        HASH_FIND_STR(hash,str,tmp);
        if(tmp==NULL){
            tmp=(Hash*)malloc(sizeof(Hash));
            tmp->key=str;
            HASH_ADD_STR(hash,key,tmp);
        }
    }

    return HASH_COUNT(hash);
}
int main() {

    return 0;
}