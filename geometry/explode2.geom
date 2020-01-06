#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
out vec4 gfrontColor;

in vec3 vnormal[];

uniform mat4 modelViewProjectionMatrix;

const float speed = 0.5;
const float angSpeed = 0.8;
uniform float time;

void main( void )
{

	vec3 BT=(gl_in[0].gl_Position.xyz + gl_in[1].gl_Position.xyz + gl_in[2].gl_Position.xyz)/3;

	vec3 A = speed*time*(vnormal[0] + vnormal[1] + vnormal[2])/3.0;

	float a = time*angSpeed;
	mat3 Rz = mat3(vec3(cos(a),sin(a),0),vec3(-sin(a),cos(a),0),vec3(0,0,1));

	for( int i = 0 ; i < 3 ; i++ )
	{
		gfrontColor = vfrontColor[i];
		vec3 V = gl_in[i].gl_Position.xyz-BT;
		V = Rz * V;
		V += BT + A;
		gl_Position = modelViewProjectionMatrix*vec4(V,1);
		EmitVertex();
	}
//EndPrimitive();
	/*for( int i = 0 ; i < 3 ; i++ )
	{
		gfrontColor = vfrontColor[i];
		vec3 V = gl_in[i].gl_Position.xyz;
		gl_Position = modelViewProjectionMatrix*vec4(V,1);
		EmitVertex();
	}*/

    EndPrimitive();
}
