#include "MyGraph.h"
OrthoListGraph::OrthoListGraph()
{
	this->vertCount = 0;
	this->arcCount = 0;
	this->CreateGraph();
}

OrthoListGraph::~OrthoListGraph()
{

}

void OrthoListGraph::CreateGraph()
{
	cout << "请输入顶点个数：" << endl;
	cin >> this->vertCount;

	cout << "请输入边数：" << endl;
	cin >> this->arcCount;

	for (int index = 0; index < this->vertCount; index++)
	{
		cout << "第" << index + 1 << "个顶点的值为：";
		cin >> this->vertNode[index].data;
		this->vertNode[index].firstIn = NULL;
		this->vertNode[index].firstOut = NULL;
	}

	CreateArc();

	cout << "完事儿" << endl;
}

void OrthoListGraph::CreateArc()
{
	OrthoArc* arc1 = NULL;

	OrthoArc* temper = NULL;

	int vi = -1;
	int vj = -1;

	for (int index = 0; index < this->arcCount; index++)
	{
		cout << "请输入边(Vi,Vj).i,j>=0,i!=j." << endl;
		cin >> vi >> vj;
		arc1 = (OrthoArc *)malloc(sizeof(OrthoArc));
		arc1->headVex = vj;
		arc1->headLink = NULL;
		arc1->tailVex = vi;
		arc1->tailLink = NULL;

		if (this->vertNode[vi].firstOut)
		{
			temper = this->vertNode[vi].firstOut;
			while (temper->tailLink)
			{
				temper = temper->tailLink;
			}
			temper->tailLink = arc1;
		}
		else
		{
			this->vertNode[vi].firstOut = arc1;
		}

		if (this->vertNode[vj].firstIn)
		{
			temper = this->vertNode[vj].firstIn;
			while (temper->headLink)
			{
				temper = temper->headLink;
			}
			temper->headLink = arc1;
		}
		else
		{
			this->vertNode[vj].firstIn = arc1;
		}
	}
}

int OrthoListGraph::LocateVex(OrthoVert vert)
{
	return 0;
}

OrthoVert OrthoListGraph::GetVex(int index)
{
	return OrthoVert();
}

void OrthoListGraph::PutVex(int index, OrthoVert vert)
{
}

void OrthoListGraph::DFSTraverse()
{
}

void OrthoListGraph::HFSTraverse()
{
}
