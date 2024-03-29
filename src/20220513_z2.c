#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include "securec.h"
#include "uthash.h"


/*
 某次招聘活动中，共有 deptNum 个部门在招人，每个部门都设定了自己的：招聘目标人数、机考和技面的最低分要求。共有 candidateNum 个应聘者，每个应聘者都有两项能力值：机考分数和技面分数。
招聘规则如下：
l  选人规则：首先达到部门的门槛要求，即机考和技面分数均大于等于对应最低分要求；然后选人：优先录取技面分数较高的；若技面分数相同，则录取机考分数较高的；若机考分数也相同，则录取应聘者编号较小的。
l  先进行常规录取，此阶段采用轮询录取方式，以完成招聘目标：
Ø  每一轮按部门编号从小到大轮询，部门遵照选人规则录取一人，若无符合要求者则放弃；若已招满（或已无人可录），不再选人；
Ø  不断轮询，直至所有部门都完成招聘目标（但不能超过）、或未招满但已无人可录。
l  在常规录取阶段结束后，各部门均尝试进行一次补录，但最多补录一人（即可能比招聘目标多一人）：
Ø  按部门编号从小到大的顺序进行补录；
Ø  如果还有应聘者与该部门常规录取的最后一名应聘者能力相同（即机考和技面分数均相同），则部门参照选人规则补录一人即结束招聘（即使未成功补录，也结束招聘）。
现给出部门的招聘需求deptDemands，以及应聘者的信息 candidateAbilities。请按部门编号从小到大依次输出所录取人员，部门内所录取人员按录取顺序输出（若无录取人员，输出空序列 []）。
输入
第一行的整数表示招聘部门个数 deptNum，1 <= deptNum <= 10
随后 deptNum 行依次表示每个部门的要求，记录于 deptDemands 数组中，deptDemands[i] 表示编号为 i 的部门的目标人数 机考最低分 技面最低分，目标人数范围 [1, 200]，最低分范围 [100, 150]
接下来一行的整数表示应聘者数量 candidateNum，1 <= candidateNum <= 10000
随后 candidateNum 行依次表示每个应聘者的信息，记录于数组 candidateAbilities 中，candidateAbilities[j] 表示编号为 j 的应聘者的机考分数 技面分数，机考和技面分数取值范围 [100, 200]
输出
按部门编号从小到大，每行输出一个部门所录取人员的编号；若没有录取人员，输出空序列 [] 。
样例
输入样例 1
2
2 130 120
1 150 150
6
150 100
160 190
150 200
200 190
160 190
160 190
输出样例 1
[2 1 4]
[3]
 提示样例 1
招聘录取过程解释如下：
https://oj.rnd.huawei.com/public/upload/da9a2103bc.png
l  第一轮：按部门编号从小到大，部门0 先选人，按选人规则优先录取了应聘者2 。然后部门1选人，优先录取了应聘者 3 ，部门1招满、退出轮询。
l  第二轮：部门0 选人，应聘者1、4、5 的能力值都相同，录取编号小的应聘者1 。
两轮后部门0 和 部门1 都达到人数目标，完成常规录取。
l  补录：部门0 先选人，应聘者 4 和 5 与此前最后录取的应聘者1 的能力值相同，按规则补录一人（应聘者4）后结束招聘。 然后部门1 补录，没有人与此前最后录取的应聘者3 具备相同的能力值。
招聘结束后：部门0依次录取人员为 2 1 4，部门1依次录取人员为 3 （应聘者0 和 应聘者5 未被任何部门录取）
输入样例 2
2
2 100 150
1 150 100
2
100 120
150 100
输出样例 2
[]
[1]
提示样例 2
两个应聘者都不满足部门0的门槛要求，因此部门0未录取人员。
应聘者1满足部门1的门槛要求，因此部门1录取了应聘者1 。
输入样例 3
3
1 100 100
1 100 120
1 100 150
5
100 200
100 200
100 200
100 200
100 200
输出样例 3
[0 3]
[1 4]
[2]
提示样例 3
常规录取阶段，三个部门分别录取应聘者0、1、2；
补录阶段，部门0先选人，补录了应聘者3； 剩下应聘者4，满足部门1和部门2的补录条件，但部门1先选人。
 */
