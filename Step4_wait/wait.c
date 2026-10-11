#include <stdio.h>
#include <windows.h>

static double cpu_ms(void)                     /* процесорний час процесу, мс */
{
    FILETIME c, e, k, u;
    GetProcessTimes(GetCurrentProcess(), &c, &e, &k, &u);
    ULONGLONG kt = (ULONGLONG)k.dwHighDateTime << 32 | k.dwLowDateTime;
    ULONGLONG ut = (ULONGLONG)u.dwHighDateTime << 32 | u.dwLowDateTime;
    return (kt + ut) / 10000.0;                /* одиниці по 100 нс */
}

/* Чекати Esc не довше за 10 секунд, щосекунди друкувати, скільки лишилось */
int main(void)
{
    ULONGLONG start = GetTickCount64();
    ULONGLONG loops = 0;
    int shown = -1;
    int pressed = 0;
    for (;;) {
        loops++;
        ULONGLONG elapsed = GetTickCount64() - start;
        if (elapsed >= 10000) {
            break;
        }
        int left = 10 - (int)(elapsed / 1000);
        if (left != shown) {
            printf("%d...\n", left);
            shown = left;
        }
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
            pressed = 1;
            break;
        }
    }
    printf("%s after %llu ms, %llu loop iterations\n",
           pressed ? "Esc" : "timeout", GetTickCount64() - start, loops);
    printf("CPU time: %.0f ms\n", cpu_ms());
    return pressed ? 0 : 1;
}
