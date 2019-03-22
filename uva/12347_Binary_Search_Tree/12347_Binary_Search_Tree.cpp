/*
Build the binary search tree, then output by postorder method
Date: 2019/02/22
*/
#include <iostream>
using namespace std;

struct node {
    int value;
    node *left = nullptr;
    node *right = nullptr;
};

node *insert(node *head, int new_value){
    node *N = new node;
    N->value = new_value;

    if (head==nullptr){
        return N;
    }

    node *tree = head;
    node *next = head;
    while(next!=nullptr) { // 1. repeat traveling until leaf(find the position that will be inserted)
        tree = next;
        if (new_value > next->value) {
            next = next -> right;
        }
        else {
            next = next -> left;
        }
    }

    // 2. Then, insert the new value
    if (new_value > tree->value) {
        tree->right = N;
    }
    else {
        tree->left = N;
    }
    return head;
}

void pre_order(node *head) {
    if (head==nullptr) return;
    printf("%d\n", head->value);
    pre_order(head->left);
    pre_order(head->right);
}
void in_order(node *head) {
    if (head==nullptr) return;
    in_order(head->left);
    printf("%d\n", head->value);
    in_order(head->right);
}
void post_order(node *head) {
    if (head==nullptr) return;
    post_order(head->left);
    post_order(head->right);
    printf("%d\n", head->value);
}

int main(){
    int value;
    node *head = nullptr;
    while (cin>>value){
        head = insert(head, value);
    }
    //pre_order(head);
    post_order(head);
}