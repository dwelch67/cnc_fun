
You are going to think I am crazy, but here goes...

Most of these start off as postscript.  Yeah, but you know it is really
THE way to to do 2D things.  For example if you are struggling to print
labels on your printer, just write a simple program to generate some
postsript.  In this case moveto, lineto, arc, closepath, and I generated
all of these patterns.  In some cases ps2pdf, pdf2svg and then into
inkscape.  Some I can just generate some simple rectangles and have them
overlap in a corner then in inkscape can select the two that make up
a corner and path->union to make them one rather than have the program
that generates the postscript do that work.  In some cases I did all
the math in the original postscript.

bigbasic is my first one of these and you can see that I did all of
the work in the C program and the svg that comes out of ps to pdf to
svg is ready to go.  The process for bigbasic was to use postscript to
make a grid, then gimp hello.ps (resolution 400) and then use the bucket
fill to fill in the grid squares to manually create the design.  For
most of these I want 45 degree angle weaves but did all the work with
horizontal and vertical.  You can see some if(0)'s in the code (and
I am still cleaning that up in some/most I have hundreds of %! at
the beginning of the file, oops.  atril and gimp didnt care.  From the
hand drawing on the grid then I program rectangles vertical and 
horizontal and sometimes curves.  Then ps to pdf to svg then into 
inkscape for scaling, conversion to dxf as needed, etc.  estlecam, cut2d,
aspire, jscut, etc are happy/content with this path.  

For some and lets take five/small as an example.  I didnt want to do all
the math.  Computing intersections of circles and circles and lines and
such.  So the basic path was make an image then in inkscape use the
edge detect to make vectors from the image.  Now the problem is that
you may know the answer to but I am not smart enough is that you get
one path for the whole drawing.  Which estlecam seems to be content with
but others just cant handle it.  hello.c generates some circles.  Then 
gimp hello.ps, I use a resolution of 400.  I start with 0.1 setlinewidth so that when multiplied in gimp it is still
one pixel wide lines at that resolution in gimp.  I do a lot of hand 
cleaning in gimp to create the actual design.  five0.png being the 
result.  five1.png is there both to show/share the design but also 
with those fills confirms I did not leave an gaps in the paths which
can cause some problems in the svg.  inkscape five0.png and tracepath
with edge detection is what I do and I crank up a number of the 
settings to make the paths/vectors better.

Here is where it gets crazy.  I was using estlecam a lot, but maturing
my work to not just cut the inside out of a hole and hoping the cutout
doesnt bounce around and interfere, I hate leaving a tab as it takes
a lot of sanding or shows marks.  I then spent a lot of time messing
with estlecam and aspire/cut2d and jscut.  To find I like jscut's pocket
the best, makes a super clean pocket and not leave marks.  In this
process found that the ones like bigbasic all the tools are happy with
the svg/dxf, but tracepath with edge detection only estlcam is able to
cut pockets the others you have to do a lot more work.  A guy started
to think, well, estlcam is/can cut a hole with patterns like five/small.
So I decided to tell estlecam to engrave on the line itself, and then
turn that into postscript moveto/lineto.  And now we are like bigbasic
we have individual postscript paths for each hole or the outline. And
like bigbasic we ps2pdf pdf2svg then inkscape that to scale and make
dxf/svg files for the other tools.  And now all of them are happy,
estlcam, aspire/cut2d, jscut.  And actually inkscape/estlcam did a good 
(enough) job of making nice making smooth lines/curves.  I can probably
figure this out with larger page sizes, but may have to go through this
a few times or do some scaling, I perfer to use larger numbers like
a few thousand units by a few thousand, but ps with a stock letter
size page you cannot have the postscript, in units of points to go
much past the 8.5x72 = 612, You can if the path has a portion that is
within the page, but if the whole path is off the page then the ps2pdf
and such will discard it.

