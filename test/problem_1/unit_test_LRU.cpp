/*
 * DO NOT MAKE ANY CHANGES
 */

#include "gtest/gtest.h"
#include "problem_1/LRU.hpp"

TEST(problem_1, LRU) {
    LRUCache<int> lru(5);

    int evicted_value;

    lru.put("a", 1, evicted_value);
    lru.put("b", 2, evicted_value);
    lru.put("c", 3, evicted_value);
    lru.put("d", 4, evicted_value);
    lru.put("e", 5, evicted_value);

    // e->d->c->b->a

    lru.put("f", 6, evicted_value);

    // f->e->d->c->b

    int val;
    bool found = lru.get("a", val);

    found = lru.get("f", val);

    found = lru.get("b", val);

    lru.remove("c");
    // f->e->d->b

    found = lru.get("c", val);

    lru.put("x", 55, evicted_value);

    // x->f->e->d->b

    lru.put("y", 31, evicted_value);

    // y->x->f->e->d
    found = lru.get("x", val);

    found = lru.get("y", val);

    found = lru.get("b", val);
}