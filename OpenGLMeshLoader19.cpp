#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <ctime>
#include <windows.h>
#include "TextureBuilder.h"
#include "Model_3DS.h"
#include "GLTexture.h"
#include <glut.h>
#include <string> 

using namespace std;

#define GLUT_KEY_ESCAPE 27
#define DEG2RAD(a) (a * 0.0174532925)

// Textures
GLTexture tex_wall1;
GLTexture tex_floor;
int render = 0;

int level = 1;		//SELEEM game level lw katabt 1 haytl3lak hagty
int camView = 1;
int coinRot = 0;
int renderPU = 1;

int renderKey1 = 1;
int hasKey1 = 0;
int renderKey2 = 1;
int hasKey2 = 0;

int renderCoin1 = 1;
int renderCoin2 = 1;
int renderCoin3 = 1;
int renderCoin4 = 1;


float posX = 0;
float posY = 0;
float posZ = -0.01;

float posXS = -0.010;
float posYS = 0;
float posZS = -0.02;

float keyRedX = 0.5;
float keyRedZ = 0.25;

float keyBlueX = 0.2;
float keyBlueZ = 0.05;

float doorRedX = 0.2;
float doorRedZ = 0.5;

float doorBlueX = 0.4;
float doorBlueZ = 0;

boolean c1taken = false;
float c1x = 0.1;
float c1z = 0.25;

boolean c2taken = false;
float c2x = 0.5;
float c2z = 0.15;

boolean c3taken = false;
float c3x = 0.3;
float c3z = 0.05;

boolean c4taken = false;
float c4x = 0.5;
float c4z = 0.05;

boolean ptaken = false;
float px = 0.3;
float pz = 0.45;

string keys[2];

float fenceR = 0;
float fenceG = 0;
float fenceB = 0;

int kr = 0;
int kb = 0;
int body = 1;
int direction = 1; // WSAD
int score = 0;

int endGame = 0;

int timeGame = 60;


float Yignore = 0.01;
float lightIntenso = 1.6;



class Vector3f {
public:
	float x, y, z;

	Vector3f(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f) {
		x = _x;
		y = _y;
		z = _z;
	}

};

class Camera {
public:
	Vector3f eye, center, up;
	float startX;
	float endX;
	float startY;
	float endY;
	float startZ;
	float endZ;


	Camera(float eyeX = 0.1f, float eyeY = 0.1f, float eyeZ = 0.1f, float centerX = 0.0f, float centerY = 0.0f, float centerZ = 0.0f,
		float upX = 0.0f, float upY = 1.0f, float upZ = 0.0f) {
		eye = Vector3f(eyeX, eyeY, eyeZ);
		center = Vector3f(centerX, centerY, centerZ);
		up = Vector3f(upX, upY, upZ);
		startX = -1;
		endX = 1;
		startY = -1;
		endY = 1;
		startZ = -10;
		endZ = 50;
	}



	void firstPerson() {
		if (level == 1) { // W S A D
			if (direction == 1) {
				startX = -0.1;
				endX = 0.3;
				startY = -0.7 - 0.1 * (0.43 + posZ);
				endY = -0.25 - 0.1 * (0.43 + posZ);
				startZ = 4.05 - 2 * posZ;
				endZ = 10;


				eye.x = 0;
				eye.y = 1;
				eye.z = 5;
				center.x = 0;
				center.y = 0.7;
				center.z = 0;
				up.x = 0;
				up.y = 1;
				up.z = 0;

			}

			if (direction == 2) {
				startX = -0.32;
				endX = 0.08;
				startY = -0.7 + 0.12 * (0.43 + posZ);
				endY = -0.25 + 0.12 * (0.43 + posZ);
				startZ = 5.95 + 2 * posZ;  //hena  /mehtag azawedo
				endZ = 10;


				eye.x = 0;
				eye.y = 1;
				eye.z = -5;
				center.x = 0;
				center.y = 0.7;
				center.z = 0;
				up.x = 0;
				up.y = 1;
				up.z = 0;

			}
			if (direction == 3) {
				startX = -0.33;
				endX = 0.07;
				startY = -0.7 - (0.1 * posX);
				endY = -0.25 - (0.1 * posX);
				startZ = 3.85 - 2 * (posX - 0.5);
				endZ = 6;


				eye.x = 5;
				eye.y = 1;
				eye.z = 0;
				center.x = 0;
				center.y = 0.7;
				center.z = 0;
				up.x = 0;
				up.y = 1;
				up.z = 0;

			}
			if (direction == 4) {
				startX = -0.07;
				endX = 0.3;
				startY = -0.62 + 0.08 * (-0.5 + posX);
				endY = -0.2 + 0.08 * (-0.5 + posX);
				startZ = 5.1 + 2 * posX;
				endZ = 10;


				eye.x = -5;
				eye.y = 1;
				eye.z = 0;
				center.x = 0;
				center.y = 0.7;
				center.z = 0;
				up.x = 0;
				up.y = 1;
				up.z = 0;

			}
		}
		else {
			if (direction == 1) {
				startX = -0.1;
				endX = 0.3;
				startY = -0.7 - 0.1 * (0.43 + posZ);
				endY = -0.25 - 0.1 * (0.43 + posZ);
				startZ = 4.05 - 2 * posZ;
				endZ = 10;


				eye.x = 0;
				eye.y = 1;
				eye.z = 5;
				center.x = 0;
				center.y = 0.7;
				center.z = 0;
				up.x = 0;
				up.y = 1;
				up.z = 0;

			}

			if (direction == 2) {
				startX = -0.32;
				endX = 0.08;
				startY = -0.7 + 0.12 * (0.43 + posZ);
				endY = -0.25 + 0.12 * (0.43 + posZ);
				startZ = 5.95 + 2 * posZ;  //hena  /mehtag azawedo
				endZ = 10;


				eye.x = 0;
				eye.y = 1;
				eye.z = -5;
				center.x = 0;
				center.y = 0.7;
				center.z = 0;
				up.x = 0;
				up.y = 1;
				up.z = 0;

			}
			if (direction == 3) {
				startX = -0.33;
				endX = 0.07;
				startY = -0.7 - (0.1 * posX);
				endY = -0.25 - (0.1 * posX);
				startZ = 3.85 - 2 * (posX - 0.5);
				endZ = 6;


				eye.x = 5;
				eye.y = 1;
				eye.z = 0;
				center.x = 0;
				center.y = 0.7;
				center.z = 0;
				up.x = 0;
				up.y = 1;
				up.z = 0;

			}
			if (direction == 4) {
				startX = -0.07;
				endX = 0.3;
				startY = -0.62 + 0.08 * (-0.5 + posX);
				endY = -0.2 + 0.08 * (-0.5 + posX);
				startZ = 5.1 + 2 * posX;
				endZ = 10;


				eye.x = -5;
				eye.y = 1;
				eye.z = 0;
				center.x = 0;
				center.y = 0.7;
				center.z = 0;
				up.x = 0;
				up.y = 1;
				up.z = 0;

			}
		}
	}

	void normalView() {

		startX = -1;
		endX = 1;
		startY = -1;
		endY = 1;
		startZ = -10;
		endZ = 50;

		eye.x = 0.1f;
		eye.y = 0.1f;
		eye.z = 0.1f;
		center.x = 0;
		center.y = 0;
		center.z = 0;


	}


	void look() {
		if (camView == 1) {

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(startX, endX, startY, endY, startZ, endZ);

			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(
				eye.x, eye.y, eye.z,
				center.x, center.y, center.z,
				up.x, up.y, up.z
			);

		}
		else {
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glFrustum(startX, endX, startY, endY, startZ, endZ);

			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(
				eye.x, eye.y, eye.z,
				center.x, center.y, center.z,
				up.x, up.y, up.z
			);
		}
	}
};

Camera camera;


