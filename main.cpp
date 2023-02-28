#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

void Inicio(void){
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,480.0);
}
void PintarPixel(int x, int y){
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}


void display(){
	float x1=2;
	float x2=7;
	float y1=2;
	float y2=8;
	int interaciones;
	float rb;
	float m;
	double yk;
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glPointSize(5);
	
	m = (y2-y1)/(x2-x1);
	
	 rb= y1-(m*x1);
	
	
	 interaciones=x2-x1;
	cout<<"X" << "Y" <<endl;
	
	for(int i=1;i<=interaciones;i++){
		
		yk=lround(m*(x1)+(rb));
		PintarPixel(x1,yk);
		
		cout<<x1 << yk <<endl;
		x1=x1+1;
		
	}
	
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Demo 1");
	Inicio();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
