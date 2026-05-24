/*Viết chương trình thực hiện công việc sau:
Xây dựng danh sách liên kết với các khóa được cung cấp ban đầu là dãy a
1
, a
2
, …, a
n
, sau đó thực hiện các thao tác trên danh sách bao gồm: thêm 1 phần tử vào đầu, vào cuối danh sách, hoặc vào trước, vào sau 1 phần tử nào đó trong danh sách, hoặc loại bỏ 1 phần tử nào đó trong danh sách

Input
Dòng 1: ghi số nguyên dương n (1 <= n <= 1000)
Dòng 2: ghi các số nguyên dương a
1
, a
2
, …, a
n
.
Các dòng tiếp theo lần lượt là các lệnh để thao tác (kết thúc bởi ký hiệu #) với các loại sau:
addlast  k: thêm phần tử có key bằng k vào cuối danh sách (nếu k chưa tồn tại)
addfirst  k: thêm phần tử có key bằng k vào đầu danh sách (nếu k chưa tồn tại)
addafter  u  v: thêm phần tử có key bằng u vào sau phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u chưa tồn tại)
addbefore  u  v: thêm phần tử có key bằng  u vào trước phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u của tồn tại)
remove  k: loại bỏ phần tử có key bằng k khỏi danh sách
reverse: đảo ngược thứ tự các phần tử của danh sách (không được cấp phát mới các phần tử, chỉ được thay đổi mối nối liên kết)
Output
Ghi ra dãy khóa của danh sách thu được sau 1 chuỗi các lệnh thao tác đã cho

Example
Input
5
5 4 3 2 1
addlast 3
addlast 10
addfirst 1
addafter 10 4
remove 1
#

Output
5 4 3 2 10
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* head = NULL;


Node* find(int k) {
    Node* p = head;
    while (p != NULL) {
        if (p->data == k) return p;
        p = p->next;
    }
    return NULL;
}

void addFirst(int k) {
    if (find(k) != NULL) return;

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = k;
    newNode->next = head;
    head = newNode;
}

void addLast(int k) {
    if (find(k) != NULL) return;

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = k;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* p = head;
    while (p->next != NULL) p = p->next;
    p->next = newNode;
}

void addAfter(int u, int v) {
    if (find(u) != NULL) return;
    Node* pv = find(v);
    if (pv == NULL) return;

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = u;
    newNode->next = pv->next;
    pv->next = newNode;
}

void addBefore(int u, int v) {
    if (find(u) != NULL) return;
    if (head == NULL) return;

    if (head->data == v) {
        addFirst(u);
        return;
    }

    Node* p = head;
    while (p->next != NULL && p->next->data != v)
        p = p->next;

    if (p->next == NULL) return;

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = u;
    newNode->next = p->next;
    p->next = newNode;
}

void removeKey(int k) {
    if (head == NULL) return;

    if (head->data == k) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
        return;
    }

    Node* p = head;
    while (p->next != NULL && p->next->data != k)
        p = p->next;

    if (p->next == NULL) return;

    Node* tmp = p->next;
    p->next = tmp->next;
    free(tmp);
}

void reverseList() {
    Node *prev = NULL, *cur = head, *next = NULL;
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        addLast(x);
    }

    char cmd[20];
    while (1) {
        scanf("%s", cmd);
        if (cmd[0] == '#') break;

        if (strcmp(cmd, "addlast") == 0) {
            int k; scanf("%d", &k);
            addLast(k);
        }
        else if (strcmp(cmd, "addfirst") == 0) {
            int k; scanf("%d", &k);
            addFirst(k);
        }
        else if (strcmp(cmd, "addafter") == 0) {
            int u, v; scanf("%d %d", &u, &v);
            addAfter(u, v);
        }
        else if (strcmp(cmd, "addbefore") == 0) {
            int u, v; scanf("%d %d", &u, &v);
            addBefore(u, v);
        }
        else if (strcmp(cmd, "remove") == 0) {
            int k; scanf("%d", &k);
            removeKey(k);
        }
        else if (strcmp(cmd, "reverse") == 0) {
            reverseList();
        }
    }

    Node* p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    return 0;
}

