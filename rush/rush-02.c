#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char *units[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char *teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

void writestring(int fd, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	numbertowords(int n, int fd)
{
	char	buffer[100];
	int	length;

	length = 0;
	if (n == 0)
	{
		writestring(fd, "zero");
	}
	else if (n < 10)
	{
		writestring(fd, units[n]);
	}
	else if (n < 20)
	{
		writestring(fd, teens[n - 10]);
	}
	else if (n < 100)
	{
		writestring(fd, tens[n / 10]);
		if (n % 10 != 0)
		{
			write(fd, " ", 1);
			writestring(fd, units[n % 10]);
		}
	}
	else if (n < 1000)
	{
		writestring(fd, units[n / 100]);
		write(fd, " hundred", 8);
		if (n % 100 != 0)
		{
			write(fd, " and ", 5);
			numbertowords(n % 100, fd);
		}
	}
	else
	{
		writestring(fd, "Number out of range");
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "Please use: ./rush-02 <number>\n", 30);
		return 1;
	}
	if (atoll(argv[1]) < 0)
	{
		write(1, "Please enter a non-negative number\n", 34);
		return 1;
	}
	numbertowords(atoll(argv[1]), 1);
	write(1, "\n", 1); 
	return 0;
}
