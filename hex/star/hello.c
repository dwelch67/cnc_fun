

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
void closepath ( void )
{
    printf("closepath\n");
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

    float fx,fy;
    float sx,sy;
    float px,py;
    float mx,my;
    float mm;
    float fad,fbd;
    float theangle;
    float rad;
    float fa;
    float fb;
    float aa;


    minx=1000;
    miny=1000;
    maxx=-100;
    maxy=-1000;


    printf("%%!\n");
    printf("0.0 setgray\n");
    printf("8.0 setlinewidth\n");



    theangle=60*degrad;



    fx=300;
    fy=300;
    rad=100;
    
    aa=50/(sqrt(3));
    mm=aa*2;

    fa=0;
    for(ra=0;ra<=6;ra++)
    {
        sx=fx+(cos(fa)*rad);
        sy=fy+(sin(fa)*rad);
        mx=fx+(cos(fa+(theangle/2))*mm);
        my=fy+(sin(fa+(theangle/2))*mm);
        px=fx+(cos(fa+theangle)*rad);
        py=fy+(sin(fa+theangle)*rad);
        moveto(fx,fy);
        lineto(sx,sy);
        lineto(mx,my);
        closepath();
        stroke();


        moveto(fx,fy);
        lineto(mx,my);
        lineto(px,py);
        closepath();
        stroke();



        //moveto(sx,sy);
        //lineto(px,py);
        //lineto(mx,my);
        //closepath();
        //stroke();


        
        fa+=theangle;
    }





    printf("showpage\n");

    fprintf(stderr,"minmax x %f %f\n",minx,maxx);
    fprintf(stderr,"minmax y %f %f\n",miny,maxy);


    return(0);
}
