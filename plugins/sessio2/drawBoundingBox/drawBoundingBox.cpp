#include "drawBoundingBox.h"
#include "glwidget.h"

void DrawBoundingBox::onPluginLoad()
{
	 GLfloat cube_vertices[]={
    1, 1, 1,
    0, 1, 1,
    1, 0, 1,
    0, 0, 1,
    1, 0, 0,
    0, 0, 0,
    1, 1, 0,
    0, 1, 0,
    1, 1, 1,
    0, 1, 1,
    0, 1, 1,
    0, 1, 0,
    0, 0, 1,
    0, 0, 0,
    1, 0, 1,
    1, 0, 0,
    1, 1, 1,
    1, 1, 0
  };
  GLfloat cube_colors[]={
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0,
    1, 0, 0
  };


	GLuint VAO;
	g.glGenVertexArrays(1,&VAO);

	GLuint coordBufferID;
	g.glGenBuffers(1, &coordBufferID);

	g.glBindVertexArray(VAO);





  // VAO Capsa



  glGenVertexArrays(1, &cubeVAO);
  glBindVertexArray(cubeVAO);
  // VBOs Capsa
  generate_vbo(verticesVBO, 18*3, &cube_vertices[0], 0, 3);
  generate_vbo(colorVBO, 18*3, &cube_colors[0], 2, 3);
}

void DrawBoundingBox::preFrame()
{
	
}

void DrawBoundingBox::postFrame()
{
	
}

void DrawBoundingBox::onObjectAdd()
{
	
}

bool DrawBoundingBox::drawScene()
{
	return false; // return true only if implemented
}

bool DrawBoundingBox::drawObject(int)
{
	return false; // return true only if implemented
}

bool DrawBoundingBox::paintGL()
{
	return false; // return true only if implemented
}

void DrawBoundingBox::keyPressEvent(QKeyEvent *)
{
	
}

void DrawBoundingBox::mouseMoveEvent(QMouseEvent *)
{
	
}

