#include <iostream>
#include <vector>
#include <map>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
  double value = 0.0;
  vector<float> densities;

  for (int i = 0; i < weights.size(); i++)
  {
    densities[i] = (float)values[i] / weights[i];
  }

  cout << densities << endl;

  return value;
}

int main()
{
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}
