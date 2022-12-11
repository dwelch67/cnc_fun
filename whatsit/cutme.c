
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

FILE *fp;
FILE *fpbatch;

#define ANGLED 0

//Radians = Degrees × (π/180)

//double degrad = 1.0 / 180.0 * M_PI;
double rangle = (45) / 180.0 * M_PI;
double raddeg = 180.0 / M_PI;
double theangle;

double twopi = 2.0 * M_PI;


#define WIDE 5.0F
#define BRAD 6.0F
#define LRAD 4.0F

#define OFFSET 80


float miny,maxy;
void moveto ( float x, float y )
{
    x+=OFFSET;
    y+=OFFSET;

    fprintf(fp,"%f %f moveto\n",x,y);
}
void lineto ( float x, float y )
{
    x+=OFFSET;
    y+=OFFSET;
    fprintf(fp,"%f %f lineto\n",x,y);
}
void stroke ( void )
{
    fprintf(fp,"stroke\n");
}

void arc ( float x, float y, float r, float a, float b )
{
    x+=OFFSET;
    y+=OFFSET;
    fprintf(fp,"%f %f %f %f %f arc\n",x,y,r,a,b);
}

void arcn ( float x, float y, float r, float a, float b )
{
    x+=OFFSET;
    y+=OFFSET;
    fprintf(fp,"%f %f %f %f %f arcn\n",x,y,r,a,b);
}


//void cut_square_l ( int x, int y )
//{
    //float fx,fy;
    //float rad;

    //elements++;
    //fprintf(fp,"%%cut_square_l(%d,%d);\n",x,y);

    //fx=(x+3)*WIDE;
    //fy=y*WIDE;
    //moveto(fx,fy);
    //fy=(y+3)*WIDE;
    //lineto(fx,fy);

    //fx=(x+3)*WIDE;
    //fy=(y+1.5F)*WIDE;
    //rad=1.5F*WIDE;
    //arc(fx,fy,rad,90,270);
    //fx=(x+3)*WIDE;
    //fy=(y)*WIDE;
    //lineto(fx,fy);
    //stroke();
//}


void upright ( float x, float y)
{
    float fx,fy;
    float rad;

    fx=(x)*WIDE;
    fy=(y+LRAD)*WIDE;
    moveto(fx,fy);

    fx=(x)*WIDE;
    fy=(y)*WIDE;
    rad=LRAD*WIDE;
    arc(fx,fy,rad,90,0);

    fx=(x+LRAD+BRAD)*WIDE;
    fy=(y)*WIDE;
    rad=BRAD*WIDE;
    arcn(fx,fy,rad,180,90);

    fx=(x+LRAD+BRAD)*WIDE;
    fy=(y+LRAD+BRAD)*WIDE;
    rad=LRAD*WIDE;
    arc(fx,fy,rad,270,180);

    fx=(x)*WIDE;
    fy=(y+LRAD+BRAD)*WIDE;
    rad=BRAD*WIDE;
    arcn(fx,fy,rad,0,270);



    stroke();

}




void downright ( float x, float y)
{
    float fx,fy;
    float rad;

    fx=(x)*WIDE;
    fy=(y-LRAD)*WIDE;
    moveto(fx,fy);

    fx=(x)*WIDE;
    fy=(y)*WIDE;
    rad=LRAD*WIDE;
    arcn(fx,fy,rad,270,0);

    fx=(x+LRAD+BRAD)*WIDE;
    fy=(y)*WIDE;
    rad=BRAD*WIDE;
    arc(fx,fy,rad,180,270);

    fx=(x+LRAD+BRAD)*WIDE;
    fy=(y-LRAD-BRAD)*WIDE;
    rad=LRAD*WIDE;
    arcn(fx,fy,rad,90,180);

    fx=(x)*WIDE;
    fy=(y-LRAD-BRAD)*WIDE;
    rad=BRAD*WIDE;
    arc(fx,fy,rad,0,90);

    stroke();

}



