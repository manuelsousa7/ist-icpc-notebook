// O(N log N)

#include <cmath>,<cstdio>,<algorithm>,<set>
#define EPS 1e-7
using namespace std;

struct Point {
	double x , y;
	int index ;
	bool operator < ( const Point & a ) const {
		return y < a.y || (fabs(y-a.y) < EPS && x < a.x );
	}
} p[60010] , tmp;

int np;
set<Point> pontos;
set<Point>::iterator it ;

bool comparaX( const Point & a , const Point & b ) {
	return a.x < b.x ;
}
double distancia( const Point & a , const Point & b ) {
	double q = a.x - b.x , w = a.y - b.y;
	return sqrt( q*q + w*w );
}

int main() {
	int i , left , a1 , a2;
	scanf("%d\n", &np);		// input
	for (i = 0 ; i < np ; i++) {
		scanf("%lf %lf\n", &p[i].x , &p[i].y);
		p[i].index = i;
	}
	sort( p , p+np , comparaX ); // ordena pontos por coordenada X
	double dist = 2000000000.0 , d;			// sweep line
	pontos.insert(p[0]);
	left = 0;
	for (i = 1 ; i < np ; i++) {			// para cada ponto p[i]
		while (p[i].x - p[left].x > dist )	// remove todos os pontos cuja distancia em X ao ponto actual (p[i])
			pontos.erase( p[left++] );	// e' maior ou igual do que a menor distancia entre pontos encontrada ate ao momento
		tmp.y = p[i].y - dist;
		it = pontos.lower_bound( tmp );
		while (it != pontos.end() && it->y < p[i].y+dist) {	// percorrer os pontos do set
			d = distancia( p[i] , *it ); // com Y dentro do intevalo
			if ( d < dist ) {	// [ p[i].y - dist , p[i].y + dist ]
				dist = d;
				a1 = it->index;
				a2 = p[i].index;
			}
			it++;
		}
		pontos.insert(p[i]);
	}
	if (a1 > a2) // verifica a1 apareceu antes que a2 no input
		swap( a1 , a2 );		
	printf("%d %d %.6f\n", a1, a2, dist);	// output
//	printf("%.4f\n", dist);	// distancia calculada, debug only
	return 0;
}
