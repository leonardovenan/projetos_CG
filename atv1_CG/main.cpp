#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);       // Especificar o uso de cores e buffers
  glutInitWindowSize (600, 400);                     // Especificar as dimensoes da janela
  glutInitWindowPosition (100, 80);                  // Especificar aonde a janela aparece na tela
  glutCreateWindow ("Primeira Atividade");     // Criar a janela
  init();
  glutDisplayFunc(display);       // Funcao que sera redesenhada pelo GLUT
  glutKeyboardFunc(keyboard);     // Funcoes de teclado
  glutMainLoop();                 // Mostrar todas as janelas criadas
  return 0;
}

// definicao de cada funcao

void init(void){
  glClearColor(1.0, 1.0, 1.0, 1.0);    // Cor de fundo da janela criada
  glOrtho (0, 256, 0, 256, -1 ,1);     // Modo de projecao ortogonal
}

void display(void){
}
void quadrado(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(40,40);
    glVertex2i(40,190);
    glVertex2i(190,190);
    glVertex2i(190,40);
    glEnd();
    glFlush();
}
void cubo(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.7, 0.2);
    glBegin(GL_LINE_LOOP);
    glVertex2i(40,40);
    glVertex2i(40,190);
    glVertex2i(190,190);
    glVertex2i(190,40);
    glEnd();

    glColor3f (1.0, 0.7, 0.2);
    glBegin(GL_LINE_LOOP);
    glVertex2i(60,60);
    glVertex2i(60,210);
    glVertex2i(210,210);
    glVertex2i(210,60);
    glEnd();

    glColor3f(1.0, 0.7, 0.2);
    glBegin(GL_LINES);
    glVertex2i(40,40);
    glVertex2i(60,60);
    glVertex2i(40,190);
    glVertex2i(60,210);
    glVertex2i(190,190);
    glVertex2i(210,210);
    glVertex2i(190,40);
    glVertex2i(210,60);
    glEnd();

    glFlush();
}

void casa(){
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_LOOP);
    glColor3f(0.6,0.2,1.0);
    glVertex2i(50,80);
    glVertex2i(50,120);
    glVertex2i(90,120);
    glVertex2i(90,80);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.6,0.2,1.0);
    glVertex2i(90,120);
    glVertex2i(90,80);
    glVertex2i(120,105);
    glVertex2i(120,140);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.6,0.2,1.0);
    glVertex2i(50,120);
    glVertex2i(70,150);
    glVertex2i(90,120);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0.6,0.2,1.0);
    glVertex2i(70,150);
    glVertex2i(90,120);
    glVertex2i(120,140);
    glVertex2i(101,165);
    glEnd();
    glFlush();
}

void estrela(){
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.0, 9.0, 0.3);
 glBegin(GL_LINE_LOOP);
 glVertex2i(75,100);
 glVertex2i(110,195);
 glVertex2i(145, 100);
 glVertex2i(60,162);
 glVertex2i(160,162);
 glEnd();
 glFlush();

}
void keyboard(unsigned char key, int x, int y){
  switch (key) {
    case 27: 
      exit(0);
      break;

    case 49: 
      quadrado();
      break;

    case 50: 
      cubo();
      break;

    case 51: 
      casa();
      break;

    case 52: 
      estrela();
      break;
  }
}
