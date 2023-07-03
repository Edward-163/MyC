#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
// 可以通过在包含#include <assert.h>的语句之前插入 #define NDEBUG 来禁用assert调用
#define NDEBUG
#include <assert.h>

/*
 
 */
int main()
{
    // @formatter:off
    assert(0); // 实际运行时报错
    assert(1>2); // 实际运行时报错
    // assert(3>2); // 实际运行时正常
    printf("%s \n","test nodebug assert");fflush(stdout);

    _Static_assert(2+2==4,"err info");
    // _Static_assert(2+2==3,"666"); // 编译失败
    // static_assert(2+2==3,"666"); // 编译失败,include assert.h之后,此行等价与上行
    // static_assert(2+2==4,"666");
    return 0;
    // @formatter:on
}
