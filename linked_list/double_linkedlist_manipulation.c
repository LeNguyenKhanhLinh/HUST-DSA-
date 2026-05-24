/*Viết chương trình thực hiện công việc sau:
Xây dựng danh sách liên kết đôi với các khóa được cung cấp ban đầu là dãy a
1
, a
2
, …, a
n
. Sau đó thực hiện các thao tác trên danh sách bao gồm: thêm 1 phần tử vào đầu, vào cuối danh sách, hoặc vào trước, vào sau 1 phần tử nào đó trong danh sách, hoặc loại bỏ 1 phần tử nào đó trong danh sách...
Chú ý trong nút đầu của danh sách liên kết đôi thì con trỏ - trỏ tới phần tử đứng trước nó - sẽ là rỗng.
Chú ý trong nút cuối của danh sách liên kết đôi thì con trỏ - trỏ tới phần tử đứng sau nó - sẽ là rỗng.
Input
Dòng 1: ghi số nguyên dương n (1 <= n <= 1000)
Dòng 2: ghi các số nguyên dương a
1
, a
2
, …, a
n
Các dòng tiếp theo lần lượt là các lệnh để thao tác (kết thúc bởi ký hiệu #):
addlast  k: thêm phần tử có key bằng k vào cuối danh sách (nếu k chưa tồn tại)
addfirst  k: thêm phần tử có key bằng k vào đầu danh sách (nếu k chưa tồn tại)
addafter  u  v: thêm phần tử có key bằng u vào sau phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u chưa tồn tại)
addbefore  u  v: thêm phần tử có key bằng  u vào trước phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u của tồn tại)
remove  k: loại bỏ phần tử có key bằng k khỏi danh sách
reverse: đảo ngược thứ tự các phần tử của danh sách (không được cấp phát mới các phần tử)
output o: o =1 sẽ output theo chiều từ trái sang phải, o = 0 sẽ output theo chiều từ phải sang trái của danh sách nối đôi
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
output 0
#
Output
10 2 3 4 5
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node *head = NULL, *tail = NULL;


Node* find(int k) {
    Node *p = head;
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
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) head->prev = newNode;
    head = newNode;
    if (tail == NULL) tail = newNode;
}

void addLast(int k) {
    if (find(k) != NULL) return;

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = k;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail != NULL) tail->next = newNode;
    tail = newNode;
    if (head == NULL) head = newNode;
}

void addAfter(int u, int v) {
    if (find(u) != NULL) return;

    Node* pv = find(v);
    if (pv == NULL) return;

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = u;

    newNode->next = pv->next;
    newNode->prev = pv;

    if (pv->next != NULL) pv->next->prev = newNode;
    pv->next = newNode;

    if (pv == tail) tail = newNode;
}

void addBefore(int u, int v) {
    if (find(u) != NULL) return;

    Node* pv = find(v);
    if (pv == NULL) return;

    if (pv == head) {
        addFirst(u);
        return;
    }

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = u;

    newNode->next = pv;
    newNode->prev = pv->prev;
    pv->prev->next = newNode;
    pv->prev = newNode;
}

void removeKey(int k) {
    Node* p = find(k);
    if (p == NULL) return;

    if (p == head) head = head->next;
    if (p == tail) tail = tail->prev;

    if (p->prev != NULL) p->prev->next = p->next;
    if (p->next != NULL) p->next->prev = p->prev;

    free(p);
}


void reverseList() {
    Node *p = head, *tmp = NULL;

    while (p != NULL) {
        tmp = p->prev;
        p->prev = p->next;
        p->next = tmp;
        p = p->prev;
    }

    if (tmp != NULL) {
        tmp = tmp->prev;
        Node *oldHead = head;
        head = tail;
        tail = oldHead;
    }
}

/* ---- OUTPUT ---- */
void output(int dir) {
    if (dir == 1) {
        Node* p = head;
        while (p != NULL) {
            printf("%d ", p->data);
            p = p->next;
        }
    } else {
        Node* p = tail;
        while (p != NULL) {
            printf("%d ", p->data);
            p = p->prev;
        }
    }
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

        if (strcmp(cmd, "addfirst") == 0) {
            int k; scanf("%d", &k);
            addFirst(k);
        }
        else if (strcmp(cmd, "addlast") == 0) {
            int k; scanf("%d", &k);
            addLast(k);
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
        else if (strcmp(cmd, "output") == 0) {
            int o; scanf("%d", &o);
            output(o);
            printf("\n");
        }
    }
    return 0;
}

