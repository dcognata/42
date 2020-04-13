/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcognata <dcognata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:22:29 by dcognata          #+#    #+#             */
/*   Updated: 2018/09/26 21:50:21 by dcognata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
# define FT_LS

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h> 
# include <sys/stat.h> 
# include <dirent.h>
# include <unistd.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>

# define TRUE		1
# define FALSE		0

# define TYPE_REG	1
# define TYPE_DIR	2
# define TYPE_CHR	3
# define TYPE_BLK	4
# define TYPE_FIFO	5
# define TYPE_LNK	6
# define TYPE_SOCK	7

# define NO_ARGS	0x1
# define FLAG_NONE	0x2
# define FLAG_A		0x4
# define FLAG_L		0x8
# define FLAG_T		0xA
# define FLAG_R		0x20
# define FLAG_RR	0x40
# define FLAG_G		0x80

# define ERR_FLAG	1
# define ERR_MALLOC	2
# define ERR_STAT	3

typedef int			t_bool;

typedef struct		s_lslist
{
	char			*path;
	char			*name;
	struct stat		*stat;
	t_bool			error;
	struct s_lslist *next;	
}					t_lslist;

char				**parse_flags(int argc, char **argv, char *flags);
void				parse_args(t_lslist **list, char **to_parse, char *flags);
void				add_item(t_lslist **list, char *path, char *name);
void				force_exit(t_lslist *list, char *error, int type);
void				clean_app(t_lslist *list);
void				sort_list(t_lslist **list, char *flags, t_bool first);
void				ft_ls(t_lslist **list, char *flags, t_bool first);

#endif