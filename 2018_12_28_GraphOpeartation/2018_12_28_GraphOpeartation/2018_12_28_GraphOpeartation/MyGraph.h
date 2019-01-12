#pragma once
#include <iostream>

using namespace std;

#define MAXVERTNUM 20

typedef struct ArcNode
{
	int vertNum;
	ArcNode *next;
}ArcNode;

typedef struct VertNode
{
	char data;
	ArcNode *firstEdge;
}VertNode;

class AdjListGraph
{
public:
	AdjListGraph();
	~AdjListGraph();
	void CreateGraph();
	int LocateVex(VertNode vert);
	VertNode GetVex(int index);
	void PutVex(int index,VertNode vert);
	void DFSTraverse();
	void HFSTraverse();
private:
	VertNode vertArray[MAXVERTNUM];
	int vertCount;
	int arcCount;
	bool isDirectedGraph;
	bool *visited;
	void CreateArc();
	void DFS(int index);
};

typedef struct OrthoArc
{
	int tailVex;
	int headVex;
	OrthoArc *headLink;
	OrthoArc *tailLink;
}OrthoArc;

typedef struct OrthoVert
{
	char data;
	OrthoArc *firstIn;
	OrthoArc *firstOut;
}OrthoVert;

class OrthoListGraph
{
public:
	OrthoListGraph();
	~OrthoListGraph();

	void CreateGraph();
	int LocateVex(OrthoVert vert);
	OrthoVert GetVex(int index);
	void PutVex(int index, OrthoVert vert);
	void DFSTraverse();
	void HFSTraverse();
private:
	OrthoVert vertNode[MAXVERTNUM];
	int vertCount;
	int arcCount;
	bool isDirectedGraph;
	void CreateArc();
};
