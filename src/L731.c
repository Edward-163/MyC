#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"

/*
实现一个 MyCalendar 类来存放你的日程安排。如果要添加的时间内不会导致三重预订时，则可以存储这个新的日程安排。
MyCalendar 有一个 book(int start, int end)方法。它意味着在 start 到 end 时间内增加一个日程安排，注意，这里的时间是半开区间，即 [start, end), 实数 x 的范围为，  start <= x < end。
当三个日程安排有一些时间上的交叉时（例如三个日程安排都在同一时间内），就会产生三重预订。
每次调用 MyCalendar.book方法时，如果可以将日程安排成功添加到日历中而不会导致三重预订，返回 true。否则，返回 false 并且不要将该日程安排添加到日历中。
请按照以下步骤调用MyCalendar 类: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)
示例：
MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(50, 60); // returns true
MyCalendar.book(10, 40); // returns true
MyCalendar.book(5, 15); // returns false
MyCalendar.book(5, 10); // returns true
MyCalendar.book(25, 55); // returns true
解释： 
前两个日程安排可以添加至日历中。 第三个日程安排会导致双重预订，但可以添加至日历中。
第四个日程安排活动（5,15）不能添加至日历中，因为它会导致三重预订。
第五个日程安排（5,10）可以添加至日历中，因为它未使用已经双重预订的时间10。
第六个日程安排（25,55）可以添加至日历中，因为时间 [25,40] 将和第三个日程安排双重预订；
时间 [40,50] 将单独预订，时间 [50,55）将和第二个日程安排双重预订。
 */
typedef struct {
    int key;
    int val; //
    UT_hash_handle hh;
} Hash;
Hash *g_head;
typedef struct {

} MyCalendarTwo;

MyCalendarTwo *myCalendarTwoCreate()
{
    g_head = NULL;
    MyCalendarTwo *obj = malloc(sizeof(MyCalendarTwo));
    return obj;
}

int cmp(Hash *a, Hash *b)
{
    return a->key - b->key;
}

Hash *Fn(int key, int num)
{
    Hash *tmp = NULL;
    HASH_FIND_INT(g_head, &key, tmp);
    if (tmp == NULL) {
        Hash *tmp3 = malloc(sizeof(Hash));
        tmp3->key = key;
        tmp3->val = num;
        HASH_ADD_INT(g_head, key, tmp3);
    } else {
        tmp->val += num;
    }
    return tmp;
}

bool myCalendarTwoBook(MyCalendarTwo *obj, int start, int end)
{
    /// 差分变种题,hash通过大部分,但超时,原因??
    Hash *ptr = Fn(start, 1);
    Hash *ptr1 = Fn(end, -1);
    int sum = 0;
    Hash *el = NULL;
    Hash *tmp = NULL;
    HASH_SORT(g_head, cmp);
    HASH_ITER(hh, g_head, el, tmp) {
        sum += el->val;
        if (sum >= 3) {
            Fn(start, -1);
            Fn(end, 1);
            return false;
        }
    }
    return true;
}

void myCalendarTwoFree(MyCalendarTwo *obj)
{
    free(obj);
}

int main()
{
    // @formatter:off
    MyCalendarTwo *obj = myCalendarTwoCreate();
    printf("%d \n",myCalendarTwoBook(obj,10, 20));fflush(stdout); // returns true
    printf("%d \n",myCalendarTwoBook(obj,50, 60));fflush(stdout); // returns true
    printf("%d \n",myCalendarTwoBook(obj,10, 40));fflush(stdout); // returns true
    printf("%d \n",myCalendarTwoBook(obj,5, 15));fflush(stdout); // returns false
    printf("%d \n",myCalendarTwoBook(obj,5, 10));fflush(stdout); // returns true
    printf("%d \n",myCalendarTwoBook(obj,25, 55));fflush(stdout); // returns true
    return 0;
    // @formatter:on
}