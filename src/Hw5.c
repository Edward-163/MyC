#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
 任意10进制正小数m转换成n进制的正小数，小数点后保留10位小数
    0.795 3
    0 0     都输0代表输入结束
    0.2101101122

   推到过程不要去背,我自己举个例子
   0.75==0.5+0.25转2进制    0.11
   0.75*2==1.5   取小数0.5*2==1.0  取小数0,0结束了不算了
   0.11*2==1.1        0.1*2==1.0
 */
int main() {
    double f;
    double fn;
    int n;
    ///头疼的是现在不知道scanf_s源码注释在哪看??
//    while (scanf_s("%lf %d", &f, &n) != EOF) {
    while (scanf_s("%lf %d", &f, &n) != -1) {
        if (n == 0)break;
//        f=0.75;
//        n=2;
        printf("0.");
        for (int i = 0; i < 10; i++) {
            fn = f * n;
            printf("%d", (int)fn);
            fflush(stdout);
            f = fn - (int)fn;
        }
        printf("\n");
        fflush(stdout);
    }
    return 0;
}