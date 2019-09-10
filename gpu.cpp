#include<gl\glut.h>
#include<stdio.h>
#include<math.h>

double rotate_x,rotate_y;

int pos = 0; // 0 = rotate-y  1 = rotate-x

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glRotatef(rotate_x,1.0,0.0,0.0);
	glRotatef(rotate_y,0.0,1.0,0.0);

	glScalef(0.5,0.5,0.5);

	glBegin(GL_QUADS);                
      glColor3f(0.0f, 1.0f, 0.0f);    
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);

      glColor3f(1.0f, 0.5f, 0.0f);     
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);
 
      glColor3f(1.0f, 0.0f, 0.0f);  
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);

      glColor3f(1.0f, 1.0f, 0.0f); 
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);
 
      glColor3f(0.0f, 0.0f, 1.0f);     
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);

      glColor3f(1.0f, 0.0f, 1.0f);     
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();  

	glFlush();
	glutSwapBuffers();
}

void mouse_click(int button, int state, int x, int y)
{
	int b;
}

void mouse_listener(int button, int state, int x, int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if(state==GLUT_DOWN)
		pos = pos==1?0:1;
		break;
	}
}

void spin()
{
	rotate_x -= pos==1 ? 0.05 : 0 ;
	rotate_y -= pos==0 ? 0.05 : 0 ;
	glutPostRedisplay();
}

int main(int argc , char * argv[])
{
	glutInit(&argc,argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Rotate Cube");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutIdleFunc(spin);
	glutMouseFunc(mouse_listener);
	glutMainLoop();
	return 0;
}