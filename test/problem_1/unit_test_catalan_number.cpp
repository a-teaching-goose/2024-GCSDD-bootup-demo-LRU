/*
 * DO NOT MAKE ANY CHANGES
 */

#include "gtest/gtest.h"
#include "problem_1/catalan_number_solver.h"

TEST(problem_1, catalan_number) {
    std::vector<size_t> expect = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862};
    for (size_t k = 0; k < expect.size(); k++) {
        ASSERT_EQ(expect[k], CatalanNumberSolver::catalan_number(k));
    }
}