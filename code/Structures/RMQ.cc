// Time Complexity: Query O(log N)
// Input:
//	N -> number of values in A
//	A[i] -> i-th value
//	M[i] -> minimum value position for
//		the interval assigned to the i-th node
//Output:	Minimum value in interval [i, j]

#define MAXN 1000
#include <cstdio>

int A[MAXN], M[MAXN], N;

void init(int node, int b, int e) {
	if (b == e) M[node] = b;
	else {
	//compute left and right subtrees ranges
		init(2*node, b, (b + e)/2);
		init(2*node + 1, (b + e)/2 + 1, e);
	//search for min value 1st, 2nd half of interval
		if (A[M[2 * node]] <= A[M[2 * node + 1]])
			M[node] = M[2 * node];
		else
			M[node] = M[2 * node + 1]; 
	}
}
// b and e are bounds of the current interval
// i and j are bounds of the query interval
int query(int node, int b, int e, int i, int j) {
	int p1, p2;

	//[b,e] doesn't intersect [i,j]
	if (i > e || j < b)		return -1;
	//[b,e] in [i,j]
	if (b >= i && e <= j)	return M[node];

	//compute the minimum position in the 
	//left and right part of the interval
	p1 = query(2*node, b, (b + e)/2, i, j);
	p2 = query(2*node + 1, (b + e)/2 + 1, e, i, j);

	//overall minimum position
	if (p1 == -1)				return M[node] = p2;
	if (p2 == -1)				return M[node] = p1;
	if (A[p1] <= A[p2])		return M[node] = p1;
	return M[node] = p2;
}
