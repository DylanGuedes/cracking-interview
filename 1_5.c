#include <stdio.h>

int get_length(char *str)
{
  if(str == NULL) return 0;
  int counter = 0;

  while(*str != '\0') {
    counter++;
    str++;
  }

  return counter;
}

void solve(char *str)
{
  int length = get_length(str);
  int i;
  int counter = 0;

  for(i=0; i < length; ++i) {
    if(str[i] == ' ')
      counter++;
  }

  int new_length = length + 2*counter;
  str[new_length] = '\0';
  for(i=length-1; i >= 0; i--) {
    if(str[i] == ' ') {
      str[new_length-1] = '0';
      str[new_length-2] = '2';
      str[new_length-3] = '%';
      new_length -= 3;
    } else {
      str[new_length-1] = str[i];
      new_length--;
    }
  }

}

int main(int argc, char const *argv[])
{
  char str[255];

  fgets(str, 255, stdin);

  solve(str);

  printf("%s\n", str);

  return 0;
}
