#include <iostream>

using std::cout;
using std::endl;

enum COLOR {RED, BLACK};

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
    bool color;
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

void rb_insert(rb_tree* T, rb_node* z)
{
    rb_node* x = T->root;
    rb_node* y = T->nil;

    // finding appropriate empty spot
    while (x != T->nil)
    {
        // preserving parent
        y = x; 

        if (z->key > x->key)
            x = x->right_child;
        else
            x = x->left_child;
    }
    z->parent = y;

    if (y == T->nil)
        T->root = y;
    else if (z->key < y->key)
        y->left_child = z;
    else
        y->right_child = z;
    
    z->left_child = T->nil;
    z->right_child = T->nil;
    z->color = RED;
    rb_insert_fixup(T, z);
}

void rb_insert_fixup(rb_tree* T, rb_node* z)
{
    rb_node* uncle = 0;
    while (z->parent != T->nil && z->parent->color == RED)
    {
        // if z's parent is a left child
        if (z->parent == z->parent->parent->left_child)
        {
            uncle = z->parent->parent->right_child;
            // CASE 1
            if (uncle->color == RED)
            {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            // CASE 2 
            else if (z == z->parent->right_child) 
            {
                z = z->parent;
                left_rotate(T, z);
            }
            z->parent->color = BLACK;
            z->parent->parent->color = RED;
            right_rotate(T, z->parent->parent);
        } else {
            uncle = z->parent->parent->left_child;
            // CASE 1
            if (uncle->color == RED)
            {
                z->parent->color = BLACK;
                uncle->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else { 
                // CASE 2 
                if (z == z->parent->left_child) 
                {
                    z = z->parent;
                    right_rotate(T, z);
                }
                // CASE 3
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                left_rotate(T, z->parent->parent);
            }
        }
    }
}

void rb_transplant(rb_tree* T, rb_node* u, rb_node* v)
{
    if (u->parent == T->nil)
        T->root = v;
    else if (u == u->parent->left_child)
        u->parent->left_child = v;
    else
        u->parent->right_child = v;
    v->parent = u->parent;
}

rb_node* tree_minimum(rb_tree* T, rb_node* z)
{
    while(z->left_child != T->nil)
        return tree_minimum(T, z->left_child);
}

void rb_delete(rb_tree* T, rb_node* z)
{
    rb_node* y = z;
    rb_node* x = 0;
    bool y_orig_color = y->color;

    if (z->left_child == T->nil)
    {
        x = z->right_child;
        rb_transplant(T, z, z->right_child);
    }
    else if (z->right_child == T->nil)
    {
        x = z->left_child;
        rb_transplant(T, z, z->left_child);
    }
    else
    {
        y = tree_minimum(T, z->right_child);
        y_orig_color = y->color;
        x = y->right_child;
        if (y->parent == z)
        {
            x->parent = y;
        } 
        else
        {
            rb_transplant(T, y, y->right_child);
            y->right_child = z->right_child;
            y->right_child->parent = y;
        }
        rb_transplant(T, z, y);
        y->left_child = z->left_child;
        y->left_child->parent = y;
        y->color = z->color;
    }

    if (y_orig_color == BLACK)
        rb_delete_fixup(T, x);
}

void rb_delete_fixup(rb_tree* T, rb_node* x)
{
    
}