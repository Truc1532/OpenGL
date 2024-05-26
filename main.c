#include <GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <time.h>

int pixelX = 10, pixelY = 10;
int chaseX = 400, chaseY = 300;
int chaseSpeed = 2;

void display(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1024, 0, 768);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPointSize(5.0);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2i(pixelX, pixelY);
    glEnd();

    glPointSize(5.0);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2i(chaseX, chaseY);
    glEnd();

    if (abs(pixelX - chaseX) < 2 && abs(pixelY - chaseY) < 2) {
        exit(0);
    }

    glFlush();
    glutSwapBuffers();
}

void updateChase() {
    int dx = pixelX - chaseX;
    int dy = pixelY - chaseY;

    if (abs(dx) > abs(dy)) {
        if (dx > 0) {
            chaseX += chaseSpeed;
        } else {

            chaseX -= chaseSpeed;
        }

    } else {
        if (dy > 0) {
            chaseY += chaseSpeed;
        } else {
            chaseY -= chaseSpeed;

        }

    }

    glutPostRedisplay();

}
void specialKeys(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_UP:
            if (pixelY < 768) {
            pixelY += 6;
            }
            break;
        case GLUT_KEY_DOWN:
            if (pixelY > 0) {
            pixelY -= 6;
            }
            break;
        case GLUT_KEY_LEFT:
            if (pixelX > 0) {
            pixelX -= 6;
            }
            break;
        case GLUT_KEY_RIGHT:
            if (pixelX < 1024) {
            pixelX += 6;
            }
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    srand(time(0));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("OpenGL window");
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutIdleFunc(updateChase);
    glutMainLoop();
    return 0;

}

