#include <iostream>
#include <vector>
using namespace std;

void mul(vector<vector<int>>, vector<vector<int>>, vector<vector<int>>*);
vector<vector<int>> mul2(vector<vector<int>>, vector<vector<int>>);
void print_vec(vector<vector<int>>);

int main() {

	int n;
	long long b;
	cin >> n >> b;

	vector<vector<int>> a(n, vector<int>(n));
	vector<vector<int>> result(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			a[i][j] %= 1000;
			if (i == j) {
				result[i][j] = 1;
			}
		}
	}
	

	if (b == 1) {
		print_vec(a);
		return 0;
	}


	while (b > 0) {
		long long n2 = 1;
		vector<vector<int>> subresult = a;
		while (b >= (n2 * 2)) {
			// 제곱근 가능!
			n2 *= 2;
			subresult = mul2(subresult, subresult);
		}

		/*cout << "n2 : " << n2 << endl;
		print_vec(subresult);
		cout << "--------" << endl;*/

		b -= n2;
		result = mul2(result, subresult);

		/*cout << "result" << endl;
		print_vec(subresult);
		cout << "--------" << endl;*/

		/*if (b == 1) {
			result = mul2(subresult, a);
			break;
		}*/
	}
	

	print_vec(result);

	return 0;
}



vector<vector<int>> mul2(vector<vector<int>> a, vector<vector<int>> b){
	vector<vector<int>> result = a;
	for (int i = 0; i < (int)a.size(); i++) {
		for (int j = 0; j < (int)a.size(); j++) {
			result[i][j] = 0;
			for (int k = 0; k < (int)a.size(); k++) {
				result[i][j] += (a[i][k] * b[k][j]);
			}
			result[i][j] %= 1000;
		}
	}
	return result;
}

void print_vec(vector<vector<int>> vec) {
	for (int i = 0; i < (int)vec.size(); i++) {
		for (int j = 0; j < (int)vec.size(); j++) {
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}

void mul(vector<vector<int>> a, vector<vector<int>> b, vector<vector<int>>* result) {
	for (int i = 0; i < (int)result->size(); i++) {
		for (int j = 0; j < (int)result->size(); j++) {
			(*result)[i][j] = 0;
			for (int k = 0; k < (int)a.size(); k++) {
				(*result)[i][j] += (a[i][k] * b[k][j]);
			}
			(*result)[i][j] %= 1000;
		}
	}
}