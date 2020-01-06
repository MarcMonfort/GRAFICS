#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
out vec4 gfrontColor;

in vec2 vtexCoord[];
out vec2 gtexCoord;

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;
uniform mat3 normalMatrix;

uniform float side = 0.05;

void main( void )
{
	/*for( int i = 0 ; i < 3 ; i++ )
	{
		gfrontColor = vfrontColor[i];
		gl_Position = gl_in[i].gl_Position;
		EmitVertex();
	}*/

	//gtexCoord = vtexCoord[0];

	vec3 V=   (modelViewMatrix * gl_in[0].gl_Position).xyz;   // A = top side
	
	gfrontColor = vfrontColor[0];
	gtexCoord = vec2(0,0);
	gl_Position = projectionMatrix * vec4(V + vec3(-side,-side,0),1);
	EmitVertex();

	gtexCoord = vec2(1,0);
	gl_Position = projectionMatrix * vec4(V + vec3(side,-side,0),1);
	EmitVertex();

	gtexCoord = vec2(0,1);
	gl_Position = projectionMatrix * vec4(V + vec3(-side,side,0),1);
	EmitVertex();

	gtexCoord = vec2(1,1);
	gl_Position = projectionMatrix * vec4(V + vec3(side,side,0),1);
	EmitVertex();


	EndPrimitive();
}
