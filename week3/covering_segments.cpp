#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

#define LL long long

using namespace std;

struct Segment
{
	LL start, end;
};

bool segment_sorter(Segment const &lhs, Segment const &rhs)
{

	return lhs.start <= rhs.start;
}

vector<LL> optimal_points(vector<Segment> segments, vector<LL> points)
{
	LL firstStart, firstEnd, secondStart, secondEnd;
	vector<Segment>::iterator first = segments.begin();

	for (vector<Segment>::iterator second = first + 1; second != segments.end(); second++)
	{
		if (first->end < second->start)
		{
			points.push_back(first->end);
			first = second;
		}
		else
		{
			first->start = second->start;
			first->end = min(first->end, second->end);
		}

		if (second == segments.end() - 1)
		{

			points.push_back(first->end);
		}
	}

	return points;
}

vector<LL> optimal_points(vector<Segment> segments)
{
	vector<LL> points;

	sort(segments.begin(), segments.end(), &segment_sorter);

	points = optimal_points(segments, points);
	sort(points.begin(), points.end());

	return points;
}

int main()
{
	int n;
	cin >> n;
	vector<Segment> segments(n);
	for (size_t i = 0; i < segments.size(); ++i)
	{
		cin >> segments[i].start >> segments[i].end;
	}
	vector<LL> points = optimal_points(segments);

	cout << points.size() << "\n";
	for (size_t i = 0; i < points.size(); ++i)
	{
		cout << points[i] << " ";
	}

	cout << endl;
}