You can watch all the videos you want, and as with me talk to a buddy
about this and go back and forth with, "I figured it out".  Nope, didnt.
Im telling you there is NO consistent solution.  You have to exercise
your anger management with distractions or violence to the keyboard or
something.  Please do not take it out on others.  The videos and tutorials
will tell you, that on inkscape, above the top ruler  you can select
mm, in, cm, px, pt, etc.  And then you click the lock between W and H
(width and height) and then set your W or H for your desired size of the
piece.  Then you go into document properties, match the units, at this
point you are probably an inches person or a millimeters (or maybe
cms) and make all of them match.  Clicking resize to content in the
document properties.  If saving as dxf unchecking the use document as
base unit (at one point inkscape would fail to save with some python
error, until I found this), setting the units in the dxf save as to 
match your mm or in or whatever.  And this may work great for you for
a while, one time or a hundred.  And then, maybe you try another tool or
maybe the stars come out of alignment and the units go all to hell.  I
have had periods of time that if I use pixels all the way through
then use an svg into estlcam and tell estlcam these are mm, while the
file says pt or px, dont remember, estlcam is only happy if I do pt
or px or a mixture of things on the way out of inkscape.  Then estlcam
or other is happy.  Take the dxf path instead of svg path into these
tools, then hold your mouth differently.  And then when you think you
have mastered it.  It goes to hell again and you just cant figure it
out.  I love that aspire for example when you click on mm from the
default of in on the opening setup, the x doesnt change a total number
but y changes or vice versa...Why?  Is it doing a conversion, did it
not read the file right, are they crazy?  The short story here is 
getting from inkscape to your tool to generate the gcode, you will
have some success and some failures with the units, you need to of
course take the time to confirm this so that you dont slam your machine
into end stops or end switches, drill holes in the table, etc.  Sad
but I was happy to find that a friend was having the same problems, it
was not just me.  Those videos online are great to get us this far but
end of the day it is the tool after inkscape that uses or ignores or
feels like it has to do a conversion of the units it sees in the file
and, naturally, each tool needs its own solution.

Right now I have a grbl v1.1 controller.  I actually like the jscut
results over the fancy tools.  You can see that I re-invent wheels 
constantly.  And jscut is my speed.  And probably the second after
I post this readme, it will create a mess that causes me to give up.
Some tricks are to exit and re-run the browser.  Select make all mm
first.  Set your pass depth to be your FINAL DEPTH if you are cutting
stuff out first then LATER set it to the per pass depth.  As you take
a path and then say create operation it takes the PER PASS depth as
the total depth not the THICKNESS. Probably a simple fix in the 
javascript but I have not dug in.  I like to make my step over like 0.8
or 0.9.  I dont get the whole rapid thing, why not use G0 instead of G1?
You control the cut order, I do not know how to delete/undo things so
just close the browser open it again and start over.  If you hold your
mouth right save settings/open settings is basically how you can save
the whole project and open it again later (seems like you need to 
leave the settings file in the same place you saved it and not try to
move it to some other directory for it to work).  All of these tools
estlcam, cut2d, etc have their own nuances and learning curve.  Aspire
or cut2D seem to have some formula for getting you from bit size and
number of flutes to feed and speed and depth per pass.  But it may
cost you a few broken keyboards or mice through the drywall with that
tool trying to actually use the bit you created.  I just hate having
to run windows in a virtual machine to use tools like this so want to
try to stick with tools that run on linux.  You need to at least add,
and remember to add to not break bits/machine, to start the spindle
when using jscut, for example.

Before jscut code

G21
G90
G94
M03 S12000
G00 Z5.0000


after

G0 Z5
M05
G0 X0 Y0
G0 Z0
M30

NOTE!!!!  If for example you want to do a 10mm deep cut at 2mm at a 
time with jscut, it will generate the 10mm last cut twice for some
reason.  Which if that frees your design it will chew it up on the
extra pass.  No matter what too, estlcam, aspire, etc, I do hand
tweaking of the gcode after as nobody can generate what I want.  I 
used to write my own gcode and still can, but it is nice to let the
tool do the bit width math for me in cutting inside and outside.  So
with jscut if I want a 20mm cut at 2mm per pass, I will set total
depth to 19, this results in 0,2,4,...18, and then ONE pass at 19.
Then search and replace the Z-19 to Z-20 or give it a little more if
you are like me and want a clean final pass and dont care about chewing
up the spill board.  (one 2x4x1/2 mdf gave me many spill boards)

