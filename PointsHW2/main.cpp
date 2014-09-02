//author: Henry West
//date:  August 27, 2014
//description: This program serves as an intoduction to OpenGL.  Draws a parallelogram and a triangle

#ifdef __APPLE__
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include<GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


#define WIDTH 500
#define HEIGHT 400

#include <iostream>
#include <vector>

struct Point {
    int x;
    int y;

    Point(int xComp, int yComp) {
        x = xComp;
        y = yComp;
    }
};

std::vector <Point> vertices;

//extra vertex

void display(void) {
	/*clear all pixels*/
	glClear(GL_COLOR_BUFFER_BIT);

	/*set color to teal-ish I think -- Alteration 1*/
	glColor3f(0.1,0.5,0.8);

    glEnableClientState(GL_VERTEX_ARRAY);

    /*set pointer to vertices array*/
    glVertexPointer(2, GL_INT, 0, vertices.data());
    glDrawArrays(GL_POINTS, 0, (GLsizei) vertices.size()); //draw the four points -- Alteration 2

	/*process buffered OpenGL routines*/
	glFlush();
}

void reshape(int w, int h) {
    glutReshapeWindow(w, h);
}

void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        vertices.push_back(Point(x,HEIGHT - y));
        std::cout << x << "," << y << std::endl;
    }
    glutPostRedisplay();
}

void init(void) {
	/*set clearing (background) color*/
	glClearColor(0.0, 0.0, 0.0, 0.0);

    glPointSize(10.0);

	/*initialize viewing values*/
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WIDTH, 0, HEIGHT);
}

/*
 *  Declare initial window size, position, and display mode
 *  (single buffer and RGB).  Open window with "Drake CS 147" in
 *  title bar.  Call initialization routines.
 *  Register callback function to display graphics.
 *  Enter main loop and process events.
 */
int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(WIDTH,HEIGHT);
	glutCreateWindow("Drake CS 147 Assignment 2");
	init();
	glutDisplayFunc(display);
    glutMouseFunc(mouseClick);
	glutMainLoop();
}

