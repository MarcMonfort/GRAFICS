#include "showDegree.h"
#include "glwidget.h"

void ShowDegree::onPluginLoad()
{
	Scene* scn = scene();



	const Object &obj = scene()->objects()[0];
	const vector<Vertex> &ver = obj.vertices();
  	int cnt[ver.size()];
  	memset(cnt, 0, sizeof cnt);

	  // do count
	  for (int i=0; i<(int)obj.faces().size(); ++i) {
	    const Face &face=obj.faces()[i];
	    for (int j=0; j<face.numVertices(); ++j)
	      ++cnt[face.vertexIndex(j)];
	  }

	  double t=0;
	  for (int i=0; i<(int)ver.size(); ++i) t+=cnt[i];
	  grau_mig=t/ver.size();

	
}

void ShowDegree::preFrame()
{
	
}

void ShowDegree::postFrame()
{
	QFont font;
  font.setPixelSize(32);
  painter.begin(glwidget());
  painter.setFont(font);
  int x = 15;
  int y = 40;


	//QString s = "Numero objectes: " + QString::number(grau_mig);
	painter.drawText(x, y, QString("%1").arg(grau_mig));  
	
  painter.end();
}

void ShowDegree::onObjectAdd()
{
	
}

bool ShowDegree::drawScene()
{
	return false; // return true only if implemented
}

bool ShowDegree::drawObject(int)
{
	return false; // return true only if implemented
}

bool ShowDegree::paintGL()
{
	return false; // return true only if implemented
}

void ShowDegree::keyPressEvent(QKeyEvent *)
{
	
}

void ShowDegree::mouseMoveEvent(QMouseEvent *)
{
	
}

