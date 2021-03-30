/*
 *  file: algorithm.cpp
 */

#include "algorithm.hpp"

GLint min(GLint x, GLint y) {
	return (x < y) ? x : y;
}

GLint max(GLint x, GLint y) {
	return (x < y) ? y : x;
}

node *select(node *back, GLint x, GLint y) {
// your implementation
}

/* Drawing funtions */
void setPixel(GLint x, GLint y) {
	glPointSize(2.0);
	glBegin (GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

/* draw 8 symmetric points on circle by a given point
 * this function is used by circleMidpoint function
 */
void circlePlotPoints(const GLint& xc, const GLint& yc, const GLint& x,
		const GLint& y) {
// your implementation
}

/* draw 4 line segments by a given point on circle
 * this function is used by circleMidpointFill for drawing filled circle
 */
void circlePlotPointsFill(GLint x1, GLint y1, GLint x, GLint y) {
// your implementation
}

// draw circle outline bye midpoint algorithm
void circleMidpoint(GLint x1, GLint y1, GLint x2, GLint y2) {
// your implementation
}

// draw filled circle by midpoint algorithm
void circleMidpointFill(GLint x1, GLint y1, GLint x2, GLint y2) {
// your implementation
}

void Bresenham(int x1, int y1, int x2, int y2) {
// your implementation

}

void drawObject(GLint x1, GLint y1, GLint x2, GLint y2, GLfloat r1, GLfloat g1,
		GLfloat b1, GLint t1, GLint s1) {
// your implementation
}

void drawShape(shape *p) {
// your implementation
}

void drawObjectList(node *front) {
// your implementation
}
