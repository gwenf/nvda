/*
This file is a part of the NVDA project.
URL: http://www.nvda-project.org/
Copyright 2006-2010 NVDA contributers.
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 2.0, as published by
    the Free Software Foundation.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
This license can be found at:
http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
*/

#include <windows.h>
#include <minhook.h>

BOOL WINAPI DllMain(HINSTANCE hModule,DWORD reason,LPVOID lpReserved) {
	//Process exiting, we must clean up any pending hooks
	if(reason==DLL_PROCESS_DETACH&&lpReserved) {
		if(MH_DisableAllHooks()!=MH_ERROR_NOT_INITIALIZED) {
			//Give enough time for all hook functions to complete.
			Sleep(250);
			MH_Uninitialize();
		}
	}
	return 1;
}