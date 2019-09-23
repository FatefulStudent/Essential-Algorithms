#include <iostream>
#include <vector>
#include <queue>

using std::endl;
using std::cout;

class BinaryTreeNode
{
public:
    BinaryTreeNode(char const * name): name(name), left_child(0), right_child(0)
    {}
    friend std::ostream& operator<<(std::ostream& is, BinaryTreeNode& node)
    {
        is << node.name;
        return is;
    }
    char const * name;
    BinaryTreeNode * left_child;
    BinaryTreeNode * right_child;
};

class BinaryTree
{
public:
    BinaryTree(BinaryTreeNode * root): root(root)
    {}
    // обход в прямом порядке
    

    BinaryTreeNode * root; 
};

void traverse_preorder(BinaryTreeNode * node)
{
    cout << *node << ", ";
    if (node->left_child != 0)
        traverse_preorder(node->left_child);

    if (node->right_child != 0)
        traverse_preorder(node->right_child);

    return;
}

void traverse_inorder(BinaryTreeNode * node)
{
    if (node->left_child != 0)
        traverse_inorder(node->left_child);
    cout << *node << ", ";
    if (node->right_child != 0)
        traverse_inorder(node->right_child);

    return;
}

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
    BinaryTreeNode root("D");
    BinaryTreeNode node1("E");
    BinaryTreeNode node2("B");
    BinaryTreeNode node3("A");
    BinaryTreeNode node5("C");
    
    root.left_child = &node2;
    root.right_child = &node1;
    
    node2.left_child = &node3;
    node2.right_child = &node5;

    cout << "traverse_preorder" << endl;
    traverse_preorder(&root);
    cout << endl;

    cout << "traverse_inorder" << endl;
    traverse_inorder(&root);
    cout << endl;
    
    cout << "traverse_postorder" << endl;
    traverse_postorder(&root);
    cout << endl;
    
    cout << "traverse_depth_first" << endl;
    traverse_depth_first(&root);
    cout << endl;

    return 0;
}