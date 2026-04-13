// ANONYS FINITE STATE MACHINE FRAMEWORK
// Copyright (c) 2026 Jan Hofmann <anonys@noloops.ch>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://apache.org

#ifndef ANONYS_CALCMAXBUFFER_H
#define ANONYS_CALCMAXBUFFER_H

#include <cstdint>

#include "Types.h"

namespace anonys
{
	void calcMaxBuffer(State& state, uint16_t& maxBufferSize);
}

#endif // ANONYS_CALCMAXBUFFER_H
