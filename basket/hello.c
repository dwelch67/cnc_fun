

#include <stdio.h>
#include <math.h>

#define DELTA 20

void doline (
    unsigned int rax,
    unsigned int ray,
    unsigned int rbx,
    unsigned int rby
)
{

    printf("%u %u moveto\n",rax,ray);
    printf("%u %u lineto\n",rbx,rby);
    printf("stroke\n");

}

#define STEP 10
#define WIDE STEP

float aa;
float ab;
float ac;
float ad;

float ba,bb,bc;
float ca,cb,cc;
float da,db,dc,dd;
float ea,eb,ec,ed;

void do_circle ( double fx, double fy, double rad )
{
    fx=fx*STEP;
    fy=fy*STEP;
    rad=rad*STEP;
    printf("%lf %lf moveto\n",fx+rad,fy);
    printf("%lf %lf %lf 0 360 arc\n",fx,fy,rad);
    printf("stroke\n");
}

double degrad = M_PI / 180.0;
double raddeg = 180.0 / M_PI;

void do_arc ( double fx, double fy, double rad, double a, double b )
{
    double sx,sy;

    fx=fx*STEP;
    fy=fy*STEP;
    rad=rad*STEP;

    sx=(cos(a*degrad)*rad)+fx;
    sy=(sin(a*degrad)*rad)+fy;


//fprintf(stderr,"fx fy sx sy %lf %lf %lf %lf\n",fx,fy,sx,sy);


    printf("%lf %lf moveto\n",sx,sy);
    printf("%lf %lf %lf %lf %lf arc\n",fx,fy,rad,a,b);
    printf("stroke\n");
}


float minx,maxx;
float miny,maxy;
void moveto ( float x, float y )
{

    x+=10;
    y+=10;


    if(x<minx) minx=x;
    if(x>maxx) maxx=x;
    if(y<miny) miny=y;
    if(y>maxy) maxy=y;


    printf("%f %f moveto\n",x,y);
}
void lineto ( float x, float y )
{

    x+=10;
    y+=10;

    printf("%f %f lineto\n",x,y);
}
void stroke ( void )
{
    printf("stroke\n");
}
void closepath ( void )
{
    printf("closepath\n");
}
void arc ( float x, float y, float rad, float a, float b )
{

    x+=10;
    y+=10;

    printf("%f %f %f %f %f arc\n",x,y,rad,a,b);
}
void arcn ( float x, float y, float rad, float a, float b )
{

    x+=10;
    y+=10;

    printf("%f %f %f %f %f arcn\n",x,y,rad,a,b);
}


void cut_horizontal ( float x, float y, float xx)
{
    float sx,sy;
    float fx,fy;

    //elements++;
    printf("%%cut_horizontal(%f,%f,%f);\n",x,y,xx);

    sx=x;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    sy=y+1;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=sx+xx;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=y;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=x;
    fx=sx*WIDE;
    lineto(fx,fy);

    stroke();

}

void cut_vertical ( float x, float y, float yy )
{
    float sx,sy;
    float fx,fy;

    //elements++;
    printf("%%cut_vertical(%f,%f,%f);\n",x,y,yy);

    sx=x;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    sy=sy+yy;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=x+1;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=y;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=x;
    fx=sx*WIDE;
    lineto(fx,fy);

    stroke();

}


void cut_square ( int x, int y)
{
    int sx,sy;
    float fx,fy;

    //elements++;
    printf("%%cut_square(%d,%d);\n",x,y);

    sx=x;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    sy=y+3;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=x+3;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=y;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=x;
    fx=sx*WIDE;
    lineto(fx,fy);

    stroke();

}



void cut_arc ( float x, float y, float rad, float a, float b)
{
    float fx,fy;
    float sx,sy;

    //elements++;
    printf("%%cut_arc(%f,%f,%f,%f,%f);\n",x,y,rad,a,b);
    sx=(cos(a*degrad)*rad)+x;
    sy=(sin(a*degrad)*rad)+y;
    sx=sx*WIDE;
    sy=sy*WIDE;
    moveto(sx,sy);
    fx=x*WIDE;
    fy=y*WIDE;
    rad=rad*WIDE;
    arc(fx,fy,rad,a,b);
    rad+=WIDE;
    arcn(fx,fy,rad,b,a);
    lineto(sx,sy);
    stroke();
}


