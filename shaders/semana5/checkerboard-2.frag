#version 330 core

in vec2 vtexCoord;
out vec4 fragColor;

const vec4 GREY=vec4(vec3(0.8), 1);
const vec4 BLACK=vec4(vec3(0), 1);


uniform float n = 8;




//bueno, github
void main()
{
	float slice=1.0/n;
  	int x = int(mod(vtexCoord.x / slice, 2));
  	int y = int(mod(vtexCoord.y / slice, 2));
  	if (x == y) fragColor=GREY;
  	else fragColor=BLACK;

	//usar opcion de checkboard-1 para no saltar copia (GITHUB)

}

/* FORMA EXTRA
void main()
{
	vec4 color;


	float x = n*vtexCoord.s;
	float y = n*vtexCoord.t;
	
	color = vec4(0);
	if (fract(x) < 0.5 && fract(y) < 0.5) color = vec4(0.8);
	else if (fract(x) > 0.5 && fract(y) > 0.5) color = vec4(0.8);

	
    fragColor = color;

}*/




