/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_to_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:34:10 by mkarim            #+#    #+#             */
/*   Updated: 2022/07/06 10:36:20 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"

int fill_cmd(t_token *token, int pipenbr, struct s_envp *envp, int cmds, int iteration, 	t_cmdl	*cmd)
{
	while (token)
	{
		if (token->type == 8 && iteration == 0)
		{
			cmd[cmds].cmd = token->value;
			printf("CMD is %s\t\n", cmd[iteration].cmd);
		}
		if (token->type == 8 && iteration > 0)
		{
			cmd->args[iteration] = strdup(token->value);
			printf("ARGS is %s\t\n", cmd->args[iteration]);
			iteration++;
		}
		if (token->type == 6)
		{
            		token = token->next;

            fill_cmd(token , pipenbr, envp, cmds + 1, 0 , cmd);
        }
		iteration++;
		token = token->next;
	}
    return 0;
}
void	pass_to_exec(t_token *token, int pipenbr, struct s_envp *envp)
{
	t_cmdl	*cmd;
	int		itre;
	int		args;

	itre = 0;
	args = 0;
	// printf("pipe nb %d cmd nbr %d\n", pipenbr - 1, pipenbr );
	// print_token(token);
	cmd = (t_cmdl *)malloc(sizeof(t_cmdl) * (pipenbr));
	cmd->args = (char **)malloc(sizeof(char *) * (pipenbr));
        fill_cmd(token, pipenbr, envp, 0, 0, cmd);
	cmd->cmd_nbr = pipenbr;
	cmd->there_is_pipe = pipenbr - 1;
	cmd->cmd_iteration = 0;
	if (cmd->cmd_nbr == 1 && cmd[0].cmd != NULL)
	{
		// heredoc_without_cmd(cmd);
		one_cmd(cmd, envp);
	}
	else if (cmd->cmd_nbr > 1)
	{
		//problem wc  | ls ? in bash ls is printing first and problem in  wc | ls when unset the PATH it must shot 2 errors not one
		// grep 1337 exec/*.c problem
		ft_pipe(cmd, envp);
	}
}
