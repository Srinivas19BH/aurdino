#define STEP_PIN_1 2//motor 1(this is our top motor or like up motor)

#define DIR_PIN_1  3

#define STEP_PIN_2 4//motor 2(let this be our front motor facing toward us )

#define DIR_PIN_2  5

#define STEP_PIN_3 6//motor 3(this is right or right of front motor )

#define DIR_PIN_3  7

#define STEP_PIN_4 8//motor 4(this is back or opposite of front )

#define DIR_PIN_4  9

#define STEP_PIN_5 10//motor 5(this is left or left of front)

#define DIR_PIN_5 11

#define STEP_PIN_6 12//mototr 6(this is botttom motor or down motor)

#define DIR_PIN_6 13


void setup() {

  pinMode(STEP_PIN_1, OUTPUT);
  pinMode(DIR_PIN_1, OUTPUT);

  pinMode(STEP_PIN_2, OUTPUT);
  pinMode(DIR_PIN_2, OUTPUT);

  pinMode(STEP_PIN_3, OUTPUT);
  pinMode(DIR_PIN_3, OUTPUT);

  pinMode(STEP_PIN_4, OUTPUT);
  pinMode(DIR_PIN_4, OUTPUT);

  pinMode(STEP_PIN_5, OUTPUT);
  pinMode(DIR_PIN_5, OUTPUT);

  pinMode(STEP_PIN_6, OUTPUT);
  pinMode(DIR_PIN_6, OUTPUT);

  digitalWrite(STEP_PIN_1, LOW);
  digitalWrite(STEP_PIN_2, LOW);
  digitalWrite(STEP_PIN_3, LOW);
  digitalWrite(STEP_PIN_4, LOW);
  digitalWrite(STEP_PIN_5, LOW);
  digitalWrite(STEP_PIN_6, LOW);

}

// for clockwise rotation

void clockwise(int rotation, int DIR_PIN, int STEP_PIN)

{

  digitalWrite(DIR_PIN, HIGH);

  int steps = rotation * 800;

  for (int i = 0; i < steps; i++) {

    digitalWrite(STEP_PIN, HIGH);

    delayMicroseconds(1000);

    digitalWrite(STEP_PIN, LOW);

    delayMicroseconds(1000);

  }

}

//fro anticlock wise rotaion

void anticlockwise(int rotation, int DIR_PIN, int STEP_PIN)

{

  digitalWrite(DIR_PIN, LOW);

  int steps = rotation * 800;

  for (int i = 0; i < steps; i++) {

    digitalWrite(STEP_PIN, HIGH);

    delayMicroseconds(1000);

    digitalWrite(STEP_PIN, LOW);

    delayMicroseconds(1000);

  }

}

// to generate random no. for rotation of cube more than 20 less than 40 

int random_number()

{


  return random(20, 41);

}

//this is to make all 6 motors to make more than 20 steps 

void suffel()

{

  clockwise((random_number() / 2), DIR_PIN_1, STEP_PIN_1);

  anticlockwise((random_number() / 2), DIR_PIN_1, STEP_PIN_1);//motor 1

  clockwise((random_number() / 2), DIR_PIN_2, STEP_PIN_2);

  anticlockwise((random_number() / 2), DIR_PIN_2, STEP_PIN_2);//motor 2

  clockwise((random_number() / 2), DIR_PIN_3, STEP_PIN_3);

  anticlockwise((random_number() / 2), DIR_PIN_3, STEP_PIN_3);//motor 3

  clockwise((random_number() / 2), DIR_PIN_4, STEP_PIN_4);

  anticlockwise((random_number() / 2), DIR_PIN_4, STEP_PIN_4);//motor 4

  clockwise((random_number() / 2), DIR_PIN_5, STEP_PIN_5);

  anticlockwise((random_number() / 2), DIR_PIN_5, STEP_PIN_5);//motor 5

  clockwise((random_number() / 2), DIR_PIN_6, STEP_PIN_6);

  anticlockwise((random_number() / 2), DIR_PIN_6, STEP_PIN_6);//motor 6

}

//right and inverse

void R(int rotation)

{

  clockwise(rotation, DIR_PIN_3, STEP_PIN_3);//R_no.

}

void R_inverse(int rotation)

{

  anticlockwise(rotation, DIR_PIN_3, STEP_PIN_3);//R'_no.

}

//front and inverse

void F(int rotation)

{

  clockwise(rotation, DIR_PIN_2, STEP_PIN_2);//F_no.

}

void F_inverse(int rotation)

{

  anticlockwise(rotation, DIR_PIN_2, STEP_PIN_2);//F'_no.

}

//up and inverse

void U(int rotation)

{

  clockwise(rotation, DIR_PIN_1, STEP_PIN_1);//U_no.

}

void U_inverse(int rotation)

{

  anticlockwise(rotation, DIR_PIN_1, STEP_PIN_1);//U'_no.

}

//left and inverse

void L(int rotation)

{

  clockwise(rotation, DIR_PIN_5, STEP_PIN_5);//L_no.

}

void L_inverse(int rotation)

{

  anticlockwise(rotation, DIR_PIN_5, STEP_PIN_5);//L'_no.

}

//back and inverse

void B(int rotation)

{

  clockwise(rotation, DIR_PIN_4, STEP_PIN_4);//B_no.

}

void B_inverse(int rotation)

{

  anticlockwise(rotation, DIR_PIN_4, STEP_PIN_4);//B'_no.

}

//down and inverse

void D(int rotation)

{

  clockwise(rotation, DIR_PIN_6, STEP_PIN_6);//D_no.

}

void D_inverse(int rotation)

{

  anticlockwise(rotation, DIR_PIN_6, STEP_PIN_6);//D'_no.

}


void loop() {

}