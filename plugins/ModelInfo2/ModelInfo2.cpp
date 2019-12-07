#include "ModelInfo2.h"
#include "glwidget.h"
#include <string>
#include <cstdio>


void ModelInfo2::printInfo()
{
	Scene* scn = scene();

	//int nObj, nVtx, nPol, nTri;	

	nObj = scn -> objects().size();
	
	nVtx = nPol = nTri = 0;

	nVtx_2 = 0;
	
	for (int i = 0; i < (int)scn->objects().size(); ++i) {
		
		Object obj = scn->objects()[i];
		nVtx_2 += obj.vertices().size();
		//cout << scn->objects()[i].vertices().size() << endl;
		
		for (int j = 0; j < (int)obj.faces().size(); ++j) {
			Face face = obj.faces()[j];
			int fver = face.numVertices();
			++nPol;
			nVtx += fver;
			nTri += fver==3;
		}
	}

	  printf("Numero objectes: %d\n", nObj);
	  printf("Numero poligons: %d\n", nPol);
	  printf("Numero vertex: %d\n", nVtx);
	  printf("Percentatge triangles: %f\n\n", ((double)nTri)/nPol);
		
	cout << "Malo: " << nVtx_2 << endl;

}

void ModelInfo2::onPluginLoad()
{
	printInfo();
	
}

void ModelInfo2::preFrame()
{
	
}

void ModelInfo2::postFrame()
{
  QFont font;
  font.setPixelSize(32);
  painter.begin(glwidget());
  painter.setFont(font);
  int x = 15;
  int y = 40;


	QString s = "Numero objectes: " + QString::number(nObj);
	QString s1 = "Numero poligons: " + QString::number(nPol);
	QString s2 = "Numero vertex: " + QString::number(nVtx);		
	QString s3 = "Percentatge triangles: " + QString::number((double)nTri/nPol);

	  painter.drawText(x, y, s);  
	  painter.drawText(x, y+30, s1);  
	  painter.drawText(x, y+60, s2);  
	  painter.drawText(x, y+90, s3);  

  painter.end();
	
}

void ModelInfo2::onObjectAdd()
{
	printInfo();
	
}

bool ModelInfo2::drawScene()
{
	return false; // return true only if implemented
}

bool ModelInfo2::drawObject(int)
{
	return false; // return true only if implemented
}

bool ModelInfo2::paintGL()
{
	return false; // return true only if implemented
}

void ModelInfo2::keyPressEvent(QKeyEvent *)
{
	
}

void ModelInfo2::mouseMoveEvent(QMouseEvent *)
{
	
}

