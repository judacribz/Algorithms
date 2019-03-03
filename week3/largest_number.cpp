#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

bool largest_number_sorter(string const &strA, string const &strB)
{
	return stoi(strA + strB) > stoi(strB + strA);
}

vector<string> sort_fast(vector<string> a)
{
	vector<string> maxString;
	vector<string>::iterator
		it,
		maxIt;

	while (a.size() != 0)
	{
		maxIt = a.begin();
		for (it = maxIt + 1; it != a.end(); it++)
		{
			if (largest_number_sorter(*it, *maxIt))
			{
				maxIt = it;
			}
		}
		maxString.push_back(*maxIt);
		a.erase(maxIt);
	}

	return maxString;
}

string largest_number(vector<string> a)
{
	stringstream ret;

	// sort(a.begin(), a.end(), largest_number_sorter);
	a = sort_fast(a);

	for (size_t i = 0; i < a.size(); i++)
	{
		ret << a[i];
	}

	return ret.str();
}

int main()
{
	int n;
	cin >> n;
	vector<string> a(n);

	for (size_t i = 0; i < a.size(); i++)
	{
		cin >> a[i];
	}
	cout << largest_number(a);
}
