#include <iostream>

using namespace std;

int main() {
	int n;
	cout << "Enter the quantity of elements: ";
	cin >> n;

	int arr[n];

	for (int i = 0; i <= n - 1; i++) {
		cout << "Enter the element: ";
		cin >> arr[i];
		if (arr[i] < 0) {
			arr[i] *= -1;
		}
	}

	for (int i = 0; i <= n - 2; i++) {
		if (arr[i] != 0) {
			do {
				if (arr[i] < arr[i + 1]) {
					arr[i + 1] = arr[i + 1] % arr[i];
				} else {
					int temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
			} while (arr[i] != 0);
		}
	}

	cout << "GCD is " << arr[n - 1];
	cin.get();
}
