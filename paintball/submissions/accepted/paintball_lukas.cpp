/* Solution to "Paintball" from KTH Challenge 2011
** Author: Lukas Polacek
*/
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#define rep(i,a,n) for(__typeof(n) i=a; i<(n); ++i)

vector<int> par;
vector<bool> bol;
bool find(int j, vector<vector<int> > &g) {
    if (par[j] == -1) return true;
    bol[j] = true; int di = par[j];
    rep(i,0,g[di].size())
    {
        int u = g[di][i];
        if (!bol[u] && find(u, g))
        {
            par[u] = di;
            par[j] = -1;
            return true;
        }
    }
    return false;
}
int match(vector<vector<int> > g, int n, int m)
{
    par.assign(m, -1);
    rep(i,0,n)
    {
        bol.assign(m, false);
        rep(j,0,g[i].size())
            if (find(g[i][j], g))
            {
                par[g[i][j]] = i;
                break;
            }
    }
    return m - count(par.begin(), par.end(), -1);
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<int> > g(n);
    rep(i,0,m)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt = match(g, n, n);
    if (cnt < n)
        printf("Impossible\n");
    else
        rep(i,0,n)
            printf("%d\n", par[i] + 1);
}
