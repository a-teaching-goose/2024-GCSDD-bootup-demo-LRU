/*
 * DO NOT MAKE ANY CHANGES
 */

#include "gtest/gtest.h"
#include "unit_test_binary_tree.h"

TEST(problem_2, dfs_in_order_int) {
    std::vector<TraverseTestCase<int>> test_cases;
    traverse_in_order_test_cases_int(test_cases);

    for (auto &test_case: test_cases) {
        BinaryTree<int> tree(test_case.tree);
        auto actual = tree.dfs_in_order();
        ASSERT_EQ(test_case.expect, *actual);
        delete actual;
    }
}

TEST(problem_2, dfs_pre_order_int) {
    std::vector<TraverseTestCase<int>> test_cases;
    traverse_pre_order_test_cases_int(test_cases);

    for (auto &test_case: test_cases) {
        BinaryTree<int> tree(test_case.tree);
        auto actual = tree.dfs_pre_order();
        ASSERT_EQ(test_case.expect, *actual);
        delete actual;
    }
}

TEST(problem_2, lca_int) {
    std::vector<LCATestCase<int> *> test_cases;
    lca_test_cases_int(test_cases);

    for (auto &test_case: test_cases) {
        auto actual = test_case->tree->lca(test_case->node_1, test_case->node_2);
        ASSERT_EQ(test_case->expect, actual);
        delete test_case;
    }
}

TEST(problem_2, tree_equal) {
    std::vector<EqualTreeTestCase<int>> test_cases;
    equal_tree_test_cases_int(test_cases);

    for (auto &test_case: test_cases) {
        BinaryTree<int> tree_1(test_case.root_1);
        BinaryTree<int> tree_2(test_case.root_2);
        if (test_case.expect) {
            ASSERT_TRUE(tree_1 == tree_2);
            ASSERT_FALSE(tree_1 != tree_2);
        } else {
            ASSERT_FALSE(tree_1 == tree_2);
            ASSERT_TRUE(tree_1 != tree_2);
        }
    }
}

TEST(problem_2, copy_constructor) {
    std::vector<CopyConstructorTestCase<int>> test_cases;
    copy_constructor_test_cases_int(test_cases);

    for (auto &test_case: test_cases) {
        BinaryTree<int> tree(test_case.root);
        BinaryTree<int> tree_copy(tree);

        ASSERT_TRUE(tree == tree_copy);

        // why do we not need to check whether this is a "deep copy"
    }
}