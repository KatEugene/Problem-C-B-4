#pragma GCC target("avx2")
#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <random>
#include <numeric>
#include <unordered_set>

typedef long long ll;
typedef long double lb;

#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_in freopen("input.txt", "r", stdin);
#define file_in_out freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

using namespace std;

int const MAX = 1e6;

template<typename T>
istream& operator>>(istream &in, vector<T> &v) {
	for (auto &it : v) {
		in >> it;
	}
	return in;
}

template<typename T>
ostream& operator<<(ostream &out, vector<T> &v) {
	if (!v.empty()) {
		out << v.front();
		for (int i = 1; i < v.size(); ++i) {
			out << " " << v[i];
		}
	}
	return out;
}

int main() {
	fast
	//file_in
	//file_in_out

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	cin >> a;
	sort(a.begin(), a.end());
	int j = 0, con = 0;
	vector<int> now;
	while(j < a.size() && a[j] <= k) {
		now.push_back(a[j]);
		++j;
	}
	int ans = 0;
	for (int i = k; i <= MAX; ++i) {
		//cout << i << " " << con << endl;
		if (j < a.size() && a[j] <= i) {
			now.push_back(a[j]);
			++j;
		}
		if (now.size() + m - con >= k) {
			++ans;
		}
		while (con < now.size() && now[con] <= i - k + 1) {
			++con;
		}
	}
	cout << ans << endl;
}