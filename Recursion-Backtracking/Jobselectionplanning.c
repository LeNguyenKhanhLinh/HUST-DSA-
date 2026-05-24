/*Given n jobs J = {1,. . .,n}. Each job i has a deadline d(i) and associated profit p(i) if the job is finished before the deadline. Every job takes the single unit of time, so the minimum possible deadline for any job is 1. It is also noted that no more than one job can be executed at a time.
Select and schedule a subset of jobs of J such that the total profits is maximal.
Input
Line 1: contains a positive integer n (1 <= n <= 10
5
)
Line i+1 (i=1,. . . ,n) contains d(i) and p(i) (1 <= d(i), p(i) <= 10
5
)
Output
Write to total profits obtained from the subset of jobs found.

Example
Input
6
3 10
2 40
6 70
3 50
5 80
1 60
Output
300
*/
#include <stdio.h>
int n;
typedef struct {
  int d;
  double p;
}job;
double s=0;
job t[10000];
int x[10000]={0};
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      scanf("%d",&t[i].d);
      scanf("%lf",&t[i].p);
    }
    for(int i=0;i<n;i++){
      for(int j=i;j<n;j++){
        if(t[i].p<t[j].p){
          job temp=t[i];
          t[i]=t[j];
          t[j]=temp;
        }
      }
    }
    for(int i = 0; i < n; i++) {
    for(int j = t[i].d; j > 0; j--) {
        if(x[j] == 0) {
            x[j] = 1;
            s += t[i].p;
            break;
        }
    }
}

    printf("%.0lf",s);

}

