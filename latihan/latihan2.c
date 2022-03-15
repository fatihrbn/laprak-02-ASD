#include <stdio.h>
#include <string.h>
#define MAX 50

typedef int ItemType;
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
    printf("%d", temp);
  }
}

void decimalToBinary(Stack *S, ItemType n) {
  while (n != 0) {
    push(S, n%2);
    n /= 2;
  }
  printf("Binary : ");
  while (S->count > 0) {
    pop(S);
  }
}

void decimalToOctal(Stack *S, ItemType n) {
  while (n != 0) {
    push(S, n%8);
    n /= 8;
  }
  printf("Octal : ");
  while (S->count > 0) {
    pop(S);
  }
}

void decimalToHexadecimal(Stack *S, ItemType n) {
  int hexResult;
  char letter;
  while (n != 0) {
    hexResult = n%16;
    push(S, hexResult);
    n /= 16;

    switch(hexResult) {
      case 10:
        letter = 'A';
        break;
      case 11:
        letter = 'B';
        break;
      case 12:
        letter = 'C';
        break;
      case 13:
        letter = 'D';
        break;
      case 14:
        letter = 'E';
        break;
      case 15:
        letter = 'F';
        break;
    }
  }
  printf("Hexadecimal : ");
  while (S->count > 0) {
    if (hexResult < 10) {
      pop(S);
    } else {
      printf("%c", letter);
      break;
    }
  }
}

int main() {
  ItemType number = 123;
  Stack stack;
  initializeStack(&stack);
  printf("Decimal number: %d\n", number);
  decimalToBinary(&stack, number);
  printf("\n");
  decimalToOctal(&stack, number);
  printf("\n");
  decimalToHexadecimal(&stack, number);
  return 0;
}