void drawPlayer() {

	glPushMatrix();

	glTranslated(0, 0, 0.25);
	glScaled(0.5, 1, 0.5);

	glPushMatrix();
	glColor3f(0.9 , 1 , 0.9);
	glScalef(0.1, 0.1, 0.1);
	glTranslated(1.1, 3, 4.5);
	glutSolidSphere(0.3, 15, 15);


	glColor3f(0.1, 0.9, 0.5);
	glTranslated(0, -0.35, 0);
	glScalef(0.2, 0.2, 0.2);
	glutSolidCube(1);

	glColor4f(1, 1, 1, 0);
	glTranslated(0, -3.5, 0);
	glScalef(4, 6, 3);
	glutSolidCube(1);

	glPopMatrix();


	int angle = 45;
	float slideup = 0;
	if (endGame == 1) {
		angle = 180;
		slideup = 0.1;
	}

	glPushMatrix();
	glTranslated(0.04, 0.20 + slideup, 0.45);
	glRotated(-angle, 0, 0, 1);
	glColor3f(1, 1, 0);
	glScalef(0.022, 0.13, 0.03);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslated(0.182, 0.20 + slideup, 0.45);
	glRotated(angle, 0, 0, 1);
	glColor3f(1 , 1 , 0);
	glScalef(0.022, 0.13, 0.03);
	glutSolidCube(1);
	glPopMatrix();

	if (body == 1) {
		glPushMatrix();

		glColor3f(1, 1, 0);
		glTranslated(0.09, 0.15, 0.45);
		glRotated(90, 1, 0, 0);
		glutSolidCone(0.015, 0.14, 15, 15);
		glPopMatrix();

		glPushMatrix();

		glColor3f(1, 1, 0);
		glTranslated(0.125, 0.15, 0.45);
		glRotated(90, 1, 0, 0);
		glutSolidCone(0.015, 0.14, 15, 15);
		glPopMatrix();
	}
	if (body == 2) {
		glPushMatrix();
		glColor3f(1, 1, 0);
		glTranslated(0.09, 0.15, 0.45);
		glRotated(90, 1, 0, 0);
		glutSolidCone(0.015, 0.14, 15, 15);
		glPopMatrix();

		glPushMatrix();

		glColor3f(1, 1, 0);
		glTranslated(0.125, 0.15, 0.45);
		glRotated(60, 1, 0, 0);
		glutSolidCone(0.015, 0.14, 15, 15);
		glPopMatrix();
	}
	if (body == 3) {
		glPushMatrix();

		glColor3f(1, 1, 0);
		glTranslated(0.09, 0.15, 0.45);
		glRotated(60, 1, 0, 0);
		glutSolidCone(0.015, 0.14, 15, 15);
		glPopMatrix();

		glPushMatrix();
		glColor3f(1, 1, 0);
		glTranslated(0.125, 0.15, 0.45);
		glRotated(90, 1, 0, 0);
		glutSolidCone(0.015, 0.14, 15, 15);
		glPopMatrix();
	}



	glPopMatrix();



}

void drawGround(double thickness) {

	//glEnable(GL_LIGHTING);

	glColor3f(0.5, 0.5, 0.5);	// Dim the ground texture a bit

	glEnable(GL_TEXTURE_2D);	// Enable 2D texturing

	glBindTexture(GL_TEXTURE_2D, tex_floor.texture[0]);	// Bind the ground texture

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0, 0, 0);glTexCoord2f(0, 3);
	glVertex3f(0.6, 0, 0);glTexCoord2f(1, 3);
	glVertex3f(0.6, 0, 0.5);glTexCoord2f(1, 0);
	glVertex3f(0, 0, 0.5);
	glEnd();
	glPopMatrix();

}
void drawGroundS(double thickness) {

	glColor3f(2, 2, 2);	// Dim the ground texture a bit

	glEnable(GL_TEXTURE_2D);	// Enable 2D texturing

	glBindTexture(GL_TEXTURE_2D, tex_floor.texture[0]);	// Bind the ground texture

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.05, 0, -0.1);glTexCoord2f(0, 2);
	glVertex3f(0.55, 0, -0.1);glTexCoord2f(2, 2);
	glVertex3f(0.55, 0, 0.6);glTexCoord2f(2, 0);
	glVertex3f(0.05, 0, 0.6);
	glEnd();
	glPopMatrix();
}
void drawDoorRed()
{
	glScaled(0.1, 0.2, 0.02);
	glColor4f(1, 0, 0, 0);
	glutSolidCube(1);
	glPopMatrix();
}
void drawDoorBlue()
{
	glPushMatrix();
	glTranslated(doorBlueX, 0.1, doorBlueZ);
	glScaled(0.1, 0.2, 0.02);
	glColor4f(0.5, 00.1, 1, 0);
	glutSolidCube(1);
	glPopMatrix();
}
void doorKey2(float edge)
{
	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslated(0, 0, 0);
	glScaled(edge * 1.7, edge, 0.1 * edge);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(edge * 0.5, 0, 0);
	glColor3f(0, 0, 0);
	glutSolidSphere(edge * 0.1, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-edge * 0.5, 0, 0);
	glColor3f(0, 0, 0);
	glutSolidSphere(edge * 0.1, 15, 15);
	glPopMatrix();
}

void drawWallS1()
{


	glEnable(GL_LIGHTING);

	glColor3f(2, 2, 2);	// Dim the ground texture a bit


	glEnable(GL_TEXTURE_2D);	// Enable 2D texturing

	glBindTexture(GL_TEXTURE_2D, tex_wall1.texture[0]);	// Bind the ground texture

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.25, 0, 0.6);glTexCoord2f(0, 3);
	glVertex3f(0.55, 0, 0.6);glTexCoord2f(1, 3);
	glVertex3f(0.55, 0.2, 0.6);glTexCoord2f(1, 0);
	glVertex3f(0.25, 0.2, 0.6);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.05, 0, 0.6);glTexCoord2f(0, 1);
	glVertex3f(0.15, 0, 0.6);glTexCoord2f(1, 1);
	glVertex3f(0.15, 0.2, 0.6);glTexCoord2f(1, 0);
	glVertex3f(0.05, 0.2, 0.6);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.25, 0, 0.5);glTexCoord2f(0, 1);
	glVertex3f(0.35, 0, 0.5);glTexCoord2f(1, 1);
	glVertex3f(0.35, 0.2, 0.5);glTexCoord2f(1, 0);
	glVertex3f(0.25, 0.2, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.25, 0, 0.4);glTexCoord2f(0, 1);
	glVertex3f(0.35, 0, 0.4);glTexCoord2f(1, 1);
	glVertex3f(0.35, 0.2, 0.4);glTexCoord2f(1, 0);
	glVertex3f(0.25, 0.2, 0.4);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.15, 0, 0.3);glTexCoord2f(0, 1);
	glVertex3f(0.25, 0, 0.3);glTexCoord2f(1, 1);
	glVertex3f(0.25, 0.2, 0.3);glTexCoord2f(1, 0);
	glVertex3f(0.15, 0.2, 0.3);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.25, 0, 0.2);glTexCoord2f(0, 2);
	glVertex3f(0.45, 0, 0.2);glTexCoord2f(1, 2);
	glVertex3f(0.45, 0.2, 0.2);glTexCoord2f(1, 0);
	glVertex3f(0.25, 0.2, 0.2);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.15, 0, 0.1);glTexCoord2f(0, 2);
	glVertex3f(0.35, 0, 0.1);glTexCoord2f(1, 2);
	glVertex3f(0.35, 0.2, 0.1);glTexCoord2f(1, 0);
	glVertex3f(0.15, 0.2, 0.1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.45, 0, 0.1);glTexCoord2f(0, 1);
	glVertex3f(0.55, 0, 0.1);glTexCoord2f(1, 1);
	glVertex3f(0.55, 0.2, 0.1);glTexCoord2f(1, 0);
	glVertex3f(0.45, 0.2, 0.1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.05, 0, 0);glTexCoord2f(0, 3);
	glVertex3f(0.35, 0, 0);glTexCoord2f(1, 3);
	glVertex3f(0.35, 0.2, 0);glTexCoord2f(1, 0);
	glVertex3f(0.05, 0.2, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.05, 0, -0.1);glTexCoord2f(0, 5);
	glVertex3f(0.55, 0, -0.1);glTexCoord2f(1, 5);
	glVertex3f(0.55, 0.2, -0.1);glTexCoord2f(1, 0);
	glVertex3f(0.05, 0.2, -0.1);
	glEnd();
	glPopMatrix();
}
void drawWallS2()
{
	glColor3f(2, 2, 2);	// Dim the ground texture a bit

	glEnable(GL_TEXTURE_2D);	// Enable 2D texturing

	glBindTexture(GL_TEXTURE_2D, tex_wall1.texture[0]);	// Bind the ground texture

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.05, 0, 0);glTexCoord2f(0, 6);
	glVertex3f(0.05, 0, 0.6);glTexCoord2f(1, 6);
	glVertex3f(0.05, 0.2, 0.6);glTexCoord2f(1, 0);
	glVertex3f(0.05, 0.2, 0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.15, 0, 0.1);glTexCoord2f(0, 4);
	glVertex3f(0.15, 0, 0.5);glTexCoord2f(1, 4);
	glVertex3f(0.15, 0.2, 0.5);glTexCoord2f(1, 0);
	glVertex3f(0.15, 0.2, 0.1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.25, 0, 0.4);glTexCoord2f(0, 1);
	glVertex3f(0.25, 0, 0.5);glTexCoord2f(1, 1);
	glVertex3f(0.25, 0.2, 0.5);glTexCoord2f(1, 0);
	glVertex3f(0.25, 0.2, 0.4);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.35, 0, 0);glTexCoord2f(0, 1);
	glVertex3f(0.35, 0, 0.1);glTexCoord2f(1, 1);
	glVertex3f(0.35, 0.2, 0.1);glTexCoord2f(1, 0);
	glVertex3f(0.35, 0.2, 0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.35, 0, 0.2);glTexCoord2f(0, 2);
	glVertex3f(0.35, 0, 0.4);glTexCoord2f(1, 2);
	glVertex3f(0.35, 0.2, 0.4);glTexCoord2f(1, 0);
	glVertex3f(0.35, 0.2, 0.2);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.45, 0, 0.3);glTexCoord2f(0, 2);
	glVertex3f(0.45, 0, 0.5);glTexCoord2f(1, 2);
	glVertex3f(0.45, 0.2, 0.5);glTexCoord2f(1, 0);
	glVertex3f(0.45, 0.2, 0.3);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.45, 0, 0);glTexCoord2f(0, 2);
	glVertex3f(0.45, 0, 0.2);glTexCoord2f(1, 2);
	glVertex3f(0.45, 0.2, 0.2);glTexCoord2f(1, 0);
	glVertex3f(0.45, 0.2, 0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.55, 0, -0.1);glTexCoord2f(0, 7);
	glVertex3f(0.55, 0, 0.6);glTexCoord2f(1, 7);
	glVertex3f(0.55, 0.2, 0.6);glTexCoord2f(1, 0);
	glVertex3f(0.55, 0.2, -0.1);
	glEnd();
	glPopMatrix();

}


