; Prototype :	int ft_checkset(const char *str, const char *set)
; Registers :	rdi rsi rdx
; Description :	return 1 if a char of the set is present in the input string

global		_ft_checkset

section 	.text

_ft_checkset:
	cld
	mov		rdx, rdi
.reset_str:
	mov		rdi, rdx
	lodsb
	test	al, al
	jz		.false
.compare:
	cmp		byte [rdi], 0x00
	je		.reset_str
	scasb
	jne		.compare
	mov		rax, 0x01
	ret
.false:
	xor		rax, rax
	ret
