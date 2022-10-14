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
struct {
    union {
        long t1;
        int t2;
        struct {
            int p;
            int q;
        } w;
    } u;
    int i;
} x;

int main()
{
    // @formatter:off
    x.u.t1=100;
    // x.t1=100; // false;
    x.u.w.p=1;
    // x.p=1; // false;
    // x.w.q=10; // false;
    // x.u.w=0; // false
    return 0;
    // @formatter:on
}