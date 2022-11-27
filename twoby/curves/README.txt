
This starts with twoarc which in that case also starts, in my process,
with these grids and I fill in by hand with corners.  And build the
postscript from that.  Then I put corners on it.

I learned about the path->union button in inkscape to combine paths
so that I can do things in straight horizontal or vertical rectangles.
Then can do that with arcs as well.

twoarc was fine as is, but if I widen it, with corners it is fine. 
But if you look at how the corners are in twoarc, look at the inner
square that is part of that half circle.  I started with that and
you can see the code commented out.  But where the middle arcs are from
a height between them and then the corners, the corners are smaller
and it looked a littne funny.  So I had to do a little math.

    rad=6*6;
    rad=rad*2;
    rad=sqrt(rad);
    adjustment=rad;
    rad=4.5*4.5;
    rad=rad*2;
    rad=sqrt(rad);
    adjustment=adjustment-rad;
    adjustment=adjustment-1.5;

Bumping those out that much allows the tangents to line up across the
sides.

Also I dont need to do the 45 degree rotation in my code, and just
do that in inkscape.

You can see the difference between twobycurves.orig.svg and 
twobycurves.svg after using inkscape to make my life easier.

