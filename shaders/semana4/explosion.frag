#version 330 core

in vec4 frontColor;
out vec4 fragColor;

uniform sampler2D explosion;
in vec2 vtexCoord;

uniform float time;

uniform sampler2D frameMap1;


/*void main()
{
	vec2 newV;
	newV.x = 0/8.0 + vtexCoord.x/8.0;
	newV.y = 5/6.0 + vtexCoord.y/6.0;
	vec4 boom = texture(explosion, newV);
    fragColor = boom.a * boom;
	
}*/


void main()
{
	vec2 texCoord=vtexCoord;
	texCoord.x /=8;
	texCoord.y /=6;
	
	int POS = int(mod(time*30,48));
	int x = POS%8;
	int y = 5 - POS/8;//int(mod(time,6.0));
	
	texCoord.x += x/8.0;
	texCoord.y += y/6.0;

	fragColor=texture(explosion, texCoord);
	fragColor*=fragColor.w;
}











/*
void main() {
  float slice=1.0/30;
  int frame=int(mod(time/slice, 48));
  int x=frame%8;
  int y=5-frame/8;

  //vec2 texCoord=vtexCoord*vec2(1.0/8, 1.0/6);


  //texCoord.x+=x/8.0;
  //texCoord.y+=y/6.0;

	  //texCoord.x+=x/8.0;
  	//texCoord.y+=y/6.0;

  fragColor=texture(explosion, texCoord);
  fragColor*=fragColor.w;
}*/
