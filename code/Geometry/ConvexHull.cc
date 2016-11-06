// Time Complexity: O(N log N)
// Input: vector<Point> P e H
// Output: H fica com pontos do convexhull elemento H[H.size - 1] = H[0]

void ConvexHull (vector<Point> P, vector<Point> & H) {               
	int n = P.size(), k = 0;
	H.resize(2*n);            	                              
	// Sort points lexicographically       
	sort(P.begin(), P.end()); /* use Point comparator*/
	// Build lower hull
	for (int i = 0; i < n; i++) {
		/* change to: "cross() < 0" to include colinears */
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
	// Build upper hull
	for (int i = n-2, t = k+1; i >= 0; i--) {
		/* change to: "cross() < 0" to include colinears */
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
	H.resize(k);
}