// ANONYS FINITE STATE MACHINE FRAMEWORK
// Copyright (c) 2026 Jan Hofmann <anonys@noloops.ch>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://apache.org

#ifndef ANONYS_TYPES_H
#define ANONYS_TYPES_H

#include <cstdint>
#include "anonys/FsmId.h"

namespace anonys
{
	struct EventId {
		constexpr EventId(uint16_t id) : id{ id } {}
		uint16_t const id;
	};
	static_assert(sizeof(EventId) == sizeof(uint16_t));

	static constexpr EventId MinTimoutEventId{ 60'001 };

	struct Event {
		EventId eventId;
		void* pData;
	};

	struct StateDef {
		uint16_t stateId;
		FsmId fsmId;
		const StateDef* pSuperState;
		uint16_t(*pGetMembersSize)();
		void (*pLiveCycle)(bool create, void* pTerminals, void* pMembers);
		const StateDef* (*pHandleEvent)(void* pMembers, Event& event);
	};

	struct DummyStates {
		static constexpr uint16_t InvalidStateId{ 0 };
		static constexpr anonys::StateDef Unhandled = { InvalidStateId, anonys::FsmId::Count_, nullptr, nullptr, nullptr, nullptr };
	};

	using State = const StateDef;
}

#endif // ANONYS_TYPES_H

