/* Sample solution to "Kindergarten Excursion" from KTH Challenge 2011.
 *
 * Author: Per Austrin
 */
#include <cctype>
#include <cstdio>
#include <cstring>

int main(void) {
  int x, y, freq[3] = {0, 0, 0};
  long long ans = 0;
  while (isdigit(x = getchar())) {
    ++freq[x-='0'];
    for (y = 2; y > x; --y) ans += freq[y];
  }
  printf("%lld\n", ans);
}
