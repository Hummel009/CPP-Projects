#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

int main() {
	int n;
	cout << "Enter the quantity of elements: ";
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++) {
		cout << "Enter the element: ";
		cin >> arr[i];
	}

	unordered_set<int> nums;

	for (int i = 0; i < n; i++) {
		nums.insert(arr[i]);
	}

	cout << "Unique elements:";
	for (int i: nums) {
		cout << " " << i;
	}
	cout << ";\nThe quantity of unique elements: " << nums.size() << "\n";

	int max = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i] == arr[j] && i != j) {
				max = arr[i];
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i] == arr[j] && i != j && max < arr[i]) {
				max = arr[i];
			}
		}
	}
	cout << "Max duplicate: " << max;
	cin.get();
}
