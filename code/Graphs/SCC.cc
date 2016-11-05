// Time Complexity: O(V + E)
// Input: adjlist
// Output: set of SCC

#include <vector>,<stack>
#define N 100
struct NODE {
	int index, lowlink;
};
int n, ind;
NODE nodes[N];
stack<int> st;
bool instack[N];
vector<vector<int> > adjlist, SCC;
void connect(int v) {
	int w;
	nodes[v].index = nodes[v].lowlink = ind++;
	st.push(v);
	instack[v] = true;
	for (int i=0; i<SZ(adjlist[v]); i++) {
		w = adjlist[v][i];
		if (!nodes[w].index) {
			connect(w);
			nodes[v].lowlink = min(nodes[v].lowlink, nodes[w].lowlink);
		}
		else if (instack[w])
			nodes[v].lowlink = min(nodes[v].lowlink, nodes[w].index);
	}
	if (nodes[v].lowlink == nodes[v].index) {
		vector<int> tmp;
		for(w = -1; w != v; ) {
			w = st.top(); st.pop();
			instack[w] = false;
			tmp.push_back(w);
		}
		SCC.push_back(tmp);
	}
}
void tarjan() {
	ind = 1;
	for (int i=0; i<n; i++) if (!nodes[i].index) connect(i);
}
