cmake_minimum_required(VERSION 3.0)
project(chyj)
#set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-std=c99")
# 学习网上相对目录,引入三方头
#引入uthash遇到的大坑,在公司修改过git的user.name和user.email,起初以为是name和email问题,
#http.postBuffer加大也没用,git config --system --unset credential.helper没用,win删除gitee相关凭证也没用
#新建文件夹clone后,用新的.git目录覆盖自己的.git目录没用,还是推送不了uthash目录,
#网上说要读写权限,gitee仓库邀请成员需要gitee账号,我只是改个name和email,我既没有申请第二个gitee账号,也和第二个gitee账号没毛关系,
#最终最笨的方法只能是用自己账号登录gitee,手动把otherHead/uthash/src创建好,然后把需要的uthash.h等头上传,成功后,最后再本地push,意外发现其他的doc目录和其他杂碎文件都push成功了.

#使用尖括号< >，编译器会到系统路径下查找头文件；通常是include目录,如用minGw编译.c
#而使用双引号" "，编译器首先在当前目录下查找头文件，如果没有找到，再到系统路径下查找

# 库name全局唯一,
# add_libraty(<name> [STATIC|SHARED] [source1] [source2...])

# 指定 .h 文件所在的目录
include_directories(${PROJECT_SOURCE_DIR}/include/uthash-2.3.0/src/)
include_directories(${PROJECT_SOURCE_DIR}/huawei_secure_c/include)
# 收集指定目录中所有源文件的名称，并将列表存储在提供的变量中
aux_source_directory(${PROJECT_SOURCE_DIR}/huawei_secure_c/src SEC_SRC)
# cmake 官网中默认变量
message(CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR})
message(CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR})
message(PROJECT_BINARY_DIR ${PROJECT_BINARY_DIR})
message(PROJECT_SOURCE_DIR ${PROJECT_SOURCE_DIR})
# 全局递归搜索/src目录下的A.c,并把绝对路径追加到abc变量(看下面的例子,此处abc应该是个集合变量)中
#file(GLOB_RECURSE abc ${PROJECT_SOURCE_DIR}/src/Hello.c)
# message相当于cmake的打印语句 C:/Users/h30029170/CLionProjects/chyj/bin/Hello.c
#message(${abc})
# 遍历项目根目录下所有的.c文件的绝对路径,并追加到files集合中    https://zhuanlan.zhihu.com/p/157646534
file(GLOB_RECURSE files ${PROJECT_SOURCE_DIR}/src/*.c)
foreach (file ${files})
    #    message(filPath\t${file})
    #    正则中\1代表获取第一个()匹配的内容,\2以此类推
    string(REGEX REPLACE ".*/(.+)\\.c" "\\1" name ${file})
    #    message(exeName\t${name})

    # 入门参数列表如右 add_executable(<name> [source1] [source2...])
    # 利用sourcesd等构建出可执行文件(名必填且唯一)
    # 自己写得.c的绝对路径就是${file},而自己写的.c引用三方的.c不就是${SEC_SRC}
    add_executable(${name} ${file} ${SEC_SRC})

    #    我猜空格在cmake中算特殊字符,需要\转义
    message(\ \ \ \ 当前目录下/src/${name}.c被编译输出到当前目录下/bin/${name}.exe)
endforeach ()
# 测试修改之前提交中某个文件的内容2
