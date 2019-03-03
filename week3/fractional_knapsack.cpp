#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

int getGreatestDensity(map<int, double> densities)
{
  double max = -1;
  int i = -1;
  map<int, double>::iterator it = densities.begin();

  for (it; it != densities.end(); it++)
  {
    if (it->second > max)
    {
      max = it->second;
      i = it->first;
    }
  }

  return i;
}

double get_optimal_value(long capacity, vector<long> weights, vector<long> values)
{
  double totalValue = 0.0;
  map<int, double> densities;

  for (int i = 0; i < weights.size(); i++)
  {
    densities[i] = (double)values[i] / weights[i];
  }

  int
      index = -1,
      weight,
      value;

  while (capacity != 0 && densities.size() != 0)
  {
    //nlogn, gets max and then entry removed from map
    index = getGreatestDensity(densities);

    weight = weights[index];
    value = values[index];

    if (weight <= capacity)
    {
      capacity -= weight;
      totalValue += value;
    }
    else
    {
      totalValue += capacity * densities[index];
      capacity = 0;
    }

    densities.erase(index);
  }

  return totalValue;
}

int main()
{
  int n;
  long capacity;
  cin >> n >> capacity;
  vector<long> values(n);
  vector<long> weights(n);
  for (int i = 0; i < n; i++)
  {
    cin >> values[i] >> weights[i];
  }
  cout.precision(10);
  cout << round(get_optimal_value(capacity, weights, values) * 10000.0) / 10000.0 << endl;
  return 0;
}
