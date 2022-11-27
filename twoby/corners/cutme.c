
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

FILE *fp;

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


void cut_horizontal ( int x, int y, int xx)
{
    int sx,sy;
    float fx,fy;

    elements++;
    fprintf(fp,"%%cut_horizontal(%d,%d,%d);\n",x,y,xx);

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

void cut_vertical ( int x, int y, int yy )
{
    int sx,sy;
    float fx,fy;

    elements++;
    fprintf(fp,"%%cut_vertical(%d,%d,%d);\n",x,y,yy);

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



void cut_cross ( int x, int y)
{
    int sx,sy;
    float fx,fy;

    elements++;
    fprintf(fp,"%%cut_cross(%d,%d);\n",x,y);

    sx=x;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    sy=sy+6;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=sx-6;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=sy+3;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=sx+6;
    fx=sx*WIDE;
    lineto(fx,fy);


    sy=sy+6;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=sx+3;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=sy-6;
    fy=sy*WIDE;
    lineto(fx,fy);


    sx=sx+6;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=sy-3;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=sx-6;
    fx=sx*WIDE;
    lineto(fx,fy);


    sy=sy-6;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=sx-3;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=sy+6;
    fy=sy*WIDE;
    lineto(fx,fy);




    stroke();

}



void cut_out ( void )
{
    int sx,sy;
    float fx,fy;

    unsigned int ra;


    elements++;
    fprintf(fp,"%%cut_out();\n");

    sx=18;
    sy=9;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    sx=sx-3;
    fx=sx*WIDE;
    lineto(fx,fy);


    for(ra=0;ra<2;ra++)
    {
    
    sx=sx-6;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=sy+6;
    fy=sy*WIDE;
    lineto(fx,fy);
    
    }

    sy=sy+3;
    fy=sy*WIDE;
    lineto(fx,fy);

    for(ra=0;ra<3;ra++)
    {
    
    sx=sx+6;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=sy+6;
    fy=sy*WIDE;
    lineto(fx,fy);
    
    }

    sx=sx+9;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=sy-6;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=sx+6;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=sy-9;
    fy=sy*WIDE;
    lineto(fx,fy);


    for(ra=0;ra<3;ra++)
    {
    
    sx=sx-6;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=sy-6;
    fy=sy*WIDE;
    lineto(fx,fy);
    
    }















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
    float fa;

    elements=0;

    sprintf(xstring,"twobycorners.ps");
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


    cut_horizontal(10,10,7);

    cut_horizontal( 4,16,11);
    cut_horizontal(18,16,5);

    cut_horizontal( 4,22,5);
    cut_horizontal(12,22,9);
    cut_horizontal(24,22,5);

    cut_horizontal(10,28,5);
    cut_horizontal(18,28,9);
    cut_horizontal(30,28,5);

    cut_horizontal(16,34,5);
    cut_horizontal(24,34,11);

    cut_horizontal(22,40,7);

    
    cut_vertical( 4,16,7);

    cut_vertical(10,10,5);
    cut_vertical(10,18,11);

    cut_vertical(16,10,11);
    cut_vertical(16,24,11);

    cut_vertical(22,16,11);
    cut_vertical(22,30,11);

    cut_vertical(28,22,11);
    cut_vertical(28,36,5);

    cut_vertical(34,28,5);






    cut_square(12,12);

    cut_square( 6,18);
    cut_square(12,18);
    cut_square(18,18);
    
    cut_square(12,24);
    cut_square(18,24);
    cut_square(24,24);
    
    cut_square(18,30);
    cut_square(24,30);
    cut_square(30,30);

    cut_square(24,36);


    //cut_cross(18,26);
    //cut_cross(42,26);

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


