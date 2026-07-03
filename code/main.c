#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int PC = 0;
    int SP = 1000;
    int LR = 0;
    int PSR = 0;

    char *instructions[] = {
        "LOAD",
        "ADD",
        "SUBTRACT",
        "JUMP"
    };


    int size = sizeof(instructions) / sizeof(instructions[0]);

    printf("\n===== SIMPLE CPU INSTRUCTION SIMULATOR =====\n");
    printf("\nInitial Register Values:\n");
    printf("PC : %d\tSP : %d\tLR : %d\tPSR : %d\n", PC, SP, LR, PSR);

    while (PC < size)
    {
        printf("\n---------------------------------------");
        printf("\nCurrent Executing Task: %s\n", instructions[PC]);

        if (PC == 0)
        {
            printf("Loading data into the CPU...\n");
        }


        else if (PC == 1)
        {
            printf("Performing Addition...\n");
            PSR = 1;
        }


        else if (PC == 2)
        {
            printf("Performing Subtraction...\n");
            PSR = 0;
        }


        else if (PC == 3)
        {
            printf("Jump Instruction Detected...\n");


            LR = PC + 1;

            printf("Return Address Saved in LR: %d\n", LR);

            printf("No more instructions to jump to.\n");
        }

        PC++;

        printf("\nUpdated Register Values:\n");
        printf("PC : %d\tSP : %d\tLR : %d\tPSR : %d\n",
               PC, SP, LR, PSR);

        sleep(1);
    }

    printf("\n---------------------------------------");
    printf("\nCPU Instruction Execution Completed Successfully.\n");

    return 0;
}
