

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


FILE *fp;

#define STEP 10


void do_hline ( float fy )
{
    fy=fy+1;
    
    fy=fy*STEP;
    
    printf("%f %f moveto\n",10.0F,fy);
    printf("%f %f lineto\n",500.0F,fy);
    printf("stroke\n");
}

void do_vline ( float fx )
{
    fx=fx+1;
    
    fx=fx*STEP;
    
    printf("%f %f moveto\n",fx,10.0F);
    printf("%f %f lineto\n",fx,500.0F);
    printf("stroke\n");
}




void do_circle ( float fx, float fy, float rad )
{
    fx=fx+1;
    fy=fy+1;
    
    
    fx=fx*STEP;
    fy=fy*STEP;
    
    rad=rad*STEP;
    printf("%f %f moveto\n",fx+rad,fy);
    printf("%f %f %f 0 360 arc\n",fx,fy,rad);
    printf("stroke\n");
}

double degrad = M_PI / 180.0;
double raddeg = 180.0 / M_PI;

void do_arc ( float fx, float fy, float rad, float a, float b )
{
    float sx,sy;

    fx=fx+1;
    fy=fy+1;
    
    fx=fx*STEP;
    fy=fy*STEP;
    rad=rad*STEP;
    
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
    unsigned int rax,ray;
    unsigned int rbx,rby;
    
    unsigned int ri,rj;
    
    unsigned int rb;
    unsigned int flag;
    
    float fx,fy;
    float fad,fbd;
    float theangle;
    float thestep;
    
    float ii,jj,kk,ll;

    char xstring[64];



ii=4;
jj=4;
//kk=8.0;

ll=30.5;



        printf("%%!\n");
        printf("0.0 setgray\n");
        printf("0.1 setlinewidth\n");

        do_vline(ll+0.5);
        do_vline(ll+1.5);
        do_vline(ll-0.5);
        do_vline(ll-1.5);
        do_hline(ll+0.5);
        do_hline(ll+1.5);
        do_hline(ll-0.5);
        do_hline(ll-1.5);


        do_arc(ll,ll,ii+0,0,360);
        do_arc(ll,ll,ii+1,0,360);
        do_arc(ll,ll,ii+2,0,360);
        do_arc(ll,ll,ii+3,0,360);

        jj=ii+2;
        for(ra=0;ra<4;ra++)
        {
            do_arc(ll,ll,ii+ra,0,360);
            do_vline(ll+(jj+ra));
            do_vline(ll-(jj+ra));
            do_hline(ll+(jj+ra));
            do_hline(ll-(jj+ra));
        }
        ii=jj+2;
        ii=ii*ii;
        ii=2*ii;
        ii=sqrt(ii);
        jj=ii+2;
        for(ra=0;ra<4;ra++)
        {
            do_arc(ll,ll,ii+ra,0,360);
            do_vline(ll+(jj+ra));
            do_vline(ll-(jj+ra));
            do_hline(ll+(jj+ra));
            do_hline(ll-(jj+ra));
        }




        printf("showpage\n");
        
    
        
    
    return(0);
}
