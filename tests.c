#include "ft_printf.h"

int main (void)
{
	ft_printf("my name is %s, and I'm %d years old\n", "Jose", 37);
	ft_printf("A character: %c\n", 'A');
	ft_printf("NULL string: %s, Empty string: %s\n", NULL, "");
	int num = 42;
    ft_printf("Address of num: %p, NULL pointer: %p\n", &num, NULL);
	ft_printf("Pos: %d, Neg: %i, Zero: %d\n", 123, -456, 0);
	ft_printf("Unsigned: %u\n", 4294967295U);
	ft_printf("Lowercase: %x, Uppercase: %X\n", 255, 255);
	ft_printf("I am 100%% sure.\n");
	ft_printf("Char: %c, String: %s, Ptr: %p, Int: %d, Hex: %x\n", 'Z', "test", (void*)0x12345678, -42, 42);
}
