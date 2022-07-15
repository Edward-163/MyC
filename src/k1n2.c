#include <sec_api/stdio_s.h>
#include <malloc.h>
#include <string.h>

#define MAX_RET_SIZE 3

static int GetTop3Num(const char *inputStr, int *outBuf) {
    int len = 0;
    while (inputStr[len] != '\0') {
        len++;
    }
    len = strlen(inputStr);
    int *arr = (int *) malloc(sizeof(int) * len);
    int count = 0;

    for (int a = 0; a < len; a++) {
        if ('0' <= inputStr[a] && inputStr[a] <= '9') {

            int sum = inputStr[a] - '0';

            int b = a + 1;
            while (b < len && '0' <= inputStr[b] && inputStr[b] <= '9') {
                sum *= 10;
                sum += inputStr[b] - '0';
                b++;
            }

            if (a - 1 >= 0 && inputStr[a - 1] == '-') {
                sum *= -1;
            }

            a = b;
            //printf("%d",sum);
            arr[count++] = sum;
        }
    }

    int min = count < 3 ? count : 3;
    for (int c = 0; c < min; c++) {
        for (int d = c + 1; d < count; d++) {
            if (arr[d] > arr[c]) {
                int temp = arr[c];
                arr[c] = arr[d];
                arr[d] = temp;
            }
        }
    }

    /**
     * 错误解析:该函数里面outBuf就临时变量,保存的是main看outBuf数组的地址
     * 对这个临时变量outBuf,它最开始接收main看outBUf数组的地址,
     * malloc后,它指向了其他内存
     */
//    outBuf=(int*)malloc(sizeof(int)*min);
//    outBuf
    for (int e = 0; e < min; e++) {
        //printf("%d",arr[e]);//right
        outBuf[e] = arr[e];//bug??
//        printf("%d", outBuf[e]);//right
    }
    return min;
}

//给出str,解析出数字,降序且取前几位
int main(void) {
    /// 不初始赋值,元素全是随机值,初始赋值{0},全部元素就是0了,很方便
//    char inputStr[101] = {0};
    /// bug:segmentation falut,字符数组强烈建议写char arr[],不要写char * arr
//    char inputStr[101] = "a56b-6-8()_56!@$-a";
    char *inputStr = "a56b-6-8()_56!@$-a";
    int outBuf[MAX_RET_SIZE];
    int count = GetTop3Num(inputStr, outBuf);
    printf("[");
    for (int i = 0; i < count; i++) {
        (void) printf("%d%s", outBuf[i], (i < count - 1) ? " " : "");
    }
    printf("]");

    return 0;
}
