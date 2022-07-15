////
//// Created by h30029170 on 2022/5/17.
////
//#include <uthash.h>
//typedef struct{
//    int key;
//    int value;
//    UT_hash_handle hh;
//}HashList;
//int getIdxByChar(char c,HashList* g_hashlist){
//    HashList* tmp=NULL;
//    HASH_FIND_INT(g_hashlist,c-'a',tmp);
//    if(tmp!=NULL)return tmp->value;
//}
//bool isAlienSorted(char ** words, int wordsSize, char * order){
//    HashList* g_hashlist=NULL;
//    int orderLen=strlen(order);
//    for(int a=0;a<orderLen;a++){
//        HashList* tmp=(HashList*)malloc(sizeof(HashList));
//        tmp->key=order[a]-'a';
//        tmp->value=a;
//        HASH_ADD_INT(g_hashlist,&(order[a]-'a'),tmp);
//    }
//
//    for(int b=0;b<wordsSize-1;b++){
//        int c=b+1;
//        char* str=words[b];
//        char* str2=words[c];
//        int idx=0;
//        while(true){
//            if(idx>strlen(str)){
//                break;
//            }
//            if(idx>strlen(str2)){
//                return false;
//            }
//            int cidx=getIdxByChar(str[idx],g_hashlist);
//            int cidx2=getIdxByChar(str2[idx],g_hashlist);
//            if(cidx<cidx2){
//                idx++;
//            }else{
//                return false;
//            }
//        }
//
//    }
//    return true;
//}