/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 08:43:04 by atabiti           #+#    #+#             */
/*   Updated: 2022/07/14 10:10:50 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_init(t_cmd *cmds, struct s_envp *envp)
{
	cmds->cmdnbr = 0;
	cmds->new = NULL;
	cmds->args_execve = NULL;
	cmds->cmdnbr = 0;
	cmds->cmd_iteration = 0;
	cmds->envvarpos = 0;
	cmds->delimiter = NULL;
	cmds->args_execve = NULL;
	cmds->fd_out = 1;
	//env 
	envp->ismalloced = 0;
	envp->new = NULL;
	return (0);
}
