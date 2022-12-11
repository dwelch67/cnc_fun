

#include <stdio.h>
#include <math.h>

#define DELTA 10
#define WIDE 10

double degrad = M_PI / 180.0;
double raddeg = 180.0 / M_PI;


float minx,maxx;
float miny,maxy;
void moveto ( float x, float y )
{
    if(x<minx) minx=x;
    if(x>maxx) maxx=x;
    if(y<miny) miny=y;
    if(y>maxy) maxy=y;


    printf("%f %f moveto\n",x,y);
}
void lineto ( float x, float y )
{
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




//void doline (
    //unsigned int rax,
    //unsigned int ray,
    //unsigned int rbx,
    //unsigned int rby
//)
//{

    //printf("%u %u moveto\n",rax,ray);
    //printf("%u %u lineto\n",rbx,rby);
    //printf("stroke\n");

//}



//void do_circle ( float fx, float fy, float rad )
//{
    //fx=fx+1;
    //fy=fy+1;


    //fx=fx*STEP;
    //fy=fy*STEP;

    //rad=rad*STEP;
    //printf("%f %f moveto\n",fx+rad,fy);
    //printf("%f %f %f 0 360 arc\n",fx,fy,rad);
    //printf("stroke\n");
//}

//double degrad = M_PI / 180.0;
//double raddeg = 180.0 / M_PI;

//void do_arc ( float fx, float fy, float rad, float a, float b )
//{
    //float sx,sy;

    //fx=fx+1;
    //fy=fy+1;

    //fx=fx*STEP;
    //fy=fy*STEP;
    //rad=rad*STEP;

    //sx=(cos(a*degrad)*rad)+fx;
    //sy=(sin(a*degrad)*rad)+fy;


////fprintf(stderr,"fx fy sx sy %f %f %f %f\n",fx,fy,sx,sy);


    //printf("%f %f moveto\n",sx,sy);
    //printf("%f %f %f %f %f arc\n",fx,fy,rad,a,b);
    //printf("stroke\n");
//}




int main ( void )
{
    unsigned int ra;
    unsigned int rax,ray;
    unsigned int rbx,rby;

    unsigned int rb;
    unsigned int flag;
    unsigned int rc;

    float fx,fy;
    float sx,sy;
    float fad,fbd;
    float theangle;
    float rad;
    float fa;
    float fb;
    float xx,yy;

    float aa,mm;


    minx=1000;
    miny=1000;
    maxx=-100;
    maxy=-1000;


    printf("%%!\n");
    printf("0.0 setgray\n");
    printf("0.01 setlinewidth\n");



    theangle=60*degrad;

    xx=20;
    yy=20;
    fb=30*degrad;
    for(rc=0;rc<35;rc++)
    {
        fx=xx;
        fy=yy;
        for(rb=0;rb<35;rb++)
        {
            rad=WIDE;
            fa=0;
            for(ra=0;ra<=6;ra++)
            {
                sx=fx+(cos(fa)*rad);
                sy=fy+(sin(fa)*rad);
                if(ra)
                {
                    lineto(sx,sy);
                }
                else
                {
                    moveto(sx,sy);
                }
                fa+=theangle;
            }
            stroke();
            fy+=WIDE*2;
        }
        xx+=((cos(fb)*WIDE)*2);
        if(rc&1)
        {
            yy-=((sin(fb)*WIDE)*2);
        }
        else
        {
            yy+=((sin(fb)*WIDE)*2);
        }
    }


    //fx=20;
    //fy=20;
    //for(rb=0;rb<10;rb++)
    //{
        //rad=WIDE;
        //fa=0;
        //for(ra=0;ra<=6;ra++)
        //{
            //sx=fx+(cos(fa)*rad);
            //sy=fy+(sin(fa)*rad);
            //if(ra)
            //{
                //lineto(sx,sy);
            //}
            //else
            //{
                //moveto(sx,sy);
            //}
            //fa+=theangle;
        //}
        //stroke();
        //fy+=WIDE*2;
    //}



    //fb=30*degrad;
    //for(rb=0;rb<6;rb++)
    //{
        //fx=100+((cos(fb)*WIDE)*2);
        //fy=100+((sin(fb)*WIDE)*2);
        //fb+=theangle;
        //rad=WIDE;
        //fa=0;
        //for(ra=0;ra<=6;ra++)
        //{
            //sx=fx+(cos(fa)*rad);
            //sy=fy+(sin(fa)*rad);
            //if(ra)
            //{
                //lineto(sx,sy);
            //}
            //else
            //{
                //moveto(sx,sy);
            //}
            //fa+=theangle;
        //}
        //stroke();
    //}


    //fb=30*degrad;
    //for(rb=0;rb<6;rb++)
    //{
        //fx=100+((cos(fb)*WIDE)*4);
        //fy=100+((sin(fb)*WIDE)*4);
        //fb+=theangle;
        //rad=WIDE;
        //fa=0;
        //for(ra=0;ra<=6;ra++)
        //{
            //sx=fx+(cos(fa)*rad);
            //sy=fy+(sin(fa)*rad);
            //if(ra)
            //{
                //lineto(sx,sy);
            //}
            //else
            //{
                //moveto(sx,sy);
            //}
            //fa+=theangle;
        //}
        //stroke();
    //}

    //mm=2*sqrt(3);


    //fb=0*degrad;
    //for(rb=0;rb<6;rb++)
    //{
        //fx=100+((cos(fb)*WIDE)*mm);
        //fy=100+((sin(fb)*WIDE)*mm);
        //fb+=theangle;
        //rad=WIDE;
        //fa=0;
        //for(ra=0;ra<=6;ra++)
        //{
            //sx=fx+(cos(fa)*rad);
            //sy=fy+(sin(fa)*rad);
            //if(ra)
            //{
                //lineto(sx,sy);
            //}
            //else
            //{
                //moveto(sx,sy);
            //}
            //fa+=theangle;
        //}
        //stroke();
    //}


    //fb=30*degrad;
    //for(rb=0;rb<6;rb++)
    //{
        //fx=100+((cos(fb)*WIDE)*6);
        //fy=100+((sin(fb)*WIDE)*6);
        //fb+=theangle;
        //rad=WIDE;
        //fa=0;
        //for(ra=0;ra<=6;ra++)
        //{
            //sx=fx+(cos(fa)*rad);
            //sy=fy+(sin(fa)*rad);
            //if(ra)
            //{
                //lineto(sx,sy);
            //}
            //else
            //{
                //moveto(sx,sy);
            //}
            //fa+=theangle;
        //}
        //stroke();
    //}



    //fb=0;
    //for(rb=0;rb<6;rb++)
    //{
        //fx=100+((cos(fb)*(WIDE+5)));
        //fy=100+((sin(fb)*(WIDE+5)));
        //fb+=theangle;
        //rad=WIDE;
        //fa=0;
        //for(ra=0;ra<=6;ra++)
        //{
            //sx=fx+(cos(fa)*rad);
            //sy=fy+(sin(fa)*rad);
            //if(ra)
            //{
                //lineto(sx,sy);
            //}
            //else
            //{
                //moveto(sx,sy);
            //}
            //fa+=theangle;
        //}
        //stroke();
    //}





    printf("showpage\n");

    fprintf(stderr,"minmax x %f %f\n",minx,maxx);
    fprintf(stderr,"minmax y %f %f\n",miny,maxy);


    return(0);
}
