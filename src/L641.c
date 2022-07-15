/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*

 */
typedef struct {
    int len;
    int *arr;
    int k;
} MyCircularDeque;

MyCircularDeque *myCircularDequeCreate(int k)
{
    MyCircularDeque *myc = (MyCircularDeque *) malloc(sizeof(MyCircularDeque));
    myc->len = 0;
    if (k > 1000) {
        k = 1000;
    }
    int *arr = (int *) malloc(sizeof(int) * k);
    myc->arr = arr;
    myc->k = k;
    return myc;
}

bool myCircularDequeInsertFront(MyCircularDeque *obj, int value)
{
    if (obj->len == obj->k) {
        return false;
    }
    (obj->len)++;
    int *arr = obj->arr;
    for (int a = (obj->len) - 1; a >= 1; a--) {
        arr[a] = arr[a - 1];
    }
    arr[0] = value;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque *obj, int value)
{
    if (obj->len == obj->k) {
        return false;
    }
    (obj->len)++;
    int *arr = obj->arr;
    int len = obj->len;
    arr[len - 1] = value;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque *obj)
{
    if (obj->len == 0) {
        return false;
    }
    int *arr = obj->arr;
    int len = obj->len;
    for (int a = 0; a < len - 1; a++) {
        arr[a] = arr[a + 1];
    }
    (obj->len)--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque *obj)
{
    if (obj->len == 0) {
        return false;
    }
    (obj->len)--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque *obj)
{
    if (obj->len == 0) {
        return -1;
    }
    return (obj->arr)[0];
}

int myCircularDequeGetRear(MyCircularDeque *obj)
{
    if (obj->len == 0) {
        return -1;
    }
    return (obj->arr)[obj->len - 1];
}

bool myCircularDequeIsEmpty(MyCircularDeque *obj)
{
    return obj->len == 0;
}

bool myCircularDequeIsFull(MyCircularDeque *obj)
{
    return obj->len == obj->k;
}

void myCircularDequeFree(MyCircularDeque *obj)
{
    free(obj->arr);
    free(obj);
}

int main()
{

    return 0;
}