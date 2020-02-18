// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <math.h>

#include <iostream>
#include <time.h>

using namespace std;

//Declarar una ventana

GLFWwindow* window;

bool golpe = false;
bool golpe1= false;
bool golpe2 = false;

bool colision = false;

float componenteXGato1 = 0.0, componenteYGato1 = 0.0f, angulo1 = 65.0f;
float componenteXGato2 = 0.0, componenteYGato2 = 0.0f, angulo2 = 65.0f;

float randomNumber;

float escalaSenal = 0.0;
float escalaF = 0.0, posXF = 0.0f, posYF = 0.0f;


float posXEstepicursor = -2.0f, velocidadEstepicursor = 0.7;
float posXNubeFrente = -0.2f, velocidadNubeFrente = 0.13;
float posXNubeFondo = -0.5, velocidadnubeFondo = 0.02;

float posXTriangulo = 0.5f , posYTriangulo = -0.5f;
float posXGato2 = 0.5f, posYGato2 = -0.2f;

float posXCuadrado = -0.5f, posYCuadrado = 0.0f;
float posXGato1 = -0.5f, posYGato1 = 0.2f;

double tiempoActual, tiempoAnterior;
double velocidadTriangulo = 10;

float rojoTriangulo = 0.0f;
float verdeTriangulo = 1.0f;
float azulTriangulo = 0.0f;

void dibujarF() {
	glPushMatrix();

	glTranslatef(posXF, posYF, 0.0f);
	glScalef(escalaF, escalaF, escalaF);

	glBegin(GL_QUADS);

	glColor3f(1.0f, 0.0f, 0.0f);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.4f, 0.0f);
	glVertex3f(0.1f, 0.4f, 0.0f);
	glVertex3f(0.1f, 0.0f, 0.0f);

	glVertex3f(0.0f, 0.4f, 0.0f);
	glVertex3f(0.3f, 0.4f, 0.0f);
	glVertex3f(0.3f, 0.3f, 0.0f);
	glVertex3f(0.0f, 0.3f, 0.0f);

	glVertex3f(0.0f, 0.2f, 0.0f);
	glVertex3f(0.2f, 0.2f, 0.0f);
	glVertex3f(0.2f, 0.1f, 0.0f);
	glVertex3f(0.0f, 0.1f, 0.0f);

	glEnd();

	glPopMatrix();
}

