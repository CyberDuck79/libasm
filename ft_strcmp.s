; Prototype :	int ft_strcmp(const char *s1, const char *s2)
; Registers :	rdi rsi rdx
; Description :	compare string and return 0 if equal, -1 if s1 < s2 or 1 if s1 > s2

global		ft_strcmp

section		.text

ft_strcmp:
	xor		rax, rax
	xor		rdx, rdx
	cld
.compare:
	cmp		byte [rsi], 0x00
	je		.last
	cmpsb
	je		.compare
	jmp		.diff
.last:
	cmpsb
.diff:
	mov		al, byte [rdi - 1]
	mov		dl, byte [rsi - 1]
	sub		rax, rdx
	ret
