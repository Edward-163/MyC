#include <stdio.h>

int minMoves2(int *nums, int numsSize) {
    /*
     肯定不是去平均值 如009 后来想了很久:排序后双指针0089
     0088先走1步让两边柱子等宽==2,最后柱子宽*中位数差值==2*(8-0)==16
     刚开始无脑向冒泡,后来看了看numsSize,放弃了,改想快速求中间柱子,
     有点类似求topk,经典解给忘了,写了冒泡慢速过了...
     */
    for (int a = 0; a <= (numsSize - 1) / 2; a++) {
        for (int b = a + 1; b < numsSize; b++) {
            if (nums[b] < nums[a]) {
                int tmp = nums[a];
                nums[a] = nums[b];
                nums[b] = tmp;
            }
        }
    }
    int res = 0;
    int mid = nums[(numsSize - 1) / 2];
    for (int a = 0; a < numsSize; a++) {
        int count = mid > nums[a] ? mid - nums[a] : nums[a] - mid;
        res += count;
    }
    return res;
}

/*
    输入：nums = [1,2,3]
    输出：2
    解释：
    只需要两步操作（每步操作指南使一个元素加 1 或减 1）：
    [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 * */
int main() {
//    int nums[]={1,2,3};
//    int nums[]={1,10,2,9};
    int nums[] = {0, 0, 8};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("%d", minMoves2(nums, numsSize));
    return 0;
}