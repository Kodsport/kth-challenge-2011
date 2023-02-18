/* Solution to "Reversed Binary Numbers" from KTH Challenge 2011
** Author: Per Austrin
*/
#include <cstdio>

int rev(int n) {
  int m = 0, h = 0;
  for (int i = 30; i >= 0; --i)
    if (n & (1<<i)) {
      if (!h) h = i;
      m |= 1<<h-i;
    }
  return m;
}

int main(void) {
  int n;
  scanf("%d", &n);
  printf("%d\n", rev(n));
  return 0;
}
