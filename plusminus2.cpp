#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;
struct node {
    int val;
    node* nxt;

    node(int val, node* nxt = 0)
        : val(val), nxt(nxt) {}
}*head,*tail;


void insert(int x) {
    node* tmp = new node(x);
    tmp->nxt = head->nxt;
    if(head == tail){
        tail = tmp;
    }
    head->nxt = tmp;
}

void deletenode(int x) {
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
    if(temp == tail) {
        tail = pt;
    }
    free(temp);
}

void append(int x) {
    node* temp = new node(x);
    tail -> nxt = temp;
    tail = temp;
}

void printlist(node* head) {
    while(head->nxt) {
        head = head->nxt;
        printf("%d\n",head->val);
    }
}
main()
{
    head = new node(0);
    tail = head;
    int n;
    char c;
    int x;
    cin >> n;
    while(n--) {
        scanf(" %c %d",&c,&x);
        switch(c) {
            case 'I': {
                insert(x);
                break;
            }
            case 'D': {
                deletenode(x);
                break;
            }
            case 'A': {
                append(x);
                break;
            }
        }
    }
        printlist(head);
}