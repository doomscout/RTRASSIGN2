//shader.frag
uniform int vertex;
uniform int normalsFlag;
uniform int lighting;
uniform int blinn; 
uniform float shiny;

varying vec4 FragColor;
varying vec4 ambient, diffuse;
varying vec3 light, normal, halfVector, eyeVec;

void main (void)
{
	//varying from vertex file which is already calucation
	//Note:Fragment file can't allow varied variable to be assign by any value
   vec3 n = normal;
   vec3 l = light;
  
	if(lighting == 1)
	{
		//Light per Pixel Mode
		if(vertex == 0)
		{
		//Using Default value for ambient from parent: Main.cpp's gl_Light0
		vec4 color = ambient;
		
		// calucation angle between Normal and light
		float NdotL = max(dot(n , l ), 0.0);
		color += diffuse;
		//Blinn Phong Light Mode
			if(blinn == 1)
			{
				if(NdotL > 0.0)
				{
					//Calucation cosine of the half vector with the normal
						float NdotHV = max(dot(n,halfVector),0.0);
					//update color with vec4(pow(NdotHV, gl_FrontMaterial.shininess))
						color += gl_FrontMaterial.specular * gl_LightSource[0].specular * vec4(pow(NdotHV, gl_FrontMaterial.shininess)) ;
				}
			
			}
			else
			{
				if(NdotL > 0.0)
				{
					//Calucation reflectDir with -light and normal
					vec3 reflectDir = reflect(-light, normal);
					//Calucation the angle 
					float specAngle = max(dot(reflectDir, eyeVec), 0.0); 
					float specular_Highlight = pow(specAngle, gl_FrontMaterial.shininess);
					//update code
					color +=  gl_FrontMaterial.specular * gl_LightSource[0].specular
							 *specular_Highlight;
				}
			}
			gl_FragColor = color;	
		}
		else
		{
			//if it is Vertex per light mode then using FragColor which is pass by Vert File
			gl_FragColor = FragColor;
		}
	}
   
   //Normal visual debug Mode
   if(normalsFlag == 1)
   {
		gl_FragColor = vec4(normal, 1.0);
   }
    	

}
