#include "catalan_number_solver.h"

void CatalanNumberSolver::possible_parenthesis(size_t n, std::vector<std::string> &result) {
    /*
     * TODO: homework
     */
}

size_t CatalanNumberSolver::catalan_number(size_t n) {
    if (n < 2) {
        return 1;
    }
    size_t numerator = 1, denominator = 1;

    for (size_t k = 2; k <= n; k++) {
        numerator *= (n + k);
        denominator *= k;
    }

    return numerator / denominator;
}
