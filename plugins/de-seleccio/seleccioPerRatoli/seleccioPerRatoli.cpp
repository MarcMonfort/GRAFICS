
#include "seleccioPerRatoli.h"

#include <stdio.h>

void SeleccioPerRatoli::onPluginLoad()
{
  
  glwidget()->makeCurrent();
  
  objSelected = -1;

  // Carrega compila i munta shaders
  vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
  vs->compileSourceFile("seleccioPerRatoli.vert");  

  fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
  fs->compileSourceFile("seleccioPerRatoli.frag");

  program = new QOpenGLShaderProgram(this);
  program->addShader(vs);
  program->addShader(fs);
  program->link();

  // Transferencia de les matrius que no canvien
  program->bind();
  program->setUniformValue("modelViewProjectionMatrix", 
                           camera()->projectionMatrix()*camera()->viewMatrix());
  
  program->setUniformValue("pas", 1);
    
  // Crea el VAO amb caixa unitaria
  creaCaixaUnitaria();
  ompleVAOCaixa();
}

void SeleccioPerRatoli::creaCaixaUnitaria()
{
   /*
   cu_xmin = -0.50, cu_xmax = 0.5;
   cu_ymin = -0.50, cu_ymax = 0.5;
   cu_zmin = -0.50, cu_zmax = 0.5;
   */
   cu_xmin = 0, cu_xmax = 1;
   cu_ymin = 0, cu_ymax = 1;
   cu_zmin = 0, cu_zmax = 1;

   // centre caixa unitaria
   ccu_x = (cu_xmax + cu_xmin)/2.0;
   ccu_y = (cu_ymax + cu_ymin)/2.0;
   ccu_z = (cu_zmax + cu_zmin)/2.0;
   
   // v1
   vertices.push_back(cu_xmin);
   vertices.push_back(cu_ymin);
   vertices.push_back(cu_zmin);
   // v2
   vertices.push_back(cu_xmax);
   vertices.push_back(cu_ymin);
   vertices.push_back(cu_zmin);
   // v3
   vertices.push_back(cu_xmax);
   vertices.push_back(cu_ymax);
   vertices.push_back(cu_zmin);
   // v4
   vertices.push_back(cu_xmin);
   vertices.push_back(cu_ymax);
   vertices.push_back(cu_zmin);
   // v5
   vertices.push_back(cu_xmin);
   vertices.push_back(cu_ymin);
   vertices.push_back(cu_zmax);
   // v6
   vertices.push_back(cu_xmax);
   vertices.push_back(cu_ymin);
   vertices.push_back(cu_zmax);
   // v7
   vertices.push_back(cu_xmax);
   vertices.push_back(cu_ymax);
   vertices.push_back(cu_zmax);
   // v8
   vertices.push_back(cu_xmin);
   vertices.push_back(cu_ymax);
   vertices.push_back(cu_zmax);

   // t1
   indices.push_back(0);
   indices.push_back(1);
   indices.push_back(2);
   // t2
   indices.push_back(0);
   indices.push_back(2);
   indices.push_back(3);
   // t3
   indices.push_back(0);
   indices.push_back(1);
   indices.push_back(4);
   // t4
   indices.push_back(1);
   indices.push_back(4);
   indices.push_back(5);
   // t5
   indices.push_back(1);
   indices.push_back(2);
   indices.push_back(5);
   // t6
   indices.push_back(2);
   indices.push_back(5);
   indices.push_back(6);
   // t7
   indices.push_back(2);
   indices.push_back(3);
   indices.push_back(6);
   // t8
   indices.push_back(3);
   indices.push_back(6);
   indices.push_back(7);
   // t9
   indices.push_back(3);
   indices.push_back(0);
   indices.push_back(7);
   // t10
   indices.push_back(0);
   indices.push_back(7);
   indices.push_back(4);
   // t11
   indices.push_back(4);
   indices.push_back(5);
   indices.push_back(6);
   // t12
   indices.push_back(4);
   indices.push_back(6);
   indices.push_back(7);
}


void SeleccioPerRatoli::ompleVAOCaixa()
{
  glwidget()->makeCurrent();

  GLWidget &g = *glwidget();

  // Crea VAOs de les caixes englobants
  g.glGenVertexArrays(1, &VAO);
  g.glBindVertexArray(VAO);

  // Crea VBO de geometria de la caixa englobant
  g.glGenBuffers(1, &VBO_coord);
  g.glBindBuffer(GL_ARRAY_BUFFER, VBO_coord); 
  g.glBufferData(GL_ARRAY_BUFFER, sizeof(float)*vertices.size(), 
                 &vertices[0], GL_STATIC_DRAW);
  g.glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  g.glEnableVertexAttribArray(0);

  /*
  // Crea VBO de normals
  g.glGenBuffers(1, &BVO_normals);
  g.glBindBuffer(GL_ARRAY_BUFFER, VBO_normals); 
  g.glBufferData(GL_ARRAY_BUFFER, sizeof(float)*normals.size(), 
                 &normals[0], GL_STATIC_DRAW);
  g.glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
  g.glEnableVertexAttribArray(1);
  */

  // Crea buffer d'indexs
  g.glGenBuffers(1, &VBO_indexs);
  g.glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO_indexs);
  g.glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*indices.size(),
                 &indices[0], GL_STATIC_DRAW);

  g.glBindVertexArray(0);
}

