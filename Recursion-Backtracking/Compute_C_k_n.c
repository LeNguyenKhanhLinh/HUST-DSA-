/*Given two positive integers k and n. Compute C(k,n) which is the number of ways to select k objects from a given set of n objects.
Input
Line 1: two positive integers k and n (1 <= k,n <= 999)
Output
Write te value C(k,n) modulo 10
9
+7.
Example
Input
3  5
Output
10
*/
#include <stdio.h>

long long memo[1001][1001];
void init_memo() {

    for (int i = 0; i < 1001; i++) {

        for(int j=0;j<1001;j++)

        memo[i][j] = -1;

    }

}

long long Ccn(int k, int n) {

    if (k == 0 || k == n) return 1;

    if (memo[n][k] != -1) return memo[n][k];

    memo[n][k] = (Ccn(k-1, n - 1) + Ccn(k, n-1)) % 1000000007;

    return memo[n][k];

}

int main(){

int k,n;

init_memo();

scanf("%d %d",&k,&n);
printf("%lld\n",Ccn(k,n));
return 0;

}

