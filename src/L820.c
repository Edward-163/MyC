#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
单词数组 words 的 有效编码 由任意助记字符串 s 和下标数组 indices 组成，且满足：

words.length == indices.length
助记字符串 s 以 '#' 字符结尾
对于每个下标 indices[i] ，s 的一个从 indices[i] 开始、到下一个 '#' 字符结束（但不包括 '#'）的 子字符串 恰好与 words[i] 相等
给你一个单词数组 words ，返回成功对 words 进行编码的最小助记字符串 s 的长度 。

示例 1：

输入：words = ["time", "me", "bell"]
输出：10
解释：一组有效编码为 s = "time#bell#" 和 indices = [0, 2, 5] 。
words[0] = "time" ，s 开始于 indices[0] = 0 到下一个 '#' 结束的子字符串，如加粗部分所示 "time#bell#"
words[1] = "me" ，s 开始于 indices[1] = 2 到下一个 '#' 结束的子字符串，如加粗部分所示 "time#bell#"
words[2] = "bell" ，s 开始于 indices[2] = 5 到下一个 '#' 结束的子字符串，如加粗部分所示 "time#bell#"
示例 2：

输入：words = ["t"]
输出：2
解释：一组有效编码为 s = "t#" 和 indices = [0]
 */
#define MAX 26
typedef struct Trie {
    int endFlag;
    struct Trie *next[MAX];
} Trie;

Trie *creat()
{
    Trie *t = malloc(sizeof(Trie));
    t->endFlag = 0;
    for (int i = 0; i < MAX; ++i) {
        t->next[i] = NULL; // 试下->和[]的优先级谁大?
    }
    return t;
}

void insert(Trie *t, char *word)
{
    int len = strlen(word);
    for (int move = len - 1; move >= 0; move--) {
        int c = word[move];
        if (t->next[c - 'a'] == NULL) {
            t->next[c - 'a'] = creat();
        }
        /// 步进
        t = t->next[c - 'a'];
    }
    t->endFlag = 1;
}

int g_ans;

void dfs(Trie *t, int len)
{
    bool allNull = true;
    for (int i = 0; i < MAX; ++i) {
        if (t->next[i] != NULL) {
            allNull = false;
            dfs(t->next[i], len + 1);
        }
    }
    if (allNull) {
        g_ans += len + 1;
    }
}

int minimumLengthEncoding(char **words, int wordsSize)
{
    Trie *t = creat();
    for (int i = 0; i < wordsSize; ++i) {
        insert(t, words[i]);
    }

    g_ans = 0;
    dfs(t, 0);
    return g_ans;
}

int main()
{
    // @formatter:off
//    char* arr[]={{"time"}, {"me"}, {"bell"}};
    char* arr[]={{"t"}};
    int size=sizeof(arr)/sizeof(arr[0]);
    int i = minimumLengthEncoding(arr, size);
    printf("%d \n",i );fflush(stdout);
    // @formatter:on
    return 0;
}