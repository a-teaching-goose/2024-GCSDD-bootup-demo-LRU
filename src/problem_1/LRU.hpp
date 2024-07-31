#pragma once

#include "array_map.h"
#include "util.h"

template<typename T>
class LRUCache;

template<typename T>
class ListNode {
private:
    std::string key;
    T value;
    ListNode<T> *next;

public:
    ListNode() : next(nullptr) {}

    ListNode(const std::string &key, const T &value) : key(key), value(value), next(nullptr) {}

    friend class LRUCache<T>;
};

template<typename T>
class LRUCache {
private:
    int capacity;

    int num_of_entry;

    ArrayMap<std::string, ListNode<T> *> *map;

    ListNode<T> head; // dummy head node

public:

    explicit LRUCache(int capacity) : capacity(capacity), num_of_entry(0) {
        map = new ArrayMap<std::string, ListNode<T> *>(capacity);
    }

    int get_capacity() {
        return capacity;
    }

    bool get(const std::string &key, T &value);

    bool remove(const std::string &key);

    bool put(const std::string &key, const T &value, T &evicted_value);

    virtual ~LRUCache() {
        delete map;
        auto ptr = head.next;
        while (ptr != nullptr) {
            auto next = ptr->next;
            delete ptr;
            ptr = next;
        }
    }
};

/*
 * removes the item with the given name as the key
 */
template<typename T>
bool LRUCache<T>::remove(const std::string &key) {
    T value_out;
    if (!get(key, value_out)) {
        return false;
    }

    // remove the node_to_delete from the linked list
    bool item_removed = false;
    auto ptr = &head;
    while (ptr->next != nullptr) {
        if (ptr->next->key == key) {
            auto node_to_delete = ptr->next;
            ptr->next = node_to_delete->next;
            delete node_to_delete;
            item_removed = true;
            map->remove(key);
            num_of_entry--;
        }
        ptr = ptr->next;
    }
    return item_removed;
}

template<typename T>
bool LRUCache<T>::put(const std::string &key, const T &value, T &evicted_value) {
    /*
     * update the value if key already exists
     */
    ListNode<T> *node;
    auto found = map->get(key, node);
    if (found) {
        node->value = value;
        return false;
    }

    /*
     * create a new node with the new key/value pair
     */
    num_of_entry++;
    auto *new_node = new ListNode<T>(key, value);
    new_node->next = head.next;
    head.next = new_node;

    map->put(key, new_node);

    if (num_of_entry > capacity) {
        // remove the last node
        auto p1 = &head;
        auto p2 = p1->next;

        // walk to the end of the list
        // h -> 1 -> 2 -> 3
        while (p2 != nullptr && p2->next != nullptr) {
            p1 = p2;
            p2 = p2->next;
        }

        map->remove(p2->key);
        evicted_value = p2->value;

        delete p2;
        num_of_entry--;
        p1->next = nullptr;

        return true;
    }

    return false;
}

/*
 * get finds and return the item based on name
 */
template<typename T>
bool LRUCache<T>::get(const std::string &key, T &result) {
    ListNode<T> *node;
    auto found = map->get(key, node);
    if (found) {
        result = node->value;
        return true;
    }
    return false;
}