void lcircle ( float x, float y)
{
    float fx,fy;
    float rad;

    fx=(x+LRAD)*WIDE;
    fy=(y)*WIDE;
    moveto(fx,fy);

    fx=(x)*WIDE;
    fy=(y)*WIDE;
    rad=LRAD*WIDE;
    arc(fx,fy,rad,0,360);

    stroke();

}




void bottom ( float x, float y, unsigned int z)
{
    float fx,fy;
    float rad;

    fx=(x)*WIDE;
    fy=(y-BRAD)*WIDE;
    moveto(fx,fy);

    fx=(x)*WIDE;
    fy=(y)*WIDE;
    rad=BRAD*WIDE;
	//if(z) arcn(fx,fy,rad,270,270);
	//else  
	arcn(fx,fy,rad,270,270-theangle);

    fx=(x)*WIDE;
    fy=(y-BRAD)*WIDE;
    moveto(fx,fy);

    fx=(x)*WIDE;
    fy=(y)*WIDE;
    rad=BRAD*WIDE;
    arc(fx,fy,rad,270,270+theangle);


    //stroke();

}

void left ( float x, float y)
{
    float fx,fy;
    float rad;

    fx=(x-BRAD)*WIDE;
    fy=(y)*WIDE;
    moveto(fx,fy);

    fx=(x)*WIDE;
    fy=(y)*WIDE;
    rad=BRAD*WIDE;
    arcn(fx,fy,rad,180,180-theangle);

    fx=(x-BRAD)*WIDE;
    fy=(y)*WIDE;
    moveto(fx,fy);

    fx=(x)*WIDE;
    fy=(y)*WIDE;
    rad=BRAD*WIDE;
    arc(fx,fy,rad,180,180+theangle);


    //stroke();

}

void right ( float x, float y)
{
    float fx,fy;
    float rad;

    fx=(x+BRAD)*WIDE;
    fy=(y)*WIDE;
    moveto(fx,fy);

    fx=(x)*WIDE;
    fy=(y)*WIDE;
    rad=BRAD*WIDE;
    arcn(fx,fy,rad,0,0-theangle);

    fx=(x+BRAD)*WIDE;
    fy=(y)*WIDE;
    moveto(fx,fy);

    fx=(x)*WIDE;
    fy=(y)*WIDE;
    rad=BRAD*WIDE;
    arc(fx,fy,rad,0,0+theangle);


    //stroke();

}




void top ( float x, float y)
{
    float fx,fy;
    float rad;

    fx=(x)*WIDE;
    fy=(y+BRAD)*WIDE;
    moveto(fx,fy);

    fx=(x)*WIDE;
    fy=(y)*WIDE;
    rad=BRAD*WIDE;
    arcn(fx,fy,rad,90,90-theangle);

    fx=(x)*WIDE;
    fy=(y+BRAD)*WIDE;
    moveto(fx,fy);

    fx=(x)*WIDE;
    fy=(y)*WIDE;
    rad=BRAD*WIDE;
    arc(fx,fy,rad,90,90+theangle);


    //stroke();

}





