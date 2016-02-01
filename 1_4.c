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

void sort(char *str)
{
  int length = get_length(str);
  int i, j;

  for(i = 0; i < length-1; ++i) {
    for(j = i; j < length; ++j) {
      if(str[i] > str[j]) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
      }
    }
  }
}

int solve(char *str1, char *str2)
{
  int length1 = get_length(str1);
  int length2 = get_length(str2);
  if(length1 != length2) return 0;

  int i;
  for(i=0; i < length1; ++i) {
    if(str1[i] != str2[i]) return 0;
  }
  return 1;
}

int main(int argc, char const *argv[])
{
  char str1[255];
  char str2[255];

  scanf("%s", str1);
  scanf("%s", str2);

  sort(str1);
  sort(str2);

  int result = solve(str1, str2);

  printf("%d\n", result);
  return 0;
}
