; Prototype :	void *ft_memcpy(void *dst, const void *src, size_t n)
; Registers :	rdi rsi rdx rcx r8
; Description :	copy memory from src to dst for n bytes, return dst

global		ft_memcpy

section		.text

ft_memcpy:
	cld
	mov		r8, rdi
	mov		rcx, 0x08
	mov		rax, rdx
	xor		rdx, rdx
	div		rcx
	mov		rcx, rax
.copy:
	rep		movsq
	jnz		.copy
	mov		rcx, rdx
.copy_carry:
	rep		movsb
	jnz		.copy_carry
	mov		rax, r8
	ret
