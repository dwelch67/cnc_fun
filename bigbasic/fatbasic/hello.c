

#include <stdio.h>
#include <math.h>


FILE *fp;
FILE *fpbatch;


void doline (
    unsigned int rax,
    unsigned int ray,
    unsigned int rbx,
    unsigned int rby
)
{

    fprintf(fp,"%u %u moveto\n",rax,ray);
    fprintf(fp,"%u %u lineto\n",rbx,rby);
    fprintf(fp,"stroke\n");

}

#define STEP 20
#define WIDE STEP


void do_circle ( double fx, double fy, double rad )
{
    fx=fx*STEP;
    fy=fy*STEP;
    rad=rad*STEP;
    fprintf(fp,"%lf %lf moveto\n",fx+rad,fy);
    fprintf(fp,"%lf %lf %lf 0 360 arc\n",fx,fy,rad);
    fprintf(fp,"stroke\n");
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


    fprintf(fp,"%lf %lf moveto\n",sx,sy);
    fprintf(fp,"%lf %lf %lf %lf %lf arc\n",fx,fy,rad,a,b);
    fprintf(fp,"stroke\n");
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


    fprintf(fp,"%f %f moveto\n",x,y);
}
void lineto ( float x, float y )
{

    x+=10;
    y+=10;

    fprintf(fp,"%f %f lineto\n",x,y);
}
void stroke ( void )
{
    fprintf(fp,"stroke\n");
}
void closepath ( void )
{
    fprintf(fp,"closepath\n");
}
void arc ( float x, float y, float rad, float a, float b )
{

    x+=10;
    y+=10;

    fprintf(fp,"%f %f %f %f %f arc\n",x,y,rad,a,b);
}
void arcn ( float x, float y, float rad, float a, float b )
{

    x+=10;
    y+=10;

    fprintf(fp,"%f %f %f %f %f arcn\n",x,y,rad,a,b);
}


void cut_horizontal ( float x, float y, float xx)
{
    float sx,sy;
    float fx,fy;

    //elements++;
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

    //elements++;
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

    //elements++;
    fprintf(fp,"%%cut_square(%d,%d);\n",x,y);

    sx=x;
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

    sy=y;
    fy=sy*WIDE;
    lineto(fx,fy);

    closepath();

    stroke();

}