void SeleccioPerRatoli::postFrame() 
{

  glwidget()->makeCurrent();

  dibuixaCaixaEnglobant();

}


void SeleccioPerRatoli::dibuixaCaixaEnglobant()
{
  glwidget()->makeCurrent();

  Scene* scn    = scene();
  int nObjectes = scn->objects().size();

// tractament de l'escena
  if( (0 <= objSelected) & (objSelected < nObjectes) )
  {
    GLWidget &g = *glwidget();
    Object& obj  = scn->objects()[objSelected];
    Box     box  = obj.boundingBox();

    // Transforma la caixa unitaria
    // escalat
    float sx = (box.max().x() - box.min().x()) / (cu_xmax - cu_xmin);
    float sy = (box.max().y() - box.min().y()) / (cu_ymax - cu_ymin);
    float sz = (box.max().z() - box.min().z()) / (cu_zmax - cu_zmin);

    // translacio
    float tx = (box.max().x() + box.min().x()) / 2.0 - ccu_x * sx;
    float ty = (box.max().y() + box.min().y()) / 2.0 - ccu_y * sy;
    float tz = (box.max().z() + box.min().z()) / 2.0 - ccu_z * sz;
    
    program->bind();
    
    program->setUniformValue("sx", sx);
    program->setUniformValue("sy", sy);
    program->setUniformValue("sz", sz);

    program->setUniformValue("tx", tx);
    program->setUniformValue("ty", ty);
    program->setUniformValue("tz", tz);

    program->setUniformValue("modelViewProjectionMatrix", 
                             camera()->projectionMatrix()*camera()->viewMatrix());
   
    program->setUniformValue("pas", 4);
    program->setUniformValue("colorPas", QVector3D(0.0, 0.0, 0.0));

  
    /*
    glm::mat4 tg (1.0f);
    tg = glm::scale(tg, glm::vec3(sx, sy, sz));
    tg = glm::translate(tg, glm::vec3(tx, ty, tz));
    program->bind();
    program->setUniformValue("tg", tg);
    */

    //  dibuixaVAO();
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    g.glBindVertexArray(VAO);
    g.glDrawElements(GL_TRIANGLES, indices.size(), 
                     GL_UNSIGNED_INT, (GLvoid*) 0);
    g.glBindVertexArray(0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glwidget()->update();
  }
}


void SeleccioPerRatoli::mousePressEvent (QMouseEvent *event )
{
  glwidget()->makeCurrent();

  xClick = event->x();
  yClick = event->y();
}


void encodeID()
{

}


void SeleccioPerRatoli::mouseReleaseEvent(QMouseEvent *event)
{
  glwidget()->makeCurrent();
  
  if (!(event->button() == Qt::LeftButton)) return;
	if (! (event->modifiers() & Qt::ControlModifier)) return;	//ctrl + click
  
  // Esborrat del frame-buffer i activacio del program
  glClearColor (1.0, 1.0, 1.0, 1.0); // color de fons d'esborrat.
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
  program->bind();

  // Dibuix de l'escena amb un color per a cada objecte
  program->setUniformValue("pas", 2);
  program->setUniformValue("modelViewProjectionMatrix",
			   camera()->projectionMatrix() * camera()->viewMatrix());
  for (unsigned int i = 0; i < scene()->objects().size(); ++i)    
  {
    GLubyte color[4];
 
    //encodeID(i, color);
    color[0] = i;
    color[1] = i;
    color[2] = i;

    program->setUniformValue("colorPas", QVector3D(color[0]/255.0,
                                                   color[1]/255.0,
                                                   color[2]/255.0));	         	  
    drawPlugin()->drawObject(i);
  }     
  
  // Llegir i decodificar el color del buffer de color 
  // del pixel on s'ha fet clic amb el cursor
  //
  GLubyte readColor[4];

  int y = glwidget()->height() - yClick;
  glReadPixels(xClick, y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, readColor);
  objSelected = readColor[0];

  int n = scene()->objects().size();
  if( objSelected < 0 ||  objSelected > n - 1 ) objSelected = -1;
}

