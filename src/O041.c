/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <uthash.h>


/*
 
 */

typedef struct {
    double sum;
    int size;
    int len;
    int *inputs;
} MovingAverage;

/** Initialize your data structure here. */

MovingAverage *movingAverageCreate(int size)
{
    MovingAverage *obj = malloc(sizeof(MovingAverage));
    obj->sum = 0;
    obj->size = size;
    obj->len = 0;
    int *inputs = malloc(sizeof(int) * 10002);
    obj->inputs = inputs;
    return obj;
}

double movingAverageNext(MovingAverage *obj, int val)
{
    if (obj->len >= obj->size) {
        obj->sum -= obj->inputs[obj->len - obj->size];
    }
    obj->sum += val;
    obj->inputs[obj->len++] = val;
    int longth = obj->len < obj->size ? obj->len : obj->size;
    return obj->sum / longth;
}

void movingAverageFree(MovingAverage *obj)
{
    free(obj->inputs);
    free(obj);
}

int main()
{
    // @formatter:off
    MovingAverage *obj=movingAverageCreate(3);
    printf("%lf \n",movingAverageNext(obj,1));fflush(stdout);
    printf("%lf \n",movingAverageNext(obj,10));fflush(stdout);
    printf("%lf \n",movingAverageNext(obj,3));fflush(stdout);
    printf("%lf \n",movingAverageNext(obj,5));fflush(stdout);
    return 0;
    // @formatter:on
}