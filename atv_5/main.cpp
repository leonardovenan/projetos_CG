#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

GLfloat angulo, fAspect, rotX, rotY;
GLdouble obsZ;

void corFundo(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void iluminacao(void){
    GLfloat luzAmbiente[]={0.3,0.3,0.3,1.0};
    GLfloat luzDifusa[]={1.0,1.0,1.0,1.0};          // luz "branca"
    GLfloat luzEspecular[]={0.9, 0.9, 0.9, 0.9};    // brilho
    GLfloat posicaoLuz[]={60.0, 60.0, 60.0, 1.0};

    GLfloat luzAmbiente1[]={0.15,0.15,0.15,1.0};
    GLfloat luzDifusa1[]={1.0,1.0,1.0,1.0};          // luz "branca"
    GLfloat luzEspecular1[]={0.8, 0.8, 0.8, 0.8};
    GLfloat posicaoLuz1[]={-60.0, -60.0, -60.0, 1.0};

    // Capacidade de brilho, referente ao material
    GLfloat especularidade[]={0.8,0.8,0.8,0.8};
    GLint especularidadeMaterial = 60;

    // Define a refletância do material
    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);

    // Define a concentração do brilho
    glMateriali(GL_FRONT,GL_SHININESS, especularidadeMaterial);

    // Ativa o uso da luz ambiente
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente1);

    // Duas fontes de luz
    // Define os parâmetros da luz de número 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

    // Define os parâmetros da luz de número 1
    glLightfv(GL_LIGHT1, GL_AMBIENT, luzAmbiente1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa1 );
    glLightfv(GL_LIGHT1, GL_SPECULAR, luzEspecular1 );
    glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz1 );
}

void Desenha(void){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    iluminacao();
    //objeto desenhado, cubo
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (0.9, 0.0, 0.6); //cor do cubo

    glBegin(GL_POLYGON);
    glVertex3f(40.0, 40.0, 40.0);
    glVertex3f(-40.0, 40.0, 40.0);
    glVertex3f(-40.0, -40.0, 40.0);
    glVertex3f(40.0, -40.0, 40.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-40.0, 40.0, 40.0);
    glVertex3f(-40.0, 40.0, -40.0);
    glVertex3f(-40.0, -40.0, -40.0);
    glVertex3f(-40.0, -40.0, 40.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(40.0, 40.0, 40.0);
    glVertex3f(40.0, -40.0, 40.0);
    glVertex3f(40.0, -40.0, -40.0);
    glVertex3f(40.0, 40.0, -40.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(40.0, 40.0, -40.0);
    glVertex3f(40.0, -40.0, -40.0);
    glVertex3f(-40.0, -40.0, -40.0);
    glVertex3f(-40.0, 40.0, -40.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-40.0, 40.0, -40.0);
    glVertex3f(-40.0, 40.0, 40.0);
    glVertex3f(40.0, 40.0, 40.0);
    glVertex3f(40.0, 40.0, -40.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-40.0, -40.0, -40.0);
    glVertex3f(40.0, -40.0, -40.0);
    glVertex3f(40.0, -40.0, 40.0);
    glVertex3f(-40.0, -40.0, 40.0);
    glEnd();

    glutSwapBuffers();
}

void Inicializa(void){
    // inicialização de funçoes
    // definição da cor do material a partir da cor corrente
    glEnable(GL_COLOR_MATERIAL);
    //uso de iluminação
    glEnable(GL_LIGHTING);
    // depth-buffering
    glEnable(GL_DEPTH_TEST);
    // luz de número 0
    glEnable(GL_LIGHT0);
    // luz de número 1
    glEnable(GL_LIGHT1);
    // modelo de colorização de Gouraud
    glShadeModel(GL_FLAT);
    // variáveis para alteração a posição do observador
    obsZ = 220;
    rotX = 30;
    rotY = 30;
    // ângulo da projeção
    angulo = 45;
}

void observador(void){ //fica melhor organizado dessa maneira
    glMatrixMode(GL_MODELVIEW); // Especifica sistema de coordenadas
    glLoadIdentity(); // Carregamento do sistema de coordenadas
    iluminacao();
    // Posição do observador e do alvo a ser rotacionado
    glTranslatef(0,0,-obsZ);
    glRotatef(rotX,1,0,0);
    glRotatef(rotY,0,1,0);
}

void reshape(int w, int h){
    // Para previnir uma divisão por zero
    if ( h == 0 ) h = 1;
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    // Calcula a correção de aspecto
    fAspect = (GLfloat)w/(GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angulo,fAspect, 0.5, 500);
    observador();
}

// função de chamada para encerramento de janela
void teclado (unsigned char tecla, int x, int y){
    switch(tecla){
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

// Função de chamada para teclas especiais
void TeclasEspeciais (int tecla, int x, int y)
{
  switch (tecla)
  {
    case GLUT_KEY_RIGHT:
        rotY++;
        break;
    case GLUT_KEY_LEFT:
        rotY--;
        break;
    case GLUT_KEY_UP:
        rotX++;
        break;
    case GLUT_KEY_DOWN:
        rotX--;
        break;
    case GLUT_KEY_HOME:
        obsZ++;
        break;
    case GLUT_KEY_END:
        obsZ--;
        break;
        }
  observador();
  glutPostRedisplay();
}


int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Objeto iluminado");
    corFundo();
    glutDisplayFunc(Desenha);
    glutSpecialFunc(TeclasEspeciais);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(teclado);
    Inicializa();
    glutMainLoop();
    return 0;
}

