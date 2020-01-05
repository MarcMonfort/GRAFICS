#ifndef _SELECCIO_PER_RATOLI_H
#define _SELECCIO_PER_RATOLI_H

#include "plugin.h"

#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <vector>
#include "glwidget.h"
/*
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
*/

class SeleccioPerRatoli : public QObject, Plugin
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "Plugin")   
  Q_INTERFACES(Plugin)

  public:
    void postFrame();     // Q_DECL_OVERRIDE;
    void onPluginLoad();  // Q_DECL_OVERRIDE;
    //void drawPlugin();
  
  protected:
    //  virtual void keyPressEvent     (QKeyEvent *e);
    virtual void mousePressEvent   (QMouseEvent *e );
    virtual void mouseReleaseEvent (QMouseEvent *e );

  private:
    QOpenGLShaderProgram* program;
    QOpenGLShader* vs;
    QOpenGLShader* fs;

    void creaCaixaUnitaria();
    void ompleVAOCaixa();
    void dibuixaCaixaEnglobant();
    void encodeID();
    
    float cu_xmin, cu_xmax;
    float cu_ymin, cu_ymax;
    float cu_zmin, cu_zmax;
    float ccu_x, ccu_y, ccu_z;

    GLuint VAO;
    GLuint VBO_coord, VBO_normals, VBO_indexs;

    int xClick, yClick;
    int objSelected;

    float color[3];
    
    vector<float> vertices;
    vector<float> normals;
    vector<unsigned int> indices;
};
#endif
