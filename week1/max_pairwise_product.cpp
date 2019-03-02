#include <iostream>
#include <algorithm>
#include <vector>

#define LL long long

using namespace std;

LL getMaxAndErase(vector<LL> &numbers)
{
	vector<LL>::iterator maxIt = numbers.begin();
	for (vector<LL>::iterator it = maxIt + 1; it != numbers.end(); it++)
	{
		if (*it >= *maxIt)
		{
			maxIt = it;
		}
	}

	LL max = *maxIt;
	numbers.erase(maxIt);

	return max;
}

LL getMaxPairwiseProduct(vector<LL> numbers)
{
	return getMaxAndErase(numbers) * getMaxAndErase(numbers);
}

LL getMaxPairwiseProductSlow(vector<LL> numbers)
{
	sort(numbers.begin(), numbers.end());

	return *(numbers.end() - 1) * *(numbers.end() - 2);
}

int main()
{
	LL n;
	cin >> n;
	vector<LL> numbers;
	bool stressTest = false;
	if (n < 2)
	{
		stressTest = true;
		n = rand() % 10 + 2;
		for (int i = 0; i < n; i++)
		{
			numbers.push_back(rand() % 1000);
		}
	}
	else
	{
		int temp;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			numbers.push_back(temp);
		}
	}

	LL prod1, prod2;
	if (stressTest)
	{
		while (stressTest)
		{
			prod1 = getMaxPairwiseProduct(numbers);
			prod2 = getMaxPairwiseProductSlow(numbers);

			cout << prod1 << " and " << prod2 << endl;
			if (prod1 != prod2)
			{
				stressTest = false;
			}
			else
			{
				numbers.clear();
				n = rand() % 10 + 2;
				for (int i = 0; i < n; i++)
				{
					numbers.push_back(rand() % 1000);
				}
			}
		}
	}
	else
	{
		prod1 = getMaxPairwiseProduct(numbers);

		cout << prod1 << endl;
	}

	return 0;
}
