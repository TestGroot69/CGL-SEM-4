#include <gl/glut.h>
#include <bits/stdc++.h>
using namespace std;

const int h=700;
const int w=700;

int choice;
double tx,ty;
double shx,shy;
double sx,sy;
double ax,ay,angle,radAngle;
char axis;

double polx[3]={250,350,450};
double poly[3]={250,350,250};

void init(){
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-h,h,-w,w);
}

void setPixel(int x,int y){
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
    glLineWidth(2);
    glVertex2f(x,y);
    glEnd();
    glFlush();
}

void drawPolygon(){
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<3;i++){
        glVertex2f(polx[i],poly[i]);
    }
    glEnd();
    glFlush();
}
void translation(){
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<3;i++){
        glVertex2f(polx[i]+tx,poly[i]+ty);
    }
    glEnd();
    glFlush();
}
void scaling(){
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<3;i++){
        glVertex2f(polx[i]*sx,poly[i]*sy);
    }
    glEnd();
    glFlush();
}
void shearing(){
glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<3;i++){
        glVertex2f(polx[i]+shx*poly[i],poly[i]+shy*polx[i]);
    }
    glEnd();
    glFlush();
}
void reflection(){
    if(axis=='x' || axis=='X'){
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<3;i++){
        glVertex2f(polx[i],poly[i]*(-1));
    }
    glEnd();
    glFlush();
    }
    else{
        glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<3;i++){
        glVertex2f(polx[i]*(-1),poly[i]);
    }
    glEnd();
    glFlush();
    }
}
void rotation(){
    radAngle=angle*3.14/180;
    double r=radAngle;
     glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<3;i++){
        glVertex2f(polx[i]*cos(r)-poly[i]*sin(r)-ax*cos(r)+ay*sin(r)+ax,
                   polx[i]*sin(r)+poly[i]*cos(r)-ax*sin(r)-ay*cos(r)+ay);

    }
    glEnd();
    glFlush();
}

void display(){
    for(int i=-w;i<w;i++){
        setPixel(i,0);
        setPixel(0,i);
    }
    drawPolygon();
    if(choice==1){
        translation();
    }
    else if(choice==2){
        scaling();
    }
    else if(choice==3){
        shearing();
    }
    else if(choice==4){
        rotation();
    }
    else if(choice==5){
        reflection();
    }
}

int main(int argc, char** argv) {

    cout<<"Enter your choice"<<endl;
    cout<<"1. translation"<<endl;
    cout<<"2. scale"<<endl;
    cout<<"3. sharing"<<endl;
    cout<<"4. rotation"<<endl;
    cout<<"5. reflection"<<endl;
    cin>>choice;
    if(choice==1){
        cout<<"enter tx: ";
        cin>>tx;
        cout<<endl;
        cout<<"enter ty: ";
        cin>>ty;
        cout<<endl;

    }else if(choice==2){
        cout<<"enter sx: ";
        cin>>sx;
        cout<<endl;
        cout<<"enter sy: ";
        cin>>sy;
        cout<<endl;
    }else if(choice==3){
        cout<<"enter sx: ";
        cin>>shx;
        cout<<endl;
        cout<<"enter sy: ";
        cin>>shy;
        cout<<endl;
    }else if(choice==4){
        cout<<"enter ax: ";
        cin>>ax;
        cout<<endl;
        cout<<"enter ay: ";
        cin>>ay;
        cout<<endl;
        cout<<"enter angle";
        cin>>angle;

    }else if(choice==5){
        cout<<"enter axis: ";
        cin>>axis;
        cout<<endl;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(h,w);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("2D Transformations");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
