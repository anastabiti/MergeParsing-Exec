/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_to_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:34:10 by mkarim            #+#    #+#             */
/*   Updated: 2022/07/06 22:31:18 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"
int	strlen_list(t_token *token, int pipenbr, t_cmdl *cmd)
{
	int	i;

	i = 0;
	while (token)
	{
		if (token->type == 10)
		{
			i++;
		}
		token = token->next;
	}
	return (i);
}
int	file_list(t_token *token, int pipenbr, t_cmdl *cmd)
{
	int	i;

	i = 0;
	while (token)
	{
		if (token->type == 7)
		{
			i++;
		}
		token = token->next;
	}
	return (i);
}

int	fill_cmd(t_token *token, int pipenbr, t_cmdl *cmd)
{
	int	i;
	int	args;
	int	file;

	i = 0;
	args = strlen_list(token, pipenbr, cmd);
	file = file_list(token, pipenbr, cmd);
	printf("files %d\n", file);
	cmd->file = (char **)malloc(sizeof(char *) * (file));
	cmd->type = (char **)malloc(sizeof(char *) * (file));
	cmd[cmd->cmd_iteration].args = (char **)malloc(sizeof(char *) * (args + 1));
	args   = 0 ;
	while (token != NULL)
	{
		if (token->type == CMD)
		{
			cmd[cmd->cmd_iteration].cmd = token->value;
		}
		if (token->type == ARG)
		{
			cmd[cmd->cmd_iteration].args[args] = token->value;
			args++;
		}
		if (token->type == RED_OUT)
		{
			cmd[cmd->cmd_iteration].type[i] = token->value;
			token = token->next;
			cmd[cmd->cmd_iteration].file[i] = token->value;
			i++;
		}
		if (token->type == RED_IN)
		{
			cmd[cmd->cmd_iteration].type[i] = token->value;
			token = token->next;
			cmd[cmd->cmd_iteration].file[i] = token->value;
			i++;
		}
		token = token->next;
	}
	return (0);
}

int	pass_to_exec(t_token *token, int pipenbr, struct s_envp *envp)
{
	t_cmdl	*cmd;
	int		itre;
	int		args;

	itre = 0;
	args = 0;
	// printf("pipe nb %d cmd nbr %d\n", pipenbr - 1, pipenbr );
	// print_token(token);
	cmd = (t_cmdl *)malloc(sizeof(t_cmdl) * (pipenbr));
	fill_cmd(token, pipenbr, cmd);
	cmd->cmd_nbr = pipenbr;
	cmd->there_is_pipe = pipenbr - 1;
	cmd->fd_out = 1;
	cmd->cmd_iteration = 0;
	if (cmd->cmd_nbr == 1 && cmd[0].cmd != NULL)
	{
		// heredoc_without_cmd(cmd);
		one_cmd(cmd, envp);
		free2d(cmd->args);
	}
	// else if (cmd->cmd_nbr > 1)
	// {
	// 	//problem wc  | ls ? in bash ls is printing first and problem in  wc | ls when unset the PATH it must shot 2 errors not one
	// 	// grep 1337 exec/*.c problem
	// 	ft_pipe(cmd, envp);
	// }
	return (0);
}
