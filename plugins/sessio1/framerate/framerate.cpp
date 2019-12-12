#include "framerate.h"
#include "glwidget.h"

void Framerate::onPluginLoad()
{
	timer.start();
	
}

void Framerate::preFrame()
{
	timer.start();
	//cout << " hola " << timer.elapsed() << endl;
}

void Framerate::postFrame()
{
	for (double i =0 ; i< 100000000; ++i) {
		int a  = 3*3;
		int b  = a*3;
	}
	cout << " hola " << timer.elapsed() << endl;
//	timer.start();
}

void Framerate::onObjectAdd()
{
	
}

bool Framerate::drawScene()
{
	return false; // return true only if implemented
}

bool Framerate::drawObject(int)
{
	return false; // return true only if implemented
}

bool Framerate::paintGL()
{
	return false; // return true only if implemented
}

void Framerate::keyPressEvent(QKeyEvent *)
{
	
}

void Framerate::mouseMoveEvent(QMouseEvent *)
{
	
}

