#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e5;
vector<int> total(MAX + 1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	// precompute the total sides for each polygon
	// polygons with sides 3 to 5 CANNOT have child polygons
	total[3] = 3;
	total[4] = 4;
	total[5] = 5;
	// start the loop in polygon with 6 sides up to (10 ^ 9)
	for (int side = 6; side <= MAX; side++) {
		// to get the total sides for each polygon the initial number of sides
		// must be added to the sides of the child polygon(s), and to create
		// a child polygon, ALTERNATING vertices must be used (simply 'n' / 2)
		// until it reaches to sides 3, 4, or 5 (since these polygons are the limit)
		total[side] = side + total[side / 2];
	}
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x, y;
			// the vertices will not be used
			cin >> x >> y;
		}
		// output the total number of sides using index 'n'
		cout << total[n] << '\n';
	}
	return 0;
}
