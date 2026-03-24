/* Given an integer n, write a program that generates all the binary sequences of length n in a lexicographic order.
Input
Line 1: contains an integer n (1 <= n <= 20)
Output
Write binary sequences in a lexicographic order, each sequence in a line

Example
Input
3
Output
000
001
010
011
100
101
110
111
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int n;
int* A;
void in(){
    for(int i=0;i<n;i++){
        printf("%d",A[i]);
    }
    printf("\n");
    return;
}
void Try(int a){
    if(a==n){
        in();
        return;}
    for(int i=0;i<=1;i++){
        A[a]=i;
         Try(a+1);
        }
}
int main(){
    scanf("%d",&n);
    A=(int*)malloc(n*sizeof(int));
    Try(0);
    return 0;
}
