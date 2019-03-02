#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment
{
  int start, end;
};

bool segment_sorter(Segment const &lhs, Segment const &rhs)
{
  return lhs.start <= rhs.start;
}

vector<int> optimal_points(vector<Segment> segments, vector<int> points)
{
  if (segments.size() < 2)
  {
    if (segments.size() == 1)
    {
      points.push_back(segments[0].end);
    }

    return points;
  }

  Segment temp;
  vector<Segment> newSeg;
  int firstEnd, secondStart, secondEnd;

  for (size_t i = 0; i < segments.size(); i += 2)
  {
    if (i + 1 >= segments.size())
    {
      newSeg.push_back(segments[i]);
      continue;
    }

    firstEnd = segments[i].end;
    secondStart = segments[i + 1].start;
    secondEnd = segments[i + 1].end;

    // disjoint
    if (firstEnd < secondStart)
    {
      points.push_back(firstEnd);
      newSeg.push_back(segments[i + 1]);
    }
    else
    {
      temp.start = secondStart;
      // end of first segment less than end of second segment ?
      temp.end = min(firstEnd, secondEnd);
      newSeg.push_back(temp);
    }
  }

  // for (int i = 0; i < newSeg.size(); i++)
  // {
  //   cout << i << ": [" << newSeg[i].start << ", " << newSeg[i].end << "]" << endl;
  // }

  return optimal_points(newSeg, points);
}

vector<int> optimal_points(vector<Segment> segments)
{
  vector<int> points;

  sort(segments.begin(), segments.end(), &segment_sorter);

  return optimal_points(segments, points);
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
  vector<int> points = optimal_points(segments);
  cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i)
  {
    cout << points[i] << " ";
  }

  cout << endl;
}
