#include "animateVerticesPlugin.h"
#include "glwidget.h"

void AnimateVerticesPlugin::onPluginLoad()
{
	GLWidget &g = *glwidget();
    g.makeCurrent();
    // Resize to power-of-two viewport

    // Carregar shader, compile & link 
    vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
    vs->compileSourceFile(glwidget()->getPluginPath()+"/../iluminacioFragmentShader/animate-vertices1.vert");
    //cout << "vs" << endl;

    fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
    fs->compileSourceFile(glwidget()->getPluginPath()+"/../iluminacioFragmentShader/animate-vertices1.frag");
    //cout << "fs" << endl;

    program = new QOpenGLShaderProgram(this);
    program->addShader(vs);
    program->addShader(fs);
    program->link();
    if (!program->isLinked()) cout << "Shader link error --------------------" << endl; 

	elapsedTimer.start();
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), glwidget(), SLOT(updateGL()));
	timer->start();
}

void AnimateVerticesPlugin::preFrame()
{
	program->bind();
	
	QMatrix4x4 MVP = camera()->projectionMatrix() * camera()->viewMatrix();
	program->setUniformValue("modelViewProjectionMatrix", MVP); 

	QMatrix3x3 NM=camera()->viewMatrix().normalMatrix();
	program->setUniformValue("normalMatrix", NM);  
	
	program->setUniformValue("time", float(elapsedTimer.elapsed()/1000.0f));
	//cout << "tiempo: " << float(elapsedTimer.elapsed()/1000.0f) << endl;

	//program->setUniformValue("amplitude", float(0.5));
	//program->setUniformValue("freq", float(1.5));
}

void AnimateVerticesPlugin::postFrame()
{
	program->release();
}


