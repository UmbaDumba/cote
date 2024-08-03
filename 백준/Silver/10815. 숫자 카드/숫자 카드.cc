#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

vector<int> sanguen_card;

bool binary_search(int a) {
	int n = sanguen_card.size();
	int left = 0;
	int right = n-1;


	while (left <= right) {
		int index = (left + right) / 2;
		//cout << "index : " << index<<endl;
		if (a == sanguen_card[index]) {
			// 정답을 찾음
			return true;
		}
		else if (a > sanguen_card[index]) {
			left = index + 1;
			continue;
		}
		else {
			right = index - 1;
			continue;
		}

	}

	return false;
}

int main() {
	//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		sanguen_card.push_back(temp);
	}

	sort(sanguen_card.begin(), sanguen_card.end());
	// 오름차순 정렬
	

	cin >> m;
	for (int i = 0; i < m; i++) {
		int q;
		scanf("%d", &q);
		//cout << "q : " << q << endl;
		//cout << binary_search(sanguen_card, q)<<" ";
		printf("%d ", binary_search(q));

	}


	return 0;
}