#include <iostream>
#include <unordered_map>


using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n;
	
	unordered_map<int, int> sangnumbers;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (sangnumbers.find(temp) != sangnumbers.end()) {
			// 가지고있는것
			sangnumbers[temp]++;
			continue;
		}
		sangnumbers[temp] = 1;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int q;
		cin >> q;
		if (sangnumbers.find(q) != sangnumbers.end()) {
			cout << sangnumbers[q] << " ";
			continue;
		}
		cout << "0 ";
	}

	return 0;
}