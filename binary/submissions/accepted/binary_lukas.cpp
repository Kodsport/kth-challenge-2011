/* Solution to "Reversed Binary Numbers" from KTH Challenge 2011
** Author: Lukas Polacek
*/
#include <iostream>
#include <bitset>
using namespace std;

#define rep(i,a,b) for(__typeof(b) i=a; i<(b); ++i)

int main()
{
    int n;
    cin >> n;
    bitset<31> b(n), c;
    int ma = 0;
    rep(i,0,31) if (b[i])
        ma = i;
    rep(i,0,ma+1)
        c[i] = b[ma - i];
    cout << c.to_ulong() << endl;
}