I rely on camotics mostly to do test cuts of my design and not actually
burn through material.  There may be a way to fix this but I dont like
their measurement of the whole design.  I might want 170mm total for
example to cut something into/through a 1/10 board, camotics will say
it is 190 something minus 9.  https://nraynaud.github.io/webgcode/ 
is what I use to get a better feel for the overall dimensions (and
after all the work maybe have to go back to inkscape and start over).
Rough estimate on duration, but everyone has their own estimate which
for some reason does not match each other.

I have written my own sender, and have had frustrations and moved
back to it from time to time.  It sends one line at a time and waits
for it to complete so the overall time is longer and for curves that
are not g02/03 it is a lot of herky/jerky.  But for a bit now have
been using chilipeppr with its sender on a raspberry pi.  I have had
issues and so go through some rituals.  I disconnect from the uart on
the pi and select the chilipeppr logo before exiting the browser.  I
exit and reopen for every cut even if it is the same design.  (one
time it cut a design that I had cut before even though I had opened
and it showed the new one I had opened).  I ssh into the pi and use
minicom to connect to the grbl controller and use ? to see where things
are. If for example you do not have your gcode return z to zero.  And
then go in and depending on how you set your Z zero the next time you
may have it where you think zero is but the controller from the prior
run has it as your clearance/movement level say 5mm.  So the controller
thinks your zero point is 5mm down and that makes for some nice noise
and damage and may even start to dig into your machines table if you
have soft enough material and a good enough bit, and or it just breaks
the bit instantly.  So I always leave chilipeppr with the uart unchecked
and go in with minicom and VERY CAREFULLY type commands (since you cannot
see them and if you oops it you will break a bit or slam an end/hard stop
or something).  Clear any alarms, make sure it is x0, y0, z0 before
you start.  If you have the tool set then I do not know of a hard
reset that will work without going to the machine and resetting the
controller board or powering cycling other than...Reboot the pi, you
may have an alarm which you $X to clear but that will hard reset the
grbl controller to all zeros position so you can sit at your desk in
the house with the wyze cam and not have to hike back to the garage/shop.

I have had problems with my 3020 pro max stock controller, that I do
not remember having with my 1310, I did almost immediately upgrade my
1310 to a sainsmart controller, but the 3020 is also a sainsmart,
different one from the 1310.  So here is how this works...with these
grbl certainly as well as other controllers.  You have lines of gcode
that you send over a uart interface (for a lot of these, certainly 
higher end may have other solutions).  Ideally you want the controller
to have at least some number of lines/commands queued up.  For example
if you disable G02/03 from estelcam as some folks recommend, you
end up with a gazillion wee bitty steps, tens of thousands of lines
of gcode.  Send these one at a time and wait, your machine may even
start shaking with the start/stop.  Now with grbl I have not yet
figured out how you can determine how many you can keep in flight, 
although I have no desire to push the fifo to its max, and maybe
that is how these controllers work but even with one command at a time.
You send the command you get an ok back and then you can use ? (grbl
at least I do not know marlin yet) to get the Idle/Run/Alarm status
and position if you care to parse that.  Send five/ten commands and you
get five/ten ok's and then can watch for idle.  My sender is one at
a time, very K.I.S.S...okay the punch line.  There can be a handshake
problem, and perhaps it is only with my 3020 controller and not my 1310.
The last time I did see a message on chilipeppr that I need to see if
it is there any other time and see if it lines up with this issue.  
The machine just stops, it is no longer cutting, the bit is spinning
but the status from the controller says Idle.  Basically a command
was sent to the controller and an ok never comes back, so the sender
waits forever for the ok.  Fortunately I know enough to be dangerous so
I ctrl-x to stop everything manually z up and move x and y to 0 then
z 0.  I look at what part of the design it stopped on, and I hack up the
gcode file to the beginning of that hole and start with a new, modfied
file.  The sender may have a skip to line but I have not used it.  I
go through removing parts from the gcode file, using camotics to see that
I am at the right place, zero the machine using gcode, reset chilipeppr
as if it were a new cut, and continue.  So far this has worked.  I may
investigate a new controller board, maybe move to a marlin based one.

