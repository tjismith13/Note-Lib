/*
    Scheduler.cpp

    A component of the note converter library used to play
    a sequence of notes

    Tyler Smith - February 2021
*/

#include "NoteConverter.h"
#include "Arduino.h"

int pin;

Scheduler::Scheduler(int pin)
{
    this -> pin = pin;
}

