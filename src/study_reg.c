#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include <regex.h>


/**   reg
 leetcode上C/C++可以使用GNU的正则库（ilearning/OJ待定）
一、代码示例（仅功能演示，代码规范请同学们自行把握）
#include <stdio.h>
#include <sys/types.h>
#include <regex.h>

void TestCRegex()
{
    int status, i;
    int cflags = REG_EXTENDED;
    regmatch_t pmatch[1];
    const size_t nmatch = 1;
    regex_t reg;
    const char * pattern = "^\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*.\\w+([-.]\\w+)*$";
    char * buf = "hyj@qq.com";
    regcomp(&reg, pattern, cflags); // 编译正则模式
    status = regexec(&reg, buf, nmatch, pmatch,0); // 执行正则表达式和缓存的比较
    if (status == REG_NOMATCH )
        printf("No match");
    else if (0 == status) {
        printf("比较成功:");
        for (i = pmatch[0].rm_so; i < pmatch[0].rm_eo; ++i) putchar(buf[i]);
        printf("");
    }
    regfree(&reg);
}

二、函数说明：
int regcomp(regex_t *preg, const char *pattern, int cflags)
功能:将要进行匹配的正则表达式pattern进行编译，做匹配前的准备工作
参数      preg, 输出参数，用来保存编译后的正则表达式结果
            pattern, 输入参数，传入要进行编译的正则表达式的字符串
            cflags, 输入参数，用来指定正则表达式匹配过程中的一些选项
返回值:编译成功返回0，失败返回非0的错误码
 
int regexec(const regex_t *preg, const char *string, size_t nmatch, regmatch_t pmatch[],  int eflags)
功能:用来检测字符串string是否匹配正则表达式preg
参数: preg, 输入参数，在(1)regcomp中编译好的正则表达式规则
            string, 输入参数，用来被匹配的字符串
            nmatch, 输入参数，用来指定pmatch参数所对应的数组的长度
            pmatch, 输出参数，用来输出在string中匹配preg的具体位置
            eflag, 输入参数，用来指定正则表达式匹配过程中的一些选项
返回值: 如果string匹配preg所指定的规则，则返回0， 否则返回非0

size_t regerror(int errcode, const regex_t *preg, char *errbuf, size_t errbuf_size)
功能:用来把在regcompt和regexec中产生的错误码转化成字符串形式的错误信息
   参数: errcode, 输入参数，在regcomp或regexec调用中返回的错误码
            preg, 输入参数，与错误码所对应的编译过的正则表达式结构
            errbuf, 输出参数，用来返回错误信息的buffer，如果buffer不够所需大小，错误信息将被截断
            errbuf_size, 输入参数，返回错误信息的buffer的大小
返回值: 如果errbuf_size为0，那么regerror返回错误信息所需要的buffer的大小

void regfree (regex_t *preg)
功能: 用来释放由regcomp编译时生成的preg结构所占用的内存
            参数: preg, 输入参数，由regcomp编译时生成的正则表达的结构指针
返回值: 无

三. 使用GNU Regex Library的一些注意事项
（1）regcomp与regfree必须配对使用，要不然会造成内存泄漏（类比malloc/free, new/delete)
（2）regex_t结构：把字符串形式的正则表达式编译成regex_t这样的一个结构，方便后续的匹配工作
（3）regmatch_t结构：用来表示正则表达式中字符串中匹配的位置的结构，用起始位置的偏移量来表示的
（4）flags：用来配置匹配过程中的一些选项, 指定如何匹配，具体参见：http://www.opengroup.org/onlinepubs/007908799/xsh/regcomp.html
（5）使用该库需要包含的头文件：sys/types.h和regex .h
 */
bool patternMatchStr(const char* pattern,const char* str){
    bool result=false;
    regex_t regex;
    int compileSuccReturn0 = regcomp(&regex, pattern, REG_EXTENDED);//????build error
    if(compileSuccReturn0){
        printf("compile fail\n");fflush(stdout);
    }else{
        const size_t nmatch = 1;
        regmatch_t pmatch[1];
        int matchSuccReturn0 = regexec(&regex, str, nmatch, pmatch, 0);
        if(matchSuccReturn0==0){
            result=true;
            for (int i = pmatch[0].rm_so; i < pmatch[0].rm_eo; i++){    //遍历输出匹配范围的字符串
                printf("%c", str[i]);fflush(stdout);
            }
            printf("\n");fflush(stdout);
        }
    }
    regfree(&regex);
    return result;
}
int main() {
    char* pattern="\\w{3}";
    char* str="hyj";

    printf("%d ", patternMatchStr(pattern,str));fflush(stdout);
    return 0;
}