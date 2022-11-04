#include <iostream>
#include <cmath>
using namespace std;

double D0(const int N,const int i)

{
	
	double D = 1;
	for (int K = N; K <= i; K++)
		D *= (1.*K - N) / (1.*K + N) + 1;
		
	return D;
}
double D1(const int N,const int i,  const int K)
{
	if (K > i)
		return 1;
	else
		return ((1. * K - N) / (1. * K + N) + 1) * D1(N, i, K + 1);
	
}
	double D2(const int N, const int i,const int K)
	{
		if ( K < N)
			return 1;
		else
			return ((1. * K - N) / (1. * K + N) + 1) * D2(N,i, K - 1);
	}
double D3(const int N,const int i, const int K,  double t)
{
	t = t *((1. * K - N) / (1. * K + N) + 1);
	if (K >= i)
		return t;
	else
		
		return D3(N,i, K+1, t);
}
double D4(const int N, const int i,const int K, double t)
{
	t = t* ((1. * K - N) / (1. * K + N) + 1);
	if (K <= N)
		return t;
	else
		return D4(N, i,K-1, t);
	
}
int main()
{
	int K, N, i;
	cout << "i="; cin >> i;
	cout << "N = "; cin >> N;
	cout << "K = "; cin >> K;
	
	cout << "(iter) D0 = " << D0(N,19) << endl;
	cout << "(rec up ++) D1 = " << D1(N, 19,N) << endl;
	cout << "(rec up --) D2 = " << D2(N, 19,19) << endl;
	cout << "(rec down ++) D3 = " << D3(N, 19,N,  1) << endl;
	cout << "(rec down --) D4 = " << D4(N, 19,19, 1) << endl;
	return 0
		;
}
