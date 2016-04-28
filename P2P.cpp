#include "xbase\x_base.h"
#include "xbase\x_guid.h"

#include "xlang\x_actor.h"
#include "xlang\x_framework.h"
#include "xlang\x_receiver.h"


namespace P2P
{

	// ----------------------------------------------------------------------------------------------------------
	// ----------------------------------------------------------------------------------------------------------
	// P2P Manager; keeping track of peer info and connected peers
	struct OnPeerCreateMsg
	{
		xcore::xguid	peerID;

	};

	struct OnPeerConnectedMsg
	{
		xcore::xguid	peerID;
	};

	class Manager : public xlang::Actor
	{
	public:
		Manager()
		{
			RegisterHandler(this, &Manager::OnPeerCreate);
			RegisterHandler(this, &Manager::OnPeerConnected);
		}

		void OnPeerCreate(const OnPeerCreateMsg& msg, const xlang::Address from)
		{

		}

		void OnPeerConnected(const OnPeerConnectedMsg& msg, const xlang::Address from)
		{

		}
	};




}
