#include "iluminacioFragmentShader.h"
#include "glwidget.h"

void IluminacioFragmentShader::onPluginLoad()
{
/*
	GLWidget &g = *glwidget();
	g.makeCurrent();

	vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
	vs->compileSourceCode(glwidget()->getPluginPath()+"../auto-rotate.vert");
	//cout << "VS log: hhhhhhhhhhhhhhhhhhhhhhhhhh" << vs->log().toStdString() << endl;

	fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
	fs->compileSourceCode(glwidget()->getPluginPath()+"../auto-rotate.frag");

	program = new QOpenGLShaderProgram(this);
	program->addShader(vs);
	program->addShader(fs);
	program->link();
	//cout << "Link log:" << program->log().toStdString() << endl;

	elapsedTimer.start();
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), glwidget(), SLOT(updateGL()));
	timer->start();*/



    GLWidget &g = *glwidget();
    g.makeCurrent();
    // Resize to power-of-two viewport

    // Carregar shader, compile & link 
    vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
    vs->compileSourceFile(glwidget()->getPluginPath()+"/../iluminacioFragmentShader/lighting4.vert");
    //cout << "vs" << endl;

    fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
    fs->compileSourceFile(glwidget()->getPluginPath()+"/../iluminacioFragmentShader/lighting4.frag");
    //cout << "fs" << endl;

    program = new QOpenGLShaderProgram(this);
    program->addShader(vs);
    program->addShader(fs);
    program->link();
    if (!program->isLinked()) cout << "Shader link error --------------------" << endl; 

}

void IluminacioFragmentShader::preFrame()
{
	program->bind();
	//program->setUniformValue("n", 6);
	
	/*QMatrix4x4 MVP = camera()->projectionMatrix() * camera()->viewMatrix();
	program->setUniformValue("modelViewProjectionMatrix", MVP); 

	QMatrix4x4 MV = camera()->viewMatrix();
	program->setUniformValue("modelViewMatrix", MV); 

	QMatrix3x3 NM=camera()->viewMatrix().normalMatrix();
	program->setUniformValue("normalMatrix", NM);  
	
	program->setUniformValue("time", float(elapsedTimer.elapsed()/1000.0f));*/
	//cout << "tiempo: " << float(elapsedTimer.elapsed()/1000.0f) << endl;

	//program->setUniformValue("amplitude", float(0.5));
	//program->setUniformValue("freq", float(1.5));

	const Camera* cam=camera();
    program->setUniformValue("modelViewProjectionMatrix", cam->projectionMatrix()*cam->viewMatrix());
    program->setUniformValue("modelViewMatrix", cam->viewMatrix());
    program->setUniformValue("normalMatrix", cam->viewMatrix().normalMatrix());
    //lightAmbient = Vector(0.1,0.1,0.1);
    //lightDiffuse = Vector(1,1,1);
    //lightSpecular = Vector(1,1,1);
    //lightPosition = QVector4D(0,0,0,1);
    program->setUniformValue("lightAmbient", QVector4D(Vector(0.1,0.1,0.1),1));
    program->setUniformValue("lightDiffuse", QVector4D(Vector(1,1,1),1));
    program->setUniformValue("lightSpecular", QVector4D(Vector(1,1,1),1));
    program->setUniformValue("lightPosition", QVector4D(0,0,0,1));
    //materialAmbient = Vector(0.8, 0.8, 0.6);
    //materialDiffuse = Vector(0.8, 0.8, 0.6);
    //materialSpecular = Vector(1.0, 1.0, 1.0);
    //materialShininess = 64.0;
    program->setUniformValue("matAmbient", QVector4D(Vector(0.8, 0.8, 0.6),1));
    program->setUniformValue("matDiffuse", QVector4D(Vector(0.8, 0.8, 0.6),1));
    program->setUniformValue("matSpecular", QVector4D(Vector(1.0, 1.0, 1.0),1));
    program->setUniformValue("matShininess", GLfloat(64.0));
	

}

void IluminacioFragmentShader::postFrame()
{
	program->release();
}



