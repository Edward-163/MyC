#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include <regex.h>
/*
 请设计一款自动售货机的进出货管理系统 VendingMachineSystem()，需实现以下功能：
//         设置该自动售货机上共有 trayNum 个商品轨道，每个商品轨道上最多可放置 trayCapacity 个商品。
//    每个轨道上只能放置同一品牌的商品；同一品牌的商品只能放置在一个轨道上；
//    对于已售空的轨道可以加入某一品牌的商品，即不一定是原品牌。
         VendingMachineSystem(int trayNum, int trayCapacity)：
//         向系统中添加商品，品牌为 brandId ，商品编号为 productIdList ，从所在轨道的末端商品之后按数组 productIdList 下标升序依次放入。
//    售货机内已有该品牌的商品：若所在轨道剩余空间充足，则放入商品并返回 true ；否则不做任何操作并返回 false ；
//    售货机内没有该品牌商品：若售货机内有空轨道，且该轨道空间充足，则放入商品并返回 true ；否则不做任何操作并返回 false 。
         addProduct(int brandId, int[] productIdList)
//         购买品牌为 brandId 的 num 个商品。
//    若有足够的商品，则取该轨道上前 num 个商品并返回其商品编号列表；
//    若没有该品牌商品，或该商品数量不足 num 个，则不做任何操作并返回空数组 []。
         buyProduct(int brandId, int num)
//         按照品牌编号升序返回每个品牌的首个商品编号(忽略空轨道)；若售货机为空，返回空数组 []。
         queryProduct()
示例 1：
输入：["VendingMachineSystem","addProduct","buyProduct","queryProduct"]
[[2,5],[3,[3,5,4,6,2]],[3,3],[]]
输出：[null,true,[3,5,4],[6]]
解释：
VendingMachineSystem obj = VendingMachineSystem(2,5); // 设置自动售货机共有 2 个轨道，每个轨道上只能放 5 个商品
obj.addProduct(3,[3,5,4,6,2]); // 在售货机放置品牌编号为 3 的商品，按照下标升序依次放入，商品编号依次为 3、5、4、6、2，返回 true
obj.buyProduct(3,3); // 购买 3 个品牌编号为 3 的商品，被购买的商品编号依次为 3、5、4，返回所购商品编号列表 [3,5,4]
obj.queryProduct(); // 当前只有1个品牌商品，其首个商品编号为6，返回 [6]
注：输出中的 null 表示此对应函数无输出（其中：C 的构造函数有返回值，但是也是无需输出）
示例 2：
输入：
["VendingMachineSystem","addProduct","addProduct","addProduct","addProduct","buyProduct","buyProduct","buyProduct","queryProduct","addProduct","addProduct","buyProduct","addProduct"]
[[2,5],[3,[3,5,4,6,2,1]],[3,[3,5,4,6,2]],[1,[9]],[2,[7]],[3,3],[9,3],[3,3],[],[3,[10,20,13,14]],[3,[10,20,13]],[3,5],[9,[5,4]]]
输出：[null,false,true,true,false,[3,5,4],[],[],[9,6],false,true,[6,2,10,20,13],true]
提示：
1 <= addProduct, buyProduct, queryProduct 总操作数 <= 1000
1 <= trayNum <= 100
1 <= trayCapacity <= 100
1 <= brandId <= 200
1 <= productIdList.length <= 100
1 <= productIdList[i] <= 10^5
1 <= num <= 100
 */
