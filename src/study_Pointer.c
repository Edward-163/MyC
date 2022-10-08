#include <stdio.h>
#include <string.h>

void partialInit(){
    // 可以只给一部分元素赋值，这叫“不完全初始化”。例如：
    // 定义的数组 a 有 5 个元素，但花括号内只提供两个初值，这表示只给前面两个元素 a[0]、a[1] 初始化，而后面三个元素都没有被初始化。不完全初始化时，没有被初始化的元素自动为 0。
    int a[5] = {1, 2};
    for (int i = 0; i < 5; ++i){
        printf("%d ",a[i]);fflush(stdout);
    }
    printf("\n");fflush(stdout);
    printf("%s \n","不完全初始化结束<<<<<<<<<");fflush(stdout);
}
void fn(char* p){
//    p[1]='b';//sig
//    *(p+1)=' ';//sig
    p[1] = 'b';
    printf("%c",p[1]);
}
/**
 char* p        char arr[]    区别
 pointer只知道指向,不知道str大小,数组是明确知道大小的,这点在sizeof上有所体现
 */
void pointerStr(){
    char *str1 = "abcd1234";
    char *str2 = "abcd1234";
    char str3[] = "abcd1234";
    char str4[] = "abcd1234";
    printf("%p %p\n",str1,str2);
    printf("%p %p\n",str3,str4); // 两指针的值是同一个字面量的地址
    printf("%d \n",sizeof(str1));fflush(stdout); // 指针的大小和32位64位相关
    printf("%d \n",sizeof(str3));fflush(stdout); // 数组大小

    char * pointer="this is a test";
    char ch;
    int len=0;
    int i=0;
    while((ch=pointer[++i])!='\0'){
        if(ch=='a')continue;
        len++;
    }
    printf("len is %d \n",len);fflush(stdout);
}
/**
 str字面量长度       花括号数组长度
 */
void arrLenLiteralFlower(){
    char a[] = "abc";
    char b[] = {'a','b','c'};
    printf("字面量所占字节%d \n",sizeof(a));fflush(stdout); //
    printf("花括号所占字节%d \n",sizeof(b));fflush(stdout); //
    printf("字面量strlen %d \n",strlen(a));fflush(stdout); //
    printf("花括号strlen %d \n",strlen(b));fflush(stdout); // 随机值,啥时候遇到\0就结束了

}

int main(){
    // pointerStr();
    arrLenLiteralFlower();
    partialInit();
    /**
     在C和C字符串中,字面值是无名对象,左值.由于它是一个对象,您可以使用指针指向它.同时{1,2,3,4}只是一个不代表对象的句法结构.它只是形成聚合初始化器语法的正式字符序列.
     */
//    char* p = {'h','y'};//不能看,不能改,写法错了
//    char* p = "hyj";//可以看,不能改,right
//    Fn(p);

    int a=2;
    char arr[a];
//    char g_arr[]={'h','y'};
//    Fn(g_arr);

    /**
     p只是声明了指向int型的指针，声明指针系统是不会分配内存的，所以*p没有内存来存常量9的值，自然发生错误，int *p = NULL; p = (int*)malloc(sizeof(int )); *p = 9这样就不会有错
     永润不要对NULL解引用!!
     */
     int * p=NULL;
     *p=9;//sig

    return 0;
}