//shader.frag

//uniform vec3 uColor;
varying vec3 vColor;
varying vec3 light, normal, halfVector, eyeVec;
varying vec3 v;

void main (void)
{

  // gl_FragColor = vec4(1.0, 1.0, 0, 1);
 // gl_FragColor = gl_Color;
   gl_FragColor = vec4(normal,1.0);
}
