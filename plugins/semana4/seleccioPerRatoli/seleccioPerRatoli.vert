#version 330 core

layout (location = 0) in vec3 vertex;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec3 color;

out vec4 vColor;

uniform int   pas;
uniform vec3  colorPas;
uniform mat4  modelViewProjectionMatrix;

uniform float sx, sy, sz;
uniform float tx, ty, tz;

void main()
{
    if(pas == 1){           // escena inicial
      vColor = vec4(color, 1.0);
      gl_Position  =  modelViewProjectionMatrix * vec4(vertex, 1.0);

  } else if(pas == 2){      // seleccio
      vColor = vec4(colorPas, 1.0);    
      gl_Position  =  modelViewProjectionMatrix * vec4(vertex, 1.0);

  } else if (pas == 3){     // redibuixat escena ?
      vColor = vec4(color, 1.0);
      gl_Position  =  modelViewProjectionMatrix * vec4(vertex, 1.0);

  } else if (pas == 4){     // dibuix caixa
      vColor = vec4(colorPas, 1.0);

      // matrius definides per columnes
      mat4 escala = mat4(vec4(sx,  0,  0, 0),
                         vec4( 0, sy,  0, 0),
                         vec4( 0,  0, sz, 0),
                         vec4( 0,  0,  0, 1)
                        );

      mat4 transla = mat4(vec4( 1,  0,  0, 0),
                          vec4( 0,  1,  0, 0),
                          vec4( 0,  0,  1, 0),
                          vec4(tx, ty, tz, 1)
                         );
     gl_Position  = modelViewProjectionMatrix * transla * escala * vec4(vertex, 1.0);
   }
}
