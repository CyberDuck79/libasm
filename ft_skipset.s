; Prototype :	char *ft_skipset(const char *str, const char *set)
; Registers :	rdi rsi rcx
; Description :	return ptr to the next char of the input str who is not in the set

global		ft_skipset

section		.text

ft_skipset:
	cld
	mov		rcx, rsi
	jmp		.compare
.reset_continue:
	inc		rdi
	mov		rsi, rcx
.compare:
	lodsb
	test	al, al
	jz		.return
	cmp		byte [rdi], al
	jne		.compare
	jmp		.reset_continue
.return:
	mov		rax, rdi
	ret
