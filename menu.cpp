/*
 *  file: menu.hpp
 */

#include "menu.hpp"


// used for new drawing operation
void clear() {
// your implementation
}

void mainMenu(GLint menuOption) {
	switch (menuOption) {
	case 1:
		tool = 0;
		selection = 0;
		move = 0;
		break;
	case 2:
		exit(0);
	}
	glutPostRedisplay();
}

void typeSubMenu(GLint typeOption) {

	switch (typeOption) {
	case 1: {
		type = 1;
	}
		break;
	case 2: {
		type = 2;
	}
		break;
	case 3: {
		type = 3;
	}
	}
	glutPostRedisplay();
}

void fileSubMenu(GLint fileOption) {

}

void editSubMenu(GLint editOption) {

}

void styleSubMenu(GLint styleOption) {
	switch (styleOption) {
	case 1: {
		style = 1;
	}
		break;
	case 2: {
		style = 2;
	}
	}
	glutPostRedisplay();
}

void colorSubMenu(GLint colorOption) {
	switch (colorOption) {
	case 1: {
		red = 1.0;
		green = 0.0;
		blue = 0.0;
	}
		break;
	case 2: {
		red = 0.0;
		green = 1.0;
		blue = 0.0;
	}
		break;
	case 3: {
		red = 0.0;
		green = 0.0;
		blue = 1.0;
	}
		break;
	case 4: {
		red = 1.0;
		green = 1.0;
		blue = 1.0;
	}
	}
	glutPostRedisplay();
}

void dataviewSubMenu(GLint option) {

}
