#include<stdio.h>
struct node {
    int val;
    node* left, *right, *parent;
    node(int val, node* parent=0, node* left=0, node* right=0)
        : val(val),left(left),right(right),parent(parent) {}
}*t;
struct tree {
    node* root;
    tree(node* root=0)
        : root(root) {}

};

node* where(node* current, int x) {
    if(!current) return 0;
    if(current->val==x) return current;
    if(x <= current->val) return where(current->left, x);
    if(x > current->val) return where(current->right, x);
}
node* find_min(node* current) {
    if(!current->left) return current;
    return find_min(current->left);
}
node* find_max(node* current) {
    if(!current->right) return current;
    return find_min(current->right);
}
void del(node*& root, int x) {
    node* del = where(root, x);
    if(!del || del->val!=x) {return;}
    if(!del->left && !del->right) {
        if(!del->parent) {
            t = 0;
            return;
        }
        if(del->parent->left == del) del->parent->left = 0;
        if(del->parent->right == del) del->parent->right = 0;
        delete(del);
        return;
    }
    if(!del->right) {
        if(!del->parent){
            t = del->left;
            return;
        }
        if(del->parent->left == del) {
            del->parent->left = del->left;
            delete(del);
            return;
        }
        if(del->parent->right == del) {
            del->parent->right = del->left;
            delete(del);
            return;
        }
    }
    if(!del->left) {
        if(!del->parent){
            t = del->right;
            return;
        }
        if(del->parent->left == del) {
            del->parent->left = del->right;
            delete(del);
            return;
        }
        if(del->parent->right == del) {
            del->parent->right = del->right;
            delete(del);
            return;
        }
    }
    if(del->left && del->right) {
        node* leaf = find_min(del->right);
        del->val = leaf->val;
        leaf->parent->left = 0;
        delete(leaf);
    }
}
void insert(node*& current, int x) {
    if(!current) {
        current = new node(x);
        return;
    }

    if(x <= current->val) {
            if(!current->left) {
                current->left = new node(x, current);
                return;
            }
            insert(current->left,x);
    }
    if(x > current->val) {
            if(!current->right) {
                current->right = new node(x, current);
                return;
            }
            insert(current->right, x);
    }
}

void traverse(node* cur) {
    if(!cur) return;
    traverse(cur->left);
    printf("%d\n",cur->val);
    traverse(cur->right);
}
bool find(node* current, int x) {
    if(!current) return 0;
    if(current->val==x) return 1;
    if(x <= current->val) return find(current->left, x);
    if(x > current->val) return find(current->right, x);
}

main()
{
    t = 0;
    int M;
    scanf("%d",&M);
    while(M--) {
        int k, x;
        scanf("%d %d",&k,&x);
        if(k==1) {
            insert(t, x);
        } else if(k==2) {
            printf("%d\n",find(t, x));
        } else if(k==3) {
            del(t, x);
        }
    }

}
