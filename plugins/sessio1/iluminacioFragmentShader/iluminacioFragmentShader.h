#ifndef _ILUMINACIOFRAGMENTSHADER_H
#define _ILUMINACIOFRAGMENTSHADER_H

#include "plugin.h" 
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>


class IluminacioFragmentShader: public QObject, public Plugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "Plugin") 
	Q_INTERFACES(Plugin)

  public:
	 void onPluginLoad();
	 void preFrame();
	 void postFrame();

	 
  private:
	// add private methods and attributes here
	QOpenGLShaderProgram* program;
	QOpenGLShader *fs, *vs; 

};

#endif
