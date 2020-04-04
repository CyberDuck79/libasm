; Prototype : void *ft_list_pop_front(t_list **list)
; Registers : rdi rsi
; Description : return the first node and remove it from the list

global		_ft_list_pop_front

section		.text

_ft_list_pop_front:
	mov		rax, [rdi]
	mov		rsi, [rax+8]
	mov		[rdi], rsi
	mov		rax, [rax]
	ret
