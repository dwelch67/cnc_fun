

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


    rad=1.5*WIDE;


    sx=7;
    sy=10;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);
	sy=sy+1.5;
    fy=sy*WIDE;
    arcn(fx,fy,rad,270,90);
	closepath();
	stroke();


    sx=7;
    sy=22;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);
	sy=sy+1.5;
    fy=sy*WIDE;
    arcn(fx,fy,rad,270,90);
	closepath();
	stroke();








    sx=10;
    sy=28;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);
	sx=sx+1.5;
    fx=sx*WIDE;
    arcn(fx,fy,rad,180,0);
	closepath();
	stroke();

    sx=22;
    sy=28;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);
	sx=sx+1.5;
    fx=sx*WIDE;
    arcn(fx,fy,rad,180,0);
	closepath();
	stroke();





    sx=28;
    sy=10;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);
	sy=sy+1.5;
    fy=sy*WIDE;
    arc(fx,fy,rad,270,90);
	closepath();
	stroke();


    sx=28;
    sy=22;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);
	sy=sy+1.5;
    fy=sy*WIDE;
    arc(fx,fy,rad,270,90);
	closepath();
	stroke();






    sx=10;
    sy=7;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);
	sx=sx+1.5;
    fx=sx*WIDE;
    arc(fx,fy,rad,180,0);
	closepath();
	stroke();

    sx=22;
    sy=7;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);
	sx=sx+1.5;
    fx=sx*WIDE;
    arc(fx,fy,rad,180,0);
	closepath();
	stroke();















}



void cut_out ( void )
{
    float fx,fy;
    float sx,sy;
    float rad;

    printf("%%cut_out();\n");

    rad=4.5*WIDE;

    sx=7;
    sy=7;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);



    sy=sy+4.5;
    fy=sy*WIDE;
    arcn(fx,fy,rad,270,90);

    sy=sy+4.5;
    sy=sy+3.0;
    sy=sy+4.5;
    fy=sy*WIDE;
    arcn(fx,fy,rad,270,90);

    sy=sy+4.5;
    fy=sy*WIDE;

    sx=sx+4.5;
    fx=sx*WIDE;
    arcn(fx,fy,rad,180,0);

    sx=sx+4.5;
    sx=sx+3.0;
    sx=sx+4.5;
    fx=sx*WIDE;
    arcn(fx,fy,rad,180,0);

    sx=sx+4.5;
    fx=sx*WIDE;



    sy=sy-4.5;
    fy=sy*WIDE;
    arcn(fx,fy,rad,90,270);

    sy=sy-4.5;
    sy=sy-3.0;
    sy=sy-4.5;
    fy=sy*WIDE;
    arcn(fx,fy,rad,90,270);


    sy=sy-4.5;
    fy=sy*WIDE;


    sx=sx-4.5;
    fx=sx*WIDE;
    arcn(fx,fy,rad,0,180);

    sx=sx-4.5;
    sx=sx-3.0;
    sx=sx-4.5;
    fx=sx*WIDE;
    arcn(fx,fy,rad,0,180);




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


    cut_vertical(8,7,6);
    cut_vertical(8,16,9);
	
    cut_vertical(20,7,6);
    cut_vertical(20,16,9);

    cut_vertical(14,10,9);
    cut_vertical(14,22,6);

    cut_vertical(26,10,9);
    cut_vertical(26,22,6);


    cut_horizontal(10,8,9);
    cut_horizontal(22,8,6);

    cut_horizontal(10,20,9);
    cut_horizontal(22,20,6);

    cut_horizontal( 7,14,6);
    cut_horizontal(16,14,9);

    cut_horizontal( 7,26,6);
    cut_horizontal(16,26,9);








    cut_square(10,10);
    cut_square(16,10);
    cut_square(22,10);

    cut_square(10,16);
    cut_square(16,16);
    cut_square(22,16);

    cut_square(10,22);
    cut_square(16,22);
    cut_square(22,22);


    ////cut_arc(21,25.5,5.5,90,270);
    cut_arc(7,11.5,2.5,90,270);
    cut_arc(7,23.5,2.5,90,270);

    ////cut_arc(28.5,39,5.5,0,180);
    //cut_arc(34.5,39,5.5,0,180);
    cut_arc(11.5,28,2.5,0,180);
    cut_arc(23.5,28,2.5,0,180);

    //cut_arc(42,25.5,5.5,270,90);
    cut_arc(28,11.5,2.5,270,90);
    cut_arc(28,23.5,2.5,270,90);

    //cut_arc(28.5,18,5.5,180,0);
    cut_arc(11.5,7,2.5,180,0);
    cut_arc(23.5,7,2.5,180,0);




    cut_special();

    cut_out();

    //printf("1.0 setlinewidth\n");
    //cut_math();

    printf("showpage\n");
    return(0);
}
