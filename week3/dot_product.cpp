#include <algorithm>
#include <iostream>
#include <vector>

#define LL long long

using namespace std;

long getMax(vector<long> &vec)
{
  vector<long>::iterator
      it = vec.begin(),
      maxit = it;

  long max = *it;
  it++;

  for (it; it != vec.end(); it++)
  {
    if (*it > max)
    {
      max = *it;
      maxit = it;
    }
  }

  vec.erase(maxit);
  // cout << vec.size() << endl;
  return max;
}

LL max_dot_product(vector<long> a, vector<long> b)
{
  // write your code here
  LL result = 0;
  while (a.size() != 0 || b.size() != 0)
  {
    result += getMax(a) * getMax(b);
  }

  return result;
}

int main()
{
  size_t n;
  cin >> n;
  vector<long> a(n), b(n);
  for (size_t i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  for (size_t i = 0; i < n; i++)
  {
    cin >> b[i];
  }
  cout << max_dot_product(a, b) << endl;
}