void cut_sarc ( float x, float y, float rad, float a, float b)
{
    float fx,fy;
    float sx,sy;

    //elements++;
    printf("%%cut_sarc(%f,%f,%f,%f,%f);\n",x,y,rad,a,b);
    sx=(cos(a*degrad)*rad)+x;
    sy=(sin(a*degrad)*rad)+y;
    sx=sx*WIDE;
    sy=sy*WIDE;
    moveto(sx,sy);
    fx=x*WIDE;
    fy=y*WIDE;
    rad=rad*WIDE;
    arc(fx,fy,rad,a,b);
    stroke();
}



void cut_special ( void )
{
    float fx,fy;
    float sx,sy;
    float rad;

    printf("%%cut_out();\n");

    //cut_arc(18,25.5,5.5,90,270);
    sx=21;
    sy=25.5;
    fx=sx*WIDE;
    fy=(sy+4.5)*WIDE;
    moveto(fx,fy);

    fy=(sy+1.5)*WIDE;
    lineto(fx,fy);

    fy=sy*WIDE;
    rad=4.5*WIDE;
    arc(fx,fy,rad,90,180-ad);

    fy=(sy+6)*WIDE;
    rad=4.5*WIDE;
    arc(fx,fy,rad,180+ad,270);

    stroke();

    //cut_arc(28.5,42,5.5,0,180);
    //cut_arc(34.5,42,5.5,0,180);
    sx=28.5;
    sy=39;
    fy=sy*WIDE;
    fx=(sx+4.5)*WIDE;
    moveto(fx,fy);

    fx=(sx+1.5)*WIDE;
    lineto(fx,fy);

    fx=sx*WIDE;
    rad=4.5*WIDE;
    arc(fx,fy,rad,0,90-ad);

    fx=(sx+6)*WIDE;
    rad=4.5*WIDE;
    arc(fx,fy,rad,90+ad,180);

    stroke();



    //cut_arc(45,25.5,5.5,270,90);
    //cut_arc(45,31.5,5.5,270,90);
    sx=42;
    sy=31.5;
    fx=sx*WIDE;
    fy=(sy-4.5)*WIDE;
    moveto(fx,fy);

    fy=(sy-1.5)*WIDE;
    lineto(fx,fy);

    fy=sy*WIDE;
    rad=4.5*WIDE;
    arc(fx,fy,rad,270,0-ad);

    fy=(sy-6)*WIDE;
    rad=4.5*WIDE;
    arc(fx,fy,rad,0+ad,90);

    stroke();

    //cut_arc(28.5,15,5.5,180,0);
    //cut_arc(34.5,15,5.5,180,0);
    sx=34.5;
    sy=18;
    fy=sy*WIDE;
    fx=(sx-4.5)*WIDE;
    moveto(fx,fy);

    fx=(sx-1.5)*WIDE;
    lineto(fx,fy);

    fx=sx*WIDE;
    rad=4.5*WIDE;
    arc(fx,fy,rad,180,270-ad);

    fx=(sx-6)*WIDE;
    rad=4.5*WIDE;
    arc(fx,fy,rad,270+ad,0);

    stroke();












    //cut_arc(18,25.5,5.5,90,270);
    //cut_arc(18,31.5,5.5,90,270);

    sx=21;
    sy=25.5;
    fx=sx*WIDE;
    fy=(sy-1.5)*WIDE;
    moveto(fx,fy);

    fy=(sy+6)*WIDE;
    rad=7.5*WIDE;
    arcn(fx,fy,rad,270,270-cc);

    fy=(sy)*WIDE;
    rad=4.5*WIDE;
    arc(fx,fy,rad,270-ba,270);

    closepath();
    stroke();

    fx=sx*WIDE;
    fy=(sy+7.5)*WIDE;
    moveto(fx,fy);

    fy=(sy+0)*WIDE;
    rad=7.5*WIDE;
    arc(fx,fy,rad,90,90+cc);

    fy=(sy+6)*WIDE;
    rad=4.5*WIDE;
    arcn(fx,fy,rad,90+ba,90);

    closepath();
    stroke();




    //cut_arc(28.5,42,5.5,0,180);
    //cut_arc(34.5,42,5.5,0,180);



    sx=28.5;
    sy=39;
    fy=sy*WIDE;
    fx=(sx-1.5)*WIDE;
    moveto(fx,fy);

    fx=(sx+6)*WIDE;
    rad=7.5*WIDE;
    arcn(fx,fy,rad,180,180-cc);

    fx=(sx)*WIDE;
    rad=4.5*WIDE;
    arc(fx,fy,rad,180-ba,180);

    closepath();
    stroke();

    fy=sy*WIDE;
    fx=(sx+7.5)*WIDE;
    moveto(fx,fy);

    fx=(sx+0)*WIDE;
    rad=7.5*WIDE;
    arc(fx,fy,rad,0,0+cc);

    fx=(sx+6)*WIDE;
    rad=4.5*WIDE;
    arcn(fx,fy,rad,0+ba,0);

    closepath();
    stroke();














    //cut_arc(45,25.5,5.5,270,90);
    //cut_arc(45,31.5,5.5,270,90);



    sx=42;
    sy=31.5;
    fx=sx*WIDE;
    fy=(sy+1.5)*WIDE;
    moveto(fx,fy);

    fy=(sy-6)*WIDE;
    rad=7.5*WIDE;
    arcn(fx,fy,rad,90,90-cc);

    fy=(sy)*WIDE;
    rad=4.5*WIDE;
    arc(fx,fy,rad,90-ba,90);

    closepath();
    stroke();

    fx=sx*WIDE;
    fy=(sy-7.5)*WIDE;
    moveto(fx,fy);

    fy=(sy+0)*WIDE;
    rad=7.5*WIDE;
    arc(fx,fy,rad,270,270+cc);

    fy=(sy-6)*WIDE;
    rad=4.5*WIDE;
    arcn(fx,fy,rad,270+ba,270);

    closepath();
    stroke();



    //cut_arc(28.5,15,5.5,180,0);
    //cut_arc(34.5,15,5.5,180,0);





    sx=34.5;
    sy=18;
    fy=sy*WIDE;
    fx=(sx+1.5)*WIDE;
    moveto(fx,fy);

    fx=(sx-6)*WIDE;
    rad=7.5*WIDE;
    arcn(fx,fy,rad,0,0-cc);

    fx=(sx)*WIDE;
    rad=4.5*WIDE;
    arc(fx,fy,rad,0-ba,0);

    closepath();
    stroke();

    fy=sy*WIDE;
    fx=(sx-7.5)*WIDE;
    moveto(fx,fy);

    fx=(sx+0)*WIDE;
    rad=7.5*WIDE;
    arc(fx,fy,rad,180,180+cc);

    fx=(sx-6)*WIDE;
    rad=4.5*WIDE;
    arcn(fx,fy,rad,180+ba,180);

    closepath();
    stroke();







    //cut_arc(21,25.5,5.5,90,270);



    sx=21;
    sy=25.5;
    fx=(sx)*WIDE;
    fy=(sy+5.5)*WIDE;
    moveto(fx,fy);

    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=5.5*WIDE;
    arc(fx,fy,rad,90,180-dc);

    sx=21;
    sy=25.5+6;
    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=4.5*WIDE;
    arcn(fx,fy,rad,270-da,270-db);

    sx=21;
    sy=25.5;
    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=6.5*WIDE;
    arcn(fx,fy,rad,90+dd,90);

    closepath();
    stroke();

    sx=21;
    sy=25.5;
    fy=(sy-5.5)*WIDE;
    fx=sx*WIDE;
    moveto(fx,fy);

    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=5.5*WIDE;
    arcn(fx,fy,rad,270,90+ec);

    fx=(sx)*WIDE;
    fy=(sy+6)*WIDE;
    rad=7.5*WIDE;
    arcn(fx,fy,rad,270-ea,270-eb);

    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=6.5*WIDE;
    arc(fx,fy,rad,90+ed,270);

    closepath();
    stroke();



    //cut_arc(28.5,39,5.5,0,180);

    sx=28.5;
    sy=39;
    fx=(sx+5.5)*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=5.5*WIDE;
    arc(fx,fy,rad,0,dc);

    sx=28.5+6;
    sy=39;
    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=4.5*WIDE;
    arcn(fx,fy,rad,180-da,180-db);

    sx=28.5;
    sy=39;
    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=6.5*WIDE;
    arcn(fx,fy,rad,dd,0);

    closepath();
    stroke();


    sx=28.5;
    sy=39;
    fx=(sx-5.5)*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=5.5*WIDE;
    arcn(fx,fy,rad,180,ec);

    fx=(sx+6)*WIDE;
    fy=sy*WIDE;
    rad=7.5*WIDE;
    arcn(fx,fy,rad,180-ea,180-eb);

    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=6.5*WIDE;
    arc(fx,fy,rad,ed,180);

    closepath();
    stroke();


    //cut_arc(42,31.5,5.5,270,90);


    sx=42;
    sy=31.5;
    fx=(sx)*WIDE;
    fy=(sy-5.5)*WIDE;
    moveto(fx,fy);

    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=5.5*WIDE;
    arc(fx,fy,rad,270,360-dc);

    sx=42;
    sy=31.5-6;
    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=4.5*WIDE;
    arcn(fx,fy,rad,90-da,90-db);

    sx=42;
    sy=31.5;
    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=6.5*WIDE;
    arcn(fx,fy,rad,270+dd,270);

    closepath();
    stroke();

    sx=42;
    sy=31.5;
    fy=(sy+5.5)*WIDE;
    fx=sx*WIDE;
    moveto(fx,fy);

    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=5.5*WIDE;
    arcn(fx,fy,rad,90,270+ec);

    fx=(sx)*WIDE;
    fy=(sy-6)*WIDE;
    rad=7.5*WIDE;
    arcn(fx,fy,rad,90-ea,90-eb);

    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=6.5*WIDE;
    arc(fx,fy,rad,270+ed,90);

    closepath();
    stroke();









    //cut_arc(34.5,18,5.5,180,0);


    sx=34.5;
    sy=18;
    fx=(sx-5.5)*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=5.5*WIDE;
    arc(fx,fy,rad,180,270-dc);

    sx=34.5-6;
    sy=18;
    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=4.5*WIDE;
    arcn(fx,fy,rad,0-da,0-db);

    sx=34.5;
    sy=18;
    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=6.5*WIDE;
    arcn(fx,fy,rad,180+dd,180);

    closepath();
    stroke();


    sx=34.5;
    sy=18;
    fx=(sx+5.5)*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=5.5*WIDE;
    arcn(fx,fy,rad,0,180+ec);

    fx=(sx-6)*WIDE;
    fy=sy*WIDE;
    rad=7.5*WIDE;
    arcn(fx,fy,rad,0-ea,0-eb);

    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=6.5*WIDE;
    arc(fx,fy,rad,180+ed,0);

    closepath();

    stroke();



























}



