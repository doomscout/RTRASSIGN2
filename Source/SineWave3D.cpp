#include "SineWave3D.hpp"
#include <math.h>
#include <memory.h>


//Default Constructor
SineWave3D::SineWave3D()
{
	
	waveDim = 2;
	time = 0.0f;
	
	//std::cout <<"initing class" << std::endl;
	
	initSize(8);
	initSineWave();

}


// Constructor with setting size to Initialization
SineWave3D::SineWave3D(int sizeOfT)
{
	if(sizeOfT > 1024)
		sizeOfT = 1024;
		
	if(sizeOfT < 8)
		sizeOfT = 8;
	waveDim = 2;
	time = 0.0f;
	
	//std::cout <<"initing class" << std::endl;
	
	initSize(sizeOfT);
	initSineWave();
}

//Destcontruct
SineWave3D::~SineWave3D()
{
}

//Change size of Tess if new tess value then initization with Dynamic memory Function
void SineWave3D::reSize(int tess)
{
//std::cout << "Re"
	static int currentTess = -1;
	if(currentTess != tess)
	{
		currentTess = tess;
		cleanUp();
		initSize(tess);
		initSineWave();
		initGlenBuffers();
		

	}
		
}

//Initialization size and tess
void SineWave3D::initSize(int t)
{
	tess = t;
	size = (tess + 1) * (tess + 1) * 2; 
}

void SineWave3D::initSineWave()
{
	const float A1 = 0.25, k1 = 2.0 * PI_F, w1 = 0.25;
	const float A2 = 0.25, k2 = 2.0 * PI_F, w2 = 0.25;
	GLfloat stepSize = 2.0 / tess;
	vertices = new Point3f[size];
	int loop = 0;
	for(int j = 0; j <= tess; j++)
	{
		for(int i = 0; i <= tess; i++)
		{
			GLfloat x = -1.0 + i * stepSize;
			GLfloat z = -1.0 + j * stepSize;
			vertices[loop].setX(x);
			vertices[loop].setZ(z);	
		
		
	
			//vertices[loop].setY(A1 * sin(k1 * vertices[loop].getX() + w1 * time));
			switch(waveDim)
			{
				case 2:
					vertices[loop].setY(A1 * sinf(k1 * vertices[loop].getX() + w1 * time));
					//normal normal calucation
					loop++;
					vertices[loop].setX(-A1 * k1 * cosf(k1* vertices[loop-1].getX() + w1 * time));
					vertices[loop].setY(1.0);
					vertices[loop].setZ(0.0);
					break;
				case 3:
					vertices[loop].setY(A1 * sinf(k1 * vertices[loop].getX() + w1 * time) + A2 * sinf(k2 * vertices[loop].getZ() + w2 * time));
					//normal calucation
					loop++;
					vertices[loop].setX(-A1 * k1 * cosf(k1* vertices[loop-1].getX() + w1 * time));
					vertices[loop].setZ(-A2 * k2 * cosf(k2 * vertices[loop-1].getZ() + w2 * time));
					vertices[loop].setY(1.0);
				default:
					break;
					
			}

			loop++;
		}
	}
		
	sizeOfIndices = 2 * (tess + 1) * (tess);
	indices = new GLuint[sizeOfIndices];
		
	int count = 0;
	for (int i = 0; i < tess; i++)
	{
		int ii = i * (tess+1);
		for (int j = 0; j < tess + 1; j++)
		{
			indices[count] = ii + j;
			count++;
			indices[count] = tess + 1 + j + ii;
			count++;
		}
	}
}
//animation function to set all vertices data also if waveDim is change then shape will change too
//using glMapBuffer
void SineWave3D::animatSineWave(GLfloat t)
{
/**
	glMapBuffer is work well however more poorly performatin than glBufferData in my desktop with AMD
	from compare AMD vs Nvidia(Sutherland Laboratory) however it will be  different result while uisng 
	Sutherland Laboratory pc lab even smooth than immediation mode with Lighting and animation on.
**/
	#if 1
	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	Point3f * ptr = (Point3f *)glMapBuffer(GL_ARRAY_BUFFER,GL_READ_WRITE);


	time = t;
	const float A1 = 0.25, k1 = 2.0 * PI_F, w1 = 0.25;
	const float A2 = 0.25, k2 = 2.0 * PI_F, w2 = 0.25;
	for(int i = 0; i < size; i++)
	{
		//vertices[loop].setY(A1 * sin(k1 * vertices[loop].getX() + w1 * time));
		switch(waveDim)
		{
			case 2:
				ptr[i].setY(A1 * sinf(k1 * ptr[i].getX() + w1 * time));
				i++;
				ptr[i].setX(-A1 * k1 * cosf(k1 * ptr[i - 1].getX() + w1 * time));
				ptr[i].setY(1.0);
				ptr[i].setZ(0.0);
				break;
			case 3:
				ptr[i].setY(A1 * sinf(k1 * ptr[i].getX() + w1 * time) + A2 * sinf(k2 * ptr[i].getZ() + w2 * time));
				i++;
				ptr[i].setX(-A1 * k1 * cosf(k1* ptr[i -1].getX() + w1 * time));
				ptr[i].setZ(-A2 * k2 * cosf(k2 * ptr[i -1].getZ() + w2 * time));
				ptr[i].setY(1.0);
			default:
				break;
		}
			
			//if(i == size -1)
				//std::cout << "Max loop of i :" << i << std::endl;
	}
	
	glUnmapBuffer(GL_ARRAY_BUFFER);
	
	#endif
	
	
	
//Has to enable this code field if I am using my own computer with AMD grahpic card to avoid massive lag if I am using glMapBuffer;
//this code can work for AMD and Nvida as well
	#if 0
	time = t;
	const float A1 = 0.25, k1 = 2.0 * PI_F, w1 = 0.25;
	const float A2 = 0.25, k2 = 2.0 * PI_F, w2 = 0.25;
	for(int i = 0; i < size; i++)
	{
			//vertices[loop].setY(A1 * sin(k1 * vertices[loop].getX() + w1 * time));
			switch(waveDim)
			{
				case 2:
					vertices[i].setY(A1 * sinf(k1 * vertices[i].getX() + w1 * time));
					i++;
					vertices[i].setX(-A1 * k1 * cosf(k1 * vertices[i - 1].getX() + w1 * time));
					vertices[i].setY(1.0);
					vertices[i].setZ(0.0);
					break;
				case 3:
					vertices[i].setY(A1 * sinf(k1 * vertices[i].getX() + w1 * time) + A2 * sinf(k2 * vertices[i].getZ() + w2 * time));
					i++;
					vertices[i].setX(-A1 * k1 * cosf(k1* vertices[i -1].getX() + w1 * time));
					vertices[i].setZ(-A2 * k2 * cosf(k2 * vertices[i -1].getZ() + w2 * time));
					vertices[i].setY(1.0);
				default:
					break;
			}
			
			//if(i == size -1)
				//std::cout << "Max loop of i :" << i << std::endl;
	}
	changeGlenBuffer();
	#endif
}

