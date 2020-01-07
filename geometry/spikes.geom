#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

in vec4 vfrontColor[];
out vec4 gfrontColor;

uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat3 normalMatrix;

in vec3 vnormal[];

uniform float disp =0.05;



void main( void )
{

	vec3 BT = (gl_in[0].gl_Position.xyz + gl_in[1].gl_Position.xyz + gl_in[2].gl_Position.xyz)/3;
	//vec3 N = (vnormal[0] + vnormal[1] + vnormal[2])/3;
	
	//NORMAL con cross
	vec3 V1=(gl_in[0].gl_Position).xyz;
	vec3 V2=(gl_in[1].gl_Position).xyz;
	vec3 V3=(gl_in[2].gl_Position).xyz;

	vec3 U=V1-V3;
	vec3 V=V2-V3;
	vec3 N = normalize(cross(U,  V));
	vec3 N2 = (normalMatrix * N);	//para color, pero ineficiente
	//HASTA AQUI


	
	for( int i = 0 ; i < 3 ; i++ )
	{
		gfrontColor = vfrontColor[i]*N2.z;
		gl_Position = modelViewProjectionMatrix * gl_in[i].gl_Position;
		EmitVertex();
	}	

    EndPrimitive();

	//N = normalize(N);

	//vec3 a = BT+vec3(1,1,1)*N;//N*disp;
	vec3 a = BT + N * disp ;


	gfrontColor = vfrontColor[0]*N2.z;
	gl_Position = modelViewProjectionMatrix * gl_in[0].gl_Position;
	EmitVertex();

	gfrontColor = vfrontColor[1]*N2.z;
	gl_Position = modelViewProjectionMatrix * gl_in[1].gl_Position;
	EmitVertex();

	gfrontColor = vec4(1);
	gl_Position = modelViewProjectionMatrix * vec4(a,1);
	EmitVertex();

	EndPrimitive();



	gfrontColor = vfrontColor[0]*N2.z;
	gl_Position = modelViewProjectionMatrix * gl_in[0].gl_Position;
	EmitVertex();

	gfrontColor = vfrontColor[2]*N2.z;
	gl_Position = modelViewProjectionMatrix * gl_in[2].gl_Position;
	EmitVertex();

	gfrontColor = vec4(1);
	gl_Position = modelViewProjectionMatrix * vec4(a,1);
	EmitVertex();

	EndPrimitive();



	gfrontColor = vfrontColor[1]*N2.z;
	gl_Position = modelViewProjectionMatrix * gl_in[1].gl_Position;
	EmitVertex();

	gfrontColor = vfrontColor[2]*N2.z;
	gl_Position = modelViewProjectionMatrix * gl_in[2].gl_Position;
	EmitVertex();

	gfrontColor = vec4(1);
	gl_Position = modelViewProjectionMatrix * vec4(a,1);
	EmitVertex();

	EndPrimitive();

	
}
