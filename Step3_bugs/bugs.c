#include <stdio.h>
#include <windows.h>

/* 1. Скільки бітів числа дорівнюють 1 */
static int count_bits(DWORD x)
{
    int count = 0;
    for (int b = 0; b <= 32; b++) {
        if (x & (1u << b)) {
            count++;
        }
    }
    return count;
}

/* 2. Скількома способами два кубики дають у сумі target */
static int dice_pairs(int target)
{
    int count = 0;
    int b = 1;
    for (int a = 1; a <= 6; a++) {
        for (; b <= 6; b++) {
            if (a + b == target) {
                count++;
            }
        }
    }
    return count;
}

/* 3. Виконати команди до першої 'q': '+' - додати 1, '-' - відняти 1 */
static int run_commands(const char *cmds)
{
    int value = 0;
    for (int i = 0; cmds[i] != '\0'; i++) {
        switch (cmds[i]) {
        case '+': value++; break;
        case '-': value--; break;
        case 'q': break;                      /* стоп: решту команд не виконувати */
        default:  break;
        }
    }
    return value;
}

/* 4. Скільки пробілів у рядку */
static int count_spaces(const char *s)
{
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            count++;
            i++;                              /* пробіл враховано - до наступного символу */
        }
    }
    return count;
}

/* 5. Скільки разів подвоїти 1, щоб отримати не менше за n */
static int doublings(DWORD n)
{
    int steps = 0;
    for (DWORD p = 1; p < n; p * 2) {
        steps++;
    }
    return steps;
}

int main(void)
{
    printf("bits(6)        = %d\n", count_bits(6));
    printf("bits(7)        = %d\n", count_bits(7));
    printf("dice(7)        = %d\n", dice_pairs(7));
    printf("dice(12)       = %d\n", dice_pairs(12));
    printf("commands       = %d\n", run_commands("++-+q++"));
    printf("spaces         = %d\n", count_spaces("a  b c"));
    printf("doublings(100) = %d\n", doublings(100));
    return 0;
}
