#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include "securec.h"

#define MAX 101
typedef struct {
    int activityId;
    int startDate;
    int endDate;
    int category;
    int number;
    int priceLimit;
    int discount;
} Activity;

typedef struct {
    Activity arr[MAX];
    int arrSize;
} PromotionSys;

PromotionSys *PromotionSysCreate()
{
    PromotionSys *obj = malloc(sizeof(PromotionSys));
    if (memset_s(obj->arr, sizeof(obj->arr), -1, sizeof(Activity) * MAX) != 0) {
        return NULL;
    }
    obj->arrSize = 0;
    printf("%s ", "null");
    fflush(stdout);
    return obj;
}

bool PromotionSysAddPromotion(PromotionSys *obj, Activity *activity)
{
    if (obj->arr[activity->activityId].activityId != -1) {
        return false;
    }
    obj->arr[activity->activityId] = *activity;
    obj->arrSize++;
    return true;
}

int Cmp(int a[][3], int b[][3])
{
    if (*a[0] == *b[0]) {
        if (*a[1] == *b[1]) {
            return *a[3] - *b[3]; // 3代表元素长度为3,ele[0]代表discount,ele[1]代表最近日期,ele[2]代表actId
        }
        return *a[1] - *b[1];
    }
    return *b[0] - *a[0];
}

int PromotionSysProcessPromotion(PromotionSys *obj, int date, int category, int price)
{
    int picked[obj->arrSize][3]; // 3代表元素长度为3,ele[0]代表discount,ele[1]代表最近日期,ele[2]代表actId
    int pickedSize = 0;
    if (memset_s(picked, sizeof(picked), -1, sizeof(picked)) != 0) {
        return -1;
    }
    for (int i = 0; i < obj->arrSize; ++i) {
        if (obj->arr[i].category == category && obj->arr[i].startDate <= date && date <= obj->arr[i].endDate
            && price >= obj->arr[i].priceLimit && obj->arr[i].number > 0) {
            picked[pickedSize][0] = obj->arr[i].discount;
            picked[pickedSize][1] = obj->arr[i].endDate - date;
            picked[pickedSize][2] = obj->arr[i].activityId; // 3代表元素长度为3,ele[0]代表discount,ele[1]代表最近日期,ele[2]代表actId
            pickedSize++;
        }
    }

    int discount = 0;
    if (pickedSize > 0) {
        qsort(picked, pickedSize, sizeof(picked[0]), Cmp);
        int pickedActId = picked[0][2];
        obj->arr[pickedActId].number--;
        discount = obj->arr[pickedActId].discount;
    }
    return price - discount;
}

int PromotionSysQueryRemainingNum(PromotionSys *obj, int date, int activityId)
{
    if (obj->arr[activityId].startDate <= date && date <= obj->arr[activityId].endDate) {
        return obj->arr[activityId].number;
    }
    return 0;
}

void PromotionSysFree(PromotionSys *obj)
{
    free(obj);
}

int main()
{
    // @formatter:off
    // [null,true,200,2]
    // PromotionSys *obj = PromotionSysCreate();
    // Activity activity[]={0,1,2,5,3,100,10};
    // bool b = PromotionSysAddPromotion(obj,activity);
    // printf("%d ",b);fflush(stdout);
    //
    // int i = PromotionSysProcessPromotion(obj,1,5,210);
    // printf("%d ",i);fflush(stdout);
    //
    // int num = PromotionSysQueryRemainingNum(obj,2,0);
    // printf("%d ",num);fflush(stdout);

    /*["PromotionSys","addPromotion","processPromotion","processPromotion","processPromotion",
     "addPromotion","queryRemainingNum","processPromotion","addPromotion","addPromotion",
     "processPromotion","queryRemainingNum","queryRemainingNum","addPromotion"]
    [[],[0,1,3,5,1,20,10],[1,5,16],[2,5,25],[2,2,50],
     [1,2,7,5,2,10,6],[2,0],[2,5,22],[15,4,5,5,2,7,6],[2,4,5,5,20,7,6],
     [4,5,30],[5,2],[8,1],[0,2,2,4,3,10,5]]

     [null,true,16,15,50,true,0,16,true,true,24,19,0,false]
     */
    PromotionSys *obj = PromotionSysCreate();
    Activity activity[]={0,1,3,5,1,20,10};
    bool b = PromotionSysAddPromotion(obj,activity);
    printf("%d ",b);fflush(stdout);
    int i = PromotionSysProcessPromotion(obj,1,5,16);
    printf("%d ",i);fflush(stdout);
    int i2 = PromotionSysProcessPromotion(obj,2,5,25);
    printf("%d ",i2);fflush(stdout);
    int i3 = PromotionSysProcessPromotion(obj,2,2,50);
    printf("%d ",i3);fflush(stdout);

    Activity activity2[]={1,2,7,5,2,10,6};
    bool b2 = PromotionSysAddPromotion(obj,activity2);
    printf("%d ",b2);fflush(stdout);
    int num = PromotionSysQueryRemainingNum(obj,2,0);
    printf("%d ",num);fflush(stdout);
    int i4 = PromotionSysProcessPromotion(obj,2,5,22);
    printf("%d ",i4);fflush(stdout);
    Activity activity23[]={15,4,5,5,2,7,6};
    bool b23 = PromotionSysAddPromotion(obj,activity23);
    printf("%d ",b23);fflush(stdout);
    Activity activity233[]={2,4,5,5,20,7,6};
    bool b233 = PromotionSysAddPromotion(obj,activity233);
    printf("%d ",b233);fflush(stdout);

    int i5 = PromotionSysProcessPromotion(obj,4,5,30);
    printf("%d ",i5);fflush(stdout);
     num = PromotionSysQueryRemainingNum(obj,5,2);
    printf("%d ",num);fflush(stdout);
     num = PromotionSysQueryRemainingNum(obj,8,1); // wrong
    printf("%d ",num);fflush(stdout);
    Activity activity2333[]={0,2,2,4,3,10,5};
    bool b2333 = PromotionSysAddPromotion(obj,activity2333);
    printf("%d ",b2333);fflush(stdout);
    return 0;
    // @formatter:on
}