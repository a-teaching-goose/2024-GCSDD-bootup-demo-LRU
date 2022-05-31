#include "gtest/gtest.h"
#include "problem_3/sha256/sha256.h"

class SHA256TestCase {
public:
    std::string text;
    std::string expect;

    SHA256TestCase(const std::string &text, const std::string &expect) : text(text), expect(expect) {}
};