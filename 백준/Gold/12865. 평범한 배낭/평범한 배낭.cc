#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n, k;
vector<pair<int, int>> weight_values;
vector<vector<int>> dp;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	dp = vector<vector<int>>(n+1, vector<int>(k+1, 0));
	weight_values.push_back({ 0, 0 });
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		weight_values.push_back({ a, b });
	}

	//sort(weight_values.begin(), weight_values.end(), cmp);

	

	for (int j = 0; j <= k; j++) {
		for (int i = 1; i <= n; i++) {
			// 무게 : j까지
			// 확인할 물건 : i
			if (j >= weight_values[i].first) {
				// 넣을 수 있음
				dp[i][j] = max(dp[i - 1][j], dp[i-1][j - weight_values[i].first] + weight_values[i].second);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
			//cout << i << ", "<<j << " : "<< dp[i][j] << endl;
		}
	}
	
	

	cout << dp[n][k];

	return 0;
}