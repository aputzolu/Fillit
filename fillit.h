/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndudnicz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:12:44 by ndudnicz          #+#    #+#             */
/*   Updated: 2015/12/12 16:53:34 by ndudnicz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_SIZE 21

typedef struct			s_pattern
{
	char				letter;
	char				*str;
	char				*coord;
	struct s_pattern	*next;
}						t_pattern;

typedef struct			s_tool
{
	char				error;
	char				index;
	int					height;
	int					back_n;
	int					n;
}						t_tool;

t_pattern				*reader(int fd, t_tool *tool);
t_tool					*init_tool(void);
t_pattern				*add_link(t_pattern *pattern);
void					checker_map(t_tool *tool, t_pattern *pattern);
void					coord_map(t_pattern *pattern);
void					clean_str(t_pattern *pattern);
void					clean_position(t_tool *tool,
							t_pattern *pattern, char *str, int i);
char					*create_str(int height, int back_n);
void					solve(t_tool *tool, t_pattern *pattern);

#endif
