#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
int status = 0;
float c1x=0.0,c1y=0.0,c1z=0.0;//position f car1
float c2x=0.0,c2y=0.0,c2z=0.0;//position of car2
float width=-940,width2=600;//to move cars

float sr=0.0f,sg=0.5f,sb=1.0f;//original colors of the sky -baby blue
float snr= 1.0f,sng= 1.0f,snb= 0.0f;//colors of the sun
float cdr=1.0f,cdg=1.0f,cdb=1.0f;//colors of the clouds
float m1r=0,m1g=0.5f,m1b=1.0f;//colors to draw moon
float m2r=0,m2g=0.5f,m2b=1.0f;
float lr=1,lg=1,lb=1;//lamp colors
float gdr=0,gdg=0.4,gdb=0;//grass color

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 902.0, 0.0, 684.0);
}
void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int nbTrng = 50;
    GLfloat twicePi = 2.0f *3.14159265359;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y); // center of circle
    for(int i = 0; i <= nbTrng; i++)
    {
        glVertex2d(
            x + (radius * cos(i *  twicePi / nbTrng)),
            y + (radius * sin(i * twicePi / nbTrng))
        );
    }
    glEnd();
}
void sky()
{
    glPushMatrix();
    glColor3f(sr,sg,sb);
    glBegin(GL_QUADS);
    glVertex2i(0,684);
    glVertex2i(902,684);
    glVertex2i(902,0);
    glVertex2i(0,0);
    glEnd();
    glPopMatrix();
    glutPostRedisplay();
}
void moon()
{
    glPushMatrix();
    glColor3f(m1r,m1g,m1b);
    drawCircle(730.0f,620.0f,40.0f);
    glColor3f(m2r,m2g,m2b);
    drawCircle(740.0f,640.0f,40.0f);
    glPopMatrix();
}
void sun()
{
    glColor3f(snr,sng,snb);
    drawCircle(824.0f,615.0f,40.0f);
    glutPostRedisplay();
}
void windows(int x,int y)
{
    glPushMatrix();
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(x,y);
    glVertex2i(x+12,y);
    glVertex2i(x+12,y+18);
    glVertex2i(x,y+18);
    glEnd();
    glPopMatrix();
}
void hospital()
{
    glPushMatrix();
    glColor3ub(252,222,66);
    glBegin(GL_QUADS);
    glVertex2i(151,257);
    glVertex2i(181,257);
    glVertex2i(181,424);
    glVertex2i(151,424);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(252,222,66);
    glBegin(GL_QUADS);
    glVertex2i(449,257);
    glVertex2i(449,424);
    glVertex2i(420,424);
    glVertex2i(420,257);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(252,222,66);
    glBegin(GL_QUADS);
    glVertex2i(181,381);
    glVertex2i(420,381);
    glVertex2i(420,400);
    glVertex2i(181,400);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(190,27,9);
    glBegin(GL_QUADS);
    glVertex2i(181,258);
    glVertex2i(420,258);
    glVertex2i(420,381);
    glVertex2i(181,381);
    glEnd();
    glPopMatrix();

    int counter1=163;
    for(int i=11; i>=0; i--)
    {
        counter1+=20;
       windows(counter1,349);
    }
    int counter2=163;
    for(int i=11; i>=0; i--)
    {
        counter2+=20;
        windows(counter2,315);
    }
    int counter3=163;
    for(int i=11; i>=0; i--)
    {
        counter3+=20;
        windows(counter3,281);
    }
    glPushMatrix(); //middle
    glColor3ub(252,222,66);
    glBegin(GL_QUADS);
    glVertex2i(263,257);
    glVertex2i(339,257);
    glVertex2i(339,400);
    glVertex2i(263,400);
    glEnd();
    glPopMatrix();

    int counter4=260;
    for(int i=3; i>=0; i--)
    {
        counter4+=14;
        windows(counter4,370);
    }
    int counter5=260;
    for(int i=3; i>=0; i--)
    {
        counter5+=14;
        windows(counter5,340);
    }
    int counter6=260;
    for(int i=3; i>=0; i--)
    {
        counter6+=14;
        windows(counter6,310);
    }

    glPushMatrix();  //Door
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(286,257);
    glVertex2i(318,257);
    glVertex2i(318,298);
    glVertex2i(286,298);
    glEnd();
    glPopMatrix();

    glutPostRedisplay();
}

