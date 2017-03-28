/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esantos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 13:44:43 by esantos           #+#    #+#             */
/*   Updated: 2016/11/07 11:28:35 by esantos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

int						g_tetri_num;
# define BUFFER_SIZE 4096

typedef struct			s_tetrimino
{
	char				**tetrimino;
	char				letter;
	int					x;
	int					y;
	struct s_tetrimino	*next;
}						t_tetrimino;

int						ft_nltest(char *buf);
int						ft_g_tetrimino(char *buffer);
int						ft_maincheck(char **tab);
int						ft_shapecheck(char *str);
int						ft_numcheck(char *str);
int						ft_numcheck(char *str);
int						ft_maincheck(char **tab);
int						ft_checkline(char *str);
int						ft_width(char *tab);
int						ft_height(char *tab);
int						ft_get_i(char **tab);
int						ft_is_alone(char *s);
int						ft_check_void_int(char *s);
int						ft_get_j(char **tab);
int						ft_place(t_tetrimino *head, \
		int square_size, char **tab);
int						ft_position_check(t_tetrimino \
		*head, char **tab, int square_size);
void					ft_freetab(char **tab, int num);
void					ft_print_tab(char **tab);
char					**ft_tabfill(char **tab, char *buf);
char					**up_arrange(int i_min, char **tab);
char					**ft_redo(t_tetrimino *head, char **tab);
char					**ft_make_tab(char **tab, int square_size);
char					**left_arrange(int j_min, char **tab);
char					**ft_solve(t_tetrimino \
		*head, int square_size, char **solved_tab);
char					**ft_puttet(t_tetrimino *head, char **tab);
t_tetrimino				*ft_newtetri(char **tab, int num);
t_tetrimino				*ft_splittab(char **tab);
t_tetrimino				*arrange(t_tetrimino *head);
#endif
