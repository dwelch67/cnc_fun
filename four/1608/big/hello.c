

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


FILE *fp;

#define STEP 10


void do_circle ( float fx, float fy, float rad )
{
    fx=fx+1;
    fy=fy+1;
    
    
    fx=fx*STEP;
    fy=fy*STEP;
    
    rad=rad*STEP;
    fprintf(fp,"%f %f moveto\n",fx+rad,fy);
    fprintf(fp,"%f %f %f 0 360 arc\n",fx,fy,rad);
    fprintf(fp,"stroke\n");
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
    
    
    fprintf(fp,"%f %f moveto\n",sx,sy);
    fprintf(fp,"%f %f %f %f %f arc\n",fx,fy,rad,a,b);
    fprintf(fp,"stroke\n");
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



ii=16;
jj=8;
//kk=8.0;

ll=30;

ri=16;
rj=8;
    //for(ri=5;ri<20;ri++)
    {
    //for(rj=5;rj<20;rj++)
    {
        sprintf(xstring,"hello_%u_%u.ps",ri,rj);
        fp=fopen(xstring,"wt");
        if(fp==NULL)
        {
            printf("error creating file %s\n",xstring);
            return(1);
        }
        ii=ri;
        jj=rj;
    



        fprintf(fp,"%%!\n");
        fprintf(fp,"0.0 setgray\n");
        fprintf(fp,"0.1 setlinewidth\n");




#define POINTS 4

        thestep=360.0/POINTS;
        thestep=thestep*degrad;
        theangle=0*degrad;
        for(ra=0;ra<POINTS;ra++)
        {
            fx=cos(theangle)*jj; fx+=ll;
            fy=sin(theangle)*jj; fy+=ll;
            do_arc(fx,fy,ii+0,0,360);
            do_arc(fx,fy,ii+1,0,360);
            do_arc(fx,fy,ii+2,0,360);
            do_arc(fx,fy,ii+3,0,360);
            theangle+=thestep;
        }

        fprintf(fp,"showpage\n");
        
        fclose(fp);
    
    }
    }
    return(0);
}
