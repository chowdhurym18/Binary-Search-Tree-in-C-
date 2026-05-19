#ifndef BST_H
#define BST_H

#include <iostream>
#include "TreeNode.h"

using namespace std;

template<typename T>
class BST {

private:
    TreeNode<T>* root;
    int size;

public:

    BST() {
        root = nullptr;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool search(T e) {

        TreeNode<T>* current = root;

        while (current != nullptr) {

            if (e < current->element) {
                current = current->left;
            }
            else if (e > current->element) {
                current = current->right;
            }
            else {
                return true;
            }
        }

        return false;
    }

    void insert(T e) {

        if (root == nullptr) {

            root = new TreeNode<T>(e);

        } else {

            TreeNode<T>* parent = nullptr;
            TreeNode<T>* current = root;

            while (current != nullptr) {

                parent = current;

                if (e < current->element) {
                    current = current->left;
                }
                else if (e > current->element) {
                    current = current->right;
                }
                else {
                    return;
                }
            }

            if (e < parent->element) {
                parent->left = new TreeNode<T>(e);
            }
            else {
                parent->right = new TreeNode<T>(e);
            }
        }

        size++;
    }

    // Inorder Traversal
    void inorder() {
        inorder(root);
    }

    void inorder(TreeNode<T>* node) {

        if (node == nullptr)
            return;

        inorder(node->left);

        cout << node->element << " ";

        inorder(node->right);
    }

    // Preorder Traversal
    void preorder() {
        preorder(root);
    }

    void preorder(TreeNode<T>* node) {

        if (node == nullptr)
            return;

        cout << node->element << " ";

        preorder(node->left);

        preorder(node->right);
    }

    // Postorder Traversal
    void postorder() {
        postorder(root);
    }

    void postorder(TreeNode<T>* node) {

        if (node == nullptr)
            return;

        postorder(node->left);

        postorder(node->right);

        cout << node->element << " ";
    }

    // Remove Node
    void remove(T e) {

        TreeNode<T>* parent = nullptr;
        TreeNode<T>* current = root;

        while (current != nullptr) {

            if (e < current->element) {

                parent = current;
                current = current->left;

            }
            else if (e > current->element) {

                parent = current;
                current = current->right;

            }
            else {
                break;
            }
        }

        // Element not found
        if (current == nullptr)
            return;

        // Case 1: No left child
        if (current->left == nullptr) {

            if (parent == nullptr) {

                root = current->right;

            } else {

                if (e < parent->element) {
                    parent->left = current->right;
                }
                else {
                    parent->right = current->right;
                }
            }
        }

        // Case 2: Has left child
        else {

            TreeNode<T>* parent2 = current;
            TreeNode<T>* rightMost = current->left;

            while (rightMost->right != nullptr) {

                parent2 = rightMost;
                rightMost = rightMost->right;
            }

            current->element = rightMost->element;

            if (parent2->right == rightMost) {
                parent2->right = rightMost->left;
            }
            else {
                parent2->left = rightMost->left;
            }
        }

        size--;
    }
};

#endif
