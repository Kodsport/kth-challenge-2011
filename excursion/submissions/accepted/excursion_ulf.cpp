/* Solution to "Kindergarten Excursion" from KTH Challenge 2011
** Author: Ulf Lundström
*/
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

int main() {
    char s[1000010];
    scanf("%s", s);
    int n[3] = {0,0,0}, N;
    N = strlen(s);
    for (int i = 0; i < N; ++i)
        ++n[s[i] - '0'];
    int p[3] = {0,n[0],n[0]+n[1]};
    ll res = 0;
    for (int i = 0; i < N; ++i) {
        if (s[i] > '0') {
            res += max(p[s[i]-'0']-i,0);
            ++p[s[i]-'0'];
            ++p[s[i]-'1'];
        }
    }
    cout << res << endl;
}
