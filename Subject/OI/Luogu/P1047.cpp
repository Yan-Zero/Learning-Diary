#include <iostream>
#include <bitset> 

using namespace std;

bitset<15000> trees;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  int l, r;
  cin >> n >> m;
  trees.flip();

  for(; m > 0; --m)
  {
    cin >> l >> r;
    for(int i = l; i <= r; ++i)
      trees.set(i, 0);
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i)
    if(trees[i])
      ++ans;
  cout << ans << endl;

  return 0;
}