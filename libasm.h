/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 09:22:50 by fhenrion          #+#    #+#             */
/*   Updated: 2020/04/04 14:38:23 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdlib.h>
# include <stdio.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *str);
char				*ft_strcpy(char *dst, const char *src);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
ssize_t				ft_write(int fd, const void *buf, size_t n);
ssize_t				ft_read(int fd, void *buf, size_t n);
char				*ft_strdup(const char *s);
int					ft_atoi(const char *str);
int					ft_checkdup(const char *str);
int					ft_checkset(const char *str, const char *set);
char				*ft_skipset(const char *str, const char *set);
ssize_t				ft_setindex(const char *str, const char c);
int					ft_atoi_base(const char *str, const char *base);
t_list				*ft_new_list(void *data);
size_t				ft_list_size(t_list *list);
void				ft_list_push_front(t_list **list, void *data);
void				*ft_list_pop_front(t_list **list);
void				ft_list_add_queue(t_list *list, void *data);
void				*ft_list_pop_queue(t_list **list);
void				*ft_list_get_index(t_list *list, size_t index);
void				ft_list_remove_if(t_list **list, \
					void *data_ref, int (*cmp)(), void (*free_fct)(void*));
void				ft_list_sort(t_list **list, int (*cmp)());

#endif