#include<stdio.h>
#include<stdlib.h>

struct RBTree{
    int data;
    char color;
    struct RBTree *left;
    struct RBTree *parent;
    struct RBTree *right;
};

struct red_black_tree{
    struct RBTree *root;
    struct RBTree *NIL;
};

struct RBTree* getNode(int val){
    struct RBTree *temp = (struct RBTree*)malloc(sizeof(struct RBTree));
    temp->data = val;
    temp->color = 'R';
    temp->left = temp->right = temp->parent = NULL;

    return temp;
}

struct red_black_tree* initializeRoot(){
    struct red_black_tree *root = (struct red_black_tree*)malloc(sizeof(struct red_black_tree));
    struct RBTree *nil = (struct RBTree*)malloc(sizeof(struct RBTree));
    nil->color = 'B';
    nil->data = -1;
    nil->left = nil->parent = nil->right = NULL;
    root->NIL = nil;
    root->root = root->NIL;

    return root;
} 

void left_rotate(struct red_black_tree *r,struct RBTree *node){
    struct RBTree *y = node->right;
    node->right = y->left;
    if(y->left != r->NIL){
        y->left->parent = node;
    }
    y->parent = node->parent;
    if(node->parent == r->NIL){
        r->root = y;
    }
    else if(node == node->parent->left){
        node->parent->left = y;
    }
    else{
        node->parent->right = y;
    }
    y->left = node;
    node->parent = y;
}

void right_rotate(struct red_black_tree *r,struct RBTree *node){
    struct RBTree *y = node->left;
    node->left = y->right;
    if(y->right != r->NIL){
        y->right->parent = node;
    }
    y->parent = node->parent;
    if(node->parent == r->NIL){
        r->root = y;
    }
    else if(node == node->parent->right){
        node->parent->right = y;
    }
    else{
        node->parent->left = y;
    }
    y->right = node;
    node->parent = y;
}

void insertionfix(struct red_black_tree *r,struct RBTree *node){
    while(node->parent->color == 'R'){
        if(node->parent == node->parent->parent->left){
            struct RBTree *y = node->parent->parent->right;
            if(y->color == 'R'){         //   CASE - 1
                node->parent->color = 'B';
                y->color = 'B';
                node->parent->parent->color = 'R';
                node = node->parent->parent;
            }
            else{
                if(node == node->parent->right){       // CASE - 2
                    node = node->parent;
                    left_rotate(r,node);
                }
                                                        // CASE - 3
                node->parent->color = 'B';
                node->parent->parent->color = 'R';
                right_rotate(r,node->parent->parent);
            }
        }
        else{
            struct RBTree *y = node->parent->parent->left;
            if(y->color == 'R'){
                node->parent->color = 'B';
                y->color = 'B';
                node->parent->parent->color = 'R';
                node = node->parent->parent;
            }
            else{
                if(node == node->parent->left){
                    node = node->parent;
                    right_rotate(r,node);
                }
                node->parent->color = 'B';
                node->parent->parent->color = 'R';
                left_rotate(r,node->parent->parent);
            }
        }
    }
    r->root->color = 'B';
}

