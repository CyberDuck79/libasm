; Prototype :	int ft_strcmp(const char *s1, const char *s2)
; Registers :	rdi rsi
; Description :	compare string and return 0 if equal, -1 if s1 < s2 or 1 if s1 > s2

global		_ft_strcmp

section		.text

_ft_strcmp:
	xor		rax, rax
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
	jl		.lesser
	jg		.greater
	ret
.greater:
	dec		rax
	ret
.lesser:
	inc		rax
	ret
