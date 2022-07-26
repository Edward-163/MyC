#include <stdio.h>
void fn(char* p){
//    p[1]='b';//sig
//    *(p+1)=' ';//sig
    p[1] = 'b';
    printf("%c",p[1]);
}
int main(){
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