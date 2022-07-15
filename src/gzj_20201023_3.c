#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"
#include <regex.h>
/*
 addEvent(int startDate, String content, int num, int period) – 自日期 startDate 开始（startDate 包含在内），添加 num 个以 period 为间隔周期待办事项 content。例如若命令为 addEvent(0,"a",4,2)，表示于日期 0，2，4，6 分别添加待办事项 "a"。
    返回本次操作共计新增待办事项的数量。若部分日期上已存在该事项，无论该事项是否设置为已完成，这些日期不需添加该事项。
         finishEvent(int date, String content) – 将日期 date 上的 content 事项设置为已完成。
    若该日期上不存在此事项，或该日期上此事项已完成，返回 false；
    若设置操作完成，则返回 true。
         removeEvent(int date, String content) – 移除日期 date 上的 content 事项。
    若该日期上不存在此事项，返回 false；
    若移除操作完成，则返回 true。
         queryTodo(int startDate, int endDate) – 查询从 startDate 到 endDate（起止日期均包含在内）这段日期内所有的未完成的 content 事项，并将查询到的事项以字符串形式按日期升序记于数组后返回，若查询到相同日期的多条待办事项，则将其按字典序排列。
示例 1：
输入：["MemoSystem","addEvent","queryTodo","finishEvent","removeEvent"]
[[],[2,"eat a burger",2,3],[0,5],[2,"eat a burger"],[2,"eat a burger"]]
输出：[null,2,["eat a burger","eat a burger"],true,true]
解释：
MemoSystem ms = MemoSystem();
ms.addEvent(2,"eat a burger",2,3); // 自日期 2 开始，添加 2 个间隔周期为 3 的待办事项 "eat a burger"，即在日期 2、5 添加该待办事项。本次操作共新添加了 2 个待办事项，返回 2
ms.queryTodo(0,5); //查询自日期 0 至日期 5 的所有未完成的事项，返回数组 ["eat a burger","eat a burger"]
ms.finishEvent(2,"eat a burger"); // 将系统中日期为 2 的待办事项 "eat a burger" 设置为已完成，返回 true
ms.removeEvent(2,"eat a burger"); // 移除系统中日期为 2 的事项 "eat a burger"，返回 true
注：输出中的 null 表示此对应函数无输出（其中：C 的构造函数有返回值，但是也是无需输出）
示例 2：
输入：
["MemoSystem","addEvent","addEvent","removeEvent","finishEvent","addEvent","addEvent","queryTodo","queryTodo","finishEvent","addEvent"]
[[],[2,"save files",1,1],[2,"eat a burger",1,1],[2,"drink water"],[1,"drink water"],[0,"eat a burger",5,2],[2,"save files",1,1],[0,4],[10,11],[2,"eat a burger"],[2,"eat a burger",1,1]]
输出：[null,1,1,false,false,4,0,["eat a burger","eat a burger","save files","eat a burger"],[],true,0]
解释：
MemoSystem ms = MemoSystem();
第 3 个命令 ms.addEvent(2,"eat a burger",1,1); // 同一个日期可以增加不同的待办事项，本次操作共新添加了 1 个待办事项，返回 1
第 6 个命令 ms.addEvent(0,"eat a burger",5,2); // 自日期 0 开始，添加 5 个间隔周期为 2 的待办事项 "eat a burger"，即在日期 0，2，4，6，8 添加该待办事项。由于日期 2 的记录中已存在该事项，因此本次操作共新添加了 4 个待办事项，返回 4
第 8 个命令 ms.queryTodo(0,4); // 查询自日期 0 至日期 4 的所有未完成的事项，按日期返回，其中日期 2 的待办事项需按字典序排列，返回数组 ["eat a burger","eat a burger","save files","eat a burger"]
第 9 个命令 ms.queryTodo(10,11); // 查询自日期 10 至日期 11 的所有未完成的事项，返回空数组 []
注：输出中的 null 表示此对应函数无输出（其中：C 的构造函数有返回值，但是也是无需输出）
提示：
1 <= addEvent,finishEvent,removeEvent,queryTodo 总操作数 <= 1000
0 <= startDate <= endDate <= 1000
0 < num, period, 0 <= startDate + (num - 1) * period <= 1000
1 <= content.length <= 20 ，仅包含小写字母、大写字母与空格
0 <= date <= 1000
 */
int main() {
    return 0;
}