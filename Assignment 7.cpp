#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;

int arrx[4];
int arry[4];
int cnt=0;

void init(){
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3.0);
    glPointSize(3.0);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,800,600,0);
}

void set_pixel(int x,int y){
    glColor3b(1,0,0);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}

float bezier(float t,float p0,float p1,float p2,float p3){
    return p0*(1-t)*(1-t)*(1-t)  +  p1*3*t*(1-t)*(1-t)  +   p2*3*t*t*(1-t)  +  p3*t*t*t;
}

void draw_curve(){
    glColor3f(0.0,0.0,1.0); //blue
    glBegin(GL_LINE_STRIP);
    for(int j=0;j<1500;j++){
        float t=(float)j/1500;
        glVertex2f(bezier(t,arrx[0],arrx[1],arrx[2],arrx[3]), bezier(t,arry[0],arry[1],arry[2],arry[3]));
    }
    glEnd();
    glFlush();

    glColor3f(1.0,0.0,0.0); //red
    glBegin(GL_LINE_STRIP);
    for(int i=0;i<4;i++){
        glVertex2f(arrx[i],arry[i]);
        }
        glEnd();
        glFlush;
        cnt=0;
}

void mouse(int button,int state,int x,int y){
    if(state == GLUT_DOWN){
        if(button == GLUT_LEFT_BUTTON){
            if(cnt<4){
                glPointSize(3.0);
                set_pixel(x,y);
                arrx[cnt]=x;
                arry[cnt]=y;
                cnt++;
            }
            else
            draw_curve();
        }
        else {
                cnt=0;
                glClear(GL_COLOR_BUFFER_BIT);
        }
    }
}

void display(){
    glBegin(GL_POINTS);
    glEnd();
    glFlush();
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(40,40);
    glutCreateWindow("BEZIER_CURVE");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
