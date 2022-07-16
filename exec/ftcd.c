/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 11:37:52 by atabiti           #+#    #+#             */
/*   Updated: 2022/07/16 10:53:18 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../minishell.h"

int	check_home_inenv(char *findhome, char *error)
{
	int	len;

	len = 0;
	if (findhome == NULL)
	{
		g_exit_status = 1;
		error = "Minishell: cd: HOME not set\n";
		len = ft_strlen(error);
		write(2, error, len);
		return (UNSUCCESSFUL);
	}
	return (0);
}

int	cd_last_check(t_cmd *cmd)
{
	int	len;

	len = 0;
	if (chdir(cmd->cmd[1]) == -1)
	{
		ft_putstr_fd("Minishell: cd : ", 2);
		ft_putstr_fd(cmd->cmd[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (UNSUCCESSFUL);
	}
	return (SUCCESSFUL);
}

int	ftcd_c(t_cmd *cmd)
{
	if (cmd->cmd[1] == NULL)
	{
		if (check_home_inenv(cmd->findhome, cmd->error) == UNSUCCESSFUL)
			return (UNSUCCESSFUL);
	}
	if (cmd->cmd[1] == NULL)
	{
		chdir(cmd->findhome);
		return (SUCCESSFUL);
	}
	else if (cmd->cmd[1] != NULL)
	{
		if (cd_last_check(cmd) == 1)
			return (1);
	}
	return (SUCCESSFUL);
}

int	ftcd(t_cmd *cmd, struct s_environ *envp)
{
	int	x;

	x = 0;
	cmd->findhome = NULL;
	while (envp)
	{
		if (ft_strncmp(envp->name, "HOME", 5) == 0)
		{
			cmd->findhome = envp->value;
			break ;
		}
		envp = envp->next;
	}
	if (ftcd_c(cmd) == UNSUCCESSFUL)
		return (UNSUCCESSFUL);
	return (SUCCESSFUL);
}
