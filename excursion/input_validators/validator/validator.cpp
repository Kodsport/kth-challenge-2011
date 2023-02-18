#include "validator.h"


void run() {
    string s = Line();
    assert(1 <= s.size() && s.size() <= 1'000'000);
    for (char c : s) {
        assert('0' <= c && c <= '2');
    }
}
