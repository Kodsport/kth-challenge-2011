#include "validate.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
typedef vector<int> vi;

int main(int argc, char **argv) {
	init_io(argc, argv);

	int N, M;
	judge_in >> N >> M;

	set<pair<int, int>> eds;
	rep(i,0,M) {
		int a, b;
		judge_in >> a >> b;
		--a, --b;
        eds.emplace(a, b);
	}

	auto checkAns = [&](istream& is, feedback_function fail) -> bool {
        vector<int> sol;
        rep(i,0,N) {
            int ot;
            is >> ot;
            if (!is) {
                if (i == 0) {
                    is.clear();
                    string imp;
                    is >> imp;
                    if (is) {
                        for (char& c : imp) c = tolower(c);
                        if (imp == "impossible") {
                            return false;
                        } else {
                            fail("first line was non-int and not impossible: %s", imp.c_str());
                        }
                    } else {
                        fail("eof1");
                    }
                } else {
                    fail("eof2");
                }
            }
            if (ot < 1 || ot > N) fail("target out of range: %d vs %d", ot, N);
            sol.emplace_back(ot - 1);
        }
        if (set<int>(sol.begin(), sol.end()).size() != N) {
            fail("targets not unique");
        }
        rep(i,0,N) {
            int lo = min(i, sol[i]);
            int hi = max(i, sol[i]);
            if (!eds.count(make_pair(lo, hi))) fail("non-existent edge %d %d", i, sol[i]);
        }
		string trailing;
		if (is >> trailing) {
			fail("Trailing output");
		}
		return true;
	};

	bool judgeAns = checkAns(judge_ans, judge_error);
	bool userAns = checkAns(cin, wrong_answer);

	if (judgeAns && !userAns) {
		wrong_answer("judge had solution, user did not");
	}
	if (userAns && !judgeAns) {
		judge_error("user had solution, judge did not", userAns, judgeAns);
	}

	accept();
}
