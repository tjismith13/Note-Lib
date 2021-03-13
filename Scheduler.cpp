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
Converter converter;

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

void Scheduler::setPin(int pin)
{
    this -> pin = pin;
}

void Scheduler::play()
{
    int queueSize = queue.size();
    for(int i = 0; i < queueSize; i++) {
        Note currentNote = queue.front();
        double noteLen;
        if(currentNote.getNoteType() == 0) {
            noteLen = 1 / 4;
        }
        else if(currentNote.getNoteType() == 1) {
            noteLen = 1 / 2;
        }
        else if(currentNote.getNoteType() == 2) {
            noteLen = 1;
        }
        else if(currentNote.getNoteType() == 3) {
            noteLen = 2;
        }
        else {
            noteLen = 4;
        }
        
        noteLen *= noteDuration;
        
        double startingTime = millis();
        while(startingTime + noteDuration > millis()) {
            tone(pin, converter.toHz(currentNote.getPitch()));
        }
        noTone(pin);

        queue.pop_front();
    }
    
}