void cut_out ( void )
{
    float fx,fy;
    float sx,sy;
    float rad;

    printf("%%cut_out();\n");

    rad=7.5*WIDE;

    sx=21;
    sy=18;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);



    sy=sy+7.5;
    fy=sy*WIDE;
    arcn(fx,fy,rad,270,180-aa);

    sy=sy+6;
    fy=sy*WIDE;
    arcn(fx,fy,rad,180+aa,90);

    sy=sy+7.5;
    fy=sy*WIDE;




    sx=sx+7.5;
    fx=sx*WIDE;
    arcn(fx,fy,rad,180,90-aa);

    sx=sx+6;
    fx=sx*WIDE;
    arcn(fx,fy,rad,90+aa,0);

    sx=sx+7.5;
    fx=sx*WIDE;
    lineto(fx,fy);







    sy=sy-7.5;
    fy=sy*WIDE;
    arcn(fx,fy,rad,90,0-aa);

    sy=sy-6;
    fy=sy*WIDE;
    arcn(fx,fy,rad,0+aa,270);

    sy=sy-7.5;
    fy=sy*WIDE;





    sx=sx-7.5;
    fx=sx*WIDE;
    arcn(fx,fy,rad,0,270-aa);

    sx=sx-6;
    fx=sx*WIDE;
    arcn(fx,fy,rad,270+aa,180);

    sx=sx-7.5;
    fx=sx*WIDE;
    lineto(fx,fy);










    stroke();
}


