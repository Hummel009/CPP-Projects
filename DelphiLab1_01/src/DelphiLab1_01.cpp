#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double x = 0.6;
	while (x <= 1.1) {
		for (int n = 10; n <= 15; n++) {
			double sum = 0;
			for (int k = 1; k <= n; k++) {
				double termR1 = exp(1.2 * k);
				double termR2 = (k - 10) / (k + 30);
				double numerator = exp(log(termR1 + termR2) / k);
				double termR3 = sqrt(k * exp(log(n + 5) / 3));
				double termR4 = log(sqrt(n * x));
				double denominator = termR3 + termR4;
				sum += numerator / denominator;
			}
			double termL1 = exp(n * x) / 2;
			double termL2 = exp(log(n * x) / 3);
			double f = sum + exp(log(termL1 + termL2) / 3);
			cout << "X = " << x << ", N = " << n << ", F = " << f << "\n";
		}
		x += 0.1;
	}
	cin.get();
}
