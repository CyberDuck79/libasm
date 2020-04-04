; Prototype : t_list *ft_new_list(void *data)
; Registers : rdi
; Description : Create a new list with data ptr

global		_ft_new_list

extern		_malloc

section		.text

_ft_new_list:
	push	rdi
	mov		rdi, 0x10
	call	_malloc
	pop		rdi
	mov		[rax], rdi
	mov		qword [rax+8], 0x00
	ret
