#!/bin/bash
x86_64-w64-mingw32-gcc lp-forward.c -o LockdownProtocol.exe -mwindows -nostdlib -lkernel32 -Os -s -fno-ident -fno-asynchronous-unwind-tables -fno-unwind-tables -Wl,--file-alignment,512,--disable-reloc-section,--gc-sections,-e,WinMainCRTStartup

cp -f LockdownProtocol.exe "$HOME/.steam/steam/steamapps/common/LOCKDOWN Protocol/LockdownProtocol.exe"