//Render Vertex Array Function 
//Note: It is no longer need by assigment 1 however it is important to understand Vertex Array
#if 0
void SineWave3D::renderingWithVertexArray()
{
	int c = tess;
	int r = tess;
	unBindBuffers();
	//glVertexPointer(3, GL_FLOAT, sizeof(Vertex), structVert);
	glVertexPointer(3, GL_FLOAT, sizeof(Point3f), vertices);
	glEnableClientState(GL_VERTEX_ARRAY);
	glPushAttrib(GL_CURRENT_BIT);
	for (int i = 0; i < c; i++)
	{
		int indexa = i * (r + 1) * 2;
		glDrawElements(GL_TRIANGLE_STRIP, (r + 1) * 2, GL_UNSIGNED_INT, &indices[indexa]);
	//	glDrawElements(GL_QUAD_STRIP, (r + 1) * 2, GL_UNSIGNED_INT, &indices[indexa]);
			
	}
	glPopAttrib();
	
	glDisableClientState(GL_VERTEX_ARRAY);
}
#endif

//Initialization VBO buffer Function 
void SineWave3D::initGlenBuffers()
{
	    /* Clear old buffers if it exist */
    if (buffers != NULL) {
        glDeleteBuffers(2, buffers);
    }
    
    glGenBuffers(2, buffers);
    
    glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
		//GL_DYNAMIC_DRAW
    glBufferData(GL_ARRAY_BUFFER, size * sizeof(Point3f), vertices, GL_DYNAMIC_DRAW);
    int bufferSize = 0;
    glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &bufferSize);
     
     //Debug to check how big is buffer size with bytes mode
		//  std::cout << "size :" << bufferSize << "bytes"<< std::endl;

	//glBufferData(GL_ARRAY_BUFFER, size * sizeof(Point3f), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeOfIndices * sizeof(GLuint), indices, GL_DYNAMIC_DRAW);
    
    //SineWave3D::unBindBuffers();
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