void insert(struct red_black_tree *r,struct RBTree *node){
    struct RBTree *y = r->NIL;
    struct RBTree *temp = r->root;

    while(temp != r->NIL){
        y = temp;
        if(node->data < temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    } 
    node->parent = y;

    if(y == r->NIL){
        r->root = node;
    }
    else if(node->data < y->data){
        y->left = node;
    }
    else{
        y->right = node;
    }

    node->right = r->NIL;
    node->left = r->NIL;

    insertionfix(r,node);
}

void inorder(struct red_black_tree *r,struct RBTree *node){
    if(node != r->NIL){
        inorder(r,node->left);
        printf("%d ",node->data);
        inorder(r,node->right);
    }
}

void transplantRB(struct red_black_tree *r, struct RBTree *u,struct RBTree *v){
    if(u->parent == r->NIL){
        r->root = v;
    }
    else if(u == u->parent->left){
        u->parent->left = v;
    }
    else{
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void deletefix(struct red_black_tree *r,struct RBTree *node){
    while(node != r->root && node->color == 'B'){
        if(node == node->parent->left){
            struct RBTree *y = node->parent->right;
            if(y->color == 'R'){
                y->color = 'B';
                node->parent->color = 'R';
                left_rotate(r,node->parent);
                y = node->parent->right;
            }

            if(y->left->color == 'B' && y->right->color == 'B'){
                y->color = 'R';
                node = node->parent;
            }
            else{
                if(y->right->color == 'B'){
                    y->left->color = 'B';
                    y->color = 'R';
                    right_rotate(r,y);
                    y = node->parent->right;
                }
                y->color = node->parent->color;
                node->parent->color = 'B';
                y->right->color = 'B';
                left_rotate(r,node->parent);
                node = r->root;
            }
        }
        else{
            struct RBTree *y = node->parent->left;
            if(y->color == 'R'){
                y->color = 'B';
                node->parent->color = 'R';
                right_rotate(r,node->parent);
                y = node->parent->left;
            }

            if(y->right->color == 'B' && y->left->color == 'B'){
                y->color = 'R';
                node = node->parent;
            }
            else{
                if(y->left->color == 'B'){
                    y->right->color = 'B';
                    y->color = 'R';
                    left_rotate(r,y);
                    y = node->parent->left;
                }
                y->color = node->parent->color;
                node->parent->color = 'B';
                y->left->color =  'B';
                right_rotate(r,node->parent);
                node = r->root;
            }
        }
    }
    node->color = 'B';
}

struct RBTree* minimumelement(struct red_black_tree *r,struct RBTree *node){
    while(node->left != r->NIL){
        node = node->left;
    }
    return node;
}

void delete(struct red_black_tree *r,struct RBTree *node){
    struct RBTree *y = node;
    struct RBTree *x;
    char original = y->color;
    if(node->left == r->NIL){
        x = node->right;
        transplantRB(r,node,node->right);
        //printf("nnq");
    }
    else if(node->right == r->NIL){
        x = node->left;
        //printf("nnss");
        transplantRB(r,node,node->left);
       // printf("nsssssn");
    }
    else{
//        printf("nngfggg");

        y = minimumelement(r,node->right);
        
        original = y->color;
        x = y->right;
        if(y->parent == node){
            x->parent = node;
        }
        else{
            //printf("nnwff");
            transplantRB(r,y,y->right);
            y->right = node->right;
            y->right->parent = y;
        }
        transplantRB(r,node,y);
        y->left = node->left;
        y->left->parent = y;
        y->color = node->color;
    }
    //printf("nnffffffff");
    
    if(original == 'B'){
        deletefix(r,x);

    }
    
}


int search(struct RBTree *root,struct red_black_tree *r, int key) 
{   
    if (root == r->NIL ){
        return 0;
    }
    if( root->data == key) 
        return 1; 
     
    if (root->data < key) 
        return search(root->right,r, key); 
    else
        return search(root->left,r, key); 
} 

struct RBTree* getit(int val,struct RBTree *node,struct red_black_tree *r){
    if(node != r->NIL ){
        if(val == node->data){
            return node;
        }
        else{
            struct RBTree* node1 = getit(val,node->left,r);
            if(node1 == r->NIL){
                node1 = getit(val,node->right,r);
            }
            return node1;
        }
        
    }
    else{
        return r->NIL;
    }
    
}

int main(){
    struct red_black_tree *root = initializeRoot();
    
    while(1){
        int key;
        printf("Enter the operation which you want to do :\n");
        printf("1.insert\n");
        printf("2.delete\n");
        printf("3.search\n");
        printf("4.print inorder\n");
        printf("5.to exit\n");
        scanf("%d",&key);

        if(key == 5){
            break;
        }
        switch (key){
        case 1:
                printf("Enter the number to insert: ");
                int a;
                scanf("%d",&a);
                struct RBTree *node = getNode(a);
                insert(root,node);   
                break;
        case 2:
                printf("Enter the number to delete: ");
                
                scanf("%d",&a);
                struct RBTree *nodetd = getit(a,root->root,root);
                delete(root,nodetd);   
                break;
        case 3:
                printf("Enter the element to search :");
                scanf("%d",&a);
                if(search(root->root,root,a)){
                    printf("YES %d is present !",a);
                }
                else{
                    printf("NO %d is not present ! \n",a);
                }
                
                break;
        case 4:
                printf("Inorder of Red Black Tree is : ");
                inorder(root,root->root);
                printf("\n");
                break;        
        
        default:
            break;
        }

        
    }
    
    


    return 0;
}