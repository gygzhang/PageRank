#include"graph_store.h"
#include"matrix_cal.h"


void get_outlink(MGraph G,int *outlink) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (G.arcs[i][j].adj != INT_MAX && i != j) {
				outlink[i]++;
			}
		}
	}
}

void pankrank_iteration(double *R, double error, MGraph *G,double d,int *outlink) {	
	bool cal = 1;
	double cvg = 1e-111;
	while (cal) {
		double temp[N] = { 0 };
		double prev[N] = { 0 };
		double tcvg = 0;
		for (int i = 0; i < N; i++)
		{
			prev[i] = R[i];
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i != j && G->arcs[i][j].adj != INT_MAX) {
					temp[i] += R[j] / outlink[j];
					//temp[i] = R[i];
				}
			}
			R[i] = (1 - d) / N + d * temp[i];
		}
		for (int i = 0; i < N; i++) {
			tcvg = tcvg + (R[i] - prev[i]);
		}
		if (tcvg - cvg < 1e-36) break;
	}

}


void pagerank_matrix() {
	
}

int main() {
	//cout << 1 / 0;
	/*MGraph G;
	CreateDN(&G);
	double R[N];
	int outlink[N] = { 0 };
	double d = 0.85;
	double err = 1e-305;
	for (int i = 0; i < 6; i++) {
		R[i] = 1 / N;
	}
	get_outlink(G, outlink);
	pankrank_iteration(R, err, &G, 0.85, outlink);
	for (double r : R) {
		cout << r << endl;
	}*/

	int *matrix = (int*)malloc(sizeof(int)*100);
	int *v = (int*)malloc(sizeof(int)*100);
	//int R[N] = { 2,1,8 };
	create_matrix(&matrix);
	//trans(matrix);
	//int a = inv_num(R);
	//int b = fac(3);
	 //int c = mul_f(R, R);
	//inv(matrix);
	//get_cofactor(&matrix, 0, 1,4, &v);
	int d = get_det(&matrix, N);

	//inv(matrix);

	cout << "asd";

}
/*
1 2 0
1 1 4
3 1 8
*/


