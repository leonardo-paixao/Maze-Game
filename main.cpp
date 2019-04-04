#include<windows.h>
#include<iostream>
#include <gl/glut.h>
#include <stdio.h>


//Variáveis
float posicaox, posicaoy, tamanho;
int flag;

// Inicializa parâmetros de rendering
void Inicializa(void) {
    // Define a cor de fundo da janela de visualização
    glClearColor(1.0f, 1.0f, 1.0f, 0.5f);    
    posicaox = 180;
	posicaoy = 350;
	tamanho = 20;
	flag = 0;
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
    // Evita a divisao por zero
    if (h == 0) 
		h = 1;

    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Estabelece a janela de seleção (left, right, bottom, top)
    if (w <= h)
        gluOrtho2D(0.0f, 400.0f, 0.0f, 400.0f * h / w);
    else
        gluOrtho2D(0.0f, 400.0f * w / h, 0.0f, 400.0f);
}

void DesenhaTitulo(int x, int y, char *string) {  
  	glPushMatrix();
        // Posição no universo onde o texto será colocado          
        glRasterPos2f(x, y); 
        // Exibe caracter a caracter
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*string++); 
	glPopMatrix();
}

void DesenhaTexto(int x, int y, char *string) {  
  	glPushMatrix();
        // Posição no universo onde o texto será colocado          
        glRasterPos2f(x, y); 
        // Exibe caracter a caracter
        while(*string)
             glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,*string++); 
	glPopMatrix();
}		

void Desenha(void) {
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	
    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0f, 0.0f, 0.0f);
    // Desenha um quadrado
    glBegin(GL_POLYGON);
	    glVertex2f(posicaox, posicaoy);   
	    glVertex2f(posicaox+tamanho, posicaoy);
	    glVertex2f(posicaox+tamanho, posicaoy+tamanho);
	    glVertex2f(posicaox, posicaoy+tamanho);
    glEnd();
    
    glColor3f(0.0f, 0.0f, 0.0f);
    //Desenha o labirinto
	glBegin(GL_LINE_LOOP);
		glVertex2i(0, 0);
		glVertex2i(100, 0);   
		glVertex2i(100, 100);
		glVertex2i(200, 100);
		glVertex2i(200, 200);
		glVertex2i(300, 200);
		glVertex2i(300, 300);
		glVertex2i(200, 300);
		glVertex2i(200, 400);
		glVertex2i(170, 400);
		glVertex2i(170, 270);
		glVertex2i(170, 270);	
		glVertex2i(270, 270);
		glVertex2i(270, 270);	
		glVertex2i(270, 230);
		glVertex2i(170, 230);
		glVertex2i(170, 130);
		glVertex2i(70, 130);
		glVertex2i(70, 30);
		glVertex2i(0, 30);  
		glVertex2i(0, 0);
		 
    glEnd();
    
    DesenhaTexto(230, 10, "Aluno: Leonardo Miranda");
    
    // Executa os comandos OpenGL
    glFlush();
}		
	
void TelaVitoria(){
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
	glClearColor(0.0f, 1.0f, 0.0f, 0.5f); 
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1,1,1);
    DesenhaTitulo(160,200, "VITORIA");
   	DesenhaTexto(50, 150, "Clique com o botao direito do mouse para sair.");
    
    // Executa os comandos OpenGL
    glFlush();
}

void TelaDerrota(){
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
	glClearColor(1.0f, 0.0f, 0.0f, 0.5f); 
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1,1,1);
    DesenhaTitulo(160,200, "DERROTA");
    DesenhaTexto(50, 150, "Clique com o botao direito do mouse para sair.");
    
    // Executa os comandos OpenGL
    glFlush();
}

void Vitoria(){
	glutDisplayFunc(TelaVitoria);
//	glutMouseFunc(Mouse);
}

void Derrota(){
	glutDisplayFunc(TelaDerrota);
//	glutMouseFunc(Mouse);
}

