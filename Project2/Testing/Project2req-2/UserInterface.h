#ifndef UI_H
#define UI_H

class UI // abstract class
{
    public:
    virtual void menu(/* A container */, /* B container */) const = 0;  
    template<typename T>
    static void display(/* T container */);
    static /* A iterator */ selectA(/* A container */);
    static /* B iterator */ selectB(/* B container */); 
};

#endif