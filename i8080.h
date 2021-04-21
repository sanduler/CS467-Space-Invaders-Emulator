//
// Created by Ruben Sanduleac on 4/20/21.
//

#ifndef I8080_H
#define I8080_H
#include <stdint.h>
#include "memory.h"
struct i8080
{
    i8080(memory* mem, uint8_t _ConsoleMode);
    unsigned char ROM;
    double memory;
    i8080_state state;
};
struct i8080_state
{
        int unint_SP();
        double get_SP();
        void set_SP(int SP);
        int unset_AC();
        state_Flags flags;
};
struct state_Flags
{
             bool AC();
            double get_AC();
            double set_AC();
            bool unset_AC();
            // Flags
            uint8_t FlagZSP[0x100]; // Precalculated ZSP
            uint8_t flag_Z; // Zero
            uint8_t flag_S; // Sign
            uint8_t flag_P; // Parity
            uint8_t flag_C; // Carry
            uint8_t flag_AC; // Auxiliar Carry
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

            uint8_t* reg_M;
            uint8_t true_reg_A;
            uint8_t* reg_A = &true_reg_A; // Pointer uniformity
            uint16_t reg_BC;
            uint8_t* reg_B = ((uint8_t*) &reg_BC) + 1;
            uint8_t* reg_C = ((uint8_t*) &reg_BC);
            uint16_t reg_DE;
            uint8_t* reg_D = ((uint8_t*) &reg_DE) + 1;
            uint8_t* reg_E = ((uint8_t*) &reg_DE);
            uint16_t reg_HL;
            uint8_t* reg_H = ((uint8_t*) &reg_HL) + 1;
            uint8_t* reg_L = ((uint8_t*) &reg_HL);
            uint16_t PC, SP;
        };
    };

};

#endif //I8080_H
