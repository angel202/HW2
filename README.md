# HW2
Name: Angel Gonzalez 

PSID: 1577688

I ran everything in visual studios. I downloaded freeglut, glew, and glfw. All the packages downloaded were installed where your project is located in your computer. For example mine is at: 
C:\Users\angel\source\repos\testrun\testrun 

I followed this guide to install freeglut: 
https://heavenkong.blogspot.com/2018/03/opengl-installation-of-opengl-with.html


Problem 1: 

The teapots in a rotation. I used glPushMatrix to start at (0,0,0). I then centered the first teapot with gltranslated. With that being done I then set the size to .15. From that teapot I was able to run a forloop to reproduce all the other teapots and get it as close to the image provided. 

Problem 2: 

I did the staircase image. It was a bit more difficult but I scaled and centered it as best as I could in my gltranslatedf(). I wasnt able to get it perfectly but I played around with many different numbers until I thought the image looked as close as it could. I also ran a double forloop to continue printing the images and scaling them to go down. I also implemented the pow() function for scaling. 

Problem 3: 

My scaling is somewhat off and the hand isnt perfect as I couldnt figure out how to get the thumb to extend at an angle and not look weird. I did a "Rock on" hand design. For this I also implemented glPushMatrix(). I used glScaled() to try and make everything even. glTranslated() was also used to position everything in place all the cubes etc. The hand was build with basically those three functions.
