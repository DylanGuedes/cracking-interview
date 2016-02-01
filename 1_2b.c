#include <stdio.h>

void solution(char *mystr)
{
  char *tmp = mystr;
  char aux;

  while(*tmp != '\0') {
    ++tmp;
  }

  --tmp;

  while(tmp > mystr) {
    aux = *tmp;
    *tmp = *mystr;
    *mystr = aux;

    tmp--;
    mystr++;
  }

}

int main(int argc, char const *argv[])
{
  char mystr[255];
  scanf("%s", mystr);

  solution(mystr);

  char *tmp = mystr;
  while(*tmp != '\0') {
    printf("%c", *tmp);
    ++tmp;
  }

  printf("\n");
  return 0;
}
