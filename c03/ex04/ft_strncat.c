#include <unistd.h>

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	while (*dest)
	{
		dest++;
	}
	while (*src && nb > 0)
	{
		*dest = *src;
		dest++;
		src++;
		nb--;
	}
	*dest = '\0';
	return (dest);
}