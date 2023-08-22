#include <stdio.h>

void	ft_putstr(char *str)
{
	char	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}