//gato negro
void dibujarGato1() {

	glPushMatrix();
	glTranslatef(posXGato1, posYGato1, 0.0f);
	glScalef(0.7, 0.7, 0.7);
	//cintas de atras de la bandana
	glBegin(GL_POLYGON);

	glColor3f(1.0f, 0.2f, 0.2f);
	glVertex3f(0.05f, 0.3f, 0.0f);
	glVertex3f(-0.05f, 0.3f, 0.0f);
	glVertex3f(-0.35f, 0.05f, 0.0f);
	glVertex3f(-0.25f, 0.05f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);

	glColor3f(1.0f, 0.2f, 0.2f);
	glVertex3f(0.05f, 0.3f, 0.0f);
	glVertex3f(-0.05f, 0.3f, 0.0f);
	glVertex3f(-0.5f, 0.1f, 0.0f);
	glVertex3f(-0.4f, 0.1f, 0.0f);
	glEnd();
	//forma de la cabeza
	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.0f, 0.0f);
	for (double i = 0; i < 360.0; i += 5.0) {
		glVertex3f(0.25 /*ancho del circulo*/ * cos(i * 3.14159 / 180.0) + 0.0f /*posicion en x*/,
			(0.25 /*alto del circulo*/ * sin(i * 3.14159 / 180.0)) + 0.2f /*posicion en y*/, 0.0f);
	}

	glEnd();
	//hombros
	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.0f, 0.0f);
	for (double i = 0; i < 360.0; i += 5.0) {
		glVertex3f(0.35 /*ancho del circulo*/ * cos(i * 3.14159 / 180.0) + 0.0f /*posicion en x*/,
			(0.25 /*alto del circulo*/ * sin(i * 3.14159 / 180.0)) + -0.1f /*posicion en y*/, 0.0f);
	}
	glEnd();
	//torso
	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.35f, -0.1f, 0.0f);
	glVertex3f(0.35f, -0.1f, 0.0f);
	glVertex3f(0.35f, -0.5f, 0.0f);
	glVertex3f(-0.35f, -0.5f, 0.0f);
	glEnd();
	//cuadro de abajo
	glBegin(GL_POLYGON);

	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.4f, -0.5f, 0.0f);
	glVertex3f(0.4f, -0.5f, 0.0f);
	glVertex3f(0.4f, -0.7f, 0.0f);
	glVertex3f(-0.4f, -0.7f, 0.0f);
	glEnd();
	//orejas
	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.25f, 0.25f, 0.0f);
	glVertex3f(0.25f, 0.25f, 0.0f);
	glVertex3f(0.25f, 0.55f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.25f, 0.25f, 0.0f);
	glVertex3f(-0.25f, 0.25f, 0.0f);
	glVertex3f(-0.25f, 0.55f, 0.0f);
	glEnd();
	//frente de la bandana
	glBegin(GL_POLYGON);

	glColor3f(1.0f, 0.2f, 0.2f);
	glVertex3f(-0.25f, 0.3f, 0.0f);
	glVertex3f(0.25f, 0.3f, 0.0f);
	glVertex3f(0.25f, 0.2f, 0.0f);
	glVertex3f(-0.25f, 0.2f, 0.0f);
	glEnd();
	//numero 1
	glBegin(GL_LINE_STRIP);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.1f, -0.58f, 0.0f);
	glVertex3f(0.0f, -0.52f, 0.0f);
	glVertex3f(0.0f, -0.68f, 0.0f);
	glVertex3f(-0.1f, -0.68f, 0.0f);
	glVertex3f(0.1f, -0.68f, 0.0f);
	glEnd();
	//hoja de la espada
	glBegin(GL_POLYGON);

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(0.6f, 0.4f, 0.0f);
	glVertex3f(0.5f, 0.4f, 0.0f);
	glVertex3f(-0.05f, -0.2f, 0.0f);
	glVertex3f(0.05f, -0.2f, 0.0f);
	glEnd();
	//ojos
	glBegin(GL_POLYGON);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.15f, 0.16f, 0.0f);
	glVertex3f(-0.05f, 0.16f, 0.0f);
	glVertex3f(-0.05f, 0.14f, 0.0f);
	glVertex3f(-0.15f, 0.14f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.15f, 0.16f, 0.0f);
	glVertex3f(0.05f, 0.16f, 0.0f);
	glVertex3f(0.05f, 0.14f, 0.0f);
	glVertex3f(0.15f, 0.14f, 0.0f);
	glEnd();
	//mango de la espada
	glBegin(GL_POLYGON);

	glColor3f(0.3f, 0.3f, 0.3f);
	glVertex3f(0.1418f, -0.1f, 0.0f);
	glVertex3f(0.0418f, -0.1f, 0.0f);
	glVertex3f(-0.05f, -0.2f, 0.0f);
	glVertex3f(0.05f, -0.2f, 0.0f);
	glEnd();

	glPopMatrix();
}
//gato blanco
void dibujarGato2() {

	glPushMatrix();

	glTranslatef(posXGato2, posYGato2, 0.0f);
	glScalef(0.7, 0.7, 0.7);
	//filo de la espada
	glBegin(GL_POLYGON);

	glColor3f(0.7f, 0.7f, 0.7f);
	glVertex3f(-0.6f, 0.4f, 0.0f);
	glVertex3f(-0.5f, 0.4f, 0.0f);
	glVertex3f(0.05f, -0.2f, 0.0f);
	glVertex3f(-0.05f, -0.2f, 0.0f);
	glEnd();
	//forma de la cabeza
	glBegin(GL_POLYGON);

	glColor3f(1.0f, 1.0f, 1.0f);
	for (double i = 0; i < 360.0; i += 5.0) {
		glVertex3f(0.25 /*ancho del circulo*/ * cos(i * 3.14159 / 180.0) + 0.0f /*posicion en x*/,
			(0.25 /*alto del circulo*/ * sin(i * 3.14159 / 180.0)) + 0.2f /*posicion en y*/, 0.0f);
	}

	glEnd();
	//hombros
	glBegin(GL_POLYGON);

	glColor3f(1.0f, 1.0f, 1.0f);
	for (double i = 0; i < 360.0; i += 5.0) {
		glVertex3f(0.35 /*ancho del circulo*/ * cos(i * 3.14159 / 180.0) + 0.0f /*posicion en x*/,
			(0.25 /*alto del circulo*/ * sin(i * 3.14159 / 180.0)) + -0.1f /*posicion en y*/, 0.0f);
	}
	glEnd();
	//torso
	glBegin(GL_POLYGON);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.35f, -0.1f, 0.0f);
	glVertex3f(0.35f, -0.1f, 0.0f);
	glVertex3f(0.35f, -0.5f, 0.0f);
	glVertex3f(-0.35f, -0.5f, 0.0f);
	glEnd();
	//cuadro de abajo 
	glBegin(GL_POLYGON);

	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(-0.4f, -0.5f, 0.0f);
	glVertex3f(0.4f, -0.5f, 0.0f);
	glVertex3f(0.4f, -0.7f, 0.0f);
	glVertex3f(-0.4f, -0.7f, 0.0f);
	glEnd();
	//orejas
	glBegin(GL_POLYGON);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-0.25f, 0.25f, 0.0f);
	glVertex3f(0.25f, 0.25f, 0.0f);
	glVertex3f(0.25f, 0.55f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.25f, 0.25f, 0.0f);
	glVertex3f(-0.25f, 0.25f, 0.0f);
	glVertex3f(-0.25f, 0.55f, 0.0f);
	glEnd();
	//bandana alrededor de la cabeza
	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.4f, 1.0f);
	glVertex3f(-0.25f, 0.3f, 0.0f);
	glVertex3f(0.25f, 0.3f, 0.0f);
	glVertex3f(0.25f, 0.2f, 0.0f);
	glVertex3f(-0.25f, 0.2f, 0.0f);
	glEnd();
	//listones de atras de la bandana
	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.4f, 1.0f);
	glVertex3f(-0.05f, 0.3f, 0.0f);
	glVertex3f(0.05f, 0.3f, 0.0f);
	glVertex3f(0.2f, 0.0f, 0.0f);
	glVertex3f(0.1f, 0.0f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);

	glColor3f(0.0f, 0.4f, 1.0f);
	glVertex3f(-0.05f, 0.3f, 0.0f);
	glVertex3f(0.05f, 0.3f, 0.0f);
	glVertex3f(0.35f, 0.1f, 0.0f);
	glVertex3f(0.25f, 0.1f, 0.0f);
	glEnd();
	//numero 2
	glBegin(GL_LINE_STRIP);

	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-0.1f, -0.52f, 0.0f);
	glVertex3f(0.1f, -0.52f, 0.0f);
	glVertex3f(0.1f, -0.6f, 0.0f);
	glVertex3f(-0.1f, -0.6f, 0.0f);
	glVertex3f(-0.1f, -0.68f, 0.0f);
	glVertex3f(0.1f, -0.68f, 0.0f);
	glEnd();

	glPopMatrix();
}

