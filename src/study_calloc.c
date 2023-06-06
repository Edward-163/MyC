#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include "securec.h"

/**
calloc(size_t count,size_t size) ---- count为我们需要申请空间的块数，size为我们需要申请类型的占的字节大小，并不需要人为的计算空间大小
而且，使用malloc()函数申请后空间的值是随机的，并没有进行初始化，但是使用calloc()函数却在申请后，对空间逐一进行初始化，并设置值为0;
calloc(m, n) 本质上等价于:
p = malloc(m n);
memset(p, 0, m n);
填充的零是全零, 但不能确保生成有用的空指针值或浮点零值。
 */

int main()
{
    // @formatter:off
    
    return 0;
    // @formatter:on
}
