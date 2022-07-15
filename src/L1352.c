#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
//#include <uthash.h>


/*

 */
typedef struct {
    int* arr;
    int* psum;
    int* closeZeroIdx;
    /// bug结构体不能直接赋值??
    int len;
} ProductOfNumbers;


ProductOfNumbers* productOfNumbersCreate() {
    ProductOfNumbers* res=(ProductOfNumbers*)malloc(sizeof(ProductOfNumbers));
    int* arr=(int*)malloc(sizeof(int)*40000);
    int* psum=(int*)malloc(sizeof(int)*40000);
    int* closeZeroIdx=(int*)malloc(sizeof(int)*40000);
    memset(arr,-1,sizeof(int));
    memset(psum,-1,sizeof(int));
    memset(closeZeroIdx,-1,sizeof(int));
    res->arr=arr;
    res->psum=psum;
    res->closeZeroIdx=closeZeroIdx;
    res->len=0;
    return res;
}

void productOfNumbersAdd(ProductOfNumbers* obj, int num) {
    int* arr=obj->arr;
    int* psum=obj->psum;
    int* closeZeroIdx=obj->closeZeroIdx;
    int len=obj->len;
    arr[len]=num;//sig
    if(len==0 || psum[len-1]==0){
        psum[len]=arr[len];
    }else{
        if(psum[len-1]!=0){
            psum[len]=arr[len]*psum[len-1];
        }
    }
    if(psum[len]==0){
        closeZeroIdx[len]=len;
    }else{
        if(len-1>=0)closeZeroIdx[len]=closeZeroIdx[len-1];
    }

    /// bug
//    len++;
    obj->len=obj->len+1;
}

int productOfNumbersGetProduct(ProductOfNumbers* obj, int k) {
    int* closeZeroIdx=obj->closeZeroIdx;
    int len=obj->len;
    int czi=closeZeroIdx[len-1];
    int left=len-k;
    if(left<=czi)return 0;
    int* psum=obj->psum;
    int* arr=obj->arr;
    return psum[len-1]/psum[left]*arr[left];
}

void productOfNumbersFree(ProductOfNumbers* obj) {
    free(obj);
}

/**
 * Your ProductOfNumbers struct will be instantiated and called as such:
 * ProductOfNumbers* obj = productOfNumbersCreate();
 * productOfNumbersAdd(obj, num);

 * int param_2 = productOfNumbersGetProduct(obj, k);

 * productOfNumbersFree(obj);
*/
int main() {
    ProductOfNumbers* obj = productOfNumbersCreate();
    productOfNumbersAdd(obj, 1);
    productOfNumbersAdd(obj, 2);
    productOfNumbersAdd(obj, 3);
    int param_2 = productOfNumbersGetProduct(obj, 2);
    printf("%d",param_2);
    productOfNumbersFree(obj);
    return 0;
}