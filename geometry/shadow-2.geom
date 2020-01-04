#version 330 core
        
layout(triangles) in;
layout(triangle_strip, max_vertices = 36) out;

uniform mat4 modelViewProjectionMatrix;
uniform vec3 boundingBoxMax;
uniform vec3 boundingBoxMin;

in vec4 vfrontColor[];
out vec4 gfrontColor;

vec4 CYAN = vec4(0, 1, 1, 1);

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
		//vec4 aux = vec4(gl_in[i].gl_Position[0],boundingBoxMin.y,gl_in[i].gl_Position[2],1.0);
		vec4 aux = gl_in[i].gl_Position;
		aux.y = boundingBoxMin.y;
		gl_Position = modelViewProjectionMatrix*aux;
		EmitVertex();
	}
    EndPrimitive();


	if (gl_PrimitiveIDIn == 0) 
	{	
			float R=length(boundingBoxMax-boundingBoxMin)/2;
			vec3 C=(boundingBoxMax+boundingBoxMin)/2;
			float bottom = boundingBoxMin.y - 0.01;
			
			gfrontColor = CYAN;
			vec4 aux = vec4(C.x+R,bottom,C.z+R,1);
			gl_Position = modelViewProjectionMatrix*aux;
			EmitVertex();

			aux = vec4(C.x+R,bottom,C.z-R,1);
			gl_Position = modelViewProjectionMatrix*aux;
			EmitVertex();

			aux = vec4(C.x-R,bottom,C.z+R,1);
			gl_Position = modelViewProjectionMatrix*aux;
			EmitVertex();
		
    			EndPrimitive();


			aux = vec4(C.x-R,bottom,C.z-R,1);
			gl_Position = modelViewProjectionMatrix*aux;
			EmitVertex();

			aux = vec4(C.x+R,bottom,C.z-R,1);
			gl_Position = modelViewProjectionMatrix*aux;
			EmitVertex();

			aux = vec4(C.x-R,bottom,C.z+R,1);
			gl_Position = modelViewProjectionMatrix*aux;
			EmitVertex();
		
    			EndPrimitive();

	}

				
}
