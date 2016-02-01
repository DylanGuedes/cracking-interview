#include <iostream>

using namespace std;

string solve(string mystr)
{
  string response;
  int length = mystr.size();

  for(int i=length-1; i >= 0; --i) {
    response.push_back(mystr[i]);
  }

  return response;
}

int main(int argc, char const *argv[])
{
  string mystr;
  cin >> mystr;
  cout << solve(mystr) << endl;
  return 0;
}
