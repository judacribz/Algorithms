#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int dist, int tank, vector<long> &stops)
{
    long
        totalFills = 0,
        lastStation = 0,
        lastStopped = 0;

    for (vector<long>::iterator it = stops.begin(); it != stops.end(); it++)
    {
        if (tank > *it - lastStopped)
        {
            lastStation = *it;
            continue;
        }
        else
        {
            if (lastStation == lastStopped)
            {
                return -1;
            }
            else
            {
                totalFills++;
                lastStopped = lastStation;
            }
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

    stops.push_back(d);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
