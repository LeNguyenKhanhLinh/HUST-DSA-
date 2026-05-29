/*
Mỗi nút của một cây nhị phân T có trường id (định danh của nút, id không trùng lặp nhau). Thực hiện chuỗi các thao tác sau đây trên cây T (ban đầu, T là cây rỗng)
MakeRoot u: tạo một nút gốc có id bằng u
AddLeft u v: tạo một nút có id = u và chèn vào vị trí con trái của nút có id bằng v trên T (không thực hiện hành động chèn nếu nút có id bằng u đã tồn tại hoặc nút có id bằng v không tồn tại hoặc nút có id bằng v đã có nút con trái rồi)
AddRight u v: tạo một nút có id = u và chèn vào vị trí con phải của nút có id bằng v trên T (không thực hiện hành động chèn nếu nút có id bằng u đã tồn tại hoặc nút có id bằng v không tồn tại hoặc nút có id bằng v đã có nút con phải rồi)
PreOrder: đưa ra trên 1 dòng mới dãy id của các nút trong phép duyệt cây T theo thứ tự trước (các phần tử cách nhau bởi đúng 1 ký tự cách SPACE)
InOrder: đưa ra trên 1 dòng mới dãy id của các nút trong phép duyệt cây T theo thứ tự giữa (các phần tử cách nhau bởi đúng 1 ký tự cách SPACE)
PostOrder: đưa ra trên 1 dòng mới dãy id của các nút trong phép duyệt cây T theo thứ tự sau (các phần tử cách nhau bởi đúng 1 ký tự cách SPACE)

Input
Mỗi dòng là 1 trong số cách thao tác với định dạng được mô tả ở trên (thao tác MakeRoot chỉ xuất hiện đúng 1 lần và luôn ở ngay dòng đầu tiên). Kết thúc của dữ liệu input là dòng chứa duy nhất ký tự *

Output
Ghi ra trên 1 dòng kết quả của 1 trong số 3 thao tác InOrder, PreOrder, PostOrder mô tả ở trên

Example
Input
MakeRoot 1
AddLeft 2 1
AddRight 3 1
AddLeft 4 3
AddRight 5 2
PreOrder
AddLeft 6 5
AddRight 7 5
InOrder
*

Output
1 2 5 3 4
2 6 5 7 1 4 3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node *left, *right;
} Node;

Node* root = NULL;
Node* nodes[100001];

Node* newNode(int id) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->id = id;
    p->left = p->right = NULL;
    return p;
}

void preorder(Node* r) {
    if (!r) return;
    printf("%d ", r->id);
    preorder(r->left);
    preorder(r->right);
}

void inorder(Node* r) {
    if (!r) return;
    inorder(r->left);
    printf("%d ", r->id);
    inorder(r->right);
}

void postorder(Node* r) {
    if (!r) return;
    postorder(r->left);
    postorder(r->right);
    printf("%d ", r->id);
}

int main() {
    char cmd[20];
    int u, v;

    memset(nodes, 0, sizeof(nodes));

    while (1) {
        scanf("%s", cmd);
        if (strcmp(cmd, "*") == 0) break;

        if (strcmp(cmd, "MakeRoot") == 0) {
            scanf("%d", &u);
            root = newNode(u);
            nodes[u] = root;
        }
        else if (strcmp(cmd, "AddLeft") == 0) {
            scanf("%d %d", &u, &v);
            if (!nodes[u] && nodes[v] && nodes[v]->left == NULL) {
                nodes[u] = newNode(u);
                nodes[v]->left = nodes[u];
            }
        }
        else if (strcmp(cmd, "AddRight") == 0) {
            scanf("%d %d", &u, &v);
            if (!nodes[u] && nodes[v] && nodes[v]->right == NULL) {
                nodes[u] = newNode(u);
                nodes[v]->right = nodes[u];
            }
        }
        else if (strcmp(cmd, "PreOrder") == 0) {
            preorder(root);
            printf("\n");
        }
        else if (strcmp(cmd, "InOrder") == 0) {
            inorder(root);
            printf("\n");
        }
        else if (strcmp(cmd, "PostOrder") == 0) {
            postorder(root);
            printf("\n");
        }
    }
    return 0;
}
