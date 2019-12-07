#ifndef _MODELINFO2_H
#define _MODELINFO2_H

#include "plugin.h"
#include <QPainter> 
#include <QString>

class ModelInfo2: public QObject, public Plugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "Plugin") 
	Q_INTERFACES(Plugin)

  public:
	void printInfo();

	 void onPluginLoad();
	 void preFrame();
	 void postFrame();

	 void onObjectAdd();
	 bool drawScene();
	 bool drawObject(int);

	 bool paintGL();

	 void keyPressEvent(QKeyEvent *);
	 void mouseMoveEvent(QMouseEvent *);
  private:
	// add private methods and attributes here
    QPainter painter;
	int nObj, nVtx, nPol, nTri;
	int nVtx_2;
};

#endif