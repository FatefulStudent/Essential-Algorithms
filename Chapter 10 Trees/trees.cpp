#include <iostream>

using std::endl;
using std::cout;

class BinaryTreeNode
{
public:
    BinaryTreeNode(char const * name): name(name)
    {}
    
    char const * name;
    BinaryTreeNode * left_child;
    BinaryTreeNode * right_child;
};

int main()
{
    BinaryTreeNode root("4");
    BinaryTreeNode node1("1");
    BinaryTreeNode node2("2");
    BinaryTreeNode node3("3");
    BinaryTreeNode node5("5");
    BinaryTreeNode node6("6");
    BinaryTreeNode node7("7");
    BinaryTreeNode node8("8");
    
    root.left_child = &node2;
    root.right_child = &node5;
    
    node2.left_child = &node1;
    node2.right_child = &node3;
    
    node5.right_child = &node7;
    
    node7.left_child = &node6;
    node7.right_child = &node8;
    
    return 0;
}