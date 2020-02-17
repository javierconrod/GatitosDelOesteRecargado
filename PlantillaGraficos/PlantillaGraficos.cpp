// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <math.h>

#include <iostream>

using namespace std;

//Declarar una ventana

GLFWwindow* window;
float posXEstepicursor = -2.0f; 
float posXNubeFrente = -0.2f;
float posXNubeFondo = -0.5;

float posXTriangulo = 0.5f , posYTriangulo = -0.5f;

float posXCuadrado = -0.5f, posYCuadrado = 0.0f;

double tiempoActual, tiempoAnterior;
double velocidadTriangulo = 0.8;

float rojoTriangulo = 0.2f;
float verdeTriangulo = 0.6f;
float azulTriangulo = 0.1f;

void teclado_callback(GLFWwindow* window,
	int key, int scancode, int action, int mods) {

	if (
		(action == GLFW_PRESS || action == GLFW_REPEAT) 
		&& key == GLFW_KEY_RIGHT) {
		posXTriangulo += 0.01;
	}

	if (
		(action == GLFW_PRESS || action == GLFW_REPEAT)
		&& key == GLFW_KEY_LEFT) {
		posXTriangulo -= 0.01;
	}

	if (
		(action == GLFW_PRESS || action == GLFW_REPEAT)
		&& key == GLFW_KEY_UP) {
		posYTriangulo += 0.01;
	}

	if (
		(action == GLFW_PRESS || action == GLFW_REPEAT)
		&& key == GLFW_KEY_DOWN) {
		posYTriangulo -= 0.01;
	}



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
	for (double i = 1; i < 360; i += 5.0)
	{
		if ( i % 2 == 0 ) {
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
		posXTriangulo + 0.15f >= posXCuadrado - 0.15f &&
		//orilla izquierda del triangulo es meor que la orilla derecha del cuadrado
		posXTriangulo - 0.15f <= posXCuadrado + 0.15f &&
		//la parte de arriba
		posYTriangulo + 0.15f >= posYCuadrado - 0.15f &&
		//la parte de abajo
		posYTriangulo - 0.15f <= posYCuadrado + 0.15f) {
		rojoTriangulo = 0.0f;
		verdeTriangulo = 0.0f;
		azulTriangulo = 0.0f;
	}
	else {
		rojoTriangulo = 0.2f;
		verdeTriangulo = 0.6f;
		azulTriangulo = 0.1f;
	}
}

void actualizar() {
	tiempoActual = glfwGetTime();

	cout << tiempoActual<<"   ";

	if (tiempoActual >= 2) {
		posXEstepicursor += 0.0003f;
	}
	posXNubeFrente += 0.00001f;
	posXNubeFondo += 0.000001;
	

	checarColisiones();
	

	double tiempoDiferencial = 
		tiempoActual - tiempoAnterior;
	int estadoDerecha =
		glfwGetKey(window, GLFW_KEY_RIGHT);
	if (estadoDerecha == GLFW_PRESS) {
		posXTriangulo += velocidadTriangulo * tiempoDiferencial;
	}
	int estadoArriba =
		glfwGetKey(window, GLFW_KEY_UP);
	if (estadoArriba == GLFW_PRESS) {
		posYTriangulo += velocidadTriangulo * tiempoDiferencial;
	}
	int estadoIzquierda =
		glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoIzquierda == GLFW_PRESS) {
		posXTriangulo -= velocidadTriangulo * tiempoDiferencial;
	}
	int estadoAbajo =
		glfwGetKey(window, GLFW_KEY_DOWN);
	if (estadoAbajo == GLFW_PRESS) {
		posYTriangulo -= velocidadTriangulo * tiempoDiferencial;
	}

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
	dibujarCuadrado();
	dibujarBolaDesierto();
	dibujarTriangulo();

	
}

int main()
{
    

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
	//glfwSetKeyCallback(window, teclado_callback);

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
