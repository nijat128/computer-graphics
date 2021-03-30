/*
 * algorithm.hpp
 *
 *  Created on: 2018 M09 20
 *      Author: Nijat
 */

#ifndef ALGORITHM_HPP_
#define ALGORITHM_HPP_


#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fstream>  // C++ file I/O
#include <iostream>

#include "object.hpp"

void clear();
GLint min(GLint x, GLint y);
GLint max(GLint x, GLint y);
node *select(node *back, GLint x, GLint y);
void toFront(GLint);
void toBack(GLint);
void setPixel(GLint x, GLint y);
void Bresenham(int x1, int y1, int x2, int y2);
void circleMidpoint(GLint x1, GLint y1, GLint x2, GLint y2);
void circleMidpointFill(GLint x1, GLint y1, GLint x2, GLint y2);
void drawObject(GLint x1, GLint y1, GLint x2, GLint y2, GLfloat r1, GLfloat g1,
		GLfloat b1, GLint t1, GLint s1);
void drawObjectList(node *front);


#endif /* ALGORITHM_HPP_ */
