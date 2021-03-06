/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 09:22:50 by fhenrion          #+#    #+#             */
/*   Updated: 2020/04/06 12:35:02 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdlib.h>
# include <stdio.h>
# include "ft_list.h"

typedef size_t	t_index;

size_t			ft_strlen(const char *str);
char			*ft_strcpy(char *dst, const char *src);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			ft_bzero(void *s, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
ssize_t			ft_write(int fd, const void *buf, size_t n);
ssize_t			ft_read(int fd, void *buf, size_t n);
char			*ft_strdup(const char *s);
int				ft_atoi(const char *str);
int				ft_checkdup(const char *str);
int				ft_checkset(const char *str, const char *set);
char			*ft_skipset(const char *str, const char *set);
ssize_t			ft_setindex(const char *str, const char c);
int				ft_atoi_base(const char *str, const char *base);
t_list			*ft_create_elem(void *data);
size_t			ft_list_size(t_list *list);
void			ft_list_push_front(t_list **begin_list, void *data);
void			*ft_list_pop_front(t_list **begin_list);
void			ft_list_sort(t_list **begin_list, int (*cmp)());
void			ft_list_remove_if(t_list **list, void *data_ref, \
				int (*cmp)(), void (*free_fct)(void*));
void			ftfree(void *ptr);

// fonctions à implémenter si besoin
/*
---> fonctions utiles de la libft
*/

// fonctions liste à implémenter si besoin
// recursivité pour certaines fonctions ? a voir en c avant
/*
void			ft_list_add_queue(t_list *list, void *data);
void			*ft_list_pop_queue(t_list **begin_list);
void			*ft_list_pop_at(t_list **begin_list, t_index i);
void			*ft_list_get_first(t_list *list);
void			*ft_list_get_at(t_list *list, t_index i);
void			*ft_list_get_last(t_list *list);
void			*ft_list_find(t_list **list, void *data_ref, \
				int (*cmp)());
void			*ft_list_find_pop(t_list **list, void *data_ref, \
				int (*cmp)());
void			ft_list_remove_first(t_list **begin_list, \
				void (*free_fct)(void*));
void			ft_list_remove_at(t_list **begin_list, t_index i, \
				void (*free_fct)(void*));
void			ft_list_remove_last(t_list **begin_list, \
				void (*free_fct)(void*));
void			ft_list_reverse(t_list *list);
t_list			*ft_tab_to_list(void *tab);
void			*ft_list_to_tab(t_list *list);
void			ft_list_insert(t_list *begin_list, void *data, int (*cmp)());
void			ft_list_foreach(t_list *begin_list, void (*f)(void *));
void			ft_list_foreach_if(t_list *begin_list, void (*f)(void *), \
				void *data_ref, int (*cmp)());
void			ft_list_clear(t_list **begin_list, void (*free_fct)(void *));
void			ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void			ft_list_merge(t_list **begin_list1, t_list *begin_list2, \
				int (*cmp)());
*/

#endif