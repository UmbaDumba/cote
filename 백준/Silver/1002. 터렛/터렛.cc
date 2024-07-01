#include <iostream>
#include <cmath>
using namespace std;

double get_distance(int x1, int y1, int x2, int y2) {
	int x = x1 - x2;
	int y = y1 - y2;

	return sqrt((x*x) + (y*y));

}

int comdouble(double x, double y, double absTolerance = (1.0e-8))
{
	double diff = x - y;
	if (fabs(diff) <= absTolerance)
		return 0;

	return (diff > 0) ? 1 : -1;
}


int main() {

	int testcase;
	int* answer;
	

	cin >> testcase;

	answer = new int[testcase];

	for (int i = 0; i < testcase; i++) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double distance = get_distance(x1, y1, x2, y2);

		if (distance == 0 ) {
			if ((r1 == r2)) {
				answer[i] = -1;
				continue;
			}
			answer[i] = 0;
			continue;
		}

		double r = r1 + r2;
		

		if (r < distance) {
			answer[i] = 0;
			continue;
		}
		else if (r > distance) {
			/*
			if ( comdouble((distance + (double)r1), r2) || comdouble((distance + (double)r2), r1)) {
				answer[i] = 1;
				continue;
			}
			*/
			if (((distance + (double)r1) == r2) || ((distance + (double)r2) == r1)) {
				answer[i] = 1;
				continue;
			}
			else if (((distance + (double)r1) < r2) || ((distance + (double)r2) < r1)) {
				answer[i] = 0;
				continue;
			}
			
			answer[i] = 2;
			continue;
		}
		else {
			answer[i] = 1;
			continue;
		}

		answer[i] = 2;
		

	}

	
	for (int i = 0; i < testcase; i++) {
		cout << answer[i] << endl;
	}
	



	return 0;
}