typedef int Data;
#define NULL 0
typedef struct node {
    Data key;
    struct node * left;
    struct node * right;
    struct node * parent;
}Node;
typedef struct tree{
    Node * root;
    int height;
}Tree;
int cmp(const Data * key1,const Data * key2){
    if(&key1 > &key2){
        return 1;
    }
    else if(&key1 == &key2){
        return 0;
    }
    else {
        return -1;
    }
}
Node * Tree_Search(const Node * T,const Data k){
    Node * p=T;
    int temp=cmp(&k,&(p->key));
    while(p != NULL && temp){
        if(temp == -1){
            p=p->left;
        }
        else if(temp == 1){
            p=p->right;
        }
    }
    return p;
}
Node * Tree_Minimum(const Node *T){
    Node * p = T;
    while(p->left != NULL){
        p=p->left;
    }
    return p;
}
Node * Tree_Maximum(const Node *T){
    Node * p = T;
    while(p->right != NULL){
        p=p->right;
    }
    return p;
}
Node * Tree_Successor(const Node *p){
    if(p->right != NULL){
        return Tree_Minimum(p->right);
    }
    Node * q = p->parent;
    while(q != NULL && p == q->right){
        p = q;
        q = q->parent;
    }
    return q;
}
int Tree_Insert(Tree * T,Node * z){
    Node * y=NULL;
    Node * x=T->root;
    int temp=cmp(&(z->key),&(x->key));
    while(x!=NULL){
        y=x;
        if(temp == -1){
            x=x->left;
        }
        else if(temp == 1){
            x=x->right;
        }
    }
    z->parent=y;
    if(y == NULL){
        T->root = z;
    }
    else if(cmp(&z->key,&y->key)==-1){
        y->left=z;
    }
    else{
        y->right=z;
    }
    return 1;
}
void _Transplant(Tree * T,Node * u,Node * v){
    if(u->parent == NULL){
        T->root = v;
    }
    else if(u == u->parent->left){
        u->parent->left = v;
    }
    else{
        u->parent->right = v;
    }
    if(v != NULL){
        v->parent = u->parent;
    }
}
int Tree_Delete(Tree * T,Node * z){
    if(z->left == NULL){
        _Transplant(T,z,z->right);
    }
    else if(z->right == NULL){
        _Transplant(T,z,z->left);
    }
    else{
        Node * y=Tree_Minimum(z->right);
        if(y->parent != z){
            _Transplant(T,y,y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        _Transplant(T,z,y);
        y->left = z->left;
        y->left->parent = y;
    }
    return 1;
}