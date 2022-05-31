#include <cstdio>
#include "problem_1/catalan_number_solver.h"
#include "problem_3/sha256/sha256.h"

/*
 * This file is run through memory check.
 * However, any changes in this file will be ignored for grading, EXCEPT its memory leak
 * Meaning, if there's memory leak from this file, there will be points penalty
 */


void show_result(std::vector<std::string> &result) {
    for (std::vector<std::string>::iterator i = result.begin(); i != result.end(); ++i) {
        printf("%s\n", (*i).c_str());
    }
};

int main() {
    std::vector<std::string> result;
    CatalanNumberSolver::possible_parenthesis(6, result);
    show_result(result);

    SHA256 sha256;
    std::string myHash = sha256("Hello World");     // std::string
    printf("%s\n", myHash.c_str());
}