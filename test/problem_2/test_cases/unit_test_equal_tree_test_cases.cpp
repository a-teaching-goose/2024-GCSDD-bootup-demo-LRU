/*
 * DO NOT MAKE ANY CHANGES
 */

#include "../unit_test_binary_tree.h"

void equal_tree_test_cases_int(std::vector<EqualTreeTestCase<int>> &test_cases) {

    // empty (root==null) tree
    test_cases.push_back(EqualTreeTestCase<int>(nullptr, nullptr, true));

    //      1
    //     / \      vs null tree
    //    N   N
    auto root_1 = new TreeNode(1);
    auto root_2 = (TreeNode<int> *) nullptr;
    test_cases.push_back(EqualTreeTestCase<int>(root_1, nullptr, false));

    //      1          1
    //     / \  vs    / \
    //    N   N      N   N
    test_cases.push_back(EqualTreeTestCase<int>(new TreeNode<int>(1), new TreeNode<int>(1), true));

    //      1          2
    //     / \  vs    / \
    //    N   N      N   N
    test_cases.push_back(EqualTreeTestCase<int>(new TreeNode<int>(1), new TreeNode<int>(2), false));

    //      1
    //     / \
    //    2   N
    root_1 = new TreeNode(1);
    root_1->left = new TreeNode(2);

    //      1
    //     / \
    //    2   N
    root_2 = new TreeNode(1);
    root_2->left = new TreeNode(2);
    test_cases.push_back(EqualTreeTestCase<int>(root_1, root_2, true));

    //      1
    //     / \
    //    2   N
    root_1 = new TreeNode(1);
    root_1->left = new TreeNode(2);

    //      1
    //     / \
    //    3   N
    root_2 = new TreeNode(1);
    root_2->left = new TreeNode(3);
    test_cases.push_back(EqualTreeTestCase<int>(root_1, root_2, false));

    //      1
    //     / \
    //    2   N
    root_1 = new TreeNode(1);
    root_1->left = new TreeNode(2);

    //      3
    //     / \
    //    2   N
    root_2 = new TreeNode(3);
    root_2->left = new TreeNode(2);
    test_cases.push_back(EqualTreeTestCase<int>(root_1, root_2, false));

    //      1
    //     / \
    //    N   2
    root_1 = new TreeNode(1);
    root_1->right = new TreeNode(2);

    //      1
    //     / \
    //    N   2
    root_2 = new TreeNode(1);
    root_2->right = new TreeNode(2);
    test_cases.push_back(EqualTreeTestCase<int>(root_1, root_2, true));

    //      1
    //     / \
    //    N   2
    root_1 = new TreeNode(1);
    root_1->right = new TreeNode(2);

    //      1
    //     / \
    //    N   3
    root_2 = new TreeNode(1);
    root_2->right = new TreeNode(3);
    test_cases.push_back(EqualTreeTestCase<int>(root_1, root_2, false));

    //      1
    //     / \
    //    N   2
    root_1 = new TreeNode(1);
    root_1->right = new TreeNode(2);

    //      3
    //     / \
    //    N   2
    root_2 = new TreeNode(3);
    root_2->right = new TreeNode(2);
    test_cases.push_back(EqualTreeTestCase<int>(root_1, root_2, false));

    //      1
    //     / \
    //    2   3
    root_1 = new TreeNode(1);
    root_1->left = new TreeNode(2);
    root_1->right = new TreeNode(3);

    //      1
    //     / \
    //    2   3
    root_2 = new TreeNode(1);
    root_2->left = new TreeNode(2);
    root_2->right = new TreeNode(3);
    test_cases.push_back(EqualTreeTestCase<int>(root_1, root_2, true));

    //      1
    //     / \
    //    2   3
    root_1 = new TreeNode(1);
    root_1->left = new TreeNode(2);
    root_1->right = new TreeNode(3);

    //      1
    //     / \
    //    3   4
    root_2 = new TreeNode(1);
    root_2->left = new TreeNode(3);
    root_2->right = new TreeNode(4);
    test_cases.push_back(EqualTreeTestCase<int>(root_1, root_2, false));

    //      1
    //     / \
    //    2   3
    //   / \   \
    //  4   5   6
    root_1 = new TreeNode(1);
    root_1->left = new TreeNode(2);
    root_1->left->left = new TreeNode(4);
    root_1->left->right = new TreeNode(5);
    root_1->right = new TreeNode(3);
    root_1->right->right = new TreeNode(6);

    //      1
    //     / \
    //    2   3
    //   / \   \
    //  4   5   6
    root_2 = new TreeNode(1);
    root_2->left = new TreeNode(2);
    root_2->left->left = new TreeNode(4);
    root_2->left->right = new TreeNode(5);
    root_2->right = new TreeNode(3);
    root_2->right->right = new TreeNode(6);
    test_cases.push_back(EqualTreeTestCase<int>(root_1, root_2, true));

    //      1
    //     / \
    //    2   3
    //   / \   \
    //  4   5   6
    root_1 = new TreeNode(1);
    root_1->left = new TreeNode(2);
    root_1->left->left = new TreeNode(4);
    root_1->left->right = new TreeNode(5);
    root_1->right = new TreeNode(3);
    root_1->right->right = new TreeNode(6);

    //      1
    //     / \
    //    2   3
    //   / \   \
    //  4   5   7
    root_2 = new TreeNode(1);
    root_2->left = new TreeNode(2);
    root_2->left->left = new TreeNode(4);
    root_2->left->right = new TreeNode(5);
    root_2->right = new TreeNode(3);
    root_2->right->right = new TreeNode(7);
    test_cases.push_back(EqualTreeTestCase<int>(root_1, root_2, false));

    //      1
    //     / \
    //    2   3
    //   / \   \
    //  4   5   6
    root_1 = new TreeNode(1);
    root_1->left = new TreeNode(2);
    root_1->left->left = new TreeNode(4);
    root_1->left->right = new TreeNode(5);
    root_1->right = new TreeNode(3);
    root_1->right->right = new TreeNode(6);

    //      1
    //     / \
    //    2   3
    //   /     \
    //  4       6
    root_2 = new TreeNode(1);
    root_2->left = new TreeNode(2);
    root_2->left->left = new TreeNode(4);
    root_2->right = new TreeNode(3);
    root_2->right->right = new TreeNode(6);
    test_cases.push_back(EqualTreeTestCase<int>(root_1, root_2, false));

    //      1
    //     / \
    //    2   3
    //   / \   \
    //  4   5   6
    root_1 = new TreeNode(1);
    root_1->left = new TreeNode(2);
    root_1->left->left = new TreeNode(4);
    root_1->left->right = new TreeNode(5);
    root_1->right = new TreeNode(3);
    root_1->right->right = new TreeNode(6);

    //      1
    //     / \
    //    2   N
    //   / \
    //  4   5
    root_2 = new TreeNode(1);
    root_2->left = new TreeNode(2);
    root_2->left->left = new TreeNode(4);
    root_2->left->right = new TreeNode(5);
    test_cases.push_back(EqualTreeTestCase<int>(root_1, root_2, false));

    //      1
    //     / \
    //    2   3
    //   / \   \
    //  4   5   6
    root_1 = new TreeNode(1);
    root_1->left = new TreeNode(2);
    root_1->left->left = new TreeNode(4);
    root_1->left->right = new TreeNode(5);
    root_1->right = new TreeNode(3);
    root_1->right->right = new TreeNode(6);

    //      1
    //     / \
    //    N   3
    //         \
    //          6
    root_2 = new TreeNode(1);
    root_2->right = new TreeNode(3);
    root_2->right->right = new TreeNode(6);
    test_cases.push_back(EqualTreeTestCase<int>(root_1, root_2, false));
}