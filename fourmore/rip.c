
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



FILE *fp;
char newline[256];


int do_xy ( void )
{
    unsigned int ra;
    unsigned int rb;
    unsigned int rc;
    double fx;
    double fy;

    for(ra=0;newline[ra];ra++)
    {
        if(newline[ra]<0x20) newline[ra]=0;
    }


    
    for(ra=0;newline[ra];ra++)
    {
        if(newline[ra]=='X') break;
    }
    if(newline[ra]!='X') return(0);
    rb=ra+1;
    for(ra++;newline[ra];ra++)
    {
        if(newline[ra]==' ') break;
    }
    if(newline[ra]!=' ') return(0);
    newline[ra]=0;
    //printf("%s ",&newline[rb]);
    for(ra++;newline[ra];ra++)
    {
        if(newline[ra]=='Y') break;
    }
    if(newline[ra]!='Y') return(0);
    rc=ra+1;
    for(ra++;newline[ra];ra++)
    {
        if(newline[ra]==' ') break;
    }
    newline[ra]=0;
    //printf("%s %s ",&newline[rb],&newline[rc]);
    fx=atof(&newline[rb]);
    fy=atof(&newline[rc]);
	fx/=3.0;
	fy/=3.0;
    printf("%lf %lf ",fx,fy);
    
    
    return(1);
}

int main ( int argc, char *argv[] )
{

    if(argc<2)
    {
        fprintf(stderr,"what\n");
        return(1);
    }


    fp=fopen(argv[1],"rt");
    if(fp==NULL)
    {
        fprintf(stderr,"error opening file [%s]\n",argv[1]);
        return(1);
    }

    printf("%%!\n");
    printf("0.0 setgray\n");
    printf("0.1 setlinewidth\n");

    while(fgets(newline,sizeof(newline)-1,fp))
    {
//G00 X223.7683 Y266.6737
        if(strncmp(newline,"G00 X",5)==0)
        {
            printf("\n");
            printf("\n");
            if(do_xy()) printf("moveto\n");
        }
//G00 Z0.5000
//G01 Z0.0000 F200 S8000
//G01 Z-0.1000
//G01 X221.4851 Y269.1032
//G01 X219.2114 Y271.5416
//G01 X216.9473 Y273.9889
        if(strncmp(newline,"G01 X",5)==0)
        {
            if(do_xy()) printf("lineto\n");
        }
        
        if(strncmp(newline,"G00 Z5.0000",11)==0)
        {
            printf("closepath\n");
            printf("stroke\n");
        }
        
        
        
    }



















    printf("showpage\n");


}
