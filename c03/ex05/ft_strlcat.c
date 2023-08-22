#include <stdio.h>


unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dest_len;
	unsigned int i;

	dest_len = 0;
	i = 0;
	while (dest[dest_len] && dest_len < size)
	{
		dest_len++;
	}
	while (src[i] && dest_len + i + 1 < size)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	while (src[i])
	{
		i++;
	}
	return (dest_len + i);
}
