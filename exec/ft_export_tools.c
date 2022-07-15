/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:26:32 by atabiti           #+#    #+#             */
/*   Updated: 2022/07/15 17:21:38 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minishell.h"

void	swap(struct s_environ *a, struct s_environ *b)
{
	char	*tmp;
	char	*tmp2;

	tmp = a->name;
	a->name = b->name;
	b->name = tmp;
	tmp2 = a->value;
	a->value = b->value;
	b->value = tmp2;
}

void	ftsortenv(struct s_environ **head)
{
	struct s_environ	*current;
	struct s_environ	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (ft_strcmp(current->name, next->name) > 0)
			{
				swap(current, next);
			}
			next = next->next;
		}
		current = current->next;
	}
}

int	ft_export_1(struct s_environ *envp)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	if (envp != NULL)
	{
		i = 0;
		ftsplitenv(envp, x);
		ftsortenv(&envp);
		while (envp)
		{
			printf("declare -x %s=\"%s\"\n", envp->name, envp->value);
			envp = envp->next;
		}
		return (SUCCESSFUL);
	}
	return (UNSUCCESSFUL);
}

int	check_name_is_valid(char **split, int i, t_cmd *cmd)
{
	if (ft_is_alpha_mod(split[0][0]) == 0)
	{
		printf("Minishell: export: `%s': not a valid identifier\n",
				cmd->cmd[i]);
		return (1);
	}
	return (0);
}
