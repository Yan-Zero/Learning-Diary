#include <iostream>
using std::cin, std::cout, std::endl;
using ll_ = long long;
#include <cmath>

ll_ L, R;

ll_ f(ll_ x)
{
  ll_ t = x >> 1;
  while(x > 1)
  {
    if(x % t == 0)
      return t;
    --x;
  }
  return 1;
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> L >> R;
  ll_ ans = 0, t;
  L = L > (R - 100) ? L : (R - 100);
  for(ll_ i = L; i <= R; ++i)
  {
    t = f(i);
    if(ans < t)
      ans = t;
  }
  cout << ans;
  return 0;
}
