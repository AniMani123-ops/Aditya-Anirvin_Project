#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "lmc.h"

// Function Prototypes
void run(LMC* lmc);
int step(LMC* lmc);
int fetch(LMC* lmc);
void decode_execute(LMC* lmc, int instruction);

#endif