The 1310 controller had/has its own issues where it will skip commands
so there might be a Y 10, x10, y-10 ... and say one y-10 might just
not get executed, so now you are out of position and ultimately aiming
for an end/hard stop on your system, certainly trashing the project, 
etc.  I was doing things as simple as some rectangles and one dimension
against a ruler was off from another.  Cut a square you get a rectangle.
This lead to my own one line at a time sender and that solved those
problems o the 1310 upgraded controller.  I think I had them on the
stock controller as well.  The upgraded did half steps on the stepper
motors so gave that much better control over the accuracy, etc.

My 1310 and 3020 are screw based not belt, aluminum not plastic nor mdf.
Can cut metal but I use them for wood.  Yes they are small but I am only
doing small things.  So I like how they are built but they are relatively
inexpensive and these are cheap controller boards no doubt.  Even with
a professional level system there is still the problem above of getting
from zero to gcode.  Then you may or may not have the problems I have
with the controllers, etc, but between the learning curve of the tools
and whatever other problems you run into you need to just grind through
it, buy a lot of bits (first off that is a whole other learning curve
bits, feed and speed, etc) a lot of wood to cut, start cheap with pine
or the basswood or birch plywood and then work up to oak and others.
(price more than anything)  Can even do syrofoam or other cheap stuff.
Point being you have to cut through and toss a lot of stock and burn
through a number of bits, to start to gain the experience.

