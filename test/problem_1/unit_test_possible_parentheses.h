/*
 * DO NOT MAKE ANY CHANGES
 */

#include "gtest/gtest.h"
#include <stack>

#pragma once

class ValidParenthesesCheckerTestCase {
public:
    std::string input;
    bool expect;

    ValidParenthesesCheckerTestCase(const std::string input, bool expect) : input(input), expect(expect) {}
};