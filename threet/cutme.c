
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

FILE *fp;
FILE *fpbatch;


#define ANGLED 1

double rangle = (45) / 180.0 * M_PI;

#define WIDE 10.0F

unsigned int elements;

float middle;
int goback;
float minx,maxx;
float miny,maxy;
void moveto ( float x, float y )
{

if(ANGLED)
{
    double rx,ry;
    x-=middle*WIDE;
    y-=middle*WIDE;
    rx=(x*cos(rangle))-(y*sin(rangle));
    ry=(x*sin(rangle))+(y*cos(rangle));
    x=rx;
    y=ry;

    x+=goback*WIDE;
    y+=goback*WIDE;

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


    fprintf(fp,"%f %f moveto\n",x,y);
}
void lineto ( float x, float y )
{

if(ANGLED)
{
    double rx,ry;
    x-=middle*WIDE;
    y-=middle*WIDE;
    rx=(x*cos(rangle))-(y*sin(rangle));
    ry=(x*sin(rangle))+(y*cos(rangle));
    x=rx;
    y=ry;

    x+=goback*WIDE;
    y+=goback*WIDE;
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

    fprintf(fp,"%f %f lineto\n",x,y);
}
void stroke ( void )
{
    fprintf(fp,"stroke\n");
}
void arc ( float x, float y, float r, float a, float b )
{

if(ANGLED)
{
    double rx,ry;
    x-=middle*WIDE;
    y-=middle*WIDE;
    rx=(x*cos(rangle))-(y*sin(rangle));
    ry=(x*sin(rangle))+(y*cos(rangle));
    x=rx;
    y=ry;

    x+=goback*WIDE;
    y+=goback*WIDE;

    a+=45;
    b+=45;


}
else
{
    x+=10;
    y+=10;
}

    fprintf(fp,"%f %f %f %f %f arc\n",x,y,r,a,b);
}

void arcn ( float x, float y, float r, float a, float b )
{
if(ANGLED)
{
    double rx,ry;
    x-=middle*WIDE;
    y-=middle*WIDE;
    rx=(x*cos(rangle))-(y*sin(rangle));
    ry=(x*sin(rangle))+(y*cos(rangle));
    x=rx;
    y=ry;

    x+=goback*WIDE;
    y+=goback*WIDE;

    a+=45;
    b+=45;


}
else
{
    x+=10;
    y+=10;
}

    fprintf(fp,"%f %f %f %f %f arcn\n",x,y,r,a,b);
}


void cut_square ( int x, int y )
{
    float fx,fy;


    elements++;
    fprintf(fp,"%%cut_square(%d,%d);\n",x,y);

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

    elements++;
    fprintf(fp,"%%cut_square_l(%d,%d);\n",x,y);

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


void cut_square_bl ( int x, int y )
{
    float fx,fy;
    float rad;

    elements++;
    fprintf(fp,"%%cut_square_bl(%d,%d);\n",x,y);

    fx=(x)*WIDE;
    fy=(y+3)*WIDE;
    moveto(fx,fy);

    fx=(x+3)*WIDE;
    lineto(fx,fy);

    fy=(y)*WIDE;
    lineto(fx,fy);

    fx=(x+3)*WIDE;
    fy=(y+3)*WIDE;
    rad=3*WIDE;
    arcn(fx,fy,rad,270,180);
    stroke();
}

void cut_square_br ( int x, int y )
{
    float fx,fy;
    float rad;

    elements++;
    fprintf(fp,"%%cut_square_br(%d,%d);\n",x,y);

    fx=(x)*WIDE;
    fy=(y)*WIDE;
    moveto(fx,fy);

    fy=(y+3)*WIDE;
    lineto(fx,fy);

    fx=(x+3)*WIDE;
    lineto(fx,fy);

    fx=(x)*WIDE;
    fy=(y+3)*WIDE;
    rad=3*WIDE;
    arcn(fx,fy,rad,0,270);
    stroke();
}

void cut_square_tr ( int x, int y )
{
    float fx,fy;
    float rad;

    elements++;
    fprintf(fp,"%%cut_square_tr(%d,%d);\n",x,y);

    fx=(x+3)*WIDE;
    fy=(y)*WIDE;
    moveto(fx,fy);

    fx=(x)*WIDE;
    lineto(fx,fy);

    fy=(y+3)*WIDE;
    lineto(fx,fy);

    fx=(x)*WIDE;
    fy=(y)*WIDE;
    rad=3*WIDE;
    arcn(fx,fy,rad,90,0);
    stroke();
}


void cut_square_tl ( int x, int y )
{
    float fx,fy;
    float rad;

    elements++;
    fprintf(fp,"%%cut_square_tl(%d,%d);\n",x,y);

    fx=(x+3)*WIDE;
    fy=(y+3)*WIDE;
    moveto(fx,fy);

    fy=(y)*WIDE;
    lineto(fx,fy);

    fx=(x)*WIDE;
    lineto(fx,fy);


    fx=(x+3)*WIDE;
    fy=(y)*WIDE;
    rad=3*WIDE;
    arcn(fx,fy,rad,180,90);
    stroke();
}

void cut_square_eye ( int x, int y )
{
    float fx,fy;
    float rad;

    elements++;
    fprintf(fp,"%%cut_square_eye(%d,%d);\n",x,y);

    fx=(x)*WIDE;
    fy=(y)*WIDE;
    moveto(fx,fy);

    fx=(x+3)*WIDE;
    fy=(y)*WIDE;
    rad=3*WIDE;
    arcn(fx,fy,rad,180,90);
    
    
    fx=(x)*WIDE;
    fy=(y+3)*WIDE;
    rad=3*WIDE;
    arcn(fx,fy,rad,0,270);
    
    
    
    
    
    
    
    
    
    stroke();
}


void cut_square_r ( int x, int y )
{
    float fx,fy;
    float rad;

    elements++;
    fprintf(fp,"%%cut_square_r(%d,%d);\n",x,y);

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

    elements++;
    fprintf(fp,"%%cut_square_t(%d,%d);\n",x,y);

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

    elements++;
    fprintf(fp,"%%cut_square_b(%d,%d);\n",x,y);

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




void cut_top ( void )
{
    float fx,fy;
    float rad;

    elements++;
    fprintf(fp,"%%cut_top();\n");

    fx=(9)*WIDE;
    fy=(19)*WIDE;
    moveto(fx,fy);

    fx=(9)*WIDE;
    fy=(24)*WIDE;
    rad=5.0F*WIDE;
    arc(fx,fy,rad,270,0);

    fx=(14)*WIDE;
    fy=(27)*WIDE;
    lineto(fx,fy);


    fx=(16.5)*WIDE;
    fy=(27)*WIDE;
    rad=2.5F*WIDE;
    arcn(fx,fy,rad,180,0);


    fx=(20)*WIDE;
    fy=(27)*WIDE;
    lineto(fx,fy);

    fx=(16.5)*WIDE;
    fy=(27)*WIDE;
    rad=3.5F*WIDE;
    arc(fx,fy,rad,0,180);

    fx=(13)*WIDE;
    fy=(24)*WIDE;
    lineto(fx,fy);

    fx=(9)*WIDE;
    fy=(24)*WIDE;
    rad=4.0F*WIDE;
    arcn(fx,fy,rad,0,270);

    fx=(9)*WIDE;
    fy=(19)*WIDE;
    lineto(fx,fy);


    stroke();
}




void cut_bottom ( void )
{
    float fx,fy;
    float rad;

    elements++;
    fprintf(fp,"%%cut_top();\n");

    fx=(24)*WIDE;
    fy=(13)*WIDE;
    moveto(fx,fy);

    fx=(24)*WIDE;
    fy=(9)*WIDE;
    rad=4.0F*WIDE;
    arc(fx,fy,rad,90,180);

    fx=(20)*WIDE;
    fy=(6)*WIDE;
    lineto(fx,fy);


    fx=(16.5)*WIDE;
    fy=(6)*WIDE;
    rad=3.5F*WIDE;
    arcn(fx,fy,rad,0,180);

    fx=(14)*WIDE;
    fy=(6)*WIDE;
    lineto(fx,fy);

    fx=(16.5)*WIDE;
    fy=(6)*WIDE;
    rad=2.5F*WIDE;
    arc(fx,fy,rad,180,0);

    fx=(19)*WIDE;
    fy=(9)*WIDE;
    lineto(fx,fy);

    fx=(24)*WIDE;
    fy=(9)*WIDE;
    rad=5.0F*WIDE;
    arcn(fx,fy,rad,180,90);

    fx=(24)*WIDE;
    fy=(13)*WIDE;
    lineto(fx,fy);

    stroke();
}





void cut_t ( int x, int y )
{
    float fx,fy;
    float rad;

    elements++;
    fprintf(fp,"%% cut_t(%d,%d)\n",x,y);

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

    elements++;
    fprintf(fp,"%% cut_b(%d,%d)\n",x,y);


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

    elements++;
    fprintf(fp,"%% cut_l(%d,%d)\n",x,y);

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


void cut_r ( int x, int y )
{
    float fx,fy;
    float rad;

    elements++;
    fprintf(fp,"%%cut_r(%d,%d);\n",x,y);

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

















void cut_bl ( int x, int y )
{
    float fx,fy;
    float rad;

    elements++;
    fprintf(fp,"%%cut_bl(%d,%d);\n",x,y);

    fx=(x)*WIDE;
    fy=(y+5)*WIDE;
    moveto(fx,fy);

    fx=(x+1)*WIDE;
    lineto(fx,fy);

    fx=(x+5)*WIDE;
    fy=(y+5)*WIDE;
    rad=4.0F*WIDE;
    arc(fx,fy,rad,180,270);

    fx=(x+11)*WIDE;
    fy=(y+1)*WIDE;
    lineto(fx,fy);

    fy=(y)*WIDE;
    lineto(fx,fy);

    fx=(x+5)*WIDE;
    lineto(fx,fy);

    fx=(x+5)*WIDE;
    fy=(y+5)*WIDE;
    rad=5.0F*WIDE;
    arcn(fx,fy,rad,270,180);

    stroke();

}



void cut_tl ( int x, int y )
{
    float fx,fy;
    float rad;

    elements++;
    fprintf(fp,"%%cut_tl(%d,%d);\n",x,y);

    fx=(x+5)*WIDE;
    fy=(y+1)*WIDE;
    moveto(fx,fy);

    fy=(y)*WIDE;
    lineto(fx,fy);

    fx=(x+5)*WIDE;
    fy=(y-4)*WIDE;
    rad=4.0F*WIDE;
    arc(fx,fy,rad,90,180);

    fx=(x+1)*WIDE;
    fy=(y-10)*WIDE;
    lineto(fx,fy);

    fx=(x)*WIDE;
    lineto(fx,fy);

    fy=(y-4)*WIDE;
    lineto(fx,fy);

    fx=(x+5)*WIDE;
    fy=(y-4)*WIDE;
    rad=5.0F*WIDE;
    arcn(fx,fy,rad,180,90);

    stroke();

}




void cut_tr ( int x, int y )
{
    float fx,fy;
    float rad;

    elements++;
    fprintf(fp,"%%cut_tr(%d,%d);\n",x,y);

    //xx=x-10;
    //yy=y-4;

    fx=(x)*WIDE;
    fy=(y-4)*WIDE;
    moveto(fx,fy);

    fx=(x+1)*WIDE;
    lineto(fx,fy);

    fx=(x-4)*WIDE;
    fy=(y-4)*WIDE;
    rad=5.0F*WIDE;
    arc(fx,fy,rad,0,90);

    fx=(x-10)*WIDE;
    fy=(y+1)*WIDE;
    lineto(fx,fy);

    fy=(y)*WIDE;
    lineto(fx,fy);

    fx=(x-4)*WIDE;
    lineto(fx,fy);

    fx=(x-4)*WIDE;
    fy=(y-4)*WIDE;
    rad=4.0F*WIDE;
    arcn(fx,fy,rad,90,0);

    stroke();

}



void cut_br ( int x, int y )
{
    float fx,fy;
    float rad;

    elements++;
    fprintf(fp,"%%cut_br(%d,%d);\n",x,y);

    fx=(x-4)*WIDE;
    fy=(y)*WIDE;
    moveto(fx,fy);

    fy=(y+1)*WIDE;
    lineto(fx,fy);

    fx=(x-4)*WIDE;
    fy=(y+5)*WIDE;
    rad=4.0F*WIDE;
    arc(fx,fy,rad,270,0);

    fx=(x)*WIDE;
    fy=(y+11)*WIDE;
    lineto(fx,fy);

    fx=(x+1)*WIDE;
    lineto(fx,fy);

    fy=(y+5)*WIDE;
    lineto(fx,fy);

    fx=(x-4)*WIDE;
    fy=(y+5)*WIDE;
    rad=5.0F*WIDE;
    arcn(fx,fy,rad,0,270);

    stroke();

}



//void cut_horizontal ( int x, int y, int xx )
void cut_horizontal ( int x, int y)
{
    int sx,sy;
    float fx,fy;
    int xx;

    elements++;
    fprintf(fp,"%%cut_horizontal(%d,%d);\n",x,y);

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

    elements++;
    fprintf(fp,"%%cut_vertical(%d,%d);\n",x,y);


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

void cut_out ( int points )
{
    unsigned int ra;
    int sx,sy;
    float fx,fy;
    double rad;

    elements++;
    fprintf(fp,"%%cut_out());\n");
    
    sx=(points-1)*6;
    sy=6;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    for(ra=0;ra<(points-2);ra++)
    {
        fx=(sx)*WIDE;
        fy=(sy+6)*WIDE;
        rad=6*WIDE;
        arcn(fx,fy,rad,270,180);
        sy+=6;
        sx-=6;
    }


    //left
    fx=(sx)*WIDE;
    fy=(sy+4.5F)*WIDE;
    rad=4.5F*WIDE;
    arcn(fx,fy,rad,270,90);
    sy+=9;

    for(ra=0;ra<(points-2);ra++)
    {
        fx=(sx+6)*WIDE;
        fy=(sy)*WIDE;
        rad=6*WIDE;
        arcn(fx,fy,rad,180,90);
        sx+=6;
        sy+=6;
    }

    //top
    fx=(sx+4.5F)*WIDE;
    fy=(sy)*WIDE;
    rad=4.5F*WIDE;
    arcn(fx,fy,rad,180,0);
    sx+=9;

    for(ra=0;ra<(points-2);ra++)
    {
        fx=(sx)*WIDE;
        fy=(sy-6)*WIDE;
        rad=6*WIDE;
        arcn(fx,fy,rad,90,0);
        sy-=6;
        sx+=6;
    }

    //right
    fx=(sx)*WIDE;
    fy=(sy-4.5F)*WIDE;
    rad=4.5F*WIDE;
    arcn(fx,fy,rad,90,270);
    sy-=9;

    for(ra=0;ra<(points-2);ra++)
    {
        fx=(sx-6)*WIDE;
        fy=(sy)*WIDE;
        rad=6*WIDE;
        arcn(fx,fy,rad,0,270);
        sx-=6;
        sy-=6;
    }

    //bottom
    fx=(sx-4.5F)*WIDE;
    fy=(sy)*WIDE;
    rad=4.5F*WIDE;
    arcn(fx,fy,rad,0,180);


    stroke();

}



void cut_square_bltr ( int x, int y )
{
    float fx,fy;
    float rad;

    elements++;
    fprintf(fp,"%%cut_square_bltr(%d,%d);\n",x,y);

    fx=(x)*WIDE;
    fy=(y)*WIDE;
    moveto(fx,fy);

    fy=(y+3)*WIDE;
    lineto(fx,fy);

    fx=(x)*WIDE;
    fy=(y+9)*WIDE;
    rad=6.0F*WIDE;
    arc(fx,fy,rad,270,0);

    fx=(x+6)*WIDE;
    fy=(y+9)*WIDE;
    moveto(fx,fy);

    fx=(x+9)*WIDE;
    lineto(fx,fy);

    fy=(y+6)*WIDE;
    lineto(fx,fy);

    fx=(x+9)*WIDE;
    fy=(y)*WIDE;
    rad=6.0F*WIDE;
    arc(fx,fy,rad,90,180);
 
    fx=(x+3)*WIDE;
    fy=(y)*WIDE;
    moveto(fx,fy);

    fx=(x)*WIDE;
    lineto(fx,fy);

    stroke();
}


void cut_square_brtl ( int x, int y )
{
    float fx,fy;
    float rad;

    elements++;
    fprintf(fp,"%%cut_square_bltr(%d,%d);\n",x,y);

    fx=(x+1)*WIDE;
    fy=(y)*WIDE;
    moveto(fx,fy);

    fx=(x-1)*WIDE;
    lineto(fx,fy);

    fx=(x-8)*WIDE;
    fy=(y)*WIDE;
    rad=6.0F*WIDE;
    arc(fx,fy,rad,0,90);

    fx=(x-8)*WIDE;
    fy=(y+6)*WIDE;
    moveto(fx,fy);

    fy=(y+9)*WIDE;
    lineto(fx,fy);

    fx=(x-5)*WIDE;
    lineto(fx,fy);


    fx=(x+1)*WIDE;
    fy=(y+9)*WIDE;
    rad=6.0F*WIDE;
    arc(fx,fy,rad,180,270);

    fx=(x+1)*WIDE;
    fy=(y+3)*WIDE;
    moveto(fx,fy);

    fy=(y)*WIDE;
    lineto(fx,fy);


    stroke();
}












//void show_number ( unsigned int x, unsigned int y, unsigned int d )
//{
    //float fx,fy;

    //fx=10+(x*WIDE);
    //fy=12+(y*WIDE);

    //fprintf(fp,"%f %f moveto (%u) show\n",fx,fy,d);
//}
//void doline (
    //unsigned int rax,
    //unsigned int ray,
    //unsigned int rbx,
    //unsigned int rby
//)
//{

    //rax*=WIDE;
    //rbx*=WIDE;
    //ray*=WIDE;
    //rby*=WIDE;

    //fprintf(fp,"%u %u moveto\n",rax,ray);
    //fprintf(fp,"%u %u lineto\n",rbx,rby);
    //fprintf(fp,"stroke\n");

//}


int main ( void )
{

    char xstring[40];
    unsigned int points = 3;
    unsigned int ra;
    //unsigned int rb;
    //unsigned int rc;
    //unsigned int rx;
    //unsigned int ry;
    //unsigned int xx,yy;

    elements=0;

    sprintf(xstring,"threet.ps");
    fprintf(stderr,"%s\n",xstring);
    fp=fopen(xstring,"wt");
    if(fp==NULL)
    {
        fprintf(stderr,"Error creating file [%s]\n",xstring);
        exit(1);
    }

    minx=1000;
    miny=1000;
    maxx=-100;
    maxy=-1000;

if(ANGLED)
{

    middle=((points-1)*6)+4;
    middle+=0.5F;
    goback=points*5;
}
    ra=300;

    fprintf(fp,"%%!\n");
    fprintf(fp,"%%BoundingBox: 0 0 %u %u\n",ra,ra);
    fprintf(fp,"<< /PageSize [%u %u] >> setpagedevice\n",ra,ra);



    fprintf(fp,"1.0 setlinewidth\n");
    fprintf(fp,"0.0 setgray\n");
    cut_square_b(15,3);
    cut_square_bl(9,9);
    cut_square_eye(21,9);
    cut_square_l(3,15);
    cut_square_eye(15,15);
    cut_square_r(27,15);
    cut_square_eye(9,21);
    cut_square_tr(21,21);
    cut_square_t(15,27);
    cut_bl(7,7);
    cut_br(25,7);
    cut_tl(7,25);
    cut_tr(25,25);
    cut_br(19,13);
    cut_tl(13,19);
    cut_bottom();
    cut_top();
    cut_l(11,13);
    cut_r(21,19);
    cut_square_bltr(9,15); //bottom left
    cut_square_bltr(15,9); //bottom left
    cut_out(3);


    fprintf(fp,"showpage\n");

    fprintf(fp,"%%minmax x %f %f\n",minx,maxx);
    fprintf(fp,"%%minmax y %f %f\n",miny,maxy);
    fprintf(stderr,"minmax x %f %f\n",minx,maxx);
    fprintf(stderr,"minmax y %f %f\n",miny,maxy);

    fprintf(fp,"%%elements %u\n",elements);
    fprintf(stderr,"elements %u\n",elements);

    fclose(fp);
    return(0);
}

