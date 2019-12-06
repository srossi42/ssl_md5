/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:34:35 by srossi            #+#    #+#             */
/*   Updated: 2019/11/30 17:28:05 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "ft_md5.h"
# include "ft_sha256.h"
# include "ft_sha224.h"

# define NB_FUNCTIONS 3
# define BUFFER_SIZE 64
# define OPTS_MD5_SHA256 "pqrs"
# define OPT_PRINT_STDIN 1
# define OPT_QUIET 2
# define OPT_REV 4
# define OPT_STRING 8
# define STRING_READ 16
# define FILE_READ 32
# define FILE_READING 64
# define STRING_READING 128
# define STDIN_READ 1

typedef struct	s_info
{
	char		*algo_name;
	int			p;
	char		options;
	char		options2;
	char		*string_to_hash;
	int			current_arg;
	uint64_t	input_len;
	char		*input;
	char		*hash;
	boolean_t	ready_to_hash;
}				t_info;

typedef char	*(*t_algo_f)(char *str_to_hash, size_t size);
typedef void	(*t_parse_f)(t_info *info, int argc, char **arg);

typedef struct	s_ptrs
{
	char		*cmd;
	t_algo_f	ft_hash;
	t_parse_f	ft_parse;
}				t_ptrs;

typedef unsigned short int	t_uint2;
typedef unsigned long int	t_uint4;

void			ft_reinit_info(t_info *info);
char			*ft_md5(char *str_to_hash, size_t size);
char			*ft_sha256(char *str_to_hash, size_t size);
char			*ft_sha224(char *str_to_hash, size_t size);
void			ft_parse_opts(t_info *info, int argc, char **arg);
int				ft_is_valid_option(char option, char *options_list);
int				ft_set_option(t_info *info, char option);
void			ft_print_usage(void);
void			ft_print_usage_option(t_info *info, char option);
void			ft_print_invalid_command(char *command);
void			ft_error_opening(char *algo_name, char *arg, char *reason);
void			ft_free_info(t_info *info);
void			ft_print_hash(t_info *info, int argc, int n);
void			ft_set_valid_option(t_info *info, char **argv, int argc);
uint32_t		ft_reverse_bits(uint32_t value);
uint32_t		ft_rotate_left(uint32_t x, uint32_t n);
uint32_t		ft_rotate_right(uint32_t x, uint32_t n);

void			ft_set_readfile(t_info *info, char *filename);
void			ft_read_from_file(t_info *info, char *filename_to_hash);
void			ft_read_stdin(t_info *info);
void			ft_read_hash_stdin(t_info *info, int argc, t_ptrs *hash_ptrs);
void			ft_read_hash_saved_str(t_info *info, int argc, char **argv);
void			ft_read_hash_saved_str_rq(t_info *info, int argc, char **argv);
void			ft_read_hash_stdin_2(t_info *info, t_ptrs *hash_ptrs, int argc);
char			*ft_strnjoin(char *s1, char *s2, size_t len1, size_t len2);
char			*ft_strjoin_del(char *s1, char *s2);
char			*ft_str_toupper(char *str);

static t_ptrs	g_tab_ptrs[NB_FUNCTIONS] = {
	{"md5", ft_md5, ft_parse_opts},
	{"sha256", ft_sha256, ft_parse_opts},
	{"sha224", ft_sha224, ft_parse_opts},
};

#endif
