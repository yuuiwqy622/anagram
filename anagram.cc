#include <cstdio>
#include <set>
#include <stdio.h>

int cnt, wcnt, idx;
std::multiset<char> letters;
char word[11];

void print_w() {
  if (idx == cnt) {
    printf("%s\n", word);
    ++wcnt, --idx;
    return;
  }

  char clet = 'a' - 1;
  while (true) {
    auto it = letters.upper_bound(clet);
    if (it == letters.end())
      break;
    clet = *it;
    word[idx++] = clet;
    letters.erase(it);
    print_w();
    letters.insert(clet);
  }

  --idx;
}

int main(void) {
  while (true) {
    wcnt = idx = 0, letters = {};
    scanf("%d\n", &cnt);
    if (!cnt)
      return 0;

    word[cnt] = 0;
    while (true) {
      int l = getchar();
      if (l == '\n')
        break;
      letters.insert(l);
    }

    print_w();
    printf("%d\n", wcnt);
  }
  return 0;
}