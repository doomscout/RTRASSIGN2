//shader.frag


varying vec4 color;
varying vec3 normal, light;
varying vec3 eyeVector, halfVector;
//varying vec3 xSetVColor;
void main (void)
{
	
	#if 0
	vec3 lEC = vec3( 0.0, 0.0, 1.0 );
	vec3 ambient = vec3(0.2 * 0.2);
	vec3 n = normalize(normal);
	float dp = dot(normal, lEC);
    vec3 diffuse = vec3(0.0);
    vec3 spec = vec3(1,1,1);
	//gl_FragColor = vec4(xSetVColor, 1);
    //gl_FragColor = vec4(vColor, 1); 
    //gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);
    if (dp > 0.0)
		diffuse = vec3(dp * 1.0 * 0.8);	
		
	vec3 c = ambient + diffuse;	
	
    gl_FragColor = vec4(c, 1);
    #endif
    
    //Vertex per light
    #if 0
	vec3 lEC = vec3( 0.0, 0.0, 1.0 );

	vec3 ambient = vec3(0.2 * 0.2);
	
	float dp = dot(normal, lEC);
    vec3 diffuse = vec3(1, 1, 1);
    vec3 halfVector = normalize(lEC + vec3(0,0,1));
    vec4 specularColor;
	//gl_FragColor = vec4(xSetVColor, 1);
    //gl_FragColor = vec4(vColor, 1); 
    //gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);
    if (dp > 0.0)
    {
		//float Ndoth = dot(N, halfVector);
		float NdotHV = max(dot(normal, halfVector), 0.0);
		float specular_Highlight = pow(NdotHV, gl_FrontMaterial.shininess);
		specularColor = gl_FrontMaterial.specular * gl_LightSource[0].specular * specular_Highlight;
		diffuse = vec3(dp * 1.0 * 0.8);	
	}
	
	vec3 c = ambient + diffuse + vec3(specularColor);	
	
    gl_FragColor = vec4(c, 1);
    #endif
    
    
    //pixel of lighting
     #if 0
	vec3 lEC = vec3( 0.0, 0.0, 1.0 );

	vec3 ambient = vec3(0.2 * 0.2);
	
	float dp = dot(normal, lEC);
    vec3 diffuse = vec3(1, 1, 1);
    vec3 halfVector = normalize(lEC + vec3(0,0,1) + eyeVector);
    vec4 specularColor;
	//gl_FragColor = vec4(xSetVColor, 1);
    //gl_FragColor = vec4(vColor, 1); 
    //gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);
    if (dp > 0.0)
    {
		//float Ndoth = dot(N, halfVector);
		float NdotHV = max(dot(normal, halfVector), 0.0);
		float specular_Highlight = pow(NdotHV, gl_FrontMaterial.shininess);
		specularColor = gl_FrontMaterial.specular * gl_LightSource[0].specular * specular_Highlight;
		diffuse = vec3(dp * 1.0 * 0.8);	
	}
	
	vec3 c = ambient + diffuse + vec3(specularColor);	
	
    gl_FragColor = vec4(c, 1);
    #endif   
    
    
   // gl_FragColor = color;
}
