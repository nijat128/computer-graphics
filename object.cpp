/*
 * object.cpp
 *
 *  Created on: 2018 M09 20
 *      Author: Nijat
 */

#include "object.hpp"

shape * new_object(GLint x1, GLint y1, GLint x2, GLint y2, GLint t, GLint s,
		GLfloat r, GLfloat g, GLfloat b) {
	shape *p = (shape *) malloc(sizeof(shape));
	p->x1 = x1;
	p->y1 = y1;
	p->x2 = x2;
	p->y2 = y2;

	p->t = t;
	p->s = s;

	p->r = r;
	p->g = g;
	p->b = b;

	return p;
}

void clean(node **frontp, node **backp) {
	node* current_shape;

	while (*frontp != NULL) {
		current_shape = *frontp;
		*frontp = current_shape->next;
		free(current_shape);
	}

	*frontp = NULL;
	*backp = NULL;
}

void insert_back(node **frontp, node **backp, shape *shapep) {
	node* prev = *backp;
	node* front = *frontp;

	if (front == NULL) {
		node *new_shape = (node *) malloc(sizeof(node));
		new_shape->sp = shapep;
		new_shape->next = NULL;
		new_shape->prev = NULL;

		*frontp = new_shape;
		*backp = new_shape;
	} else {
		node *new_shape = (node *) malloc(sizeof(node));
		new_shape->sp = shapep;
		new_shape->next = NULL;
		new_shape->prev = prev;

		prev->next = new_shape;
		*backp = new_shape;
	}
}

void delete_node(node **frontp, node **backp, node *np) {

	node* current = *frontp;
	node* prev = NULL;
	node* next = current->next;

	while (current != NULL) {
		//current = *frontp;
		if (current->sp == np->sp) {
			if (prev != NULL && next != NULL) {
				prev->next = next;
				next->prev = prev;
			} else if (next == NULL && prev != NULL) {
				*backp = prev;
			} else if (next != NULL && prev == NULL) {
				*frontp = next;
			}
			free(current);
			break;
		}
		prev = current;
		current = next;
		next = current->next;
	}

}

void to_front(node **frontp, node **backp, node *np) {

	node* current = *frontp;
	node* prev = NULL;
	node* next = current->next;

	while (current != NULL) {
		//current = *frontp;
		if (current->sp == np->sp) {
			if (prev != NULL && next != NULL) {
				prev->next = next;
				next->prev = prev;
				current->next = *frontp;
				current->prev = NULL;
				*frontp = current;
			} else if (next == NULL && prev != NULL) {
				prev->next = NULL;
				current->next = *frontp;
				current->prev = NULL;
				*frontp = current;
			}
			break;
		}
		prev = current;
		current = next;
		next = current->next;
	}

}

void to_back(node **frontp, node **backp, node *np) {

	node* current = *frontp;
	node* prev = NULL;
	node* next = current->next;

	while (current != NULL) {
		//current = *frontp;
		if (current->sp == np->sp) {
			if (prev != NULL && next != NULL) {
				prev->next = next;
				next->prev = prev;
				current->next = NULL;
				current->prev = *backp;
				*backp = current;
			} else if (next != NULL && prev == NULL) {
				*frontp = current->next;
				current->next->prev = NULL;
				current->next = NULL;
				current->prev = *backp;
				*backp = current;
			}
			break;
		}
		prev = current;
		current = next;
		next = current->next;
	}

}




