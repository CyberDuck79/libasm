; Prototype :	int ft_checkdup(const char *str)
; Registers :	rdi rsi
; Description :	return 1 if dup in the input string

global		ft_checkdup

section		.text

reset:
	inc		rdi
ft_checkdup:
	cld
	cmp		byte [rdi], 0x00
	je		.false
	lea		rsi, [rdi+1]
.next:
	lodsb
	test	al, al
	jz		reset
	cmp		byte [rdi], al
	jne		.next
	mov		rax, 0x01
	ret
.false:
	xor		rax, rax
	ret