void cut_arc ( float x, float y, float rad, float a, float b)
{
    float fx,fy;
    float sx,sy;

    //elements++;
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


void cut_sarc ( float x, float y, float rad, float a, float b)
{
    float fx,fy;
    float sx,sy;

    //elements++;
    fprintf(fp,"%%cut_sarc(%f,%f,%f,%f,%f);\n",x,y,rad,a,b);
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


void cut_out ( int points )
{
    float fx,fy;
    float sx,sy;

    unsigned int ra;
    unsigned int rb;
    unsigned int rc;
    unsigned int rd;
    unsigned int rx;
    unsigned int ry;

    fprintf(fp,"%%cut_out();\n");

    rb=points*4;
    rx=rb-3;
    ry=1;
    fx=rx*WIDE;
    fy=ry*WIDE;
    moveto(fx,fy);
    for(ra=0;ra<(points-1);ra++)
    {
        ry+=4;
        fy=ry*WIDE;
        lineto(fx,fy);
        rx-=4;
        fx=rx*WIDE;
        lineto(fx,fy);
    }

	ry+=7;
	fy=ry*WIDE;
	lineto(fx,fy);

    for(ra=0;ra<(points-1);ra++)
    {
        rx+=4;
        fx=rx*WIDE;
        lineto(fx,fy);
        ry+=4;
        fy=ry*WIDE;
        lineto(fx,fy);
    }

	rx+=7;
	fx=rx*WIDE;
	lineto(fx,fy);

    for(ra=0;ra<(points-1);ra++)
    {
        ry-=4;
        fy=ry*WIDE;
        lineto(fx,fy);
        rx+=4;
        fx=rx*WIDE;
        lineto(fx,fy);
    }


	ry-=7;
	fy=ry*WIDE;
	lineto(fx,fy);

    for(ra=0;ra<(points-1);ra++)
    {
        rx-=4;
        fx=rx*WIDE;
        lineto(fx,fy);
        ry-=4;
        fy=ry*WIDE;
        lineto(fx,fy);
    }

	closepath();

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



int dome ( int points )
{


    char xstring[40];
    unsigned int ra;
    unsigned int rb;
    unsigned int rc;
    unsigned int rd;
    unsigned int rx;
    unsigned int ry;
    unsigned int xx,yy;

    if(points<3) return(1);

    sprintf(xstring,"hello%d.ps",points);
    fprintf(stderr,"%s\n",xstring);
    fp=fopen(xstring,"wt");
    if(fp==NULL)
    {
        fprintf(stderr,"Error creating file [%s]\n",xstring);
        exit(1);
    }

    fprintf(fpbatch,"echo hello%d.ps\n",points);
    fprintf(fpbatch,"ps2pdf hello%d.ps\n",points);
    fprintf(fpbatch,"pdf2svg hello%d.pdf hello%d.svg\n",points,points);



    fprintf(fp,"%%!\n");
    fprintf(fp,"0.0 setgray\n");
    fprintf(fp,"0.1 setlinewidth\n");

    //if(1)
    //{
        //for(rb=STEP;rb<600;rb+=STEP)
        //for(ra=STEP;ra<600;ra+=STEP)
        //{
            ////horizontal
            //flag=1;

            //if(ra==(STEP*(28+1))) flag++;
            //if(ra==(STEP*(29+1))) flag++;
            //if(ra==(STEP*(30+1))) flag++;
            //if(ra==(STEP*(31+1))) flag++;


            //if(flag)
            //{
                //rax=STEP;
                //rbx=rb;
                //ray=ra;
                //rby=ra;
                //doline(rax,ray,rbx,rby);
            //}

            ////vertical
            //flag=1;

            //if(ra==(STEP*(28+1))) flag++;
            //if(ra==(STEP*(29+1))) flag++;
            //if(ra==(STEP*(30+1))) flag++;
            //if(ra==(STEP*(31+1))) flag++;
            //if(flag)
            //{
                //rax=ra;
                //rbx=ra;
                //ray=STEP;
                //rby=rb;
                //doline(rax,ray,rbx,rby);
            //}

        //}
    //}

//if(1)
//{

    //fprintf(fp,"/Courier-Bold findfont 8 scalefont setfont\n");
    //for(ra=0;ra<57;ra++)
    //{
    //fprintf(fp,"%u %u moveto (%u) show\n",(ra*STEP)+STEP,STEP+3,ra);
    //if(ra)
    //fprintf(fp,"%u %u moveto (%u) show\n",STEP,(ra*STEP)+STEP+3,ra);
    //}
//}


    rd=1;
    for(ra=0;ra<points;ra++)
    {
        for(rb=0;rb<rd;rb++)
        {
            cut_square((points-ra+rb)*4,(ra+1)*4);
        }
        rd+=2;
    }
    rd-=2;
    for(ra=1;ra<points;ra++)
    {
        rd-=2;
        for(rb=0;rb<rd;rb++)
        {
            cut_square((ra+rb+1)*4,(points+ra)*4);
        }
    }




    for(ra=0;ra<points;ra++)
    {
        rx=((points-ra)*4)-2;
        ry=((ra+1)*4)-2;
        if(ra) rc=7; else rc=5;
        cut_horizontal(rx,ry,rc);
    }

    for(ra=0;ra<(points-1);ra++)
    {
        rx=((points-ra)*4)-2;
        ry=((ra+1)*4)-2;
        rc=3;
        cut_vertical(rx,ry,rc);
    }


    for(rb=0;rb<(points-1);rb++)
    {
        for(ra=1;ra<(points-1);ra++)
        {
            rx=((points-ra+rb)*4)+2;
            ry=((ra+1+rb)*4);
            rc=5;
            cut_vertical(rx,ry,rc);
        }
    }


    for(rb=1;rb<(points-1);rb++)
    {
        for(ra=0;ra<(points-1);ra++)
        {
            rx=((points-ra+rb-1)*4);
            ry=((ra+1+rb)*4)+2;
            rc=5;
            cut_horizontal(rx,ry,rc);
        }
    }

    rb=points*4;
    for(ra=0;ra<points;ra++)
    {
        rx=((ra)*4)+2;
        ry=rb+((ra-1)*4);
        rc=7;
        if(ra==0)
        {
            ry+=2;
            rc-=2;
        }
        cut_vertical(rx,ry,rc);
    }


    rb=points*4;
    for(ra=0;ra<points;ra++)
    {
        rx=((ra)*4)+2;
        ry=rb+((ra-1)*4);
        rc=7;
        if(ra==0)
        {
            ry+=2;
            rc-=2;
        }
        ry+=rc-1;
        rc=3;
        if((ra+1)==points) rc=5;
        cut_horizontal(rx,ry,rc);
    }



    rb=points*4;
    for(ra=1;ra<(points);ra++)
    {
        rx=rb+((ra)*4);
        ry=((ra+1)*4)-2;
        rc=3;
        cut_horizontal(rx,ry,rc);
    }

    rb=points*4;
    for(ra=0;ra<(points);ra++)
    {
        rx=rb+((ra)*4);
        ry=((ra+1)*4)-2;
        rc=3;
        rx+=rc-1;
        rc=7;
        if((ra+1)==points) rc=5;
        cut_vertical(rx,ry,rc);
    }

    rb=points*4;
    for(ra=1;ra<(points);ra++)
    {
        rx=rb+((points-ra-1)*4)+2;
        ry=rb+((ra)*4);
        rc=3;
        cut_vertical(rx,ry,rc);
    }


    rb=points*4;
    for(ra=1;ra<(points);ra++)
    {
        rx=rb+((ra-1)*4);
        ry=rb+((points-ra)*4)-2;
        rc=7;
        cut_horizontal(rx,ry,rc);
    }



    cut_out(points);

    //fprintf(fp,"1.0 setlinewidth\n");
    //cut_math();

    fprintf(fp,"showpage\n");
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

    for(ra=3;ra<6;ra++)
    {
        dome(ra);
    }
    fclose(fpbatch);

    return(0);
}
















