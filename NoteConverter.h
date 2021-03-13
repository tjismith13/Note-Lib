/*
    NoteConverter.h

    Library for converting musical notes into frequency
    Values in hertz in order to be used with the arduino
    tone() command.

    Tyler Smith - February 2021
*/

#ifndef NoteConverter_h
#define NoteConverter_h

#include "Arduino.h"

enum Pitch : int{
    c0 = -56,
    cSharp0,
    d0,
    dSharp0,
    e0,
    f0,
    fSharp0,
    g0,
    a0,
    aSharp0,
    b0,
    c1,
    cSharp1,
    d1,
    dSharp1,
    e1,
    f1,
    fSharp1,
    g1,
    gSharp1,
    a1,
    aSharp1,
    b1,
    c2,
    cSharp2,
    d2,
    dSharp2,
    e2,
    f2,
    fSharp2,
    g2,
    gSharp2,
    a2,
    aSharp2,
    b2,
    c3,
    cSharp3,
    d3,
    dSharp3,
    e3,
    f3,
    fSharp3,
    g3,
    gSharp3,
    a3,
    aSharp3,
    b3,
    c4,
    cSharp4,
    d4,
    dSharp4,
    e4,
    f4,
    fSharp4,
    g4,
    gSharp4,
    a4,
    aSharp4,
    b4,
    c5,
    cSharp5,
    d5,
    dSharp5,
    e5,
    f5,
    fSharp5,
    g5,
    gSharp5,
    a5,
    aSharp5,
    b5,
    c6,
    cSharp6,
    d6,
    dSharp6,
    e6,
    f6,
    fSharp6,
    g6,
    gSharp6,
    a6,
    aSharp6,
    b6,
    c7,
    cSharp7,
    d7,
    dSharp7,
    e7,
    f7,
    fSharp7,
    g7,
    gSharp7,
    a7,
    aSharp7,
    b7
};

enum NoteType : int {
    sixteenth,
    eighth,
    quarter,
    half,
    full
};

class Note {
    public:
        Note(Pitch pitch, NoteType noteType);
    private:
        Pitch pitch;
        NoteType noteType;
};

class Converter {
    public:
        int toHz(Pitch);
        Pitch toNote(int frequency);
};

class Scheduler {
    public:
        int pin;
        Scheduler(int pin, int noteDuration);
        void setNoteDuration(int sec);
        void addNote(Note note);
        int queueLength();
        void play();
    private:
        int noteDuration;
};

#endif
