#include "libft.h"
#include <stdio.h>

double	d_strlen(const	char *str)
{
	int		i;
	double	len;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			len = -1;
		i++;
		len++;
	}
	return (len);
}

char	*quit_dot(const char *str)
{
	char	*s1;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s1 = malloc(sizeof (char) * ft_strlen(str));
	if (!s1)
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
			i++;
		else
		{
			s1[j] = str[i];
			i++;
			j++;
		}
	}
	s1[j] = '\0';
	return (s1);
}

double	aux_atod(char *s)
{
	int	i;
	int	sg;
	int	nb;

	i = 0;
	sg = 1;
	nb = 0;
	while ((s[i] >= '\t' && s[i] <= '\r') || s[i] == ' ')
	{
		i++;
	}
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sg = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		nb = (nb * 10) + (s[i] - '0');
		i++;
	}
	return ((double)sg * (double)nb);
}

double	ft_atod(const char *str)
{
	double	len;
	char	*s;
	double	number;

	if (!str)
		return (0);
	len = d_strlen(str);
	s = quit_dot(str);
	number = aux_atod(s);
	free(s);
	while (len-- != 0)
		number = number / 10;
	return (number);
}
