#ifndef _VISIT_H
#define _VISIT_H

#include "plugin.h" 

class Visit: public QObject, public Plugin
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "Plugin") 
	Q_INTERFACES(Plugin)

  public:
	 void onPluginLoad();
	 void onObjectAdd();
	 void keyPressEvent(QKeyEvent *);
  private:
	// add private methods and attributes here
	void info();
};

#endif