void dibujarFondo() {

	

	//piso
	glBegin(GL_QUADS);

	glColor3f(0.79f, 0.677f, 0.4819f);

	glVertex3f(-1.0f, 0.12f, 0.0f);
	glVertex3f(1.0f, 0.12f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);

	glEnd();
	
	//Nube Fondo

	glPushMatrix();

	glScalef(.8, 0.6, 0.8);
	glTranslatef(posXNubeFondo, 0.6, 0.0);

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.8f, 0.8f);
	for (double i = 1; i < 360; i += 5.0)
	{
		glVertex3f((0.2 * cos(i * 3.1416 / 180.0)), (0.1 * sin(i * 3.1416 / 180.0)), 0.0f);
	}

	glEnd();

	glBegin(GL_POLYGON);
	for (double i = 1; i < 360; i += 5.0)
	{
		glVertex3f((0.15 * cos(i * 3.1416 / 180.0)) - 0.1, (0.15 * sin(i * 3.1416 / 180.0)) + 0.1, 0.0f);
	}

	glEnd();

	glBegin(GL_POLYGON);
	for (double i = 1; i < 360; i += 5.0)
	{
		glVertex3f((0.12 * cos(i * 3.1416 / 180.0)) - 0.2, (0.12 * sin(i * 3.1416 / 180.0)) + 0.05, 0.0f);
	}

	glEnd();

	glPopMatrix();


	//nubeFrente
	glPushMatrix();

	glScalef(1.0, 0.8, 0.8);
	glTranslatef(posXNubeFrente, 0.3, 0.0);

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	for (double i = 1; i < 360; i += 5.0)
	{
		glVertex3f((0.2 * cos(i * 3.1416 / 180.0)), (0.1 * sin(i * 3.1416 / 180.0)), 0.0f);
	}

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	for (double i = 1; i < 360; i += 5.0)
	{
		glVertex3f((0.15 * cos(i * 3.1416 / 180.0)) -0.1, (0.15 * sin(i * 3.1416 / 180.0)) + 0.1, 0.0f);
	}

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	for (double i = 1; i < 360; i += 5.0)
	{
		glVertex3f((0.12 * cos(i * 3.1416 / 180.0)) - 0.2, (0.12 * sin(i * 3.1416 / 180.0)) +0.05, 0.0f);
	}

	glEnd();
	//sombra
	glBegin(GL_POLYGON);
	glColor3f(0.69f, 0.577f, 0.3819f);
	for (double i = 1; i < 360; i += 5.0)
	{
		glVertex3f((0.25 * cos(i * 3.1416 / 180.0)) - 0.1, (0.05 * sin(i * 3.1416 / 180.0)) - 0.2, 0.0f);
	}

	glEnd();

	glPopMatrix();

	
	//cactusGrande
	glPushMatrix();

	glTranslatef(0.2f, -0.1f, 0.0f);
	
	glBegin(GL_QUADS);

	glColor3f(0.1989, 0.52, 0.026);

	glVertex3f(0.1, 0.0, 0.0);
	glVertex3f(0.1, 0.27, 0.0);
	glVertex3f(0.2, 0.29, 0.0);
	glVertex3f(0.2, 0.0, 0.0);
	
	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(0.2, 0.15, 0.0);
	glVertex3f(0.3, 0.15, 0.0);
	glVertex3f(0.3, 0.25, 0.0);
	glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.25, 0.2, 0.0);
	glVertex3f(0.2, 0.2, 0.0);

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(0.1, 0.05, 0.0);
	glVertex3f(0.0, 0.05, 0.0);
	glVertex3f(0.0, 0.15, 0.0);
	glVertex3f(0.05, 0.15, 0.0);
	glVertex3f(0.05, 0.1, 0.0);
	glVertex3f(0.2, 0.1, 0.0);

	glEnd();

	glPopMatrix();

}

