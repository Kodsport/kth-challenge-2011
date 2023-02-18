/* Solution to "Kindergarten Excursion" from KTH Challenge 2011
** Author: Ulf Lundström
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    char s[1000010];
    scanf("%s", s);
    int n[3] = {0,0,0}, N;
    N = strlen(s);
    for (int i = 0; i < N; ++i)
        ++n[s[i] - '0'];
    int p[3] = {0,n[0],n[0]+n[1]};
    long long res = 0;
    for (int i = 0; i < N; ++i) {
        if (s[i] > '0') {
            res += p[s[i] - '0']++ - i;
            ++p[s[i] - '1'];
        }
    }
    printf("%lld\n",res);
}