typedef struct {

};
//         设置该自动售货机上共有 trayNum 个商品轨道，每个商品轨道上最多可放置 trayCapacity 个商品。
//    每个轨道上只能放置同一品牌的商品；同一品牌的商品只能放置在一个轨道上；
//    对于已售空的轨道可以加入某一品牌的商品，即不一定是原品牌。
VendingMachineSystem(int trayNum, int trayCapacity){

}
//         向系统中添加商品，品牌为 brandId ，商品编号为 productIdList ，从所在轨道的末端商品之后按数组 productIdList 下标升序依次放入。
//    售货机内已有该品牌的商品：若所在轨道剩余空间充足，则放入商品并返回 true ；否则不做任何操作并返回 false ；
//    售货机内没有该品牌商品：若售货机内有空轨道，且该轨道空间充足，则放入商品并返回 true ；否则不做任何操作并返回 false 。
bool addProduct(int brandId, int* productIdList,int listLen){

}
//         购买品牌为 brandId 的 num 个商品。
//    若有足够的商品，则取该轨道上前 num 个商品并返回其商品编号列表；
//    若没有该品牌商品，或该商品数量不足 num 个，则不做任何操作并返回空数组 []。
int* buyProduct(int brandId, int num){

}
int cmp(const void*a,const void*b){

}
//         按照品牌编号升序返回每个品牌的首个商品编号(忽略空轨道)；若售货机为空，返回空数组 []。
int* queryProduct(int* retSize){

}
/**
 * 光写完36分钟,所以我决定要封装hash的常用方法,和学习多变量写同一行,能省点时间算点
 * @return
 */
int main() {
    /*
     ["VendingMachineSystem","addProduct","addProduct","addProduct","addProduct",
     "buyProduct","buyProduct","buyProduct","queryProduct",
     "addProduct","addProduct","buyProduct","addProduct"]
[[2,5],[3,[3,5,4,6,2,1]],[3,[3,5,4,6,2]],[1,[9]],[2,[7]],
     [3,3],[9,3], [3,3],[],
     [3,[10,20,13,14]],[3,[10,20,13]],[3,5],[9,[5,4]]]
输出：[null,false,true,true,false,
     [3,5,4],[],[],[9,6],
     false,true,[6,2,10,20,13],true]
     */
    VendingMachineSystem(2,5);
    int listLen;
    int prodlist[]={3,5,4,6,2,1};
    listLen=sizeof(prodlist)/sizeof(prodlist[0]);
    printf("%d ", addProduct(3,prodlist,listLen));fflush(stdout);
    int prodlist2[]={3,5,4,6,2};
    listLen=sizeof(prodlist2)/sizeof(prodlist2[0]);
    printf("%d ", addProduct(3,prodlist2,listLen));fflush(stdout);
    int prodlist3[]={9};
    listLen=sizeof(prodlist3)/sizeof(prodlist3[0]);
    printf("%d ", addProduct(1,prodlist3,listLen));fflush(stdout);
    int prodlist4[]={7};
    listLen=sizeof(prodlist4)/sizeof(prodlist4[0]);
    printf("%d ", addProduct(2,prodlist4,listLen));fflush(stdout);
    int *pInt = buyProduct(3, 3);
    for (int i = 0; i < 3; ++i){
        printf("%d ", pInt[i]);fflush(stdout);
    }
    printf("\n");fflush(stdout);
    int *product = buyProduct(9, 3);
    for (int i = 0; i < 3; ++i){
        printf("%d ", prodlist[i]);fflush(stdout);
    }
    printf("\n");fflush(stdout);
    int *pInt1 = buyProduct(3, 3);
    for (int i = 0; i < 3; ++i){
        printf("%d ", pInt1[i]);fflush(stdout);
    }
    printf("\n");fflush(stdout);
    int retSize=0;
    int *pInt2 = queryProduct(&retSize);
    for (int i = 0; i < retSize; ++i){
        printf("%d ", pInt2[i]);fflush(stdout);
    }
    printf("\n");fflush(stdout);
    int prodlist5[]={10,20,13,14};
    listLen=sizeof(prodlist5)/sizeof(prodlist5[0]);
    printf("%d ", addProduct(3,prodlist5,listLen));fflush(stdout);
    int prodlist6[]={10,20,13};
    listLen=sizeof(prodlist6)/sizeof(prodlist6[0]);
    printf("%d ", addProduct(3,prodlist6,listLen));fflush(stdout);
    int *pInt3 = buyProduct(3, 5);
    for (int i = 0; i < 5; ++i){
        printf("%d ", pInt3[i]);fflush(stdout);
    }
    printf("\n");fflush(stdout);
    int prodlist7[]={5,4};
    listLen=sizeof(prodlist7)/sizeof(prodlist7[0]);
    printf("%d ", addProduct(9,prodlist7,listLen));fflush(stdout);
    return 0;
}