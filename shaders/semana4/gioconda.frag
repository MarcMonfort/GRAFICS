#version 330 core

in vec2 vtexCoord;
out vec4 fragColor;

uniform float time;
uniform sampler2D sampler;

const vec2 EYE=vec2(0.393, 0.652);
const vec2 OFF=vec2(0.057, -0.172);

void main() {
  vec2 texCoord=vtexCoord;
  if (fract(time)>0.5) {
    float f=length(texCoord-EYE);
    if (f<=0.025) texCoord+=OFF;
  }
  fragColor=texture(sampler, texCoord);
}
