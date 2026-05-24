/*Given an integers sequence a=(a
1
, a
2
,…, a
n
). A subsequence of aa is defined to be a
i
, a
i+1
,…, a
j
. The weight of a subsequence is the sum of its elements. Find the subsequence having the highest weight.
Input
Line 1 contains n (1≤n≤10
6
)
Line 2 contains a
1
,…,a
n
 (−500≤a
i
≤500)
Output
Write the weight of the highest subsequence found.
Example
input
10
3 -1 -3 5 2 5 0 -1 5 4
output
20
*/
#include <stdio.h>
int main()
{
  int n;
  int a[1000000];
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int maxsum=a[0];
  int sum=a[0];
  for(int i=1;i<n;i++){
    if (sum<0) sum=a[i];
    else sum=sum+a[i];
    if(sum>maxsum) maxsum=sum;
  }
  printf("%d",maxsum);
}
