#include <GL/glut.h>
float k=0.4;

void draw(float a, float b, float c, float y) {
    glColor3f(a, b, c);
    glRectf(-0.40, -0.080 + y, 0.30, 0.080 + y);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    draw(1.0, 0.25, 0.0, 0.32 + k);
    draw(1.0, 1.0, 1.0, 0.16 + k);
    draw(0.1, 0.5, 0.1, 0.0 + k);
    glColor3f(0.6, 0.25, 0.0);
    glRectf(-0.4, -0.70, -0.45, 0.90);
    glFlush();
}

void idle(){
    k+=0.0001;
    if (k>=0.5) {
        k-=0.1;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("FLAG");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
