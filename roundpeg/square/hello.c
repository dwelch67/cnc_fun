

#include <stdio.h>
#include <math.h>

#define DELTA 20

#define STEP 10

void doline (
    unsigned int rax,
    unsigned int ray,
    unsigned int rbx,
    unsigned int rby
)
{

    printf("%u %u moveto\n",rax,ray);
    printf("%u %u lineto\n",rbx,rby);
    printf("stroke\n");

}

void do_circle ( double fx, double fy, double rad )
{
    fx=fx;
    fy=fy;
    rad=rad;
    printf("%lf %lf moveto\n",fx+rad,fy);
    printf("%lf %lf %lf 0 360 arc\n",fx,fy,rad);
    printf("stroke\n");
}

double degrad = M_PI / 180.0;
double raddeg = 180.0 / M_PI;

void do_arc ( double fx, double fy, double rad, double a, double b )
{
    double sx,sy;
    
    fx=fx;
    fy=fy;
    rad=rad;
    
    sx=(cos(a*degrad)*rad)+fx;
    sy=(sin(a*degrad)*rad)+fy;


//fprintf(stderr,"fx fy sx sy %lf %lf %lf %lf\n",fx,fy,sx,sy);
    
    
    printf("%lf %lf moveto\n",sx,sy);
    printf("%lf %lf %lf %lf %lf arc\n",fx,fy,rad,a,b);
    printf("stroke\n");
}




int main ( void )
{
    unsigned int ra;
    unsigned int rax,ray;
    unsigned int rbx,rby;
    
    unsigned int rb;
    unsigned int flag;
    
    //double fx,fy;
    //double zz;
    //double xx;
    double rr;
	double jj;
    //double sx,sy;
    //double bx,by;
    


    printf("%%!\n");
    printf("0.0 setgray\n");
    printf("0.1 setlinewidth\n");

    if(0)
    {
        for(rb=STEP;rb<600;rb+=STEP)
        for(ra=STEP;ra<600;ra+=STEP)
        {
            //horizontal
            flag=1;

            if(ra==(STEP*(28+1))) flag++;
            if(ra==(STEP*(29+1))) flag++;
            if(ra==(STEP*(30+1))) flag++;
            if(ra==(STEP*(31+1))) flag++;

            
            if(flag)
            {
                rax=STEP;
                rbx=rb;
                ray=ra;
                rby=ra;
                doline(rax,ray,rbx,rby);
            }

            //vertical
            flag=1;
            
            if(ra==(STEP*(28+1))) flag++;
            if(ra==(STEP*(29+1))) flag++;
            if(ra==(STEP*(30+1))) flag++;
            if(ra==(STEP*(31+1))) flag++;
            if(flag)
            {
                rax=ra;
                rbx=ra;
                ray=STEP;
                rby=rb;
                doline(rax,ray,rbx,rby);
            }

        }
    }

if(0)
{

    printf("/Courier-Bold findfont 8 scalefont setfont\n");
    for(ra=0;ra<57;ra++)
    {
    printf("%u %u moveto (%u) show\n",(ra)+STEP,STEP+3,ra);
    if(ra)
    printf("%u %u moveto (%u) show\n",STEP,(ra)+STEP+3,ra);
    }
}

rr=120;
jj=70;

    do_arc(300,300,rr+ 0,0,360);
    do_arc(300,300,rr+10,0,360);
    do_arc(300,300,rr+20,0,360);
    do_arc(300,300,rr+30,0,360);

    do_arc(300+jj,300+jj,rr+ 0,0,360);
    do_arc(300+jj,300+jj,rr+10,0,360);
    do_arc(300+jj,300+jj,rr+20,0,360);
    do_arc(300+jj,300+jj,rr+30,0,360);

    do_arc(300-jj,300-jj,rr+ 0,0,360);
    do_arc(300-jj,300-jj,rr+10,0,360);
    do_arc(300-jj,300-jj,rr+20,0,360);
    do_arc(300-jj,300-jj,rr+30,0,360);


    do_arc(300+jj,300-jj,rr+ 0,0,360);
    do_arc(300+jj,300-jj,rr+10,0,360);
    do_arc(300+jj,300-jj,rr+20,0,360);
    do_arc(300+jj,300-jj,rr+30,0,360);

    do_arc(300-jj,300+jj,rr+ 0,0,360);
    do_arc(300-jj,300+jj,rr+10,0,360);
    do_arc(300-jj,300+jj,rr+20,0,360);
    do_arc(300-jj,300+jj,rr+30,0,360);














    printf("showpage\n");
    return(0);
}
