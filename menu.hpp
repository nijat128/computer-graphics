/*
 * menu.hpp
 *
 *  Created on: 2018 M09 20
 *      Author: Nijat
 */

#ifndef MENU_HPP_
#define MENU_HPP_


#include "file.hpp"

//these global variables will be used in the function, need to import by key word extern
extern GLsizei winWidth;
extern GLsizei winHeight;
extern shape *sshapep;
extern GLfloat red, green, blue;
extern GLint type;
extern GLint style, tool, selection, move;
extern node *front, *back, *snodep;

void mainMenu(GLint menuOption);
void typeSubMenu(GLint typeOption);
void fileSubMenu(GLint fileOption);
void editSubMenu(GLint editOption);
void styleSubMenu(GLint styleOption);
void colorSubMenu(GLint colorOption);
void dataviewSubMenu(GLint option);


#endif /* MENU_HPP_ */
