/*
 * DO NOT MAKE ANY CHANGES
 */

#include "../unit_test_binary_tree.h"

// push_back vs emplace_back
// https://yasenh.github.io/post/cpp-diary-1-emplace_back/#:~:text=push_back%3A%20Adds%20a%20new%20element,after%20its%20current%20last%20element.

void lca_test_cases_int(std::vector<LCATestCase<int> *> &test_cases) {

    //      1
    //     / \
    //    2   N
    auto *root = new TreeNode(1);
    root->left = new TreeNode(2);
    auto *tree = new BinaryTree(root);
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 1, 2, 1));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 2, 1, 1));
    delete tree;

    //      1
    //     / \
    //    N   3
    root = new TreeNode(1);
    root->right = new TreeNode(3);
    tree = new BinaryTree(root);
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 1, 3, 1));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 3, 1, 1));
    delete tree;

    //      1
    //     / \
    //    2   3
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    tree = new BinaryTree(root);
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 1, 2, 1));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 2, 1, 1));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 1, 3, 1));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 3, 1, 1));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 2, 3, 1));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 3, 2, 1));
    delete tree;

    //          1
    //         /
    //        2
    //       /
    //      3
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    tree = new BinaryTree(root);
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 2, 3, 2));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 3, 2, 2));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 1, 3, 1));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 3, 1, 1));
    delete tree;

    //          1
    //           \
    //            2
    //             \
    //              3
    root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    tree = new BinaryTree(root);
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 2, 3, 2));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 3, 2, 2));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 1, 3, 1));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 3, 1, 1));
    delete tree;

    //      1
    //     / \
    //    2   3
    //   / \   \
    //  4   5   6
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(6);
    tree = new BinaryTree(root);
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 4, 5, 2));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 4, 2, 2));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 4, 6, 1));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 4, 3, 1));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 5, 3, 1));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 6, 2, 1));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 2, 3, 1));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 4, 1, 1));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 6, 1, 1));
    delete tree;

    //             1
    //            /  \
    //           2    3
    //          /  \    \
    //         4    5    6
    //        /    /
    //       7    8
    //      /
    //     9
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->left->left = new TreeNode(9);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(6);
    tree = new BinaryTree(root);
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 9, 6, 1));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 9, 1, 1));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 9, 8, 2));
    test_cases.emplace_back(new LCATestCase<int>(new BinaryTree<int>(*tree), 7, 3, 1));
    delete tree;
}