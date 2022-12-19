

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


FILE *fp;

#define STEP 35


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
	
	float a,b,c,d;
	float aaa;
    
    float ii,jj,kk,ll;

    char xstring[64];


    for(ri=1;ri<3;ri++)
    for(rj=9;rj<13;rj++)
	for(aaa=1;aaa<2;aaa+=0.1)
    {













		ra=aaa*10;

        sprintf(xstring,"hello_%u_%02u_%02u.ps",ri,rj,ra);
        fp=fopen(xstring,"wt");
        if(fp==NULL)
        {
            printf("error creating file %s\n",xstring);
            return(1);
        }
        //ii=ri;
        //jj=rj;
    

//A1: 594 mm x 841 mm. (23.39 in. x 33.11 in.)


        fprintf(fp,"%%!\n");
	//	ra=(ri+rj+2)*STEP;
		
		
//fprintf(fp,"<< /PageSize [%u %u] >> setpagedevice\n",ra,ra);
        fprintf(fp,"0.0 setgray\n");
        fprintf(fp,"0.1 setlinewidth\n");


a=0;
b=aaa;
c=b+1;
d=c+aaa;



        //do_line(0,0,ri+rj,0);
        //do_line(0,1,ri+rj,1);
        //do_line(0,2,ri+rj,2);
        //do_line(0,3,ri+rj,3);

        do_line(0,a,ri,a);
        do_line(0,b,ri,b);
        do_line(0,c,ri,c);
        do_line(0,d,ri,d);


        do_line(rj,a,rj+ri,a);
        do_line(rj,b,rj+ri,b);
        do_line(rj,c,rj+ri,c);
        do_line(rj,d,rj+ri,d);



        //do_line(0,0,0,ri+rj);
        //do_line(1,0,1,ri+rj);
        //do_line(2,0,2,ri+rj);
        //do_line(3,0,3,ri+rj);

        do_line(a,0,a,ri);
        do_line(b,0,b,ri);
        do_line(c,0,c,ri);
        do_line(d,0,d,ri);

        do_line(a,rj,a,ri+rj);
        do_line(b,rj,b,ri+rj);
        do_line(c,rj,c,ri+rj);
        do_line(d,rj,d,ri+rj);



        //do_line(0,ri+rj-0,ri+rj,ri+rj-0);
        //do_line(0,ri+rj-1,ri+rj,ri+rj-1);
        //do_line(0,ri+rj-2,ri+rj,ri+rj-2);
        //do_line(0,ri+rj-3,ri+rj,ri+rj-3);

        do_line(0,ri+rj-a,ri,ri+rj-a);
        do_line(0,ri+rj-b,ri,ri+rj-b);
        do_line(0,ri+rj-c,ri,ri+rj-c);
        do_line(0,ri+rj-d,ri,ri+rj-d);

        do_line(rj,ri+rj-a,ri+rj,ri+rj-a);
        do_line(rj,ri+rj-b,ri+rj,ri+rj-b);
        do_line(rj,ri+rj-c,ri+rj,ri+rj-c);
        do_line(rj,ri+rj-d,ri+rj,ri+rj-d);

        //do_line(ri+rj-0,0,ri+rj-0,ri+rj);
        //do_line(ri+rj-1,0,ri+rj-1,ri+rj);
        //do_line(ri+rj-2,0,ri+rj-2,ri+rj);
        //do_line(ri+rj-3,0,ri+rj-3,ri+rj);

        do_line(ri+rj-a,0,ri+rj-a,ri);
        do_line(ri+rj-b,0,ri+rj-b,ri);
        do_line(ri+rj-c,0,ri+rj-c,ri);
        do_line(ri+rj-d,0,ri+rj-d,ri);

        do_line(ri+rj-a,rj,ri+rj-a,ri+rj);
        do_line(ri+rj-b,rj,ri+rj-b,ri+rj);
        do_line(ri+rj-c,rj,ri+rj-c,ri+rj);
        do_line(ri+rj-d,rj,ri+rj-d,ri+rj);








        do_line(ri+rj+1,0,ri+rj+1,ri+rj+1);

        do_line(0,ri+rj+1,ri+rj+1,ri+rj+1);



        do_arc(ri,ri,rj-a,0,90);
        do_arc(ri,ri,rj-b,0,90);
        do_arc(ri,ri,rj-c,0,90);
        do_arc(ri,ri,rj-d,0,90);

        do_arc(rj,ri,rj-a,90,180);
        do_arc(rj,ri,rj-b,90,180);
        do_arc(rj,ri,rj-c,90,180);
        do_arc(rj,ri,rj-d,90,180);


        do_arc(rj,rj,rj-a,180,270);
        do_arc(rj,rj,rj-b,180,270);
        do_arc(rj,rj,rj-c,180,270);
        do_arc(rj,rj,rj-d,180,270);


        do_arc(ri,rj,rj-a,270,0);
        do_arc(ri,rj,rj-b,270,0);
        do_arc(ri,rj,rj-c,270,0);
        do_arc(ri,rj,rj-d,270,0);




        fprintf(fp,"showpage\n");
        
        fclose(fp);
    

    }
    return(0);
}
