#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;
struct node {
    int val;
    node* prev, *nxt;

    node(int val, node* nxt = 0, node* prev = 0)
        : val(val), prev(prev), nxt(nxt) {}
}*head;


void append(int x) {
    node* temp = new node(x);

    if(!head->nxt) {
        head->nxt = temp;
        temp->nxt = temp;
        temp->prev = temp;
        return;
    }

    node* tail = head->nxt->prev;
    tail->nxt = temp;
    head->nxt->prev = temp;
    temp->nxt = head->nxt;
    temp->prev = tail;
}

void insert(int x) {
    if(!head->nxt) {
        append(x);
        return;
    }
    node* tmp = new node(x);
    tmp->nxt = head->nxt;
    tmp->prev = head->nxt->prev;
    head->nxt->prev->nxt = tmp;
    head->nxt->prev = tmp;
    head->nxt = tmp;
}


void lr() {
    if(!head->nxt) return;
    head->nxt = head->nxt->nxt;
}

void rr() {
    if(!head->nxt) return;
    head->nxt = head->nxt->prev;
}

void printlist() {
    node* tmp = head;
    tmp=tmp->nxt;
    if(!tmp) return;
    do{
        printf("%d\n",tmp->val);
        tmp = tmp->nxt;
    }while(tmp!=head->nxt);
}
main()
{
    head = new node(0);
    int n;
    char c[3];
    int x;
    cin >> n;
    while(n--) {
        scanf(" %s",c);
    
        if(c[0]=='l'){
            if(c[1]=='r') {
                lr();
            } else {
                scanf("%d",&x);
                insert(x);
            }
        }
        else {  
            if(c[1]=='r') {
                rr();
            } else {
                scanf("%d",&x);
                append(x);
            }
        }
    }
    
    printlist();
}