void colisao(float xi, float yi, float xf, float yf){
	if  ((xi == 00  || yi == 0)   || yf == 30  && xi <=  70		||
		((xi == 70  || xf == 70)  && yf >= 30  && yf <= 130) 	||
		((xi == 100 || xf == 100) && yi >= 0   && yi <= 100)	||
		((yi == 100 || yf == 100) && xf >= 100 && xf <= 200)	||
		((yi == 130 || yf == 130) && xi >= 70  && xi <= 170)	||
		((xi == 170 || xf == 170) && yf >= 130 && yf <= 230) 	||
		((xi == 200 || xf == 200) && yi >= 100 && yi <= 200)	||
		((yi == 200 || yf == 200) && xf >= 200 && xf <= 300)	||
		((yi == 230 || yf == 230) && xi >= 170 && xi <= 270)	||
		((xi == 270 || xf == 270) && yi <= 270 && yf >= 230) 	||
		((xi == 300 || xf == 300) && yi >= 200 && yi <= 300)	||
		((yi == 270 || yf == 270) && xi >= 170 && xi <= 270)	||
		((yi == 300 || yf == 300) && xf >= 200 && xf <= 300)	||
		((xi == 170 || xf == 170) && yf >= 270 && yf <= 399) 	||
		((xi == 200 || xf == 200) && yf >= 300 && yf <= 399)					
		){
			posicaox = 5;
			posicaoy = 5;
			flag++;
		}
		if (flag == 4)
			Derrota();
		
		if (yf == 400)
			Vitoria();
	}

void Mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON){
	    	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	    	glColor3f(0.0f, 0.0f, 1.0f);
	}	  
	  
	if (button == GLUT_RIGHT_BUTTON){
		if (state == GLUT_DOWN)
				exit(0);
	}	
    glutPostRedisplay();
}

void Teclado(unsigned char key, int x, int y) {
    switch (key) {
    	case 'Q':
    	exit(0);
	}
}

void TeclasEspeciais(int key, int x, int y){
    if(key == GLUT_KEY_DOWN) {
		posicaoy -= 1.0;
		printf ("xi = %.1f \nyi = %.1f \nxf = %.1f \nyf = %.1f \n\n", posicaox, posicaoy, posicaox+tamanho, posicaoy+tamanho);	
		colisao(posicaox, posicaoy, posicaox + tamanho, posicaoy + tamanho);
    }
    if(key == GLUT_KEY_UP) {
		posicaoy += 1.0;
		printf ("xi = %.1f \nyi = %.1f \nxf = %.1f \nyf = %.1f \n\n", posicaox, posicaoy, posicaox+tamanho, posicaoy+tamanho);	
		colisao(posicaox, posicaoy, posicaox + tamanho, posicaoy + tamanho);
    }
    if(key == GLUT_KEY_LEFT) {
		posicaox -= 1.0;
		printf ("xi = %.1f \nyi = %.1f \nxf = %.1f \nyf = %.1f \n\n", posicaox, posicaoy, posicaox+tamanho, posicaoy+tamanho);
		colisao(posicaox, posicaoy, posicaox + tamanho, posicaoy + tamanho);
    }
    if(key ==  GLUT_KEY_RIGHT) {
		posicaox += 1.0;
		printf ("xi = %.1f \nyi = %.1f \nxf = %.1f \nyf = %.1f \n\n", posicaox, posicaoy, posicaox+tamanho, posicaoy+tamanho);
		colisao(posicaox, posicaoy, posicaox + tamanho, posicaoy + tamanho);
    }
    glutPostRedisplay();
}


int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Labirinto");
    glutReshapeFunc(AlteraTamanhoJanela);
    glutDisplayFunc(Desenha);
	glutKeyboardFunc(Teclado);
	glutSpecialFunc(TeclasEspeciais);
	glutMouseFunc(Mouse);
    Inicializa();
    glutMainLoop();
	return 0;
}
