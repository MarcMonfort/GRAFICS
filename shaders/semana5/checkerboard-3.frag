#version 330 core

in vec2 vtexCoord;
out vec4 fragColor;

//const vec4 GREY=vec4(vec3(0.8), 1);
//const vec4 BLACK=vec4(vec3(0), 1);


uniform float n = 8;


void main()
{

	vec4 color;


	float x = n*vtexCoord.s;
	float y = n*vtexCoord.t;
	
	if (fract(x) < 0.1) color = vec4(0);

	if (fract(y) < 0.1) color = vec4(0);
	else if (fract(x)>0.1 && fract(y)>0.1)color = vec4(0.8);	//muy retorcido, mejor como github
	
    fragColor = color;
}

/*	GITHUB
void main() {
  float x=fract(vtexCoord.x*n);
  float y=fract(vtexCoord.y*n);
  if (x>0.1 && y>0.1) fragColor=GREY;
  else fragColor=BLACK;
}

*/




