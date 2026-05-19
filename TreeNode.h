#ifndef TREENODE_H
#define TREENODE_H

template<typename T>
class TreeNode {

public:
    T element;

    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T e) {
        element = e;
        left = nullptr;
        right = nullptr;
    }
};

#endif
