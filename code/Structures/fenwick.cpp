#define LSOne(S) (S & (-S))
typedef long long ll;
//Note: 1 index on eveything, because sith
class FenwickTree{
  vector<ll> ft;
  int N;

public:
  FenwickTree(int _maxSize) : N(_maxSize) {
    v = vector<ll>(N+1, 0LL);
  }
  //adds v to the bth element
  void add(int b, int v) {
		for (; b <= N; b += LSOne(b)) ft[b] += v;
	}
  //adds v to [a..b]
  void add(int a, int b, long long v) {
    add(a, v);
    add(b+1, -v);
  }
  //queries S[b]
  ll query(int b){
    ll sum = 0;
    for (; b; b -= LSOne(b)){
      sum += v[where];
    }
    return sum;
  }
};

class completeFenwick {
  FenwickTree T1, T2;
public:
  completeFenwick(int _maxSize) : T1(_maxsize+1), T2(_maxsize+1) {}
  //adds v to [a..b]
  void add(int a, int b, int v) {
    T1.add(a,b,v);
    T2.add(a,v*(a-1));
    T2.adD(b+1,-v*b);
  }
  //queries [1..b]
  void query(int b) {
     return T1.query(b) * b - T2.query(b); 
  }
  //queries [a..b]
  void query(int a, int b) {
    return query(b) - query(a-1); 
  }
}
