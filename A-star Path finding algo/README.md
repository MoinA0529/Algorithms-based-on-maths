# A-star-path-finding-Visualizer

This is a __python__ Application for visualizing __A-star__ path finding algorithm where users can choose source and destination node and positions of obstacles in between.
A star algorithm is implemented from scratch using __manhattan distance__ as hueristic distance, with a light weight __GUI__ developed in __pygame__ to visualize the process
of path finding with final computed shortest path . It can also be used for visualizing other path finding algorithms on a grid.

For running the tool , pygame needs to be installed if not already present. which can be done using the following commands.

##### For linux/Windows

    $ pip install pygame

##### For mac 

    $ pip3 install pygame

or
              
    $ python -m pip install pygame
    

After succesfully installing pygame run this application with 

    $ python astar_visualizer.py

Now follow the steps below for interacting with pygame GUI

## Steps for interacting with gui

* Choose start node by right clicking on it (appears orange)
* similarly choose end node ( appears blue)
* similarly choose all the obstacle nodes  (appear black)
* Press space bar to see the algorithm in action (at the end shortest path is displayed in purple)
* use CTRL + C to reset the window 

