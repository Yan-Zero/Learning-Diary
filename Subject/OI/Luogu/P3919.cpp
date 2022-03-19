#include <iostream>
using std::cin, std::cout, std::endl;

int n, m, top = -1, root[1000008];

struct Node
{
  int left, right, val;
} tree[100002000];

inline int clone(int index)
{
  ++top;
  tree[top] = tree[index];
  return top;
}

int build_tree(int l, int r)
{
  int node =++top;
  if(l == r)
  {
    tree[node].left = tree[node].right = -1;
    tree[node].val = root[l];
  }
  else
  {
    tree[node].val = (l + r) >> 1;
    tree[node].left = build_tree(l, tree[node].val);
    tree[node].right = build_tree(tree[node].val + 1, r);
  }
  return node;
}

int update_value(int node, int index, int value)
{
  node = clone(node);
  if(tree[node].left == -1)
    tree[node].val = value;
  else
  {
    if(index <= tree[node].val)
      tree[node].left = update_value(tree[node].left, index, value);
    else
      tree[node].right = update_value(tree[node].right, index, value);
  }
  return node;
}

int query(int node, int index)
{
  while(tree[node].left != -1)
    if(index <= tree[node].val)
      node = tree[node].left;
    else
      node = tree[node].right;
  return tree[node].val;
}

int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int mode, now = 0, ver, loc, val;

  cin >> n >> m;
  for(int i = 0; i < n; ++i)
    cin >> root[i];
  root[0] = build_tree(0, n - 1);

  for(int i = 0; i < m; ++i)
  {
    cin >> ver >> mode >> loc;
    switch(mode)
    {
      case 1:
        cin >> val;
        root[++now] = update_value(root[ver], --loc, val);
        break;
      case 2:
        cout << query(root[ver], --loc) << endl;
        root[++now] = root[ver];
        break;
      default:
        break;
    }
  }

  return 0;
}
