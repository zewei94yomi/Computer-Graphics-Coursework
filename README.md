# Computer-Graphics-Coursework
COMP3055 – 2020 Autumn – Machine Learning Coursework - Scene Building

Please read 'CG_2020_20029947_REPORT.pdf'.

# 1. How to run the program

1. **Use Xcode**. I developed the program on a Mac machine by using Xcode. The whole project should not be opened on the computer desktop but opened in ‘Downloads’, otherwise it wouldn’t be open. Then open ‘G53GRA.Framework’. It’s wired but true. **Again, don’t copy the project file to the desktop, leave it in ‘Downloads’.** **Otherwise, you won’t be able to open it.**

2. **Copy sources**. 
   1. In ‘G53GRA.Framework’, open ‘G53GRA.Framework.xcodeproj’ which is a XCode project file.
   2. Run the program. Please be patient since it will probably take about 10 seconds to build the project. It will build successfully but won’t run correctly. You will see the errors as following. ![clip_image001](https://cdn.jsdelivr.net/gh/zewei94yomi/ImageLoader@master/uPic/clip_image001.png) ![clip_image002](https://cdn.jsdelivr.net/gh/zewei94yomi/ImageLoader@master/uPic/clip_image002.png)
   3. Now go to the ‘Product’ and open the file in folder. ![clip_image003](https://cdn.jsdelivr.net/gh/zewei94yomi/ImageLoader@master/uPic/clip_image003.png)
   4. **Copy sources**. In the ‘Products’ folder, you will see there is only one file. Now you will need to copy all source files (.files and .bmp files) in ‘Sources’ folder to this folder. ![clip_image004](https://cdn.jsdelivr.net/gh/zewei94yomi/ImageLoader@master/uPic/clip_image004.png) ![clip_image005](https://cdn.jsdelivr.net/gh/zewei94yomi/ImageLoader@master/uPic/clip_image005.png) ![clip_image006](https://cdn.jsdelivr.net/gh/zewei94yomi/ImageLoader@master/uPic/clip_image006.png) ![clip_image007](https://cdn.jsdelivr.net/gh/zewei94yomi/ImageLoader@master/uPic/clip_image007.png)
   5. Now you should be good to run the program.

3. **Run the program twice if necessary.** Since I am suggesting opening the project in ‘Downloads’, the Mac OS system will probably warn you that you are accessing files in ‘Downloads’. Just click ‘OK’, stop the program and start the program again. Ignore printed warnings and errors. ![clip_image008](https://cdn.jsdelivr.net/gh/zewei94yomi/ImageLoader@master/uPic/clip_image008.png)

4. **Use keyboard and mouse to move the camera**. ‘W’: move forward; ‘S’: move backward; ‘A’: move left; ‘D’: move right; ‘J’: move upward; ‘K’: move downward; ‘space’: reset the camera.

5. **Object interactions**: ‘1’/’2’: open/close the door; ‘3’/’4’: open/close the closet; ‘5’/’6’: open/close the drawers; ‘7’: rotate the tellurion; ‘8’/’9’: open/close the window glass; ‘e’/’r’: pick/throw the dart; ‘t’: play the basketball; ‘f’/’g’: turn on/off the fan; ‘z’/’x’: take off / land the plane; ‘c’/’v’: get in/off the hot air balloon; ‘,’/’.’: turn on/off the room light; ‘[’/’]’: turn on/off the sunlight.

 

# 2. Scene Screenshots

1. Inside view ![clip_image009](https://cdn.jsdelivr.net/gh/zewei94yomi/ImageLoader@master/uPic/clip_image009.png) 



2. Outside view ![img](file:////Users/ryan/Library/Group%20Containers/UBF8T346G9.Office/TemporaryItems/msohtmlclip/clip_image010.png)

 

# 3. Project Requirements

1. **Objects** (Object images won’t be shown in this section due to the great number of objects)

   - **Own-created objects**

     - **Room**. ‘Room’ object contains the framework of the room, the door and the window. The walls are created by drawing solid cubes and scratching them to the appropriate sizes. Then texture images are added to the surface. For convenience, the door and the window are created within the room class. They all have the animation for opening and closing. The door can be opened or closed by rotating the door. The window can be opened by transforming the glass. Also, the window is drawn in transparency. You can see the outside through glasses.

     - **Door**. Door. The door object is actually defined and created inside the Room object, which means there is no .cpp or .h file for Door object. Door object has a frame which is created by calling ‘glutSolidCube’. The door plank is created also in such way and it has a wooden texture to improve its realistics. Besides, it also has a door bar to open the door. When the door is opening, the bar will rotate

     - **Window**. The window is drawn with transparent glasses. You can see the outside view through the window. I drew two solid cubes to represent glasses and colored them with half transparency.

     - **Walls**. Walls are covered by wall papers.

     - **Bed**. ‘Bed’ object is constructed by creating two solid cubes and scratching them. It has two parts which are covered by texture images. There is an imported object, ‘Pillow’, which will be introduced in ‘Imported Objects’ session.

     - **Closet**. ‘Closet’ object contains several boards. It has three wooden boards, two doors, a cloth hanger and interlayer. Similar to door object, the whole closet was built by scaling solid cubes instead of drawing quads, which makes it look like a real closet because closet’s wooden boards have thickness rather than planes with 0 thickness.

     - **Desktop.** ‘Desktop’ object is constructed by combining several boards and two drawers. All surfaces are covered with texture images. You can press ‘5’/6’ to open/close the two drawers. 

     - **Clock**. On the wall, I created a clock which shows the current time. The clock consists of the dial plate, 3 pointers (second, minute and hour). The clock will update itself in every second. The time it gets is from the computer system rather than the variable ‘deltaTime’, so it is more accurate. Detailed implementation can be found in ‘Clock.cpp’.

     - **Dartboard**. Similar to the construction of the clock, dartboard is created by drawing several circles.

     - **Tellurion**. This object has a sphere and a base. The sphere is covered with an earth texture image. You can rotate the tellurion by pressing ‘7’. The animation I implemented is smooth. The tellurion will firstly speed up and then slow down. It has an acceleration speed.

     - **Basketball**. In the project, ‘Basketball’ is implemented in ‘BouncingBall.cpp’ and ‘BouncingBall.hpp’. The bouncing ball has an interaction and animation. Users can press ‘E’ to bounce the ball and the ball will bounce with the effect of gravity.

   - **Imported objects**

     - **Chair.**

     - **PC**. The PC is covered with a texture image which represents the wallpaper.

     - **Dart**. You can pick up the dart by pressing ‘E’ and throw it by pressing ‘R’. When you pick up the dart, it will move with your camera view. It is like you pick up an object in real life, which the dart will move around you.

     - **Fan.** ‘Fan’ has an animation which is rotation. You can press ‘F’/’G’ to control the fan. The animation is similar to the tellurion. It is smooth.

     - **Bulb**. ‘Bulb’ is half transparent. It can be lightened and extinguished by pressing ‘,’/’.’. 

     - **Pillow**. 

     - **Hot Air Balloon**. This object has an animation which is flowing. You can take the hot air balloon by pressing ‘C’ and get out of it by pressing ‘V’. I implemented a distance check. You can only get on the hot air balloon if you are close enough to it.

     - **Plane**. This object has two animations which are taking off and landing. The animations are smooth. For taking off, it will firstly speed up in slow pace, and then speed up very quickly until reach its maximum speed. Landing has similar smooth animation. You can press ‘Z’ to let the plane take off and press ‘X’ to let the plane land.

     - **Boat**. This object has one animation which is flowing in the river. 

     - **Sofa**.

     - **Table**.

     - **Bin**.

   - **Scene objects**

     - **Ground**. This object is a quad with very large area. It looks like infinite, but it has fixed size. 

     - **Skybox**. Skybox is implemented by drawing six quads and combine them to each other. Different texture images are covered to quads. Similar to the ground, the size of the skybox is very big so that you will not find the boundary of the scene. It makes the scene/world look infinite. 

     - **Road**. This object is used for the plane to take off and land. It has no animation.

     - **Water**. This object is constructed by repeating a water texture image. Also, it has an animation of flowing. In another word, it’s not a still river. It will change itself according to the current time.  ![clip_image013](https://cdn.jsdelivr.net/gh/zewei94yomi/ImageLoader@master/uPic/clip_image013.png)



- **Transformations & Animations (Details will be shown in demo videos)**

  - Door: Opening / closing

  - Closet: Opening / closing

  - Drawers: Opening / closing

  - Windows: Opening / closing

  - Clock: Ticktock

  - Dart: Pick up / Throwing / Moving with the camera view

  - Tellurion: Rotation

  - Basketball: Bouncing with the effect of gravity

  - Fan: Rotation

  - Boat: Flowing

  - Water: Flowing

  - How air balloon: Flying

  - Plane: Taking off / Landing

3. **Textures**:

- **Implementation**: Texture images are read by ‘Scene’ using ‘GetTexture’ function. All texture images are kept in ‘Textures’ folder. 

- Many own-created objects are covered with texture images. 

  - **Ground** ![clip_image014](https://cdn.jsdelivr.net/gh/zewei94yomi/ImageLoader@master/uPic/clip_image014.png)

  - **Water** ![clip_image015](https://cdn.jsdelivr.net/gh/zewei94yomi/ImageLoader@master/uPic/clip_image015.png)

  - **Wall **![clip_image016](https://cdn.jsdelivr.net/gh/zewei94yomi/ImageLoader@master/uPic/clip_image016.png)

  - **Closet **![clip_image017](https://cdn.jsdelivr.net/gh/zewei94yomi/ImageLoader@master/uPic/clip_image017.png)

  - **Tellurion**, **Desk, Drawers** ![clip_image018](https://cdn.jsdelivr.net/gh/zewei94yomi/ImageLoader@master/uPic/clip_image018.png)

  - **Bed**
  - **Basketball**
  - **Floor**
  - **Door**
  - **PC Desktop**

4. **Different Viewpoints**

   - In this program, there is a camera object and you can change the camera view by pressing ‘W’, ‘S’, ‘A’ and ‘D’. Also, you can press ‘J’ and ‘K’ to move the camera upward and downward.

   - In addition to the camera, there is a hot air balloon. You take the balloon and it will take you to the air. Your camera view will change according to the height of the hot air balloon. 

5. **Lighting effects**

   - To create lighting effect in a fixed position, I change the way in which we normally draw the lighting. The program will firstly draw all objects to the scene, and then it will draw the lighting, otherwise, the position of the light will change according to the position of the camera. 

   - **Room light**. Room lighting is fixed within the room and it will not go out. But since the window is transparent, light will go out through the window. Shading is also implemented in the scene. All surfaces have normal vectors. You can turn on or off the room light by pressing ‘,’ or ‘.’. ![clip_image020](https://cdn.jsdelivr.net/gh/zewei94yomi/ImageLoader@master/uPic/clip_image020.png)

   - **Sun light**. Similar to room light, sun light has a different position and it will create different shading effects. You can turn on or off the room light by pressing ‘[’ or ‘]’.

   - **Important notes**: After testing for many times, the commands for turning on or off the lighting will fail sometimes due to unknown reasons. I suggest you add a line of code to ‘Engine’ class. For example, add “printf(“”);”. Then run the program. The lighting effect will work as expected.

6. **Creative ideas**.

   - **Gravity**. In this program, gravity is implemented to make bouncing objects more real. Precisely, the basketball is the bouncing object in our program. When you press ‘T’ to play the basketball, it will firstly go up. Due to the effect of gravity, the speed will reduce to 0. When the speed is 0, it will then go down and speed up at the same time. When it touches the ground, it will reduce energy due to friction. Eventually, it will stop.

   - **Dart movement**. When you pick up the dart, it will move around with the camera. It uses complex calculation to work out the right direction and position. Such animation can be used for other animation such as picking up a gun and shoot (FPS games). 

   - **Smooth animation**. All animations in this program are smooth. For example, the basketball and fan have an acceleration speed. Plane even has an acceleration of acceleration speed for more smooth animation.   

7. **Good code structure**

   - Used object-oriented programming 

   - Used and extended the given framework (pure glut library)

   - All objects are created in ‘MyScene’ class, in ‘Initialise’ function

   - All objects inherit ‘Displayable’ class, some also inherit ‘Animation’ or ‘Input’

     - ‘Displayable’: To be displayed in the scene, has a ‘Display’ function

     - ‘Animation’: To be updated in the scene, has a ‘Update’ function

     - ‘Input’: To handle mouse and keyboard input 

   - Project structure: 

     ![clip_image025](https://cdn.jsdelivr.net/gh/zewei94yomi/ImageLoader@master/uPic/clip_image025.png)

     ![clip_image026](https://cdn.jsdelivr.net/gh/zewei94yomi/ImageLoader@master/uPic/clip_image026.png)

     ![clip_image027](https://cdn.jsdelivr.net/gh/zewei94yomi/ImageLoader@master/uPic/clip_image027.png)

  

 

 
     


