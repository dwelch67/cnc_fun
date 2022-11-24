
#include <stdio.h>
#include <math.h>

#define ANGLED 1

//Radians = Degrees × (π/180)

//double degrad = 1.0 / 180.0 * M_PI;
double rangle = (45) / 180.0 * M_PI;

#define WIDE 10.0F

#define MIDDLE 10.5F
#define ADJUST 12

float minx,maxx;
float miny,maxy;
void moveto ( float x, float y )
{

if(ANGLED)
{
    double rx,ry;
    x-=MIDDLE*WIDE;
    y-=MIDDLE*WIDE;
    rx=(x*cos(rangle))-(y*sin(rangle));
    ry=(x*sin(rangle))+(y*cos(rangle));
    x=rx;
    y=ry;

    x+=ADJUST*WIDE;
    y+=ADJUST*WIDE;

}
else
{
    x+=10;
    y+=10;
}



    if(x<minx) minx=x;
    if(x>maxx) maxx=x;
    if(y<miny) miny=y;
    if(y>maxy) maxy=y;


    printf("%f %f moveto\n",x,y);
}
void lineto ( float x, float y )
{

if(ANGLED)
{
    double rx,ry;
    x-=MIDDLE*WIDE;
    y-=MIDDLE*WIDE;
    rx=(x*cos(rangle))-(y*sin(rangle));
    ry=(x*sin(rangle))+(y*cos(rangle));
    x=rx;
    y=ry;

    x+=ADJUST*WIDE;
    y+=ADJUST*WIDE;
}
else
{
    x+=10;
    y+=10;
}


    if(x<minx) minx=x;
    if(x>maxx) maxx=x;
    if(y<miny) miny=y;
    if(y>maxy) maxy=y;

    printf("%f %f lineto\n",x,y);
}
void stroke ( void )
{
    printf("stroke\n");
}
void arc ( float x, float y, float r, float a, float b )
{

if(ANGLED)
{
    double rx,ry;
    x-=MIDDLE*WIDE;
    y-=MIDDLE*WIDE;
    rx=(x*cos(rangle))-(y*sin(rangle));
    ry=(x*sin(rangle))+(y*cos(rangle));
    x=rx;
    y=ry;

    x+=ADJUST*WIDE;
    y+=ADJUST*WIDE;

    a+=45;
    b+=45;

    
}
else
{
    x+=10;
    y+=10;
}

    printf("%f %f %f %f %f arc\n",x,y,r,a,b);
}

void arcn ( float x, float y, float r, float a, float b )
{
if(ANGLED)
{
    double rx,ry;
    x-=MIDDLE*WIDE;
    y-=MIDDLE*WIDE;
    rx=(x*cos(rangle))-(y*sin(rangle));
    ry=(x*sin(rangle))+(y*cos(rangle));
    x=rx;
    y=ry;

    x+=ADJUST*WIDE;
    y+=ADJUST*WIDE;
    
    a+=45;
    b+=45;
    
    
}
else
{
    x+=10;
    y+=10;
}

    printf("%f %f %f %f %f arcn\n",x,y,r,a,b);
}


void cut_square ( int x, int y )
{
    float fx,fy;

    fx=x*WIDE;
    fy=y*WIDE;
    moveto(fx,fy);
    x+=3;
    fx=x*WIDE;
    lineto(fx,fy);
    y+=3;
    fy=y*WIDE;
    lineto(fx,fy);
    x-=3;
    fx=x*WIDE;
    lineto(fx,fy);
    y-=3;
    fy=y*WIDE;
    lineto(fx,fy);
    stroke();

}

void cut_square_l ( int x, int y )
{
    float fx,fy;
    float rad;

    printf("%%cut_square_l(%d,%d);\n",x,y);

    fx=(x+3)*WIDE;
    fy=y*WIDE;
    moveto(fx,fy);
    fy=(y+3)*WIDE;
    lineto(fx,fy);

    fx=(x+3)*WIDE;
    fy=(y+1.5F)*WIDE;
    rad=1.5F*WIDE;
    arc(fx,fy,rad,90,270);
    fx=(x+3)*WIDE;
    fy=(y)*WIDE;
    lineto(fx,fy);
    stroke();
}

void cut_square_r ( int x, int y )
{
    float fx,fy;
    float rad;

    printf("%%cut_square_r(%d,%d);\n",x,y);

    fx=(x)*WIDE;
    fy=y*WIDE;
    moveto(fx,fy);

    fy=(y+3)*WIDE;
    lineto(fx,fy);

    fx=(x)*WIDE;
    fy=(y+1.5F)*WIDE;
    rad=1.5F*WIDE;
    arc(fx,fy,rad,270,90);
    stroke();
}


