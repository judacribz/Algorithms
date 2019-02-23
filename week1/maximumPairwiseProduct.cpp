#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getMaxAndErase(vector<int> &numbers) {
	vector<int>::iterator maxIt = numbers.begin();
	for (vector<int>::iterator it = maxIt + 1; it != numbers.end(); it++) {
		if (*it >= *maxIt) {
			maxIt = it;
		}
	}

	int max = *maxIt;
	numbers.erase(maxIt);

	return max;
}

long long getMaxPairwiseProduct(vector<int> numbers) {
	return (long long)getMaxAndErase(numbers) * getMaxAndErase(numbers);
}

long long getMaxPairwiseProductSlow(vector<int> numbers) {
	int n = sizeof(numbers)/sizeof(numbers[0]);
	sort(numbers.begin(), numbers.end());  

	return (long long) *(numbers.end() - 1) * *(numbers.end() - 2);
}

int main() {
	int n;
	cin >> n;
	vector<int> numbers;
	bool stressTest = false;
	if (n < 2) {
		stressTest = true;
		n = rand() % 10 + 2;
		for (int i = 0; i < n; i++) {
			numbers.push_back(rand() % 1000);
		}
	} else {
		int temp;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			numbers.push_back(temp);
		}
	}

	long long prod1, prod2;
	if (stressTest) {
		while (stressTest) {
			prod1 = getMaxPairwiseProduct(numbers);
			prod2 = getMaxPairwiseProductSlow(numbers);

			cout << prod1 << " and " << prod2 << endl;
			if (prod1 != prod2) {
				stressTest = false;
			} else {
				numbers.clear();
				n = rand() % 10 + 2;
				for (int i = 0; i < n; i++) {
					numbers.push_back(rand() % 1000);
				}
			}
		}
	} else {
			prod1 = getMaxPairwiseProduct(numbers);

			cout << prod1 << endl;
	}

	return 0;
}