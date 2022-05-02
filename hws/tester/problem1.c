#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* interleave(char* s1, char* s2);

int getLen(char* s);

int main() {
  char* s1 = "get";
  char* s2 = "ras";
  char* w = interleave(s1,s2);
  printf("%s\n",w);
  free(w);

  return 0;
}

int getLen(char* s) {
  int len = 0;
  while(s[len] != '\0' && ++len);
  return len;
}

char* interleave(char* s1, char* s2) {
  int total = getLen(s1) + getLen(s2);
  printf("%d\n", total);
  char* ans = (char*)malloc(sizeof(char)*(total+1));
  int c1=0, c3 = 0;
  for(int i=0; i<total/2; i++) {
    ans[c3++] = s1[c1];
    ans[c3++] = s2[c1++];
  }
  ans[total] = '\0';
  return ans;
}
