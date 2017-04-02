#include <gl/glut.h>   
#include <stdio.h>    
#include <string.h>    
#include <stdlib.h>   
#include <math.h> 

static int shoulder1 = 0;
static int shoulder2 = 0;
static int hand = 0;
static int turn1 = 0;
static int tag = 0;


static int turn = 0;//ת��
static float forward = 0;//ǰ��
static float elbow = 0, z = 0;
int w;
int h;
int font = (int)GLUT_BITMAP_8_BY_13;




static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

//�Ƿ�ֹͣת��
bool  IsStop = false;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);


	//�������˶�
	glPushMatrix();
	glTranslatef(forward, 0.0, z); //ǰ��  
	glRotatef((GLfloat)turn, 0.0, 1.0, 0.0);
	


	glTranslatef(0.375, 0.0, 0.0);//�����Ҵ���
	glRotatef((GLfloat)shoulder2, 1.0, 0.0, 0.0);


	glTranslatef(0.0, -0.5, 0.0);
	glColor3f(0.8, 1.0, 0.2);
	glPushMatrix();
	glScalef(0.5, 1.0, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();


	glTranslatef(0.0, -0.5, 0.0);//������С��   
	glRotatef((GLfloat)elbow, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.5, 0.0);

	glColor3f(0.5, 0.1, 0.8);
	glPushMatrix();
	glScalef(0.5, 1.0, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glTranslatef(0.0, -0.5, -0.1);//�ҽ�  

	glColor3f(32, 32, 32);

	glPushMatrix();
	glScalef(0.5, 0.1, 0.7);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(forward, 0.0, z);
	glRotatef((GLfloat)turn, 0.0, 1.0, 0.0);

	glTranslatef(-0.375, 0.0, 0.0);//�����   
	glRotatef((GLfloat)shoulder1, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.5, 0.0);

	glColor3f(0.8, 1.0, 0.2);
	glPushMatrix();
	glScalef(0.5, 1.0, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();


	glTranslatef(0.0, -0.5, 0.0);//��С��   
	glRotatef((GLfloat)elbow, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.5, 0.0);

	glColor3f(0.5, 0.1, 0.8);
	glPushMatrix();
	glScalef(0.5, 1.0, 0.5);//�����ķ���
	glutSolidCube(1.0);//���ķ���  
	glPopMatrix();
	glTranslatef(0.0, -0.5, -0.1);//���   
	glColor3f(32, 32, 32);
	glPushMatrix();
	glScalef(0.5, 0.1, 0.7);
	glutSolidCube(1.0);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(forward, 0.0, z);
	glRotatef((GLfloat)turn, 0.0, 1.0, 0.0);

	glTranslatef(0.0, 1.0, 0.0);//����   

	glColor3f(0.2, 0.2, 0.2);
	glPushMatrix();
	glScalef(1.4, 2.0, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();


	glTranslatef(0.0, 1.25, 0.0);//ͷ   
	glColor3f(1.0, 0.6, 0.4);
	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(forward, 0.0, z);
	glRotatef((GLfloat)turn, 0.0, 1.0, 0.0);


	glTranslatef(0.85, 1.75, 0.0);//�ұ�   
	glRotatef((GLfloat)shoulder1, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.5, 0.0);

	glColor3f(0.6, 0.0, 1.0);
	glPushMatrix();
	glScalef(0.3, 1.3, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	glPopMatrix();
	glPushMatrix();
	glTranslatef(forward, 0.0, z);
	glRotatef((GLfloat)turn, 0.0, 1.0, 0.0);

	glTranslatef(-0.85, 1.75, 0.0);//���   
	glRotatef((GLfloat)shoulder2, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -0.5, 0.0);

	glColor3f(0.6, 0.0, 1.0);
	glPushMatrix();
	glScalef(0.3, 1.3, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();


	glPopMatrix();


	glutSwapBuffers();
}



void reshape(int w1, int h1)
{
	w = w1;
	h = h1;
	glViewport(0, 0, (GLsizei)w1, (GLsizei)h1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w1 / (GLfloat)h1, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -8.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w': //��ǰ�� 
		turn1 = turn;
		forward = forward - 0.04*sin((GLfloat)turn1 / 360 * 3.14 * 2);
		z = z - 0.05*cos((GLfloat)turn1 / 360 * 3.14 * 2);//�ı�z �Ӷ��ı�

		if (tag == 0) {
			shoulder1 = (shoulder1 + 1);
			shoulder2 = (shoulder2 - 1);
			if (shoulder1 >= 0) { elbow = elbow - 1.2; }
			else { elbow = elbow + 1.2; }
		}
		else
		{
			shoulder1 = (shoulder1 - 1);
			shoulder2 = (shoulder2 + 1);
			if (shoulder1 >= 0) { elbow = elbow + 1.25; }
			else { elbow = elbow - 1.2; }
		}
		if (shoulder1>30) {
			tag = 1;
		}
		if (shoulder1<-30) {
			tag = 0;
		}
		IsStop = true;
		glutPostRedisplay();
		break;
	case 's': //����� 
		turn1 = turn;
		forward = forward + 0.04*sin((GLfloat)turn1 / 360 * 3.14 * 2);
		z = z + 0.05*cos((GLfloat)turn1 / 360 * 3.14 * 2);
		if (tag == 0) {
			shoulder1 = (shoulder1 - 1);
			shoulder2 = (shoulder2 + 1);
		}
		else
		{
			shoulder1 = (shoulder1 + 1);
			shoulder2 = (shoulder2 - 1);
		}
		if (shoulder1>30) {
			tag = 0;
		}
		if (shoulder1<-30) {
			tag = 1;
		}
		IsStop = true;
		glutPostRedisplay();
		break;
	case 'd'://��ת
		turn = (turn - 5) % 360;
		glutPostRedisplay();
		IsStop = true;
		break;
	case 'a'://��ת
		turn = (turn + 5) % 360;
		glutPostRedisplay();
		IsStop = true;
		break;
	
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("walking robots!!");
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);


	glutMainLoop();
	return 0;
}