#include <windows.h>
#define EXE "\"LockdownProtocol\\Binaries\\Win64\\LockdownProtocol-Win64-Shipping.exe\" "
#define FLAG_0  "-vulkan"
#define FLAG_1   "-dx12"
#define FLAG_2   "-dx11"

__attribute__((force_align_arg_pointer))
void WinMainCRTStartup(void) {
    STARTUPINFOA si = { 0 };
    PROCESS_INFORMATION pi;
    char env[4];
    char cmd[] = EXE FLAG_0;
    si.cb = sizeof(si);

    if (GetEnvironmentVariableA("LP_DX12", env, sizeof(env)) && env[0] == '1') {
        __builtin_memcpy(cmd + sizeof(EXE) - 1, FLAG_1, sizeof(FLAG_1));
    }
    else if
       (GetEnvironmentVariableA("LP_DX11", env, sizeof(env)) && env[0] == '1') {
        __builtin_memcpy(cmd + sizeof(EXE) - 1, FLAG_2, sizeof(FLAG_2));
    }
    if (CreateProcessA(NULL, cmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
    }
    ExitProcess(0);
}
