#include <iostream>
#include <vector>

#define LL long long

using namespace std;

LL compute_min_refills(LL dist, LL tank, vector<LL> &stops)
{
	LL
		totalFills = 0,
		lastStation = 0,
		lastStopped = 0;

	stops.push_back(dist);

	LL currDist;
	for (vector<LL>::iterator it = stops.begin(); it != stops.end(); it++)
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
			if (*it != dist)
			{
				lastStation = lastStopped = *it;
				totalFills++;
			}
		}
	}

	return totalFills;
}

int main()
{
	// distance to city
	LL d = 0;
	cin >> d;

	// full tank distance
	LL m = 0;
	cin >> m;

	// num gas stations on the way
	LL n = 0;
	cin >> n;

	vector<LL> stops(n);
	for (size_t i = 0; i < n; ++i)
	{
		cin >> stops.at(i);
	}

	cout << compute_min_refills(d, m, stops) << "\n";

	return 0;
}
