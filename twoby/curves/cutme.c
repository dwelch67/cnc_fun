
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

FILE *fp;

double degrad = M_PI / 180.0;
double raddeg = 180.0 / M_PI;


float adjustment;


#define WIDE 10.0F

unsigned int elements;

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


    fprintf(fp,"%f %f moveto\n",x,y);
}
void lineto ( float x, float y )
{

    x+=10;
    y+=10;

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
void arc ( float x, float y, float rad, float a, float b )
{

    x+=10;
    y+=10;

    if(x<minx) minx=x;
    if(x>maxx) maxx=x;
    if(y<miny) miny=y;
    if(y>maxy) maxy=y;

    fprintf(fp,"%f %f %f %f %f arc\n",x,y,rad,a,b);
}
void arcn ( float x, float y, float rad, float a, float b )
{

    x+=10;
    y+=10;

    if(x<minx) minx=x;
    if(x>maxx) maxx=x;
    if(y<miny) miny=y;
    if(y>maxy) maxy=y;

    fprintf(fp,"%f %f %f %f %f arcn\n",x,y,rad,a,b);
}


void cut_horizontal ( float x, float y, float xx)
{
    float sx,sy;
    float fx,fy;

    elements++;
    fprintf(fp,"%%cut_horizontal(%f,%f,%f);\n",x,y,xx);

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

    elements++;
    fprintf(fp,"%%cut_vertical(%f,%f,%f);\n",x,y,yy);

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

    elements++;
    fprintf(fp,"%%cut_square(%d,%d);\n",x,y);

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

    elements++;
    fprintf(fp,"%%cut_arc(%f,%f,%f,%f,%f);\n",x,y,rad,a,b);
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


void cut_special ( void )
{
    float x,y;
    float fx,fy;
    float sx,sy;
    float rad;

    elements++;
    fprintf(fp,"%%cut_special();\n");

    x=9;
    y=18;
    sx=x;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);
    sx-=adjustment;
    fx=sx*WIDE;
    lineto(fx,fy);
    sy+=1.5;
    fy=sy*WIDE;
    rad=1.5*WIDE;
    arcn(fx,fy,rad,270,90);
    sx=x;
    sy=y+3;
    fx=sx*WIDE;
    fy=sy*WIDE;
    lineto(fx,fy);
    sx=x;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    lineto(fx,fy);
    stroke();



    //sx=15;
    //sy=15;
    //fx=sx*WIDE;
    //fy=sy*WIDE;
    //moveto(fx,fy);

    //sx-=1.5;
    //fx=sx*WIDE;
    //rad=1.5*WIDE;
    //arc(fx,fy,rad,180,0);
    //stroke();


    x=15;
    y=15;
    sx=x;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);
    sy-=adjustment;
    fy=sy*WIDE;
    lineto(fx,fy);
    sx-=1.5;
    fx=sx*WIDE;
    rad=1.5*WIDE;
    arcn(fx,fy,rad,0,180);
    sx=x-3;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    lineto(fx,fy);
    sx=x;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    lineto(fx,fy);
    stroke();

    //sx=24;
    //sy=36;
    //fx=sx*WIDE;
    //fy=sy*WIDE;
    //moveto(fx,fy);

    //sx+=1.5;
    //fx=sx*WIDE;
    //rad=1.5*WIDE;
    //arc(fx,fy,rad,0,180);
    //stroke();


    x=24;
    y=36;
    sx=x;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);
    sy+=adjustment;
    fy=sy*WIDE;
    lineto(fx,fy);
    sx+=1.5;
    fx=sx*WIDE;
    rad=1.5*WIDE;
    arcn(fx,fy,rad,180,0);
    sx=x+3;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    lineto(fx,fy);
    sx=x;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    lineto(fx,fy);
    stroke();

    //sx=30;
    //sy=33;
    //fx=sx*WIDE;
    //fy=sy*WIDE;
    //moveto(fx,fy);

    //sy-=1.5;
    //fy=sy*WIDE;
    //rad=1.5*WIDE;
    //arc(fx,fy,rad,270,90);
    //stroke();

    x=30;
    y=33;
    sx=x;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);
    sx+=adjustment;
    fx=sx*WIDE;
    lineto(fx,fy);
    sy-=1.5;
    fy=sy*WIDE;
    rad=1.5*WIDE;
    arcn(fx,fy,rad,90,270);
    sx=x;
    sy=y-3;
    fx=sx*WIDE;
    fy=sy*WIDE;
    lineto(fx,fy);
    sx=x;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    lineto(fx,fy);
    stroke();

    sx=12;
    sy=24;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    sx+=3;
    fx=sx*WIDE;
    lineto(fx,fy);

    rad=3*WIDE;
    arc(fx,fy,rad,90,180);
    stroke();



    sx=18;
    sy=30;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    sx+=3;
    fx=sx*WIDE;
    lineto(fx,fy);

    rad=3*WIDE;
    arc(fx,fy,rad,90,180);
    stroke();



    sx=21;
    sy=21;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    sx-=3;
    fx=sx*WIDE;
    lineto(fx,fy);

    rad=3*WIDE;
    arc(fx,fy,rad,270,0);
    stroke();



    sx=27;
    sy=27;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    sx-=3;
    fx=sx*WIDE;
    lineto(fx,fy);

    rad=3*WIDE;
    arc(fx,fy,rad,270,0);
    stroke();

}


