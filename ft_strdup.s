; Prototype :	char *ft_strdup(const char *s)
; Registers :	rdi rsi rdx rcx r8 r9 r10
; Description :	return a new string copy of the input string

global		_ft_strdup

extern		_ft_strlen
extern		_malloc
extern		_ft_memcpy

section		.text

_ft_strdup:
	push	rdi
	call	_ft_strlen
	inc		rax
	mov		rdi, rax
	push	rax
	sub		rsp, 0x08
	call	_malloc
	add		rsp, 0x08
	pop		rdx
	pop		rdi
	mov		rsi, rdi
	mov		rdi, rax
	call	_ft_memcpy
	ret
