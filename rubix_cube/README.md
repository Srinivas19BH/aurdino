# Rubik's Cube Solver

An automated Rubik's Cube Solver using Arduino and stepper motors.

## Components

* Arduino mega or teensy 4.0
* 6 Stepper Motors
* Stepper Motor Drivers
* 12V SMPS
* Rubik's Cube

## Working

The project uses six stepper motors to control the six faces of a Rubik's Cube.

The cube state is represented using arrays in the program. Based on the cube state and required moves, the corresponding stepper motors are rotated to perform the Rubik's Cube moves.

The solving algorithm can be run on a laptop, or an online Rubik's Cube solver can be used to generate the solution moves. The generated moves can then be provided as input to the Arduino.

## Project Status

Currently under development. The rotation and array-based cube state changes are being implemented and tested.
