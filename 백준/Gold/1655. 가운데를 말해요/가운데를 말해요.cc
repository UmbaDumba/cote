#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int>> min_heap;

	// 첫번째와 두번째 입력은 무조건 max, min heap에 하나씩 골고루 들어가야함
	int in1, in2;
	cin >> in1 >> in2;
	if (in1 <= in2) {
		max_heap.push(in1);
		min_heap.push(in2);
		cout << in1 << "\n" << in1 << "\n";
	}
	else {
		max_heap.push(in2);
		min_heap.push(in1);
		cout << in1 << "\n" << in2 << "\n";
	}

	for (int i = 2; i < n; i++) {
		// a, b, c, d, e, f ...
		// -> a, b, c, 를 max_heap에 넣으면 top은 c
		// -> d, e, f, 를 min_heap에 넣으면 top은 d
		// => 즉 max_heap의 top이 항상 중앙값임!
		// 개수는 똑같거나, max_heap이 항상 딱 한개 많아야함

		int temp;
		cin >> temp;

		int maxsize = max_heap.size();
		int minsize = min_heap.size();

		if (maxsize == minsize) {
			// max heap이 한 개 증가해야함
			if (temp <= min_heap.top()) {
				// 그냥 maxheap에 넣어주면됨
				max_heap.push(temp);
			}
			else {
				// 오른쪽에 들어가야함 == min.top을 max로 보내주고, temp를 minheap으로 넣어주기
				max_heap.push(min_heap.top());
				min_heap.pop();
				min_heap.push(temp);
			}
		}
		else {
			// max_heap 이 min보다 1개 많은경우 == min이 한개 증가해야함
			if (temp >= max_heap.top()) {
				min_heap.push(temp);
			}
			else {
				// max top을 min으로 보내고, max에 넣어주기
				min_heap.push(max_heap.top());
				max_heap.pop();
				max_heap.push(temp);

			}
		}
		cout <<max_heap.top() << "\n";
	}


}