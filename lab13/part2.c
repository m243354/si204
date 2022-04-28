#include <stdio.h>

int main() {
  printf("enter string (no spaces): ");
  int STRMAX = 20, pally = 1;
  char word[STRMAX];
  char rev[STRMAX];
  scanf("%s",   word);
  int k = 0;
  //delete all of this. Start two counters one at the char befroe the null
  //and 


  for(int i=STRMAX; i>=0; i--) {
    rev[k] = word[i];
    k++;
  }
  for(int i=0; i<STRMAX; i--) {
    printf("%s\n", rev);
    if(rev[i] != word[i]) {
      pally=0;
      break;
    }
  }
  if(pally == 1) {
    printf("palindrome\n");
  } else {
    printf("not palindrome\n");
  }

  printf("%s %s\n", word, rev);
  return 0;
}
