#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 
 */
#define MAX 1000002
typedef struct {
    int *arr;
} MyHashSet;

MyHashSet *myHashSetCreate()
{
    MyHashSet *obj = malloc(sizeof(MyHashSet));
    int *arr = malloc(sizeof(int) * MAX);
    memset(arr, -1, sizeof(int) * MAX);
    obj->arr = arr;
    return obj;
}

void myHashSetAdd(MyHashSet *obj, int key)
{
    if (obj->arr[key] == -1) {
        obj->arr[key] = key;
    }
}

void myHashSetRemove(MyHashSet *obj, int key)
{
    obj->arr[key] = -1;
}

bool myHashSetContains(MyHashSet *obj, int key)
{
    return obj->arr[key] != -1;
}

void myHashSetFree(MyHashSet *obj)
{
    free(obj->arr);
    free(obj);
}

int main()
{
    // @formatter:off
    
    return 0;
    // @formatter:on
}