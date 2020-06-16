; Prototype : void ft_list_push_front(t_list **begin_list, void *data)
; Registers : rdi rsi
; Description : push new node at front of the list

global		ft_list_push_front

extern		ft_create_elem

section		.text

ft_list_push_front:
	push	rdi
	mov		rdi, rsi
	call	ft_create_elem
	pop		rdi
	mov		rsi, [rdi]
	mov		[rax+8], rsi
	mov		[rdi], rax
	ret
