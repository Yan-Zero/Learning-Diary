#include <iostream>
using std::cin, std::cout, std::endl;
#define max(x, y) (x)>(y)?(x):(y)
#define MAX 1000004

int lose[MAX], win[MAX], dp[MAX], n, x;
short use[MAX];

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> x;
  for(int i = 1; i <= n; ++i)
    cin >> lose[i] >> win[i] >> use[i];
  
  for(int i = 1; i <= n; ++i)
  {
    for(int j = x; j >= use[i]; --j)
      dp[j] = max(dp[j] + lose[i], dp[j-use[i]] + win[i]);
    for(int j = use[i]-1;j>=0;j--)
      dp[j] += lose[i];
  }

  cout << dp[x] * 5ll;
}