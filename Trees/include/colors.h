#ifndef COLORS_H_INCLUDED
#define COLORS_H_INCLUDED

#include <windows.h>

class ConsoleColor{
    HANDLE console_color;


    public:
        // default constructor
        ConsoleColor(){
            console_color = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(console_color, 14);
        }

        //color functions
        // light white
        void LWhite(){
            SetConsoleTextAttribute(console_color, 7);
        }
        // grey
        void Grey(){
            SetConsoleTextAttribute(console_color, 8);
        }
        //blue
        void Blue(){
            SetConsoleTextAttribute(console_color, 9);
        }
        //red
        void Red(){
            SetConsoleTextAttribute(console_color, 12);
        }
        // purple
        void Purple(){
            SetConsoleTextAttribute(console_color, 13);
        }

        //white
        void White(){
            SetConsoleTextAttribute(console_color, 15);
        }
        //light purple
        void LPurple(){
            SetConsoleTextAttribute(console_color, 5);
        }
        //green
        void Green(){
            SetConsoleTextAttribute(console_color, 10);
        }

};

#endif // COLORS_H_INCLUDED
