/*
 * DO NOT MAKE ANY CHANGES
 */

#pragma once

#include <map>
#include <vector>
#include <string>
#include <set>

/*
 * 1. fixed size KV stores
 * 2. size is 2^n, n = [0, 1, ...]
 * 3. not supporting adding new keys
 */
class MerkleKV {
private:
    std::map<std::string, std::string> map_sorted;

    std::vector<std::string> keys_sorted;

    std::vector<std::string> meta_tree;

    void update_meta_tree();

    void collect_keys();

    void compare(const std::vector<std::string> &, int, std::set<std::string> &diff_keys);

    void compare(const std::vector<std::string> &, std::set<std::string> &diff_keys);

    int right(int node_idx);

    int left(int node_idx);

public:
    MerkleKV(const MerkleKV &);

    MerkleKV(const std::map<std::string, std::string> &map_sorted) : map_sorted(map_sorted) {
        update_meta_tree();
        collect_keys();
    }

    void put(const std::string &key, const std::string &val);

    bool get(const std::string &key, std::string *val);

    size_t size() {
        return map_sorted.size();
    }

    const std::vector<std::string> &get_meta_tree() const {
        return meta_tree;
    };

    const std::vector<std::string> &get_keys_sorted() const {
        return keys_sorted;
    };

    std::set<std::string> compare(const MerkleKV &another_kv);
};