#include<windows.h>
#include <GL/glut.h>
#include<iostream>
#include <stdlib.h>

using namespace std;

const int w = 600;
const int h = 600;

GLint x1,y1,x2,y2;

void setpixel(GLint x, GLint y){
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}


void initialize(){
    glClearColor(0.0,1.0,0.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
}


void display(){
    int i;
    glPointSize(3.0);
    for(i=-w; i<w; i++){
        setpixel(0,i);
        setpixel(i,0);
    }

}

class Line{

    public:
        void dda(int item){
            GLfloat dx,dy,step,x,y;
            GLfloat xinc, yinc;

            int i;
            dx = x2-x1;
            dy = y2-y1;
            if(abs(dx)>=abs(dy)){
                step = dx;
            }
            else{
                step = dy;
            }

            xinc = (float)dx/step;
            yinc = (float)dy/step;

            x=x1;
            y=y1;

            setpixel(x,y);

            if(item == 1){
                for(i=1; i<=step; i++){
                    x+=xinc;
                    y+=yinc;

                    x1=x+0.5;
                    y1=y+0.5;

                    setpixel(x1,y1);
                }
            }
            if(item == 2){
                for(i=1; i<=step; i++){
                    x+=xinc;
                    y+=yinc;

                    x1=x+0.5;
                    y1=y+0.5;

                    if(i%6==0){
                        setpixel(x1,y1);
                    }
                }
            }

            if(item == 3){
                for(i=1; i<=step; i++){
                    x+=xinc;
                    y+=yinc;

                    x1=x+0.5;
                    y1=y+0.5;

                    if(i%10 < 5){
                        setpixel(x1,y1);
                    }
                }
            }

            if(item == 4){
                for(i=1; i<=step; i++){
                    x+=xinc;
                    y+=yinc;

                    x1=x+0.5;
                    y1=y+0.5;
                    glPointSize(5.0);
                    setpixel(x1,y1);
                }
            }


        }

        void Bresenham(int item){
            GLfloat dx = abs(x1-x2),dy = abs(y1-y2);
            GLfloat p = 2*dy - dx;
            GLfloat twoDy = 2*dy, twoDyDx = 2*(dy-dx);
            GLint x,y,xEnd;

            bool increment = true;
            if(x1<x2 && y1<y2){
                x = x1;
                xEnd = x2;
                y = y1;
            }
            else if(x1<x2 && y1>y2){
                x=x1;
                xEnd = x2;
                y=y1;
                increment = false;
            }
            else if(x1>x2 && y1<y2){
                x=x2;
                xEnd = x1;
                y= y2;
                increment =false;
            }
            else if(x1>x2 && y1>y2){
                x=x2;
                xEnd = x1;
                y= y2;
            }

            if(item == 5){
                setpixel(x,y);
                while(x<=xEnd){
                    x++;
                    if(p<0){
                        p+=twoDy;
                    }
                    else{
                        if(increment){
                                y++ ;}
                        else{
                            y--;
                        }
                        p+=twoDyDx;
                    }
                    setpixel(x,y);
                }
            }
            if(item == 6){
                setpixel(x,y);
                while(x<=xEnd){
                    x++;
                    if(p<0){
                        p+=twoDy;
                    }
                    else{
                        if(increment){y++;}
                        else{
                            y--;
                        }
                        p+=twoDyDx;
                    }
                    if(x%6==0){
                        setpixel(x,y);
                    }
}
            }
            if(item == 7){
                setpixel(x,y);
                while(x<=xEnd){
                    x++;
                    if(p<0){
                        p+=twoDy;
                    }
                    else{
                        if(increment){
                                y++ ;}
                        else{
                            y--;
                        }
                        p+=twoDyDx;
                    }
                    if (abs(x)%10 < 5){
                        setpixel(x,y);
                    }
                }
            }
            if(item == 8){
                glPointSize(5.0);
                setpixel(x,y);
                while(x<=xEnd){
                    x++;
                    if(p<0){
                        p+=twoDy;
                    }
                    else{
                        if(increment){
                                y++ ;}
                        else{
                            y--;
                        }
                        p+=twoDyDx;
                    }
                    setpixel(x,y);
                }
            }
        }


};

Line obj;

void keyboard(unsigned char key, int x, int y){
    if(key == 27){
        exit(0);
    }
}

void menu(int item){
    if(item == 1){
        obj.dda(1);
    }

    if(item==2){
        obj.dda(2);
    }
    if(item==3){
        obj.dda(3);
    }
    if(item==4){
        obj.dda(4);
    }
    if(item==5){
        obj.Bresenham(5);
    }
    if(item==6){
        obj.Bresenham(6);
    }
    if(item==7){
        obj.Bresenham(7);
    }
    if(item==8){
        obj.Bresenham(8);
    }
    if(item == 9){
        exit(0);
    }

}

void mouse(int button, int state, int x, int y){
    if(state == GLUT_DOWN){
        if(button == GLUT_LEFT_BUTTON){
            x1 = x-w/2;
            y1= h/2 -y;
            glPointSize(3.0);
            setpixel(x1,y1);
        }

        else{
            if(button == GLUT_RIGHT_BUTTON){
                x2=x-w/2;
                y2=h/2-y;
                glPointSize(3.0);
                setpixel(x2,y2);
            }
        }
    }
}

int main(int argc, char **argv){

    glutInit(&argc,argv);
    glutInitWindowSize(w,h);
    glutInitWindowPosition(100,0);
    glutCreateWindow("ASSIGNMENT-2");
    initialize();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutCreateMenu(menu);
    glutAddMenuEntry("DDA_SIMPLE",1);
    glutAddMenuEntry("DDA_DOTTED",2);
    glutAddMenuEntry("DDA_DASHED",3);
    glutAddMenuEntry("DDA_SOLID",4);
    glutAddMenuEntry("BRESEHMAN_SIMPLE",5);
    glutAddMenuEntry("BRESEHMAN_DOTTED",6);
    glutAddMenuEntry("BRESEHMAN_DASHED",7);
    glutAddMenuEntry("BRESEHMAN_SOLID",8);
    glutAddMenuEntry("EXIT",9);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
    glutMainLoop();
    return 0;

}
