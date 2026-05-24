/*Viết chương trình thực hiện công việc sau:
Xây dựng hai danh sách liên kết đơn với các khóa được cung cấp ban đầu là dãy a
1
, a
2
, ..., a
n
 và dãy b
1
, b
2
, ..., b
m
 (các khóa của danh sách a và b đều đã được sắp xếp theo thứ tự không tăng (hoặc không giảm)); sau đó thực hiện trộn hai danh sách này thành danh sách mới với các khóa đã được sắp xếp theo thứ tự không tăng (hoặc không giảm)
Input
Dòng 1: ghi số nguyên dương n (1 <= n <= 1000)
Dòng 2: ghi các số nguyên dương a
Dòng 3: ghi số nguyên dương m (1 <= m <= 1000)
Dòng 4: ghi các số nguyên dương b
Các dòng tiếp theo lần lượt là một trong hai lệnh dưới đây:
iSort: trộn hai danh sách này thành danh sách mới với thứ tự các khóa không giảm
dSort: trộn hai danh sách này thành danh sách mới với thứ tự các khóa không tăng
Output
Ghi ra dãy khóa của danh sách mới thu được sau khi trộn
-----------------------------------
Example1:
Input
5
5 4 3 2 1
4
8 5 3 1
dSort

Output
8 5 5 4 3 3 2 1 1
-----------------------------------
Example2:
Input
5
1 2 3 4 5
4
1 3 5 8
iSort

Output
1 1 2 3 3 4 5 5 8
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node* newNode(int v) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->val = v;
    p->next = NULL;
    return p;
}

Node* createListFromArray(int a[], int n) {
    if (n == 0) return NULL;
    Node *head = newNode(a[0]), *tail = head;
    for (int i = 1; i < n; ++i) {
        tail->next = newNode(a[i]);
        tail = tail->next;
    }
    return head;
}

Node* reverseList(Node* head) {
    Node *prev = NULL, *cur = head;
    while (cur) {
        Node *nx = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nx;
    }
    return prev;
}


Node* mergeInc(Node* a, Node* b) {
    Node dummy; Node *tail = &dummy; dummy.next = NULL;
    while (a && b) {
        if (a->val <= b->val) {
            tail->next = a; a = a->next;
        } else {
            tail->next = b; b = b->next;
        }
        tail = tail->next;
    }
    tail->next = (a ? a : b);
    return dummy.next;
}


Node* mergeDec(Node* a, Node* b) {
    Node dummy; Node *tail = &dummy; dummy.next = NULL;
    while (a && b) {
        if (a->val >= b->val) {
            tail->next = a; a = a->next;
        } else {
            tail->next = b; b = b->next;
        }
        tail = tail->next;
    }
    tail->next = (a ? a : b);
    return dummy.next;
}

void printList(Node* head) {
    Node* p = head;
    int first = 1;
    while (p) {
        if (!first) printf(" ");
        printf("%d", p->val);
        first = 0;
        p = p->next;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* p = head;
    while (p) {
        Node* nx = p->next;
        free(p);
        p = nx;
    }
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int *a = (int*)malloc(sizeof(int) * (n>0?n:1));
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

        int m;
        if (scanf("%d", &m) != 1) { free(a); break; }
        int *b = (int*)malloc(sizeof(int) * (m>0?m:1));
        for (int i = 0; i < m; ++i) scanf("%d", &b[i]);

        char cmd[16];
        if (scanf("%s", cmd) != 1) { free(a); free(b); break; }

        Node *la = createListFromArray(a, n);
        Node *lb = createListFromArray(b, m);


        int a_inc = 1, b_inc = 1;
        if (n >= 2) a_inc = (a[0] <= a[1]) ? 1 : 0;
        if (m >= 2) b_inc = (b[0] <= b[1]) ? 1 : 0;

        if (strcmp(cmd, "iSort") == 0) {

            if (!a_inc) la = reverseList(la);
            if (!b_inc) lb = reverseList(lb);
            Node* res = mergeInc(la, lb);
            printList(res);
            freeList(res);
        } else if (strcmp(cmd, "dSort") == 0) {

            if (a_inc) la = reverseList(la);
            if (b_inc) lb = reverseList(lb);
            Node* res = mergeDec(la, lb);
            printList(res);
            freeList(res);
        } else {

            Node* res = mergeInc(la, lb);
            printList(res);
            freeList(res);
        }

        free(a); free(b);


        char sep[8];
        if (scanf("%s", sep) != 1) break;
        if (strcmp(sep, "#") != 0) {

            int len = strlen(sep);
            for (int i = len - 1; i >= 0; --i) ungetc(sep[i], stdin);

            ungetc(' ', stdin);
        }
    }
    return 0;
}

