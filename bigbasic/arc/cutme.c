
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



int dome ( int points )
{


    char xstring[40];
    unsigned int ra;
    unsigned int rb;
    unsigned int rc;
    unsigned int rx;
    unsigned int ry;
    unsigned int xx,yy;

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

    //double dx;
    //double dy;
    //dx=((points-2)*6)-1;
    //dx=dx*dx;
    //dx=dx+dx;
    //dx=sqrt(dx);
    //goback=dx+0.5;
    //goback++;
    //fprintf(stderr,"goback %u\n",goback);
    goback=points*5;



    //dy=(points*6)+2;
    //dy=dy*dy;
    //dy=dy+dy;
    //dy=sqrt(dy);
    //fprintf(stderr,"wide %f\n",dy);
    //dy=dy+40;
    //dy*=WIDE;
    //ra=dy;

}





    fprintf(fp,"%%!\n");
//if(ANGLED)
//{
////    fprintf(fp,"%%BoundingBox: 0 0 330 330\n");
////    fprintf(fp,"%%BoundingBox: 0 0 490 490\n");
    //fprintf(fp,"%%BoundingBox: 0 0 %u %u\n",ra,ra);
//}
//else
//{
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
            if((rb==0)&&(ra==0))
            {
                cut_square_b(rx,ry);
            }
            else
            if((rb==0)&&(ra==(points-1)))
            {
                cut_square_l(rx,ry);
            }
            else
            if((rb==(rc-1))&&(ra==(points-1)))
            {
                cut_square_r(rx,ry);
            }
            else
            if(rb==0)
            {
                cut_square_bl(rx,ry);
            }
            else
            if(rb==(rc-1))
            {
                cut_square_br(rx,ry);
            }
            else
            {
                cut_square(rx,ry);
            }
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
            if(ra==(points-1))
            {
                cut_square_t(rx,ry);
            }
            else
            if(rb==0)
            {
                cut_square_tl(rx,ry);
            }
            else
            if(rb==(rc-1))
            {
                cut_square_tr(rx,ry);
            }
            else
            {
                cut_square(rx,ry);
            }
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
        cut_bl(rx,ry); //corner
        rx-=6;
        ry+=6;
    }


    rb=points-2;
    rx=(points*6)+7;
    ry=7;
    for(ra=0;ra<rb;ra++)
    {
        cut_br(rx,ry); //corner
        rx+=6;
        ry+=6;
    }

    rb=points-2;
    rx=7;
    ry=(points*6)+7;
    for(ra=0;ra<rb;ra++)
    {
        cut_tl(rx,ry); //corner
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


    rx=(points*6)+1;
    ry=11;
    cut_b(rx,ry); //long leg

    rx=((points-1)*6)+1;
    ry=(((points-1)+(points-3))*6)+8+1;
    cut_t(rx,ry); //long leg

    rx=11;
    ry=((points-1)*6)+1;
    cut_l(rx,ry); //long leg

    rx=(((points-1)+(points-3))*6)+8+1;
    ry=(points*6)+1;
    cut_r(rx,ry); //long leg

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



