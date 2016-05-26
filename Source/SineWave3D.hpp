#pragma once
#define GL_GLEXT_PROTOTYPES
#include "Point3f.hpp"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/glext.h>
#define BUFFER_OFFSET(i) ((void*)(i))


const float  PI_F=3.14159265358979f;

class SineWave3D
{

	public:
	Point3f *vertices; //interleave with position and normal value,
	//Point3f *normals; // no long to be need for assignment 
	GLuint *indices; //array of indices set
	int size; //total size of vertices set
	int sizeOfIndices; // total size of indices set
	int tess; //tessellation
	int waveDim; //wave Length
	GLfloat time; 
	GLuint buffers[2]; //VBO buffer 
	SineWave3D();
	SineWave3D(int sizeOfT);
	~SineWave3D();
	void reSize(int tess);
	void initSize(int t);
	void initSineWave();
	void changeGlenBuffer();
	void animatSineWave(GLfloat t);
	//void renderingWithVertexArray(); //not use for assigment but requirement by lab 2
	void initGlenBuffers();
	void unBindBuffers();
	void renderingWithVBO(bool lighting);
	void drawNormVec();
	void printDebug();
	void cleanUp();
	
};
