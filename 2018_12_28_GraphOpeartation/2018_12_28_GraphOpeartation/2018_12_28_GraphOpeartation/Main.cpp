#include "MyGraph.h"
int main()
{
	AdjListGraph ajG = AdjListGraph();
	//OrthoListGraph olG = OrthoListGraph();
	
	ajG.DFSTraverse();
	system("pause");
	return 0;
}