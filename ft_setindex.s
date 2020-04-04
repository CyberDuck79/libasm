; Prototype :	ssize_t ft_setindex(const char *str, const char c)
; Registers :	rdi rsi rcx
; Description :	return index of a char in a set, -1 if not present in set

global		_ft_setindex

section		.text

_ft_setindex:
	cld
	xor		rcx, rcx
	test	sil, sil
	jz		.not_found
	not		rcx
	xor		al, al
	repne	scasb
	not		rcx
	lea		rcx, [rcx+2]
	std
	mov		al, sil
	repne	scasb
	cmp		sil, byte [rdi]
	jne		.not_found
	mov		rax, rcx
	ret
.not_found:
	dec		rcx
	mov		rax, rcx
	ret
