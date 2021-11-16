#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	printf("%c\n", '8');
	ft_printf("%c\n", '8');
	printf("%s\n", "toto");
	ft_printf("%s\n", "toto");
	return (0);
}