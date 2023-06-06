#include <string.h>
#include <math.h>
#include <stdio.h>
#include "securec.h"

/*
 
 */
void prinfAll(const int *dst, size_t size)
{
    for (int i = 0; i < size; ++i) {
        printf("%d ", dst[i]);
        fflush(stdout);
    }
    printf("\n");
    fflush(stdout);
}
#define MAX 10002
typedef struct {
    char *contentArr[MAX];
    int finishArr[MAX];
    int csize;
} MemoSystem;

int main()
{
    // @formatter:off
    MemoSystem *obj = malloc(sizeof(MemoSystem));
    /// obj是指针,obj不是数组,若obj是数组可以直接用下行
    // memset_s(obj, sizeof(obj), 0, sizeof(obj));
    /// 结构体memset
    memset_s(obj, sizeof(MemoSystem), 0, sizeof(MemoSystem));


    /// 注意它在string.h中
    /// 一个字节一个字节给dst指针指向的内存区域赋值val(表面是int,实际只截取低位1字节,并用截取的1字节挨个挨个填充,共填充n次)
    /// memset坑 函数按字节对内存块进行初始化，val不能为0和-1之外的其他值
    /// 0000 0000          -1==1111 1111  通过下面博客大概知道为啥只能0和-1了
    /// https://blog.csdn.net/melody_1016/article/details/83479778
    // int dst[3]; // 局部变量数组在栈分配空间,元素值随机
    // size_t i1 = sizeof(dst);
    // size_t size = i1/sizeof(dst[0]);
    //
    // prinfAll(dst, size);
    //
    // int val=1;
    // size_t n = sizeof(dst);
    // memset(dst,val,n);
    // /// succ 返 EOK==0
    // errno_t ans = memset_s(dst,sizeof(dst),val,n);
    // if(ans!=EOK){
    //     return 0;
    // }
    //
    // prinfAll(dst, size);



    /**
     * memset_s(dest,)
     * succ返回EOK;fail返回错误码
     */
    int arr2[4][2];
    // if(memset_s(arr2,sizeof(arr2),-1,sizeof(arr2))!=EOK){ /// 这两种等价,但我推荐这种
    if(memset_s(arr2,sizeof(arr2),-1,sizeof(int*)*4)!=EOK){
        return -1;
    }
    for (int i = 0; i < 4; ++i){
        printf("%d %d\n",arr2[i][0],arr2[i][1]);fflush(stdout);
    }





    return 0;
    // @formatter:on
}

