## Collision-Balls
This is a part of the assignment during the course C program at ISAE-SUPAERO for first-year students.  

## Collision detection
This project implements collision detection between several balls. The balls are represented by structs that contain their x and y coordinates, their radii, and their velocities. The main function creates two balls and checks if they collide with others or with the wall. If they do collide, the code calculates the new velocities of the balls and updates their positions. Finally, an animation will be visualized on a new screen.

## Getting started
To run this project, you will need to have a C compiler installed. Once you have a compiler, you can compile the project by running the following command:

* `make *target file`

Here `*target file` is the name of file that you want to run. (See the Makefile to extract more details)

Example:
* `make compile-all` - Compile all program.

Once your program has compiled, there is `.o file` in the main dictionary.
Following command:
* `./clash-of-particles-naive-file` - Run the program

## Contribution

This program is run by the 'naive' version, which means this will cost a lot of time and energy if the number of balls is large (> 100). To address this problem, **I need your help**

## Dependencies
* <stdlib.h> 
* <stdbool.h>
* <stdio.h>
* <math.h>
* "disc.h"
