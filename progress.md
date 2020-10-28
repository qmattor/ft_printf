10/21/20:
    Since my updates have been sparse so far, I will just give a brief
overview of what I've done so far:

    I started by creating a system to print out the variable when called for
(ex: %d) as well as the surrounding text. After that I tried to add a system
for managing the mods (ex: %#015x) and after trying to integrate that into the
system and failing, I realized that a rework is probably for the best. I
commented out my old code (variable_param.c) and started again with parsing.c.
After rewriting my code into a more workable system, I was happy with how it
worked, despite a couple of flaws. I worked on debugging the flaws and wrote
the write routines. At this point I hadn't worked in the length modifiers yet.
I thought about how to achieve this, and came up with the solution that each
size would need its own routine. After thinking about it some more, I realized
that my itoa function, if adapted to be able to manage an unsigned long long
would work the same for any variable passed to it if casted properly. I made a
new routine infotoascii which just calls the proper itoa function (unsigned vs
hex vs octal, etc). I now need to test and debug the project.

    For today I need to test and debug basically everything and look at edge
cases for each piece of the project. When I'm done with that, which will
probably be a day or two, I need to update the make file in order to make the
program compile into a library function, rather than compile as a program.

Issues found while debugging:
    1:
        when printing an unsigned long long, the number is not fully printed
        after 10 digits.
    2:
        segfault when no width specifier
    3:
        printing 2 strings says invalid mods
    4:
        left just and '+' modifiers adds an extra space at the end
    5:
        the '0' and '+' or ' ' mods put the + or ' ' in the wrong spot

I have to rewrite the function because the signs are messed up with the
0 modifier

I have tested every combination of mods I can think of, and everything now
seems to be working as intended.

I just made a couple quick adjustments to fix the program from leaking.

I added the final touches to the comments and I think its ready