/* Solution to "Base-2 Palindrome" from KTH Challenge 2011
** Author: Per Austrin
*/
#include <cstdio>

int rev(int n, int h) {
  int m = 0;
  for (int i = 30; i >= 0; --i)
    if (n & (1<<i)) m |= 1<<h-i;
  return m;
}

int main(void) {
  int M, h = 0;
  scanf("%d", &M);
  --M;
  while ((1<<(h/2)) <= M) M -= 1<<(h/2), ++h;
  int X = (1<<h) | (M<<((h+1)/2)) | (rev(M, h/2-1)<<1) | 1;
  printf("%d\n", X);
  return 0;
}
