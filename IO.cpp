#include "xbase\x_base.h"
#include "xbase\x_guid.h"

#include "xlang\x_actor.h"
#include "xlang\x_framework.h"
#include "xlang\x_receiver.h"

#include <string>

namespace xcore
{
	class filepath
	{
	public:

	};

	class dirpath
	{
	public:

	};

}


namespace IO
{

	// ----------------------------------------------------------------------------------------------------------
	// ----------------------------------------------------------------------------------------------------------

	// Request for reading a chunk
	struct OnReadChunk
	{
		void*	depot_hash;
		void*	chunk_hash;
		void*	chunk_data;
		int		chunk_size;
	};

	// Request for writing a chunk
	struct OnWriteChunk
	{
		void*	depot_hash;
		void*	chunk_hash;
		void*	chunk_data;
		int		chunk_size;
	};

	class IO : public xlang::Actor
	{
	public:
		IO()
		{
			RegisterHandler(this, &IO::OnReadChunk);
			RegisterHandler(this, &IO::OnWriteChunk);
		}

		void OnReadChunk(const OnReadChunk& msg, const xlang::Address from)
		{

		}

		void OnWriteChunk(const OnWriteChunk& msg, const xlang::Address from)
		{

		}

	protected:
		struct file_t
		{
			void*			mFileHandle;
			time_t			mLastUsed;
		};

		int				mMaxOpenFiles;
		int				mCurOpenFiles;
		file_t**		mOpenFilesArray;

		struct depot_t
		{
			xcore::dirpath	mDepotPath;
			file_t*			mBinFiles;

			file_t			open(void* hash);
			void			close(file_t);
		};

	};
}
