; Prototype :	char *ft_strdup(const char *s)
; Registers :	rdi rsi rdx rcx r8 r9 r10
; Description :	return a new string copy of the input string

global		ft_strdup

extern		ft_strlen
extern		malloc
extern		ft_memcpy

section		.text

ft_strdup:
	push	rdi
	call	ft_strlen
	inc		rax
	mov		rdi, rax
	push	rax
	sub		rsp, 0x08
	call	malloc
	add		rsp, 0x08
	pop		rdx
	pop		rdi
	mov		rsi, rdi
	mov		rdi, rax
	call	ft_memcpy
	ret
