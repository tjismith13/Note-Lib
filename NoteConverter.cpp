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

int Converter::toHz(Note note)
{
    int noteVal = note;
    return 440 * pow((pow(2, (1/12))), noteVal);
}

Note Converter::toNote(int frequency)
{
    int difference = MAXFLOAT;
    Note result;
    for(int i = -56; i < 39; i++)
    {
        Note note = static_cast<Note>(frequency);
        if(abs(frequency - toHz(note)) < difference)
        {
            difference = abs(frequency - toHz(note));
            result = note;
        }
    }
    return result;
}

