// Time Complexity: O(N^3)
// Input: cost (adjacency matrix with cost)
// Output: Shortest path between all pair of nodes

#include <algorithm>
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define N 100
int path[N][N], cost[N][N];
void FloydWarshall() {
	FOR(i,0,n) FOR(j,0,n) path[i][j] = cost[i][j];
	FOR(k,0,n) FOR(i,0,n) FOR(j,0,n)
		path[i][j] = min(path[i][j], path[i][k]+path[k][j]);
}
