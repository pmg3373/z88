// includes.h
//
// Original version:	Warren Carithers, Novermber 2000
// Updates: Edited by ddm9373 to change included .h files
//
// Master include file for the almost-PDP11

#ifndef _INCLUDES_H
#define _INCLUDES_H

// system include files

#include <cstdlib>
#include <iostream>
#include <iomanip>

// 'arch' library

#include <Clock.h>
#include <Bus.h>
#include <StorageObject.h>
#include <Clearable.h>
#include <Counter.h>
#include <Memory.h>
#include <BusALU.h>
#include <Constant.h>

using namespace std;

// program-specific includes

#include "globals.h"
#include "prototypes.h"

#endif
