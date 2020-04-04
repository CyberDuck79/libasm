; Prototype : t_list *ft_create_elem(void *data)
; Registers : rdi
; Description : Create a new list with data ptr

global		_ft_create_elem

extern		_malloc

section		.text

_ft_create_elem:
	push	rdi
	mov		rdi, 0x10
	call	_malloc
	pop		rdi
	mov		[rax], rdi
	mov		qword [rax+8], 0x00
	ret
