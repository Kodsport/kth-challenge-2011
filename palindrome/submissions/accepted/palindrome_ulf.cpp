/* Solution to "Base-2 Palindrome" from KTH Challenge 2011
** Author: Ulf Lundström
*/
#include <iostream>
using namespace std;

int main() {
    int M;
    cin >> M;
    M -= 1;
    for (int i = 1;;++i) {
        int n = 1<<((i-1)/2);
        if (M>=n)
            M -= n;
        else {
            int res = M + (1<<((i-1)/2));
            M /= 1+(i%2);
            for (int j = i%2; j < (i-1)/2; ++j) {
                res = res*2 + M%2;
                M /= 2;
            }
            if (i>1)
                res = res*2 + 1;
            cout << res << endl;
            break;
        }
    }
}
