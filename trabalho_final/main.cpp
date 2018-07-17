#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

GLfloat angulo, fAspect, rotX, rotY;
GLdouble obsZ;
static GLfloat meio = 0;
static GLfloat contMeio = 0;

void corFundo(void){
    glClearColor(0.1, 0.1, 0.44, 1.0);
}

void iluminacao(void){
    GLfloat luzAmbiente[]={0.3,0.3,0.3,0.8};
    GLfloat luzDifusa[]={0.9,0.9,0.9,0.9};          // luz "branca"
    GLfloat luzEspecular[]={0.5, 0.5, 0.5, 0.5};    // brilho
    GLfloat posicaoLuz[]={80.0, 80.0, 80.0, 1.0};

    GLfloat luzAmbiente1[]={0.15,0.15,0.15,1.0};
    GLfloat luzDifusa1[]={0.5,0.5,0.5,0.5};          // luz "branca"
    GLfloat luzEspecular1[]={0.8, 0.8, 0.8, 0.8};
    GLfloat posicaoLuz1[]={50.0, 500.0, 1200, 0.0};

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

    //chao
    glColor3f(0.13,0.55,0.13);
    glBegin(GL_POLYGON);
    glVertex3f(120.0, 120.0, -40.0);
    glVertex3f(-120.0, 120.0, -40.0);
    glVertex3f(-120.0, -120.0, -40.0);
    glVertex3f(120.0, -120.0, -40.0);
    glEnd();


    glPushMatrix();
    glColor3f(0.7,0.45,0.2);
    //cubo
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

    //parte de cima moinho
    glColor3f(0.43,0.21,0.1);
    glBegin(GL_POLYGON);
    glVertex3f(40.0,40.0,40.0);
    glVertex3f(0.0,40.0,70.0);
    glVertex3f(-40.0,40.0,40.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-40.0,-40.0,40.0);
    glVertex3f(0.0,-40.0,70.0);
    glVertex3f(40.0,-40.0,40.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-40.0,40.0,40.0);
    glVertex3f(-40.0,-40.0,40.0);
    glVertex3f(0.0,-40.0,70.0);
    glVertex3f(0.0,40.0,70.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(40.0,40.0,40.0);
    glVertex3f(40.0,-40.0,40.0);
    glVertex3f(0.0,-40.0,70.0);
    glVertex3f(00.0,40.0,70.0);
    glEnd();

    glPopMatrix();
    glPushMatrix();
    glTranslated(0.0,0.0,40.0); //rotação no eixo y
    glRotated(meio,0.0,1.0,0.0);
    glTranslated(0.0,0.0,-40.0);

    //helices moinho
    glColor3f(0.6,0.6,0.6);

    glBegin(GL_POLYGON);
    glVertex3f(0.0,45.0,40.0);
    glVertex3f(65.0,45.0,55.0);
    glVertex3f(65.0,45.0,20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.0,45.0,40.0);
    glVertex3f(-65.0,45.0,55.0);
    glVertex3f(-65.0,45.0,20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.0,45.0,40.0);
    glVertex3f(20.0,45.0,-25.0);
    glVertex3f(-20.0,45.0,-25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.0,45.0,40.0);
    glVertex3f(20.0,45.0,95.0);
    glVertex3f(-20.0,45.0,95.0);
    glEnd();

    glColor3f(0.66, 0.66, 0.66);
    glBegin(GL_POLYGON);
    glVertex3f(0.0,45.0,40.0);
    glVertex3f(65.0,45.0,55.0);
    glVertex3f(65.0,45.0,20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.0,40.0,40.0);
    glVertex3f(-65.0,45.0,55.0);
    glVertex3f(-65.0,45.0,20.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.0,40.0,40.0);
    glVertex3f(20.0,45.0,-25.0);
    glVertex3f(-20.0,45.0,-25.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.0,40.0,40.0);
    glVertex3f(20.0,45.0,95.0);
    glVertex3f(-20.0,45.0,95.0);
    glEnd();

    glPopMatrix();

    //eixo das helices
    glPushMatrix();
    glTranslated(0.0,40.0,40.0);
    glColor3f (0.66, 0.66, 0.66); //cor da esfera
    glutSolidSphere(7, 150, 100); //padrões esfera
    glPopMatrix();


    //Lua

    glPushMatrix();
    glTranslated(50.0,-160.0,110.0);
    glColor3f (1.0, 0.98, 0.94); //cor da esfera
    glutSolidSphere(40, 500, 120); //padrões esfera
    glPopMatrix();

    glEnable(GL_BLEND); //ativação neblina
    //estrelas
    glPushMatrix();
    glTranslated(100.0,-170.0,120.0);
    glColor3f (1.0, 0.98, 0.94); //cor da esfera
    glutSolidSphere(1, 500, 120); //padrões esfera
    glPopMatrix();

    glPushMatrix();
    glTranslated(-100,-183.0,143.0);
    glColor3f (1.0, 0.98, 0.94); //cor da esfera
    glutSolidSphere(1, 500, 120); //padrões esfera
    glPopMatrix();

    glPushMatrix();
    glTranslated(120,-183.0,110.0);
    glColor3f (1.0, 0.98, 0.94); //cor da esfera
    glutSolidSphere(1, 500, 120); //padrões esfera
    glPopMatrix();

    glPushMatrix();
    glTranslated(120,-230.0,180.0);
    glColor3f (1.0, 0.98, 0.94); //cor da esfera
    glutSolidSphere(1, 500, 80); //padrões esfera
    glPopMatrix();

    glPushMatrix();
    glTranslated(111,-238.0,160.0);
    glColor3f (1.0, 0.98, 0.94); //cor da esfera
    glutSolidSphere(1, 500, 80); //padrões esfera
    glPopMatrix();


    glPushMatrix();
    glTranslated(-134,-173.0,113.0);
    glColor3f (1.0, 0.98, 0.94); //cor da esfera
    glutSolidSphere(1, 500, 120); //padrões esfera
    glPopMatrix();

    glPushMatrix();
    glTranslated(-170,-193.0,133.0);
    glColor3f (1.0, 0.98, 0.94); //cor da esfera
    glutSolidSphere(1, 500, 120); //padrões esfera
    glPopMatrix();

    glPushMatrix();
    glTranslated(170,-193.0,133.0);
    glColor3f (1.0, 0.98, 0.94); //cor da esfera
    glutSolidSphere(1, 500, 120); //padrões esfera
    glPopMatrix();

    glPushMatrix();
    glTranslated(183,-163.0,113.0);
    glColor3f (1.0, 0.98, 0.94); //cor da esfera
    glutSolidSphere(1, 500, 120); //padrões esfera
    glPopMatrix();


    glRasterPos3d(40.0,40.0,40.0);
    glPixelZoom(1,1);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glBlendFunc(GL_DST_COLOR , GL_ONE_MINUS_DST_COLOR);
    glDisable(GL_BLEND);

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
    obsZ = 260;
    rotX = 290;
    rotY = 160;
    // ângulo da projeção
    angulo = 60;
}

void observador(void){ //fica melhor organizado dessa maneira
    glMatrixMode(GL_MODELVIEW); // Especifica sistema de coordenadas
    glLoadIdentity(); // Carregamento do sistema de coordenadas
    iluminacao();
    // Posição do observador e do alvo a ser rotacionado
    glTranslatef(1,1,-obsZ);
    glRotatef(rotX,1,0,0);
    glRotatef(rotY,0,0,1);
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
        case 49:
            meio +=2; // + 2 graus de giro (velocidade de giro)
            contMeio = 1;
            glutPostRedisplay();
            break;
        case 50:
            meio -=2; // - 2 graus de giro (velocidade de giro)
            contMeio = -1;
            glutPostRedisplay();
            break;
        case 'p':
            contMeio = 0;
            break;
        case 'P':
            contMeio = 0;
            break;
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
        obsZ--;
        break;
    case GLUT_KEY_END:
        obsZ++;
        break;
        }
  observador();
  glutPostRedisplay();
}

void animacao(int passo){
    meio = meio + contMeio;
    glutPostRedisplay();
    glutTimerFunc(10, animacao, 1);

}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Moinho Obscuro");
    corFundo();
    glutDisplayFunc(Desenha);
    glutSpecialFunc(TeclasEspeciais);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(teclado);
    Inicializa();
    glutTimerFunc(10,animacao,1);
    glutMainLoop();
    return 0;
}

