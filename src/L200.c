#include <stdio.h>
#include <stdlib.h>

/*
 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。
 
示例 1：
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
示例 2：
输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
 
提示：
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 '0' 或 '1'
 */
typedef struct {
    int row;
    int col;
} ParentCoor;
ParentCoor **g_pc; // set
ParentCoor find(int row, int col)
{
    int rtmp = row;
    int ctmp = col;
    // 若当前坐标的父坐标不是自己,说明不是顶层节点,继续找
    while (!(row == g_pc[row][col].row && col == g_pc[row][col].col)) {
        /// 此bug好难找呀!!!,自己改变了row的值,影响而第二次g_pc[row改动了][col]
        // row = g_pc[row][col].row;
        // col = g_pc[row][col].col;
        int rr = g_pc[row][col].row;
        int cc = g_pc[row][col].col;
        // 步进
        row = rr;
        col = cc;
    }
    // 压缩路径 一加压缩就错,我想找出原因
    g_pc[rtmp][ctmp].row = row;
    g_pc[rtmp][ctmp].col = col;
    ParentCoor root = {row, col};
    return root;
}

void unio(ParentCoor pc1, ParentCoor pc2)
{
    // 若2个节点的根parent不同,则合并,
    if (!(pc1.row == pc2.row && pc1.col == pc2.col)) {
        /// bug 没有改变pc元素的值
        // pc1.row = pc2.row;
        // pc1.col = pc2.col;
        g_pc[pc2.row][pc2.col].row = pc1.row;
        g_pc[pc2.row][pc2.col].col = pc1.col;
    }
}

int numIslands(char **grid, int size, int *colsize)
{
    // construct g_pc
    g_pc = malloc(sizeof(ParentCoor *) * size);
    for (int row = 0; row < size; ++row) {
        g_pc[row] = malloc(sizeof(ParentCoor) * colsize[row]);
    }
    // init g_pc 每个点的父坐标就是自己
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < colsize[row]; ++col) {
            g_pc[row][col].row = row;
            g_pc[row][col].col = col;
        }
    }
    // 遍历
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < colsize[row]; ++col) {
            if (grid[row][col] == '1') {
                // for (int row = 0; row < size; ++row) {
                //     for (int col = 0; col < colsize[row]; ++col) {
                //         printf("%d_%d\t", g_pc[row][col].row, g_pc[row][col].col);
                //         fflush(stdout);
                //     }
                //     printf("\n");
                //     fflush(stdout);
                // }
                // printf("------\n");
                // fflush(stdout);
                /// 从这行可以看出,find和union还是分开比较好,find1只调用一次
                ParentCoor find1 = find(row, col);
                if (0 <= row - 1 && grid[row - 1][col] == '1') {
                    ParentCoor find2 = find(row - 1, col);
                    unio(find1, find2);
                }
                if (row + 1 <= size - 1 && grid[row + 1][col] == '1') {
                    ParentCoor find2 = find(row + 1, col);
                    unio(find1, find2);
                }

                if (0 <= col - 1 && grid[row][col - 1] == '1') {
                    ParentCoor find2 = find(row, col - 1);
                    unio(find1, find2);
                }
                if (col + 1 <= colsize[row] - 1 && grid[row][col + 1] == '1') {
                    ParentCoor find2 = find(row, col + 1);
                    unio(find1, find2);
                }

            }
        }
    }

    // 统计根parent数量
    int ans = 0;
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < colsize[row]; ++col) {
            if (grid[row][col] == '1' && row == g_pc[row][col].row && col == g_pc[row][col].col) {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    // @formatter:off
    // char g_arr[][2] = {{'1', '1'}, {'1', '0'}};
    // char g_arr[][5] = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    char arr[][5] = {{'1','0','1','1','1'}, {'1','0','1','0','1'}, {'1','1','1','0','1'}};
    int size=sizeof(arr)/sizeof(arr[0]);
    char* grid[size];
    int *colsize = malloc(sizeof(int)*size);
    for (int i = 0; i < size; ++i){
        grid[i]=arr[i];
        colsize[i]=sizeof(arr[i])/sizeof(arr[i][0]);
    }

    int ans = numIslands(grid,size,colsize);
    printf("%d ",ans);fflush(stdout);
    return 0;
    // @formatter:on
}

