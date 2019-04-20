/*
Ref: https://codertw.com/程式語言/411726/ 
Linked List
*/
#include <iostream>
#include <map>

using namespace std;

typedef struct node{
    int number;
    node *next;
}Node;

Node* CreateNode(int x) {
    Node *p;
    p = (Node*)malloc(sizeof(Node));
    p->number = x;
    p->next = NULL;
    return p;
}
Node* CreateJoseph(int n) {
    Node *head, *q, *p;
    for (int i=1; i<=n; i++){
        p = CreateNode(i);
        if (i==1) {
            head = p;
        }
        else {
            q->next = p;
        }
        q = p;
    }
    q->next = head;
    return head;
}

void RunJoseph(int n, int m) {
    Node *p, *q;
    p = CreateJoseph(n);
    q = p;
    while(p->next!=q){
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    p = q->next;

    printf("%d--", q->number);
    free(q);

    while(p->next!=p) {
        for (int i=1; i<m-1; i++){
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        p = p->next;
        printf("%d--", q->number);
        free(q);
    }
    printf("\n剩下最後的數為: %d\n", p->number);
}

int main(){
    
    int n, m;
    scanf("%d %d", &n, &m);
    RunJoseph(n,m);
    return 0;
}