void dibujarBolaDesierto() {
	glPushMatrix();

	glTranslatef(posXEstepicursor, -0.2, 0.0);

	glBegin(GL_POLYGON);

	glColor3f(1, 0.89, 0.7);
	for (float i = 1; i < 360; i += 5.0)
	{
		int i2 = i;
		if ( i2%2 == 0 ) {
			glVertex3f((0.24 * cos(i * 3.1416 / 180.0)), (0.17 * sin(i * 3.1416 / 180.0)), 0.0f);
		}
		else {
			glVertex3f((0.2 * cos(i * 3.1416 / 180.0)), (0.2 * sin(i * 3.1416 / 180.0)), 0.0f);
		}
	}

	glEnd();
	glPopMatrix();
}

void checarColisiones() {
	if (//La orilla derecha del triangulo es mayor que la orilla izquierda del cuadrado
		posXGato2 + 0.15f >= posXGato1 - 0.15f &&
		//orilla izquierda del triangulo es meor que la orilla derecha del cuadrado
		posXGato2 - 0.15f <= posXGato1 + 0.15f &&
		//la parte de arriba
		posYGato2 + 0.15f >= posYGato1 - 0.15f &&
		//la parte de abajo
		posYGato2 - 0.15f <= posYGato1 + 0.15f) {
		if (golpe2 == true)
		{
			posYF = 0.4;
			posXF = -0.6;
			rojoTriangulo = 1.0f;
			verdeTriangulo = 1.0;
			azulTriangulo = 1.0f;
		}
		else
		{
			posYF = -0.3;
			posXF = 0.6;
			rojoTriangulo = 0.0f;
			verdeTriangulo = 0.0;
			azulTriangulo = 0.0f;
		}
		escalaF = 1.0f;
		colision = true;
	}
}
void dibujarSenal()
{
	glBegin(GL_POLYGON);

	glColor3f(rojoTriangulo, verdeTriangulo, azulTriangulo);
	for (double i = 1; i < 360; i += 5.0)
	{
		glVertex3f((escalaSenal * cos(i * 3.1416 / 180.0)) + 0.6, (escalaSenal * sin(i * 3.1416 / 180.0)) + 0.5, 0.0f);
	}

	glEnd();
}
void actualizar() {
	tiempoActual = glfwGetTime();


	double tiempoDiferencial = tiempoActual - tiempoAnterior;
	cout << tiempoActual<<"   ";

	
	
	randomNumber -= tiempoDiferencial;

	if (randomNumber <= 0)
	{
		escalaSenal = 0.3;
		int estadoA =
			glfwGetKey(window, GLFW_KEY_A);
		if (estadoA == GLFW_PRESS) {
			if (golpe1 == false && randomNumber <= 0 && golpe == false) {
				golpe1 = true;
				golpe = true;
				
			}
		}
		
		int estadoL =
			glfwGetKey(window, GLFW_KEY_L);
		if (estadoL == GLFW_PRESS) {
			if (golpe2 == false && randomNumber <= 0 && golpe == false) {
				golpe2 = true;
				golpe = true;
			}
		}

		if (golpe1 == true && golpe == true) {
			if (colision == false) {
				componenteXGato1 = sinf(2 * 3.1415 * (angulo1 / 360.0f));
				posXGato1 += componenteXGato1 * (velocidadTriangulo * tiempoDiferencial);
				componenteYGato1 = cosf(2 * 3.1415 * (angulo1 / 360.0f));
				posYGato1 -= componenteYGato1 * (velocidadTriangulo * tiempoDiferencial);
			}


		}
		if (golpe2 == true && golpe == true)
		{
			if (colision == false) {
				componenteXGato2 = sinf(2 * 3.1415 * (angulo2 / 360.0f));
				posXGato2 -= componenteXGato2 * (velocidadTriangulo * tiempoDiferencial);
				componenteYGato2 = cosf(2 * 3.1415 * (angulo2 / 360.0f));
				posYGato2 += componenteYGato2 * (velocidadTriangulo * tiempoDiferencial);
			}
		}
		checarColisiones();
	}
	
	if (tiempoActual >= 2) {
		posXEstepicursor += velocidadEstepicursor * tiempoDiferencial;
	}
	posXNubeFrente += velocidadNubeFrente * tiempoDiferencial;
	posXNubeFondo += velocidadnubeFondo * tiempoDiferencial;

	tiempoAnterior = tiempoActual;
}

