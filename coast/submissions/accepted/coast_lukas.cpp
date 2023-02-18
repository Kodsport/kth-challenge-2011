/* Solution to "Coast Length" from KTH Challenge 2011
** Author: Lukas Polacek
*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstdio>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef pair<int, int> pii;
typedef vector<int> vi;
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    char c[n + 2][m + 2];
    rep(i,0,n+2) rep(j,0,m+2)
        c[i][j] = '0';
    char w[m + 2];
    rep(i,0,n)
    {
        scanf("%s", w);
        rep(j,0,m)
            c[i + 1][j + 1] = w[j];
    }

    queue<pii> q;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    c[0][0] = '#';
    int res = 0;
    for (q.push(pii(0, 0)); !q.empty(); q.pop())
    {
        pii u = q.front();
        rep(k,0,4)
        {
            int s = u.first + dx[k], t = u.second + dy[k];
            if (s < 0 || s >= n + 2 || t < 0 || t >= m + 2)
                continue;
            res += c[s][t] == '1';
            if (c[s][t] != '0')
                continue;
            c[s][t] = '#';
            q.push(pii(s, t));
        }
    }

    cout << res << endl;
}
