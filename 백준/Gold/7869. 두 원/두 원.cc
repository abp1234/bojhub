#include <iostream>
#include <cmath>
#include <iomanip>

#define M_PI 3.141592654589793

using namespace std;

double calcArea(double x1, double y1, double r1, double x2, double y2, double r2) {
	double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	double rr1 = r1 * r1;
	double rr2 = r2 * r2;

	if (d > r1 + r2) {
		return 0.0;
	}
	else if (d <= abs(r1 - r2) && r1 < r2) {
		return M_PI * rr1;
	}
	else if (d <= abs(r1 - r2) && r1 >= r2) {
		return M_PI * rr2;
	}
	else {
		double phi = 2.0 * acos((rr1 + d * d - rr2) / (2.0 * r1 * d));
		double theta = 2.0 * acos((rr2 + d * d - rr1) / (2.0 * r2 * d));
		double a1 = 0.5 * rr1 * (phi - sin(phi));
		double a2 = 0.5 * rr2 * (theta - sin(theta));
		return a1 + a2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	double res = calcArea(x1, y1, r1, x2, y2, r2);

	cout << fixed << setprecision(3) << res << '\n';
	return 0;
}