

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
    
    unsigned int rb;
    unsigned int flag;
    
    float fx,fy;
    float fad,fbd;
    float theangle;
    
	float ii,jj,kk,ll;
	

    for(rb=STEP;rb<600;rb+=STEP)

    printf("%%!\n");
    printf("0.0 setgray\n");
    printf("0.1 setlinewidth\n");

    if(0)
    {
        for(ra=STEP;ra<600;ra+=STEP)
        {
            //horizontal
            flag=0;
            //if(ra==(STEP*(16+1))) flag++;
            //if(ra==(STEP*(17+1))) flag++;
            //if(ra==(STEP*(18+1))) flag++;
            //if(ra==(STEP*(19+1))) flag++;
            
            //if(ra==(STEP*(22+1))) flag++;
            //if(ra==(STEP*(23+1))) flag++;
            //if(ra==(STEP*(24+1))) flag++;
            //if(ra==(STEP*(25+1))) flag++;


            //if(ra==(STEP*(34+1))) flag++;
            //if(ra==(STEP*(35+1))) flag++;
            //if(ra==(STEP*(36+1))) flag++;
            //if(ra==(STEP*(37+1))) flag++;

            //if(ra==(STEP*(40+1))) flag++;
            //if(ra==(STEP*(41+1))) flag++;
            //if(ra==(STEP*(42+1))) flag++;
            //if(ra==(STEP*(43+1))) flag++;


            
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
            //if(ra==(STEP*(16+1))) flag++;
            //if(ra==(STEP*(17+1))) flag++;
            //if(ra==(STEP*(18+1))) flag++;
            //if(ra==(STEP*(19+1))) flag++;
            
            //if(ra==(STEP*(22+1))) flag++;
            //if(ra==(STEP*(23+1))) flag++;
            //if(ra==(STEP*(24+1))) flag++;
            //if(ra==(STEP*(25+1))) flag++;


            //if(ra==(STEP*(34+1))) flag++;
            //if(ra==(STEP*(35+1))) flag++;
            //if(ra==(STEP*(36+1))) flag++;
            //if(ra==(STEP*(37+1))) flag++;

            //if(ra==(STEP*(40+1))) flag++;
            //if(ra==(STEP*(41+1))) flag++;
            //if(ra==(STEP*(42+1))) flag++;
            //if(ra==(STEP*(43+1))) flag++;
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


    fad=3*3;
    fad=fad*2;
    fad=sqrt(fad);
    fprintf(stderr,"fad %f\n",fad);
    theangle=acos(fad/8.5);
    fprintf(stderr,"theangle %f\n",theangle);
    theangle=theangle*raddeg;
    fprintf(stderr,"theangle %f\n",theangle);
    theangle=theangle-45;
    fprintf(stderr,"theangle %f\n",theangle);

    //doline(41*STEP,41*STEP,47*STEP,47*STEP);
    //doline(44*STEP,44*STEP,54*STEP,34*STEP);
    //do_arc(40,40,8.5,180,360-theangle);
    //do_arc(46,46,8.5,270+theangle,90);

ii=8.5;
kk=8.0;
//jj=12.5;
jj=ii+kk;

ll=22;

    do_arc(ll,ll-kk,ii+0,180,0);
    do_arc(ll,ll-kk,ii+2,180,0);
    do_arc(ll,ll-kk,ii+3,180,0);
    do_arc(ll,ll-kk,ii+5,180,0);
    //do_arc(ll,ll-kk,8.5,180+theangle,0-theangle);

    do_arc(ll+kk,ll,ii+0,270,90);
    do_arc(ll+kk,ll,ii+2,270,90);
    do_arc(ll+kk,ll,ii+3,270,90);
    do_arc(ll+kk,ll,ii+5,270,90);
    //do_arc(ll+kk,ll,8.5,270+theangle,90-theangle);

    do_arc(ll-kk,ll,ii+0,90,270);
    do_arc(ll-kk,ll,ii+2,90,270);
    do_arc(ll-kk,ll,ii+3,90,270);
    do_arc(ll-kk,ll,ii+5,90,270);
    //do_arc(ll-kk,ll,8.5,90+theangle,270-theangle);

    do_arc(ll,ll+kk,ii+0,0,180);
    do_arc(ll,ll+kk,ii+2,0,180);
    do_arc(ll,ll+kk,ii+3,0,180);
    do_arc(ll,ll+kk,ii+5,0,180);
    //do_arc(ll,ll+kk,8.5,0+theangle,180-theangle);

    do_arc(ll+kk,ll-kk,jj+0,90,180);
    do_arc(ll+kk,ll-kk,jj+2,90,180);
    do_arc(ll+kk,ll-kk,jj+3,90,180);
    do_arc(ll+kk,ll-kk,jj+5,90,180);

    do_arc(ll+kk,ll+kk,jj+0,180,270);
    do_arc(ll+kk,ll+kk,jj+2,180,270);
    do_arc(ll+kk,ll+kk,jj+3,180,270);
    do_arc(ll+kk,ll+kk,jj+5,180,270);

    do_arc(ll-kk,ll+kk,jj+0,270,0);
    do_arc(ll-kk,ll+kk,jj+2,270,0);
    do_arc(ll-kk,ll+kk,jj+3,270,0);
    do_arc(ll-kk,ll+kk,jj+5,270,0);

    do_arc(ll-kk,ll-kk,jj+0,0,90);
    do_arc(ll-kk,ll-kk,jj+2,0,90);
    do_arc(ll-kk,ll-kk,jj+3,0,90);
    do_arc(ll-kk,ll-kk,jj+5,0,90);



    printf("showpage\n");
    return(0);
}