int dome ( int points )
{

    char xstring[40];
    unsigned int ra;
    unsigned int rb;
    unsigned int rc;
    unsigned int rx;
    unsigned int ry;
    unsigned int xx,yy;
	
	double dx,dy;

    //elements=0;

    sprintf(xstring,"hello%d.ps",points);
    fprintf(stderr,"%s\n",xstring);
    fp=fopen(xstring,"wt");
    if(fp==NULL)
    {
        fprintf(stderr,"Error creating file [%s]\n",xstring);
        exit(1);
    }

    fprintf(fpbatch,"echo hello%d.ps\n",points);
    fprintf(fpbatch,"ps2pdf hello%d.ps\n",points);
    fprintf(fpbatch,"pdf2svg hello%d.pdf hello%d.svg\n",points,points);


    //ra=(points-1)*6;
    //ra*=2;
    //ra+=9;
    //ra*=WIDE;
    //ra+=20;


//if(ANGLED)
//{

    //middle=((points-1)*6)+4;
    //middle+=0.5F;
    //goback=points*5;
//}


	theangle=((LRAD+BRAD)/2.0)/BRAD;
	theangle=acos(theangle);
	theangle=theangle*raddeg;
	theangle=90-theangle;
	printf("angle %lf\n",theangle);





    fprintf(fp,"%%!\n");
    
    //fprintf(fp,"%%BoundingBox: 0 0 %u %u\n",ra,ra);
    //fprintf(fp,"<< /PageSize [%u %u] >> setpagedevice\n",ra,ra);


    fprintf(fp,"1.0 setlinewidth\n");
    fprintf(fp,"0.0 setgray\n");






    for(rb=0;rb<6;rb+=2)
    {
        ry=rb*(LRAD+BRAD);
        for(ra=0;ra<5;ra++)
        {
            rx=ra*(LRAD+BRAD);
            if(ra&1)
            {
                if(rb)
                downright(rx,ry);
            }
            else
            {
                upright(rx,ry);
            }
        }
    }

    //for(rb=0;rb<=5;rb++)
    //{
        //ry=rb*(LRAD+BRAD);
        //for(ra=0;ra<=5;ra++)
        //{
            //if
            //(
                //((rb==0)&&(ra&1))
                //||
                //((ra==0)&&(rb&1))
                //||
                //((rb==5)&&((ra&1)==0))
                //||
                //((ra==5)&&((rb&1)==0))
            //)
            //{
                //rx=ra*(LRAD+BRAD);
                //lcircle(rx,ry);
            //}
        //}
    //}

    for(rb=1;rb<=5;rb+=2)
    {
        ry=rb*(LRAD+BRAD);
        ra=0;
        {
            rx=ra*(LRAD+BRAD);
            lcircle(rx,ry);
        }
    }

    for(rb=0;rb<=5;rb+=2)
    {
        ry=rb*(LRAD+BRAD);
        ra=5;
        {
            rx=ra*(LRAD+BRAD);
            lcircle(rx,ry);
        }
    }

    rb=0;
    {
        ry=rb*(LRAD+BRAD);
        for(ra=1;ra<=5;ra+=2)
        {
            rx=ra*(LRAD+BRAD);
            lcircle(rx,ry);
        }
    }

    rb=5;
    {
        ry=rb*(LRAD+BRAD);
        for(ra=0;ra<=5;ra+=2)
        {
            rx=ra*(LRAD+BRAD);
            lcircle(rx,ry);
        }
    }





    rb=0;
    {
        ry=rb*(LRAD+BRAD);
        for(ra=0;ra<=5;ra++)
        {
            rx=ra*(LRAD+BRAD);
			if(ra==0) bottom(rx,ry,1);
			else      bottom(rx,ry,0);
        }
    }
    for(rb=0;rb<=5;rb++)
    {
        ry=rb*(LRAD+BRAD);
        ra=5;
        {
            rx=ra*(LRAD+BRAD);
            right(rx,ry);
        }
    }

    for(rb=0;rb<=5;rb++)
    {
        ry=rb*(LRAD+BRAD);
        ra=5;
        {
            rx=ra*(LRAD+BRAD);
            right(rx,ry);
        }
    }

    //rb=0;
    //{
        //ry=rb*(LRAD+BRAD);
        //for(ra=0;ra<=5;ra++)
        //{
            //rx=ra*(LRAD+BRAD);
            //bottom(rx,ry);
        //}
    //}

    for(rb=0;rb<=5;rb++)
    {
        ry=rb*(LRAD+BRAD);
        ra=0;
        {
            rx=ra*(LRAD+BRAD);
            left(rx,ry);
        }
    }

    rb=5;
    {
        ry=rb*(LRAD+BRAD);
        for(ra=0;ra<=5;ra++)
        {
            rx=ra*(LRAD+BRAD);
            top(rx,ry);
        }
    }

	stroke();

    fprintf(fp,"showpage\n");












    fclose(fp);
    return(0);
}


int main ( void )
{
    unsigned int ra;

    fpbatch=fopen("go.bat","wt");
    if(fpbatch==NULL)
    {
        fprintf(stderr,"error creating file\n");
        return(1);
    }

    dome(3);

    fclose(fpbatch);

    return(0);
}



