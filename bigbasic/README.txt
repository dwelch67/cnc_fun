
This was really my first exercise starting with these basic square
corner weave patterns.  I simply counted how many corners on a side and
then made this generic program to generate N number of corners.  We
were curious about what a 1000 corner one would do, if the tools would
handle, it.  But even 100 corners starts to be big files, that the tools
were okay with but would take you a very long time to select the hole
cuts unless your tool has a way to select many at once.  And then the
cut time would be LOL, an eternity, if you even had something big enough
to make the holes larger than your smallest bit yet large enough work
surface.

Anyway run make and then run go.bat to make the svgs.  Can change
the main() program to generate larger number of corners but larger than
10...have fun...

arc directory is the same but the corners are rounded.  I figured out
with twoby that the corners are smaller than the sides, but I have not
tried to fix that here.

My process for now and will remain to some extent is to use postscript,
moveto, lineto, arc, arcn, etc to generate the rough design, if not
final.  Then convert that to svg and inkscape to dxf.  I have gotten
a little better at inkscape but it is also infuriating.  I want a simple
path/vector/node editor tool for linux for 2D.  Put a node at a crossing
point select a set of nodes to make a path from, simple.  I would still
use postscript to generate the lines/paths and then would use some other
tool to group the nodes, saves a ton of math.

Also note five.png I use postscript to give me a grid then gimp to
paint in the blocks to make the patttern, then use the grid to write
the postscript.

