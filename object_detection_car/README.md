# Obstacle Avoiding Robot Car

An Arduino-based obstacle-avoiding robot car that uses an **HC-SR04 ultrasonic sensor** mounted on a **servo motor** to detect obstacles and choose a clear direction.

## Components

* Arduino
* HC-SR04 Ultrasonic Sensor
* Servo Motor
* 2 DC Motors
* Motor Driver
* Robot Car Chassis
* Battery / Power Supply
* Jumper Wires

## Pin Configuration

| Component       | Arduino Pin |
| --------------- | ----------: |
| Ultrasonic TRIG |           9 |
| Ultrasonic ECHO |           8 |
| Left Motor      |        6, 7 |
| Right Motor     |        4, 5 |
| Servo Motor     |          10 |

## Working

The ultrasonic sensor continuously measures the distance in front of the robot.

### 1. No Obstacle

If the distance in front is greater than **30 cm**, the robot moves forward.

### 2. Obstacle Detected

If an obstacle is detected within 30 cm:

1. The robot stops.
2. The servo rotates the ultrasonic sensor to the left.
3. The distance on the left is measured.
4. The servo rotates to the right.
5. The distance on the right is measured.
6. The servo returns to the center.
7. The robot chooses the direction with more available space.

### 3. Direction Selection

The robot follows this logic:

* **Right is clear** → Turn right
* **Left is clear** → Turn left
* **Both directions are blocked** → Move backward and scan again

## Distance Measurement

The ultrasonic sensor calculates distance using the echo time.

```text
Distance = Echo Duration / 58.2
```

The program uses a maximum safe distance of:

```text
30 cm
```

## Motor Control

The two DC motors are controlled using four digital pins.

```text
Left Motor  → Pins 6, 7
Right Motor → Pins 4, 5
```

The program provides four basic movements:

* Forward
* Backward
* Left
* Right

## Servo Scanning

The servo is connected to pin 10.

```cpp
Myservo.write(90);   // Center
Myservo.write(180);  // Left
Myservo.write(0);    // Right
```

The servo allows the ultrasonic sensor to scan different directions before deciding where the robot should move.

## Main Algorithm

```text
Start
  ↓
Measure front distance
  ↓
Is distance > 30 cm?
  ├── Yes → Move Forward
  │
  └── No
       ↓
     Stop
       ↓
   Scan Left
       ↓
  Scan Right
       ↓
 Is Right clearer?
  ├── Yes → Turn Right
  │
  └── No
       ↓
 Is Left clearer?
  ├── Yes → Turn Left
  │
  └── No → Move Backward
             ↓
          Scan Again
```

## Software

* Arduino IDE
* Arduino C/C++
* Servo Library

## Project Status

**Completed basic obstacle avoidance implementation.**

Future improvements can include:

* PWM-based motor speed control
* More accurate turning angles
* Better obstacle detection
* PID-based movement control
* Improved power management
* Autonomous navigation

