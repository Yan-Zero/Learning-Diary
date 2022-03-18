#include <iostream>

using namespace std;

int student[2500000];
int quest[150000];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m, t;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> student[i];
  for (int i = 1; i <= m; ++i)
    cin >> quest[i];
  for (int i = 1; i <= m; ++i)
    cout << student[quest[i]] << endl;

  return 0;
}