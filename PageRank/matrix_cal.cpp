#include"matrix_cal.h"
#include<iostream>
using namespace std;
//#include"graph_store.h"


//#define N 3

void dial_inv(double **M) {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) {
			if (i == j) {
				*(*M+i*N+j) = 1.0/(*(*M+i*N+j));
			}
		}
	}
}

void square_martix_mul(double *A, double *B, double **C) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			*(*C + i * N + j) = 0;
			for (int k = 0; k < N; k++) {
				 double s =(double)*(A+i*N+k) * *(B+k*N+j);
				 *(*C + i * N + j) += s;		
			}
			
		}
	}
}

void trans(double** A) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < j) {
				double temp =*(*A+i*N+j);
				*(*A + i * N + j) = *(*A + j * N + i);
				*(*A + j * N + i) = temp;
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



double get_det(double **M,int n) {
	int sign=1;
	double Det = 0;
	
	double *temp = (double *)malloc(sizeof(double) * 100);
	if (n == 1) return **M;
	if (n == 2) {
		return (**M) * (*(*M + 3)) - *(*M + 1) * (*(*M + 2));
	}
	if(n>2){
	for (int i = 0; i < n; i++) {
		get_submatrix_by_i_j(M, 0, i, n, &temp);
		Det+=sign* *((*M) + i)*get_det(&temp, n-1);
		sign = -sign;
		
	}
	}
	return Det;
	
		/*int d, k, n;
		int **p;
		p = new int*[size];
		for (auto i = 0; i < size; i++)
		{
			p[i] = new int[size];
		}
		auto j = 0;
		d = 0;
		k = 1;
		n = size - 1;
		if (size == 1)
		{
			d = arr[0][0];
			return d;
		}
		if (size == 2)
		{
			d = (**arr) * (*(*arr + 3)) - *(*arr + 1) * (*(*arr + 2));
			return d;
		}
		if (size > 2)
		{
			for (auto i = 0; i < size; i++)
			{
				get_cofactor(arr, 0, i, n, p);
				d += k * *((*arr) + i) * get_det(p, n);
				k = -k;
			}
		}
		return d;*/
	
}

double get_algebraic_cofactor(double ** A, int i, int j)
{
	double *t = (double *)malloc(sizeof(double) * 100);
	get_submatrix_by_i_j(A, i, j, N, &t);
	return sign(i + j) * get_det(&t, N-1);
}

void get_adjoint_matrix(double ** A, int size, double ** B)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			double temp;
			temp = get_algebraic_cofactor(A, i, j);
			*(*B + j * size + i) = temp;
		}
	}
}

void get_inverse_matrix(double ** A, int size, double ** B)
{
	double determinant = get_det(A, size);
	//int *temp = (int *)malloc(sizeof(int) * 100);
	get_adjoint_matrix(A, size, B);
	munber_mul_matrix(B, size, 1.0/determinant);
}

void munber_mul_matrix(double ** A, int size,double num)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			*(*A + i * size + j) *= num;
			cout << "sad";
		}
	}
}

void gen_identity_matrix(double ** M, int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if(i==j) *(*M + i * size + j) = 1;
			else *(*M + i * size + j) = 0;
		}
	}
}


void create_matrix(double** M) {
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%lf", ((*M)+i*N)+j);
		}
	}
}

void get_submatrix_by_i_j(double **A, int i, int j,int size, double **Cofactor)
{
	int c = 0;
	for (int a = 0; a < size; a++) {
		for (int b = 0; b < size; b++) {
			if (a != i && b != j) {
				*((*Cofactor)+c) = *((*A)+a*size+b);
				c++;
			}
		}
	}
}

//double ** get_submatrix_by_i_j(double ** A, int i, int j, int size)
//{
//	double *temp = (double *)malloc(sizeof(double) * 100);
//	get_submatrix_by_i_j(A, i, j, size, &temp);
//	return &temp;
//}

void substract(double **A,double **B,double **C) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			*(*C+i*N+j) = *(*A + i * N + j) - *(*B + i * N + j);
			//cout << "a";
		}
	}
}

void comm_matrix_mul(double ** A, int m, int r, int n, double ** B, double ** C)
{
	//N N 1
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < r; k++) {
				*(*C + i * m + j) += *(*A + i * r + k)**(*B + k * n+j);
				//cout << "a";
			}

		}
	}
}

void matrix_init(double ** A, int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			*(*A + i * size + j) = 0;
		}
	}
}

void matrix_print(double * A, int size)
{
	cout << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << (*(A + i * size + j))<<" ";
		}
		cout << endl;
	}
}

void mul_col_vector(double ** A, int size,double I, double ** B)
{
	for (int i = 0; i < size; i++) {
		double temp = 0;
		for (int j = 0; j < size; j++) {
			temp += *(*A + i * size + j);
		}
		*(*B + i * size) = temp * I;
	}
}

