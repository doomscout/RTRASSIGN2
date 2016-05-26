#pragma once
#define GL_GLEXT_PROTOTYPES
#include "shaders.h"
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/constants.hpp>


/*DebugMode for print Vector Function*/
void printVec(float *v, int n);

/*DebugMode for print MatrixLinear Function*/
void printMatrixLinear(float *m, int n);

/*DebugMode for print MatrixColumnMagjor Function*/
void printMatrixColumnMajor(float *m, int n);

/*Initization for main() */
void init(void);

/*change Screen size while updating Function*/
void reshape(int w, int h);

/*Draw axis with glm vec Function*/
void drawAxes(float length);

/*draw Vector for visual debug function*/
void drawVector(glm::vec3 & o, glm::vec3 & v, float s, bool normalize, glm::vec3 & c);

/*Console performance meter*/
void consolePM();

/*DisplayOSD function*/
void displayOSD();


/*Compute Light function with glm library*/
glm::vec3 computeLighting(glm::vec3 & rEC, glm::vec3 & nEC);
glm::vec3 computeBinnLighting(glm::vec3 & rEC, glm::vec3 & nEC);
/*Draw SineWave with glm vector Function*/
void drawSineWave(int tess);

/*update or idle function*/
void idle();

/*Display mulitView Screen Function*/
void displayMultiView();

/*Display Single Screen Function*/    
void display();

/*Keyboard control function*/
void keyboard(unsigned char key, int x, int y);


/*mouse control function*/
void mouse(int button, int state, int x, int y);


/*mouse motion function*/
void motion(int x, int y);

/*update render state function from hotkey event Function*/
void updateRenderState();
