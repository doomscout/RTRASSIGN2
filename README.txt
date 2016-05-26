//////////
//README
//Real-Time Rendering & 3D Games Programming Assignment 1

student group:
Ke Yi Ren s3405167
William Field s3434180

***************************************************************************************************************************************
/*Main Assignment 2 File*/
/*Functionality:Pong Lighting, Blinn Phong lighting, control, OSD display, Shade mode*/
Assignment2 file: main cpp, Point3f.cpp, SineWave3D.cpp, Readme, shader.vert, shader.frag(Bin Folder), shaders.cpp(Bin Folder)
Makefile folder location - Assignment2/Source/
Run/execution program 's folder  -Assignment1/Bin/
Note: for hotkey: press v for enable Vertex Buffer Object mode
Note: you will notice two folders: "PreAss2" and "Unfinish" and below will explain what are them.

a - toggle animation 
d - toggle directional, positional lighting 
f - toggle smooth, flat shading // Double check 
H/h - increase/decrease shininess
l - lighting
m - Blinn-Phong or Phong specular lighting model
n - render normals: as line segments in fixed pipeline mode but as colours in programable pipeline i.e. shader mode
o - cycle through OSD options
p - per (vertex, pixel) lighting
s - toggle shader (fixed/programmable) mode // pipeline vs shaders 
T/t - increase/decrease tesselation
w - wireframe (line) or fill mode

***************************************************************************************************************************************
/*PreAss2 File*/
/*Functionality :Lab 6 result from Pong Lighting and Blinn Phong Lighting */
/*Note: no shader mode*/
PreAss2 file: main cpp, shaders.cpp,  sinewave3D-glm, shaders.cpp
Makefile folder location --PreAss2/Source/
Run/execution program 's folder  -PreAss2/Bin/

Hotkey: 
m for switch Blinn/Phong
f for switch coded lighting function with Pong/BlinPong or fixed pipeline function from opengl
l for enable lighting
***************************************************************************************************************************************


/*Unfinish File*/
/*Ran out of time to implementation "Using GLM in conjunction with shaders for transformations" Function for Assignment 2 */
/*And I dont' want mess up Assignment 2's AxesSet*/
/*This work which is implementatin "Using GLM in conjunction with shaders for transformations" and it is functionable however
*it don't made into Assignment 2 code.
*/
/*you can read code shader.vert for "Using GLM in conjunction with shaders for transformations" check from Bin Folder  */
Unfinish file: main cpp, Point3f.cpp, SineWave3D.cpp, shader.vert(Bin Folder, shader.frag(Bin Folder), shaders.cpp
folder location --Unfinish/Source/
Run/execution program 's folder  -Unfinish/Bin/

Hotkey:
e for enable/disband Shader Mode
d for switch Imme Mode to VBO or VBO to IMme mode
***************************************************************************************************************************************
/**/
//////////
//Questions 1.
//Is there any visual difference between fixed pipeline and shader lighting? Should there be?
  No there isn't, and no there shouldn't be because the fixed pipeline rendering and GPU rendering modes sharing same calucation
  however Shader programmable can be trick and it can be modifty various light setting make it looks different from fixed pipeline

//Questions 2.
//Is there any performance difference between fixed pipeline and using shader lighting?
   Nothing much different from shader lighting and fixed pipeline.

//Questions 3.
//What overhead/slowdown factor is there for performing animation compared to static geometry using the vertex shader? For static i.e. geometry is it worth pre-computing and storing the sine wave values in buffers?
I don't see overhead or slowdown factor from peforming animation and it quite impressived me from compare from Assignment 1 and Assignment 2.
I can see Assignment 1 Vertex Buffer Object Animation can be very lag due bottleneck. This time Shader just loaded Vertex Buffer Object stored data and modifty value for animation without access CPU so in otherword Bottleneck is not happen.

//Questions 4.
//Is there any difference in performance between per vertex and per pixel shader based lighting?
 Nothing much.... hardly to see huga impact between per vertex and per pixel shader based lighting

//Questions 5.
//What is the main visual difference between Phong and Blinn-Phong lighting?
These two lighting models are the same in terms of using simple ambient reflection and diffuse reflection but differ
in the specular reflection calculation. One difference between the two modes is, the Blinn-Phong calculates
a halfway vector, which is a vector at the angle equal distance from the eye and the light source.
Phong calucates a reflect with using two vectors: -light Direction , normal. then calucate the angle with crossProduce between reflect Direction and eye Vector.
In PreAss2 result Phong light's shininess specular less than blinn Phong light. so Yes there is visual difference from result
In Assignment 2 result shows same result from PreAss2 althought Phong Light is slight shininess than PreAss2.

//
////////////

/*Issue*/
1.We already spend countless hours for solving Phong and Blinn Pong Light problem and we have to admit it is giving us hard time.

2.Phong Light already confused us a lot..... due EyeVector problem

3.Visual Debugging is much worse than printconsole Debug mode..... i can't see very important math data from Shader programming!

4.I believes we have spend so much time on visual debugging while programming lighting code for shader. that why we run out of time and don't have enough
time to implementation "Using GLM in conjunction with shaders for transformations"