//need for animation and don't have to recreate new data with glBufferData() for indices
void SineWave3D::changeGlenBuffer()
{
	#if 1
	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	//glBufferSubData(GL_ARRAY_BUFFER, 0, size * sizeof(Point3f), vertices);
		glBufferData(GL_ARRAY_BUFFER, size * sizeof(Point3f), vertices, GL_DYNAMIC_DRAW);
	#endif
	
}


void SineWave3D::unBindBuffers()
{
  int buffer;

  glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &buffer);
  if (buffer != 0)
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &buffer);
  if (buffer != 0)
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

//draw normal vector function for visual debugging
void SineWave3D::drawNormVec()
{
	#if 1
	float scale = 0.05;
	glPushAttrib(GL_CURRENT_BIT);
	glColor3f(1.0, 0.0, 1.0 );
	glBegin(GL_LINES);
	for(int i = 0; i < size; i++)
	{
		i++;
		GLfloat x = vertices[i].getX();
		GLfloat y = vertices[i].getY();
		GLfloat z = vertices[i].getZ();
		GLfloat mag = sqrt(x * x + y * y + z * z);
		x /= mag;
		y /= mag;
		z /= mag;
		x *= scale;
		y *= scale;
		z *= scale;
		
		glVertex3f(vertices[i-1].getX(), vertices[i-1].getY(), vertices[i-1].getZ());
		glVertex3f(vertices[i-1].getX() + x , vertices[i-1].getY() + y, vertices[i-1].getZ() + z);
	}
	#endif
	
	glEnd();
	glPopAttrib();
}

//print on console for debug function
void SineWave3D::printDebug()
{
	std::cout << "size: " << size << std::endl;
	std::cout << "tess: " << tess << std::endl;
	std::cout << "sizeOfIndices: " << sizeOfIndices << std::endl;
	/*
	
	for(int i = 0; i < size; i ++)
	{
		std::cout << "Vertices[" << i << "]s value is " << vertices[i].getX()  << " "<<
			vertices[i].getY() << " " << vertices[i].getZ() << " " << std::endl;
	}
	
	for(int i = 0; i < size; i ++)
	{
		std::cout << "normalVertices[" << i << "]s value is " << normalVertices[i].getX()  << " "<<
			normalVertices[i].getY() << " " << normalVertices[i].getZ() << " " << std::endl;
	}
	
		
	for(int i = 0; i < sizeOfIndices; i ++)
	{
		std::cout << "indices[" << i << "]s value is " << indices[i]  << " "<< std::endl;
	}
	* */
	
}

//Rendering VBO function
void SineWave3D::renderingWithVBO(bool lighting)
{
	glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
	glVertexPointer(3, GL_FLOAT, 2 * sizeof(Point3f), NULL);

	if(lighting)
	{
		glNormalPointer(GL_FLOAT, 2 * sizeof(Point3f), ((Point3f*)NULL) + 1);
	}
	glEnableClientState(GL_VERTEX_ARRAY);

	
	
	if(lighting)
	{
		glEnableClientState(GL_NORMAL_ARRAY);
	}
		/*Indices BindBuffer*/
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
	// std::cout << "rendering VBO" << std::endl;

	int rows = tess + 1;


	for (int i = 0; i < tess; i++)
	{
		//glDrawElements(GL_QUAD_STRIP, (rows) * 2, GL_UNSIGNED_INT,  BUFFER_OFFSET(i * (rows) * 2 * sizeof(GLuint)));
		glDrawElements(GL_TRIANGLE_STRIP, (rows) * 2, GL_UNSIGNED_INT,  BUFFER_OFFSET(i * (rows) * 2 * sizeof(GLuint)));
	}

	
	glDisableClientState(GL_VERTEX_ARRAY);

	if(lighting)
		glDisableClientState(GL_NORMAL_ARRAY);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

//Free class member memory function
void SineWave3D::cleanUp()
{
	//SineWave3D::unBindBuffers();
	if(vertices != NULL)
	{
		//std::cout << "deleteing vertices" << std::endl;
		delete[] vertices;
		vertices = NULL;
	}
	
	if(indices != NULL)
	{
	//	std::cout << "deleteing indices" << std::endl;
		delete[] indices;
		indices = NULL;
	}
	
    if (buffers != NULL) {
	//	std::cout << "deleteing buffers" << std::endl;
        glDeleteBuffers(2, buffers);
    }
}
