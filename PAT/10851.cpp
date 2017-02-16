#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	long long p;
	cin >> n >> p;
	if (n == 0) {
		cout << n;
		return 0;
	}
	long long int *a = new long long int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int result = 1;
	int temp = 1;
	for (int i = 0; i <= n - 2; i++) {
		for (int j = i + result; j <= n - 1; j++) {
			if (a[j] <= a[i] * p) {
				temp = j - i + 1;
				if (temp > result) {
					result = temp;
				}
			}
			else {
				break;
			}
		}
	}
	cout << result;

	return 0;
}