void drawWall1() {
	//glDisable(GL_LIGHTING);	// Disable lighting 

	glColor3f(0.5, 0.5, 0.5);	// Dim the ground texture a bit

	glEnable(GL_TEXTURE_2D);	// Enable 2D texturing

	glBindTexture(GL_TEXTURE_2D, tex_wall1.texture[0]);	// Bind the ground texture

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.1, 0, 0.5);glTexCoord2f(0, 5);
	glVertex3f(0.6, 0, 0.5);glTexCoord2f(1, 5);
	glVertex3f(0.6, 0.2, 0.5);glTexCoord2f(1, 0);
	glVertex3f(0.1, 0.2, 0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.1, 0, 0.4);glTexCoord2f(0, 1);
	glVertex3f(0.2, 0, 0.4);glTexCoord2f(1, 1);
	glVertex3f(0.2, 0.2, 0.4);glTexCoord2f(1, 0);
	glVertex3f(0.1, 0.2, 0.4);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.4, 0, 0.4);glTexCoord2f(0, 1);
	glVertex3f(0.5, 0, 0.4);glTexCoord2f(1, 1);
	glVertex3f(0.5, 0.2, 0.4);glTexCoord2f(1, 0);
	glVertex3f(0.4, 0.2, 0.4);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.1, 0, 0.3);glTexCoord2f(0, 3);
	glVertex3f(0.4, 0, 0.3);glTexCoord2f(1, 3);
	glVertex3f(0.4, 0.2, 0.3);glTexCoord2f(1, 0);
	glVertex3f(0.1, 0.2, 0.3);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.5, 0, 0.3);glTexCoord2f(0, 1);
	glVertex3f(0.6, 0, 0.3);glTexCoord2f(1, 1);
	glVertex3f(0.6, 0.2, 0.3);glTexCoord2f(1, 0);
	glVertex3f(0.5, 0.2, 0.3);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0, 0, 0.2);glTexCoord2f(0, 1);
	glVertex3f(0.1, 0, 0.2);glTexCoord2f(1, 1);
	glVertex3f(0.1, 0.2, 0.2);glTexCoord2f(1, 0);
	glVertex3f(0, 0.2, 0.2);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.3, 0, 0.2);glTexCoord2f(0, 1);
	glVertex3f(0.4, 0, 0.2);glTexCoord2f(1, 1);
	glVertex3f(0.4, 0.2, 0.2);glTexCoord2f(1, 0);
	glVertex3f(0.3, 0.2, 0.2);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.1, 0, 0.1);glTexCoord2f(0, 2);
	glVertex3f(0.3, 0, 0.1);glTexCoord2f(1, 2);
	glVertex3f(0.3, 0.2, 0.1);glTexCoord2f(1, 0);
	glVertex3f(0.1, 0.2, 0.1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0.5, 0, 0.1);glTexCoord2f(0, 1);
	glVertex3f(0.6, 0, 0.1);glTexCoord2f(1, 1);
	glVertex3f(0.6, 0.2, 0.1);glTexCoord2f(1, 0);
	glVertex3f(0.5, 0.2, 0.1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);glTexCoord2f(0, 0);
	glVertex3f(0, 0, 0);glTexCoord2f(0, 6);
	glVertex3f(0.6, 0, 0);glTexCoord2f(1, 6);
	glVertex3f(0.6, 0.2, 0);glTexCoord2f(1, 0);
	glVertex3f(0, 0.2, 0);
	glEnd();
	glPopMatrix();

	//glEnable(GL_LIGHTING);

	//glColor3f(0.9, 0.9, 0.9);
}