typedef struct Dept {
    int did;
    int picknum; // 招人数
    int exam;
    int inte;
    int *arr;
    int arrsize;
    int lastCandIdx;
    int over;
} Dept;
typedef struct Cand {
    int cid; // third
    int exam; // second
    int inte; // first
    int picked;
} Cand;

int cmp(Cand *a, Cand *b)
{
    if (a->inte == b->inte) {
        if (b->exam == a->exam) {
            return a->cid - b->cid;
        }
        return b->exam - a->exam;
    }
    return b->inte - a->inte;
}

void foo(int deptsize, Dept *depts, int candsize, Cand *cands)
{
    for (int d = 0; d < deptsize; ++d) {
        if (depts[d].over == 1 || depts[d].arrsize >= depts[d].picknum) {
            continue;
        }
        bool nochoice = true;
        for (int c = 0; c < candsize; ++c) {
            if (cands[c].picked == 1 || cands[c].inte < depts[d].inte || cands[c].exam < depts[d].exam) {
                continue;
            }
            depts[d].arr[depts[d].arrsize++] = cands[c].cid;
            depts[d].lastCandIdx = c;
            cands[c].picked = 1;
            nochoice = false;
            break;
        }
        if (nochoice || depts[d].arrsize >= depts[d].picknum) {
            depts[d].over = 1;
        }
    }
}

void Bulu(int deptsize, Dept *depts, int candsize, Cand *cands)
{// 补录
    for (int d = 0; d < deptsize; ++d) {
        int lastCandId = depts[d].lastCandIdx;
        for (int c = 0; c < candsize; ++c) {
            if (cands[c].picked == 0 && depts[d].lastCandIdx != -1 && cands[c].inte == cands[lastCandId].inte &&
                cands[c]
                        .exam == cands[lastCandId].exam) {
                // bug 存cid会因为cands的排序而不方便再从cands中取出
                depts[d].arr[depts[d].arrsize++] = cands[c].cid;
                cands[c].picked = 1;
                break;
            }
        }
    }
}

void PrintAns(int deptsize, Dept *depts)
{// print ans
    for (int d = 0; d < deptsize; ++d) {
        for (int a = 0; a < depts[d].arrsize; ++a) {
            printf("%d ", depts[d].arr[a]);
            fflush(stdout);
        }
        printf("\n");
        fflush(stdout);
    }
}

int main()
{
    // @formatter:off
    /*
2
2 130 120
1 150 150
6
150 100
160 190
150 200
200 190
160 190
160 190
[2 1 4]
[3]
     */
    int deptsize;
    int round=0;
    scanf("%d",&deptsize);
    Dept depts[deptsize]; // 局部定义数组,元素值随机
    for (int i = 0; i < deptsize; ++i){
        depts[i].did=i;
        scanf("%d %d %d",&depts[i].picknum,&depts[i].exam,&depts[i].inte);
        depts[i].arr=malloc(sizeof(int)*(depts[i].picknum+1));
        depts[i].arrsize=0;
        depts[i].lastCandIdx=-1;
        depts[i].over=0;
        if(depts[i].picknum>round){
            round=depts[i].picknum;
        }
    }
    int candsize;
    scanf("%d",&candsize);
    Cand cands[candsize];
    for (int i = 0; i < candsize; ++i){
        cands[i].cid=i;
        scanf("%d %d",&cands[i].exam,&cands[i].inte);
        cands[i].picked=0; // 0 not picked
    }
    qsort(cands,candsize,sizeof(Cand),cmp);

    // 学别人的:1 录取和补录拆分 2 结束条件,招几轮==部门的picknum的max,我从一开始就没这么想,我第一时间想到的结束条件是所有部门都招完了
    for(int r=0;r<round;r++){
        foo(deptsize, depts, candsize, cands);
    }

    Bulu(deptsize, depts, candsize, cands);PrintAns(deptsize, depts);

    return 0;
    // @formatter:on
}




























/*

 */