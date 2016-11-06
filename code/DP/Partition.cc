// Input: A given arrangement S of non-negative numbers s1; ... ; sn and an integer k.
// Output: Partition S into k ranges, so to minimize the maximum sum over all the ranges.

int M[1000][100], D[1000][100];
void partition_i(vector<int> &v, int k) {
	int p[1000], i, n = v.size();
	v.insert(v.begin(),0);	p[0] = 0;
	for(i = 1;i < v.size(); i++)	p[i] = p[i - 1] + v[i];
	for (i = 1; i <= n; i++)		M[i][1]=p[i];
	for (i = 1; i <= k; i++)		M[1][i] = v[1];
	for (i = 2; i <= n; i++) {
		for (int j = 2; j<=k; j++) {
			M[i][j] = INT_MAX<<1 - 1;
			int s = 0;
			for (int x = 1; x <= i - 1; x++) {
				s = max(M[x][j-1], p[i] - p[x]);
				if (M[i][j] > s)
					M[i][j] = s, 	D[i][j] = x;
	}	}	}
	printf("%d\n", M[n][k]);
}
//n = number of elements of the initial set
void reconstruct_partition(
const vector<int> &S, int n, int k) {
	if (k == 1) {
		for (int i = 1; i <= n; i++) printf("%d ", S[i]);
		putchar('\n');
	} else {
		reconstruct_partition(S, D[n][k], k - 1);
		for (int i = D[n][k] + 1; i<= n; i++) printf("%d ", S[i]);
		putchar('\n');
	}
}