void drawWall2() {
	//glDisable(GL_LIGHTING);	// Disable lighting 

	glColor3f(0.5, 0.5, 0.5);	// Dim the ground texture a bit

	glEnable(GL_TEXTURE_2D);	// Enable 2D texturing

	glBindTexture(GL_TEXTURE_2D, tex_wall1.texture[0]);	// Bind the ground texture


	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(0, 0, 0);
	glTexCoord2f(0, 5);
	glVertex3f(0, 0, 0.5);
	glTexCoord2f(1, 5);
	glVertex3f(0, 0.2, 0.5);
	glTexCoord2f(1, 0);
	glVertex3f(0, 0.2, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(0.1, 0, 0.3);
	glTexCoord2f(0, 1);
	glVertex3f(0.1, 0, 0.4);
	glTexCoord2f(1, 1);
	glVertex3f(0.1, 0.2, 0.4);
	glTexCoord2f(1, 0);
	glVertex3f(0.1, 0.2, 0.3);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex3f(0.2, 0, 0.2);
	glTexCoord2f(0, 1);
	glVertex3f(0.2, 0, 0.3);
	glTexCoord2f(1, 1);
	glVertex3f(0.2, 0.2, 0.3);
	glTexCoord2f(1, 0);
	glVertex3f(0.2, 0.2, 0.2);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glBegin(GL_QUADS);	glTexCoord2f(0, 0);
	glVertex3f(0.3, 0, 0.3);	glTexCoord2f(0, 2);
	glVertex3f(0.3, 0, 0.5);	glTexCoord2f(1, 2);
	glVertex3f(0.3, 0.2, 0.5);	glTexCoord2f(1, 0);
	glVertex3f(0.3, 0.2, 0.3);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glBegin(GL_QUADS);	glTexCoord2f(0, 0);
	glVertex3f(0.3, 0, 0.1);	glTexCoord2f(0, 1);
	glVertex3f(0.3, 0, 0.2);	glTexCoord2f(1, 1);
	glVertex3f(0.3, 0.2, 0.2);	glTexCoord2f(1, 0);
	glVertex3f(0.3, 0.2, 0.1);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glBegin(GL_QUADS);	glTexCoord2f(0, 0);
	glVertex3f(0.4, 0, 0);	glTexCoord2f(0, 1);
	glVertex3f(0.4, 0, 0.1);	glTexCoord2f(1, 1);
	glVertex3f(0.4, 0.2, 0.1);	glTexCoord2f(1, 0);
	glVertex3f(0.4, 0.2, 0);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glBegin(GL_QUADS);	glTexCoord2f(0, 0);
	glVertex3f(0.4, 0, 0.2);	glTexCoord2f(0, 1);
	glVertex3f(0.4, 0, 0.3);	glTexCoord2f(1, 1);
	glVertex3f(0.4, 0.2, 0.3);	glTexCoord2f(1, 0);
	glVertex3f(0.4, 0.2, 0.2);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);	glTexCoord2f(0, 0);
	glVertex3f(0.5, 0, 0.1);	glTexCoord2f(0, 1);
	glVertex3f(0.5, 0, 0.2);	glTexCoord2f(1, 1);
	glVertex3f(0.5, 0.2, 0.2); 	glTexCoord2f(1, 0);
	glVertex3f(0.5, 0.2, 0.1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);	glTexCoord2f(0, 0);
	glVertex3f(0.5, 0, 0.3);	glTexCoord2f(0, 1);
	glVertex3f(0.5, 0, 0.4);	glTexCoord2f(1, 1);
	glVertex3f(0.5, 0.2, 0.4);	glTexCoord2f(1, 0);
	glVertex3f(0.5, 0.2, 0.3);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);	glTexCoord2f(0, 0);
	glVertex3f(0.6, 0, 0);	glTexCoord2f(0, 1);
	glVertex3f(0.6, 0, 0.1);	glTexCoord2f(1, 1);
	glVertex3f(0.6, 0.2, 0.1);	glTexCoord2f(1, 0);
	glVertex3f(0.6, 0.2, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);	glTexCoord2f(0, 0);
	glVertex3f(0.6, 0, 0.2);	glTexCoord2f(0, 3);
	glVertex3f(0.6, 0, 0.5);	glTexCoord2f(1, 3);
	glVertex3f(0.6, 0.2, 0.5);	glTexCoord2f(1, 0);
	glVertex3f(0.6, 0.2, 0.2);
	glEnd();
	glPopMatrix();

	//glEnable(GL_LIGHTING);

	glColor3f(0.9, 0.9, 0.9);
}

void squareLamp(float side) {

	glPushMatrix();
	glColor3f(0.9, 0.7, 1);
	glTranslated(0, 0, 0.1);
	glScaled(side, side, side);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.9, 0.8, 0.9);
	glTranslated(side / 2, side + 0.1, side / 2);
	glScaled(side, side, side);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.9, 0.9, 0.8);
	glTranslated(0, (2 * side) + 0.1, 0.1);
	glScaled(side, side, side);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.9, 1, 0.7);
	glTranslated(side / 2, (3 * side) + 0.1, side / 2);
	glScaled(side, side, side);
	glutSolidCube(1);
	glPopMatrix();

}