void dibujarTriangulo() {
	glPushMatrix();

	glTranslatef(posXTriangulo, posYTriangulo, 0.0f);
	glScalef(1.5, 1.5, 1.5);
	glBegin(GL_TRIANGLES);

	glColor3f(rojoTriangulo, verdeTriangulo, azulTriangulo);
	glVertex3f(0.0f, 0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);

	glEnd();
	glPopMatrix();
}

void dibujarCuadrado() {
	glPushMatrix();

	glTranslatef(posXCuadrado, posYCuadrado, 0.0f);
	glScalef(1.5, 1.5, 2.0);
	glBegin(GL_QUADS);

	glColor3f(0.7, 0.2, 0.5);

	glVertex3f(-0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, 0.15f, 0.0f);
	glVertex3f(0.15f, -0.15f, 0.0f);
	glVertex3f(-0.15f, -0.15f, 0.0f);

	glEnd();
	glPopMatrix();
}


void dibujar() {
	dibujarFondo();
	dibujarGato1();
	dibujarBolaDesierto();
	dibujarGato2();
	dibujarSenal();
	dibujarF();

	
}

int main()
{
    
	srand(time(NULL));
	randomNumber = 1 + rand() % (8 - 1);
	//Si no se pudo iniciar GLFW
	//Terminamos ejecucion
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW
	//inicializamos la ventana
	window =
		glfwCreateWindow(600, 600, "Ventana",
			NULL, NULL);
	//Si no se pudo crear la venata
	//Terminamos ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecemos la ventana como contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto
	//Se activan las funciones "modernas" (gpu)
	glewExperimental = true;

	GLenum errores = glewInit();
	if (errores != GLEW_OK) {
		glewGetErrorString(errores);
	}

	const GLubyte* versionGL =
		glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	//Establecemos que con cada evento de teclado
	//se llama a la función teclado_callback

	tiempoActual = glfwGetTime();
	tiempoAnterior = tiempoActual;
	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer region de dibujo
		glViewport(0, 0, 600, 600);
		//Establecemos el color de borrado
		//Valores RGBA
		glClearColor(0.96, 0.3898, 0.1824, 1);
		//Borrar!
		glClear(GL_COLOR_BUFFER_BIT | 
			GL_DEPTH_BUFFER_BIT);

		//Actualizar valores y dibujar
		actualizar();
		dibujar();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	//Despúes del ciclo de dibujo
	//Eliminamos venta y procesos de glfw
	glfwDestroyWindow(window);
	glfwTerminate();
}
