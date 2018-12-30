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
				if (G->arcs[j][i].adj==1) {
					double  aa= (double)R[j] / outlink[j];
					temp[i] += aa;
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

void get_K(int *outlink, double **K) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				*(*K + i * N + j) = *(outlink + i);
				cout << K;
			}
			else *(*K + i * N + j) = 0;
		}
	}
}

void get_M(AdjMatrix A,double *K,double **M) {
	double *temp = (double *)malloc(sizeof(double) * 100);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(A[i][j].adj==1){
				*(temp + i * N + j) = (double)A[i][j].adj == 1;
				//cout << "asd";
			}
			else {
				*(temp + i * N + j) = 0;
			}
		}
	}
	dial_inv(&K);
	square_martix_mul(K, temp, M);
	//trans(M);
}

void get_col_vector_contains_ones(double **I,int size) {
	for (int i = 0; i < size; i++) {
		*(*I + i*size) = 1;
	}
}


void pagerank_matrix(AdjMatrix Adj,int *outlink,double d) {
	double *indentity_matrix = (double*)malloc(sizeof(double) * 100);
	double *M = (double*)malloc(sizeof(double) * 100);
	double *H = (double*)malloc(sizeof(double) * 100);
	double *U = (double*)malloc(sizeof(double) * 100);
	double *I = (double*)malloc(sizeof(double) * 100);
	double *R = (double*)malloc(sizeof(double) * 100);
	double *K = (double *)malloc(sizeof(double) * 100);
	matrix_init(&indentity_matrix, N);
	matrix_init(&M, N);
	matrix_init(&H, N);
	matrix_init(&U, N);
	matrix_init(&I, N);
	matrix_init(&R, N);
	matrix_init(&K, N);
	gen_identity_matrix(&indentity_matrix, N);
	get_K(outlink, &K);
	get_M(Adj, K, &M);
	trans(&M);
	munber_mul_matrix(&M, N, d);
	substract(&indentity_matrix, &M, &H);
	//matrix_print(H, N);
	get_inverse_matrix(&H, N, &U);
	get_col_vector_contains_ones(&I, N);
	munber_mul_matrix(&I, N, (1 - d) / N);
	//comm_matrix_mul(&U, N, N, 1, &I, &R);
	mul_col_vector(&U, N, (1 - d) / N,&R);
	trans(&R);
	//cout << "aa";
}

int main() {
	//cout << 1 / 0;
	MGraph G;
	CreateDN(&G);
	double R[N]; //= (double *)malloc(sizeof(double)*N);
	int outlink[N] = { 0 };
	double d = 0.85;
	double err = 1e-35;
	for (int i = 0; i < N; i++) {
	*(R+i) = 1.0 / N;
	}
	get_outlink(G, outlink);
	/*pankrank_iteration(R, err, &G, 0.85, outlink);
	for (double r : R) {
		cout << r << endl;
	}*/
	//test();
	double *matrix = (double*)malloc(sizeof(double)*100);
	double *v = (double*)malloc(sizeof(double)*100);
	//int R[N] = { 2,1,8 };
	//memset(v, 0, sizeof(double) * 100);
	//create_matrix(&matrix);
	//trans(matrix);
	//int a = inv_num(R);
	//int b = fac(3);
	 //int c = mul_f(R, R);
	//inv(matrix);
	//get_cofactor(&matrix, 0, 1,4, &v);
	//get_cofactor(&v, 0, 1, 3, &v);
	double e=0;
	//e = get_det(&matrix, N);
	//get_inverse_matrix(&matrix, N, &v);
	//get_adjoint_matrix(&matrix, N, &v);
	//e = det(matrix, N);
	//cout<<endl<<e;
	//square_martix_mul(matrix, matrix, &v);
	pagerank_matrix(G.arcs, outlink, 0.85);

	//inv(matrix);

	cout << "asd";

}
/*

8 14
1 2 3 4 5 6 7 8
1 6 1
1 8 1
2 8 1
2 1 1
3 4 1
3 8 1
4 2 1
4 8 1
4 5 1
5 8 1
6 8 1
6 7 1
6 5 1
7 8 1
8 3 1
0 0 0





1 2 0
-1 1 -4
3 -1 8
-142
5 1 1 1
-2 2 -1 4
-2 -3 -1 -5
0 1 2 11

1 2 3 4 5
6 7 8 9 10
1 2 5 7 8
2 -8 9 -8 -6
7 4 5 8 6

1 2
3 4
*/



