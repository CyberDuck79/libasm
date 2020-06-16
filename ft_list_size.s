; Prototype : size_t ft_list_size(t_list *list)
; Registers : rdi
; Description : Return the size of a list

global		ft_list_size

section		.text

ft_list_size:
	xor		rax, rax
.check_next:
	test	rdi, rdi
	jz		.ret_size
	inc		rax
	mov		rdi, [rdi+8]
	jmp		.check_next
.ret_size:
	ret
