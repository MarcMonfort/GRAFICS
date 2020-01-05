#include "boundingBoxCapsaUnitaria.h"
#include "glwidget.h"

void BoundingBoxCapsaUnitaria::onPluginLoad()
{
   glwidget()->makeCurrent();

  // Carrega shader, compila i munta
  vs = new QOpenGLShader(QOpenGLShader::Vertex, this);
  vs->compileSourceFile("boundingBox.vert");

  fs = new QOpenGLShader(QOpenGLShader::Fragment, this);
  fs->compileSourceFile("boundingBox.frag");

  program = new QOpenGLShaderProgram(this);
  program->addShader(vs);
  program->addShader(fs);
  program->link();
}

void BoundingBoxCapsaUnitaria::preFrame()
{
	
}

void BoundingBoxCapsaUnitaria::postFrame()
{
	GLWidget &g = *glwidget();

  program->bind();
  program->setUniformValue("mvp",
                           camera()->projectionMatrix() *
                           camera()->viewMatrix());
  
  // Genera la caixa englobat
  cleanUp();
  createBox();//capsa unitaria

  Box   bBox = scene()->objects()[0].boundingBox(); // com només hi ha un esta a la posicio 0
    	float xmin = bBox.min().x();
    	float xmax = bBox.max().x();
    	float ymin = bBox.min().y();
    	float ymax = bBox.max().y();
    	float zmin = bBox.min().z();
    	float zmax = bBox.max().z();


	//calcula lscale
	float sx = (xmax - xmin) / 1.0; //1 perque la capsa es unitaria, max = 1 i min = 0
	float sy = (ymax - ymin) / 1.0;
	float sz = (zmax - zmin) / 1.0;
	
	//calcula la translacio
	float tx = (xmax + xmin)/2.0 - ((1.0 + 0.0)/2.0) * sx;
	float ty = (ymax + ymin)/2.0 - ((1.0 + 0.0)/2.0) * sy;
	float tz = (zmax + zmin)/2.0 - ((1.0 + 0.0)/2.0) * sz;

	program->setUniformValue("sx", sx); 
	program->setUniformValue("sy", sy); 
	program->setUniformValue("sz", sz); 

	program->setUniformValue("tx", tx); 
	program->setUniformValue("ty", ty); 
	program->setUniformValue("tz", tz); 
	
  // Crea VAO de la caixa englobant
  GLuint VAO;
  g.glGenVertexArrays(1, &VAO);
  g.glBindVertexArray(VAO);

  // Crea VBO de geometria
  GLuint coordBufferID; 
  g.glGenBuffers(1, &coordBufferID);
  g.glBindBuffer(GL_ARRAY_BUFFER, coordBufferID); 
  g.glBufferData(GL_ARRAY_BUFFER, sizeof(float)*vertices.size(), 
                 &vertices[0], GL_STATIC_DRAW);
  g.glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
  g.glEnableVertexAttribArray(0);

  // Crea buffer d'IDs
  GLuint indexBufferID;
  g.glGenBuffers(1, &indexBufferID);
  g.glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
  g.glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*indices.size(),
                 &indices[0], GL_STATIC_DRAW);

  // El VAO ha estat definit
  g.glBindVertexArray(0);

  // Dibuxa el VAO de la caixa englobat
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//si fico fill pinta les cares senceres, no només els fils o bordes
  g.glBindVertexArray(VAO);
  g.glDrawElements(GL_TRIANGLES, indices.size(), 
                   GL_UNSIGNED_INT, (GLvoid*) 0); 
  g.glBindVertexArray(0);

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void BoundingBoxCapsaUnitaria::onObjectAdd()
{
	
}

bool BoundingBoxCapsaUnitaria::drawScene()
{
	return false; // return true only if implemented
}

bool BoundingBoxCapsaUnitaria::drawObject(int)
{
	return false; // return true only if implemented
}

bool BoundingBoxCapsaUnitaria::paintGL()
{
	return false; // return true only if implemented
}

void BoundingBoxCapsaUnitaria::keyPressEvent(QKeyEvent *)
{
	
}

void BoundingBoxCapsaUnitaria::mouseMoveEvent(QMouseEvent *)
{
	
}

void BoundingBoxCapsaUnitaria::cleanUp()
{
  
/*
  GLWidget &g = *glwidget();
  g.glDeleteBuffers(coordBufferID.size(),  &coordBufferID[0]);
  g.glDeleteBuffers(normalBuffers.size(), normalBuffers[0]);
  g.glDeleteBuffers(indexBufferID.size(),  &indexBufferID[0]);
  g.glDeleteBuffers(colorBuffers.size(),  &colorBuffers[0]);
  g.glDeleteVertexArrays(VAO.size(), &VAO[0]);
*/

  vertices.clear();
  indices.clear();
}
void BoundingBoxCapsaUnitaria::createBox()
{
/*
    Box   bBox = scene()->objects()[0].boundingBox(); // com només hi ha un esta a la posicio 0
    float xmin = bBox.min().x();
    float xmax = bBox.max().x();
    float ymin = bBox.min().y();
    float ymax = bBox.max().y();
    float zmin = bBox.min().z();
    float zmax = bBox.max().z();
*/

    // v1
    vertices.push_back(0);
    vertices.push_back(0);
    vertices.push_back(0);
    // v2
    vertices.push_back(1);
    vertices.push_back(0);
    vertices.push_back(0);
    // v3
    vertices.push_back(1);
    vertices.push_back(1);
    vertices.push_back(0);
    // v4
    vertices.push_back(0);
    vertices.push_back(1);
    vertices.push_back(0);
    // v5
    vertices.push_back(0);
    vertices.push_back(0);
    vertices.push_back(1);
    // v6
    vertices.push_back(1);
    vertices.push_back(0);
    vertices.push_back(1);
    // v7
    vertices.push_back(1);
    vertices.push_back(1);
    vertices.push_back(1);
    // v8
    vertices.push_back(0);
    vertices.push_back(1);
    vertices.push_back(1);

    // t1
    indices.push_back(0); // els vertex pels quals estan formades les cares, els index son els de l'ordre de dalt
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
