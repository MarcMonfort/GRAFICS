#include "animateVerticesPlugin.h"
#include "glwidget.h"

void AnimateVerticesPlugin::onPluginLoad()
{
	QString vs_src =
      "#version 330 core"

"layout (location = 0) in vec3 vertex;	//object space"
"layout (location = 1) in vec3 normal;	//object space"
"layout (location = 2) in vec3 color;"
"layout (location = 3) in vec2 texCoord;"

"out vec4 frontColor;"
"out vec2 vtexCoord;"

"uniform mat4 modelViewProjectionMatrix;"
"uniform mat3 normalMatrix;"

"uniform float time;"
"uniform float amplitude = 0.1;"
"uniform float freq = 1;"

"const float PI = 3.141592;"

"void main()"
"{"
"	vec3 V = vertex + normal*abs(amplitude*sin(2*PI*freq*time+0));	//abs evita ir hacia atras"
 "   vec3 N = normalize(normalMatrix * normal);"
"	frontColor=vec4(vec3(N.z),1);"

"    gl_Position = modelViewProjectionMatrix * vec4(V, 1.0);	//esto transforma el vertex de" "object a clip"
"}";










	vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
	vs->compileSourceCode(vs_src);
	cout << "VS log:" << vs->log().toStdString() << endl;

	QString fs_src =
      "#version 330 core\n"
      "out vec4 fragColor;"
      "void main() {"
      "  fragColor = frontColor;"
      "}";

	fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
	fs->compileSourceCode(fs_src);
	cout << "FS log:" << fs->log().toStdString() << endl;

	program = new QOpenGLShaderProgram(this);
    program->addShader(vs);
    program->addShader(fs);
    program->link();

	elapsedTimer.start();
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), glwidget(), SLOT(updateGL()));
	timer->start();

	
    cout << "Link log:" << program->log().toStdString() << endl;
	
}

void AnimateVerticesPlugin::preFrame()
{
	    program->bind();
    QMatrix4x4 MVP = camera()->projectionMatrix() * camera()->viewMatrix();
    program->setUniformValue("modelViewProjectionMatrix", MVP); 
	
	QMatrix3x3 NM=camera()->viewMatrix().normalMatrix();
	program->setUniformValue("normalMatrix", NM);  

	program->setUniformValue("time", float(elapsedTimer.elapsed()/1000.0f));
}

void AnimateVerticesPlugin::postFrame()
{
	program->release();
}


