/*
    NoteConverter.cpp
    
    Library for converting musical notes into frequency
    Values in hertz in order to be used with the arduino
    tone() command.

    Tyler Smith - February 2021
*/

#include "NoteConverter.h"
#include "Arduino.h"
#include "math.h"

int Converter::toHz(Pitch pitch)
{
    int noteVal = pitch;
    return 440 * pow((pow(2, (1/12))), noteVal);
}

Pitch Converter::toNote(int frequency)
{
    int difference = MAXFLOAT;
    Pitch result;
    for(int i = -56; i < 39; i++)
    {
        Pitch pitch = static_cast<Pitch>(frequency);
        if(abs(frequency - toHz(pitch)) < difference)
        {
            difference = abs(frequency - toHz(pitch));
            result = pitch;
        }
    }
    return result;
}

