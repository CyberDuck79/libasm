; Prototype :	char *ft_strcpy(char *dst, const char *src)
; Registers :	rdi rsi rdx rcx r8
; Description :	copy string src to dst, dst need to be large enough

global		ft_strcpy

extern		ft_strlen
extern		ft_memcpy

section		.text

ft_strcpy:
	mov		rdx, rdi
	mov		rdi, rsi
	call	ft_strlen
	mov		rdi, rdx
	mov		rdx, rax
	call	ft_memcpy
	ret
