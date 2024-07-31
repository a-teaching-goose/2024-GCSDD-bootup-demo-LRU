#pragma once

#include "util.h"

class Book {
private:
    std::string name;
    std::string isbn;
    int published_year;

    friend class Floor;

    friend class Library;

public:
    Book() = default;

    Book(const std::string &name,
         const std::string &isbn,
         int publishedYear) : name(name), isbn(isbn),
                              published_year(publishedYear) {}

    const std::string &get_name() const {
        return name;
    }
};

