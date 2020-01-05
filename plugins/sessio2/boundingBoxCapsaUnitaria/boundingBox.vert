#version 330 core

in vec3 vertex;

uniform mat4 mvp;
uniform float sx;
uniform float sy;
uniform float sz;

uniform float tx;
uniform float ty;
uniform float tz;

void main()
{
  mat4 translate = mat4(vec4(1,0,0,0),
                        vec4(0,1,0,0), 
                        vec4(0,0,1,0), 
                        vec4(tx,ty,tz,1));
  mat4 scale = mat4(vec4(sx,0,0,0),
                    vec4(0,sy,0,0), 
                    vec4(0,0,sz,0),
                    vec4(0,0,0,1));
    
  gl_Position = mvp * translate * scale * vec4(vertex, 1.0);
}