void cut_out ( void )
{
    float sx,sy;
    float fx,fy;
    float rad;

    elements++;
    fprintf(fp,"%%cut_out();\n");

    sx=9;
    sy=15;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    sx-=adjustment;
    fx=sx*WIDE;
    lineto(fx,fy);

    //sx=9;
    sy=19.5;
    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=4.5*WIDE;
    arcn(fx,fy,rad,270,90);

    sx+=adjustment;
    sy+=4.5;
    fx=sx*WIDE;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=15;
    sy=24;
    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=6*WIDE;
    arcn(fx,fy,rad,180,90);

    sx=21;
    sy=30;
    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=6*WIDE;
    arcn(fx,fy,rad,180,90);

    //sx=25.5;
    //sy=36;
    //fx=sx*WIDE;
    //fy=sy*WIDE;
    //rad=4.5*WIDE;
    //arcn(fx,fy,rad,180,0);

    sx=21;
    sy=36+adjustment;
    fx=sx*WIDE;
    fy=sy*WIDE;
    lineto(fx,fy);
    sx+=4.5;
    fx=sx*WIDE;
    rad=4.5*WIDE;
    arcn(fx,fy,rad,180,0);
    sx=21+9;
    sy=36;
    fx=sx*WIDE;
    fy=sy*WIDE;
    lineto(fx,fy);


    //sx=30;
    //sy=31.5;
    //fx=sx*WIDE;
    //fy=sy*WIDE;
    //rad=4.5*WIDE;
    //arcn(fx,fy,rad,90,270);

    //sx=30+adjustment;
    //sy=36;
    sx+=adjustment;
    sy-=4.5;
    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=4.5*WIDE;
    arcn(fx,fy,rad,90,270);
    sx-=adjustment;
    sy-=4.5;
    fx=sx*WIDE;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=24;
    sy=27;
    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=6*WIDE;
    arcn(fx,fy,rad,0,270);

    sx=18;
    sy=21;
    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=6*WIDE;
    arcn(fx,fy,rad,0,270);

    //sx=13.5;
    //sy=15;
    //fx=sx*WIDE;
    //fy=sy*WIDE;
    //rad=4.5*WIDE;
    //arcn(fx,fy,rad,0,180);

    sx=13.5;
    sy=15-adjustment;
    fx=sx*WIDE;
    fy=sy*WIDE;
    rad=4.5*WIDE;
    arcn(fx,fy,rad,0,180);
    sx-=4.5;
    sy+=adjustment;
    fx=sx*WIDE;
    fy=sy*WIDE;
    lineto(fx,fy);

    stroke();

}



#define STEP WIDE

