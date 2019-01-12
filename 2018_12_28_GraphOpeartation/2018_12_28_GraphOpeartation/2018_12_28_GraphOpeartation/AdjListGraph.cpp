#include "MyGraph.h"

AdjListGraph::AdjListGraph()
{
	this->vertCount = 0;
	this->arcCount = 0;
	this->isDirectedGraph = false;
	this->CreateGraph();
}

AdjListGraph::~AdjListGraph()
{

}

void AdjListGraph::CreateGraph()
{
	cout << "是否是有向图(1,0)：" << endl;
	cin >> this->isDirectedGraph;

	cout << "请输入顶点个数：" << endl;
	cin >> this->vertCount;

	cout << "请输入边数：" << endl;
	cin >> this->arcCount;

	//给访问数组分配空间
	visited = (bool *)malloc(this->vertCount*sizeof(bool));

	for (int index = 0; index < this->vertCount; index++)
	{
		cout << "第" << index + 1 << "个顶点的值为：";
		cin >> this->vertArray[index].data;
		this->vertArray[index].firstEdge = NULL;
	}

	CreateArc();

	cout << "完事儿" << endl;
}

void AdjListGraph::CreateArc()
{
	ArcNode* arc1 = NULL;
	ArcNode* arc2 = NULL;

	ArcNode* temper = NULL;
	ArcNode* temper2 = NULL;

	int vi = -1;
	int vj = -1;

	for (int index=0;index<this->arcCount;index++)
	{
		cout << "请输入边(Vi,Vj).i,j>=0,i!=j." << endl;
		cin >> vi >> vj;
		arc1 = (ArcNode *)malloc(sizeof(ArcNode));
		arc1->vertNum = vj;
		arc1->next = NULL;

		if (!this->isDirectedGraph)
		{
			arc2 = (ArcNode *)malloc(sizeof(ArcNode));
			arc2->vertNum = vi;
			arc2->next = NULL;
		}

		if (this->vertArray[vi].firstEdge)
		{
			temper = this->vertArray[vi].firstEdge;
			while (temper->next)
			{
				temper = temper->next;
			}
			temper->next = arc1;
		}
		else
		{
			this->vertArray[vi].firstEdge = arc1;
		}

		if (!this->isDirectedGraph)
		{
			if (this->vertArray[vj].firstEdge)
			{
				temper2 = this->vertArray[vj].firstEdge;
				while (temper2->next)
				{
					temper2 = temper2->next;
				}
				temper2->next = arc2;
			}
			else
			{
				this->vertArray[vj].firstEdge = arc2;
			}
		}
	}
}


int AdjListGraph::LocateVex(VertNode vert)
{
	return 0;
}

VertNode AdjListGraph::GetVex(int index)
{
	return VertNode();
}

void AdjListGraph::PutVex(int index, VertNode vert)
{
}

void AdjListGraph::DFS(int index)
{
	ArcNode *temper = NULL;

	temper = this->vertArray[index].firstEdge;
	cout << this->vertArray[index].data;
	visited[index] = true;
	
	while (temper)
	{
		if (!visited[temper->vertNum])
		{
			DFS(temper->vertNum);
		}
		temper = temper->next;
	}
}

void AdjListGraph::DFSTraverse()
{
	for (int index=0;index<this->vertCount;index++)
	{
		visited[index] = false;
	}

	for (int index = 0; index < this->vertCount; index++)
	{
		if (!visited[index])
		{
			DFS(index);
		}
	}
}

void AdjListGraph::HFSTraverse()
{
}
