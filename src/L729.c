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
 
 */
#define MAX 1002
typedef struct {
    int sta;
    int end;
} MyCalendar;
int g_len;

MyCalendar *myCalendarCreate()
{
    MyCalendar *arr = (MyCalendar *) malloc(sizeof(MyCalendar) * MAX);
    g_len = 0;
    return arr;
}

bool myCalendarBook(MyCalendar *obj, int start, int end)
{
    if (g_len == 0) {
        obj[g_len].sta = start;
        obj[g_len].end = end - 1;
        g_len++;
    } else {
        for (int i = 0; i < g_len; ++i) {
            /// bug end需要减1,和后续设值保持一致
            if (!(start > obj[i].end || end-1 < obj[i].sta)) {
                return false;
            }
        }
        obj[g_len].sta = start;
        obj[g_len].end = end - 1;
        g_len++;
    }
    return true;
}

void myCalendarFree(MyCalendar *obj)
{
    free(obj);
}

/**
 * Your MyCalendar struct will be instantiated and called as such:
 * MyCalendar* obj = myCalendarCreate();
 * bool param_1 = myCalendarBook(obj, start, end);

 * myCalendarFree(obj);
*/
int main()
{
    // @formatter:off
    MyCalendar *obj = myCalendarCreate();
//    printf("%d \n",myCalendarBook(obj,10,20));fflush(stdout);
//    printf("%d \n",myCalendarBook(obj,15,25));fflush(stdout);
//    printf("%d \n",myCalendarBook(obj,20,30));fflush(stdout);
    printf("%d \n",myCalendarBook(obj,47,50));fflush(stdout); // true
    printf("%d \n",myCalendarBook(obj,33,41));fflush(stdout); // true
    printf("%d \n",myCalendarBook(obj,39,45));fflush(stdout); // false
    printf("%d \n",myCalendarBook(obj,33,42));fflush(stdout); // false
    printf("%d \n",myCalendarBook(obj,25,32));fflush(stdout); // true
    printf("%d \n",myCalendarBook(obj,26,35));fflush(stdout); // false
    printf("%d \n",myCalendarBook(obj,19,25));fflush(stdout); // false
    printf("%d \n",myCalendarBook(obj,3,8));fflush(stdout); // true
    printf("%d \n",myCalendarBook(obj,8,13));fflush(stdout); // true
    printf("%d \n",myCalendarBook(obj,18,27));fflush(stdout); // false
    return 0;
    // @formatter:on
}