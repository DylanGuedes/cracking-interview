#include <stdio.h>

int get_length(char *mystr)
{
  if(mystr == NULL) return 0;

  int counter = 1;

  while(*mystr != '\0') {
    counter++;
    mystr++;
  }
  return counter;
}

void solve(char *mystr)
{
  int length = get_length(mystr);

  int i, j;
  int bound = 1;

  for(i=1; i < length; ++i) {
    for(j=0; j < bound; ++j) {
      if(mystr[i] == mystr[j]) break;
    }

    if(j == bound) {
      mystr[j] = mystr[i];
      ++bound;
    }
  }

  mystr[bound] = '\0';
}

int main(int argc, char const *argv[])
{
  char mystr[255];
  scanf("%s", mystr);

  solve(mystr);
  printf("%s\n", mystr);
  return 0;
}
