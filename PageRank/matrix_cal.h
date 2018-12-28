#pragma once
#define _CRT_SECURE_NO_WARNINGS 0
//#include"graph_store.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 3

void dial_inv(int M[N][N]); 

void mul(int A[N][N], int B[N][N], int C[N][N]); 

void trans(int A[N][N]);

int inv_num(int M[N]);

int sign(int t);
int fac(int n);

int mul_f(int M[N], int T[N]);

void inv(int A[N][N]);

void create_matrix(int** M);

void get_cofactor(int **A, int i,int j,int size, int **Cofactor);

int get_det(int **M, int n);