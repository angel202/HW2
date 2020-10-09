#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#if __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = { 0,1,4,1 };
int windowWidth = 640, windowHeight = 480;
double yRot = 0;
int curProblem = 1; // TODO: change this number to try different examples

float specular[] = { 1.0, 1.0, 1.0, 1.0 };
float shininess[] = { 50.0 };

void problem1() {
	//TODO: Your code here!
	int numTeapots = 9; // num of teapots based on example pic
	glPushMatrix();//Using to center the teapots 
	glTranslated(1, 0, 0); // center 
	glutSolidTeapot(.15); // size of teapots 
	
	for (int i = 0; i < numTeapots; i++) { //recreate the teapots
		glTranslated(-.3, -.7, 0);
		glRotatef(324, 0, 0, 1); // space out the pots 
		glutSolidTeapot(.15); // size of teapots 
	}
	glPopMatrix(); 

}

void problem2() {
	// TODO: Your code here!
	int Steps = 15;
	for (int i = 0; i <= Steps; i++) {
		for (int j = 0; j < i; j++) {
			glPushMatrix();
			glTranslatef(-1.75 + i * 0.23, 0.013 * pow(j,1.5), 0); // center picture create the steps using the power of j w 1.5 for scale 
			glutSolidCube(0.23);
			glPopMatrix();
		}
	}
}


//attempt at making a rock on hand 
void problem3() {

	//base
	glPushMatrix();
	glScaled(1, 1.3, .5);
	glTranslated(-.01, -1.25, 0);
	glutSolidCube(1);

	glPushMatrix();
	glScaled(1.5, .75, 1);
	glTranslated(-.01, 1.1, 0);
	glutSolidCube(1);

	glPushMatrix();

	//Finger 
	glTranslated(.395, .55, 0);
	glScaled(.2, .5, 1);
	glRotated(10, 1, 0, 0);
	glutSolidCube(1);

	glTranslated(0, 1, 0);
	glRotated(10, 1, 0, 0);
	glutSolidCube(1);

	glTranslated(0, 1, 0);
	glRotated(10, 1, 0, 0);
	glutSolidCube(1);

	glPopMatrix(); 

	//Finger
	glPushMatrix();
	glTranslated(.15, .75, 0);
	glScaled(.2, .5, 1);
	glRotated(10, 1, 0, 0);
	glutSolidCube(1);

	glTranslated(0,0 , 1);
	glRotated(15, 1, 0, 0);
	glutSolidCube(1);
	
	glTranslated(0, -1, 0);
	glRotated(10, 1, 0, 0);
	glutSolidCube(1);

	glPopMatrix();
	
	//Finger
	glPushMatrix();
	glTranslated(-.395, .75, 0);
	glScaled(.2, .3, 1);
	glRotated(10, 1, 0, 0);
	glutSolidCube(1);
	
	glTranslated(0, 1, 0);
	glRotated(10, 1, 0, 0);
	glutSolidCube(1);

	glTranslated(0, 1, 0);
	glRotated(10, 1, 0, 0);
	glutSolidCube(1);

	glPopMatrix(); 

	//Finger
	glPushMatrix();
	glTranslated(-.15, .75, 0);
	glScaled(.2, .5, 1);
	glRotated(10, 1, 0, 0);
	glutSolidCube(1);

	
	glTranslated(0, 0, 1);
	glRotated(15, 1, 0, 0);
	glutSolidCube(1);
	
	glTranslated(0, -1, 0);
	glRotated(10, 1, 0, 0);
	glutSolidCube(1);

	glPopMatrix();


	//Finger
	glPushMatrix();
	glTranslated(.5, .20, .3);
	glScaled(.2, .5, 1);
	glRotated(20, 4, 0, 0);
	glutSolidCube(1);


	glTranslated(0,1,0);
	glRotated(10, 1, 0, 0);
	glutSolidCube(1);


	glPopMatrix();
	
	glTranslated(-.10, 0, 0);
	glScaled(.6, 1, 1);
	glutSolidCube(1);


	glPopMatrix();
	glPopMatrix();

}

void display() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0); // x axis
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 1, 0); // y axis
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 1); // z axis
	glEnd(/*GL_LINES*/);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, windowWidth, windowHeight);

	float ratio = (float)windowWidth / (float)windowHeight;
	gluPerspective(50, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);

	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

	glRotatef(yRot, 0, 1, 0);

	if (curProblem == 1) problem1();
	if (curProblem == 2) problem2();
	if (curProblem == 3) problem3();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON) rightDown = (state == GLUT_DOWN);

	lastPos[0] = x;
	lastPos[1] = y;
}

void mouseMoved(int x, int y) {
	if (leftDown) yRot += (x - lastPos[0]) * .1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1, (y - lastPos[1]) * .1);
	}


	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	curProblem = key - '0';
	if (key == 'q' || key == 'Q' || key == 27) {
		exit(0);
	}
	glutPostRedisplay();
}

void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");

	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	while (true) {
		cin.get();
	}

	return 0;
}
