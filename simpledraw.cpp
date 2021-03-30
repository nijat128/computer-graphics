/*
 *  file: simpledraw.cpp
 *  author: Nijat Abdulkarimli
 *  date:
 *  description: CP411A1 simple draw program
 */

#include "simpledraw.hpp"

void init(void) {
	glutInitDisplayMode(GLUT_DOUBLE);  // GLUT_DOUBLE for double buffer
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("SimpleDraw (Nijat Abdulkarimli)");

	glClearColor(1.0, 1.0, 1.0, 0.0); // Set display-window color to white
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, winWidth, winHeight, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(3.0);
	glFlush();
}

void drawList(void) {
	glClear(GL_COLOR_BUFFER_BIT); // Clear display window.

	snodep = front;
	while (snodep != NULL) {

		sshapep = snodep->sp;
		type = sshapep->t;
		style = sshapep->s;
		glColor3f(sshapep->r, sshapep->g, sshapep->b);

		if (type == 1) { // check if shape is rectangle
			if (style == 1) { // check if shape filled
				glRecti(snodep->sp->x1, snodep->sp->y1, snodep->sp->x2,
						snodep->sp->y2);
			} else { // shape outlined
				glBegin(GL_LINE_LOOP);
				glVertex2i(snodep->sp->x1, snodep->sp->y1);
				glVertex2i(snodep->sp->x1, snodep->sp->y2);
				glVertex2i(snodep->sp->x2, snodep->sp->y2);
				glVertex2i(snodep->sp->x2, snodep->sp->y1);
				glEnd();
			}
		} else if (type == 2) { // check if shape is circle
			if (style == 1) { // check if shape filled
				glBegin(GL_LINE_LOOP);
				xbegin = snodep->sp->x1;
				ybegin = snodep->sp->y1;
				radius = sqrt(
						pow(snodep->sp->x2 - xbegin, 2)
								+ pow(snodep->sp->y2 - ybegin, 2));
				for (i = 0; i < 360; i++) {
					float degInRad = i * DEG2RAD;
					glVertex2f(xbegin + cos(degInRad) * radius,
							ybegin + sin(degInRad) * radius);
				}
				glEnd();
			} else { // shape outlined
				glBegin(GL_LINE_LOOP);
				xbegin = snodep->sp->x1;
				ybegin = snodep->sp->y1;
				radius = sqrt(
						pow(snodep->sp->x2 - xbegin, 2)
								+ pow(snodep->sp->y2 - ybegin, 2));
				for (i = 0; i < 360; i++) {
					float degInRad = i * DEG2RAD;
					glVertex2f(xbegin + cos(degInRad) * radius,
							ybegin + sin(degInRad) * radius);
				}
				glEnd();
			} // Shape is line
		} else {
			glBegin(GL_LINES);
			glVertex2i(snodep->sp->x1, snodep->sp->y1);
			glVertex2i(snodep->sp->x2, snodep->sp->y2);
			glEnd();
		}

		snodep = snodep->next;
	}

	glutPostRedisplay();
	glFlush();
	glutSwapBuffers();

}

void mouseDraw(GLint button, GLint action, GLint xMouse, GLint yMouse) {

	if (button == GLUT_LEFT_BUTTON) {
		if (action == GLUT_DOWN) {
			sshapep = new_object(xMouse, yMouse, xMouse, yMouse, type, style,
					red, green, blue);
			insert_back(&front, &back, sshapep);
			printf("%d\n", type);
			printf("s%d\n", style);
			printf("%f%f%f\n", red, green, blue);
		} else if (action == GLUT_UP && sshapep != NULL) {
			sshapep->x2 = xMouse;
			sshapep->y2 = yMouse;
			counter++;
		}

	}

	glutPostRedisplay();
	glFlush();
}

void mouseMotion(GLint x, GLint y) {
// your implementation
	sshapep->x2 = x;
	sshapep->y2 = y;

	glutPostRedisplay();
	glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
	/*  Reset viewport and projection parameters  */
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, GLdouble(newWidth), GLdouble(newHeight), 0.0);
	/*  Reset display-window size parameters.  */
	winWidth = newWidth;
	winHeight = newHeight;
	drawList();
}

int main(int argc, char** argv) {
	setvbuf(stdout, NULL, _IONBF, 0);  //used for prompt Eclipse console output
	setvbuf(stderr, NULL, _IONBF, 0);
//  ShowWindow(FindWindowA("ConsoleWindowClass", NULL), false);  //used to hide console

	glutInit(&argc, argv);

//  //menu setting
	GLint edit_subMenu = glutCreateMenu(editSubMenu);
	glutAddMenuEntry("Select ", 1);
	glutAddMenuEntry("Deselect ", 2);
	glutAddMenuEntry("Delete", 3);
	glutAddMenuEntry("Pull to top", 4);
	glutAddMenuEntry("Push to bottom", 5);
	glutAddMenuEntry("Move ", 6);

	GLint type_subMenu = glutCreateMenu(typeSubMenu);
	glutAddMenuEntry(" Rectangle ", 1);
	glutAddMenuEntry(" Circle (Midpoint Alg.) ", 2);
	glutAddMenuEntry(" Line (Bresenham Alg.) ", 3); //

	GLint style_subMenu = glutCreateMenu(styleSubMenu);
	glutAddMenuEntry("Filled ", 1);
	glutAddMenuEntry("Outline ", 2);

	GLint file_subMenu = glutCreateMenu(fileSubMenu);
	glutAddMenuEntry("Save SVG File ", 1);
	glutAddMenuEntry("Open SVG File ", 2);
	glutAddMenuEntry("Export to Bitmap ", 3);

	GLint color_subMenu = glutCreateMenu(colorSubMenu);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);
	// more colors

	GLint dataview_subMenu = glutCreateMenu(dataviewSubMenu);
	glutAddMenuEntry("Linear Regression", 1);

	glutCreateMenu(mainMenu); // Create main pop-up menu.
	glutAddMenuEntry("New ", 1);
	glutAddSubMenu("Draw ", type_subMenu);
	glutAddSubMenu("Edit ", edit_subMenu);
	glutAddSubMenu("Styles ", style_subMenu);
	glutAddSubMenu("Colors ", color_subMenu);
	glutAddSubMenu("Files ", file_subMenu);
	glutAddSubMenu("Data visualization ", dataview_subMenu);
	glutAddMenuEntry("Quit", 2);
	// end of menu

	init();
	glutReshapeFunc(winReshapeFcn);
	glutDisplayFunc(drawList);
	glutMouseFunc(mouseDraw);
	glutMotionFunc(mouseMotion);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	return 0;
}

