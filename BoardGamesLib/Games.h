#pragma once
#include <iostream>
#include <string>

// -------------------------------------------------- Ewa Miazga ----------------------------------------------------------

class Games
{
public:
    Games() = default;

    virtual void play() = 0;

    virtual void display() = 0;

    ~Games() {}
};
