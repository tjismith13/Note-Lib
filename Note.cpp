/*
    Template class for the Note to be passed to the scheduler.
    Contains the pitch and duration of the note.
*/

#include "NoteConverter.h"
#include "Arduino.h"
using namespace std;

Pitch pitch;
NoteType noteType;

Note::Note(Pitch pitch, NoteType noteType) 
{
    this -> pitch = pitch;
    this -> noteType = noteType;
}

Pitch Note::getPitch()
{
    return pitch;
}

NoteType Note::getNoteType() 
{
    return noteType;
}