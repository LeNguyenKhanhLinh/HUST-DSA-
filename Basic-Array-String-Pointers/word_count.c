/*
Given a Text, write a prorgam to count the number Q of words (ignore characters SPACE, TAB, LineBreak) of this Text

Input
The Text

Output
Write the number Q of words

Example
Input
Hanoi University Of Science and Technology
School of Information and Communication Technology


Output
12
*/
#include <stdio.h>

#include <string.h>

#include <ctype.h>

int main() {
  char s[100000];
  int count = 0;
  while (fgets(s, sizeof(s), stdin)) {
    int i = 0;
    int flag = 1;
    while (s[i]) {
      if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') {
        flag = 1;
      } else {
        if (flag == 1) {
          count++;
          flag=0;
        }
      }
      i = i + 1;
    }

  }
  printf("%d", count);
}

