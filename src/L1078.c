#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **findOcurrences(char *text, char *first, char *second, int *returnSize) {
    int tlen = strlen(text);
    char *split = strtok(text, " ");
    char *words[tlen];
    int widx = 0;
    while (split != NULL) {
        words[widx] = split;
        widx++;
        split = strtok(NULL, " ");
    }
    //结束后widx刚好也是words的size
    /**
     bug:res局部变量,回main后res为空
     bug:因为数组名只是代表数组第一个元素的地址的值，比如数组 int a[10]，a实际上就是 &a[0]，
        它只是一个值，就像 5 这类东西一样，是不能作为左值的，不能给它赋值。在任何时候都不能把数组名直接放在等号的左边
     */
    char** res=(char**)malloc(sizeof(char*)*tlen);//Variable-sized object may not be initialized
//    res=(char*)malloc(sizeof(char*)*tlen);//Array type 'char *[tlen]' is not assignable
    int ridx = 0;
    for (int a = 0; a < widx - 2; a++) {
        if (strcmp(words[a], first) == 0 && strcmp(words[a + 1], second) == 0) {
            res[ridx] = words[a + 2];
            ridx++;
        }
    }
    *returnSize = ridx;
    return res;
}

int main() {
    /**
     https://blog.csdn.net/chenkaixin_1024/article/details/53150951?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1-53150951-blog-46334695.pc_relevant_default&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-1-53150951-blog-46334695.pc_relevant_default&utm_relevant_index=1
     C语言中并不存在字符串类型，有的只是字符串常量，而且字符串常量是存放在静态全局区上的，而一般局部变量，
     形式参数则是保存在栈区上的。因此在这里字符指针变量arr以及字符数组arr[]都是在栈区上的，而对于char* g_arr="hello world";
     而言，仅仅是定义了一个指针并让它指向静态区上的字符串常量"hello world"【即arr上保存的是"hello world"的首字符地址】，
     而stcpy(g_arr,"hello");则是要将"hello world"改成"hello"，但因为是常量无法修改，所以程序崩溃
     */
//    char *text = "alice is a good girl she is a good student";
    char text[] = "alice is a good girl she is a good student";
    char first[] = "a";
    char second[] = "good";
    int *returnSize = (int *) malloc(sizeof(int));
    char** res=findOcurrences(text, first, second,returnSize);
    for(int a=0;a<*returnSize;a++){
        printf("%s\n",res[a]);
    }
    return 0;
}