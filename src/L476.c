#include <stdio.h>
#include <math.h>

int findComplement(int num){
    /// 全位取反
    //num=~num;
    double d3 = (double) num;
    /// bug:sqrt(8)==2.8 人家算得没毛病,我是要求log2(8)
    //double d = sqrt(d3);
    double d = log2(d3);
    int aa=(int)d;
    int arr[aa+1];
    int aidx=0;
    while(num!=1){
        arr[aidx++] = num % 2;
        num/=2;
    }
    arr[aidx++]=num;

    double res=0;
    for(int a=0;a<aidx;a++){
        /// bug:pow(2,1)==2^1==0 ??
        double d2 = pow(2.0, a);
        double d1 = d2 * (arr[a]==1?0:1);
        res=res+d1;
    }
    return (int)res;
}

int main(){
    int num=8;
    printf("%d", findComplement(num));
//    printf("%lf", pow(2,1));
    return 0;
}