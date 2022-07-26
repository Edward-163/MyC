#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool fn(int* arr,int len,bool isA,int left){
    int ridx=len-1;
    while(ridx>=0 && arr[ridx]==1){
        ridx--;
    }
    /// bug:
//    int max=g_arr[ridx];
    int max=ridx+1;
    if(isA==true && max>=left)return true;
    if(isA==false && max>=left)return false;

    //a不知道怎么选,只能遍历
    for(int a=0;a<len && arr[a]==0;a++){
        //选下标a,相当于选了数字a+1
        arr[a]=1;
        if(fn(arr,len,!isA,left-(a+1))==true)return true;
        //不加else,稳输的局,continue
        arr[a]=0;
    }
    return false;
}
bool canIWin(int maxChoosableInteger, int desiredTotal){
    //若能选数>=des,直接赢
    //10,20 a选9,10稳赢,其他稳输

    int* arr=(int*)malloc(sizeof(int)*maxChoosableInteger);
    memset(arr,0,sizeof(int)*maxChoosableInteger);
    return fn(arr,maxChoosableInteger,true,desiredTotal);
}
int main(){
//    printf("%d",canIWin(10,20));
    printf("%d",canIWin(10,11));
    return 0;
}