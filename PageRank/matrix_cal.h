#pragma once
#define _CRT_SECURE_NO_WARNINGS 0
//#include"graph_store.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5

//对角矩阵求逆
void dial_inv(int **M); 
//矩阵乘法
void mul(int *A, int *B, double **C); 
//将一个矩阵转置
void trans(int A[N][N]);
//获得逆序数
int inv_num(int M[N]);
//偶数返回1，奇数返回-1
int sign(int t);

//递归阶乘
int fac(int n);

int mul_f(int M[N], int T[N]);

void inv(int A[N][N]);
//创建行列式
void create_matrix(int** M);
//获得除i行j列的子矩阵
void get_submatrix_by_i_j(int **A, int i,int j,int size, int **Cofactor);

int ** get_submatrix_by_i_j(int **A, int i, int j, int size);

//获得行列式
int get_det(int **M, int n);
//获取代数余子式
int get_algebraic_cofactor(int **A,int i,int j);

void get_adjoint_matrix(int **A, int size, double **B);

void get_inverse_matrix(int **A,int size,double **B);

void munber_mul_matrix(double **A, int size,double num);

void gen_identity_matrix(double **M, int size);

void substract(double **A, double **B, double **C);

