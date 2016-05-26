//shader.vert

#define PI_F 3.141592653589793238462643383279

varying vec4 FragColor;
uniform mat4 mv;

uniform int dimWave;
uniform float time;

//Is lighting enabled

uniform int lighting; //Lighting flag
uniform int blinn; //Specular lighting flag
uniform int vertex; //Flag for vertex pixel or vertex
uniform int normalsFlag; //Normal flag
uniform int directional; //Directional or Positional light flag
uniform float shiny;// NO longer use and replace by gl_FrontMaterial.shininess
varying vec4 ambient;
varying vec4 diffuse; 
//
varying vec3 light, normal, halfVector, eyeVec;


void main(void)
{


 //Borrowed from Startup Code
    const float A1 = 0.25, k1 = 2.0 * PI_F, w1 = 0.25;
    const float A2 = 0.25, k2 = 2.0 * PI_F, w2 = 0.25;
     //os - object space, es - eye space, cs - clip space
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
    
    //calucation normal with gl_NormalMatrix
    normal = normalize(gl_NormalMatrix * osNormal);
    
    //calucation for gl_Position for confirm vertex
    vec4 esVert = gl_ModelViewMatrix * osVert; 
    vec4 csVert = gl_ProjectionMatrix * esVert;
    gl_Position = csVert;  
    
    //EyeVector to/for camera and it requirement for Positonal Lighting
    eyeVec = -vec3(esVert);
    
    //calucation lighting for Directional Lighting or Positional Lighting
    if(directional == 1)
    {
		light = normalize(vec3(gl_LightSource[0].position));
    }
    else
    {
		light = normalize(eyeVec + vec3(gl_LightSource[0].position));
    }
    
    //has to reset eyeVec to modelView because it will be infinite distance if don't reset
    //Wait wait........
    //magic number from startup code
    eyeVec = normalize(vec3(0.0, 0.0, 1)); 
    vec3 reflectDir = reflect(-light, normal);
	
	
	//calucation halfVector with light + eyeVec
	halfVector = normalize(light + eyeVec);



	if(lighting == 1)
	{
		vec4 color;	
		//Using Default value for ambient from parent: Main.cpp's gl_Light0
		ambient = gl_FrontMaterial.ambient * (gl_LightModel.ambient
				+ gl_LightSource[0].ambient);
				//update color                                      
		color = ambient;
		
		// calucation angle between Normal and light
		float NdotL = max(dot(normal,light), 0.0); 
		//calucation diffuse value with NdotL 
		diffuse = NdotL*  gl_FrontLightProduct[0].diffuse * gl_LightSource[0].diffuse;		 
		//update color value
		color += diffuse;
		
		//Vertex per Light mode
		if(vertex == 1)
    	{
			//Blinn Phong Light Mode
			if(blinn == 1)
			{
				if(NdotL > 0.0)
				{
					//Calucation cosine of the half vector with the normal
					float NdotHV = max(dot( halfVector, normal), 0.0);
					
					vec4 specular = gl_FrontMaterial.specular * gl_LightSource[0].specular * pow(NdotHV, gl_FrontMaterial.shininess);
					//update color
					color += gl_FrontMaterial.specular * gl_LightSource[0].specular *specular;
				}
			}		
			else//Phong LIght Mode		
			{	   
			
				if(NdotL > 0.0)
				{
					//Calucation reflectDir with -light and normal
					
					//Calucation the angle 
					
					float specAngle = max(dot(reflectDir, eyeVec), 0.0); 			
					float specular_Highlight = pow(specAngle, gl_FrontMaterial.shininess);
					//update code
					color +=  gl_FrontMaterial.specular * gl_LightSource[0].specular
						 *specular_Highlight;
				}
			}
			
			FragColor = color;
		}
		
	    }	
	    else
	    {
			gl_FrontColor = gl_Color;
	    }

    
    //If normals are enabled, set to rainbow normals
    //Where the colour is assosiated to i,j,k components as, R,B,G
    if(normalsFlag == 1)
    {
		gl_FrontColor = vec4(normal, 1.0);
    }
    else
    {
		gl_FrontColor = gl_Color; 
    }
}
 
