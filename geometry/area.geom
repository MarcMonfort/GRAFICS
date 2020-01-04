#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
out vec4 gfrontColor;

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;

const float areamax = 0.0005;

const vec4 RED = vec4(1,0,0,1);
const vec4 YELLOW = vec4(1,1,0,1);

void main( void )
{

	vec3 V1=(modelViewMatrix*gl_in[0].gl_Position).xyz;
	vec3 V2=(modelViewMatrix*gl_in[1].gl_Position).xyz;
	vec3 V3=(modelViewMatrix*gl_in[2].gl_Position).xyz;

	vec3 U=V1-V3;
	vec3 V=V2-V3;
	float area =length(cross(U, V))/2;  // modul producte vectorial
	area/=areamax;                     // normalitza valor
	
	gfrontColor = mix(RED,YELLOW, (area));

	//if (area >= 1) gfrontColor = YELLOW;	
	for( int i = 0 ; i < 3 ; i++ )
	{
		
		gl_Position = modelViewProjectionMatrix*gl_in[i].gl_Position;
		EmitVertex();
	}
    EndPrimitive();
}
