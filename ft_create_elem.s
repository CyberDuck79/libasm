; Prototype : t_list *ft_create_elem(void *data)
; Registers : rdi rsi rdx rcx r8 r9
; Description : Create a new list with data ptr

global		ft_create_elem

extern		malloc

section		.text

ft_create_elem:
	push	rdi
	mov		rdi, 0x10
	call	malloc
	pop		rdi
	mov		[rax], rdi
	mov		qword [rax+8], 0x00
	ret
