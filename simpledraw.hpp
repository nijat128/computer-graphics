/*
 * simpledraw.hpp
 *
 *  Created on: 2018 M09 20
 *      Author: Nijat
 */

#ifndef SIMPLEDRAW_HPP_
#define SIMPLEDRAW_HPP_


#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fstream>  // C++ file I/O
#include <iostream>

#include "object.hpp"
#include "algorithm.hpp"
#include "file.hpp"
#include "menu.hpp"
#include "dataview.hpp"

//global variables
const float DEG2RAD = 3.14159 / 180;
shape *sshapep; //selected shape object pointer
shape tshape;   //temporal shape variable
node *front = NULL, *back = NULL, *snodep = NULL; //pointers for double linked list.

GLsizei winWidth = 640, winHeight = 480;
GLint tool = 0; //0:draw,1:edit,2:dataview
GLint selection = 0; //1: in selection mode, else not.
GLint move = 0; //0:not move, 1:move, used when tool = 1
GLint type = 1; //1:rectangle,2:circle;3:line
GLint style = 1; //1:filled,2:outline,3:no
GLfloat red = 1.0, green = 0.0, blue = 0.0;
GLint dataview_option = 4; //1:bar,2:pi,3:plot,4:regression
GLint xbegin, ybegin, i;
GLfloat radius;
GLint counter = 0; // number of shape object for testing


#endif /* SIMPLEDRAW_HPP_ */
