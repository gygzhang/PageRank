#include"matrix_cal.h"

//#include"graph_store.h"


//#define N 3

void dial_inv(int M[N][N]) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			if (i == j) {
				M[i][j] = 1 / M[i][j];
			}
		}
	}
}

void mul(int A[N][N], int B[N][N], int C[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				C[i][j] += A[j][k] * B[k][j];
			}
		}
	}
}

void trans(int A[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < j) {
				int temp = A[i][j];
				A[i][j] = A[j][i];
				A[j][i] = temp;
			}
		}
	}
}

int inv_num(int M[N]) {
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (M[i] > M[j]) {
				temp++;
			}
		}
	}
	return temp;
}

int sign(int t) {
	if (t % 2 == 0) return 1;
	else return -1;
}

int fac(int n) {
	if (n == 1) return 1;
	else {
		return n * fac(n - 1);
	}
}
//ITEM
int mul_f(int M[N], int T[N]) {
	int temp = 1;
	for (int i = 0; i < N; i++) {
		temp = temp * M[i];
	}
	int c = temp * sign(inv_num(T));
	return temp * sign(inv_num(T));
}

void inv(int A[N][N]) {
	int u = fac(N);
	int M[N] = { 0 }, R = 0, *P, r = 0;
	P = (int *)malloc(sizeof(int)*u);
	memset(P, 0, sizeof(int)*u);
	for (int i = 0; i < N; i++) {
		int x[N] = { 0 }, y[N] = { 0 }, K[N] = { 0 };
		r = 0;
		//M selected from  col
		M[r] = A[i][0];
		//K store the index of col
		K[r] = i;
		r++;
		//y x map to the matrix
		y[i] = 1;
		x[0] = 1;
		for (int j = 0; j < N; j++) {

			for (int k = 0; k < N; k++) {
				if(y[j]!=1&&x[k]!=1){
					M[r] = A[j][k];
					K[r] = k;
					r++;
					y[j] = 1;
					x[k] = 1;
				}
			}
		}
		P[i] = mul_f(M, K);
	}
	printf("asd");
}



int get_det(int **M,int n) {
	int sign = 1;
	int Det = 0;
	int *temp = (int *)malloc(sizeof(int) * 100);
	if (n == 1) return **M;
	for (int i = 0; i < n; i++) {
		get_cofactor(M, 0, i, 4, &temp);
		Det+=sign*get_det(&temp, n - 1);
		sign = -sign;
	}
	return Det;
}


void create_matrix(int** M) {
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", (*M)+i*N+j);
		}
	}
}

void get_cofactor(int **A, int i, int j,int size, int **Cofactor)
{
	int c = 0;
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (a != i && b != j) {
				(*Cofactor)[c++] = *((*A)+a*N+b);
			}
		}
	}
}

void substract(int **A,int **B,int **C) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			C[i][j] = A[i][j] - B[i][j];
		}
	}
}
