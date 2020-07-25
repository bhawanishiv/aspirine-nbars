/*
* ASPIRiNE nBARS 98.1, A micro-controller based line follower autonomous robot
*/

#include <avr/io.h>

int main()
{
    DDRB = 0x0F;  //initialization of LEDs port (O/P device)
    PORTB = 0x00; //clearing the port

    DDRC = 0x00;  //initialization of sensors port (I/P device)
    PORTC = 0x00; //clearing the port

    DDRD = 0xF0;  //initialization of Motors port (O/P device)
    PORTD = 0x00; //clearing the port

    while (1)
    {
        switch (PINC & 0x03) //read both the sensors
        {
        case 0x00:        //if both the sensors read
            PORTB = 0x01; //glow 1st LED
            PORTD = 0x60; //move forward
            break;

        case 0x01:        //if left sensor reads
            PORTB = 0x08; //glow 4th LED
            PORTD = 0xA0; //move right
            break;

        case 0x02:        //if right sensor reads
            PORTB = 0x04; //glow 3rd LED
            PORTD = 0x50; // move left
            break;

        case 0x03:        //if both the sensors do not read
            PORTB = 0x02; //glow 2nd LED
            PORTD = 0x00; //stop moving
            break;
        }
    }
}
