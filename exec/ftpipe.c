/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atabiti <atabiti@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 08:51:00 by atabiti           #+#    #+#             */
/*   Updated: 2022/07/11 19:00:06 by atabiti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../parsing/parse.h"
// problem here
//&& redire_2(list) == 0 i must check previous redirection is not rdout
//  &&  ft_strncmp( list[0].type[1], RDOUT, 7) != 0 not workings
//check echo asd > f1 > f3 << f4
//ls > f1 > f2<< FF
int	redire_2(t_cmd *list)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (list->f_type[i])
	{
		if (list->f_type[i] == RED_IN_APP)
		{
			list->fd_in = open("/tmp/tmpherdoc", O_RDWR | O_CREAT | O_TRUNC,
					0600);
		}
		if (list->f_type[i] == RED_OUT)
		{
			list->fd_out = open(list->f_name[i],
								O_RDWR | O_CREAT | O_TRUNC,
								0600);
			if (list->fd_out == -1)
			{
				printf("bash: No such file or directory\n");
			}
			ret = 1;
		}
		if (list->f_type[i] == RED_IN)
		{
			list->fd_in = open(list->f_name[i], O_RDONLY, 0);
			if (list->fd_in == -1)
			{
				printf("bash: No such file or directory\n");
			}
			ret = 1;
		}
		if (list->f_type[i] == RED_OUT_APP)
		{
			list->fd_out = open(list->f_name[i],
								O_RDWR | O_CREAT | O_APPEND,
								0600);
			ret = 1;
		}
		printf("i is %d \n", i);
		i++;
	}
	return (ret);
}

void	ft_pipe(t_cmd *list, struct s_envp *envp)
{
	int	i;
	int	id;
	
	int pipes[2];
	i = 0;
	int fdin = 0;
	list->cmd_iteration = 0;
	list->fd_out = 1;

	while (list)
	{

		
			
					heredoc_exec(list);


		pipe(pipes);//
		id = fork();
		if (id == 0)
		{
			// if(i != 0)
			
			dup2( fdin ,  0);
			if (list->next)
				dup2(pipes[1], 1);//
	
		
			close(pipes[0]);
					redirections(list);
			set_rd(list);
			if(ft_is_built_in(envp, list) == 0)
			ft_bin_usr_sbin(list, envp);

		}
		else
		{
			wait(&g_exit_status);
			if (WIFEXITED(g_exit_status))
				g_exit_status = WEXITSTATUS(g_exit_status);
			close(pipes[1]);
			fdin = pipes[0];
		// pipes[0] = 	 list->fd_in;
			i++;
			list = list->next;
		}
	}
}
