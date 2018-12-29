#pragma once
#define _CRT_SECURE_NO_WARNINGS 0
//#include"graph_store.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 5

//�ԽǾ�������
void dial_inv(int **M); 
//����˷�
void mul(int *A, int *B, double **C); 
//��һ������ת��
void trans(int A[N][N]);
//���������
int inv_num(int M[N]);
//ż������1����������-1
int sign(int t);

//�ݹ�׳�
int fac(int n);

int mul_f(int M[N], int T[N]);

void inv(int A[N][N]);
//��������ʽ
void create_matrix(int** M);
//��ó�i��j�е��Ӿ���
void get_submatrix_by_i_j(int **A, int i,int j,int size, int **Cofactor);

int ** get_submatrix_by_i_j(int **A, int i, int j, int size);

//�������ʽ
int get_det(int **M, int n);
//��ȡ��������ʽ
int get_algebraic_cofactor(int **A,int i,int j);

void get_adjoint_matrix(int **A, int size, double **B);

void get_inverse_matrix(int **A,int size,double **B);

void munber_mul_matrix(double **A, int size,double num);

void gen_identity_matrix(double **M, int size);

void substract(double **A, double **B, double **C);

