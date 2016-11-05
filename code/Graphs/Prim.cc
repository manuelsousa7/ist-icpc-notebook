//Complexidade: O(E log V)
//Dados iniciais: pair<distancia, vertice> na lista de adjacencia
//Dados finais:
//	d[v] -> distancia da aresta que liga a MST ao vertice v
//	parent[v] -> vertice a que esta ligado o vertice v
//	totalweight -> peso total da arvore

#include <vector>,<set>
#define NVERTICES 10010
vector< pair<int,int> > adjlist[NVERTICES];
set< pair<int,int> > heap;
int d[NVERTICES], parent[NVERTICES], totalweight;
void add(int cost, int v, int p) {
	if(cost<d[v]) {
		parent[v]=p;
		heap.erase(pair<int,int>(d[v], v));
		d[v]=cost;
		heap.insert(pair<int,int>(d[v], v));
	}
}

void prim(int root) {
	memset(d, 0x3f, sizeof(d)); // 0x3f3f3f3f > 1.000.000.000
	memset(parent, -1, sizeof(parent));
	totalweight=0;
	add(0, root, -1);
	while(!heap.empty()) {
		pair<int,int> cur = *heap.begin();
		totalweight+=d[cur.second];
		d[cur.second]=0; //vertex in MST
		heap.erase(heap.begin()); //pop closest vertex
		for(unsigned int i=0; i<adjlist[cur.second].size(); i++) //for each neighbour
			add(adjlist[cur.second][i].first, adjlist[cur.second][i].second, cur.second); //add/refresh distance
	}
}
