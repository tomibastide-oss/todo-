void setup ()
{ pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
}

void loop ()
{digitalWrite (2,1);
digitalWrite (1,0);
delay (500);
digitalWrite (3,1);
 digitalWrite(2,0);
delay (500);
}
