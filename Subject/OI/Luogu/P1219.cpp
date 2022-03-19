#include <iostream>
#include <bitset>
using namespace std;

int n, total, rows[13], x;
bitset<26> rslash, lslash;
bitset<13> cols;

void queen(int i)
{
  if(i > n)
  {
    if(total < 3)
    {
      for(int j = 0; j < n; ++j)
        cout << rows[j] << " ";
      cout << endl;
    }
    ++total;
    return;
  }

  for(int j = 0; j < n; ++j)
  {
    if((!cols[j]) && (!rslash[i+j]) && (!lslash[i-j+n]))
    {
      rows[i-1] = j+1;
      cols[j] = rslash[i+j] = lslash[i-j+n] = 1;
      queen(i+1);
      cols[j] = rslash[i+j] = lslash[i-j+n] = 0;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  queen(1);
  cout << total << endl;

  return 0;
}