/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:34:35 by srossi            #+#    #+#             */
/*   Updated: 2018/09/11 14:40:03 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdlib.h>
# include <limits.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <dirent.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

# define OPTS "pqrs"
# define OPT_PRINT_STDIN (1 << 0)
# define OPT_QUIET (1 << 1)
# define OPT_REV (1 << 2)
# define OPT_STRING (1 << 3)

typedef struct		s_info
{
	int				command;
	int				options;
	char			*file_to_hash;
    char			*string_to_hash;
}					t_info;

//typedef int			(*t_node_cmp)(t_node *current_node, t_node *child);
//typedef void		(*t_node_action)(t_node *node, t_info *info);
void				ft_get_options(char option, t_info *info);
void				ft_print_usage();
int					ft_check_argv(char *argv, int option);
int					ft_check_argv_all(int argc, char **argv);
void				ft_error(t_info *info, char *path);
void				ft_error_option(char *option);
void				ft_errno_error(t_info *info, char *path);
int					ft_check_errors_2(t_info *info, char *path, struct stat *st\
		, DIR *dir);
void				ft_check_errors(t_info *info, DIR *dir, char *path);
void	            ft_argv_sort(char *argv[], int size);

#endif