int main ( void  )
{


    char xstring[40];
    unsigned int ra;
    //unsigned int rb;
    //unsigned int rc;
    //unsigned int rx;
    //unsigned int ry;
    //unsigned int xx,yy;
    float fa,rad;

    elements=0;

    sprintf(xstring,"twobycurves.ps");
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



    ra=600;


    fprintf(fp,"%%!\n");
    fprintf(fp,"%%BoundingBox: 0 0 %u %u\n",ra,ra);
    fprintf(fp,"<< /PageSize [%u %u] >> setpagedevice\n",ra,ra);
    fprintf(fp,"1.0 setlinewidth\n");
    fprintf(fp,"0.0 setgray\n");


    rad=6*6;
    rad=rad*2;
    rad=sqrt(rad);
    adjustment=rad;
    rad=4.5*4.5;
    rad=rad*2;
    rad=sqrt(rad);
    adjustment=adjustment-rad;
    adjustment=adjustment-1.5;



    //cut_horizontal(10,10,7);

    //cut_horizontal( 4,16,11);
    cut_horizontal(9-adjustment,16,6+adjustment);

    //cut_horizontal(18,16,5);

    //cut_horizontal( 4,22,5);
    cut_horizontal(9-adjustment,22,adjustment);


    cut_horizontal(12,22,9);
    //cut_horizontal(24,22,5);

    //cut_horizontal(10,28,5);
    cut_horizontal(18,28,9);
    //cut_horizontal(30,28,5);
    cut_horizontal(30,28,adjustment);

    //cut_horizontal(16,34,5);
    //cut_horizontal(24,34,11);
    //cut_horizontal(24,34,6);
    cut_horizontal(24,34,6+adjustment);

    //cut_horizontal(22,40,7);


    //cut_vertical( 4,16,7);

    //cut_vertical(10,10,5);
    cut_vertical(10,15-adjustment,adjustment);

    //cut_vertical(10,18,11);
    cut_vertical(10,18,6);

    //cut_vertical(16,10,11);
    //cut_vertical(16,15,6);
    cut_vertical(16,15-adjustment,6+adjustment);

    //cut_vertical(16,24,11);
    cut_vertical(16,24,6);

    //cut_vertical(22,16,11);
    cut_vertical(22,21,6);

    //cut_vertical(22,30,11);
    //cut_vertical(22,30,6);
    cut_vertical(22,30,6+adjustment);

    //cut_vertical(28,22,11);
    cut_vertical(28,27,6);


    //cut_vertical(28,36,5);
    cut_vertical(28,36,adjustment);

    //cut_vertical(34,28,7);


    //cut_square(12,12);

    //cut_square( 6,18);
    cut_square(12,18);
    //cut_square(18,18);

    //cut_square(12,24);
    cut_square(18,24);
    //cut_square(24,24);

    //cut_square(18,30);
    cut_square(24,30);
    //cut_square(30,30);

    //cut_square(24,36);


    cut_arc(15,24,4,90,180);
    cut_arc(21,30,4,90,180);

    cut_arc(18,21,4,270,0);
    cut_arc(24,27,4,270,0);


    //cut_arc(9,19.5,2.5,90,270);
    cut_arc(9-adjustment,19.5,2.5,90,270);



    //cut_arc(13.5,15,2.5,180,0);
    cut_arc(13.5,15-adjustment,2.5,180,0);

    //cut_arc(25.5,36,2.5,0,180);
    cut_arc(25.5,36+adjustment,2.5,0,180);

    //cut_arc(30,31.5,2.5,270,90);
    cut_arc(30+adjustment,31.5,2.5,270,90);

    cut_special();

    cut_out();

if(0)
{
    fprintf(fp,"/Courier-Bold findfont 8 scalefont setfont\n");
    for(ra=0;ra<57;ra++)
    {
        fa=ra;
        fprintf(fp,"%f %f moveto (%u) show\n",(fa*STEP)+STEP,STEP+3,ra);
        if(ra)
            fprintf(fp,"%f %f moveto (%u) show\n",STEP,(fa*STEP)+STEP+3,ra);
    }
}


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


