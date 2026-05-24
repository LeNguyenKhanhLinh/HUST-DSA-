/*Given a sequence a of positive a1, a2, . . ., an. A subsequence of a is defined to be the sequence obtained by removing some elements. Find the subsequence of a such that the elements is in an increasing order and the number of elements of the subsequence is maximal.

Input
Line 1: contains a positive integer n (1 <= n <= 10000)
Line 2: contains n elements of the given sequence (1 <= ai <= 10000)
Output
The length of the subsequence found.

Example
Input
6
5 8 2 8 10 10

Output
3
*/
#include <stdio.h>
int n;
int a[10000];
int s[10000];
int km;
int mc=0;
int Try(int k){
  if(k==0){
    if(s[k]>mc){
      mc=s[k];
    }
    return mc;
  }
  else if(k==n-1){
    s[k]=1;
    mc=1;
    Try(k-1);
  }
  else{
    int tmc=0;
    for(int i=k+1;i<n;i++){
      if (a[i]>a[k]&&s[i]>tmc){
        tmc=s[i];
      }
    }
    s[k]=tmc+1;
    if(s[k]>mc){
      mc=s[k];
    }
    Try(k-1);
}}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      scanf("%d",&a[i]);
    }
    Try(n-1);
    printf("%d",mc);
}

