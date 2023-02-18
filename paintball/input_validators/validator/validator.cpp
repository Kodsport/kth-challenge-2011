#include "validator.h"


void run() {
    int N = Int(2, 1'000); Space();
    int M = Int(0, 5'000); Endl();
    set<pair<int, int>> seen;
    for (int i = 0; i < M; i++) {
        int A = Int(1, N); Space();
        int B = Int(A + 1, N); Endl();
        seen.emplace(A, B);
    }
    assert(seen.size() == M);
}
