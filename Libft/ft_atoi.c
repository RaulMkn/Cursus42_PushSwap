/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 02:08:25 by rmakende          #+#    #+#             */
/*   Updated: 2024/10/09 16:09:40 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\v')
			i++;
		else if (str[i] == '\n' || str[i] == '\f')
			i++;
		else if (str[i] == '\t' || str[i] == '\r')
			i++;
		else
			break ;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sum;
	int	mult;

	i = check_spaces(str);
	sum = 0;
	mult = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	if (i >= 2)
		mult = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = (sum * 10) + (str[i] - '0');
		if (ft_isalpha(str[i]) && sum )
			return (0);
		i++;
	}
	return (sum * mult);
}

#include <stdio.h>
#include <limits.h>

// Prototipo de la función ft_atoi que se asume está definida en otro lugar
int ft_atoi(const char *str);

int main() {
    // Pruebas con los valores máximo y mínimo de int
    const char *min_int_str = "-2147483649"; // INT_MIN

    int result_min = ft_atoi(min_int_str);

    // Imprimir los resultados
    printf("String: %s -> ft_atoi result: %d\n", min_int_str, result_min);

    // Verificar si los resultados coinciden con INT_MAX y INT_MIN

    if (result_min == INT_MIN) {
        printf("Min int test passed.\n");
    } else {
        printf("Min int test failed. Expected %d, got %d\n", INT_MIN, result_min);
    }

    return 0;
}
