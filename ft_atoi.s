; Prototype :	int ft_atoi(const char *str)
; Registers :	rdi rsi rdx rcx
; Description :	convert input string to signed integer
; 				escape all whitespaces before the sign or digits
; 				accept one sign char +/- before digits
; 				stop conversion when char is not anymore a digit

global		ft_atoi

section		.text

ft_atoi:
	mov		rcx, 0x0a
	xor		rax, rax
	xor		rsi, rsi
	jmp		.is_space
.skip_space:
	inc		rdi
	cmp		byte [rdi], 0x00
	jz		.return
.is_space:
	cmp		byte [rdi], 0x20
	jz		.skip_space
	cmp 	byte [rdi], 0x09
	jb		.neg_sign
	cmp		byte [rdi], 0x0e
	jb		.skip_space
.neg_sign:
	cmp		byte [rdi], 0x2d
	jnz		.skip_sign
	inc		rsi
	jmp		.inc_ptr
.skip_sign:
	cmp		byte [rdi], 0x2b
	jnz		.is_digit
.inc_ptr:
	inc		rdi
.is_digit:
	cmp		byte [rdi], 0x30
	jb		.sign
	cmp		byte [rdi], 0x39
	ja		.sign
.convert:
	mul		rcx
	movzx	rdx, byte [rdi]
	add		rax, rdx
	sub		rax, 0x30
	jmp		.inc_ptr
.sign:
	test	rsi, rsi
	jz		.return
	neg		rax
.return:
	ret
