/*Given an integer n, write a program to generate all permutations of 1, 2, ..., n in a lexicalgraphic order (elements of a permutation are separated by a SPACE character).
Example
Input
3
Output
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/
#include <stdio.h>
#include <math.h>
int x[21];
int n;
int check (int v,int k){
  return 1;
}
int solution(){
  int k=0;
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      if(x[i]==x[j]){
        k=k+1;}
    }
    }
    if (k==0){
  for (int i=1;i<=n;i++){
    printf("%d ",x[i]);}
    printf("\n");}
}
void try (int k){
  for(int v=1;v<=n;v++){
    if (check(v,k)){
       x[k]=v;

      if(k==n){
        solution();
      }
      else try(k+1);

}}}

int main()
{
  scanf("%d",&n);
  try(1);
  return 0;
}

