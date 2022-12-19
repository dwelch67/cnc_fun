

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define JUMP 100
#define STEP 80

#define JUMP0 (JUMP-10)
#define STEP0 (STEP-20)

#define JUMP1 (JUMP0-10)
#define STEP1 (STEP0-20)

#define JUMP2 (JUMP1-10)
#define STEP2 (STEP1-20)


double degrad = M_PI / 180.0;
double raddeg = 180.0 / M_PI;

void do_line ( float ax, float ay, float bx,float by )
{
    //ax=ax+1;
    //ay=ay+1;
    //bx=bx+1;
    //by=by+1;


    //ax=ax*STEP;
    //ay=ay*STEP;
    //bx=bx*STEP;
    //by=by*STEP;

    printf("%f %f moveto\n",ax,ay);
    printf("%f %f lineto\n",bx,by);
    printf("stroke\n");
}

void do_circle ( float fx, float fy, float rad )
{
    //fx=fx+1;
    //fy=fy+1;


    //fx=fx*STEP;
    //fy=fy*STEP;

    rad=rad*STEP;
    printf("%f %f moveto\n",fx+rad,fy);
    printf("%f %f %f 0 360 arc\n",fx,fy,rad);
    printf("stroke\n");
}

void do_arc ( float fx, float fy, float rad, float a, float b )
{
    float sx,sy;

    fx=fx+1;
    fy=fy+1;

    //fx=fx*STEP;
    //fy=fy*STEP;
    //rad=rad*STEP;

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
    unsigned int rb;

    float fx,fy;
    float sx[3],sy[3];
    float ax[3],ay[3];
    float bx[3],by[3];
    float theangle;
    float thestep;
    float angle;
	float step;
	float jump;

    printf("%%!\n");
    //printf("<< /PageSize [%u %u] >> setpagedevice\n",ra,ra);
    printf("0.0 setgray\n");
    printf("0.1 setlinewidth\n");






    fx=300;
    fy=300;
    
    thestep=120*degrad;
    theangle=90*degrad;
    

	for(rb=0;rb<4;rb++)
	{
		switch(rb)
		{
			case 0:
			{
				jump=200;
				step=173;
				break;
			}
			case 1:
			case 2:
			case 3:
			{
				jump-=30;
				step-=34.5;
				break;
			}
			//case 2:
			//{
				//jump-=20;
				//step-=20;
				//break;
			//}
			//case 3:
			//{
				//jump-=20;
				//step-=20;
				//break;
			//}
		}
	
	
		for(ra=0;ra<3;ra++)
		{
			sx[ra]=fx+(cos(theangle)*jump);
			sy[ra]=fy+(sin(theangle)*jump);
			angle=theangle+(150*degrad);
			ax[ra]=sx[ra]+(cos(angle)*step);
			ay[ra]=sy[ra]+(sin(angle)*step);
			angle=theangle+((-150)*degrad);
			bx[ra]=sx[ra]+(cos(angle)*step);
			by[ra]=sy[ra]+(sin(angle)*step);
			theangle=theangle+thestep;
		}
		for(ra=0;ra<3;ra++)
		{
			do_line(sx[ra],sy[ra],ax[ra],ay[ra]);
			do_line(sx[ra],sy[ra],bx[ra],by[ra]);
		}

		do_line(ax[0],ay[0],bx[2],by[2]);
		do_line(ax[1],ay[1],bx[0],by[0]);
		do_line(ax[2],ay[2],bx[1],by[1]);



	}
    printf("showpage\n");


    return(0);
}
