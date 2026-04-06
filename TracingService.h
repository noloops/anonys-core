// ANONYS FINITE STATE MACHINE FRAMEWORK
// Copyright (c) 2026 Jan Hofmann <anonys@noloops.ch>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://apache.org

#ifndef ANONYS_TRACING_H
#define ANONYS_TRACING_H

#include <cstdint>
#include "anonys/EventId.h"
#include "anonys/FsmId.h"

namespace anonys
{
	class TracingService {
	public:
		virtual ~TracingService() = default;
		virtual void traceHandledEvent(FsmId fsmId, uint16_t stateId, EventId eventId) = 0;
		virtual void traceUnhandledEvent(FsmId fsmId, uint16_t stateId, EventId eventId) = 0;
		virtual void traceEnterState(FsmId fsmId, uint16_t stateId) = 0;
		virtual void traceExitState(FsmId fsmId, uint16_t stateId) = 0;
	};
}

#endif // ANONYS_TRACING_H
