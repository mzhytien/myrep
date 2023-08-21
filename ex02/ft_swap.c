#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int с;
	с = *a;
	*a = *b;
	*b = с;
}

void	ft_putnbr(int nbr)
{
	char	digit;

	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
	}
	digit = nbr % 10 + '0';
	write(1, &digit, 1);
}

int	main()
{
	int	num1;
	int	num2;

	num1 = 5;
	num2 = 10;
	int *ptr1 = &num1;
	int *ptr2 = &num2;

	*ptr1 = &num1;
	*ptr2 = &num2;

	ft_swap(ptr1, ptr2);

	ft_putnbr(num1);
	write(1, " ", 1);
	ft_putnbr(num2);

	return 0;
}
