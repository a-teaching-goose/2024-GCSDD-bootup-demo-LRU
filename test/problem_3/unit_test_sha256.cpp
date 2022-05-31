#include "unit_test_sha256.h"

TEST(problem_3, sha256) {
    SHA256 sha256;
    // cases generated using https://emn178.github.io/online-tools/sha256.html
    std::vector<SHA256TestCase> test_cases = {
            SHA256TestCase("Hello World", "a591a6d40bf420404a011733cfb7b190d62c65bf0bcda32b57b277d9ad9f146e"),
            SHA256TestCase("hello world", "b94d27b9934d3e08a52e52d7da7dabfac484efe37a5380ee9088f7ace2efcde9"),
            SHA256TestCase("Seattle", "52235717290f5d209639646478dbd3645d651762f5b80af29e0ac2da10e29438"),
            SHA256TestCase("seattle", "3151a8f227c0e11fd9a7fd1aa24ebfee734503dea095c22c3b2fae09d62eeb25"),
    };

    for (auto test_case: test_cases) {
        std::string actual = sha256(test_case.text);
        ASSERT_EQ(test_case.expect, actual);
    }
}