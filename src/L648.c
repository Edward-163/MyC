/*
 *
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"


/*
 (字符)前缀树==字典树=trie,总结这玩意容错率太低了
 */
typedef struct Trie {
    int isEnd;
    struct Trie *next[26];
} Trie;

Trie *create()
{
    Trie *t = (Trie *) malloc(sizeof(Trie));
    t->isEnd = 0;
    for (int i = 0; i < 26; ++i) {
        t->next[i] = NULL;
    }
    return t;
}

void insert(Trie *t, char *word)
{
    int move = 0;
    char c;
    while (word[move] != NULL) {
        /// a先插入,再插ab,ab其实再第一个字符数组[26]的时候就已经没必要往下插入'b'
        if (t->isEnd == 1) {
            return;
        }
        c = word[move];
        if (t->next[c - 'a'] == NULL) {
            t->next[c - 'a'] = create();
            /// bug 少了t的步进
            t = t->next[c - 'a'];
        } else {
            t = t->next[c - 'a'];
        }

        move++;
    }
    t->isEnd = 1;
}

char *g_ans;
int g_len;

void shortPre(Trie *t, char *split)
{
    int len = strlen(split);

    int move = 0;
    int addcharcount = 0;
    while (split[move] != NULL) {
        char c = split[move];
        // 根:a和ab split==abc,当找c时肯定找不到,break,准备往g_ans塞入"ab空格"
        if (t->next[c - 'a'] == NULL) {
            // 根:a和ab split==xab,一开始就找不到,那就不替换,准备往g_ans塞入"xab空格"
//            if (move == 0) {
            // 根:ab split==ac,刚开始g_ans补充了一个a,addcharcount==1,查找c的时候肯定找不到,准备往g_ans塞入"ac空格"
            /// bug g_ans+g_len
//                memcpy(g_ans, split, sizeof(char) * len);
            g_len -= addcharcount;
            memcpy(g_ans + g_len, split, sizeof(char) * len);
            /// bug memcpy后忘了g_len要自增
            g_len += len;
//            }
            break;
        } else {
            addcharcount++;
            g_ans[g_len++] = c;
            /// bug
//            if (t->isEnd == 1) {
            if (t->next[c - 'a']->isEnd == 1) {
                break;
            }
            t = t->next[c - 'a'];
        }

        move++;
    }
    g_ans[g_len++] = ' ';
    g_ans[g_len] = '\0';
}

char *replaceWords(char **dict, int dsize, char *sentence)
{
    Trie *t = create();
    for (int i = 0; i < dsize; ++i) {
        insert(t, dict[i]);
    }

//    g_ans = (char *) malloc(sizeof(char) * strlen(sentence)); // heap overflow
//    g_ans = (char *) malloc(sizeof(char) * 1003000);
    g_ans =  malloc(sizeof(char) * 1003000);
    g_len = 0;
    char *split = strtok(sentence, " ");
    while (split != NULL) {
        shortPre(t, split);
//        printf("%s\n", g_ans);fflush(stdout);
        split = strtok(NULL, " ");
    }
    g_ans[g_len - 1] = '\0';
    return g_ans;
}

int main()
{
    // @formatter:off
    /** 之前还在苦恼c的二维数组的动态列长度,今天误打误撞再套一层{},结果是可行的,猜测{}在c中就是返回指针的意思??,char str[]="hyj"
        char* str={"hyj"}; // 悟了悟了
     */
//    char* dict[]={{"a"},{"ab"},{"b"}};
    char* dict[]={{"cat"},{"bat"},{"rat"}};
    int size=sizeof(dict)/sizeof(dict[0]);
//    char* sentence={"the cattle was rattled by the battery"}; // "the cat was rat by the bat" 可以正常打印,但tok时会sig
//    char sentence[]="the cattle was rattled by the battery"; // "the cat was rat by the bat"
    char sentence[]="by the battery"; // "the cat was rat by the bat" 可以正常打印,但tok时会sig
    char *ans = replaceWords(dict,size,sentence);
    printf("%s \n",ans );fflush(stdout);
    return 0;
    // @formatter:on
}