void hospitalLogo(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int nbTrng = 50;
    GLfloat twicePi = 2.0f * 3.1416;
    glColor3ub(252,222,66);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y); // center of circle
    for(i = 0; i <= nbTrng; i++)
    {
        glVertex2d(
            x + (radius * cos(i *  twicePi / nbTrng)),
            y + (radius * sin(i * twicePi / nbTrng))
        );
    }
    glEnd();

    glPushMatrix();
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(295,395);
    glVertex2i(307,395);
    glVertex2i(307,426);
    glVertex2i(295,426);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(284,408);
    glVertex2i(318,408);
    glVertex2i(318,418);
    glVertex2i(284,418);
    glEnd();
    glPopMatrix();
}
void building()
{
    glPushMatrix();
    glColor3ub(8,32,19);
    glBegin(GL_QUADS);
    glVertex2i(449,257);
    glVertex2i(644,257);
    glVertex2i(644,289);
    glVertex2i(449,289);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(23,60,43);
    glBegin(GL_QUADS);
    glVertex2i(473,289);
    glVertex2i(500,289);
    glVertex2i(500,413);
    glVertex2i(473,413);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(15,47,106);
    glBegin(GL_QUADS);
    glVertex2i(500,289);
    glVertex2i(517,289);
    glVertex2i(517,435);
    glVertex2i(500,435);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(21,63,53);
    glBegin(GL_QUADS);
    glVertex2i(517,289);
    glVertex2i(617,289);
    glVertex2i(617,408);
    glVertex2i(517,408);
    glEnd();
    glPopMatrix();

    glColor3ub(23,60,43);  // side circle
    drawCircle(475.0f,310.0f,18.0f);
    drawCircle(475.0f,348.0f,18.0f);
    drawCircle(475.0f,383.0f,18.0f);

    int bcounter1=430;
    for(int i=7; i>=0; i--)
    {
        bcounter1+=24;
        windows(bcounter1,267);
    }
    int bcounter2=498;
    for(int i=3; i>=0; i--)
    {
        bcounter2+=24;
        windows(bcounter2,377);
    }
    int bcounter3=498;
    for(int i=3; i>=0; i--)
    {
        bcounter3+=24;
        windows(bcounter3,350);
    }
    int bcounter4=498;
    for(int i=3; i>=0; i--)
    {
        bcounter4+=24;
        windows(bcounter4,323);
    }
    int bcounter5=498;
    for(int i=3; i>=0; i--)
    {
        bcounter5+=24;
        windows(bcounter5,295);
    }
}
void school()
{
    glPushMatrix();
    glColor3ub(214,130,5);
    glBegin(GL_QUADS);
    glVertex2i(643,257);
    glVertex2i(884,257);
    glVertex2i(884,351);
    glVertex2i(643,351);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(73,3,5);
    glBegin(GL_QUADS);
    glVertex2i(640,351);
    glVertex2i(887,351);
    glVertex2i(887,358);
    glVertex2i(640,358);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(80,149,146);
    glBegin(GL_QUADS);
    glVertex2i(648,265);
    glVertex2i(719,265);
    glVertex2i(719,275);
    glVertex2i(648,275);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(80,149,146);
    glBegin(GL_QUADS);
    glVertex2i(808,265);
    glVertex2i(879,265);
    glVertex2i(879,275);
    glVertex2i(808,275);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(217,132,3);
    glBegin(GL_POLYGON);
    glVertex2i(713,358);
    glVertex2i(813,358);
    glVertex2i(813,381);
    glVertex2i(763,402);
    glVertex2i(713,381);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(75,3,4);
    glBegin(GL_TRIANGLES);
    glVertex2i(707,381);
    glVertex2i(819,381);
    glVertex2i(763,409);
    glEnd();
    glPopMatrix();

    glColor3ub(200,200,240);
    drawCircle(762.0f,369.0f,10.0f);
    int scounter1=623;
    for(int i=2; i>=0; i--)
    {
        scounter1+=25;
        windows(scounter1,328);
    }
    int scounter2=623;
    for(int i=2; i>=0; i--)
    {
        scounter2+=25;
        windows(scounter2,304);
    }
    int scounter3=623;
    for(int i=2; i>=0; i--)
    {
        scounter3+=25;
        windows(scounter3,281);
    }
    int scounter4=783;
    for(int i=2; i>=0; i--)
    {
        scounter4+=25;
        windows(scounter4,328);
    }
    int scounter5=783;
    for(int i=2; i>=0; i--)
    {
        scounter5+=25;
        windows(scounter5,304);
    }
    int scounter6=783;
    for(int i=2; i>=0; i--)
    {
        scounter6+=25;
        windows(scounter6,282);
    }
    glPushMatrix();//door
    glColor3ub(72,2,4);
    glBegin(GL_QUADS);
    glVertex2i(728,257);
    glVertex2i(797,257);
    glVertex2i(797,321);
    glVertex2i(728,321);
    glEnd();
    glPopMatrix();

    glPushMatrix();//triangle of the door
    glColor3ub(75,3,4);
    glBegin(GL_TRIANGLES);
    glVertex2i(722,321);
    glVertex2i(803,321);
    glVertex2i(763,347);
    glEnd();
    glPopMatrix();
}
void cloud()
{
    glPushMatrix();
    glColor3f(cdr,cdg,cdb);
    drawCircle(594.0f,586.0f,20.0f);
    drawCircle(572.0f,595.0f,28.0f);
    drawCircle(539.0f,595.0f,35.0f);
    drawCircle(513.0f,575.0f,20.0f);
    glPopMatrix();

    glPushMatrix();
    drawCircle(393.0f,577.0f,20.0f);
    drawCircle(370.0f,585.0f,28.0f);
    drawCircle(339.0f,583.0f,35.0f);
    drawCircle(311.0f,565.0f,20.0f);
    glPopMatrix();

    glPushMatrix();
    drawCircle(193.0f,607.0f,20.0f);
    drawCircle(170.0f,615.0f,28.0f);
    drawCircle(139.0f,613.0f,35.0f);
    drawCircle(111.0f,595.0f,20.0f);
    glPopMatrix();
}
void street()
{
    glPushMatrix();
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(0,148);
    glVertex2i(902,148);
    glVertex2i(902,47);
    glVertex2i(0,47);
    glEnd();
    glPopMatrix();

    for(int i=0; i<120*8; i+=120)
    {
        glPushMatrix();
        glColor3ub(255,255,255);
        glBegin(GL_QUADS);
        glVertex2i(0+i,95);
        glVertex2i(35+i,95);
        glVertex2i(35+i,100);
        glVertex2i(0+i,100);
        glEnd();
        glPopMatrix();
    }
}
void belowStreet()
{
    glPushMatrix();
    glColor3f(gdr,gdg,gdb);
    glBegin(GL_QUADS);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(902.0,0.0,0.0);
    glVertex3f(902.0,47.0,0.0);
    glVertex3f(0.0,47.0,0.0);
    glEnd();
    glPopMatrix();
}
void aboveStreet()
{
    glPushMatrix();
    glColor3f(gdr,gdg,gdb);
    glBegin(GL_QUADS);
    glVertex3f(0.0,157.0,0.0);
    glVertex3f(902.0,157.0,0.0);
    glVertex3f(902.0,258.0,0.0);
    glVertex3f(0.0,258.0,0.0);
    glEnd();
    glPopMatrix();
}
void lamp()
{
    for(int i=0; i<8*115; i+=115)
    {
        glPushMatrix();
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(34+i,158);
        glVertex2i(51+i,158);
        glVertex2i(51+i,160);
        glVertex2i(34+i,160);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(37+i,160);
        glVertex2i(48+i,160);
        glVertex2i(48+i,162);
        glVertex2i(37+i,162);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3f(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(40+i,162);
        glVertex2i(45+i,162);
        glVertex2i(45+i,206);
        glVertex2i(40+i,206);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3ub(0,0,0);
        glBegin(GL_QUADS);
        glVertex2i(38+i,206);
        glVertex2i(48+i,206);
        glVertex2i(48+i,209);
        glVertex2i(38+i,209);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3f(lr,lg,lb);
        drawCircle(43+i,218,9);
        glPopMatrix();

        if(lr==1 && lg==1 && lb==0)//if the lamp is on
        {
            glPushMatrix();
            glColor3f(1,1,0);
            glBegin(GL_TRIANGLE_FAN);
            glVertex2i(48+i,209);
            glVertex2i(38+i,209);
            glVertex2i(0+i,150);
            glVertex2i(80+i,150);
            glEnd();
            glPopMatrix();
        }
    }
}
void car1()
{
    glPushMatrix();
    glColor3ub(34,160,160);
    glTranslatef(c1x,c1y,c1z);
    glBegin(GL_QUADS);
    glVertex2i(311-500,112);
    glVertex2i(414-500,112);
    glVertex2i(414-500,174);
    glVertex2i(311-500,174);
    glEnd();

    glColor3ub(45,194,198);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(414-500,162);
    glVertex2i(445-500,162);
    glVertex2i(473-500,134);
    glVertex2i(473-500,112);
    glVertex2i(414-500,112);
    glEnd();

    glColor3ub(75,89,89);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(417-500,158);
    glVertex2i(444-500,158);
    glVertex2i(463-500,139);
    glVertex2i(463-500,134);
    glVertex2i(417-500,134);
    glEnd();

    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2i(464-500,128);
    glVertex2i(472-500,128);
    glVertex2i(472-500,113);
    glVertex2i(464-500,113);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2i(419-500,126);
    glVertex2i(431-500,126);
    glVertex2i(431-500,129);
    glVertex2i(419-500,129);
    glEnd();

    glColor3ub(48,48,46);
    drawCircle(342-500,116,15);
    glColor3ub(255,255,255);
    drawCircle(342-500,116,10);
    glColor3ub(0,0,0);
    drawCircle(342-500,116,8);

    glColor3ub(48,48,46);
    drawCircle(434-500,116,15);
    glColor3ub(255,255,255);
    drawCircle(434-500,116,10);
    glColor3ub(0,0,0);
    drawCircle(434-500,116,8);
    glPopMatrix();
}
void car2()
{
    glPushMatrix();
    glTranslatef(c2x,c2y,c2z);
    glColor3ub(234,56,78);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(459+500,154-70);
    glVertex2i(466+500,160-70);
    glVertex2i(491+500,160-70);
    glVertex2i(510+500,179-70);
    glVertex2i(568+500,179-70);
    glVertex2i(579+500,162-70);
    glVertex2i(579+500,141-70);
    glVertex2i(459+500,141-70);
    glEnd();

    glColor3ub(155,186,189);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(503+500,169-70);
    glVertex2i(512+500,177-70);
    glVertex2i(525+500,177-70);
    glVertex2i(521+500,163-70);
    glVertex2i(503+500,163-70);
    glEnd();

    glColor3ub(155,186,189);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(526+500,163-70);
    glVertex2i(530+500,177-70);
    glVertex2i(547+500,177-70);
    glVertex2i(547+500,163-70);
    glEnd();

    glColor3ub(155,186,189);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(552+500,163-70);
    glVertex2i(551+500,177-70);
    glVertex2i(561+500,177-70);
    glVertex2i(570+500,163-70);
    glEnd();

    glColor3ub(51,53,50);
    drawCircle(474+500,142-70,10);
    glColor3ub(255,0,0);
    drawCircle(474+500,142-70,8);
    glColor3ub(0,0,0);
    drawCircle(474+500,142-70,7);

    glColor3ub(51,53,50);
    drawCircle(551+500,142-70,10);
    glColor3ub(255,0,0);
    drawCircle(551+500,142-70,8);
    glColor3ub(0,0,0);
    drawCircle(551+500,142-70,7);

    glPopMatrix();
}
void carTranslate(int value)
{
    width+=1.0;
    width2-=1.0;
        c1x+=0.1;
        if(width>10091)
        {
            width=-940;
            c1x=0.0;
        }
        cout << "Width: " << width << endl;
    if(width2>-1614)
    {
        c2x-=0.5;
        if(width2==-1613)
        {
            width2=600;
            c2x=0;
            glutPostRedisplay();
        }
        if(width2<1200)
            glutPostRedisplay();
    }
    cout << "Width 2: " << width2 << endl;
    glutTimerFunc(0,carTranslate,5);
}
void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    sky();
    hospitalLogo(300.0f,400.0f,40.0f);
    hospital();
    building();
    school();
    sun();
    cloud();
    aboveStreet();
    street();
    lamp();
    belowStreet();
    car1();
    car2();
    if(lr==1 && lg==1 && lb==0)//if the lamp is on, display moon
    {
        moon();
    }
    glutSwapBuffers();
}
void keyboard( unsigned char key, int x, int y )
{
    switch( key )
    {
    case 'q' :
    case 'Q' :
        exit( EXIT_SUCCESS );
        break;
    case 'm':
    case 'M':
        carTranslate(0);
        glutPostRedisplay();
        break;
    case 'n':
    case 'N':
        if(sr==0.0f && sg==0.5f && sb==1.0f)//if it was day, it becomes night
        {
            sr=0.0f;//sky becomes black
            sg=0.0f;
            sb=0.0f;
            lr=1;//lamp is on
            lg=1;
            lb=0;
            snr=0;//sun becomes black
            sng=0;
            snb=0;
            cdr=0;//clouds become black
            cdg=0;
            cdb=0;
            gdr=0.2;//grass will be dark green
            gdg=0.5;
            gdb=0.19;
            m1r=1;//moon is yellow
            m1g=1;
            m1b=0;
            m2r=0;
            m2g=0;
            m2b=0;
        }
        else if(sr==0.0f && sg==0.0f&& sb==0.0f)//if it was night
        {
            sr=0.0f;//sky is blue
            sg=0.5f;
            sb=1.0f;
            lr=1;//lamp is off
            lg=1;
            lb=1;
            snr=1;//sun is yellow
            sng=1;
            snb=0;
            cdr=1;//cloud is white
            cdg=1;
            cdb=1;
            gdr=0.0;//grass is green
            gdg=0.4;
            gdb=0.0;
            m1r=0;//moon is blue
            m1g=0.5;
            m1b=1;
            m2r=0;
            m2g=0.5;
            m2b=1;
        }
    }
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);
    glutInitWindowSize (902,684);
    glutInitWindowPosition (250, 50);
    glutCreateWindow ("Street & Buildings");
    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
}
