#include <stdio.h>

int global = 0;

void myPrint(int param) {
  if (param == 1)
    printf("param is 1");
  for (int i = 0 ; i < 10 ; i++ ) {
    global += i;
  }
}

int main(int argc, char *argv[]) {
  int param = 1;
  myPrint(param);
  return 0;
}
