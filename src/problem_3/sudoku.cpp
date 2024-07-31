#include <set>
#include "sudoku.h"

Sudoku::~Sudoku() {
    delete[] challenge;
}

bool Sudoku::solve() {
    return solve(0, 0);
}

bool Sudoku::solve(size_t row, size_t col) {
    // move to the next unknown to fill
    while (row < 9 && *challenge_board(row, col) != 0) {
        if (col == 8) {
            col = 0;
            row++;
        } else {
            col++;
        }
    }

    if (row == 9) {
        return true;
    }

    // find the number to fill in the current spot
    // after checking row, col, 3x3 square, and diag,
    // candidates has all the possible numbers for location (row, col)
    std::set<int> candidates;
    for (int i = 0; i < SUDOKU_BOARD_SIZE; i++) {
        candidates.insert(i + 1);
    }
    for (int i = 0; i < SUDOKU_BOARD_SIZE; i++) {
        // look for candidate in the row
        int val = *challenge_board(row, i);
        if (val != 0) {
            candidates.erase(val);
        }
        // look for candidate in the column
        val = *challenge_board(i, col);
        if (val != 0) {
            candidates.erase(val);
        }
    }

    // check for 3x3 square
    size_t square_start_row = (row / 3) * 3;
    size_t square_start_col = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int val = *challenge_board(square_start_row + i, square_start_col + j);
            if (val != 0) {
                candidates.erase(val);
            }
        }
    }

    if (candidates.empty()) {
        return false;
    }

    // fill in the number
    for (int candidate: candidates) {
        *challenge_board(row, col) = candidate;

        // move right or wrap down to the next number
        bool found_solution = solve(row, col);
        if (found_solution) {
            return true;
        }
        *challenge_board(row, col) = 0;
    }
    return false;
}