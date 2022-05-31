/*
 * DO NOT MAKE ANY CHANGES
 */

#pragma once

template<class T>
class BinaryTree;

template<class T>
class TreeNode {
public:
    friend class BinaryTree<T>;

    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

public:
    TreeNode() : left(nullptr), right(nullptr) {}

    TreeNode(const T val) : TreeNode() {
        this->val = val;
    }
};