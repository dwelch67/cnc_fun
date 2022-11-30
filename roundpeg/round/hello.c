

#include <stdio.h>
#include <math.h>

#define DELTA 20

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

#define STEP 10


void do_circle ( double fx, double fy, double rad )
{
    fx=fx*STEP;
    fy=fy*STEP;
    rad=rad*STEP;
    printf("%lf %lf moveto\n",fx+rad,fy);
    printf("%lf %lf %lf 0 360 arc\n",fx,fy,rad);
    printf("stroke\n");
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
    
    double fx,fy;
    double zz;
	double xx;
	double rr;
	double sx,sy;
	double bx,by;
    


    printf("%%!\n");
    printf("0.0 setgray\n");
    printf("0.1 setlinewidth\n");

    if(1)
    {
        for(rb=STEP;rb<600;rb+=STEP)
        for(ra=STEP;ra<600;ra+=STEP)
        {
            //horizontal
            flag=0;

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
            flag=0;
            
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
    printf("%u %u moveto (%u) show\n",(ra*STEP)+STEP,STEP+3,ra);
    if(ra)
    printf("%u %u moveto (%u) show\n",STEP,(ra*STEP)+STEP+3,ra);
    }
}
//void arc ( float x, float y, float r, float a, float b )
//{
    //x+=OFFSET;
    //y+=OFFSET;
    //fprintf(fp,"%lf %lf %lf %lf %lf arc\n",x,y,r,a,b);
//}

xx=7.5;
rr=12.0;


    do_arc(30.5,30.5,rr+0,0,360);
    do_arc(30.5,30.5,rr+1,0,360);
    do_arc(30.5,30.5,rr+2,0,360);
    do_arc(30.5,30.5,rr+3,0,360);


//41.18 = 23
//27.5 30
//27.5-16 = 11.5;
    zz=rr+1.5;
	
	rr=rr/2;

    do_arc(30.5-zz,30.5,rr+0,180,45);
    do_arc(30.5-zz,30.5,rr+1,180,45);
    do_arc(30.5-zz,30.5,rr+2,180,45);
    do_arc(30.5-zz,30.5,rr+3,180,45);
	
    do_arc(30.5+zz,30.5,rr+0,0,180+45);
    do_arc(30.5+zz,30.5,rr+1,0,180+45);
    do_arc(30.5+zz,30.5,rr+2,0,180+45);
    do_arc(30.5+zz,30.5,rr+3,0,180+45);
	
    do_arc(30.5,30.5-zz,rr+0,45,270);
    do_arc(30.5,30.5-zz,rr+1,45,270);
    do_arc(30.5,30.5-zz,rr+2,45,270);
    do_arc(30.5,30.5-zz,rr+3,45,270);
	
    do_arc(30.5,30.5+zz,rr+0,180+45,90);
    do_arc(30.5,30.5+zz,rr+1,180+45,90);
    do_arc(30.5,30.5+zz,rr+2,180+45,90);
    do_arc(30.5,30.5+zz,rr+3,180+45,90);





    printf("showpage\n");
    return(0);
}
