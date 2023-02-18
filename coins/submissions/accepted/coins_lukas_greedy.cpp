/* Solution to "Getting Rid of Coins" from KTH Challenge 2011
** Author: Lukas Polacek
*/
#include <iostream>
#include <vector>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

int v[] = {1, 5, 10, 25};
int greedy(int x[3], int price)
{
    if (price < 0) return -1;
    vector<int> use(3, 0);
    rep(i,0,3)
    {
        if (i < 2)
        {
            int fill = (price % v[i + 1]) / v[i];
            if (fill > x[i])
            {
                if (i == 1 && use[0] >= 5)
                {
                    use[0] -= 5;
                    price += 5;
                    fill = 0;
                }
                else return -1;
            }
            price -= fill * v[i];
            use[i] = fill;
            //now price % v[i + 1] == 0
        }

        int coef = i < 2 ? v[i + 1] / v[i] : 1;
        int fill = min(price / (coef * v[i]), (x[i] - use[i]) / coef) * coef;
        price -= fill * v[i];
        use[i] += fill;
    }
    if (price != 0) return -1;
    return use[0] + use[1] + use[2];
}
int main()
{
    int price, avail[4];
    cin >> price;
    rep(i,0,4) cin >> avail[i];

    int s10 = avail[0] + 5 * avail[1] + 10 * avail[2];
    s10 -= (s10 % 25 - price % 25 + 25) % 25;

    int res = -1;
    rep(k,0,2)
    {
        int trial = greedy(avail, s10 - k * 25);
        int new_price = price - s10 + k * 25;
        if (trial == -1 || new_price < 0 || new_price / 25 > avail[3])
            continue;
        res = max(res, new_price / 25 + trial);
    }
    if (res == -1)
        cout << "Impossible" << endl;
    else
        cout << res << endl;
}
