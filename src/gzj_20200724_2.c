#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 给定一个字符串words，比如"abbbccdbbee",字符串是弹性的（所谓弹性，就是相邻的相同的字符可以被简化到只剩一个（也可以不简化），
 如words可简化为 “abcdbe”, “abbcdbbe”，…），然后给定一个字符串数组dic，求dic数组有多少字符串可有words弹性得到？（假定字符串的长度均小于1000）
 words=="abbbccdbbee"
 dic={“abcdbe”, “abbcdbbe”}     输出2
 dic={“abcdbe”, “abbcdbbe”,"aabbccdbbee","a"}     输出2
 */

#define MAX_LEN 1000

int numOfStr(char* words,char** dic,int dicSize){
    //把word按"弹性段"分段,如abbbccdbbee分为6段,abbaa分为3段,我把这些数字定义为段实际len
    int wlen=strlen(words);
    int darr[MAX_LEN]={0};
    int dlen=0;//段实际len
    for (int a = 0; a < wlen; ++a) {
        //a==0单独算一段or当出现某个字符不同于前字符时,又算新增一段
        if(a==0 || words[a]!=words[a-1]){
            dlen++;
        }
        //darr[i]代表第i+1段有多少个字符
        darr[dlen-1]++;
    }

    int res=0;
    for (int c = 0; c < dicSize; ++c) {
        char* dicc=dic[c];
        int diccLen=strlen(dicc);
        int i=0;//代表dicc可以分为几段
        int val=0;//代表当前段有多少个字符
        bool flag=true;//代表这个dicc可以由words压缩而来
        for (int a = 0; a < diccLen; ++a) {
            ///bug dicc写成words
            //if(a == 0 || words[a] != words[a - 1]){
            //a==0单独算一段or当出现某个字符不同于前字符时,又算新增一段
            if(a == 0 || dicc[a] != dicc[a - 1]){
                i++;
                val=0;
            }
            val++;
            //注意书写顺序关系到越界bug,当前段含有的字符过多or原words只有6段,而dicc能分为7段就离谱
            if(i>dlen || val>darr[i-1]){
                flag=false;
                break;
            }
        }
        if(i<dlen)flag=false;//原words只有6段,而dicc能分为5段就离谱
        if(flag)res++;
    }

    return res;
}

int main() {
    char words[]="abbbccdbbee";
    char arr[][MAX_LEN]={"a","abbccdbbee","abcdbe", "abbcdbbe"};
    int dicSize= sizeof(arr) / sizeof(arr[0]);
    char* dic[dicSize];
    for(int a=0;a<dicSize;a++){
        dic[a]=arr[a];
    }
    printf("%d", numOfStr(words, dic, dicSize));
    fflush(stdout);
    return 0;
}


/*
typedef struct tagWordInfo{
    int cnt;
    char ch;
}WordInfo;

//给传入的wordInfo[]赋值,
void makeWordsInfo(char* words,WordInfo* wordInfo,int wordInfoSize,int* used){
    int len=strlen(words);
    char now=words[0];
    int count=0;
    int index;
    int wordInfoLen=0;
    for(index=0;index<len;index++){
        if(wordInfoLen > wordInfoSize)return;//有必要??

        if(now==words[index]){
            count++;
            continue;
        }
        wordInfo[wordInfoLen].cnt=count;
        wordInfo[wordInfoLen].ch=now;
        now = words[index];
        count=1;
        wordInfoLen++;
    }

    wordInfo[wordInfoLen].cnt=count;
    wordInfo[wordInfoLen].ch=now;
    wordInfoLen++;
    *used=wordInfoLen;
}
bool isValidDir(WordInfo* wordInfo,int wordInfoUsed,WordInfo*dic,int dicUsed){
    if(wordInfoUsed!=dicUsed)return false;

    for (int i = 0; i < wordInfoUsed; i++) {
        if(wordInfo[i].ch!=dic[i].ch)return false;
        if(wordInfo[i].cnt<dic[i].cnt)return false;
    }
    return true;
}
int numOfStr(char* words,char** dic,int dicSize){
    WordInfo wordInfo[MAX_LEN] = {0};
    int wordUsed=0;
    int dicUsed=0;
    int matchCnt=0;

    makeWordsInfo(words,wordInfo,MAX_LEN,&wordUsed);//解析原words,解析成ch-ch使用次数

    for(int a=0;a<dicSize;a++){
        WordInfo dicNow[MAX_LEN] = {0};
        makeWordsInfo(dic[a],dicNow,MAX_LEN,&dicUsed);//解析每个dic元素,解析成ch-ch使用次数

        if(isValidDir(wordInfo,wordUsed,dicNow,dicUsed))
            matchCnt++;//看到这读懂了,原作者就是暴力
    }
    return matchCnt;
}
 */