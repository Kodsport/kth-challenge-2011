/* Sample solution to "Paintball" from KTH Challenge 2011.
 *
 * Author: Per Austrin
 */
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi adj[2000];
int vis[2000];
int mate[2000];

bool aug(int i) {
  vis[i] = true;
  for (vi::iterator it = adj[i].begin(); it != adj[i].end(); ++it)
    if (!mate[*it] || !vis[mate[*it]] && aug(mate[*it])) {
      mate[*it] = i;
      return true;
    } 
  return false;
}

int main(void) {
  int N, M, X;
  scanf("%d%d", &N, &M);
  for (int i = 0;i < M; ++i) { 
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  memset(mate, 0, sizeof(mate));
  for (X = 1; X <= N; ++X) {
    memset(vis, 0, sizeof(vis));
    if (!aug(X)) break;
  }
  if (X <= N) printf("Impossible\n");
  else
    for (int i = 1; i <= N; ++i)
      printf("%d\n", mate[i]);
  return 0;
}
