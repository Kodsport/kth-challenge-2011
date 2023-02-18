/* Solution to "Getting Rid of Coins" from KTH Challenge 2011
** Author: Ulf Lundström
*/
#include <iostream>
using namespace std;

int main() {
    int P, N1, N5, N10, N25;
    cin >> P >> N1 >> N5 >> N10 >> N25;
    int best = -1;
    for (int i = 0; i < 25; ++i) {
        int n1 = min(N1,P)-i;
        if (n1 < 0) break;
        int Q = P-n1;
        for (int j = 0; j < 10; ++j) {
            int n5 = min(N5,Q/5)-j;
            if (n5 < 0) break;
            int R = Q-5*n5;
            for (int k = 0; k < 5; ++k) {
                int n10 = min(N10,R/10)-k;
                if (n10 < 0) break;
                int S = R-10*n10;
                if (S%25==0 && S/25 <= N25)
                    best = max(best, n1+n5+n10+S/25);
            }
        }
    }
    if (best == -1)
        cout << "Impossible" << endl;
    else
        cout << best << endl;
}
