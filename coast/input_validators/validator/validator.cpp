#include "validator.h"


void run() {
    int N = Int(1, 1'000); Space();
    int M = Int(1, 1'000); Endl();
    for (int i = 0; i < N; i++) {
        string L = Line();
        assert(L.size() == M);
        for (char c : L) {
            assert(c == '0' || c == '1');
        }
    }
}
