#include "validator.h"


void run() {
    int N = Int(1, 1'000'000); Endl();
    int prev = 1'000'000;
    for (int i = 0; i < 2 * N; i++) {
        prev = Int(1, prev); Endl();
    }
}
