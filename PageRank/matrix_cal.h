#pragma once
#define _CRT_SECURE_NO_WARNINGS 0
//#include"graph_store.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 8

//�ԽǾ�������
void dial_inv(double **M); 
//����˷�
void square_martix_mul(double *A, double *B, double **C); 
//��һ������ת��
void trans(double **A);
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
void get_submatrix_by_i_j(double **A, int i,int j,int size, double **Cofactor);

//int ** get_submatrix_by_i_j(double **A, int i, int j, int size);

//�������ʽ
int get_det(double **M, int n);
//��ȡ��������ʽ
int get_algebraic_cofactor(double **A,int i,int j);

void get_adjoint_matrix(double **A, int size, double **B);

void get_inverse_matrix(double **A,int size,double **B);

void munber_mul_matrix(double **A, int size,double num);

void gen_identity_matrix(double **M, int size);

void substract(double **A, double **B, double **C);

void comm_matrix_mul(double** A,int m,int r,int n,double** B,double **C);

