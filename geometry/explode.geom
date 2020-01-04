#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
out vec4 gfrontColor;

in vec3 vnormal[];

uniform mat4 modelViewProjectionMatrix;

const float speed = 0.5;
uniform float time;

void main( void )
{
	vec3 A = speed*time*(vnormal[0] + vnormal[1] + vnormal[2])/3.0;
	

	for( int i = 0 ; i < 3 ; i++ )
	{
		gfrontColor = vfrontColor[i];
		vec3 V = gl_in[i].gl_Position.xyz + A;
		gl_Position = modelViewProjectionMatrix*vec4(V,1);
		EmitVertex();
	}
    EndPrimitive();
}
