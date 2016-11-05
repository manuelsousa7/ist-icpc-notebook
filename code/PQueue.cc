// priority queue having minimum at top

#include <queue>,<functional>
priority_queue< T, vector<T>, greater<T> > pqueue;

// priority queue with custom comparing function
#include <queue>
struct cmp {
	bool operator ()(const int a, const int b) {
		return ((a)<(b));
	}
};
priority_queue<int, vector<int>, cmp> q;
