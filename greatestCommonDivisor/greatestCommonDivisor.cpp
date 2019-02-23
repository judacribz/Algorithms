#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long

ll remainder(ll a, ll b) {
	return a % b;
}

ll gcd(ll a, ll b) {
	return (b == 0) ? a : gcd(b, a % b);
}

int main() {
	int 
		a, 
		b;

	cin >> a;
	cin >> b;

	cout << gcd(a, b) << endl;

	return 0;
}