#define XWIDE 20

void cut_math ( void )
{
    float fx,fy;
    float sx,sy,sr;
    float rad;

    float aa;


    sy=28;
    sx=10;

    fx=(sx+0)*XWIDE;
    fy=(sy-1)*XWIDE;
    moveto(fx,fy);
    fy=(sy+1)*XWIDE;
    lineto(fx,fy);
    stroke();

    fx=(sx-1)*XWIDE;
    fy=(sy+0)*XWIDE;
    moveto(fx,fy);
    fx=(sx+1)*XWIDE;
    lineto(fx,fy);
    stroke();



    sr=7.5;
    fx=(sx+sr)*XWIDE;
    fy=(sy)*XWIDE;
    moveto(fx,fy);
    fx=sx*XWIDE;
    fy=sy*XWIDE;
    rad=sr*XWIDE;
    arc(fx,fy,rad,0,180);
    stroke();

    sr=6.5;
    fx=(sx+sr)*XWIDE;
    fy=(sy)*XWIDE;
    moveto(fx,fy);
    fx=sx*XWIDE;
    fy=sy*XWIDE;
    rad=sr*XWIDE;
    arc(fx,fy,rad,0,180);
    stroke();

    sr=5.5;
    fx=(sx+sr)*XWIDE;
    fy=(sy)*XWIDE;
    moveto(fx,fy);
    fx=sx*XWIDE;
    fy=sy*XWIDE;
    rad=sr*XWIDE;
    arc(fx,fy,rad,0,180);
    stroke();

    sr=4.5;
    fx=(sx+sr)*XWIDE;
    fy=(sy)*XWIDE;
    moveto(fx,fy);
    fx=sx*XWIDE;
    fy=sy*XWIDE;
    rad=sr*XWIDE;
    arc(fx,fy,rad,0,180);
    stroke();


    //sy=55;
    //sx=20;
    sx+=6;

    fx=(sx+0)*XWIDE;
    fy=(sy-1)*XWIDE;
    moveto(fx,fy);
    fy=(sy+1)*XWIDE;
    lineto(fx,fy);
    stroke();

    fx=(sx-1)*XWIDE;
    fy=(sy+0)*XWIDE;
    moveto(fx,fy);
    fx=(sx+1)*XWIDE;
    lineto(fx,fy);
    stroke();



    sr=7.5;
    fx=(sx+sr)*XWIDE;
    fy=(sy)*XWIDE;
    moveto(fx,fy);
    fx=sx*XWIDE;
    fy=sy*XWIDE;
    rad=sr*XWIDE;
    arc(fx,fy,rad,0,180);
    stroke();

    sr=6.5;
    fx=(sx+sr)*XWIDE;
    fy=(sy)*XWIDE;
    moveto(fx,fy);
    fx=sx*XWIDE;
    fy=sy*XWIDE;
    rad=sr*XWIDE;
    arc(fx,fy,rad,0,180);
    stroke();

    sr=5.5;
    fx=(sx+sr)*XWIDE;
    fy=(sy)*XWIDE;
    moveto(fx,fy);
    fx=sx*XWIDE;
    fy=sy*XWIDE;
    rad=sr*XWIDE;
    arc(fx,fy,rad,0,180);
    stroke();

    sr=4.5;
    fx=(sx+sr)*XWIDE;
    fy=(sy)*XWIDE;
    moveto(fx,fy);
    fx=sx*XWIDE;
    fy=sy*XWIDE;
    rad=sr*XWIDE;
    arc(fx,fy,rad,0,180);
    stroke();





}



