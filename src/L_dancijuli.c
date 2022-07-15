#include <stdio.h>

int findClosest(char** words, int wordsSize, char* word1, char* word2){

}
//17.11 单词举例
int main(){
    char* arr[]={"I","am","a","student","from","a","university","in","a","city"};
    ///bug
    //int wordsSize=sizeof(arr);//80
    int wordsSize=sizeof(arr)/sizeof(arr[0]);
    char* word1="a";
    char* word2="student";
    printf("%d", findClosest(arr, wordsSize, word1, word2));
    fflush(stdout);
    return 0;
}