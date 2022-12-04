

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



void do_line (
    unsigned int rax,
    unsigned int ray,
    unsigned int rbx,
    unsigned int rby
)
{

    rax=rax*STEP;
    ray=ray*STEP;
    rbx=rbx*STEP;
    rby=rby*STEP;

    printf("%u %u moveto\n",rax,ray);
    printf("%u %u lineto\n",rbx,rby);
    printf("stroke\n");

}


void do_circle ( float fx, float fy, float rad )
{
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

void moveto ( float x, float y)
{
    printf("%f %f moveto\n",x,y);
}
void lineto ( float x, float y)
{
    printf("%f %f lineto\n",x,y);
}
void closepath ( void )
{
    printf("closepath\n");
}
void stroke ( void )
{
    printf("stroke\n");
}


int main ( void )
{
    unsigned int ra;
    unsigned int rax,ray;
    unsigned int rbx,rby;

    unsigned int rb;
    unsigned int flag;

    float sx,sy;
    float fx,fy;
    float zz;
    float xx;
    float rr;



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
            if(ra==(STEP*(16+1))) flag++;
            if(ra==(STEP*(17+1))) flag++;
            if(ra==(STEP*(18+1))) flag++;
            if(ra==(STEP*(19+1))) flag++;

            if(ra==(STEP*(22+1))) flag++;
            if(ra==(STEP*(23+1))) flag++;
            if(ra==(STEP*(24+1))) flag++;
            if(ra==(STEP*(25+1))) flag++;


            if(ra==(STEP*(34+1))) flag++;
            if(ra==(STEP*(35+1))) flag++;
            if(ra==(STEP*(36+1))) flag++;
            if(ra==(STEP*(37+1))) flag++;

            if(ra==(STEP*(40+1))) flag++;
            if(ra==(STEP*(41+1))) flag++;
            if(ra==(STEP*(42+1))) flag++;
            if(ra==(STEP*(43+1))) flag++;



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
            if(ra==(STEP*(16+1))) flag++;
            if(ra==(STEP*(17+1))) flag++;
            if(ra==(STEP*(18+1))) flag++;
            if(ra==(STEP*(19+1))) flag++;

            if(ra==(STEP*(22+1))) flag++;
            if(ra==(STEP*(23+1))) flag++;
            if(ra==(STEP*(24+1))) flag++;
            if(ra==(STEP*(25+1))) flag++;


            if(ra==(STEP*(34+1))) flag++;
            if(ra==(STEP*(35+1))) flag++;
            if(ra==(STEP*(36+1))) flag++;
            if(ra==(STEP*(37+1))) flag++;

            if(ra==(STEP*(40+1))) flag++;
            if(ra==(STEP*(41+1))) flag++;
            if(ra==(STEP*(42+1))) flag++;
            if(ra==(STEP*(43+1))) flag++;
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
    //fprintf(fp,"%f %f %f %f %f arc\n",x,y,r,a,b);
//}

//xx=7.5;
rr=3.0;


	do_line(30-rr,30-rr-0,30+rr,30-rr-0);
	do_line(30-rr,30-rr-1,30+rr,30-rr-1);
	do_line(30-rr,30-rr-2,30+rr,30-rr-2);
	do_line(30-rr,30-rr-3,30+rr,30-rr-3);

	do_line(30-rr,30+rr+0,30+rr,30+rr+0);
	do_line(30-rr,30+rr+1,30+rr,30+rr+1);
	do_line(30-rr,30+rr+2,30+rr,30+rr+2);
	do_line(30-rr,30+rr+3,30+rr,30+rr+3);


	do_line(30-rr-0,30-rr,30-rr-0,30+rr);
	do_line(30-rr-1,30-rr,30-rr-1,30+rr);
	do_line(30-rr-2,30-rr,30-rr-2,30+rr);
	do_line(30-rr-3,30-rr,30-rr-3,30+rr);

	do_line(30+rr+0,30-rr,30+rr+0,30+rr);
	do_line(30+rr+1,30-rr,30+rr+1,30+rr);
	do_line(30+rr+2,30-rr,30+rr+2,30+rr);
	do_line(30+rr+3,30-rr,30+rr+3,30+rr);



    //sx=30-rr;
    //fx=sx*STEP;
    //sy=30-rr;
    //fy=sy*STEP;
    //moveto(fx,fy);
    //sx+=rr+rr;
    //fx=sx*STEP;
    //lineto(fx,fy);
    //sy+=rr+rr;
    //fy=sy*STEP;
    //lineto(fx,fy);
    //sx-=rr+rr;
    //fx=sx*STEP;
    //lineto(fx,fy);
    //closepath();
    //stroke();

    //sx=30-rr-1;
    //fx=sx*STEP;
    //sy=30-rr-1;
    //fy=sy*STEP;
    //moveto(fx,fy);
    //sx+=rr+rr+2;
    //fx=sx*STEP;
    //lineto(fx,fy);
    //sy+=rr+rr+2;
    //fy=sy*STEP;
    //lineto(fx,fy);
    //sx-=rr+rr+2;
    //fx=sx*STEP;
    //lineto(fx,fy);
    //closepath();
    //stroke();

    //sx=30-rr-2;
    //fx=sx*STEP;
    //sy=30-rr-2;
    //fy=sy*STEP;
    //moveto(fx,fy);
    //sx+=rr+rr+4;
    //fx=sx*STEP;
    //lineto(fx,fy);
    //sy+=rr+rr+4;
    //fy=sy*STEP;
    //lineto(fx,fy);
    //sx-=rr+rr+4;
    //fx=sx*STEP;
    //lineto(fx,fy);
    //closepath();
    //stroke();

    //sx=30-rr-3;
    //fx=sx*STEP;
    //sy=30-rr-3;
    //fy=sy*STEP;
    //moveto(fx,fy);
    //sx+=rr+rr+6;
    //fx=sx*STEP;
    //lineto(fx,fy);
    //sy+=rr+rr+6;
    //fy=sy*STEP;
    //lineto(fx,fy);
    //sx-=rr+rr+6;
    //fx=sx*STEP;
    //lineto(fx,fy);
    //closepath();
    //stroke();


    sx=30+rr;
    sy=30+rr;
    do_arc(sx,sy,rr+rr+0,270,180);
    do_arc(sx,sy,rr+rr+1,270,180);
    do_arc(sx,sy,rr+rr+2,270,180);
    do_arc(sx,sy,rr+rr+3,270,180);

    sx=30-rr;
    sy=30-rr;
    do_arc(sx,sy,rr+rr+0,90,0);
    do_arc(sx,sy,rr+rr+1,90,0);
    do_arc(sx,sy,rr+rr+2,90,0);
    do_arc(sx,sy,rr+rr+3,90,0);

    sx=30-rr;
    sy=30+rr;
    do_arc(sx,sy,rr+rr+0,0,270);
    do_arc(sx,sy,rr+rr+1,0,270);
    do_arc(sx,sy,rr+rr+2,0,270);
    do_arc(sx,sy,rr+rr+3,0,270);

    sx=30+rr;
    sy=30-rr;
    do_arc(sx,sy,rr+rr+0,180,90);
    do_arc(sx,sy,rr+rr+1,180,90);
    do_arc(sx,sy,rr+rr+2,180,90);
    do_arc(sx,sy,rr+rr+3,180,90);












    //do_arc(30.5-xx,30.5,rr+0,0,360);
    //do_arc(30.5-xx,30.5,rr+1,0,360);
    //do_arc(30.5-xx,30.5,rr+2,0,360);
    //do_arc(30.5-xx,30.5,rr+3,0,360);

    //do_arc(30.5+xx,30.5,rr+0,0,360);
    //do_arc(30.5+xx,30.5,rr+1,0,360);
    //do_arc(30.5+xx,30.5,rr+2,0,360);
    //do_arc(30.5+xx,30.5,rr+3,0,360);


    //do_arc(30.5,30.5-xx,rr+0,0,360);
    //do_arc(30.5,30.5-xx,rr+1,0,360);
    //do_arc(30.5,30.5-xx,rr+2,0,360);
    //do_arc(30.5,30.5-xx,rr+3,0,360);


    //do_arc(30.5,30.5+xx,rr+0,0,360);
    //do_arc(30.5,30.5+xx,rr+1,0,360);
    //do_arc(30.5,30.5+xx,rr+2,0,360);
    //do_arc(30.5,30.5+xx,rr+3,0,360);







////41.18 = 23
////27.5 30
////27.5-16 = 11.5;
    //zz=11;
    //do_arc(30.5,30.5,zz+0,0,360);
    //do_arc(30.5,30.5,zz+1,0,360);
    //do_arc(30.5,30.5,zz+2,0,360);
    //do_arc(30.5,30.5,zz+3,0,360);



    //do_arc(30.5-zz,30.5-zz,rr+0,0,360);
    //do_arc(30.5-zz,30.5-zz,rr+1,0,360);
    //do_arc(30.5-zz,30.5-zz,rr+2,0,360);
    //do_arc(30.5-zz,30.5-zz,rr+3,0,360);
    //do_arc(30.5-zz,30.5+zz,rr+0,0,360);
    //do_arc(30.5-zz,30.5+zz,rr+1,0,360);
    //do_arc(30.5-zz,30.5+zz,rr+2,0,360);
    //do_arc(30.5-zz,30.5+zz,rr+3,0,360);
    //do_arc(30.5+zz,30.5-zz,rr+0,0,360);
    //do_arc(30.5+zz,30.5-zz,rr+1,0,360);
    //do_arc(30.5+zz,30.5-zz,rr+2,0,360);
    //do_arc(30.5+zz,30.5-zz,rr+3,0,360);
    //do_arc(30.5+zz,30.5+zz,rr+0,0,360);
    //do_arc(30.5+zz,30.5+zz,rr+1,0,360);
    //do_arc(30.5+zz,30.5+zz,rr+2,0,360);
    //do_arc(30.5+zz,30.5+zz,rr+3,0,360);




    printf("showpage\n");
    return(0);
}
