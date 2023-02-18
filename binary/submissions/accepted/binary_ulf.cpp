/* Solution to "Reversed Binary Numbers" from KTH Challenge 2011
** Author: Ulf Lundström
*/
#include <iostream>
using namespace std;

int main() {
    int N, M = 0;
    cin >> N;
    while (N) {
        M = M*2+N%2;
        N /= 2;
    }
    cout << M << endl;
}