void cut_square_t ( int x, int y )
{
    float fx,fy;
    float rad;

    printf("%%cut_square_t(%d,%d);\n",x,y);

    fx=(x+3)*WIDE;
    fy=(y)*WIDE;
    moveto(fx,fy);

    fy=(y)*WIDE;
    lineto(fx,fy);

    fx=(x+1.5F)*WIDE;
    fy=(y)*WIDE;
    rad=1.5F*WIDE;
    arcn(fx,fy,rad,180,0);
    stroke();
}


void cut_square_b ( int x, int y )
{
    float fx,fy;
    float rad;

    printf("%%cut_square_b(%d,%d);\n",x,y);

    fx=(x)*WIDE;
    fy=(y+3)*WIDE;
    moveto(fx,fy);

    fx=(x+3)*WIDE;
    lineto(fx,fy);

    fx=(x+1.5F)*WIDE;
    fy=(y+3)*WIDE;
    rad=1.5F*WIDE;
    arcn(fx,fy,rad,0,180);
    stroke();
}





//void cut_bl ( int x, int y, int yy, int xx )
void cut_bl ( int x, int y )
{
    int sx,sy;
    float fx,fy;
    int xx,yy;
//    cut_bl ( 7,7,11,17);
    xx=x+10;
    yy=y+4;
    
    sx=x;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    sy=yy+1;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx+=1;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=y+1;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=xx+1;
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


//void cut_tl ( int x, int y, int yy, int xx )
void cut_tl ( int x, int y )
{
    int sx,sy;
    float fx,fy;
    int xx,yy;

    yy=y-10;
    xx=x+4;

    sx=x;
    sy=yy;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    sy=y+1;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=xx+1;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=sy-1;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=x+1;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=yy;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=sx-1;
    fx=sx*WIDE;
    lineto(fx,fy);

    stroke();

}



//void cut_tr ( int x, int y, int yy, int xx )
void cut_tr ( int x, int y)
{
    int sx,sy;
    float fx,fy;
    int xx,yy;

    //cut_tr (25,25,21,15); top right box
    xx=x-10;
    yy=y-4;

    sx=xx;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    sy=y+1;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=x+1;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=yy;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=sx-1;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=y;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=xx;
    fx=sx*WIDE;
    lineto(fx,fy);

    stroke();

}


//void cut_br ( int x, int y, int yy, int xx )
void cut_br ( int x, int y )
{
    int sx,sy;
    float fx,fy;
    int xx,yy;

    //cut_br (25,7,17,21); botton right box
    xx=x-4;
    yy=y+10;

    sx=xx;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    sy=y+1;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=x;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=yy+1;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=sx+1;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=y;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=xx;
    fx=sx*WIDE;
    lineto(fx,fy);

    stroke();

}

void cut_t ( int x, int y )
{
    float fx,fy;
    float rad;
    
    printf("%% cut_t(%d,%d)\n",x,y);

    fx=(x)*WIDE;
    fy=(y)*WIDE;
    moveto(fx,fy);

    fy=(y+6)*WIDE;
    lineto(fx,fy);

    fx=(x+3.5F)*WIDE;
    //fy=(y+6)*WIDE;
    rad=3.5F*WIDE;
    arcn(fx,fy,rad,180,0);

    fx=(x+7)*WIDE;
    lineto(fx,fy);

    fx=(x+3.5F)*WIDE;
    //fy=(y+6)*WIDE;
    rad=2.5F*WIDE;
    arc(fx,fy,rad,0,180);

    fx=(x+1)*WIDE;
    fy=(y)*WIDE;
    lineto(fx,fy);

    fx=(x)*WIDE;
    lineto(fx,fy);

    stroke();

}



void cut_b ( int x, int y )
{
    float fx,fy;
    float rad;
    
    printf("%% cut_b(%d,%d)\n",x,y);


    fx=(x)*WIDE;
    fy=(y+1)*WIDE;
    moveto(fx,fy);

    fx=(x+1)*WIDE;
    lineto(fx,fy);

    fy=(y-5)*WIDE;
    lineto(fx,fy);

    fx=(x-2.5F)*WIDE;
    rad=3.5F*WIDE;
    arcn(fx,fy,rad,0,180);

    fx=(x-5)*WIDE;
    lineto(fx,fy);

    fx=(x-2.5F)*WIDE;
    //fy=(y-5)*WIDE;
    rad=2.5F*WIDE;
    arc(fx,fy,rad,180,0);

    fx=(x)*WIDE;
    fy=(y+1)*WIDE;
    lineto(fx,fy);

    stroke();

}



void cut_l ( int x, int y )
{
    float fx,fy;
    float rad;
    
    printf("%% cut_l(%d,%d)\n",x,y);



    fx=(x+1)*WIDE;
    fy=y*WIDE;
    moveto(fx,fy);

    fx=(x-5)*WIDE;
    lineto(fx,fy);

    fx=(x-5)*WIDE;
    fy=(y+3.5F)*WIDE;
    rad=3.5F*WIDE;
    arcn(fx,fy,rad,270,90);

    fy=(y+6)*WIDE;
    lineto(fx,fy);

    fx=(x-5)*WIDE;
    fy=(y+3.5F)*WIDE;
    rad=2.5F*WIDE;
    arc(fx,fy,rad,90,270);

    fx=(x+1)*WIDE;
    fy=(y+1)*WIDE;
    lineto(fx,fy);

    fy=(y)*WIDE;
    lineto(fx,fy);

    stroke();

}


//void cut_r ( int x, int y, int a, int b, int c )
void cut_r ( int x, int y )
{
    float fx,fy;
    float rad;

    printf("%%cut_r(%d,%d);\n",x,y);

    fx=(x)*WIDE;
    fy=(y)*WIDE;
    moveto(fx,fy);

    fx=(x+6)*WIDE;
    lineto(fx,fy);

    //fx=(x+6)*WIDE;
    fy=(y-2.5F)*WIDE;
    rad=2.5F*WIDE;
    arcn(fx,fy,rad,90,270);

    fy=(y-6)*WIDE;
    lineto(fx,fy);

    //fx=(x+6)*WIDE;
    fy=(y-2.5F)*WIDE;
    rad=3.5F*WIDE;
    arc(fx,fy,rad,270,90);

    fx=(x)*WIDE;
    fy=(y+1)*WIDE;
    lineto(fx,fy);

    fy=(y)*WIDE;
    lineto(fx,fy);

    stroke();


}


//void cut_horizontal ( int x, int y, int xx )
void cut_horizontal ( int x, int y)
{
    int sx,sy;
    float fx,fy;
    int xx;

    //cut_horizontal(15,13,23);
    xx=x+8;

    sx=x;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    sy=y+1;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=xx+1;
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



//void cut_vertical ( int x, int y, int yy )
void cut_vertical ( int x, int y )
{
    int sx,sy;
    float fx,fy;
    int yy;


    //cut_vertical(13, 9,17); //bottom box
    yy=y+8;

    sx=x;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    sy=yy+1;
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

void cut_out ( void )
{
    float fx,fy;
    float rad;

    printf("%%cut_out();\n");

    fx=6*WIDE;
    fy=6*WIDE;
    moveto(fx,fy);

    fy=10.5F*WIDE;
    rad=4.5F*WIDE;
    arcn(fx,fy,rad,270,90);

    fx=10.5F*WIDE;
    fy=(14+1)*WIDE;
    rad=4.5F*WIDE;
    arcn(fx,fy,rad,180,0);

    fx=(14+1)*WIDE;
    fy=10.5F*WIDE;
    rad=4.5F*WIDE;
    arcn(fx,fy,rad,90,270);

    fx=10.5F*WIDE;
    fy=6*WIDE;
    rad=4.5F*WIDE;
    arcn(fx,fy,rad,0,180);






    stroke();

}



int main ( void )
{
    unsigned int ra;
    minx=1000;
    miny=1000;
    maxx=-100;
    maxy=-1000;


if(ANGLED)
{
    ra=240;
}
else
{
    ra=220;
}


    printf("%%BoundingBox: 0 0 %u %u\n",ra,ra);
    printf("<< /PageSize [%u %u] >> setpagedevice\n",ra,ra);
    printf("1.0 setlinewidth\n");
    printf("0.0 setgray\n");


    cut_square_b(9,3);

    cut_square_l(3,9);
    cut_square(9,9);
    cut_square_r(15,9);

    cut_square_t(9,15);
    

    cut_l(11,7); //long leg end
    cut_r(9,13); //long leg end

    cut_b(13,11); //long leg end
    cut_t(7,9); //long leg end

    cut_out();

    printf("showpage\n");

    fprintf(stderr,"x %f %f\n",minx,maxx);
    fprintf(stderr,"y %f %f\n",miny,maxy);
/*

ps2pdf hello.ps
pdf2svg hello.pdf hello.svg

*/

    return(0);
}
