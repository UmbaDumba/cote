#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	priority_queue<int> maxheap;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		int answer = 0;
		if (num == 0) {
			if (!(maxheap.empty())) {
				answer = maxheap.top();
				maxheap.pop();
			}
			cout << answer << '\n';
		}
		else {
			maxheap.push(num);
		}

	}

	return 0;
}