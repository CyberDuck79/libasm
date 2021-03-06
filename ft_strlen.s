; Prototype :	size_t ft_strlen(const char *str)
; Registers :	rdi rcx
; Description :	return a new string copy of the input string

global		ft_strlen

section		.text

ft_strlen:
	cld
	xor		rcx, rcx
	not		rcx
	xor		al, al
	repne	scasb
	not		rcx
	lea		rax, [rcx-1]
	ret
