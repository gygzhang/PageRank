#include"graph_store.h"
#include<stdio.h>


constexpr auto N = 6;



int main() {
	double R[N];
	int outlink[N] = {0};
	double d = 0.85;
	for (int i = 0; i < 6; i++) {
		R[i] = 1 / N;
	}
	double aa = 0.0078323600137409841;
	MGraph G;
	CreateDN(&G);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (G.arcs[i][j].adj != INT_MAX&&i!=j) {
				outlink[i]++;
			}
		}
	}
	/*outlink[0] = 3;
	outlink[1] = 2;
	outlink[2] = 4;
	outlink[3] = 1;
	outlink[4] = 5;
	outlink[5] = 2;*/
	bool cal = 1;
	double cvg = 1e-111;
	while (cal) {
		double temp[N] = { 0 };
		double prev[N] = { 0 };
		double tcvg=0;
		for (int i = 0; i < N; i++)
		{
			prev[i] = R[i];
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i != j&&G.arcs[i][j].adj!=INT_MAX) {
					temp[i] +=R[j] / outlink[j];
					//temp[i] = R[i];
				}
			}
			R[i] = (1 - d) / N + d * temp[i];
		}

		for (int i = 0; i < N; i++) {
			tcvg = tcvg + ( R[i]-prev[i]);
		}
		//cout << "a";
		if (tcvg-cvg<1e-36) break;		
	}

}


