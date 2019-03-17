Entry Number1: 2017CS10351 , Meenal Meena
Entry Number2: 2017CS10377 , Shivam Goyal

We have simulated the indian traffic system whose output can be seen on terminal as well as visual graphics using openGL GLUT library.
Our simulation have the following features:
1. A Road whose Length and Width is variable and can be set by specifying in Configuration file.
2. Several types of different colored vehicles with different lengths and widths as specififed in Configurstion file.
2. Road has features such as Grey Color, white lines in between, Yellow-Black footpath/divider so as to make the graphics realistic and like Indian Roads.
3. Types of vehicles entering Road(represented by rectangles) is made variable i.e. we can add multiple types of vehicles in the simulation, it is not hard coded.
4. When the simulation Starts ,there are three kinds of operations we can perform and run our simulation on:
    a. Make a Vehicle to enter the road from a random position.
    b. Make the simulation run for any number of times using "Pass" feature.
    c.Changing the color of Traffic Light present on the road i.e. making it Red or Green.
5. The Vehicles entering road enters from a random position.
6. Vehicles follow the standard traffic light rules to be followed by driving the car.
7. Vehicles stop when Light is Red and then again go on when color becomes Green again.
8. We have made driver intelligent i.e.
    a. It can speed up when road in front of it is empty.
    b. Can change lane when there is a vehicle in front of it.
    c. Can overtake a vehicle by speeding up whenever required.
9. Logically in recordings we have kept the speed and maxspeed of heavy vehicles slow and smaller vehicles fast.
10. We have also used the keyboard key sensing function of GLUT. Using the "escape key" the display screen of simulation can exited.
    Key can be changed depending on user preference.
11. It is not necessary to specify all the features when defining vehicles. We have set default values which can be take whenever anything is unspecified.
12. We have included comment skipping part while reading from configuration file in our code.
