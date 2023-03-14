#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STACK_SIZE 100

char stack[STACK_SIZE];
int top = -1;

void push(char c) {
  if (top < STACK_SIZE - 1) {
    stack[++top] = c;
  }
}

char pop() {
  if (top >= 0) {
    return stack[top--];
  }
  return '\0';
}

void print_string(char *s) {
  int i;
  for (i = 0; i < strlen(s); i++) {
    push(s[i]);
  }
  printf("Original string: %s\n", s);
  printf("Reversed string: ");
  while (top >= 0) {
    printf("%c", pop());
  }
  printf("\n");
}

bool is_palindrome(char *s) {
  int i, j;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    if (s[i] != s[j]) {
      return false;
    }
  }
  return true;
}

int main() {
  char s[100];
  printf("Enter a string: ");
  scanf("%s", s);
  print_string(s);
  if (is_palindrome(s)) {
    printf("The string is a palindrome.\n");
  } else {
    printf("The string is not a palindrome.\n");
  }
  return 0;
}

