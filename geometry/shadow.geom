#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

uniform mat4 modelViewProjectionMatrix;
uniform vec3 boundingBoxMin;


in vec4 vfrontColor[];
out vec4 gfrontColor;

void main( void )
{
	for( int i = 0 ; i < 3 ; i++ )
	{
		gfrontColor = vfrontColor[i];
		gl_Position = modelViewProjectionMatrix*gl_in[i].gl_Position;
		EmitVertex();
	}
    EndPrimitive();
	for( int i = 0 ; i < 3 ; i++ )
	{
		gfrontColor = vec4(0);
		vec4 aux = vec4(gl_in[i].gl_Position[0],boundingBoxMin.y,gl_in[i].gl_Position[2],1.0);
		gl_Position = modelViewProjectionMatrix*aux;
		EmitVertex();
	}
    EndPrimitive();
}