void bigLamp(float length, float radius)
{

	glPushMatrix();
	glScaled(0.2, 0.2, 1.0);
	glTranslated(0, 2.55 * length, 0);
	glColor3f(0.2, 1, 1);
	glutSolidSphere(0.35, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glRotated(-90.0, 1, 0, 0);
	glTranslated(0, 1.8 * length, 0);
	glColor3f(0.2, 1, 1);
	glutSolidTorus(0.055, 0.25, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotated(-90.0, 1, 0, 0);
	glTranslated(0, 1.2 * length, 0);
	glColor3f(0.2, 1, 1);
	glutSolidTorus(0.06, 0.3, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotated(-90.0, 1, 0, 0);
	glTranslated(0, 0.6 * length, 0);
	glColor3f(0.2, 1, 1);
	glutSolidTorus(0.065, 0.35, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotated(-90.0, 1, 0, 0);
	glTranslated(0, 0, 0);
	glColor3f(0.2, 1, 1);
	glutSolidTorus(0.07, 0.4, 20, 20);
	glPopMatrix();

	glPushMatrix();
	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();


	glTranslated(0, 1, 0);
	glColor3f(0.0f, 0.0f, 0.0f);
	gluCylinder(quadratic, radius * 1.5, radius, 1.5 * length, 15, 15);
	glPopMatrix();
}

void coins()
{
	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);
	glColor3f(0.81, 0.71, 0.23);
	glutWireIcosahedron();
	glPopMatrix();
}
void powerS()
{
	glPushMatrix();
	glColor3f(1, 0, 1);
	glutSolidSphere(0.015, 15, 15);
	glPopMatrix();
}
void doorKey(float edge, int r, int g, int b)
{
	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(0, 0, 0);
	glScaled(edge * 1.7, edge, 0.1 * edge);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(edge * 0.5, 0, 0);
	glColor3f(0, 0, 0);
	glutSolidSphere(edge * 0.1, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-edge * 0.5, 0, 0);
	glColor3f(0, 0, 0);
	glutSolidSphere(edge * 0.1, 15, 15);
	glPopMatrix();
}

void doorKeySlot(float edge)
{
	glPushMatrix();
	glColor3f(0.90, 0.91, 0.98);
	glTranslated(0, 0, 0);
	glScaled(edge * 1.7, edge, 0.1 * edge);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(edge * 0.5, 0, 0);
	glColor3f(0, 0, 0);
	glutSolidSphere(edge * 0.1, 15, 15);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-edge * 0.5, 0, 0);
	glColor3f(0, 0, 0);
	glutSolidSphere(edge * 0.1, 15, 15);
	glPopMatrix();
}

void door(float height, float width, float thick, int r, int g, int b)
{
	glPushMatrix();
	glColor3f(r, g, b);
	glTranslated(0, 0, 0);
	glScaled(width, height, thick);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(width * 0.5, 0, 0);
	glScaled(width * 0.05, height, thick * 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslated(-width * 0.5, 0, 0);
	glScaled(width * 0.05, height, thick * 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glRotatef(90, 0, 0, 1);
	glTranslated(height * 0.5, 0, 0);
	glScaled(width * 0.05, width, thick * 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glRotatef(90, 0, 0, 1);
	glTranslated(-height * 0.5, 0, 0);
	glScaled(width * 0.05, width, thick * 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glRotatef(22, 0, 0, 1);
	glTranslated(0, 0, 0);
	glScaled(width * 0.05, height * 1.05, thick * 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glRotatef(-22, 0, 0, 1);
	glTranslated(0, 0, 0);
	glScaled(width * 0.05, height * 1.05, thick * 2);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslated(width * 0.35, 0, 0.2);
	doorKeySlot(0.15);
	glPopMatrix();

}


void setupLights1() {
	GLfloat ambient[] = { 0.7f, 0.7f, 0.7, 1.0f };
	GLfloat diffuse[] = { 0.6f, 0.6f, 0.6, 1.0f };
	GLfloat specular[] = { 1.0f, 1.0f, 1.0, 1.0f };
	GLfloat shininess[] = { 50 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

	GLfloat lightIntensity[] = { lightIntenso, lightIntenso, lightIntenso, 1.0f };
	GLfloat lightPosition[] = { 0, 2, 0, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);

	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 15.0);
	GLfloat spot_direction[] = { 0.0, -1.0, 0.0 };
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 2.0);
}

void setupCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 5);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camera.look();
}

void print(float x, float y, char* string, int numb)
{
	int len, i;

	//set the position of the text in the window using the x and y coordinates
	glRasterPos2f(x, y);

	//get the length of the string to display
	len = (int)strlen(string);

	//loop to display character by character
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}


	std::string s = std::to_string(numb);
	len = s.length();
	for (i = 0; i < len; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
	}
}

void Display() {
	setupCamera();
	setupLights1();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();	glPopMatrix();
	glPopMatrix();
	glPopMatrix();	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	char* p0s[20];


	if (endGame == 2) {


		sprintf((char*)p0s, "0 You lost... ");
		print(-0.3, 0, (char*)p0s, 0);

		sprintf((char*)p0s, "Score: ");
		print(-0.2, -0.2, (char*)p0s, score);

		glFlush();

		return;
	}

	if (endGame == 3) {

		sprintf((char*)p0s, "0 YOU HAVE WONN!!!! ");
		print(-0.6, 0, (char*)p0s, 0);

		sprintf((char*)p0s, "Score: ");
		print(-0.2, -0.2, (char*)p0s, score);


		glFlush();

		return;
	}

	if (level == 1) {
		glPushMatrix();
		if (camView == 2 && direction == 1)
			glTranslated(-2 * posX, 0, 0);

		if (camView == 2 && direction == 2)
			glTranslated(-2 * posX, 0, 0);

		if (camView == 2 && direction == 3)
			glTranslated(0, 0, -2 * (posZ + 0.41));  //mehtaga tetzabat f level 2

		if (camView == 2 && direction == 4)
			glTranslated(0, 0, -2 * (posZ + 0.41));  //mehtaga tetzabat f level 2


		glPushMatrix();
		glTranslated(0, 0.2, 0);
		glScaled(0.2, 0.2, 0.2);
		squareLamp(0.5);
		glPopMatrix();

		/*glPushMatrix();
		glTranslated(0.3, 0.3, 0);
		glScaled(0.1, 0.1, 0.1);
		bigLamp(2, 0.03);
		glPopMatrix();*/

		if (renderPU == 1) {
			glPushMatrix();
			glTranslated(0.1, 0.15, 0.15);
			glScaled(0.1, 0.1, 0.1);
			glColor3f(0.8, 0.3, 0);
			glutSolidSphere(0.3, 15, 15);
			glPopMatrix();
		}

		if (renderKey1 == 1 && hasKey1 == 0) {
			glPushMatrix();
			glTranslated(0.3, 0.1, 0.7);
			glScaled(0.1, 0.1, 0.2);
			doorKey(0.8, 5, 0, 0);						//red key
			glPopMatrix();
		}

		if (renderKey1 == 1) {
			glPushMatrix();
			glTranslated(0.3, 0.15, 0.4);
			glScaled(0.14, 0.2, 0.04);			//red wall
			door(1.2, 1, 0.5, 5, 0, 0);
			glPopMatrix();
		}
		if (renderKey2 == 1 && hasKey2 == 0) {
			glPushMatrix();
			glTranslated(1.1, 0.1, 0.7);
			glScaled(0.1, 0.1, 0.2);
			doorKey(0.8, 0, 0, 5);						//green key
			glPopMatrix();
		}
		if (renderKey2 == 1) {
			glPushMatrix();
			glTranslated(0.9, 0.15, 0.2);
			glScaled(0.14, 0.2, 0.04);			//green wall
			door(1.2, 1, 0.5, 0, 0, 5);
			glPopMatrix();
		}

		if (renderCoin1 == 1) {
			glPushMatrix();
			glTranslated(1.1, 0.15, 0.1);
			glRotated(coinRot, 0, 1, 0);
			glScaled(0.1, 0.1, 0.1);
			glColor3f(0.8, 0.3, 0);
			coins();
			glPopMatrix();
		}
		if (renderCoin2 == 1) {
			glPushMatrix();
			glTranslated(0.7, 0.15, 0.1);
			glRotated(coinRot, 0, 1, 0);
			glScaled(0.1, 0.1, 0.1);
			glColor3f(0.8, 0.3, 0);
			coins();
			glPopMatrix();
		}
		if (renderCoin3 == 1) {
			glPushMatrix();
			glTranslated(0.7, 0.15, 0.8);
			glRotated(coinRot, 0, 1, 0);
			glScaled(0.1, 0.1, 0.1);
			glColor3f(0.8, 0.3, 0);
			coins();
			glPopMatrix();
		}
		if (renderCoin4 == 1) {
			glPushMatrix();
			glTranslated(0.5, 0.15, 0.5);
			glRotated(coinRot, 0, 1, 0);
			glScaled(0.1, 0.1, 0.1);
			glColor3f(0.8, 0.3, 0);
			coins();
			glPopMatrix();
		}

		glScaled(2, 1, 2);

		drawWall1();
		drawWall2();

		glPushMatrix();
		glTranslated(posX, posY, posZ);
		if (direction == 1) {
			glRotated(180, 0, 1, 0);
			glTranslated(-0.11, 0, -0.95);
		}
		if (direction == 4) {
			glRotated(90, 0, 1, 0);
			glTranslated(-0.525, 0, -0.41);
		}
		if (direction == 3) {

			glTranslated(0.54, 0, 0.415);
			glRotated(270, 0, 1, 0);
		}
		drawPlayer();
		glPopMatrix();

		glPushMatrix();
		drawGround(0.02);  //GROUND
		glPopMatrix();

		sprintf((char*)p0s, "Time Left: ");
		print(-0.4, 0.6, (char*)p0s, timeGame);

		sprintf((char*)p0s, "Score: ");
		print(0.2, 1.2, (char*)p0s, score);

		glPopMatrix();

		glFlush();
	}
	else {

		glPushMatrix();
		if (camView == 2 && direction == 1)
			glTranslated(-2 * posX, 0, 0);

		if (camView == 2 && direction == 2)
			glTranslated(-2 * posX, 0, 0);

		if (camView == 2 && direction == 3)
			glTranslated(0, 0, -2 * (posZ + 0.41));  //mehtaga tetzabat f level 2

		if (camView == 2 && direction == 4)
			glTranslated(0, 0, -2 * (posZ + 0.41));  //mehtaga tetzabat f level 2

		glPushMatrix();

		glScaled(2, 1, 2);

		drawWallS1();
		drawWallS2();

		glPushMatrix();
		glTranslated(doorRedX, 0.15, doorRedZ);
		glScaled(0.07, 0.2, 0.02);
		door(1.2, 1, 0.5, 5, 0, 0);
		glPopMatrix();

		glPushMatrix();
		glTranslated(doorBlueX, 0.15, doorBlueZ);
		glScaled(0.07, 0.2, 0.02);
		door(1.2, 1, 0.5, 0, 0, 5);
		glPopMatrix();

		glPushMatrix();
		glTranslated(posX, posY, posZ);
		if (direction == 1) {
			glRotated(180, 0, 1, 0);
			glTranslated(-0.11, 0, -0.95);
		}
		if (direction == 4) {
			glRotated(90, 0, 1, 0);
			glTranslated(-0.525, 0, -0.41);
		}
		if (direction == 3) {

			glTranslated(0.54, 0, 0.415);
			glRotated(270, 0, 1, 0);
		}
		drawPlayer();
		glPopMatrix();

		glPushMatrix();
		glTranslated(keyRedX, 0.15, keyRedZ);
		doorKey(0.04, 5, 0, 0);
		glPopMatrix();

		glPushMatrix();
		glTranslated(keyBlueX, 0.15, keyBlueZ);
		doorKey(0.04, 0, 0, 5);
		glPopMatrix();


		glPushMatrix();
		glTranslated(c1x, 0.15, c1z);
		glRotated(coinRot, 0, 1, 0);
		glScaled(0.05, 0.1, 0.05);
		glColor3f(0.8, 0.3, 0);
		coins();
		glPopMatrix();

		glPushMatrix();
		glTranslated(c2x, 0.15, c2z);
		glRotated(coinRot, 0, 1, 0);
		glScaled(0.05, 0.1, 0.05);
		glColor3f(0.8, 0.3, 0);
		coins();
		glPopMatrix();

		glPushMatrix();
		glTranslated(c3x, 0.15, c3z);
		glRotated(coinRot, 0, 1, 0);
		glScaled(0.05, 0.1, 0.05);
		glColor3f(0.8, 0.3, 0);
		coins();
		glPopMatrix();

		glPushMatrix();
		glTranslated(c4x, 0.15, c4z);
		glRotated(coinRot, 0, 1, 0);
		glScaled(0.05, 0.1, 0.05);
		glColor3f(0.8, 0.3, 0);
		coins();
		glPopMatrix();

		glPushMatrix();
		glTranslated(px, 0.15, pz);
		glRotated(coinRot, 0, 1, 0);
		glScaled(1, 2, 1);
		powerS();
		glPopMatrix();

		glPushMatrix();
		glTranslated(0.5, 0.2, 0.6);
		glScaled(0.07, 0.1, 0.07);
		squareLamp(0.5);
		glPopMatrix();

		glPushMatrix();
		drawGroundS(0.02);  //GROUND
		glPopMatrix();

		glPopMatrix();

		sprintf((char*)p0s, "Time Left: ");
		print(-0.8, 0.7, (char*)p0s, timeGame);

		sprintf((char*)p0s, "Score: ");
		print(0.2, 1.2, (char*)p0s, score);

		glPopMatrix();

		glFlush();

	}
}

void Keyboard(unsigned char key, int x, int y) {

	int bodytemp = body;
	body = 1;

	switch (key) {
	case '1':
		camView = 1;
		camera.normalView();
		break;
	case '2':
		camView = 2;
		camera.firstPerson();
		break;



	case GLUT_KEY_ESCAPE:
		exit(EXIT_SUCCESS);
	}

	if (endGame == 1)
		return;
	if (level == 1) {

		switch (key) {
		case 'z': //bel tarteeb men foo2 l taht


			cout << "X: " << posX << " Z: " << posZ << endl;
			break;
		case 'w':
		case 'W': //bel tarteeb men foo2 l taht
			if (posZ < -0.42)
				return;

			if (posX > 0.015 && posX < 0.25 && posZ <-0.33 && posZ>-0.4)
				return;

			if (posX > 0.32 && posX < 0.38 && posZ < -0.33)
				return;

			if (posX > 0.43 && posX < 0.6 && posZ <-0.33 && posZ>-0.4)
				return;

			if (posX > 0.41 && posX < 0.48 && posZ <-0.24 && posZ>-0.35)
				return;

			if (posX > -0.1 && posX < 0.075 && posZ <-0.23 && posZ>-0.31)
				return;

			if (posX > 0.21 && posX < 0.33 && posZ < -0.24 && posZ > -0.3)
				return;

			if (posX > 0.015 && posX < 0.38 && posZ <-0.13 && posZ>-0.2)
				return;

			if (posX > 0.43 && posX < 0.6 && posZ <-0.13 && posZ>-0.2)
				return;

			if (posX > 0.01 && posX < 0.18 && posZ <-0.03 && posZ>-0.07)
				return;

			if (posX > 0.32 && posX < 0.48 && posZ <-0.03 && posZ>-0.06)
				return;

			if (renderKey1 == 1 && posZ < -0.23)  //red wall
				return;


			if (renderKey2 == 1 && posX > 0.35 && posX < 0.41 && posZ < -0.33) //green wall
				return;


			bodytemp += 1;
			direction = 1;
			posZ -= 0.01;
			PlaySound(TEXT("step.wav"), NULL, SND_ASYNC | SND_FILENAME);			break;
		case 'a':
		case 'A':
			if (posX <= -0.01)
				return;


			if (posX < 0.075 && posZ <-0.24 && posZ>-0.31)
				return;

			if (posX > 0.075 && posX < 0.1 && posZ <-0.10 && posZ>-0.2)
				return;

			if (posX > 0.15 && posX < 0.2 && posZ <-0.20 && posZ>-0.3)
				return;

			if (posX > 0.05 && posX < 0.19 && posZ<-0.04 && posZ >-0.1)
				return;

			if (posX > 0.25 && posX < 0.3 && posZ<-0.3 && posZ >-0.41)
				return;

			if (posX > 0.25 && posX < 0.3 && posZ<0.01 && posZ >-0.17)
				return;

			if (posX > 0.34 && posX < 0.39 && posZ<-0.34 && posZ >-0.43)
				return;

			if (posX > 0.34 && posX < 0.39 && posZ <-0.15 && posZ>-0.31)
				return;

			if (posX > 0.43 && posX < 0.49 && posZ<-0.25 && posZ >-0.37)
				return;

			if (posX > 0.43 && posX < 0.48 && posZ <-0.04 && posZ>-0.16)
				return;

			bodytemp += 1;
			direction = 3;
			posX -= 0.01;
			PlaySound(TEXT("step.wav"), NULL, SND_ASYNC | SND_FILENAME);			break;
		case 's':
		case 'S':

			if (posX > 0.015 && posX < 0.28 && posZ <-0.34 && posZ>-0.41)
				return;

			if (posX > 0.41 && posX < 0.6 && posZ <-0.34 && posZ>-0.41)
				return;

			if (posX > -0.1 && posX < 0.075 && posZ <-0.25 && posZ>-0.32)
				return;

			if (posX > 0.21 && posX < 0.38 && posZ < -0.25 && posZ > -0.32)
				return;

			if (posX > 0.50 && posX < 0.6 && posZ <-0.25 && posZ>-0.32)
				return;

			if (posX > 0.11 && posX < 0.19 && posZ <-0.25 && posZ>-0.32)
				return;

			if (posX > 0.015 && posX < 0.37 && posZ <-0.15 && posZ>-0.23)
				return;

			if (posX > 0.41 && posX < 0.6 && posZ <-0.15 && posZ>-0.23)
				return;

			if (posX > 0.015 && posX < 0.18 && posZ <-0.04 && posZ>-0.11)
				return;

			if (posX >= 0.32 && posX < 0.47 && posZ <-0.04 && posZ>-0.11)
				return;


			if (posZ > -0.02)
				return;

			bodytemp += 1;
			direction = 2;
			posZ += 0.01;
			PlaySound(TEXT("step.wav"), NULL, SND_ASYNC | SND_FILENAME);			break;
		case 'd':
		case 'D':
			if (posX >= 0.49 && posZ > -0.29)
				return;

			if (posX >= 0.49 && posZ < -0.35)
				return;

			if (posX >= 0 && posX < 0.04 && posZ <-0.04 && posZ>-0.21)
				return;

			if (posX > 0.01 && posX < 0.05 && posZ <-0.34 && posZ>-0.4)
				return;

			if (posX > 0.1 && posX < 0.16 && posZ <-0.19 && posZ>-0.30)
				return;

			if (posX > 0.2 && posX < 0.23 && posZ <0 && posZ>-0.20)
				return;

			if (posX > 0.2 && posX < 0.23 && posZ <-0.25 && posZ>-0.39)
				return;

			if (posX > 0.3 && posX < 0.36 && posZ <-0.04 && posZ>-0.1)
				return;

			if (posX > 0.3 && posX < 0.36 && posZ <-0.19 && posZ>-0.30)
				return;

			if (posX > 0.3 && posX < 0.36 && posZ < -0.35)
				return;

			if (posX > 0.39 && posX < 0.44 && posZ <-0.06 && posZ>-0.21)
				return;

			if (posX > 0.39 && posX < 0.44 && posZ <-0.26 && posZ>-0.4)
				return;

			bodytemp += 1;
			direction = 4;
			posX += 0.01;
			PlaySound(TEXT("step.wav"), NULL, SND_ASYNC | SND_FILENAME);			break;

		case GLUT_KEY_ESCAPE:
			exit(EXIT_SUCCESS);
		}

		if (posX > 0.05 && posX < 0.12 && posZ <-0.1 && posZ>-0.16) {
			hasKey1 = 1;
			PlaySound(TEXT("card.wav"), NULL, SND_ASYNC | SND_FILENAME);

		}

		if (posX > 0.45 && posX < 0.51 && posZ <-0.09 && posZ>-0.15) {
			hasKey2 = 1;
			PlaySound(TEXT("card.wav"), NULL, SND_ASYNC | SND_FILENAME);

		}

		if (renderPU == 1 && posX > -0.03 && posX < 0.03 && posZ <-0.36 && posZ>-0.43) {
			renderPU = 0;
			timeGame += 50;
			lightIntenso += 1.5;
		}

		if (renderCoin1 == 1 && posX > 0.43 && posX < 0.51 && posZ <-0.38 && posZ>-0.45) {
			renderCoin1 = 0;
			score += 50;
			PlaySound(TEXT("coin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		}
		if (renderCoin2 == 1 && posX > 0.24 && posX < 0.31 && posZ <-0.38 && posZ>-0.45) {
			renderCoin2 = 0;
			score += 50;
			PlaySound(TEXT("coin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		}
		if (renderCoin3 == 1 && posX > 0.25 && posX < 0.32 && posZ <-0.03 && posZ>-0.13) {
			renderCoin3 = 0;
			score += 50;
			PlaySound(TEXT("coin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		}
		if (renderCoin4 == 1 && posX > 0.14 && posX < 0.21 && posZ <-0.23 && posZ>-0.27) {
			renderCoin4 = 0;
			score += 50;
			PlaySound(TEXT("coin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		}


		if (posX >= 0.56) {
			camera.normalView();
			camView = 1;
			endGame = 1;
		}

		if (camView == 2)
			camera.firstPerson();

		glutPostRedisplay();
	}
	else {
		switch (key) {
		case 'z': //bel tarteeb men foo2 l taht


			cout << "X: " << posX << " Z: " << posZ << endl;
			break;

		case 'k':
		case 'K':
			// -------------------------- KEY RED -------------------------- //
			if (posX > 0.08 && posX < 0.22 && posZ < 0.07 && posZ>0)
			{
				if (keys[0] == "red" || keys[1] == "red")
				{
					doorRedX = 20.0;
					doorRedZ = 20.0;
					kr = 1;
				}

			}
			// -------------------------- KEY BLUE -------------------------- //
			if (posX > 0.316 && posX < 0.416 && posZ <-0.43 && posZ>-0.5)
			{
				if (keys[0] == "blue" || keys[1] == "blue")
				{
					doorBlueX = 20.0;
					doorBlueZ = 20.0;
					kb = 1;
				}

			}



			break;
		case 'w':
		case 'W': //bel tarteeb men foo2 l taht


			// -------------------------- LINE 1 -------------------------- //
			if (posZ < -0.538)
				return;
			// -------------------------- LINE 2 -------------------------- //
			if (posX > 0 && posX < 0.316 && posZ <-0.43 && posZ>-0.5)
				return;
			//-------blue door------//
			if (posX > 0.316 && posX < 0.416 && posZ <-0.43 && posZ>-0.5)
			{
				if (kb == 0)
					return;
			}
			// -------------------------- LINE 3 -------------------------- //
			if (posX > 0.095 && posX < 0.316 && posZ <-0.33 && posZ>-0.4)
				return;

			if (posX > 0.38 && posX < 0.5 && posZ <-0.33 && posZ>-0.4)
				return;
			// -------------------------- LINE 4 -------------------------- //
			if (posX > 0.18 && posX < 0.42 && posZ <-0.23 && posZ>-0.3)
				return;
			// -------------------------- LINE 5 -------------------------- //
			if (posX > 0.08 && posX < 0.22 && posZ <-0.13 && posZ>-0.2)
				return;
			if (posX > 0.36 && posX < 0.425 && posZ < 0.07 && posZ>0)
				return;
			// -------------------------- LINE 6 -------------------------- //
			if (posX > 0.18 && posX < 0.32 && posZ <-0.03 && posZ>-0.1)
				return;
			// -------------------------- LINE 7 -------------------------- //
			if (posX > 0.18 && posX < 0.32 && posZ < 0.07 && posZ>0)
				return;
			//-------red door------//
			if (posX > 0.08 && posX < 0.22 && posZ < 0.07 && posZ>0)
			{
				if (kr == 0)
					return;
			}
			// -------------------------- KEY RED -------------------------- //
			if (posX > 0.44 && posX < 0.46 && posZ <-0.22 && posZ>-0.3)
			{

				keyRedX = 20;
				keyRedZ = 20;
				if (keys[0] == "blue")
					keys[1] = "red";
				else keys[0] = "red";
				PlaySound(TEXT("card.wav"), NULL, SND_ASYNC | SND_FILENAME);

			}

			// -------------------------- KEY BLUE -------------------------- //
			if (posX > 0.14 && posX < 0.16 && posZ <-0.4 && posZ>-0.45)
			{
				keyBlueX = 20;
				keyBlueZ = 20;
				if (keys[0] == "red")
					keys[1] = "blue";
				else keys[0] = "blue";
				PlaySound(TEXT("card.wav"), NULL, SND_ASYNC | SND_FILENAME);

			}


			bodytemp += 1;
			direction = 1;
			posZ -= 0.01;
			PlaySound(TEXT("step.wav"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		case 'a':
		case 'A':


			// -------------------------- LINE 1 -------------------------- //
			if (posX < 0.04 && posZ >-0.5)
				return;

			// -------------------------- LINE 2 -------------------------- //
			if (posX > 0.12 && posX < 0.14 && posZ < 0.04 && posZ >-0.4)
				return;
			// -------------------------- LINE 3 -------------------------- //
			if (posX > 0.22 && posX < 0.24 && posZ < 0.042 && posZ >-0.1)
				return;

			/*if (posX > 0.27 && posX < 0.2 && posZ < -0.26 && posZ >-0.3)
				return;*/
				// -------------------------- LINE 4 -------------------------- //
			if (posX > 0.32 && posX < 0.36 && posZ < -0.1 && posZ >-0.3)
				return;
			if (posX > 0.31 && posX < 0.33 && posZ < -0.36 && posZ >-0.5)
				return;
			// -------------------------- LINE 5 -------------------------- //
			if (posX > 0.39 && posX < 0.43 && posZ < 0.03 && posZ >-0.2)
				return;

			if (posX > 0.4 && posX < 0.43 && posZ < -0.23 && posZ >-0.49)
				return;


			// -------------------------- KEY RED -------------------------- //
			if (posX > 0.44 && posX < 0.46 && posZ <-0.22 && posZ>-0.3)
			{
				keyRedX = 20;
				keyRedZ = 20;
				if (keys[0] == "blue")
					keys[1] = "red";
				else keys[0] = "red";
				PlaySound(TEXT("card.wav"), NULL, SND_ASYNC | SND_FILENAME);

			}
			// -------------------------- KEY BLUE -------------------------- //
			if (posX > 0.14 && posX < 0.16 && posZ <-0.4 && posZ>-0.45)
			{
				keyBlueX = 20;
				keyBlueZ = 20;
				if (keys[0] == "red")
					keys[1] = "blue";
				else keys[0] = "blue";
				PlaySound(TEXT("card.wav"), NULL, SND_ASYNC | SND_FILENAME);

			}

			bodytemp += 1;
			direction = 3;
			posX -= 0.01;
			PlaySound(TEXT("step.wav"), NULL, SND_ASYNC | SND_FILENAME);			break;
		case 's':
		case 'S':


			// -------------------------- LINE 2 -------------------------- //
			if (posX > 0 && posX < 0.325 && posZ <-0.48 && posZ>-0.51)
				return;
			if (posX > 0.37 && posX < 0.41 && posZ <-0.48 && posZ>-0.51)
				return;
			// -------------------------- LINE 3 -------------------------- //
			if (posX > 0.095 && posX < 0.316 && posZ <-0.38 && posZ>-0.41)
				return;

			if (posX > 0.38 && posX < 0.5 && posZ <-0.38 && posZ>-0.41)
				return;
			// -------------------------- LINE 4 -------------------------- //
			if (posX > 0.18 && posX < 0.42 && posZ <-0.28 && posZ>-0.31)
				return;
			// -------------------------- LINE 5 -------------------------- //
			if (posX > 0.08 && posX < 0.22 && posZ <-0.18 && posZ>-0.21)
				return;
			if (posX > 0.36 && posX < 0.425 && posZ <-0.18 && posZ>-0.21)
				return;
			// -------------------------- LINE 6 -------------------------- //
			if (posX > 0.18 && posX < 0.32 && posZ <-0.08 && posZ>-0.11)
				return;
			// -------------------------- LINE 7 -------------------------- //
			if (posX > 0.18 && posX < 0.32 && posZ < 0.02 && posZ>-0.01)
				return;
			// -------------------------- LINE 8-------------------------- //
			if (posZ > 0.1)
				return;
			// -------------------------- KEY RED -------------------------- //
			if (posX > 0.44 && posX < 0.46 && posZ <-0.22 && posZ>-0.3)
			{
				keyRedX = 20;
				keyRedZ = 20;
				if (keys[0] == "blue")
					keys[1] = "red";
				else keys[0] = "red";
				PlaySound(TEXT("card.wav"), NULL, SND_ASYNC | SND_FILENAME);

			}
			// -------------------------- KEY BLUE -------------------------- //
			if (posX > 0.14 && posX < 0.16 && posZ <-0.4 && posZ>-0.45)
			{
				keyBlueX = 20;
				keyBlueZ = 20;
				if (keys[0] == "red")
					keys[1] = "blue";
				else keys[0] = "blue";
				PlaySound(TEXT("card.wav"), NULL, SND_ASYNC | SND_FILENAME);

			}



			bodytemp += 1;
			direction = 2;
			posZ += 0.01;
			PlaySound(TEXT("step.wav"), NULL, SND_ASYNC | SND_FILENAME);			break;
		case 'd':
		case 'D':


			// -------------------------- LINE 2 -------------------------- //
			if (posX > 0.06 && posX < 0.08 && posZ < 0.04 && posZ >-0.4)
				return;

			// -------------------------- LINE 3 -------------------------- //
			if (posX > 0.16 && posX < 0.18 && posZ < 0.042 && posZ >-0.1)
				return;

			if (posX > 0.17 && posX < 0.2 && posZ < -0.26 && posZ >-0.3)
				return;
			// -------------------------- LINE 4 -------------------------- //
			if (posX > 0.26 && posX < 0.3 && posZ < -0.1 && posZ >-0.3)
				return;
			if (posX > 0.26 && posX < 0.3 && posZ < -0.36 && posZ >-0.5)
				return;
			// -------------------------- LINE 5 -------------------------- //
			if (posX > 0.35 && posX < 0.4 && posZ < 0.03 && posZ >-0.2)
				return;

			if (posX > 0.35 && posX < 0.4 && posZ < -0.23 && posZ >-0.49)
				return;

			// -------------------------- LINE 6 -------------------------- //
			if (posX > 0.45)
				return;

			// -------------------------- KEY RED -------------------------- //
			if (posX > 0.44 && posX < 0.46 && posZ <-0.22 && posZ>-0.3)
			{
				keyRedX = 20;
				keyRedZ = 20;
				if (keys[0] == "blue")
					keys[1] = "red";
				else keys[0] = "red";
				PlaySound(TEXT("card.wav"), NULL, SND_ASYNC | SND_FILENAME);

			}
			// -------------------------- KEY BLUE -------------------------- //
			if (posX > 0.14 && posX < 0.16 && posZ <-0.4 && posZ>-0.45)
			{
				keyBlueX = 20;
				keyBlueZ = 20;
				if (keys[0] == "red")
					keys[1] = "blue";
				else keys[0] = "blue";
				PlaySound(TEXT("card.wav"), NULL, SND_ASYNC | SND_FILENAME);

			}

			bodytemp += 1;
			direction = 4;
			posX += 0.01;
			PlaySound(TEXT("step.wav"), NULL, SND_ASYNC | SND_FILENAME);			break;

		case GLUT_KEY_ESCAPE:
			exit(EXIT_SUCCESS);
		}

		// -------------------------- COIN 1 -------------------------- //

		if (!c1taken && posX > 0.02 && posX < 0.06 && posZ <-0.19 && posZ>-0.21)
		{
			c1taken = true;
			c1x = 20.0;
			c1z = 20.0;
			score += 50;
			PlaySound(TEXT("coin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		}
		// -------------------------- COIN 2 -------------------------- //
		if (!c2taken && posX > 0.38 && posX < 0.5 && posZ <-0.28 && posZ>-0.35)
		{
			c2taken = true;
			c2x = 20.0;
			c2z = 20.0;
			score += 50;
			PlaySound(TEXT("coin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		}
		// -------------------------- COIN 3 -------------------------- //
		if (!c3taken && posX > 0.24 && posX < 0.26 && posZ <-0.4 && posZ>-0.45)
		{
			c3taken = true;
			c3x = 20.0;
			c3z = 20.0;
			score += 50;
			PlaySound(TEXT("coin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		}
		// -------------------------- COIN 4 -------------------------- //
		if (!c4taken && posX > 0.42 && posX < 0.46 && posZ <-0.4 && posZ>-0.45)
		{
			c4taken = true;
			c4x = 20.0;
			c4z = 20.0;
			score += 50;
			PlaySound(TEXT("coin.wav"), NULL, SND_ASYNC | SND_FILENAME);
		}
		// -------------------------- POWERUP -------------------------- //
		if (!ptaken && posX > 0.21 && posX < 0.27 && posZ < 0.02 && posZ>-0.06)
		{
			ptaken = true;
			px = 20.0;
			pz = 20.0;
			score = score * 2;
		}

		if (posX < -0.02) {
			camera.normalView();
			camView = 1;
			endGame = 1;
		}

		if (camView == 2)
			camera.firstPerson();


		glutPostRedisplay();

	}

	if (bodytemp == 4)
		bodytemp = 2;
	body = bodytemp;
}

void timeLose(int val)//timer animation function, allows the user to pass an integer value to the timer function.
{
	timeGame = timeGame - 1;
	if (timeGame == 0)
		endGame = 2;

	lightIntenso -= 0.03;
	glutPostRedisplay();						// redraw
	glutTimerFunc(1000, timeLose, 0);					//recall the time function after 1000 ms and pass a zero value as an input to the time func.

}

void timerFall(int val)
{
	if (endGame == 1) {
		posY -= Yignore;
		Yignore = Yignore * 1.2;
	}

	if (posY < -1 && level == 1) {
		Yignore = 0.01;
		level = 2;
		posX = 0.05;
		posY = 0;
		posZ = -0.01;
		endGame = 0;
	}

	if (posY < -2 && level == 2) {
		timeGame = 100;
		endGame = 3;
	}
	glutPostRedisplay();						// redraw
	glutTimerFunc(100, timerFall, 0);					//recall the time function after 1000 ms and pass a zero value as an input to the time func.

}

void timerCoin(int val)
{
	coinRot += 5;
	glutPostRedisplay();						// redraw
	glutTimerFunc(100, timerCoin, 0);					//recall the time function after 1000 ms and pass a zero value as an input to the time func.

}

void mouseFunc(int button, int state, int x, int y) {
	if (level == 1) {
		if (button == GLUT_LEFT_BUTTON)
		{
			if (hasKey1 == 1 && posX > 0.04 && posX < 0.11 && posZ <-0.21 && posZ>-0.26)
			{
				PlaySound(TEXT("door.wav"), NULL, SND_ASYNC | SND_FILENAME);
				renderKey1 = 0;
			}
			if (hasKey2 == 1 && posX > 0.33 && posX < 0.41 && posZ < -0.3)
			{
				PlaySound(TEXT("door.wav"), NULL, SND_ASYNC | SND_FILENAME);
				renderKey2 = 0;
			}
		}
	}
	else {

		// -------------------------- KEY RED -------------------------- //
		if (posX > 0.08 && posX < 0.22 && posZ < 0.07 && posZ>0)
		{
			if (keys[0] == "red" || keys[1] == "red")
			{
				doorRedX = 20.0;
				doorRedZ = 20.0;
				kr = 1;
				PlaySound(TEXT("door.wav"), NULL, SND_ASYNC | SND_FILENAME);
			}

		}
		// -------------------------- KEY BLUE -------------------------- //
		if (posX > 0.316 && posX < 0.416 && posZ <-0.43 && posZ>-0.5)
		{
			if (keys[0] == "blue" || keys[1] == "blue")
			{
				doorBlueX = 20.0;
				doorBlueZ = 20.0;
				kb = 1;
				PlaySound(TEXT("door.wav"), NULL, SND_ASYNC | SND_FILENAME);
			}

		}
	}
}

//=======================================================================
// Lighting Configuration Function
//=======================================================================
void InitLightSource()
{
	// Enable Lighting for this OpenGL Program
	//glEnable(GL_LIGHTING);

	// Enable Light Source number 0
	// OpengL has 8 light sources
	glEnable(GL_LIGHT0);

	// Define Light source 0 ambient light
	GLfloat ambient[] = { 0.1f, 0.1f, 0.1, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

	// Define Light source 0 diffuse light
	GLfloat diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

	// Define Light source 0 Specular light
	GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	// Finally, define light source 0 position in World Space
	GLfloat light_position[] = { 0.0f, 10.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}



void LoadAssets()
{
	tex_wall1.Load("textures/wall.bmp");
	tex_floor.Load("textures/tile.bmp");
}

//=======================================================================
// Main Function
//=======================================================================
void main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("Lab 5");
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);

	glClearColor(0, 1, 0.9, 0.0f);

	glutTimerFunc(0, timerFall, 0);
	glutTimerFunc(0, timeLose, 0);
	glutTimerFunc(0, timerCoin, 0);
	glutMouseFunc(mouseFunc);

	LoadAssets();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	//glEnable(GL_LIGHT2);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);

	glutMainLoop();
}