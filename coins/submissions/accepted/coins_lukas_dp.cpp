/* Solution to "Getting Rid of Coins" from KTH Challenge 2011
** Author: Lukas Polacek
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

int v[] = {1, 5, 10, 25};
typedef vector<int> vi;
int main()
{
    int price, avail[4];
    cin >> price;
    rep(i,0,4) cin >> avail[i];
    vi ma(price / 5 + 1, -1);
    ma[0] = 0;
    rep(j,1,4)
    {
        vi cnt(ma.size(), 0);
        int upper = (int)ma.size() - v[j] / 5;
        rep(i,0,upper) if (ma[i] >= 0 && cnt[i] < avail[j])
            if (ma[i + v[j] / 5] == -1)
            {
                ma[i + v[j] / 5] = ma[i] + 1;
                cnt[i + v[j] / 5] = cnt[i] + 1;
            }
    }

    int res = -1;
    for (int i = 0; i * 5 <= price; i++)
        if (ma[i] >= 0 && price - i * 5 <= avail[0])
            res = max(res, ma[i] + price - i * 5);

    if (res == -1)
        cout << "Impossible" << endl;
    else
        cout << res << endl;
}
