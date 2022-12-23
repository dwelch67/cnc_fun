
This one is kind of fun.  

Basically, what it was supposed to be.  Is make arcs from the top left
to bottom left corner.  Walk the middle of the arcs across evenly. 
And repeat from the other side so they intersect along that middle
point.  And from some three point circle googling I ended up with 
something someone got from wikipedia.  BUT...its not quite right
it looks okay though.  Maybe I try to get it right on another
go around.


Change this number 2,3,4...to make the thickness.

    printf("4 setlinewidth\n");

    bx=110;
    for(ra=0;ra<5;ra++)
with
        bx+=20;

or

    bx=120;
    for(ra=0;ra<5;ra++)
with
        bx+=20;

both make interesting patterns I think I like the first one better;


could do this too

    bx=105;
    for(ra=0;ra<10;ra++)
with
        bx+=20;

    bx=110;
    for(ra=0;ra<10;ra++)
with
        bx+=20;

have fun cutting that!!

Okay that is right, it is doing the circle math correctly.  The circles
quickly get to a point where they would go outside the box.

        arc(xc,yc,rad,0,360);
and/or
        arc(200+(100-xc),yc,rad,0,360);

will show that.



