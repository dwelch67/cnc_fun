

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




int main ( void )
{
    unsigned int ra;
    unsigned int rax,ray;
    unsigned int rbx,rby;
    
    unsigned int rb;
    unsigned int flag;
    
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

xx=7.5;
rr=9.0;


    do_arc(30.5-xx,30.5,rr+0,0,360);
    do_arc(30.5-xx,30.5,rr+1,0,360);
    do_arc(30.5-xx,30.5,rr+2,0,360);
    do_arc(30.5-xx,30.5,rr+3,0,360);

    do_arc(30.5+xx,30.5,rr+0,0,360);
    do_arc(30.5+xx,30.5,rr+1,0,360);
    do_arc(30.5+xx,30.5,rr+2,0,360);
    do_arc(30.5+xx,30.5,rr+3,0,360);


    do_arc(30.5,30.5-xx,rr+0,0,360);
    do_arc(30.5,30.5-xx,rr+1,0,360);
    do_arc(30.5,30.5-xx,rr+2,0,360);
    do_arc(30.5,30.5-xx,rr+3,0,360);


    do_arc(30.5,30.5+xx,rr+0,0,360);
    do_arc(30.5,30.5+xx,rr+1,0,360);
    do_arc(30.5,30.5+xx,rr+2,0,360);
    do_arc(30.5,30.5+xx,rr+3,0,360);

//41.18 = 23
//27.5 30
//27.5-16 = 11.5;
    zz=13.5;

    do_arc(30.5-zz,30.5-zz,rr+0,0,360);
    do_arc(30.5-zz,30.5-zz,rr+1,0,360);
    do_arc(30.5-zz,30.5-zz,rr+2,0,360);
    do_arc(30.5-zz,30.5-zz,rr+3,0,360);
    do_arc(30.5-zz,30.5+zz,rr+0,0,360);
    do_arc(30.5-zz,30.5+zz,rr+1,0,360);
    do_arc(30.5-zz,30.5+zz,rr+2,0,360);
    do_arc(30.5-zz,30.5+zz,rr+3,0,360);
    do_arc(30.5+zz,30.5-zz,rr+0,0,360);
    do_arc(30.5+zz,30.5-zz,rr+1,0,360);
    do_arc(30.5+zz,30.5-zz,rr+2,0,360);
    do_arc(30.5+zz,30.5-zz,rr+3,0,360);
    do_arc(30.5+zz,30.5+zz,rr+0,0,360);
    do_arc(30.5+zz,30.5+zz,rr+1,0,360);
    do_arc(30.5+zz,30.5+zz,rr+2,0,360);
    do_arc(30.5+zz,30.5+zz,rr+3,0,360);



    //do_arc(24.5,24.5,11.5,90,360);
    //do_arc(24.5,24.5,12.5,90,360);
    //do_arc(24.5,24.5,13.5,90,360);
    //do_arc(24.5,24.5,10.5,90,360);
    
    //do_arc(36.5,36.5,5.5,90,360);
    //do_arc(36.5,36.5,6.5,90,360);
    //do_arc(36.5,36.5,7.5,90,360);
    //do_arc(36.5,36.5,4.5,90,360);

    //do_arc(36.5,36.5,11.5,-90,180);
    //do_arc(36.5,36.5,12.5,-90,180);
    //do_arc(36.5,36.5,13.5,-90,180);
    //do_arc(36.5,36.5,10.5,-90,180);
    
    



    ////do_circle(48.5,48.5,13.5);
    ////do_circle(48.5,48.5,10.5);
    //do_arc(48.5,48.5,10.5,180-50,180);
    //do_arc(48.5,48.5,11.5,180-50,180);
    //do_arc(48.5,48.5,12.5,180-50,180);
    //do_arc(48.5,48.5,13.5,180-50,180);
    
    //do_arc(48.5,48.5,10.5,270,270+50);
    //do_arc(48.5,48.5,11.5,270,270+50);
    //do_arc(48.5,48.5,12.5,270,270+50);
    //do_arc(48.5,48.5,13.5,270,270+50);
    
    
    

    ////do_circle(30.5,48.5,13.5);
    ////do_circle(30.5,48.5,10.5);
    //do_arc(30.5,48.5,10.5,0,50);
    //do_arc(30.5,48.5,11.5,0,50);
    //do_arc(30.5,48.5,12.5,0,50);
    //do_arc(30.5,48.5,13.5,0,50);
    
    

    ////do_circle(48.5,30.5,13.5);
    ////do_circle(48.5,30.5,10.5);
    //do_arc(48.5,30.5,10.5,90-50,90);
    //do_arc(48.5,30.5,11.5,90-50,90);
    //do_arc(48.5,30.5,12.5,90-50,90);
    //do_arc(48.5,30.5,13.5,90-50,90);


////  do_circle(12.5,12.5,13.5);
    ////do_circle(12.5,12.5,10.5);
    //do_arc(12.5,12.5,10.5,90,90+50);
    //do_arc(12.5,12.5,11.5,90,90+50);
    //do_arc(12.5,12.5,12.5,90,90+50);
    //do_arc(12.5,12.5,13.5,90,90+50);

    //do_arc(12.5,12.5,10.5,0-50,0);
    //do_arc(12.5,12.5,11.5,0-50,0);
    //do_arc(12.5,12.5,12.5,0-50,0);
    //do_arc(12.5,12.5,13.5,0-50,0);




    ////do_circle(30.5,12.5,13.5);
    ////do_circle(30.5,12.5,10.5);
    //do_arc(30.5,12.5,10.5,180,180+50);
    //do_arc(30.5,12.5,11.5,180,180+50);
    //do_arc(30.5,12.5,12.5,180,180+50);
    //do_arc(30.5,12.5,13.5,180,180+50);





    ////do_circle(12.5,30.5,13.5);
    ////do_circle(12.5,30.5,10.5);
    //do_arc(12.5,30.5,10.5,270-50,270);
    //do_arc(12.5,30.5,11.5,270-50,270);
    //do_arc(12.5,30.5,12.5,270-50,270);
    //do_arc(12.5,30.5,13.5,270-50,270);




    printf("showpage\n");
    return(0);
}
