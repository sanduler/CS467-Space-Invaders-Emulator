#include <stdio.h>
#include <string>
#include "../i8080_struct.h"
#include "OpCodeFunctions.h"

// CPU VARIABLES
i8080_CPU i8080_control;                // CPU to compare to 
i8080_CPU i8080;               // CPU to run functions on
i8080_CPU *ctl_ptr = &i8080_control;  
i8080_CPU *var_ptr = &i8080_control;

// PROTOTYPES
void resetCpu(i8080_CPU *cpu);
void setControlTestState();
void setVariableTestState();
bool compareCPUs();


/*
    Function to reset the CPU
*/
void resetCpu(i8080_CPU *cpu) 
{
    // Reset the control CPU
    cpu->state.flag_Z.set(0);
    cpu->state.flag_S.set(0);
    cpu->state.flag_P.set(0);
    cpu->state.flag_C.set(0);
    cpu->state.flag_AC.set(0);
    cpu->state.reg_A.set(0);
    cpu->state.reg_B.set(0);
    cpu->state.reg_C.set(0);
    cpu->state.reg_D.set(0);
    cpu->state.reg_E.set(0);
    cpu->state.reg_H.set(0);
    cpu->state.reg_L.set(0);
    cpu->state.reg_SP.set(0);
    cpu->state.reg_PC.set(0);
}

/*
    Sets the initial test state in the control CPU
*/
void setControlTestState()
{
    i8080_control.state.flag_Z.set(0);
    i8080_control.state.flag_S.set(0);
    i8080_control.state.flag_P.set(0);
    i8080_control.state.flag_C.set(0);
    i8080_control.state.flag_AC.set(0);
    i8080_control.state.reg_A.set(0);
    i8080_control.state.reg_B.set(0);
    i8080_control.state.reg_C.set(0);
    i8080_control.state.reg_D.set(0);
    i8080_control.state.reg_E.set(0);
    i8080_control.state.reg_H.set(0);
    i8080_control.state.reg_L.set(0);
    i8080_control.state.reg_SP.set(0);
    i8080_control.state.reg_PC.set(0);
}

/*
    Sets the initial test state in the variable CPU
*/
void setVariableTestState()
{
    i8080.state.flag_Z.set(0);
    i8080.state.flag_S.set(0);
    i8080.state.flag_P.set(0);
    i8080.state.flag_C.set(0);
    i8080.state.flag_AC.set(0);
    i8080.state.reg_A.set(0);
    i8080.state.reg_B.set(0);
    i8080.state.reg_C.set(0);
    i8080.state.reg_D.set(0);
    i8080.state.reg_E.set(0);
    i8080.state.reg_H.set(0);
    i8080.state.reg_L.set(0);
    i8080.state.reg_SP.set(0);
    i8080.state.reg_PC.set(0);
}

/*
    Compares the control and variable CPU and returns bool
*/
bool compareCPUs()
{
    if(
        i8080_control.state.reg_A.get() != i8080.state.reg_A.get() ||
        i8080_control.state.reg_B.get() != i8080.state.reg_B.get() ||
        i8080_control.state.reg_C.get() != i8080.state.reg_C.get() ||
        i8080_control.state.reg_D.get() != i8080.state.reg_D.get() ||
        i8080_control.state.reg_E.get() != i8080.state.reg_E.get() ||
        i8080_control.state.reg_H.get() != i8080.state.reg_H.get() ||
        i8080_control.state.reg_L.get() != i8080.state.reg_L.get() ||
        i8080_control.state.reg_SP.get() != i8080.state.reg_SP.get() ||
        i8080_control.state.reg_PC.get() != i8080.state.reg_PC.get() 
    ) 
    {
        return false;
    } else
    {
        return true;
    }
}

int main(int argc, char* argv[])
{
    printf("%d\n", compareCPUs());
    return 0;
}