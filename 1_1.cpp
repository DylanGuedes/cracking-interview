#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

bool solve(string to_test)
{
  bool letters[258];
  memset(letters, false, sizeof letters);
  int length = to_test.size();

  for(int i=0; i < length; ++i) {
    int element = (int)to_test[i];
    if(letters[element] == true) {
      return false;
    } else {
      letters[element] = true;
    }
  }

  return true;
}

int main(int argc, char const *argv[])
{
  string mystring = "Hello world!";
  string otherstring = "abcdefghijklmn";

  bool sol1 = solve(mystring);
  bool sol2 = solve(otherstring);

  cout << sol1 << endl;
  cout << sol2 << endl;
  return 0;
}
