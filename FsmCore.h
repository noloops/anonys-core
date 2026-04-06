// ANONYS FINITE STATE MACHINE FRAMEWORK
// Copyright (c) 2026 Jan Hofmann <anonys@noloops.ch>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://apache.org

#ifndef ANONYS_FSMBASE_H
#define ANONYS_FSMBASE_H

#include "Types.h"
#include "AnonysManualConfig.h"
#include "anonys/GeneratedConfig.h"
#include "anonys/FsmId.h"
#include "anonys/Timer.h"
#include "anonys/TracingService.h"

namespace anonys
{
	class FsmCore : private TimerCore {
	public:
		void initialize(FsmId fsmId, void* pTerminals, uint8_t* pAlignedBuffer, size_t bufferSize,
			TimerService* pTimerService = nullptr);

		void setTracingService(TracingService* pTracingService = nullptr);

		void handleEvent(Event& event);

		void handleTimeoutEvent(int16_t depth, EventId eventId);

		void executeTransition(const StateDef* pState);

		inline TimerCore& getTimerCore() { return *this; }

	private:
		struct El {
			StateDef const* pState{nullptr};
			uint8_t* pMembers{nullptr};
		};

		const StateDef* findSharedSuperState(const StateDef* pState);

		void popAll();

		void popToState(const StateDef& state);

		void pushToState(const StateDef* pState);

		void push(const StateDef* pState);

		void pop();

		void* m_pTerminals{nullptr};

		El m_stack[MaxNestedStates]{ };
		int16_t m_depth{ -1 };

		uint8_t* m_pMembersBegin{ nullptr };
		uint8_t* m_pMembersEnd{ nullptr };
		uint8_t* m_pMembersNext{ nullptr };

		TracingService* m_pTracingService{ nullptr };
	};
}

#endif // ANONYS_FSMBASE_H
