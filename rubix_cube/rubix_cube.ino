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

int cube[54];
int u[9] = {0,0,0,0,0,0,0,0,0};
int r[9] = {1,1,1,1,1,1,1,1,1};
int f[9] = {2,2,2,2,2,2,2,2,2};
int d[9] = {3,3,3,3,3,3,3,3,3};
int l[9] = {4,4,4,4,4,4,4,4,4};
int b[9] = {5,5,5,5,5,5,5,5,5};



  void setup()
{
    for(int i = 0; i < 54; i++)//0 → U-color
    {                          //1 → R-color
      cube[i] = i / 9;         //2 → F-color
    }                          //3 → D-color
                                //4 → L-color
                              //5 → B-color
    


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


  return random(1, 10);

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
//apply right in array
void apply_right(int rotaion)//this is for changig the matrix 
{
  int i=0;
  while( i<rotaion)//this is for r2 or r3
  {
    for(int j=2;j<9;j+=3)//here like from point of view of front 
    {
      int temp_a=u[j];
      u[j]=f[j];
      f[j]=d[j];
      d[j] = b[8-j];//the back view is like mirror
      b[8-j] = temp_a;
      
    }
    i++;
    int temp[9];

    for(int k = 0; k < 9; k++)
    {
       temp[k] = r[k];
    }

    r[0] = temp[6];
    r[1] = temp[3];
    r[2] = temp[0];

    r[3] = temp[7];
    r[4] = temp[4];
    r[5] = temp[1];

    r[6] = temp[8]  ;
    r[7] = temp[5];
    r[8] = temp[2];
  };

}

//now r inverse (array)
void apply_right_inverse(int rotaion)//this is for changig the matrix 
{
  int i=0;
  while( i<rotaion)//this is for r2 or r3
  {
    for(int j=2;j<9;j+=3)//here like from point of view of front 
    {
      int temp_a= b[8-j];
      u[j]= temp_a;
      b[8-j]= d[j];//the back view is like mirro
      
      d[j]=f[j];
      f[j]=u[j];
      
      
    }
    i++;
    int temp[9];

    for(int k = 0; k < 9; k++)
    {
       temp[k] = r[k];
    }
    //this is for right rotaion of others except left
    r[0]=temp[2];
    r[1]=temp[5];
    r[2]=temp[8];
    r[3]=temp[1];
    r[4]=temp[4];
    r[5]=temp[7];
    r[6]=temp[0];
    r[7]=temp[3];
    r[8]=temp[6];
  };

}


//apply left in array
void apply_left(int rotaion)//this is for changig the matrix 
{
  int i=0;
  while( i<rotaion)//this is for r2 or r3
  {
    for(int j=0;j<9;j+=3)//here like from point of view of front 
    {
      int temp_a=u[j];
      u[j]=f[j];
      f[j]=d[j];
      d[j] = b[8-j];//the back view is like mirror
      b[8-j] = temp_a;
      
    }
    i++;
    int temp[9];

    for(int k = 0; k < 9; k++)
    {
       temp[k] = l[k];
    }

    l[0] = temp[6];
    l[1] = temp[3];
    l[2] = temp[0];

    l[3] = temp[7];
    l[4] = temp[4];
    l[5] = temp[1];

    l[6] = temp[8]  ;
    l[7] = temp[5];
    l[8] = temp[2];
  };

}

//now l inverse (array)
void apply_left_inverse(int rotaion)//this is for changig the matrix 
{
  int i=0;
  while( i<rotaion)//this is for r2 or r3
  {
    for(int j=0;j<9;j+=3)//here like from point of view of front 
    {
      int temp_a= b[8-j];
      u[j]= temp_a;
      b[8-j]= d[j];//the back view is like mirro
      
      d[j]=f[j];
      f[j]=u[j];
      
      
    }
    i++;
    int temp[9];

    for(int k = 0; k < 9; k++)
    {
       temp[k] = l[k];
    }
    //this is for left rotaion of others except right
    l[0]=temp[2];
    l[1]=temp[5];
    l[2]=temp[8];
    l[3]=temp[1];
    l[4]=temp[4];
    l[5]=temp[7];
    l[6]=temp[0];
    l[7]=temp[3];
    l[8]=temp[6];
  };

}


//apply up in array
void apply_up(int rotaion)//this is for changig the matrix 
{
  int i=0;
  while( i<rotaion)//this is for r2 or r3
  {
    for(int j=0;j<3;j++)//here like from point of view of front 
    {
      int temp_a=f[j];
      f[j]=r[j];
      r[j]=b[2-j];
      b[2-j] = l[j];//the back view is like mirror
      l[j] = f[j];
      
    }
    i++;
    int temp[9];

    for(int k = 0; k < 9; k++)
    {
       temp[k] = r[k];
    }

    u[0] = temp[6];
    u[1] = temp[3];
    u[2] = temp[0];

    u[3] = temp[7];
    u[4] = temp[4];
    u[5] = temp[1];

    u[6] = temp[8]  ;
    u[7] = temp[5];
    u[8] = temp[2];
  };

}

//now up inverse (array)
void apply_up_inverse(int rotaion)//this is for changig the matrix 
{
  int i=0;
  while( i<rotaion)//this is for r2 or r3
  {
    for(int j=0;j<3;j++)//here like from point of view of front 
    {
      int temp_a= f[j];
      f[j]=l[j];
      l[j]= b[2-j];//the back view is like mirro
      
      b[2-j]=r[j];
      r[j]=temp_a;
      
      
    }
    i++;
    int temp[9];

    for(int k = 0; k < 9; k++)
    {
       temp[k] = l[k];
    }
    //this is for up rotaion of others except down
    u[0]=temp[2];
    u[1]=temp[5];
    u[2]=temp[8];
    u[3]=temp[1];
    u[4]=temp[4];
    u[5]=temp[7];
    u[6]=temp[0];
    u[7]=temp[3];
    u[8]=temp[6];
  };

}

//apply down in array
void apply_down(int rotaion)//this is for changig the matrix 
{
  int i=0;
  while( i<rotaion)//this is for r2 or r3
  {
   for(int j = 6; j < 9; j++)
    {
      int temp_a = f[j];

      f[j] = r[j];
      r[j] = b[14-j];
      b[14-j] = l[j];
      l[j] = temp_a;
    }
    i++;
  
    
    int temp[9];

    for(int k = 0; k < 9; k++)
    {
       temp[k] = r[k];
    }

    d[0] = temp[6];
    d[1] = temp[3];
    d[2] = temp[0];

    d[3] = temp[7];
    d[4] = temp[4];
    d[5] = temp[1];

    d[6] = temp[8]  ;
    d[7] = temp[5];
    d[8] = temp[2];
  };

}

//now down inverse (array)
void apply_down_inverse(int rotaion)//this is for changig the matrix 
{
  int i=0;
  while( i<rotaion)//this is for r2 or r3
  {
    for(int j=6;j<9;j++)//here like from point of view of front 
    {
      int temp_a= f[j];
      f[j]=r[j];
      r[j]= b[14-j];//the back view is like mirro
      
      b[14-j]=l[j];
      l[j]=temp_a;
      
      
    }
    i++;
    int temp[9];

    for(int k = 0; k < 9; k++)
    {
       temp[k] = l[k];
    }
    //this is for up rotaion of others except up
    d[0]=temp[2];
    d[1]=temp[5];
    d[2]=temp[8];
    d[3]=temp[1];
    d[4]=temp[4];
    d[5]=temp[7];
    d[6]=temp[0];
    d[7]=temp[3];
    d[8]=temp[6];
  };

}
//apply f on array 
void apply_front(int rotation)
{
    int i = 0;

    while(i < rotation)
    {
        // U bottom -> R left -> D top -> L right -> U bottom

        int temp_u[3];

        temp_u[0] = u[6];
        temp_u[1] = u[7];
        temp_u[2] = u[8];

        u[6] = l[8];
        u[7] = l[5];
        u[8] = l[2];

        l[2] = d[0];
        l[5] = d[1];
        l[8] = d[2];

        d[0] = r[6];
        d[1] = r[3];
        d[2] = r[0];

        r[0] = temp_u[0];
        r[3] = temp_u[1];
        r[6] = temp_u[2];


        // Rotate F face clockwise

        int temp[9];

        for(int k = 0; k < 9; k++)
        {
            temp[k] = f[k];
        }

        f[0] = temp[6];
        f[1] = temp[3];
        f[2] = temp[0];

        f[3] = temp[7];
        f[4] = temp[4];
        f[5] = temp[1];

        f[6] = temp[8];
        f[7] = temp[5];
        f[8] = temp[2];

        i++;
    }
}

//apply f inverse on array
void apply_front_inverse(int rotation)
{
    int i = 0;

    while(i < rotation)
    {
        // U bottom -> L right -> D top -> R left -> U bottom

        int temp_u[3];

        temp_u[0] = u[6];
        temp_u[1] = u[7];
        temp_u[2] = u[8];

        u[6] = r[0];
        u[7] = r[3];
        u[8] = r[6];

        r[0] = d[2];
        r[3] = d[1];
        r[6] = d[0];

        d[0] = l[2];
        d[1] = l[5];
        d[2] = l[8];

        l[2] = temp_u[0];
        l[5] = temp_u[1];
        l[8] = temp_u[2];


        // Rotate F face anticlockwise

        int temp[9];

        for(int k = 0; k < 9; k++)
        {
            temp[k] = f[k];
        }

        f[0] = temp[2];
        f[1] = temp[5];
        f[2] = temp[8];

        f[3] = temp[1];
        f[4] = temp[4];
        f[5] = temp[7];

        f[6] = temp[0];
        f[7] = temp[3];
        f[8] = temp[6];

        i++;
    }
}

//apply back in array 
void apply_back(int rotation)
{
    int i = 0;

    while(i < rotation)
    {
        // U top -> L left -> D bottom -> R right -> U top

        int temp_u[3];

        temp_u[0] = u[0];
        temp_u[1] = u[1];
        temp_u[2] = u[2];

        u[0] = r[2];
        u[1] = r[5];
        u[2] = r[8];

        r[2] = d[8];
        r[5] = d[7];
        r[8] = d[6];

        d[6] = l[0];
        d[7] = l[3];
        d[8] = l[6];

        l[0] = temp_u[2];
        l[3] = temp_u[1];
        l[6] = temp_u[0];


        // B face clockwise from the BACK viewpoint
        // With your front-reference/mirrored B indexing,
        // clockwise appears as anticlockwise in the array.

        int temp[9];

        for(int k = 0; k < 9; k++)
        {
            temp[k] = b[k];
        }

        b[0] = temp[2];
        b[1] = temp[5];
        b[2] = temp[8];

        b[3] = temp[1];
        b[4] = temp[4];
        b[5] = temp[7];

        b[6] = temp[0];
        b[7] = temp[3];
        b[8] = temp[6];

        i++;
    }
} 

//apply back in inverse in array 
void apply_back_inverse(int rotation)
{
    int i = 0;

    while(i < rotation)
    {
        // U top -> R right -> D bottom -> L left -> U top

        int temp_u[3];

        temp_u[0] = u[0];
        temp_u[1] = u[1];
        temp_u[2] = u[2];

        u[0] = l[6];
        u[1] = l[3];
        u[2] = l[0];

        l[0] = d[6];
        l[3] = d[7];
        l[6] = d[8];

        d[6] = r[8];
        d[7] = r[5];
        d[8] = r[2];

        r[2] = temp_u[0];
        r[5] = temp_u[1];
        r[8] = temp_u[2];


        // B face anticlockwise from the BACK viewpoint
        // Because your B array is mirrored, this appears clockwise
        // in the front-reference array.

        int temp[9];

        for(int k = 0; k < 9; k++)
        {
            temp[k] = b[k];
        }

        b[0] = temp[6];
        b[1] = temp[3];
        b[2] = temp[0];

        b[3] = temp[7];
        b[4] = temp[4];
        b[5] = temp[1];

        b[6] = temp[8];
        b[7] = temp[5];
        b[8] = temp[2];

        i++;
    }
}

//right and inverse

void R(int rotation)

{

  clockwise(rotation, DIR_PIN_3, STEP_PIN_3);//R_no.
  apply_right(rotation);
}

void R_inverse(int rotation)

{

  anticlockwise(rotation, DIR_PIN_3, STEP_PIN_3);//R'_no.
  apply_right_inverse(rotation);
}

//front and inverse

void F(int rotation)

{

  clockwise(rotation, DIR_PIN_2, STEP_PIN_2);//F_no.
  apply_front(rotation);
}

void F_inverse(int rotation)

{

  anticlockwise(rotation, DIR_PIN_2, STEP_PIN_2);//F'_no.
  apply_front_inverse(rotation);
}

//up and inverse

void U(int rotation)

{

  clockwise(rotation, DIR_PIN_1, STEP_PIN_1);//U_no.
  apply_up(rotation);
}

void U_inverse(int rotation)

{

  anticlockwise(rotation, DIR_PIN_1, STEP_PIN_1);//U'_no.
  apply_up_inverse(rotation);
}

//left and inverse

void L(int rotation)

{

  clockwise(rotation, DIR_PIN_5, STEP_PIN_5);//L_no.
  apply_left(rotation);
}

void L_inverse(int rotation)

{

  anticlockwise(rotation, DIR_PIN_5, STEP_PIN_5);//L'_no.
  apply_left_inverse(rotation);
}

//back and inverse

void B(int rotation)

{

  clockwise(rotation, DIR_PIN_4, STEP_PIN_4);//B_no.
  apply_back(rotation);
}

void B_inverse(int rotation)

{

  anticlockwise(rotation, DIR_PIN_4, STEP_PIN_4);//B'_no.
  apply_back_inverse( rotation);
}

//down and inverse

void D(int rotation)

{

  clockwise(rotation, DIR_PIN_6, STEP_PIN_6);//D_no.
  apply_down(rotation);
}

void D_inverse(int rotation)

{

  anticlockwise(rotation, DIR_PIN_6, STEP_PIN_6);//D'_no.
  apply_down_inverse(rotation);
}



void loop() {

}