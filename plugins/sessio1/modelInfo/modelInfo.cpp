#include "modelInfo.h"
#include "glwidget.h"

void ModelInfo::printInfo()
{
	Scene* scn = scene();

	int nObj, nVtx, nPol, nTri;	

	nObj = scn -> objects().size();
	
	nVtx = nPol = nTri = 0;

	int nvtx2 = 0;
	
	for (int i = 0; i < (int)scn->objects().size(); ++i) {
		
		Object obj = scn->objects()[i];
		nVtx += obj.vertices().size();
		//cout << scn->objects()[i].vertices().size() << endl;
		
		for (int j = 0; j < (int)obj.faces().size(); ++j) {
			Face face = obj.faces()[j];
			int fver = face.numVertices();
			++nPol;
			nvtx2 += fver;
			nTri += fver==3;
		}
	}

	  printf("Numero objectes: %d\n", nObj);
	  printf("Numero poligons: %d\n", nPol);
	  printf("Numero vertex: %d\n", nvtx2);
	  printf("Percentatge triangles: %f\n\n", ((double)nTri)/nPol);
		
	cout << "mmm: " << nVtx << endl;

}


void ModelInfo::onPluginLoad()
{
	printInfo();
}

void ModelInfo::preFrame()
{
	
}

void ModelInfo::postFrame()
{	

}

void ModelInfo::onObjectAdd()
{
	printInfo();
	
}

bool ModelInfo::drawScene()
{
	return false; // return true only if implemented
}

bool ModelInfo::drawObject(int)
{
	return false; // return true only if implemented
}

bool ModelInfo::paintGL()
{
	return false; // return true only if implemented
}

void ModelInfo::keyPressEvent(QKeyEvent *)
{
	
}

void ModelInfo::mouseMoveEvent(QMouseEvent *)
{
	
}

