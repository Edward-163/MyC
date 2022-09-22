#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int GetInt(char **matrix, int r, int c, int col, int count)
{
    int left = c - 1;
    while (left >= 0 && matrix[r][left] != 'B') {
        if (matrix[r][left] == 'P') {
            count++;
        }
        left--;
    }
    int righ = c + 1;
    while (righ < col && matrix[r][righ] != 'B') {
        if (matrix[r][righ] == 'P') {
            count++;
        }
        righ++;
    }
    return count;
}

int Cal(char **matrix, int r, int c, int row, int col)
{
    int count = 0;
    count = GetInt(matrix, r, c, col, count);
    int up = r - 1;
    while (up >= 0 && matrix[up][c] != 'B') {
        if (matrix[up][c] == 'P') {
            count++;
        }
        up--;
    }
    int down = r + 1;
    while (down < row && matrix[down][c] != 'B') {
        if (matrix[down][c] == 'P') {
            count++;
        }
        down++;
    }
    return count;
}

int GetMaxPeopleNum(char **matrix, int matrixSize)
{
    int ans = 0;
    int row = matrixSize;
    int a=strlen(matrix);
    int col=strlen(matrix[0]); /// 这才是对的
    int c = strlen(*matrix);
    // int d = strlen(*matrix[0]);
    // int col = strlen(matrix); /// bug
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            if (matrix[r][c] == 'N') { /// ==写成= 是真心难找
                int count = Cal(matrix, r, c, row, col);
                ans = count > ans ? count : ans;
            }
        }
    }
    return ans;
}

int main()
{
    // @formatter:off
    // char arr[][999]={{"PPBNBP"}}; //
    char arr[][999]={{"NN"},{"PP"},{"PN"},{"NP"}}; //
    // char arr[][5]={{"NNNPN"},{"PPBNP"},{"PNNPN"},{"NPNNN"}}; // 4
    // char arr[][5]={{"PBPPB"},{"BNBNP"},{"PPBBB"},{"NBPPP"}}; // 2
    int matSize=sizeof(arr)/sizeof(arr[0]);
    char* mat[matSize];
    for (int i = 0; i < matSize; ++i){
        mat[i]=arr[i];
    }
    int num = GetMaxPeopleNum(mat,matSize);
    printf("%d ",num);fflush(stdout);
    return 0;
    // @formatter:on
}