#include "problem_3/merkle_kv.h"

class MerkleKVMetaTestCase {
public:
    std::map<std::string, std::string> data;
    std::vector<std::string> expect_meta_tree;

    MerkleKVMetaTestCase(const std::map<std::string, std::string> &data,
                         const std::vector<std::string> &expectMetaTree) : data(data),
                                                                           expect_meta_tree(expectMetaTree) {}
};

class MerkleKVDiffTestCase {
public:
    std::map<std::string, std::string> kv1;
    std::map<std::string, std::string> kv2;
    std::set<std::string> expect;

    MerkleKVDiffTestCase(const std::map<std::string, std::string> &kv1,
                         const std::map<std::string, std::string> &kv2,
                         const std::set<std::string> &expect)
            : kv1(kv1), kv2(kv2), expect(expect) {}
};

void update_meta_tree_test_cases(std::vector<MerkleKVMetaTestCase> &test_cases);

void diff_key_test_cases(std::vector<MerkleKVDiffTestCase> &test_cases);

void diff_key_test_cases_large_kv(std::vector<MerkleKVDiffTestCase> &test_cases, int size);

void diff_key_test_cases_large_kv(std::vector<MerkleKVDiffTestCase> &test_cases, int size,
                                  std::vector<int> changed_keys_id);

void diff_key_test_cases_large_kv_no_diff(std::vector<MerkleKVDiffTestCase> &test_cases, int size);
