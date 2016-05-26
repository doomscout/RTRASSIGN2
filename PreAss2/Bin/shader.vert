//shader.vert
//uniform vec3 uColor;

#define M_PI 3.141592653589793238462643383279
varying vec3 normal, light;
varying vec3 eyeVector, halfVector;
//uniform vec3 xSetUColor;
//varying vec3 xSetVColor;
varying vec4 color;
void main(void)
{
	
	const float A1 = 0.25, k1 = 2.0 * M_PI, w1 = 0.25;
	const float A2 = 0.25, k2 = 2.0 * M_PI, w2 = 0.25;
	
    // os - object space, es - eye space, cs - clip space
    vec4 esVert = gl_Vertex;
        

    vec3 normalVert = gl_Normal.xyz;
	//normalVert
	
   // vec4 esVert = gl_ModelViewMatrix * osVert;
    vec4 csVert = esVert;
    eyeVector = vec3(esVert);
    gl_Position = csVert;
    
	//vec3 n = normalize(gl_NormalMatrix * normalVert);
   // normal
    normal = normalVert;
    
    
  //  normal = gl_Normal;
   color = vec4(normal, 1);
    
    
	
  
}
 
