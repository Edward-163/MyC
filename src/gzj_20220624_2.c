/*
 *
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "uthash.h"


/*
 题干：
    给定仅由小写字母组成的字符串数组words，找出每个字符串都出现的字符，若一字符在所有字符串中多次出现则输出多次，请以字典序输出左右字符，并以字符串形式返回。
 * 示例1：
    输入：words = ["smooth","common","mooorings"]
    输出："moo"
 * 解释：
    m 在 "smooth" 中出现 1 次，在 "common" 中出现 2 次，在 "mooorings" 中出现 1 次，所以只有 1 个 m 符合要求。
    o 在 "smooth" 中出现 2 次，在 "common" 中出现 2 次，在 "mooorings" 中出现 3 次，所以有 2 个 o 符合要求。
    其他字符没有在 words 的每个字符串中都出现。因此按照a-z的顺序输出为 "moo"（不能输出为 "oom"）。
 * 示例2：
    输入：words = ["softwares"]
    输出："aeforsstw"
 * 提示：
    1 <= words.length <= 100
    1 <= words[i].length <= 100
    words[i][j]均为小写字母
 */

int main()
{

    return 0;
}