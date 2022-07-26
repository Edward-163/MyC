#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

static int cmp(const void *a, const void *b) {
    char* aa=(char*)a;
    char* bb=(char*)b;
    return *bb-*aa;
    //void*转成char*  指针再解引用   用内容相减,逆序排列
    return *((char*)b) - *((char*)a);
}

int maximumSwap(int num){
    if (num == 0) {
        return 0;
    }
    char str0[16] = {0};
    char str[16] = {0};

    sprintf(str0, "%d", num);
    sprintf(str, "%d", num);

    int len = (int) strlen(str);

    qsort(str, len, sizeof(char), cmp);

    for (int i = 0; i < len; i++) {
        if (str[i] != str0[i]) {
            ///c就[]得优先级1级,&优先级2,从要交换的位置开始的str逆向找字符  类似的还有strchr(char* str,int c)正向找字符c
            char *p = strrchr(&str0[i], str[i]);
            *p = str0[i];
            str0[i] = str[i];
            break;
        }
    }
    ///把str转成int 类似atof str转float atol str转long atoll str转long long
    return atoi(str0);
}

int maximumSwap2(int num){
    int numcopy=num;
    ///bug:不能这么写
//    int g_arr[9]=(int*)malloc(sizeof(int)*9);
    int arr[9];
//    int* g_arr=(int*)malloc(sizeof(int)*9);
    int aidx=0;
    while(num!=0){
        arr[aidx++]=num%10;
        num/=10;
    }
    /***
     * bug如1993,我会把第二个9和首位交换,
     */
    for(int a=aidx-1;a>=1;a--){
        int max=arr[a];
        int maxidx=a;
        for(int b=a-1;b>=0;b--){
            if(arr[b]>max){
                max=arr[b];
                maxidx=b;
            }
        }

        if(max!=arr[a]){
            int tmp=arr[a];
            arr[a]=arr[maxidx];
            arr[maxidx]=tmp;

            int res=0;
            for(a=aidx-1;a>=0;a--){
                int mm=(int)pow(10.0,a);
                res+=arr[a]*mm;
            }
            return res;
        }
    }

    return numcopy;
}

int main(){
    char str[3] = {0};
    sprintf(str,"%d",1234);//str[0]=='1' str[1]=='2' 注意str太短会接受不了低位数字
    int len=strlen(str);
    printf("%d",len);

//    printf("%d",maximumSwap(2736));
    printf("%d",maximumSwap(9973));
    return 0;
}