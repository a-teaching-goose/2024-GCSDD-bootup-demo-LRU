/*
 * DO NOT MAKE ANY CHANGES
 */

#include "unit_test_utils.h"

bool is_valid(const std::string &result) {
    if (result.size() == 0) {
        return true;
    }
    std::stack<char> stack;
    for (char c: result) {
        if (!stack.empty() && stack.top() == '(' && c == ')') {
            stack.pop();
            continue;
        }
        stack.push(c);
    }
    return stack.empty();
}

TEST(problem_1, valid_parenthesis_checker) {
    std::vector<ValidParenthesesCheckerTestCase> test_cases = {
            ValidParenthesesCheckerTestCase("", true),
            ValidParenthesesCheckerTestCase("(", false),
            ValidParenthesesCheckerTestCase(")", false),
            ValidParenthesesCheckerTestCase("()", true),
            ValidParenthesesCheckerTestCase("((", false),
            ValidParenthesesCheckerTestCase("))", false),
            ValidParenthesesCheckerTestCase(")(", false),
            ValidParenthesesCheckerTestCase(")(", false),
            ValidParenthesesCheckerTestCase("()", true),
            ValidParenthesesCheckerTestCase("()(", false),
            ValidParenthesesCheckerTestCase("(()", false),
            ValidParenthesesCheckerTestCase(")()", false),
            ValidParenthesesCheckerTestCase("()()", true),
            ValidParenthesesCheckerTestCase("(())", true),
            ValidParenthesesCheckerTestCase("())(", false),
            ValidParenthesesCheckerTestCase("()()()", true),
            ValidParenthesesCheckerTestCase("()(())", true),
            ValidParenthesesCheckerTestCase("(())()", true),
            ValidParenthesesCheckerTestCase("((()))", true),
            ValidParenthesesCheckerTestCase("((()))()()(())", true),
            ValidParenthesesCheckerTestCase("()()()()(())", true),
    };

    for (ValidParenthesesCheckerTestCase &test_case: test_cases) {
        ASSERT_EQ(test_case.expect, is_valid(test_case.input));
    }
}
