#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;
struct node {
    int val;
    node* nxt;

    node(int val, node* nxt = 0)
        : val(val), nxt(nxt) {}
};

void insert(node* head, int x) {
    node* tmp = new node(x);
    tmp->nxt = head->nxt;
    head->nxt = tmp;
}

void deletenode(node* head, int x) {
    node* pt = head;
    x-=1;
    if(!pt->nxt) return;
    while(x--) {
        pt = pt->nxt;
        if(!pt->nxt) return;
    }
    
    if(!pt->nxt) return;
    node* temp = pt->nxt;
    pt->nxt = temp->nxt;
    free(temp);
}
void printlist(node* head) {
    while(head->nxt) {
        head = head->nxt;
        printf("%d\n",head->val);
    }
}
main()
{
    node* head = new node(0);
    int n;
    char c;
    int x;
    cin >> n;
    while(n--) {
        scanf(" %c %d",&c,&x);
    switch(c) {
        case 'I': {
            insert(head, x);
            break;
        }
        case 'D': {
            deletenode(head, x);
            break;
        }
    }
    }
    
    
        printlist(head);
}