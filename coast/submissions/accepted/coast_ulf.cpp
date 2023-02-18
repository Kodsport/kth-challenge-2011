/* Solution to "Coast Length" from KTH Challenge 2011
** Author: Ulf Lundström
*/
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,int> pii;

int main() {
    int N,M;
    char A[1001][1001];
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    int sum = 0;
    queue<pii> q;
    for (int i = 0; i < M; ++i) {
        q.push(pii(0,i));
        q.push(pii(N-1,i));
    }
    for (int i = 0; i < N; ++i) {
        q.push(pii(i,0));
        q.push(pii(i,M-1));
    }
    while (!q.empty()) {
        pii p = q.front();
        q.pop();
        if (p.first<0 || p.second<0 || p.first>=N || p.second>=M)
            continue;
        if (A[p.first][p.second] == '1')
            ++sum;
        else if (A[p.first][p.second] == '0') {
            A[p.first][p.second] = '2';
            q.push(pii(p.first+1,p.second));
            q.push(pii(p.first-1,p.second));
            q.push(pii(p.first,p.second+1));
            q.push(pii(p.first,p.second-1));
        }
    }
    cout << sum << endl;
}
