; Prototype : void ft_list_push_front(t_list **list, void *data)
; Registers : rdi rsi
; Description : push new node at front of the list

global		_ft_list_push_front

extern		_ft_new_list

section		.text

_ft_list_push_front:
	push	rdi
	mov		rdi, rsi
	call	_ft_new_list
	pop		rdi
	mov		rsi, [rdi]
	mov		[rax+8], rsi
	mov		[rdi], rax
	ret