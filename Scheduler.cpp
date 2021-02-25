/*
    Scheduler.cpp

    A component of the note converter library used to play
    a sequence of notes

    Tyler Smith - February 2021
*/

#include "NoteConverter.h"
#include "Arduino.h"
#include<list>
using namespace std;

int pin;
int noteDuration;

list<Note> queue; 

Scheduler::Scheduler(int pin, int noteDurationSec)
{
    this -> pin = pin;
    noteDuration = noteDurationSec;
}

void Scheduler::addNote(Note note)
{
    queue.push_back(note);
}

int Scheduler::queueLength()
{
    return queue.size();
}

void Scheduler::setNoteDuration(int noteDurationSec)
{
    noteDuration = noteDurationSec;
}