/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakende <rmakende@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:33:32 by rmakende          #+#    #+#             */
/*   Updated: 2024/11/10 14:56:05 by rmakende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_split(char ***token_temp)
{
	int		j;
	char	**token;

	j = 0;
	token = *token_temp;
	while (token[j] != NULL)
	{
		free(token[j]);
		j++;
	}
	free(token);
}

int	*init_nums(int **contador, t_list **list)
{
	int	*nums;

	nums = malloc(500 * sizeof(int));
	if (!nums)
	{
		free_list(list);
		return (NULL);
	}
	**contador = 0;
	return (nums);
}

int	parse_argument(const char *arg, int *nums, int *contador, t_list **list)
{
	char	**tokens;

	if (strchr(arg, ' ') != NULL)
	{
		tokens = ft_split(arg, ' ');
		if (!tokens)
		{
			free(nums);
			free_list(list);
			return (-1);
		}
		if (parse_tokens(tokens, nums, contador, list) == -1)
			return (-1);
	}
	else if (arg[0] != '\0')
	{
		if (validate_and_store_num(arg, nums, contador, list) == -1)
			return (-1);
	}
	return (0);
}

int	parse_tokens(char **tokens, int *nums, int *contador, t_list **list)
{
	int	j;

	j = 0;
	while (tokens[j] != NULL)
	{
		if (validate_and_store_num(tokens[j], nums, contador, list) == -1)
		{
			free_split(&tokens);
			return (-1);
		}
		j++;
	}
	free_split(&tokens);
	return (0);
}

int	validate_and_store_num(const char *token, int *nums, int *contador,
		t_list **list)
{
	int	comparer;

	comparer = 0;
	nums[*contador] = ft_atoi(token, &comparer);
	if (comparer || (nums[*contador] == 0 && is_valid_num(token) == 1))
	{
		free(nums);
		free_list(list);
		return (-1);
	}
	(*contador)++;
	return (0);
}
