/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:14:00 by sminna            #+#    #+#             */
/*   Updated: 2021/12/27 19:34:05 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"
# include <signal.h>
# include <dirent.h>
# include <semaphore.h>
# include <sys/types.h>

typedef struct s_pipes {
	int		pipe_count;
	int		fd_in;
	int		fd_out;
	int		*flags;
}				t_pipes;

typedef struct s_shell {
	char	**str;
	int		pipe_count;
	int		pipe_count_max;
	int		func_count;
	int		i;
	int		j;
	int		n;
	int		error;
	int		flags_count;
	int		longs;
	int		error_cod;
	int		preflag;
	int		lenght;
	int		*flags;
	int		**flags_for_prog;
	int		tmp_split_p;
	int		tmp_split_on_off;
	int		*start_flag_prog;
	int		*count_flag_prog;
	int		cycle;
	char	tmp_split;
	int		tmp_split2;
	int		free;
	char	**envp;
	t_pipes	*pipes;
}				t_shell;

typedef struct s_com
{
	char			*name;
	char			**flags;
	struct s_com	*next;
	int				fd_in;
	int				fd_out;
	char			*path;
}				t_com;

void	rl_replace_line(const char *buffer, int val);
char	*get_next_line(int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split_shell(char const *s, char c, int i, t_shell *shell);
void	record_num(int count, t_shell *shell, char c);
int		fd_redirect(t_shell *shell);
int		preparser(char *str);
char	*shell_parser(char *str, t_shell *shell);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(void *b, size_t len);
void	memor_for_pipe_flags(char *str, t_shell *shell, int i, int j);
void	write_pipe_flags(t_shell *shell);
void	just_plus(int *a, int *b);
int		fd_redirect_input_2(t_shell *shell);
int		fd_redirect_input_1(t_shell *shell);
int		fd_file_exist(char *str, int j, int n);
char	*ft_find_file_name(char *str, t_shell *shell, int l);
char	*find_key(t_shell *shell, char *str1);
void	tmp_write(t_shell *shell, char c, int i);
char	**ft_split(char const *s, char c);
void	param_preparation(int argc, char **argv, char **envp, t_shell *shell);
void	sigin_c(int val);
void	sign_d(t_shell	*shell);
void	split_fresher(char **str, int j);
int		error_checker(char *str, t_shell *shell);
void	create_flag(char *str, t_shell *shell);
t_list	*make_ev(char **ev);
void	tmp_changer(t_shell *shell);
void	double_free(char *str1, char *str2);

//echo_pwd.c
int		ft_strlen_sym(char *str, char c);
int		ft_lstcount(t_com **com);
int		ft_pwd(void);
void	ft_echo_help(t_com *com);
int		ft_echo(t_com *com);

//utils.c
void	env_help(char *help);
void	ft_exec_one_help(t_com *com);

//env_cd.c
void	make_cd_pwd_help(t_list **evl, char *oldpwd);
int		make_cd_pwd(t_list **evl, char *oldpwd);
void	ft_cd_help(t_com *com, char *oldpwd, t_list **evl);
int		ft_cd(t_com *com, t_list **evl);
int		ft_env(t_com *com, t_list **evl);

//exit.c
int		clear_all_com(t_com *com);
void	ft_exit_error(t_com *com, t_list **evl);
int		ft_exit(t_com *com, t_list **evl);

//export.c
int		ebannyi_tipo_unset1(char *arg, t_list **l1, t_list **l2, t_list **evl);
int		ebannyi_tipo_unset2(char *arg, t_list **l1, t_list **l3, t_list **l2);
int		tipo_unset_help(char *arg, t_list **evl);
int		tipo_unset(char *arg, t_list **evl);
int		ft_export(t_com *com, t_list **evl);

//export_help.c
void	print_export_error(char *str);
int		parsing_export(char *str);
char	*arg_tipo_unset(char *arg);
int		tipo_unset_h_c2(char *arg, char *help);
int		tipo_unset_h_c1(char *arg, t_list **evl, char *help, t_list *l1);

//export_help2.c
void	sort_change2(t_list **ll1);
int		sort_count(t_list **evl);
void	print_simple_export(char *str);
void	export_print_sim(t_list **evl);
void	ft_sort_easy(t_list **evl);

//export_help3.c
int		who_is_more(char *s1, char *s2);
void	sort_change1(t_list **evl, t_list **l1);

//nopipe.c
char	*change_name(char *str);
int		p_access_er(char *s1, char *s2);
int		check_access_dir_help(t_com *com, DIR *dir, int iden);
int		check_access_dir(t_com *com);
int		ft_exec_one(t_com *com, char **ev, t_list **evl);

//nopipe_utils.c
int		ft_exec_sim_help(t_com *com, char **ev, t_list *l);
void	ft_exec_sim(t_com *com, char **ev, t_list **evl);
int		ft_exec_other(t_com *com, t_list **evl);
char	*make_new_name(char *str);

//pipe.c
t_com	*ft_lstgive(t_com **com, int i);
int		execve_for_pipe(t_com *com, char **ev, t_list **evl);
void	ft_child_b(t_com *com, char **ev, t_list **evl, int fd_out);
int		ft_exec_pipe(t_com **com, char **ev, t_list **evl);

//start.c
int		timur(char **ev, t_com *com, t_list **evl);

//unset.c
void	unset_help2(t_com *com, int i, t_list **evl, t_list **l1);
int		unset_help31(t_com *com, int i, char *help);
int		unset_help32(char *hel2, t_com *com, int i);
void	unset_help3(t_com *com, int i, t_list **evl);
int		ft_unset(t_com *com, t_list **evl);

//unset_help.c
int		check_arg_unset(char *str);
int		unset_help1(t_com *com, int i);

#endif
