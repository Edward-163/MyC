#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize){
    ///bug:利用arr记录val,错在遍历arr找criticalIdx时修改arr的值
    int arr[100000]={0};//head val>=1,arr的空间可以优化掉.
    int aidx = 0;
    while(head!=NULL){
        arr[aidx++]=head->val;
        head=head->next;
    }
    int* arr2=(int*)malloc(sizeof(int)*aidx);//
    memset(arr2,0,sizeof(int)*aidx);
    //结束后aidx==len

    for(int a=1;a<aidx-1;a++){
        if(arr[a-1]>arr[a] && arr[a]<arr[a+1]){
            arr2[a]=1;
        }
        if(arr[a-1]<arr[a] && arr[a]>arr[a+1]){
            arr2[a]=1;
        }
    }

    int criticalIdx1=-1;
    int min=-1;
    int firstCriticalIdx=-1;
    for(int a=1;a<aidx-1;a++){
//        printf("%d",g_arr[a]);
//        fflush(stdout);
        if(arr2[a]==1){
            if (criticalIdx1 == -1) {
                firstCriticalIdx=a;
            }else{
                int dis=a-criticalIdx1;
                if(min==-1)min=dis;
                else if(dis<min)min=dis;
                ///bug求max的时候不是相邻点相减
                //if(max==-1)max=dis;
                //else if(dis>max)max=dis;
            }

            criticalIdx1=a;
        }
    }

    int *res = (int *) malloc(sizeof(int) * 2);
    res[0]=min;
    ///bug没有节点or只有一个节点时,下面直接相减为0,不是正确答案
    //res[1]=criticalIdx1-firstCriticalIdx;
    res[1]=min==-1?min:criticalIdx1-firstCriticalIdx;
    *returnSize=2;
    return res;
}

int main() {
    return 0;
}