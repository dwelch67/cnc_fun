

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define JUMP 100
#define STEP 80

#define JUMP0 (JUMP-10)
#define STEP0 (STEP-20)

#define JUMP1 (JUMP0-10)
#define STEP1 (STEP0-20)

#define JUMP2 (JUMP1-10)
#define STEP2 (STEP1-20)


#define MULT 1


double degrad = M_PI / 180.0;
double raddeg = 180.0 / M_PI;

void do_line ( float ax, float ay, float bx,float by )
{
    //ax=ax+1;
    //ay=ay+1;
    //bx=bx+1;
    //by=by+1;


    ax=ax*MULT;
    ay=ay*MULT;
    bx=bx*MULT;
    by=by*MULT;

    printf("%f %f moveto\n",ax,ay);
    printf("%f %f lineto\n",bx,by);
    printf("stroke\n");
}


void moveto ( float ax, float ay )
{
    //ax=ax+1;
    //ay=ay+1;

    ax=ax*MULT;
    ay=ay*MULT;

    printf("%f %f moveto\n",ax,ay);
}


void lineto ( float ax, float ay )
{
    //ax=ax+1;
    //ay=ay+1;

    ax=ax*MULT;
    ay=ay*MULT;

    printf("%f %f lineto\n",ax,ay);
}

void closepath ( void )
{
    printf("closepath\n");
}


void stroke ( void )
{
    printf("stroke\n");
}

void arc ( float fx, float fy, float rad, float a, float b )
{
    printf("%f %f %f %f %f arc\n",fx,fy,rad,a,b);
}



void do_circle ( float fx, float fy, float rad )
{
    //fx=fx+1;
    //fy=fy+1;


    fx=fx*STEP;
    fy=fy*STEP;

    rad=rad*STEP;
    printf("%f %f moveto\n",fx+rad,fy);
    printf("%f %f %f 0 360 arc\n",fx,fy,rad);
    printf("stroke\n");
}

void do_arc ( float fx, float fy, float rad, float a, float b )
{
    float sx,sy;

    fx=fx+1;
    fy=fy+1;

    //fx=fx*STEP;
    //fy=fy*STEP;
    //rad=rad*STEP;

    sx=(cos(a*degrad)*rad)+fx;
    sy=(sin(a*degrad)*rad)+fy;


//fprintf(stderr,"fx fy sx sy %f %f %f %f\n",fx,fy,sx,sy);


    printf("%f %f moveto\n",sx,sy);
    printf("%f %f %f %f %f arc\n",fx,fy,rad,a,b);
    printf("stroke\n");
}




int main ( void )
{
    unsigned int ra;
    unsigned int rb;

    float fx,fy;
    float sx,sy;
    float ax,ay;
    float bx,by;
    float cx,cy;
    float d;
    float xc,yc;
    float theangle;
    float thestep;
    float angle;
    float step;
    float jump;
    float rad;

    printf("%%!\n");
    //printf("<< /PageSize [%u %u] >> setpagedevice\n",ra,ra);
    printf("0.0 setgray\n");
    printf("4 setlinewidth\n");

    ax=100;
    ay=150;
    cx=100;
    cy=50;

    moveto(100,50);
    lineto(100,150);
    lineto(200,150);
    lineto(200,50);
    closepath();
    stroke();

    by=100;
    bx=120;
    for(ra=0;ra<5;ra++)
    {
        //from wikipedia.
        d=((ax*(by-cy))+(bx*(cy-ay))+(cx*(ay-by)))*2.0;
        xc = ((ax * ax + ay * ay) * (by - cy) + (bx * bx + by * by) * (cy - ay) + (cx * cx + cy * cy) * (ay - by)) / d;
        yc = ((ax * ax + ay * ay) * (cx - bx) + (bx * bx + by * by) * (ax - cx) + (cx * cx + cy * cy) * (bx - ax)) / d;
        fprintf(stderr,"%f, %f\n",xc,yc);

        rad=bx-xc;

        sx=asin(50/rad);
        sx=raddeg*sx;
        moveto(cx,cy);
        arc(xc,yc,rad,0-sx,0+sx);
        //arc(xc,yc,rad,0,360);
        stroke();

        moveto(ax+100,ay);
        arc(200+(100-xc),yc,rad,180-sx,180+sx);
        //arc(200+(100-xc),yc,rad,0,360);
        stroke();

        bx+=20;
    }

    printf("showpage\n");


    return(0);
}
