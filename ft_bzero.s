; Prototype :	void ft_bzero(void *s, size_t n)
; Registers :	rdi rsi rcx rdx
; Description :	set the memory pointed by s to 0 for n bytes

global		_ft_bzero

section		.text

_ft_bzero:
	cld
	mov		rcx, 0x08
	mov		rax, rsi
	xor		rdx, rdx
	div		rcx
	mov		rcx, rax
	xor		rax, rax
.write:
	rep		stosq
	jnz		.write
	mov		rcx, rdx
.write_carry:
	rep		stosb
	jnz		.write_carry
	ret
