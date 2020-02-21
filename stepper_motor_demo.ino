int smDirectionPin = 2;
int smStepPin = 3;
int smEnablePin = 6;

void setup()
{
    pinMode(smDirectionPin, OUTPUT);
    pinMode(smStepPin, OUTPUT);
    pinMode(smEnablePin, OUTPUT);

    digitalWrite(smEnablePin, HIGH); //Disables the motor until it is called uppond

    Serial.begin(9600);
}

void loop()
{
    rotate(800, 0.1); //The motor rotates 800 steps clockwise with a speed of 0.1 (slow)
    delay(5000);
    rotate(1600, 0.5); //The motor rotates 1600 steps clockwise with a speed of 0.5 (medium)
    delay(5000);
    rotate(-1600, 1); //The motor rotates 1600 steps counter clockwise with a speed of 1 (fast)
    delay(5000);
}

void rotate(int steps, float speed)
{
    digitalWrite(smEnablePin, LOW); // enabling the motor, so it will move when asked to

    int direction;

    if (steps > 0)
    {
        direction = HIGH;
    }
    else
    {
        direction = LOW;
    }

    speed = 1 / speed * 70;
    steps = abs(steps);

    digitalWrite(smDirectionPin, direction);

    /*Steppin'*/
    for (int i = 0; i < steps; i++)
    {
        digitalWrite(smStepPin, HIGH);
        delayMicroseconds(speed);
        digitalWrite(smStepPin, LOW);
        delayMicroseconds(speed);
    }

    digitalWrite(smEnablePin, HIGH); // disable the motor until next time :3
}
}