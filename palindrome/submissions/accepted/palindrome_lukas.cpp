/* Solution to "Base-2 Palindrome" from KTH Challenge 2011
** Author: Lukas Polacek
*/
#include <iostream>
#include <bitset>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

typedef long long ll;
int main()
{
    int n; cin >> n;
    n--;
    rep(l,1,32)
    {
        int len = (l + 1) / 2 - 1;
        int cnt = 1 << len;
        if (n < cnt)
        {
            bitset<32> b((n + cnt) << (l - 1 - len));
            rep(i,0,len+1)
                b[i] = b[l - 1 - i];

            cout << b.to_ulong() << endl;
            break;
        }
        else n -= cnt;
    }
}
