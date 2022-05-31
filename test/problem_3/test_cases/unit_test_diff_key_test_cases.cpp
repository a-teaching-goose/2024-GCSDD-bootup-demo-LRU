#include "../unit_test_merkle_kv.h"

#include "gtest/gtest.h"
#include <cmath>

void diff_key_test_cases(std::vector<MerkleKVDiffTestCase> &test_cases) {
    test_cases = {
            {
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                    },
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                    },
                    {},
            },
            {
                    {
                            {"x1", "1"},
                    },
                    {
                            {"x1", "2"},
                    },
                    {"x1"},
            },
            {
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                    },
                    {
                            {"x1", "0"},
                            {"x2", "2"},
                    },
                    {"x1"},
            },
            {
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                    },
                    {
                            {"x1", "1"},
                            {"x2", "0"},
                    },
                    {"x2"},
            },
            {
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                    },
                    {
                            {"x1", "4"},
                            {"x2", "5"},
                    },
                    {"x1", "x2"},
            },
            {
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                            {"x3", "3"},
                            {"x4", "4"},
                    },
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                            {"x3", "3"},
                            {"x4", "4"},
                    },
                    {},
            },
            {
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                            {"x3", "3"},
                            {"x4", "4"},
                    },
                    {
                            {"x1", "1"},
                            {"x2", "0"},
                            {"x3", "3"},
                            {"x4", "4"},
                    },
                    {"x2"},
            },
            {
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                            {"x3", "3"},
                            {"x4", "4"},
                    },
                    {
                            {"x1", "1"},
                            {"x2", "0"},
                            {"x3", "0"},
                            {"x4", "4"},
                    },
                    {"x2", "x3"},
            },
            {
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                            {"x3", "3"},
                            {"x4", "4"},
                            {"x5", "5"},
                            {"x6", "6"},
                            {"x7", "7"},
                            {"x8", "8"},
                    },
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                            {"x3", "0"},
                            {"x4", "4"},
                            {"x5", "5"},
                            {"x6", "6"},
                            {"x7", "7"},
                            {"x8", "8"},
                    },
                    {"x3"},
            },
            {
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                            {"x3", "3"},
                            {"x4", "4"},
                            {"x5", "5"},
                            {"x6", "6"},
                            {"x7", "7"},
                            {"x8", "8"},
                    },
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                            {"x3", "0"},
                            {"x4", "4"},
                            {"x5", "5"},
                            {"x6", "6"},
                            {"x7", "7"},
                            {"x8", "0"},
                    },
                    {"x3", "x8"},
            },
            {
                    {
                            {"x1", "0"},
                            {"x2", "2"},
                            {"x3", "0"},
                            {"x4", "4"},
                            {"x5", "5"},
                            {"x6", "6"},
                            {"x7", "7"},
                            {"x8", "8"},
                    },
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                            {"x3", "3"},
                            {"x4", "4"},
                            {"x5", "0"},
                            {"x6", "6"},
                            {"x7", "0"},
                            {"x8", "0"},
                    },
                    {"x1", "x3", "x5", "x7", "x8"},
            },
            {
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                            {"x3", "3"},
                            {"x4", "4"},
                            {"x5", "5"},
                            {"x6", "6"},
                            {"x7", "7"},
                            {"x8", "8"},
                    },
                    {
                            {"x1", "a"},
                            {"x2", "b"},
                            {"x3", "c"},
                            {"x4", "d"},
                            {"x5", "5"},
                            {"x6", "6"},
                            {"x7", "7"},
                            {"x8", "8"},
                    },
                    {"x1", "x2", "x3", "x4"},
            },
            {
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                            {"x3", "3"},
                            {"x4", "4"},
                            {"x5", "5"},
                            {"x6", "6"},
                            {"x7", "7"},
                            {"x8", "8"},
                    },
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                            {"x3", "3"},
                            {"x4", "4"},
                            {"x5", "a"},
                            {"x6", "b"},
                            {"x7", "c"},
                            {"x8", "d"},
                    },
                    {"x5", "x6", "x7", "x8"},
            },
            {
                    {
                            {"x1", "1"},
                            {"x2", "2"},
                            {"x3", "3"},
                            {"x4", "4"},
                            {"x5", "5"},
                            {"x6", "6"},
                            {"x7", "7"},
                            {"x8", "8"},
                    },
                    {
                            {"x1", "r"},
                            {"x2", "s"},
                            {"x3", "t"},
                            {"x4", "q"},
                            {"x5", "a"},
                            {"x6", "b"},
                            {"x7", "c"},
                            {"x8", "d"},
                    },
                    {"x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8"},
            },
    };
}

void diff_key_test_cases_large_kv(std::vector<MerkleKVDiffTestCase> &test_cases, int size) {
    std::vector<int> changed_keys_id = {0, size / 4, size / 3, size / 2, size - size / 3, size - size / 7, size - 1};
    diff_key_test_cases_large_kv(test_cases, size, changed_keys_id);
}

void diff_key_test_cases_large_kv_no_diff(std::vector<MerkleKVDiffTestCase> &test_cases, int size) {
    diff_key_test_cases_large_kv(test_cases, size, {});
}

void diff_key_test_cases_large_kv(std::vector<MerkleKVDiffTestCase> &test_cases, int size,
                                  std::vector<int> changed_keys_id) {
    // verify size is power of 2
    if (ceil(log2(size)) != floor(log2(size))) {
        FAIL() << "test size must be power of 2";
    }

    //generate the original kv
    std::map<std::string, std::string> kv1;
    for (int i = 0; i < size; i++) {
        kv1[std::to_string(i)] = std::to_string(i);
    }

    //generate the modified kv
    std::map<std::string, std::string> kv2(kv1);

    std::set<std::string> changed_keys;
    for (int id: changed_keys_id) {
        changed_keys.insert(std::to_string(id));
    }

    for (auto &changed_key: changed_keys) {
        kv2[changed_key] = "nop!";
    }
    test_cases.emplace_back(
            kv1,
            kv2,
            changed_keys
    );
}