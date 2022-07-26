#include <string.h>

#define MAX(a,b) (a)>(b)?(a):(b)

int removeCoveredIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    //g_arr[100001]  下标是左界,值是右界
    int arr[100001];
    memset(arr,-1,sizeof(int)*100001);

    int res=intervalsSize;
    for(int a=0;a<intervalsSize;a++){
        int aidx=intervals[a][0];
        if(arr[aidx]==-1){
            int aval=intervals[a][1];
            arr[aidx]=aval;
        }else{
            //相同左界,不用想,肯定有一个被覆盖了
            res--;
            int aval=MAX(intervals[a][1],arr[aidx]);
            arr[aidx]=aval;
        }
    }

    /**
        bug:考虑不周,忽视4-7不能合并到3-6中,但可以合并到2-8中,所以还用到一种数据结构单增栈,不含=
        1 2 3 4
        4 8 6 7
    */
    int narr[res];
    int naidx=0;
    for (int a = 0; a < 100001; ++a) {
        if(arr[a]!=-1)narr[naidx++]=arr[a];
    }
    int stacktop=narr[0];
    for(int a=1;a<naidx;a++){
        if(narr[a]>stacktop){
            stacktop=narr[a];
        }else{
            res--;
        }
    }

//    for(int a=100000;a>=0;a--){
//        if(g_arr[a]!=-1){
//            int aa=a-1;
//            while(aa>=0 && g_arr[aa]==-1){
//                aa--;
//            }
//            ///bug:aa可能越界
//            //if(g_arr[a]<=g_arr[aa]){
//            if(aa>=0 && g_arr[a]<=g_arr[aa]){
//                res--;
//            }
//
//            a=aa+1;
//        }
//    }

    return res;
}

int main(){
//    int g_arr[][2] = {{1, 4}, {2, 8}, {3, 6}};
    int arr[][2]={{66672,75156},{59890,65654},{92950,95965},{9103,31953},{54869,69855},{33272,92693},{52631,65356},{43332,89722},{4218,57729},{20993,92876}};
    int intervalsSize = sizeof(arr) / sizeof(arr[0]);
    int * intervals[intervalsSize];
    for (int a = 0; a < intervalsSize; ++a) {
        intervals[a]=arr[a];
    }
    int res=removeCoveredIntervals(intervals, intervalsSize, NULL);
    return 0;
}

