#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int dist, int tank, vector<long> &stops)
{
	long
		totalFills = 0,
		lastStation = 0,
		lastStopped = 0;

	stops.push_back(dist);

	long currDist;
	for (vector<long>::iterator it = stops.begin(); it != stops.end(); it++)
	{
		currDist = *it - lastStopped;

		// Tank less than gas stop distance
		if (tank < currDist)
		{
			if (lastStation == lastStopped)
			{
				return -1;
			}

			lastStopped = lastStation;
			currDist = *it - lastStopped;
			totalFills++;
		}

		// Tank greater than gas stop distance
		if (tank > currDist)
		{
			lastStation = *it;
		}
		// Tank equal to gas stop distance
		else if (tank == currDist)
		{
			lastStation = lastStopped = *it;
			totalFills++;
		}
	}
	return totalFills;
}

int main()
{
	// distance to city
	long d = 0;
	cin >> d;

	// full tank distance
	int m = 0;
	cin >> m;

	// num gas stations on the way
	int n = 0;
	cin >> n;

	vector<long> stops(n);
	for (size_t i = 0; i < n; ++i)
	{
		cin >> stops.at(i);
	}

	cout << compute_min_refills(d, m, stops) << "\n";

	return 0;
}
