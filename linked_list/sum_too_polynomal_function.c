/*Viết chương trình thực hiện công việc sau:
Xây dựng hai danh sách liên kết đơn với các nút có khóa được cung cấp ban đầu gồm các cặp số (hệ số, số mũ) là dãy (a
0
,0), (a
1
,1), ..., (a
n-1
,n-1) và dãy (b
0
,0), (b
1
,1), ..., (b
m-1
,m-1) biểu diễn cho các hàm số dạng đa thức p(x) = a
0
*x^0 + a
1
*x^1 + ... + a
n-1
*x^(n-1) và q(x) = b
0
*x^0 + b
1
*x^1 + ... + b
m-1
*x^(m-1).
Yêu cầu thực hiện tính tổng (hoặc hiệu) hai đa thức này.
Chú ý tất cả các danh sách ứng với đa thức p(x), đa thức q(x) và đa thức tổng (hoặc hiệu) không được tồn tại nút có khóa với hệ số = 0 (với trường hợp p(x)=0, q(x)=0 và p(x) + q(x) = 0 (hoặc p(x) - q(x) = 0) thì danh sách tương ứng với chúng sẽ chỉ chứa một nút có khóa là (0,0)).
Input
Dòng 1: ghi số nguyên dương n (1 <= n <= 1000)
Dòng 2: ghi các số nguyên a
Dòng 3: ghi số nguyên dương m (1 <= m <= 1000)
Dòng 4: ghi các số nguyên b
Các dòng tiếp theo lần lượt là một trong hai lệnh dưới đây:
plus: tính tổng hai đa thức
minus: tính hiệu hai đa thức
Output
Ghi ra số nút và dãy khóa của danh sách mới thu được sau khi tính tổng (hoặc hiệu), chú ý nếu hệ số = 0 không tồn tại nút thì vẫn phải ghi khóa =0 ra.
-----------------------------------
Example1:
Input
5
-3 2 0 1 -7
4
4 0 5 -1
plus
Output
4 1 2 5 0 7
-----------------------------------
Example2:
Input
2
-1 -2
2
-1 -2
minus
Output
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d", &n);

    int *a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    scanf("%d", &m);
    int *b = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);

    char cmd[10];
    scanf("%s", cmd);

    int max = (n > m ? n : m);
    int* r = (int*)calloc(max, sizeof(int));

    for (int i = 0; i < max; i++) {
        int x = (i < n ? a[i] : 0);
        int y = (i < m ? b[i] : 0);

        if (cmd[0] == 'p')
            r[i] = x + y;
        else
            r[i] = x - y;
    }

    int cnt = 0;
    for (int i = 0; i < max; i++)
        if (r[i] != 0)
            cnt++;

    if (cnt == 0) {
        printf("1 0");
        return 0;
    }

    printf("%d ", cnt);
    for (int i = 0; i < max; i++)
        printf("%d ", r[i]);

    return 0;
}

