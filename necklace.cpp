#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;
int n;
struct node {
    int val;
    int head;
    node* nxt;

    node(int val, node* nxt = 0)
        : val(val), head(val), nxt(nxt) {}
};

node** mem;
class Platform {
    public:
        node* head;
        node* tail;
    
    public:
        Platform();
        void append(int);
        void printlist();
        void append(node*);
        void cut();
        void update_tail(Platform);
};

Platform::Platform() {
    head = new node(0);
    tail = head;
}

void Platform::append(int x) {
    node* temp = new node(x);
    tail->nxt = temp;
    tail = temp;
}

void Platform::printlist() {
    node* pt = head;
    while(pt!=tail) {
        pt = pt->nxt;
        printf("%d ",pt->val);
    }
}

void Platform::cut() {
    if(head==tail) return;
    head->nxt = 0;
    tail = head;
}

int find_head(node* i) {
    int headmem = i->head;
    while(headmem!=i->val) {
        i = mem[i->head-1];
        headmem = i->head;
    }
    return headmem;
}

void Platform::append(node* i) {
    tail->nxt = i->nxt;
    i->nxt = head->nxt;
    int headmem = find_head(i);
    head->nxt->head = headmem;
}

void Platform::update_tail(Platform i) {
    if(tail->nxt){
        tail = i.tail;
    }
}

main()
{
    cin >> n;
    int a,b;
    Platform pf[n];
    mem = new node*[n];

    for(int i=0;i<n;i++) {
        pf[i].append(i+1);
        mem[i] = pf[i].head->nxt;
    }

    for(int i=1;i<n;i++) {
        scanf("%d %d",&a, &b);
        //search a and b
        int A,B;
        node* BB;

        A = a-1;
        B = find_head(mem[b-1]) - 1;
        BB = mem[b-1];
        pf[A].append(BB);
        pf[B].update_tail(pf[A]);
        pf[A].cut();

        // for debug
        // for(int k=0;k<n;k++) {
        //     printf("%d-> ",k+1);
        //     printf("%d",mem[k]->head);
        //     // pf[k].printlist();
        //     printf("\n");
        // }
    }
        for(int k=0;k<n;k++) {
            pf[k].printlist();
        }
}
