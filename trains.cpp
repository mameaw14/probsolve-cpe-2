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

class Platform {
    public:
        node* head;
        node* tail;
    
    public:
        Platform();
        void append(int);
        void printlist();
        void moveto(Platform);
        void append(Platform);
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
        printf("%d\n",pt->val);
    }
}

void Platform::moveto(Platform j) {
    if(head==tail) return;
    head->nxt = 0;
    tail = head;
}
void Platform::append(Platform i) {
    if(i.head==i.tail) return;
    tail->nxt = i.head->nxt;
    tail = i.tail;
}

main()
{
    Platform platform[100001];
    int n;
    char c;
    int x, i;

    scanf("%d",&n);
    while(n--) {
        scanf(" %c %d %d", &c, &x, &i);
        if(c=='N') { //append
            platform[i].append(x);
        }else{ //move
            platform[i].append(platform[x]);
            platform[x].moveto(platform[i]);
        }
    }
    for(int j=0; j<100001; j++){
        platform[j].printlist();
    }
}
