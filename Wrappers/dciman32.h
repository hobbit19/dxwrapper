#pragma once

#define VISIT_DCIMAN32_PROCS(visit) \
	visit(DCIBeginAccess) \
	visit(DCICloseProvider) \
	visit(DCICreateOffscreen) \
	visit(DCICreateOverlay) \
	visit(DCICreatePrimary) \
	visit(DCIDestroy) \
	visit(DCIDraw) \
	visit(DCIEndAccess) \
	visit(DCIEnum) \
	visit(DCIOpenProvider) \
	visit(DCISetClipList) \
	visit(DCISetDestination) \
	visit(DCISetSrcDestClip) \
	visit(GetDCRegionData) \
	visit(GetWindowRegionData) \
	visit(WinWatchClose) \
	visit(WinWatchDidStatusChange) \
	visit(WinWatchGetClipList) \
	visit(WinWatchNotify) \
	visit(WinWatchOpen)

namespace dciman32
{
	class dciman32_dll
	{
	public:
		HMODULE dll = nullptr;
		VISIT_DCIMAN32_PROCS(ADD_FARPROC_MEMBER);

		void Load()
		{
			// Load real dll
			dll = Wrapper::LoadDll(dtype.dciman32);

			// Load dll functions
			if (dll)
			{
				VISIT_DCIMAN32_PROCS(LOAD_ORIGINAL_PROC);
			}
		}
	};

	extern dciman32_dll module;
};