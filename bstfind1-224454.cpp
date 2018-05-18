#include<stdio.h>
struct node {
    int val, c_left, c_right;
    node* left, *right, *parent;
    node(int val,node* parent=0, node* left=0, node* right=0)
        : val(val),left(left),right(right),c_left(0),c_right(0),parent(parent) {}
};
struct tree {
    node* root;
    tree(node* root=0)
        : root(root) {}

};
void insert(node*& current, int x) {
    if(!current) {
        current = new node(x);
        return;
    }

    if(x <= current->val) {
            current->c_left++;
            if(!current->left) {
                current->left = new node(x, current);                
                return;
            }
            insert(current->left,x);
    }
    if(x > current->val) {
            current->c_right++;
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
int count_right(node* current, int x) {
    if(!current) return 0;
    if(current->val==x) return current->c_right;
    if(x < current->val) {
        int result = count_right(current->left, x);
        if(result) return result;

        int sum = 1;
        if(current->right) sum+=current->right->c_right;
        if(current->parent && current->parent->right) {
            sum+=current->parent->right->c_right;
        }
        return sum;
    }
    if(x > current->val) {
        int result = count_right(current->right, x);
        if(result) return result;

        int sum = 0;
        if(current->parent && current->parent->right && current->parent->right != current) {
            sum+=current->parent->right->c_right;
        }
        return sum;
    }

}

main()
{
    node* t = 0;
    int M;
    scanf("%d",&M);
    while(M--) {
        int k, x;
        scanf("%d %d",&k,&x);
        if(k==1) {
            insert(t, x);
        } else if(k==2) {
            printf("%d\n",count_right(t, x));
        }
    }

}
