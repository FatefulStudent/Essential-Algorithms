#include <iostream>
#include <vector>
#include <queue>

using std::endl;
using std::cout;

class BinaryTreeNode
{
public:
    BinaryTreeNode(int value): value(value), left_child(0), right_child(0)
    {}
    
    friend std::ostream& operator<<(std::ostream& is, BinaryTreeNode& node)
    {
        is << node.value;
        return is;
    }

    void add_node(int new_value)
    {
        if (new_value < value)
        {
            if (left_child == 0)
                left_child = new BinaryTreeNode(new_value);
            else
                left_child->add_node(new_value);
        } else {
            if (right_child == 0)
                right_child = new BinaryTreeNode(new_value);
            else
                right_child->add_node(new_value);
        }
            
            
    }

    BinaryTreeNode * find_node(int target)
    {
        if (target == value)
            return this;
        
        if (target < value)
        {
            if (left_child == 0)
                return 0;
            else
                left_child->find_node(target);
        } else {
            if (right_child == 0)
                return 0;
            else
                right_child->find_node(target);
        }  
    }

    int value;
    BinaryTreeNode * left_child;
    BinaryTreeNode * right_child;
};

class BinaryTree
{
public:
    BinaryTree(BinaryTreeNode * root): root(root)
    {}
    

    BinaryTreeNode * root; 
};

// обход в прямом порядке
void traverse_preorder(BinaryTreeNode * node)
{
    cout << *node << ", ";
    if (node->left_child != 0)
        traverse_preorder(node->left_child);

    if (node->right_child != 0)
        traverse_preorder(node->right_child);

    return;
}

// обход в симметричном порядке
void traverse_inorder(BinaryTreeNode * node)
{
    if (node->left_child != 0)
        traverse_inorder(node->left_child);
    cout << *node << ", ";
    if (node->right_child != 0)
        traverse_inorder(node->right_child);

    return;
}

// обход в обратном порядке
void traverse_postorder(BinaryTreeNode * node)
{
    if (node->left_child != 0)
        traverse_postorder(node->left_child);
    
    if (node->right_child != 0)
        traverse_postorder(node->right_child);

    cout << *node << ", ";

    return;
}

void traverse_depth_first(BinaryTreeNode * first_node)
{
    std::queue<BinaryTreeNode*> children;
    children.push(first_node);

    while (children.size()>0)
    {
        BinaryTreeNode* node = children.front();
        children.pop();

        cout << *node << ", ";

        if (node->left_child != 0)
            children.push(node->left_child);
    
        if (node->right_child != 0)
            children.push(node->right_child);

    }

    return;
}

int main()
{
    BinaryTreeNode root(5);
    BinaryTreeNode node1(2);
    BinaryTreeNode node2(6);

    BinaryTreeNode node3(1);
    BinaryTreeNode node4(4);

    BinaryTreeNode node5(9);
    
    
    root.left_child = &node1;
    root.right_child = &node2;

    node1.left_child = &node3;
    node1.right_child = &node4;
    
    node2.left_child = &node5;

    

    // cout << "traverse_preorder" << endl;
    // traverse_preorder(&root);
    // cout << endl;

    // cout << "traverse_inorder" << endl;
    // traverse_inorder(&root);
    // cout << endl;
    
    // cout << "traverse_postorder" << endl;
    // traverse_postorder(&root);
    // cout << endl;
    
    cout << "traverse_depth_first" << endl;
    traverse_depth_first(&root);
    cout << endl;

    BinaryTreeNode new_node(5);
    new_node.add_node(2);
    new_node.add_node(6);
    new_node.add_node(1);
    new_node.add_node(4);
    new_node.add_node(9);

    cout << "traverse_depth_first" << endl;
    traverse_depth_first(&new_node);
    cout << endl;

    cout << "find existing node " << new_node.find_node(4) << endl;
    cout << "find nonexisting node " << new_node.find_node(3) << endl;
    
    cout << endl;

    return 0;
}