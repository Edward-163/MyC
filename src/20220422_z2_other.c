#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include "securec.h"
/*
 
 */
#define MAX_ROW_SIZE 20
#define MAX_COL_SIZE 26
#define MAX_STR_LEN 10

int GetOneValue(const char values[][MAX_COL_SIZE][MAX_STR_LEN], char *str)
{
    if (isdigit(str[0])) {
        return strtol(str, NULL, 10);
    }
    int col = str[0] - 'A';
    int row = strtol(str + 1, NULL, 10) - 1;
    int value = strtol(values[row][col], NULL, 10);
    return value;
}

int GetDigit(const char values[][MAX_COL_SIZE][MAX_STR_LEN], int row, int col)
{
    if (isdigit(values[row][col][0])) {
        return strtol(values[row][col], NULL, 10);
    }
    char *str = values[row][col];
    str += 1;
    char *connext = NULL;
    if (strchr(str, '+')) {
        char *right = NULL;
        char *left = strtok_s(str, "+", &connext);
        if (left != NULL) {
            right = strtok_s(NULL, "+", &connext);
        }
        return GetOneValue(values, left) + GetOneValue(values, right);
    } else if (strchr(str, '-')) {
        char *right = NULL;
        char *left = strtok_s(str, "-", &connext);
        if (left != NULL) {
            right = strtok_s(NULL, "-", &connext);
        }
        return GetOneValue(values, left) - GetOneValue(values, right);
    }
    return GetOneValue(values, str);
}

// 待实现函数，在此函数中填入答题代码
static int GetSum(const char values[][MAX_COL_SIZE][MAX_STR_LEN], int rows, int cols, const char *sumArea)
{
    int sum = 0;
    char area[MAX_STR_LEN] = {0};
    if (memcpy_s(area, sizeof(area), sumArea, strlen(sumArea)) != 0) {
        return sum;
    }
    char *connext = NULL;
    char *right = NULL;
    char *left = strtok_s(area, ":", &connext);
    if (left != NULL) {
        right = strtok_s(NULL, ":", &connext);
    }
    int lcol = left[0] - 'A';
    int lrow = strtol((left + 1), NULL, 10) - 1;
    int rcol = right[0] - 'A';
    int rrow = strtol((right + 1), NULL, 10) - 1;
    for (int i = lrow; i <= rrow; i++) {
        for (int j = lcol; j <= rcol; j++) {
            sum += GetDigit(values, i, j);
        }
    }
    return sum;
}

int main(void)
{
    // @formatter:off
    int rows, cols;
    if (scanf_s("%d %d", &rows, &cols) != 2) { return -1; }
    static char values[MAX_ROW_SIZE][MAX_COL_SIZE][MAX_STR_LEN];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf_s("%s", &values[i][j], MAX_STR_LEN) != 1) { return -1; }
        }
    }
    char sumArea[MAX_STR_LEN];
    if (scanf_s("%s", sumArea, sizeof(sumArea)) != 1) { return -1; }
    int output = GetSum(values, rows, cols, sumArea);
    printf("%d", output);
    return 0;
    // @formatter:on
}
