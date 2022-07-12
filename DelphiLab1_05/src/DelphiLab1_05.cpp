#include <iostream>
#include <cmath>
using namespace std;

static void doCalcsWithEps(double limit) {
	double eps = 0;
	double x = 0.1;
	while (x < 1.0) {
		int k = 1;
		double f = 0;
		do {
			double temp = f;
			f += pow(x, 3 * k + 1) / ((4 * k - 1) * (4 * k - 2));
			k += 1;
			eps = abs(f - temp);
		} while (eps > limit);

		cout << "X = " << x << "; K = " << k << "; F =" << f << "\n";
		x += 0.1;
	}
	cout << "\n";
}

int main() {
	doCalcsWithEps(1e-5);
	doCalcsWithEps(1e-6);
	cin.get();
}
