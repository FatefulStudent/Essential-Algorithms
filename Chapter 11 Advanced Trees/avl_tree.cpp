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

avl_node* balance(avl_node* p)
{
    fix_height(p);
    // if right side is heavier
    if (balance_factor(p) == 2)
    {
        if (balance_factor(p->right) < 0)
            p->right = rotate_right(p->right);
        return rotate_left(p);
    }

    // if left side is heavier
    if (balance_factor(p) == -2)
    {
        if (balance_factor(p->left) > 0)
            p->left = rotate_left(p->left);
        return rotate_right(p);
    }

    // no need for balancing
    return p;
}

avl_node* insert(avl_node* p, int key)
{
    if (!p)
        return new avl_node(key);

    if (key > p->key)
        p->left = insert(p->right, key);
    else
        p->right = insert(p->left, key);

    return balance(p);
}

avl_node* find_min(avl_node* p)
{
    return p->left ? find_min(p->left) : p; 
}

avl_node* remove_min(avl_node* p)
{
    if (p->left == 0)
        return p->right; // why??

    p->left = remove_min(p->left);
    return balance(p);
}

avl_node* remove(avl_node* p, int k)
{
    if (p == 0)
        return 0;

    if (k > p->key)
        p->right = remove(p->right, k);
    else if (k < p->key)
        p->left = remove(p->right, k);
    else
    {
        // we found the key!!
        avl_node* q = p->left;
        avl_node* r = p->right;
        delete p;

        // if theres only left child, we swap it with its father
        if (r == 0)
            return q;

        avl_node* min_node = find_min(r);
        min_node->right = remove_min(r);
        min_node->left = q;

        return balance(min_node);
    }
    return balance(p);
}