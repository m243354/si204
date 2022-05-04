#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getLen(char* s);

char** reverse(char** s);

int main() {
  int words;
  char* input;
  printf("%s\n", "Number of words: ");
  scanf("%d", &words);
  printf("%s\n", "Sentence: ");
  scanf("%s\n", input);
  printf("%s\n", input1);

  char** out = reverse(input);
  for(int i=0; i<words; i++) {
    printf("%s\n", out[i]);
  }
  return 0;
}

int getLen(char* s) {
  int len = 0;
  while(s[len] != '\0' && ++len);
  return len;
}

char* reverse(char* s) {
  int len = getLen(s);
  printf("%d\n", len);
  char* rev = (char*)malloc(sizeof(char)*(len+1));
  int c = 0;
  // for(int k=0; k<words; k++) {
  //   //find index of each words start and ending
  // }
  for(int i=len; i>=0; i--) {
    printf("%c\n", s[i]);
    rev[c++] = s[i];
  }
  rev[c] = '\0';
  return rev;
}
