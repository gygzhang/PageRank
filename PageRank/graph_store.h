#pragma once
#define _CRT_SECURE_NO_WARNINGS 0
#include<stdio.h>
#include<iostream>
using namespace std;
#define INT_MAX _CRT_INT_MAX
#define MAX_VERTEX_NUM 20

#define N 8

//数组的方式
typedef enum { DG, DN, UDG, UDN }GraphKind;
typedef void* InfoType;
typedef double VertexTpye;
typedef int  VRType;
typedef struct ArcCell {
	VRType adj;
	InfoType info;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct {
	VertexTpye vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum, arcnum;
	GraphKind kind;
}MGraph;

typedef struct ArcNode {
	int adjvex;
	int weight;
	struct ArcNode*nextarc;
	InfoType *info;
}ArcNode;
typedef struct VNode {
	VertexTpye data;
	ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
	int kind;
}ALGraph;

typedef struct QQueue {
	double *data;
	int front, rear;
};

void InitQueue(QQueue* Q);

void EnQueue(QQueue* Q, double data);

void DeQueue(QQueue *Q, double *v);

bool QueueIsEmpty(QQueue Q);
int LOC(MGraph G, double a);

int LOC(ALGraph G, double a);

ArcNode* GetTail(ArcNode *AD);

void CreateUDN(ALGraph *G);



void CreateDN(ALGraph *G);

void CreateDG(ALGraph *G);

void CreateUDG(MGraph *G);

void CreateDN(MGraph *G);
/*
6 16
1 2 3 4 5 6
1 2 1
1 4 1
1 5 1
2 3 1
2 4 1
3 2 1
3 5 1
3 4 1
3 6 1
4 5 1
5 1 1
5 2 1
5 3 1
5 4 1
5 6 1
6 2 1
6 3 1
0 0 0
*/
void CreateGraph(MGraph *G);

void Print(double v);
//bool visited[20];
//void(*V) (double v);

double FristAdjVex(MGraph G, double v);
double NextAdjVex(MGraph G, double v, double w);

void DFS(MGraph G, double v);

void DFSTraverse(MGraph G, void(*visit)(double v));
void BFSTraverse(MGraph G, void(*visit)(double v));

void BFSTraverse(ALGraph AG, void(*visit)(double v));

void DFS(ALGraph AG, double a);

void DFSTraverse(ALGraph AG, void(*visit)(double v));


/*
3 2
1 2 3
1 2 44
1 3 66
*/
/*
4 6
7 4 6 5
6 5 11
5 6 33
7 5 88
7 4 99
4 7 10
6 4 58
0 0 0
*/

/*
10 13
7 5 4 6 8 1 9 2 3 0
7 5 11
5 6 12
6 5 13
6 9 14
9 6 15
9 1 16
6 4 17
4 8 18
4 7 19
7 4 20
8 2 21
2 3 22
3 0 23
0 0 0
*/

/*
3 2
1 2 3
1 2
1 3
0 0
0 0
0 0
*/

/*
4 4
1 2 3 4
1 2
2 1
1 3
3 4
2 4
0 0
0 0
0 0
*/

/*
10 12
7 5 4 6 8 9 2 1 3 0
7 5 10
7 4 11
4 7 12
5 6 13
6 5 14
9 6 15
6 9 16
9 1 17
4 8 18
8 2 19
2 3 20
1 0 21
0 1 22
3 0 23
0 0 0
*/

/*int main() {
	MGraph G;
	ALGraph AG;
	//CreateDN(&AG);
	//CreateUDN(&G);
	CreateDN(&G);
	DFSTraverse(G, Print);
	//cout << endl;
	//BFSTraverse(G, Print);
	//DFSTraverse(AG, Print);
	system("pause");
}*/