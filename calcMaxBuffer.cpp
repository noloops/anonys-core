// ANONYS FINITE STATE MACHINE FRAMEWORK
// Copyright (c) 2026 Jan Hofmann <anonys@noloops.ch>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://apache.org

#include "anonys/calcMaxBuffer.h"
#include "anonys/Utils.h"
#include <limits>

namespace anonys
{
	void calcMaxBuffer(State& state, uint16_t& maxBufferSize) {
		uint32_t sum{0};
		const StateDef* pState{&state};
		while (pState != nullptr) {
			if (pState->pGetMembersSize != nullptr) {
				sum += pState->pGetMembersSize();
			}
			else {
				ANONYS_ASSERT(false);
			}
			pState = pState->pSuperState;
		}
		if (sum > std::numeric_limits<uint16_t>::max()) {
            sum = std::numeric_limits<uint16_t>::max();
            ANONYS_ASSERT(false);
		}
        uint16_t const size{static_cast<uint16_t>(sum)};
        if (size > maxBufferSize) {
            maxBufferSize = size;
        }
	}
}
