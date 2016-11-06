// Time Complexity: O(E * N_flow)
// Input: src, end, cap[i][j] (capacity between nodes i and j)
// Output: Maximum flow from src to end

#include <vector>
#define N 100
#define INF 1000000007
typedef vector< pair<int,int> > vii;
int n, cap[N][N], flow[N][N];
bool vis[N];

bool dfs(int src, int end, vii &path) {
	if (src == end) {
		path.push_back(make_pair(end, INF));
		return true;
	}
	vis[src] = true;
	for (int i=0; i < n; i++) {
		int res = cap[src][i] - flow[src][i];
		if (res > 0 && !vis[i]) {
			path.push_back( make_pair(src, res) );
			bool ret = dfs(i, end, path);
			if (ret) { vis[src] = false; return true; }
			path.pop_back();
		}
	}
	vis[src] = false;
	return false;
}
int max_flow(int src, int end) {
	vector< pair<int,int> > path;
	while (dfs(src, end, path)) {
		int val = INF;
		for (int i=0; i < (int)path.size(); i++)
			val = min(val, path[i].second);
		for (int i=0; i < (int)path.size()-1; i++) {
			int a=path[i].first, b=path[i+1].first;
			flow[a][b] += val;
			flow[b][a] -= val;
		}
		path.resize(0);
	}
	int ret = 0;
	for (int i=0; i < n; i++) ret += flow[src][i];
	return ret;