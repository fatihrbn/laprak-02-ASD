#include <stdio.h>
#define MAX 50

typedef char ItemType;
typedef struct {
  ItemType item[MAX];
  int count;
} Stack;

void initializeStack(Stack *S) {
  S->count = 0;
}

int isEmpty(Stack *S) {
  return (S->count == 0);
}

int isFull(Stack *S) {
  return (S->count == MAX);
}

void push(Stack *S, ItemType x) {
  if (isFull(S)) {
    printf("Stack penuh, Data tidak dapat disimpan\n");
  } else {
    S->item[S->count] = x;
    S->count++;
  }
}

void pop(Stack *S) {
  ItemType temp;
  if (isEmpty(S)) {
    printf("Stack kosong, tidak dapat mengambil data\n");
  } else {
    S->count--;
    temp = S->item[S->count];
    printf("%c", temp);
  }
}

int main() {
  char word[] = {'E','A','S','*','Y','*','Q','U','E','*','*','*','S','T','*','*','*','I','O','*','N','*','*','*'};
  int wordLength = sizeof(word)/sizeof(*word);
  Stack stack;
  initializeStack(&stack);
  printf("Input:\n");
  for (int i = 0; i< wordLength; i++) {
    printf("%c ", word[i]);
  }
  printf("\n\n");
  printf("Output:\n");
  for (int i = 0; i < wordLength; i++) {
    if (word[i] == '*') {
      pop(&stack);
    } else {
      push(&stack, word[i]);
    }
  }
  return 0;
}
