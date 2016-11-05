// Time Complexity: O( V * E ) which at most is O(V^3)
// Input: adjency list graph graph[i] has all the nodes j to which node i can be connected
//Output:
//	- matchL[m] (right vertex to which left vertex m is matched, -1 if not matched)
//	- matchR[n] (left vertex to which right vertex n is matched, -1 if not matched)
//	- nmatches (number of matches)

#include <cstring> 
#include <vector> 
#define MAX 410 
vector<int> graph[MAX]; 
bool seen[MAX]; 
int matchL[MAX], matchR[MAX], nmatches; 
int nLeft, nRight; 
bool findmatch(int leftv) { 
	for(int i=0; i<(int)graph[leftv].size(); i++) { 
		int rightv = graph[leftv][i];		 
		if (seen[rightv]) continue; 
		seen[rightv]=true; 
		if(matchR[rightv]==-1 || findmatch(matchR[rightv])) { 
			nmatches += (matchR[rightv]==-1 ? 1:0); 
			matchR[rightv]=leftv; 
			matchL[leftv]=rightv; 
			return true; 
		} 
	} 
	return false; 
} 
void bpm() { 
	memset(matchL, -1, sizeof(matchL)); 
	memset(matchR, -1, sizeof(matchR)); 
	memset(seen, 0, sizeof(seen)); 
	nmatches=0; 
	for(int i=0; i<nLeft; i++) { 
		findmatch(i); 
		memset(seen, 0, sizeof(seen));	 
	} 
}
