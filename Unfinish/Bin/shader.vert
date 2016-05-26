//shader.vert

#define PI_F 3.141592653589793238462643383279

uniform vec3 uColor;
uniform mat4 mvMat;
uniform mat3 nMat;
uniform mat4 oroProj;
uniform int dimWave;
uniform float time;

attribute vec3 coord3d;


varying vec3 v;
varying vec3 light, normal, halfVector, eyeVec;
varying vec3 vColor; 
//uniform vec3 xSetUColor;
//varying vec3 xSetVColor;

//attribute vec3 coord3d;

void main(void)
{
	#if 0
    vec4 osVert = gl_Vertex;
    vec4 esVert = gl_ModelViewMatrix * osVert;
    vec4 csVert = gl_ProjectionMatrix * esVert;
    gl_Position = csVert;
    #endif
    
    #if 1
    	
	const float A1 = 0.25, k1 = 2.0 * PI_F, w1 = 0.25;
	const float A2 = 0.25, k2 = 2.0 * PI_F, w2 = 0.25;
    
   //  vec4 osVertN = gl_
    vec4 osVert = gl_Vertex;
  
    vec3 osNormal= vec3(0.0);
  
    if(dimWave == 2)
    {
	//calculation for Animation 
	   osVert.y = 	A1 * sin(k1 * osVert.x + w1 * time);
	//calculation for Normal
	   osNormal.x = -A1 * k1 * cos(k1 * osVert.x + w1 * time);
	   osNormal.y = 1.0; 
	   osNormal.z = 0.0;
    }
    else //dimWave == 3
    {
	//calculation for Animation 
	   osVert.y = A1 * sin(k1 * osVert.x + w1 * time) + A2 * sin(k2 * osVert.z + w2 * time);
	 //calucation normal
	   osNormal.x = -A1 * k1 * cos(k1 * osVert.x + w1 * time);
	   osNormal.y = 1.0;
	   osNormal.z = -A2 * k2 * cos(k2 * osVert.z + w2 * time);
    }
	
	






    vec4 esVert = osVert * mvMat;
    vec4 csVert = oroProj * esVert;
    gl_Position = csVert;
    
    normal = normalize(nMat * osNormal);
    #endif
    
    #if 0
     gl_Position =  gl_Vertex  * gl_ProjectionMatrix * mvMat;
    #endif
}
 
