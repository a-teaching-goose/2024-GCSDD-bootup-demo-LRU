/*
 * DO NOT MAKE ANY CHANGES
 */

#include "../unit_test_binary_tree.h"

void traverse_pre_order_test_cases_int(std::vector<TraverseTestCase<int>> &test_cases) {

    // empty (root==null) tree
    test_cases.push_back(TraverseTestCase<int>(nullptr, {}));

    //      1
    //     / \
    //    N   N
    test_cases.push_back(TraverseTestCase<int>(new TreeNode<int>(1), {1}));

    //      1
    //     / \
    //    2   N
    auto *root = new TreeNode(1);
    root->left = new TreeNode(2);
    test_cases.push_back(TraverseTestCase<int>(root, {1, 2}));

    //      1
    //     / \
    //    N   3
    root = new TreeNode(1);
    root->right = new TreeNode(3);
    test_cases.push_back(TraverseTestCase<int>(root, {1, 3}));

    //      1
    //     / \
    //    2   3
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    test_cases.push_back(TraverseTestCase<int>(root, {1, 2, 3}));

    //          1
    //         /
    //        2
    //       /
    //      3
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    test_cases.push_back(TraverseTestCase<int>(root, {1, 2, 3}));

    //          1
    //           \
    //            2
    //             \
    //              3
    root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    test_cases.push_back(TraverseTestCase<int>(root, {1, 2, 3}));

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
    test_cases.push_back(TraverseTestCase<int>(root, {1, 2, 4, 5, 3, 6}));

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
    test_cases.push_back(TraverseTestCase<int>(root, {1, 2, 4, 7, 9, 5, 8, 3, 6}));
}