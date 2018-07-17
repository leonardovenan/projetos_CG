#include <GL/glut.h>
#include <stdlib.h>

static int meio = 0;

void corFundo(void){
    glClearColor (0.0, 0.5, 1.0, 0.5);
}

void cata_vento(void){

    glClear (GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    glColor3f(0.9,0.5,0.4);
    glBegin(GL_TRIANGLES);
    glVertex2f(-2.0,0.0);
    glVertex2i(0.0,2);
    glVertex2f(2,0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,0.6,0.4);
    glVertex2f(-2,0);
    glVertex2f(-2,-2);
    glVertex2f(2,-2);
    glVertex2f(2,0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(-3.0,2.3);
    glVertex2f(-2.5,2.3);
    glVertex2f(-2.5,2.0);
    glVertex2f(-3.0,2.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(-2.0,2.5);
    glVertex2f(-1.5,2.5);
    glVertex2f(-1.5,2.2);
    glVertex2f(-2.0,2.2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(0.0,2.25);
    glVertex2f(-0.5,2.25);
    glVertex2f(-0.5,2.0);
    glVertex2f(0.0,2.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(1.0,2.25);
    glVertex2f(0.5,2.25);
    glVertex2f(0.5,1.9);
    glVertex2f(1.0,1.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex2f(3.0,2.4);
    glVertex2f(2.5,2.4);
    glVertex2f(2.5,2.1);
    glVertex2f(3.0,2.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.3,0.3,0.3);
    glVertex2f(-0.5,-0.4);
    glVertex2f(-0.5,-1.0);
    glVertex2f(0.5,-1.0);
    glVertex2f(0.5,-0.4);
    glEnd();
    glPopMatrix();
    glPushMatrix();

    glColor3f(0.6,0.6,0.6);
    glTranslatef(0.0, 0.5, 0.0); //ponto onde quero as helices
    glRotatef((GLfloat) meio, 0.0, 0.0, 1.0); //rotação no eixo z

    glBegin(GL_TRIANGLES);
    glVertex2f(0.0,-1.6);
    glVertex2i(0,0);
    glVertex2f(1.0,-1.6);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-1.0,1.6);
    glVertex2i(0,0);
    glVertex2f(0.0,1.6);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(1.6,0.0);
    glVertex2i(0,0);
    glVertex2f(1.6,1.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-1.6,0.0);
    glVertex2i(0,0);
    glVertex2f(-1.6,-1.0);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape (int w, int h){
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef (0.0, 0.0, -5.0);
    }

void keyboard (unsigned char teclado, int x, int y){
    switch (teclado) {
        case 49:
            meio +=2; // + 2 graus de giro (velocidade de giro)
            glutPostRedisplay();
            break;
        case 50:
            meio -=2; // - 2 graus de giro (velocidade de giro)
            glutPostRedisplay();
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
        }
    }

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    corFundo();
    glutDisplayFunc(cata_vento);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
    }
