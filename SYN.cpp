/*
[Framework] HGX
[Actor] Sync

Configuration:
	Number of DEPOTS to sync in parallel
	Number of BINS to sync in parallel (0 mean 1 BIN per DEPOT)
	Number of CHUNKS allowed for REQUEST
	Number of CHUNKS allowed for REPLY
	Number of CHUNKS to cache (LRU cache)


Book-Keeping:
	Peer-ID[]
		Depot[]
			Root Hash
			Bin[]
				Root Hash

On-Tick:
	Execute main sync logic
		Build list of chunks  that we can request from as many peers as possible.
		Clean up data of peers that are removed
		Initialize data for peers that are added

Message-Handlers:
	On-Depot-Merkle-Received(Peer-ID, Depot-ID, Merkle)
		Register Merkle at Peer-Depot
		Send Self::On-Tick

	On-Bin-Merkle-Received(Peer-ID, Depot-ID, Bin-ID, Merkle)
		Register Merkle at Peer-Depot-Bin
		Send Self::On-Tick

	On-Peer-Connected(Peer-ID)
		Add Peer to list of connected peers
		Send Request-Depots
		Send Self::On-Tick

	On-Peer-Disconnected(Peer-ID)
		Remove peer from list of connected peers
		Send Self::On-Tick

	On-Peer-Message-Handler(Peer-ID, Messages)
		Received Request for DEPOTS Merkle
		Received Request for DEPOT Merkle
		Received Request for BIN Merkle
		Received Merkle-Tree (DEPOT or BIN)
			Set it at Peer-DEPOT or Peer-DEPOT-BIN
			Send Self::On-Tick
		Received Chunk-Request
			Send Chunk-IO::On-Read-Chunk
		Received Chunk-Reply
			Send  Chunk-IO::On-Write-Chunk

	On-Chunk-Read-Finished(Chunk-ID)
		Send  P2P-Messaging::Send-Message

	On-Chunk-Write-Finished(Chunk-ID)
		P2P-Messaging::On-Release-Message
		Re-compute Merkle?
		Send Self::On-Tick
*/