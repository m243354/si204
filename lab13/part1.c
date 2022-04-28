#include <stdio.h>

int main() {
  int in, tot = 0, r = 1;
  char c;
  scanf("%d ", &tot);
  //total is now first number entered
  while(scanf("%c", &c) && r == 1) {
    //now I try to read in the next character. If it is anything not a plus or minus, equal sign, i exit.
    if(c == '+') {
      scanf("%d ", &in);
      tot += in;
    }
    else if(c == '-') {
      scanf("%d ", &in);
      tot -= in;
    } else  {
      r = 0;
    }
  }
  printf("%d\n", tot);
  return 0;
}
