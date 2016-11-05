// Time Complexity: O(V * E)
// Input: ne, nv, src, end, edges[N] (list of edges)
// Output: Shortest path from src to every vertex on the graph (iff bellman_ford() returns 0. 1 means negative cycle)

#define N 1000
struct Edge {
	int u, v, w;
};
int nv, ne, src, d[N];
Edge edges[N];
int bellman_ford() {
	memset(d, 0x3f, sizeof(d));
	d[src] = 0;
	for (int i=0; i < nv-1; i++)
		for (int j=0; j < ne; j++)
			if (d[edges[j].u] + edges[j].w < d[edges[j].v])
				d[edges[j].v] = d[edges[j].u] + edges[j].w;			
	for (int i=0; i < ne; i++)
		if (d[edges[i].u] + edges[i].w < d[edges[i].v])
			return 1;
	return 0;
}
