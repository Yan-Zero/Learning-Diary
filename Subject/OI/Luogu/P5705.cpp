#include <iostream>
#include <algorithm>

using namespace std;
string str;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> str;
  reverse(str.begin(), str.end());
  cout << str;

  return 0;
}