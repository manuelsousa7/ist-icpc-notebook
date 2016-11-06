// Time Complexity: O(V * E^2)
// Input: ne, nv, src, end, cap[i][j] (capacity between nodes i and j)
// Output: Maximum flow from src to end

#include <cstring>
#include <queue>
#define N 100
#define INF 1000000007
int n, cap[N][N], flow[N][N], pre[N], res[N];
void bfs(int src, int end) {
	queue<int> qu;
	memset(pre,-1,sizeof(pre));	
	res[src] = INF; qu.push(src);
	while (!qu.empty() && pre[end] < 0) {
		int c = qu.front(); qu.pop();
		for (int i=0; i < n; i++) {
			if (pre[i] < 0 && cap[c][i]-flow[c][i] > 0) {
				qu.push(i);
				pre[i] = c;
				res[i] = min(res[c], cap[c][i]-flow[c][i]);
}	}	}	}
int max_flow(int src, int end) {
	if (src == end) return INF;
	while (true) {
		bfs(src, end);	
		if (pre[end] < 0) break; // No more cap in pres
		for (int i=end; i != src; i=pre[i]) {
			flow[pre[i]][i] += res[end];
			flow[i][pre[i]] -= res[end];
		}
	}
	int ret = 0;
	for (int i=0; i < n; i++) ret += flow[src][i];
	return ret;
}