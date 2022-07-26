#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
 题:翻译为,有根箭,最多可以射穿k个区间,暴力:每次加一个区域,和之前的区域比较,相交则k++,且得出相交区域,
 随着k++,相交区域大概率会缩小
 50/98

 线段树??动态开点??
 */
typedef struct {
    int k;
    int arr[400][2];
    int arrSize;
} MyCalendarThree;

MyCalendarThree *myCalendarThreeCreate() {
    MyCalendarThree *myc = (MyCalendarThree *) malloc(sizeof(MyCalendarThree));
    myc->k = 1;
    myc->arrSize = 0;
    return myc;
}

int myCalendarThreeBook(MyCalendarThree *obj, int start, int end) {
    obj->arr[obj->arrSize][0] = start;
    obj->arr[obj->arrSize][1] = end;
    obj->arrSize++;
    int merge[2] = {start, end};
    int count=1;
    for (int a = 0; a < obj->arrSize - 1; a++) {
        if (obj->arr[a][1] <= merge[0] || obj->arr[a][0] >= merge[1]) {
            continue;
        }else{
            if(obj->arr[a][0]>merge[0])merge[0]=obj->arr[a][0];
            if(obj->arr[a][1]<merge[1])merge[1]=obj->arr[a][1];
            count++;
        }
    }
    if(count>obj->k)obj->k=count;
    return obj->k;
}

void myCalendarThreeFree(MyCalendarThree *obj) {
    /// bug不能释放arr,提示arr不是通过malloc分配的
    //free(obj->g_arr);
    free(obj);
}

int main() {

    return 0;
}