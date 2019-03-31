typedef int Data;
#define NULL 0
#define RED 1
#define BLACK 0
typedef struct node {
    Data key;
    int color;
    struct node * left;
    struct node * right;
    struct node * parent;
}Node;
typedef struct tree{
    Node * root;
    int height;
    Node * NIL;
}Tree;
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
Tree * Initialize(void){
    Tree * T=(Tree*)malloc(sizeof(Tree));
    T->height = 0;
    T->root = NULL;
    T->NIL->color = BLACK;
    T->NIL->key = NULL;
    T->NIL->left = NULL;
    T->NIL->right = NULL;
    T->NIL->parent = NULL;
    return T;
}
void _Left_Rotate(Tree * T,Node * x){
    Node * y = x->right;
    x->right = y->left;
    if(y->left != T->NIL){
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == T->NIL){
        T->root = y;
    }
    else if(x == x->parent->left){
        x->parent->left = y;
    }
    else{
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}
void _Right_Rotate(Tree * T,Node * x){
    Node * y = x->left;
    x->left = y->right;
    if(y->right != T->NIL){
        y->right->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == T->NIL){
        T->root = y;
    }
    else if(x == x->parent->right){
        x->parent->right = y;
    }
    else if(x == x->parent->left){
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}
int RB_Insert(Tree * T,Node * z){
    Node * y = T->NIL;
    Node * x = T->root;
    while(x != T->NIL){
        y = x;
        if(cmp(&(z->key),&(x->key)) == -1){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }
    z->parent = y;
    if(y == T->NIL){
        T->root = z;
    }
    else if(cmp(&(z->key),&(y->key) == -1)){
        y->left = z;
    }
    else{
        y->right = z;
    }
    z->left = T->NIL;
    z->right = T->NIL;
    z->color = RED;
    RB_Insert_Fixup(T,z);
}
void RB_Insert_Fixup(Tree * T,Node * z){
    Node * y;
    while(z->parent->color == RED){
        if(z->parent == z->parent->parent->left){
           y = z->parent->parent->right; 
           if(y->color == RED){
               z->parent->color = BLACK;
               y->color = BLACK;
               z->parent->parent->color = RED;
               z = z->parent->parent->color = RED;
           }
           else if(z == z->parent->right){
               z = z->parent;
               _Left_Rotate(T,z);
           }
           z->parent->color = BLACK;
           z->parent->parent->color = RED;
           _Right_Rotate(T,z->parent->parent);
        }
        else{
           y = z->parent->parent->left; 
           if(y->color == RED){
               z->parent->color = BLACK;
               y->color = BLACK;
               z->parent->parent->color = RED;
               z = z->parent->parent->color = RED;
           }
           else if(z == z->parent->left){
               z = z->parent;
               _Right_Rotate(T,z);
           }
           z->parent->color = BLACK;
           z->parent->parent->color = RED;
           _Left_Rotate(T,z->parent->parent);
        }
    }
    T->root->color = BLACK;
}
void _RB_Transplant(Tree * T,Node * u,Node * v){
    if(u->parent == T->NIL){
        T->root = v;
    }
    else if(u == u->parent->left){
        u->parent->left = v;
    }
    else{
        u->parent->right = v;
    }
    v->parent = u->parent;
}
void RB_Delete(Tree * T,Node * z){
    Node * y = z;Node * x;
    int y_original_color = y->color;
    if(z->left == T->NIL){
        x = z->right;
        _RB_Transplant(T,z,z->right);
    }
    else if(z->right == T->NIL){
        x = z->left;
        _RB_Transplant(T,z,z->left);
    }
    else{
        y = Tree_Minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if(y->parent == z){
            x->parent =y;
        }
        else{
            _RB_Transplant(T,y,y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        _RB_Transplant(T,z,y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if(y_original_color == BLACK){
        RB_Delete_Fixup(T,x);
    }
}
void RB_Delete_Fixup(Tree * T,Node * x){
    Node * w;
    while(x != T->root && x->color == BLACK){
        if(x == x->parent->left){
            w = x->parent->right;
            if(w->color == RED){
                w->color = BLACK;
                x->parent->color = RED;
                _Left_Rotate(T,x->parent);
                w = x->parent->right;
            }
            if(w->left->color == BLACK && w->right->color == BLACK){
                w->color = RED;
                x = x->parent;
            }
            else if(w->right->color == BLACK){
                w->left->color = BLACK;
                w->color = RED;
                _Right_Rotate(T,w);
                w = x->parent->right;
            }
            w->color = x->parent->color;
            x->parent->color = BLACK;
            w->right->color = BLACK;
            _Left_Rotate(T,x->parent);
            x = T->root;
        }
        else{

        }
    }
    x->color = BLACK;
}