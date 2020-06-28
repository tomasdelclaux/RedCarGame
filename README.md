# RedCarGame

## Assets

Thanks a lot for the following assets:
    - redCar ==> https://opengameart.org/content/red-car
    - big truck ==> https://opengameart.org/content/top-view-car-truck-sprites
    - garbage truck ==> https://opengameart.org/content/garbage-truck
 
 
## Overview

The red car gamme is a simple pixelated game, where the redCar needs to move across five lanes and avoid colliding with the rest of the vehicles. Two lanes are in reverse direction and the cars move twice as fast, and the remainder three lanes are in the direction of the red Car. The score is increased the further the red Car goes.

## Controls

- Left key = moves the red car left
- Right key = moves the red car right
- Up key = red car accelerates and moves faster

<img src="./redCarGame.png" width="600" height="450"/>

## Structure

- Game.h/Game.cpp = Object representing the game. It contains objects for redCar, lanes and renderer. It also has private members to keep track of the game difficulty and increase it as the score/distance increases
- Vehicle.h/Vehicle.cpp = Vehicle objects that represent the cars in the lanes acting as obstacles. RedCar object inherits from vehicle
- Lane.h/Lane.cpp = Lane object that keeps track of the vehicles in each lane and destroys them when the leave sdl window. Also updates their positions through the game loop.
- Renderer.h/Renderer.cpp = Loads the textures needed for the game from the assets files, and render the information from the lane and game class
- Controller.h/Controller.cpp = Object to accept user keyboard input and change behaviour of red car accordingly