int main ( void )
{
    unsigned int ra;
    unsigned int rax,ray;
    unsigned int rbx,rby;

    unsigned int rb;
    unsigned int flag;

    double fx,fy;
    double zz;
    double xx;
    double rr;
    double sx,sy;
    double bx,by;


//c1 = (0,0)
//c2 = (0,6)
//r1 = 7.5
//r2 = 7.5
//Points of intersection:
// (3.00000000000000,6.87386354243376)
    aa=acos(6.87386354243376/7.5);
    aa=raddeg*aa;
    fprintf(stderr,"aa %f\n",aa);

//r1 = 6.5
//r2 = 6.5
//Points of intersection:
// (3.00000000000000,5.76628129733540)
    ab=acos(5.76628129733540/6.5);
    ab=raddeg*ab;
    fprintf(stderr,"ab %f\n",ab);

//r1 = 5.5
//r2 = 5.5
//Points of intersection:
 //(4.60977222864644,3.00000000000000)
    ac=acos(4.60977222864644/5.5);
    ac=raddeg*ac;
    fprintf(stderr,"ac %f\n",ac);

//r1 = 4.5
//r2 = 4.5
//Points of intersection:
 //(3.35410196624968,3.00000000000000)
    ad=acos(3.35410196624968/4.5);
    ad=raddeg*ad;
    fprintf(stderr,"ad %f\n",ad);

//aa 23.578178
//ab 27.486425
//ac 33.055733
//ad 41.810318

//c1 = (0,0)
//c2 = (6,0)
//r1 = 4.5
//r2 = 7.5
//Points of intersection:
 //(0,-4.50000000000000)
 //(0,4.50000000000000)
    ba = 90;
    fprintf(stderr,"ba %f\n",ba);


//c1 = (0,0)
//c2 = (6,0)
//r1 = 5.5
//r2 = 7.5
//Points of intersection:
 //(0.833333333333332,-5.43650214343336)
 //(0.833333333333332,5.43650214343336)

    bb=acos(0.833333333333332/5.5);
    bb=raddeg*bb;
    fprintf(stderr,"bb %f\n",bb);



//c1 = (0,0)
//c2 = (6,0)
//r1 = 6.5
//r2 = 7.5
//Points of intersection:
 //(1.83333333333333,-6.23609564462324)
 //(1.83333333333333,6.23609564462324)

    bc=acos(1.833333333333332/6.5);
    bc=raddeg*bc;
    fprintf(stderr,"bc %f\n",bc);


//ba 90.000000
//bb 81.285255
//bc 73.617332


//c1 = (0,0)
//c2 = (6,0)
//r1 = 7.5
//r2 = 6.5
 //(4.16666666666667,6.23609564462324)

    ca=acos(4.16666666666667/7.5);
    ca=raddeg*ca;
    fprintf(stderr,"ca %f\n",ca);


//c1 = (0,0)
//c2 = (6,0)
//r1 = 7.5
//r2 = 5.5
 //(5.16666666666667,5.43650214343336)

    cb=acos(5.16666666666667/7.5);
    cb=raddeg*cb;
    fprintf(stderr,"cb %f\n",cb);


//c1 = (0,0)
//c2 = (6,0)
//r1 = 7.5
//r2 = 4.5


 //(6.00000000000000,4.50000000000000)


    cc=acos(6/7.5);
    cc=raddeg*cc;
    fprintf(stderr,"cc %f\n",cc);


//ca 56.251011
//cb 46.457783
//cc 36.869896

//c1 = (0,0)
//c2 = (6,0)
//r1 = 5.5
//r2 = 4.5
 //(3.83333333333333,3.94405318873308)

    dc=acos(3.83333333333333/5.5);
    dc=raddeg*dc;
    fprintf(stderr,"dc %f\n",dc);

    da=acos((6-3.83333333333333)/4.5);
    da=raddeg*da;
    fprintf(stderr,"da %f\n",da);




//c1 = (0,0)
//c2 = (6,0)
//r1 = 6.5
//r2 = 4.5
 //(4.83333333333333,4.34613493680177)

    dd=acos(4.83333333333333/6.5);
    dd=raddeg*dd;
    fprintf(stderr,"dd %f\n",dd);

    db=acos((6-4.83333333333333)/4.5);
    db=raddeg*db;
    fprintf(stderr,"db %f\n",db);


//c1 = (0,0)
//c2 = (6,0)
//r1 = 5.5
//r2 = 7.5

 //(0.833333333333332,5.43650214343336)

    ec=acos(0.833333333333332/5.5);
    ec=raddeg*ec;
    fprintf(stderr,"ec %f\n",ec);

    ea=acos((6-0.83333333333333)/7.5);
    ea=raddeg*ea;
    fprintf(stderr,"ea %f\n",ea);


//c1 = (0,0)
//c2 = (6,0)
//r1 = 6.5
//r2 = 7.5

 //(1.83333333333333,6.23609564462324)

    ed=acos(1.83333333333333/6.5);
    ed=raddeg*ed;
    fprintf(stderr,"ed %f\n",ed);

    eb=acos((6-1.83333333333333)/7.5);
    eb=raddeg*eb;
    fprintf(stderr,"eb %f\n",eb);












    printf("%%!\n");
    printf("0.0 setgray\n");
    printf("0.1 setlinewidth\n");

    if(0)
    {
        for(rb=STEP;rb<600;rb+=STEP)
        for(ra=STEP;ra<600;ra+=STEP)
        {
            //horizontal
            flag=1;

            if(ra==(STEP*(28+1))) flag++;
            if(ra==(STEP*(29+1))) flag++;
            if(ra==(STEP*(30+1))) flag++;
            if(ra==(STEP*(31+1))) flag++;


            if(flag)
            {
                rax=STEP;
                rbx=rb;
                ray=ra;
                rby=ra;
                doline(rax,ray,rbx,rby);
            }

            //vertical
            flag=1;

            if(ra==(STEP*(28+1))) flag++;
            if(ra==(STEP*(29+1))) flag++;
            if(ra==(STEP*(30+1))) flag++;
            if(ra==(STEP*(31+1))) flag++;
            if(flag)
            {
                rax=ra;
                rbx=ra;
                ray=STEP;
                rby=rb;
                doline(rax,ray,rbx,rby);
            }

        }
    }

if(0)
{

    printf("/Courier-Bold findfont 8 scalefont setfont\n");
    for(ra=0;ra<57;ra++)
    {
    printf("%u %u moveto (%u) show\n",(ra*STEP)+STEP,STEP+3,ra);
    if(ra)
    printf("%u %u moveto (%u) show\n",STEP,(ra*STEP)+STEP+3,ra);
    }
}


    cut_vertical(22,21,9);
    cut_vertical(22,33,6);

    cut_vertical(34,21,9);
    cut_vertical(34,33,6);

    cut_vertical(28,18,6);
    cut_vertical(28,27,9);

    cut_vertical(40,18,6);
    cut_vertical(40,27,9);

    cut_horizontal(21,19,6);
    cut_horizontal(30,19,9);

    cut_horizontal(21,31,6);
    cut_horizontal(30,31,9);

    cut_horizontal(24,25,9);
    cut_horizontal(36,25,6);

    cut_horizontal(24,37,9);
    cut_horizontal(36,37,6);

    cut_square(24,21);
    cut_square(24,27);
    cut_square(24,33);

    cut_square(30,21);
    cut_square(30,27);
    cut_square(30,33);

    cut_square(36,21);
    cut_square(36,27);
    cut_square(36,33);


    //cut_arc(21,25.5,5.5,90,270);
    cut_arc(21,31.5,5.5,90,270);

    //cut_arc(28.5,39,5.5,0,180);
    cut_arc(34.5,39,5.5,0,180);

    cut_arc(42,25.5,5.5,270,90);
    //cut_arc(42,31.5,5.5,270,90);

    cut_arc(28.5,18,5.5,180,0);
    //cut_arc(34.5,18,5.5,180,0);




    cut_special();

    cut_out();

    //printf("1.0 setlinewidth\n");
    //cut_math();

    printf("showpage\n");
    return(0);
}
