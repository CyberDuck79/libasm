; Prototype :	char *ft_strcpy(char *dst, const char *src)
; Registers :	rdi rsi rdx rcx r8
; Description :	copy string src to dst, dst need to be large enough

global		_ft_strcpy

extern		_ft_strlen
extern		_ft_memcpy

section		.text

_ft_strcpy:
	mov		rdx, rdi
	mov		rdi, rsi
	call	_ft_strlen
	mov		rdi, rdx
	mov		rdx, rax
	call	_ft_memcpy
	ret
