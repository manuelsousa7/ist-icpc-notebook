// Time Complexity: O(len(W) + len(S))
// Input: S and W (W is the substring to search in S)
// Output: Position of the first match of W in S

#include <cstdlib>,<string>
int* compute_prefix(string w) { 
	int m = w.length(), k = 0; 
	int *pi = (int*)malloc(sizeof(int)*m); 
	pi[0] = 0;
	for (int q=1; q<m; q++) { 
		while (k > 0 && w[k] != w[q]) k = pi[k-1];
		if (w[k] == w[q]) k++; 
		pi[q] = k; 
	} 
	return pi;
}
int kmp_match(string s, string w) {
	int *pi=compute_prefix(w); 
	int q = 0, n = s.length(), m = w.length();
	for (int i=0; i<n; i++) {
		while (q > 0 && w[q] != s[i]) q = pi[q-1];
		if (w[q] == s[i]) q++;
		if (q == m) return i-m+1; // Match at pos i-m+1
	}
	return -1; // No Match
}
