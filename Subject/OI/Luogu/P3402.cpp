#include <iostream>

using std::endl, std::cout, std::cin;

int n;


void union_set(int a, int b)
{

}
short is_same_set(int a, int b)
{

}
void back_staus(int id)
{

}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int m, arg_1, arg_2;
  cin >> n >> m;
  short code;
  for(int i = 0; i < m; ++i)
  {
    cin >> code;
    switch(code)
    {
      case 1:
        cin >> arg_1 >> arg_2;
        union_set(arg_1, arg_2);
        break;
      case 2:
        cin >> arg_1;
        back_staus(arg_1);
        break;
      case 3:
        cin >> arg_1 >> arg_2;
        cout << is_same_set(arg_1, arg_2);
        break;
      default:
        break;
    }
  }

  return 0;
}