Sawdust.......I dont have asthma but have allergies, very quickly 
figured out I was breathing in a lot of sawdust.  With the 1310 I would
just let it do its thing, this was 5/6mm stuff.  And the sawdust would
very nicely be in a pile/layer over the top could just vacuum it up
when done.  The 3020 even at, in theory, lower rpm (I wonder maybe I
am at max rpm all the time, hmmm) it sprays the sawdust about the 
workspace, depending on the bit and depth, leaves a large mess.  In
both cases finer particles are suspended in the air waiting for you to
inhale them.  Possibly my bad luck or other, this was also a struggle
and if you watch videos you see others struggle as well.  In the end
I bough a nice air handler/filter, not too expensive about $150 on
amazon, not a house hepa thing but an actual shop one.  I have a nice
shop vac anyway, got one of the hobby cyclone things and a bucket
and some various bits of hose.  Dust shoe at least for the 3020, hose
for that, etc.  With these small hobby things they are not 2.5 inch
fittings for the dust collection so adapters, good to have a buddy with
a 3D printer to print adapters (but these are the rules of life anyway
if you do not have a truck you need a friend with a truck and buy them
some pizza and beer, and these days need a buddy with a 3D printer if
you do not have one (talk about a learning curve)).  Your experience
may vary based on the specific vac, hose, cyclone, hose, dust shoe, etc.
As to how much lands in the bucket and how much goes into the vac.  If
you read up on even multi/many thousand dollar professional systems the
cyclone only picks up the larger particles, the fine stuff needs another
solution. While the filter and the cyclone helps get it out of the air
the fine dust landing in the shop vac coating/filling that filter means
making a mess and putting fine dust in the air cleaning out the shop 
vac.  Where I am now on this is vacuum bags in the shop vac just like
good old vacuum bags on traditional vacuums (they make ones specific
for your shop vac.  The nicer filter on the shop vac, the cyclone of
course.  And either N95 (not KN95) mask or a reusable resperator.  Even
with a nicer setup or with a shop vac setup and no visible dust in the
shop vac filter, there is still fine particles making it through.  And
you can look it up for yourself that it is not just a case of dust in
the lungs that reduce your oxygen that you have to then steam out or
whatever, but it gets into your body. X type of wood gives this kind
of athsma, Y type of wood gives this kind of cancer.  And that is just
the natural wood dust, then if you get into treated wood or you are
using glues or other chemicals and start breathing that.  If nothing
else actual N95 masks with the around the head rubber bands, kn95
might have the equivalent filter but around the ear does not make the
same seal so the filtering properties are bypassed.  YMMV...

For now myself and a buddy have both given up on the dust shoe skirt.
I spent time adjusting the depth of the bit in the machine so that
the skirt was almost/just touching on the last pass (so as to not
get into the cut and/or not knock the shoe off and have it get into
the spindle/bit)  And so far it is working fine, minimal cleanup after.
Been doing a lot of 3/4ths inch/19mm stuff so lot of delta from top to
bottom, I did buy some nicer, long bits, the shorter less expensive ones
are not even long enough to cover the 3/4ths plus skirt length anyway. YMMV.

Amazon has many bits, it is almost frustrating trying to figure this all
out, looks like walmart.com has significantly more to choose from, more
than I have time to wade through.  I have some favorites now for 3/4th
inch oak (1/8th inch bit) but still trying to find a favorite for 
smaller/thinner stuff for smaller designs (1/16th, 1.5mm, 1mm 0.5mm (yeah
really)).  I highly recommend getting both a 1/8th and 1/4th inch collet
and a spare nut...Figured out by failing and then getting lucky with
a website, that you do put the collet in the nut first, it clicks in
there, then the bit wont get stuck in there AND the bit wont be crooked
and wobble when tight.  Having a spare nut for the 1/4th inch shank
bits, means you dont have to pop the collet out of the nut each time
you want to change between shank sizes.  There are many different size
collets but at least at walmart and amazon for these types of hobby
machines the bits are either 1/8th or 1/4th inch shanks.

Soft wood tends to tear out more than hardwood.  Speed and feed affects
the tearout and also the quality of the cut, how much sanding, etc.
Sharpness of the bit, yes some of these $20 bits I have only been able
to use for less than 10 things at a couple-handful of hours of cutting
time each thing.  I am still learning feed/speed/depth per pass though.
Going too slow can heat up the bit and age it as well as going to fast.
Then again there are so many different bits, number of flutes of course
but the corn cob ones vs not, etc.  What the bit is made of or coated
with.  This/these 0.5mm bits even into soft wood, yeah 0.25mm per pass.
I saw someone say and saw aspire do this as well, that the depth per pass
being half the diameter of the bit.  Four flutes is four times the
cutting edges than one flute.  At the same feed rate the one flute
makes deeper cuts as the bit moves four times further forward than the
four flute per revolution.  So you can and want to run more flutes at
a higher feed rate to not heat up the bit.  Making too much fine dust
speed the rate up, chunks too big, slow down.  

There are too many videos and websites and opinions.  In theory this
stuff should be easy and software should do all the work, but it doesnt
so you have to go through a learning curve.  Everything I have written
above may fail miserably for you, or it might help.  Every inkscape
video and there are a ton of them, may help or may just lead to more
frustration.  

For decades though I have turned to postscript as a starting point for
various things from barcodes to label printing but also just art getting
something I can feed to gimp that I find easier and much more accurate
than tring to make lines and circles in other tools manually trying
to center the circle or angle the line.  The breakthrough was that you
can simply apt-get a pdf2svg program.  The other was that inkscape (and
others) have a trace from image solution to get paths that can be cut.
I dont mind spending an hour or two erasing pixels in gimp to make a
design, but I do mind spending hours in these other tools that are
not intuitive or are just not well done software.  Was a time there I
was able to crash inkscape literally measured in minutes.  I would have
to save after every two or three things I as doing (separating/combining
paths together) otherwise I would lose it all the next crash.



