#include <stack>
#include "binary_tree.h"

/*
 * To be done iteratively
 * NO RECURSION ALLOWED
 */
template<class T>
std::vector<T> *BinaryTree<T>::dfs_in_order() {
    auto *result = new std::vector<T>();
    std::stack<TreeNode<T> *> stack;

    if (root == nullptr) {
        return result;
    }

    stack.push(root);
    while (!stack.empty()) {
        auto node = stack.top();
        while (node->left != nullptr) {
            stack.push(node->left);
            node = node->left;
        }

        while (!stack.empty()) {
            node = stack.top();
            stack.pop();
            result->push_back(node->val);
            if (node->right != nullptr) {
                stack.push(node->right);
                break;
            }
        }
    }
    return result;
}

/*
 * To be done iteratively
 * NO RECURSION ALLOWED
 */
template<class T>
std::vector<T> *BinaryTree<T>::dfs_pre_order() {
    auto *result = new std::vector<T>();
    std::stack<TreeNode<T> *> stack;

    if (root == nullptr) {
        return result;
    }

    stack.push(root);
    while (!stack.empty()) {
        auto node = stack.top();
        stack.pop();
        result->push_back(node->val);
        if (node->right != nullptr) {
            stack.push(node->right);
        }
        if (node->left != nullptr) {
            stack.push(node->left);
        }
    }

    return result;
}

template<class T>
TreeNode<T> *BinaryTree<T>::lca(TreeNode<T> *node_start, TreeNode<T> *node_1, TreeNode<T> *node_2) {
    if (node_start == nullptr) {
        return nullptr;
    }

    if (node_start->val == node_1->val || node_start->val == node_2->val) {
        return node_start;
    }

    TreeNode<int> *left = lca(node_start->left, node_1, node_2);
    TreeNode<int> *right = lca(node_start->right, node_1, node_2);

    if (left == nullptr && right == nullptr) {
        return nullptr;
    }

    if (left != nullptr && right != nullptr) {
        return node_start;
    }

    return left != nullptr ? left : right;
    /*
     * TODO: homework
     * This helper function is OPTIONAL.
     * Use this or change it to your like.
     * If you do, remember to change the same in the .h file.
     */
}

template<class T>
TreeNode<T> *BinaryTree<T>::lca(TreeNode<T> *node_1, TreeNode<T> *node_2) {
    return lca(root, node_1, node_2);
}

template<class T>
BinaryTree<T>::~BinaryTree() {
    delete_tree(root);
}

template<class T>
void BinaryTree<T>::delete_tree(TreeNode<T> *node) {
    if (node == nullptr) {
        return;
    }
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree &another_tree) {
    if (another_tree.root == nullptr) {
        root = nullptr;
        return;
    }

    root = new TreeNode(another_tree.root->val);

    copy_node(root, another_tree.root);
}

template<class T>
void BinaryTree<T>::copy_node(TreeNode<T> *tree_node_1, TreeNode<T> *tree_node_2) {

    if (tree_node_2->left) {
        tree_node_1->left = new TreeNode(tree_node_2->left->val);
        copy_node(tree_node_1->left, tree_node_2->left);
    }

    if (tree_node_2->right) {
        tree_node_1->right = new TreeNode(tree_node_2->right->val);
        copy_node(tree_node_1->right, tree_node_2->right);
    }
}

template<class T>
bool BinaryTree<T>::operator==(const BinaryTree &another_tree) const {
    return check_equal(root, another_tree.root);
}

template<class T>
bool BinaryTree<T>::check_equal(TreeNode<T> *tree_node_1, TreeNode<T> *tree_node_2) const {
    if (tree_node_1 == nullptr && tree_node_2 == nullptr) {
        return true;
    }
    if (tree_node_1 == nullptr && tree_node_2 != nullptr) {
        return false;
    }
    if (tree_node_1 != nullptr && tree_node_2 == nullptr) {
        return false;
    }
    if (tree_node_1->val != tree_node_2->val) {
        return false;
    }

    return check_equal(tree_node_1->left, tree_node_2->left) &&
           check_equal(tree_node_1->right, tree_node_2->right);
}


template<class T>
bool BinaryTree<T>::operator!=(const BinaryTree &another_tree) const {
    return !(another_tree == *this);
}

template<class T>
TreeNode<T> *BinaryTree<T>::get_root() const {
    return root;
}