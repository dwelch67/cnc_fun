

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


FILE *fp;

#define STEP 40


void do_line ( float ax, float ay, float bx,float by )
{
    ax=ax+1;
    ay=ay+1;
    bx=bx+1;
    by=by+1;
    
    
    ax=ax*STEP;
    ay=ay*STEP;
    bx=bx*STEP;
    by=by*STEP;
    
    fprintf(fp,"%f %f moveto\n",ax,ay);
    fprintf(fp,"%f %f lineto\n",bx,by);
    fprintf(fp,"stroke\n");
}

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


    for(ri=1;ri<7;ri++)
    for(rj=9;rj<13;rj++)
    {
        sprintf(xstring,"hello_%u_%02u.ps",ri,rj);
        fp=fopen(xstring,"wt");
        if(fp==NULL)
        {
            printf("error creating file %s\n",xstring);
            return(1);
        }
        //ii=ri;
        //jj=rj;
    



        fprintf(fp,"%%!\n");
        fprintf(fp,"0.0 setgray\n");
        fprintf(fp,"0.1 setlinewidth\n");




        //do_line(0,0,ri+rj,0);
        //do_line(0,1,ri+rj,1);
        //do_line(0,2,ri+rj,2);
        //do_line(0,3,ri+rj,3);

        do_line(0,0,ri,0);
        do_line(0,1,ri,1);
        do_line(0,2,ri,2);
        do_line(0,3,ri,3);


        do_line(rj,0,rj+ri,0);
        do_line(rj,1,rj+ri,1);
        do_line(rj,2,rj+ri,2);
        do_line(rj,3,rj+ri,3);



        //do_line(0,0,0,ri+rj);
        //do_line(1,0,1,ri+rj);
        //do_line(2,0,2,ri+rj);
        //do_line(3,0,3,ri+rj);

        do_line(0,0,0,ri);
        do_line(1,0,1,ri);
        do_line(2,0,2,ri);
        do_line(3,0,3,ri);

        do_line(0,rj,0,ri+rj);
        do_line(1,rj,1,ri+rj);
        do_line(2,rj,2,ri+rj);
        do_line(3,rj,3,ri+rj);



        //do_line(0,ri+rj-0,ri+rj,ri+rj-0);
        //do_line(0,ri+rj-1,ri+rj,ri+rj-1);
        //do_line(0,ri+rj-2,ri+rj,ri+rj-2);
        //do_line(0,ri+rj-3,ri+rj,ri+rj-3);

        do_line(0,ri+rj-0,ri,ri+rj-0);
        do_line(0,ri+rj-1,ri,ri+rj-1);
        do_line(0,ri+rj-2,ri,ri+rj-2);
        do_line(0,ri+rj-3,ri,ri+rj-3);

        do_line(rj,ri+rj-0,ri+rj,ri+rj-0);
        do_line(rj,ri+rj-1,ri+rj,ri+rj-1);
        do_line(rj,ri+rj-2,ri+rj,ri+rj-2);
        do_line(rj,ri+rj-3,ri+rj,ri+rj-3);

        //do_line(ri+rj-0,0,ri+rj-0,ri+rj);
        //do_line(ri+rj-1,0,ri+rj-1,ri+rj);
        //do_line(ri+rj-2,0,ri+rj-2,ri+rj);
        //do_line(ri+rj-3,0,ri+rj-3,ri+rj);

        do_line(ri+rj-0,0,ri+rj-0,ri);
        do_line(ri+rj-1,0,ri+rj-1,ri);
        do_line(ri+rj-2,0,ri+rj-2,ri);
        do_line(ri+rj-3,0,ri+rj-3,ri);

        do_line(ri+rj-0,rj,ri+rj-0,ri+rj);
        do_line(ri+rj-1,rj,ri+rj-1,ri+rj);
        do_line(ri+rj-2,rj,ri+rj-2,ri+rj);
        do_line(ri+rj-3,rj,ri+rj-3,ri+rj);








        do_line(ri+rj+1,0,ri+rj+1,ri+rj+1);

        do_line(0,ri+rj+1,ri+rj+1,ri+rj+1);



        do_arc(ri,ri,rj-0,0,90);
        do_arc(ri,ri,rj-1,0,90);
        do_arc(ri,ri,rj-2,0,90);
        do_arc(ri,ri,rj-3,0,90);

        do_arc(rj,ri,rj-0,90,180);
        do_arc(rj,ri,rj-1,90,180);
        do_arc(rj,ri,rj-2,90,180);
        do_arc(rj,ri,rj-3,90,180);


        do_arc(rj,rj,rj-0,180,270);
        do_arc(rj,rj,rj-1,180,270);
        do_arc(rj,rj,rj-2,180,270);
        do_arc(rj,rj,rj-3,180,270);


        do_arc(ri,rj,rj-0,270,0);
        do_arc(ri,rj,rj-1,270,0);
        do_arc(ri,rj,rj-2,270,0);
        do_arc(ri,rj,rj-3,270,0);




		

if(0)
{
        do_line(0,0,ri+rj+ri,0);
        do_line(0,1,ri+rj+ri,1);
        do_line(0,2,ri+rj+ri,2);
        do_line(0,3,ri+rj+ri,3);
        
        
        do_line(0,0,0,ri+rj+ri);
        do_line(1,0,1,ri+rj+ri);
        do_line(2,0,2,ri+rj+ri);
        do_line(3,0,3,ri+rj+ri);

        do_line(0,ri+rj+ri-0,ri+rj+ri,ri+rj+ri-0);
        do_line(0,ri+rj+ri-1,ri+rj+ri,ri+rj+ri-1);
        do_line(0,ri+rj+ri-2,ri+rj+ri,ri+rj+ri-2);
        do_line(0,ri+rj+ri-3,ri+rj+ri,ri+rj+ri-3);

        do_line(ri+rj+ri-0,0,ri+rj+ri-0,ri+rj+ri);
        do_line(ri+rj+ri-1,0,ri+rj+ri-1,ri+rj+ri);
        do_line(ri+rj+ri-2,0,ri+rj+ri-2,ri+rj+ri);
        do_line(ri+rj+ri-3,0,ri+rj+ri-3,ri+rj+ri);




        do_arc(ri,ri,rj-0,0,360);
}

		
        //do_arc(0,0,rj-1,0,360);
        //do_arc(0,0,rj-2,0,360);
        //do_arc(0,0,rj-3,0,360);

        //do_arc(rj,0,rj-0,0,360);
        //do_arc(rj,0,rj-1,0,360);
        //do_arc(rj,0,rj-2,0,360);
        //do_arc(rj,0,rj-3,0,360);

        //do_arc(0,rj,rj-0,0,360);
        //do_arc(0,rj,rj-1,0,360);
        //do_arc(0,rj,rj-2,0,360);
        //do_arc(0,rj,rj-3,0,360);

        //do_arc(rj,rj,rj-0,0,360);
        //do_arc(rj,rj,rj-1,0,360);
        //do_arc(rj,rj,rj-2,0,360);
        //do_arc(rj,rj,rj-3,0,360);

        fprintf(fp,"showpage\n");
        
        fclose(fp);
    

    }
    return(0);
}
