#version 330 core

in vec4 frontColor;
out vec4 fragColor;

uniform int n=5;

void main() {
/*  
	//same but GITHUB
	if (int(gl_FragCoord.y)%n==0) gl_FragColor=frontColor;
	else discard;
*/


	if (mod(int(gl_FragCoord.y),n)==0) gl_FragColor=frontColor;
	else discard;

}
