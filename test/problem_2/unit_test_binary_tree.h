/*
 * DO NOT MAKE ANY CHANGES
 */

#include "gtest/gtest.h"

#include "problem_2/binary_tree.h"

template<class T>
class TraverseTestCase {
public:
    TreeNode<T> *tree;
    std::vector<T> expect;

    TraverseTestCase(TreeNode<T> *tree, const std::vector<T> &expect) : tree(tree), expect(expect) {}
};

void traverse_in_order_test_cases_int(std::vector<TraverseTestCase<int>> &test_cases);

void traverse_pre_order_test_cases_int(std::vector<TraverseTestCase<int>> &test_cases);

template<class T>
class LCATestCase {
public:
    BinaryTree<T> *tree;
    TreeNode<T> *node_1;
    TreeNode<T> *node_2;
    TreeNode<T> *expect;

    // shallow copy of tree
    LCATestCase(BinaryTree<T> *other_tree, T node_1_val, T node_2_val, T node_expect_val) {
        tree = other_tree;
        node_1 = find_node_by_value(node_1_val);
        node_2 = find_node_by_value(node_2_val);
        expect = find_node_by_value(node_expect_val);
    };


    virtual ~LCATestCase() {
        delete tree;
    }

private:
    TreeNode<T> *find_node_by_value(T val) {
        return find_node_by_value(val, tree->get_root());
    }

    TreeNode<T> *find_node_by_value(T val, TreeNode<T> *node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->val == val) {
            return node;
        }

        TreeNode<T> *result = find_node_by_value(val, node->left);
        if (result != nullptr) {
            return result;
        }

        result = find_node_by_value(val, node->right);
        return result;
    }
};

template<class T>
class EqualTreeTestCase {
public:
    TreeNode<T> *root_1;
    TreeNode<T> *root_2;
    bool expect;

    EqualTreeTestCase(TreeNode<T> *tree1, TreeNode<T> *tree2, bool expect) : root_1(tree1), root_2(tree2),
                                                                             expect(expect) {}
};

template<class T>
class CopyConstructorTestCase {
public:
    TreeNode<T> *root;

    CopyConstructorTestCase(TreeNode<T> *root) : root(root) {}
};


void traverse_in_order_test_cases_int(std::vector<TraverseTestCase<int>> &test_cases);

void traverse_pre_order_test_cases_int(std::vector<TraverseTestCase<int>> &test_cases);

void lca_test_cases_int(std::vector<LCATestCase<int> *> &test_cases);

void equal_tree_test_cases_int(std::vector<EqualTreeTestCase<int>> &test_cases);

void copy_constructor_test_cases_int(std::vector<CopyConstructorTestCase<int>> &test_cases);
