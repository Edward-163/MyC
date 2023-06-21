#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>

/*
 
 */

int main()
{
    // @formatter:off
    assert(1>2); // 实际运行时报错
    // assert(3>2); // 实际运行时正常
    
    _Static_assert(2+2==4,"666");
    // _Static_assert(2+2==3,"666"); // 编译失败
    // static_assert(2+2==3,"666"); // 编译失败,include assert.h之后,此行等价与上行
    // static_assert(2+2==4,"666");
    return 0;
    // @formatter:on
}
