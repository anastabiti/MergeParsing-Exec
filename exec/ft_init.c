/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 08:43:04 by atabiti           #+#    #+#             */
/*   Updated: 2022/07/09 09:59:44 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_init( t_cmd *cmds)
{
		cmds->cmdnbr = 0;

	cmds->new = NULL;
	cmds->args_execve =NULL;
	cmds->cmdnbr = 0;
	cmds->cmd_iteration = 0;
	cmds->envvarpos = 0;
	cmds->delimiter = NULL;
	return (0);
}
