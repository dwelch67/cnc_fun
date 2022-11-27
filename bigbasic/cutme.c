
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

FILE *fp;
FILE *fpbatch;


#define ANGLED 1

//Radians = Degrees × (π/180)

//double degrad = 1.0 / 180.0 * M_PI;
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


//void cut_bl ( int x, int y, int yy, int xx )
void cut_bl ( int x, int y )
{
    int sx,sy;
    float fx,fy;
    int xx,yy;
//    cut_bl ( 7,7,11,17);

    elements++;
    fprintf(fp,"%%cut_bl(%d,%d);\n",x,y);


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


    elements++;
    fprintf(fp,"%%cut_tl(%d,%d);\n",x,y);


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

    elements++;
    fprintf(fp,"%%cut_tr(%d,%d);\n",x,y);

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

    elements++;
    fprintf(fp,"%%cut_br(%d,%d);\n",x,y);

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


//void cut_b ( int x, int y, int a, int b, int c )
void cut_b ( int x, int y )
{
    int sx,sy;
    float fx,fy;
    int a,b,c;

    elements++;
    fprintf(fp,"%%cut_b(%d,%d);\n",x,y);

    //cut_b(19,5,1,25,11);
    a=y-4;
    b=x+6;
    c=y+6;


    sx=x;
    sy=y+1;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    sx=sx+1;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=a+1;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=b;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=c+1;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=sx+1;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=a;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=x;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=y+1;
    fy=sy*WIDE;
    lineto(fx,fy);

    stroke();

}



//void cut_t ( int x, int y, int a, int b, int c )
void cut_t ( int x, int y )
{
    int sx,sy;
    float fx,fy;
    int a,b,c;

    elements++;
    fprintf(fp,"%%cut_t(%d,%d);\n",x,y);

//    cut_t(19,33,43,25,39); //lower left box
    a=y+10;
    b=x+6;
    c=y+6;

    sx=x;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    sy=a+1;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=b+1;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=c;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=sx-1;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=a;
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


//void cut_l ( int x, int y, int a, int b, int c )
void cut_l ( int x, int y )
{
    int sx,sy;
    float fx,fy;
    int a,b,c;

    elements++;
    fprintf(fp,"%%cut_l(%d,%d);\n",x,y);

    //cut_l(11,19,1,25,5); //lower right box
    a = x-10;
    b = y+6;
    c = x-6;

    sx=x+1;
    sy=y;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    sx=a;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=b+1;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=c+1;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=b;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=a+1;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=y+1;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=x+1;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=y;
    fy=sy*WIDE;
    lineto(fx,fy);

    stroke();

}


//void cut_r ( int x, int y, int a, int b, int c )
void cut_r ( int x, int y )
{
    int sx,sy;
    float fx,fy;
    int a,b,c;

    elements++;
    fprintf(fp,"%%cut_r(%d,%d);\n",x,y);

    //cut_r (33,25,43,19,39); //upper left box
    a = x+10;
    b = y-6;
    c = x+6;

    sx=x;
    sy=y+1;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    sx=a+1;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=b;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=c;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=b+1;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=a;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=y;
    fy=sy*WIDE;
    lineto(fx,fy);

    sx=x;
    fx=sx*WIDE;
    lineto(fx,fy);

    sy=y+1;
    fy=sy*WIDE;
    lineto(fx,fy);


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

    elements++;

    sx=(points-1)*6;
    sy=0;
    fx=sx*WIDE;
    fy=sy*WIDE;
    moveto(fx,fy);

    for(ra=0;ra<(points-1);ra++)
    {
        sy+=6;
        fy=sy*WIDE;
        lineto(fx,fy);

        sx-=6;
        fx=sx*WIDE;
        lineto(fx,fy);
    }

    sy+=9;
    fy=sy*WIDE;
    lineto(fx,fy);

    for(ra=0;ra<(points-1);ra++)
    {
        sx+=6;
        fx=sx*WIDE;
        lineto(fx,fy);

        sy+=6;
        fy=sy*WIDE;
        lineto(fx,fy);
    }


    sx+=9;
    fx=sx*WIDE;
    lineto(fx,fy);

    for(ra=0;ra<(points-1);ra++)
    {
        sy-=6;
        fy=sy*WIDE;
        lineto(fx,fy);

        sx+=6;
        fx=sx*WIDE;
        lineto(fx,fy);
    }

    sy-=9;
    fy=sy*WIDE;
    lineto(fx,fy);

    for(ra=0;ra<(points-1);ra++)
    {
        sx-=6;
        fx=sx*WIDE;
        lineto(fx,fy);

        sy-=6;
        fy=sy*WIDE;
        lineto(fx,fy);
    }

    sx-=9;
    fx=sx*WIDE;
    lineto(fx,fy);


    stroke();

}



int dome ( int points )
{


    char xstring[40];
    unsigned int ra;
    unsigned int rb;
    unsigned int rc;
    unsigned int rx;
    unsigned int ry;
    unsigned int xx,yy;

    if(points<3) return(1);

    elements=0;

    sprintf(xstring,"hello%05d.ps",points);
    fprintf(stderr,"%s\n",xstring);
    fp=fopen(xstring,"wt");
    if(fp==NULL)
    {
        fprintf(stderr,"Error creating file [%s]\n",xstring);
        exit(1);
    }

    fprintf(fpbatch,"echo hello%05d.ps\n",points);
    fprintf(fpbatch,"ps2pdf hello%05d.ps\n",points);
    fprintf(fpbatch,"pdf2svg hello%05d.pdf hello%05d.svg\n",points,points);

    minx=1000;
    miny=1000;
    maxx=-100;
    maxy=-1000;


    ra=(points-1)*6;
    ra*=2;
    ra+=9;
    ra*=WIDE;
    ra+=20;


if(ANGLED)
{

    middle=((points-1)*6)+4;
    middle+=0.5F;

    goback=points*5;

}





    fprintf(fp,"%%!\n");
    fprintf(fp,"%%BoundingBox: 0 0 %u %u\n",ra,ra);
//}
//if(ANGLED)
//{
    //fprintf(fp,"<< /PageSize [490 490] >> setpagedevice\n");
////    fprintf(fp,"<< /PageSize [70 70] >> setpagedevice\n");
//}
//else
//{
    fprintf(fp,"<< /PageSize [%u %u] >> setpagedevice\n",ra,ra);
//}
    fprintf(fp,"1.0 setlinewidth\n");
    fprintf(fp,"0.0 setgray\n");




    xx=((points-1)*6)+3;
    yy=3;
    rx=xx;
    ry=yy;
    rc=1;
    for(ra=0;ra<points;ra++)
    {
        rx=xx;
        ry=yy;
        for(rb=0;rb<rc;rb++)
        {
            cut_square(rx,ry);
            rx+=6;
        }
        rc+=2;
        xx-=6;
        yy+=6;
    }
    xx+=12;
    rc-=4;
    for(ra=1;ra<points;ra++)
    {
        rx=xx;
        ry=yy;
        for(rb=0;rb<rc;rb++)
        {
            cut_square(rx,ry);
            rx+=6;
        }
        rc-=2;
        xx+=6;
        yy+=6;
    }



    rb=points-2;
    rx=(rb*6)+1;
    ry=7;
    for(ra=0;ra<rb;ra++)
    {
        cut_bl(rx,ry); //bottom left box
        rx-=6;
        ry+=6;
    }


    rb=points-2;
    rx=(points*6)+7;
    ry=7;
    for(ra=0;ra<rb;ra++)
    {
        cut_br(rx,ry); //bottom right box
        rx+=6;
        ry+=6;
    }

    rb=points-2;
    rx=7;
    ry=(points*6)+7;
    for(ra=0;ra<rb;ra++)
    {
        cut_tl(rx,ry); //top left box
        rx+=6;
        ry+=6;
    }

    rb=points-2;
    rx=((points-1)*6)+8+5;
    ry=(((points-1)*6)*2)+8-7;
    for(ra=0;ra<rb;ra++)
    {
        cut_tr(rx,ry);
        rx+=6;
        ry-=6;
    }


    rb=points-2;
    xx=(points*6)-3;
    yy=13;
    for(rc=0;rc<(rb+1);rc++)
    {
        rx=xx;
        ry=yy;
        for(ra=0;ra<rb;ra++)
        {
            cut_horizontal(rx,ry);
            rx+=6;
            ry+=6;
        }
        xx-=6;
        yy+=6;
    }

    xx=((points-1)*6)+1;
    yy=9;
    for(rc=0;rc<(points-2);rc++)
    {
        rx=xx;
        ry=yy;
        for(ra=0;ra<(points-1);ra++)
        {
            cut_vertical(rx,ry);
            rx+=6;
            ry+=6;
        }
        xx-=6;
        yy+=6;
    }


    rx=((points-1)*6)+1;
    ry=5;
    cut_b(rx,ry); //upper left


    rx=((points-1)*6)+1;
    ry=(((points-1)+(points-3))*6)+8+1;
    cut_t(rx,ry); //lower left box

    rx=11;
    ry=((points-1)*6)+1;
    cut_l(rx,ry); //lower right box

    rx=(((points-1)+(points-3))*6)+8+1;
    ry=(points*6)+1;
    cut_r(rx,ry); //upper left box

    cut_out(points);

    fprintf(fp,"showpage\n");

    fprintf(fp,"%%minmax x %f %f\n",minx,maxx);
    fprintf(fp,"%%minmax y %f %f\n",miny,maxy);
    fprintf(stderr,"minmax x %f %f\n",minx,maxx);
    fprintf(stderr,"minmax y %f %f\n",miny,maxy);

    fprintf(fp,"%%elements %u\n",elements);
    fprintf(stderr,"elements %u\n",elements);
/*

ps2pdf hello.ps
pdf2svg hello.pdf hello.svg


inkscape --export-type=dxf --export-extension=org.ekips.output.dxf_outlines hello.svg


ps2pdf angled.ps
pdf2svg angled.pdf angled.svg
inkscape --export-type=dxf --export-extension=org.ekips.output.dxf_outlines angled.svg


To draw a circle or an arc, use the "arc" command. You must specify the center, radius, and starting and ending angles (in degrees). Also, if you are drawing a circle, you should end with "closepath" in order to join the two ends of the arc. This becomes more important when you're filling the circles but it's a good habit to get into.

So, a typical circle command looks like:

        4 5 3 0 360 arc closepath
        stroke












*/
    fclose(fp);
    return(0);
}


int main ( void )
{
    unsigned int ra;

    fpbatch=fopen("go.bat","wt");
    if(fpbatch==NULL)
    {
        fprintf(stderr,"error creating file\n");
        return(1);
    }

    for(ra=3;ra<10;ra++)
    {
        dome(ra);
    }
    for(ra=10;ra<=100;ra+=10)
    {
        dome(ra);
    }
    //for(ra=10;ra<100;ra+=10)
    //{
        //dome(ra);
    //}
    //for(ra=100;ra<=1000;ra+=100)
    //{
        //dome(ra);
    //}
    //dome(5);
    //dome(6);
    //dome(100);
    //dome(1000);
    fclose(fpbatch);

    return(0);
}



