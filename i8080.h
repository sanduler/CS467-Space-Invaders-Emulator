//
// Created by Ruben Sanduleac on 4/20/21.
//

#ifndef I8080_H
#define I8080_H

struct i8080
{
    i8080(unsigned char rom);
    unsigned char ROM;
    double memory;
    struct state
    {
        int unint_SP();
        double get_SP();
        void set_SP(int SP);
        int unset_AC();
        struct Flags
        {
            bool AC();
            double get_AC();
            double set_AC();
            bool unset_AC();
        };

        struct Inputs
        {
            int bit[256];
            int get_Inputs();
        };

        struct Registers
        {
            double unint8_A;
            double unint_get_A();
            void set_A(int A);
            int unint_PC();
            int get_PC();
            void set_PC(int PC);
        };
    };

};

#endif //I8080_H
