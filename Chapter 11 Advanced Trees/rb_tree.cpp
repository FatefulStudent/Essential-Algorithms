#include <iostream>

using std::cout;
using std::endl;

// 1. Every node either black or red
// 2. Root is black
// 3. Every leaf is black
// 4. If a node is red, both children are black
// 5. All paths from root to leafs contain 
//    the same amount of black nodes
struct rb_node
{
    rb_node * parent;
    rb_node * left_child;
    rb_node * right_child;
    int key;
    bool is_black;
};

struct rb_tree
{
    rb_tree(rb_node * root = 0): 
        root(root), nil(0)
    {}

    ~rb_tree(){
        delete root;
    }
    rb_node * root;
    rb_node * nil;
};

/*    
        (x)                          (y)
       /   \                        /   \
     (A)   (y)        ------>     (x)   (C)
          /   \                  /   \
        (B)   (C)              (A)   (B)
*/
void left_rotate(rb_tree * T, rb_node* x)
{
    // define y
    rb_node* y = x->right_child;
    // exchange (y) with (B)
    x->right_child = y->left_child;

    // link from y's left child to x 
    if (y->left_child != T->nil)
        y->left_child->parent = x;

    // exchanging parents
    y->parent = x->parent;
    if (x->parent == T->nil)
        T->root = y;
    else if (x == x->parent->left_child)
        x->parent->left_child = y;
    else
        x->parent->right_child = y;
    y->left_child = x;
    x->parent = y;
}


/*    
       (y)                       (x)
       /  \                     /   \
     (x)  (C)     ---->       (A)   (y)
    /   \                           / \
   (A)  (B)                       (B) (C)
*/
void right_rotate(rb_tree * T, rb_node* y)
{
    rb_node* x = y->left_child;
    y->left_child = x->right_child;

    if (y->left_child != T->nil)
        y->left_child->parent = x;

    x->parent = y->parent;
    if (y->parent == T->nil)
        T->root = x;     
    else if (y->parent->left_child == y)
        y->parent->left_child = x;
    else
        y->parent->right_child = x;
    y->parent = x;
    x->right_child = y;
}