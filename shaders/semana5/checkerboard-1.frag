#version 330 core

in vec2 vtexCoord;
out vec4 fragColor;

//const vec4 GREY=vec4(vec3(0.8), 1);
//const vec4 BLACK=vec4(vec3(0), 1);


void main()
{

	vec4 color;
	
	int x = int(mod(8*vtexCoord.s,2));
	int y = int(mod(8*vtexCoord.t,2));
	
	if (x==y) color = vec4(0.8);	//red
	else color = vec4 (0);		//blue

	fragColor = color;

}

/*
void main()
{
	//float slice=1.0/100;
  	int x = int(mod(vtexCoord.x * 8, 2));
  	int y = int(mod(vtexCoord.y * 8, 2));
  	if (x == y) fragColor=GREY;
  	else fragColor=BLACK;




}*/






