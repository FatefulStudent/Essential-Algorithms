#include <iostream>

using std::cout;
using std::endl;

struct avl_node
{
    avl_node(int key):
        key(key), height(1), left(0), right(0)
    {}

    int key;
    unsigned char height;
    avl_node* left;
    avl_node* right;
};

// returns height of a node if it is not empty
// if it is returns 0
unsigned char height(avl_node* node)
{
    return node ? node->height : 0;
}

// calculates balance factor of the node
// should be in range [-1, 1]
int balance_factor(avl_node* node)
{
    return height(node->right) - height(node->left);
}

// updates height field using height of left and right
void fix_height(avl_node* node)
{   

    unsigned char l_height = height(node->left);
    unsigned char r_height = height(node->right);
      
    node->height = l_height>r_height ? l_height : r_height;
}

avl_node* rotate_right(avl_node* p)
{
    avl_node* q = p->left;

    p->left = q->right;
    q->right = p;

    fix_height(p);
    fix_height(q);
    return q;
}

avl_node* rotate_left(avl_node* q)
{
    avl_node* p = q->right;

    q->right = p->left;
    p->left = q;

    fix_height(q);
    fix_height(p);
    return p;
}