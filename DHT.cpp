#include "xbase\x_base.h"
#include "xbase\x_guid.h"

#include "xlang\x_actor.h"
#include "xlang\x_framework.h"
#include "xlang\x_receiver.h"


namespace DHT
{

	// ----------------------------------------------------------------------------------------------------------
	// ----------------------------------------------------------------------------------------------------------
	// What kind of DHT do we want here and why ?:
	// - Symphony
	// - Kademlia
	// - Chord
	// 
	// Why a DHT ?
	// To be connected into a structured mesh and use it to communicate with neighbors only to synchronize
	// data.

	// Periodic tick
	struct OnTick
	{


	};

	// Someone is requesting a list of all current DHT node connections
	struct OnRequestNeighbors
	{


	};

	// DHT related messages
	struct OnReceiveMessages
	{

	};


	class DHT : public xlang::Actor
	{
	public:
		DHT()
		{
			RegisterHandler(this, &DHT::OnTick);
			RegisterHandler(this, &DHT::OnRequestNeighbors);
			RegisterHandler(this, &DHT::OnReceiveMessages);
		}

		void OnTick(const OnTick& msg, const xlang::Address from)
		{

		}

		void OnRequestNeighbors(const OnRequestNeighbors& msg, const xlang::Address from)
		{

		}

		void OnReceiveMessages(const OnReceiveMessages& msg, const xlang::Address from)
		{

		}
	};




}
