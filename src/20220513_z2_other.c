#include <stdio.h>
#include "securec.h"
#define MAX_DEPT_NUM 10
#define MAX_CAND_NUM 10000
#define MAX_EMPLOY_NUM 201
typedef struct {
    int id;             // 编号
    int employNum;      // 招聘目标
    int progmThd;       // 机考门槛值
    int techThd;        // 技面门槛值
} DeptDemand;
typedef struct {
    int id;             // 编号
    int progmGrade;     // 机试分数
    int techGrade;      // 技面分数
    int isUsed;         // 是否录取状态，1为被录取，0为未录取
} Candidate;
typedef struct {
    int size;
    int employees[MAX_EMPLOY_NUM];
    int minProgm;       // 机考最小值
    int minTech;        // 技面最小值
} DeptEmployee;
// 1.先将人员进行排序，技术面分>机考分>编号较小 √
// 2.人员加个属性，是否被录取，1或0,1则不处理；另外deptemployee对应size和employees里作相应记录； √ 另外取两个值记录每个目标的最后录取人员的数值；
// 3.轮数设置为depedemand招聘目标的最大值，√并且按照最大值进行循环录取处理，
// 4.循环录取处理后进行补录操作，补录进行简单判断即可
int Compare(const void *a, const void *b)
{
    Candidate* aTmp = (Candidate*)a;
    Candidate* bTmp = (Candidate*)b;
    if (aTmp->techGrade != bTmp->techGrade) {
        return (bTmp->techGrade - aTmp->techGrade);
    } else if (aTmp->progmGrade != bTmp->progmGrade) {
        return (bTmp->progmGrade - aTmp->progmGrade);
    } else {
        return (aTmp->id - bTmp->id);
    }
}
void CircleRecruit(int deptNum, DeptDemand *deptDemands, int candidateNum,
        Candidate *candidateAbilities, DeptEmployee *deptEmployees)
{
    for (int j = 0; j < deptNum; j++) {
        for (int k = 0; k < candidateNum; k++) {
            // 不符合要求或已被录取或超出部门录取限制，此部门不录取，跳下一个部门
            if (candidateAbilities[k].progmGrade < deptDemands[j].progmThd \
                || candidateAbilities[k].techGrade < deptDemands[j].techThd \
                || candidateAbilities[k].isUsed == 1 \
                || deptDemands[j].employNum <= deptEmployees[j].size) {
                continue;
            }
            // 剩下的是符合要求的，将符合要求的人录取
            // 记录最后一个人的信息
            deptEmployees[j].minProgm = candidateAbilities[k].progmGrade;
            deptEmployees[j].minTech = candidateAbilities[k].techGrade;
            deptEmployees[j].employees[deptEmployees[j].size++] = candidateAbilities[k].id;
            // 标志位
            candidateAbilities[k].isUsed = 1;
            break;
        }
    }
    return;
}
// 待实现函数，在此函数中填入答题代码
// 生成的信息列表存于deptEmployees中，maxOutBufLen是最大数组长度，返回值为实际长度。
static int GetRecruitmentResult(int deptNum, DeptDemand *deptDemands, int candidateNum,
        Candidate *candidateAbilities, DeptEmployee *deptEmployees, int maxOutBufLen)
{
    int maxRound = 0;  // 最大面试轮数
    // 1.先将人员进行排序，技术面分>机考分>编号较小 √
    qsort(candidateAbilities, candidateNum, sizeof(Candidate), Compare);
    // 3.轮数设置为depedemand招聘目标的最大值
    for (int i = 0; i < deptNum; i++) {
        maxRound = fmax(deptDemands[i].employNum, maxRound);
    }
    // 按照最大值进行循环录取处理
    for (int i = 0; i < maxRound; i++) {
        CircleRecruit(deptNum, deptDemands, candidateNum, candidateAbilities, deptEmployees);
    }
    // 补录环节
    for (int i = 0; i < deptNum; i++) {
        for (int j = 0; j < candidateNum; j++) {
            if (candidateAbilities[j].isUsed == 0 && candidateAbilities[j].progmGrade == deptEmployees[i].minProgm \
                && candidateAbilities[j].techGrade == deptEmployees[i].minTech) {
                deptEmployees[i].employees[deptEmployees[i].size++] = candidateAbilities[j].id;
                // 标志位
                candidateAbilities[j].isUsed = 1;
                break;
            }
        }
    }
    return deptNum;
}
// 以下为考题输入输出框架，此部分代码不建议改动
static void OutputData(const DeptEmployee *deptEmployees, int outputSize)
{
    for (int i = 0; i < outputSize; i++) {
        printf("[");
        for (int j = 0; j < deptEmployees[i].size; j++) {
            printf("%s%d", ((j == 0) ? "" : " "), deptEmployees[i].employees[j]);
        }
        printf("]\n");
    }
}
int main(void)
{
    int deptNum;
    if (scanf_s("%d", &deptNum) != 1) { return -1; }
    static DeptDemand deptDemands[MAX_DEPT_NUM];
    for (int i = 0; i < deptNum; i++) {
        deptDemands[i].id = i;
        if (scanf_s("%d %d %d", &deptDemands[i].employNum,
                &deptDemands[i].progmThd, &deptDemands[i].techThd) != 3) {
            return -1;
        }
    }
    int candidateNum;
    if (scanf_s("%d", &candidateNum) != 1) { return -1; }
    static Candidate candidateAbilities[MAX_CAND_NUM];
    for (int i = 0; i < candidateNum; i++) {
        candidateAbilities[i].id = i;
        if (scanf_s("%d %d", &candidateAbilities[i].progmGrade, &candidateAbilities[i].techGrade) != 2) {
            return -1;
        }
    }
    DeptEmployee deptEmployees[MAX_DEPT_NUM] = { 0 };
    int outputSize = GetRecruitmentResult(deptNum, deptDemands, candidateNum, candidateAbilities,
            deptEmployees, MAX_DEPT_NUM);
    OutputData(deptEmployees, outputSize);
    return 0;
}