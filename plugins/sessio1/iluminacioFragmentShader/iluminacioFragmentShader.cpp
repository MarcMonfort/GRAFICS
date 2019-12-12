#include "iluminacioFragmentShader.h"
#include "glwidget.h"

void IluminacioFragmentShader::onPluginLoad()
{
	vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
    vs->compileSourceCode("/home/marc/UNI/NewViewer_52d9d92/plugins/iluminacioFragmentShader/lighting4.vert");
    cout << "VS log:" << vs->log().toStdString() << endl;
	fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
    fs->compileSourceCode("/home/marc/UNI/NewViewer_52d9d92/plugins/iluminacioFragmentShader/lighting4.frag");
	program = new QOpenGLShaderProgram(this);
    program->addShader(vs);
    program->addShader(fs);
    program->link();
    cout << "Link log:" << program->log().toStdString() << endl;
}

void IluminacioFragmentShader::preFrame()
{
	
}

void IluminacioFragmentShader::postFrame()
{
	
}

void IluminacioFragmentShader::onObjectAdd()
{
	
}

bool IluminacioFragmentShader::drawScene()
{
	return false; // return true only if implemented
}

bool IluminacioFragmentShader::drawObject(int)
{
	return false; // return true only if implemented
}

bool IluminacioFragmentShader::paintGL()
{
	return false; // return true only if implemented
}

void IluminacioFragmentShader::keyPressEvent(QKeyEvent *)
{
	
}

void IluminacioFragmentShader::mouseMoveEvent(QMouseEvent *)
{
	
}

