; Prototype :	int ft_atoi_base(const char *str, const char *base)
; Registers :	rdi rsi rdx rcx r8 r9 r10 r11 r12
; Description :	convert input string to signed integer with set base
; 				escape all whitespaces before the sign or set base chars
; 				accept one sign char +/- before set base chars
; 				stop conversion when char is not anymore in set base

global		_ft_atoi_base

extern		_ft_strlen
extern		_ft_checkdup
extern		_ft_checkset
extern		_ft_skipset
extern		_ft_setindex

default		rel

section		.data
; invalid chars set to check in base str
.inv: db	0x09,0x0a,0x0b,0x0c,0x0d,0x20,0x2b,0x2d,0x00
; whitespace chars set to skip
.spc: db	0x09,0x0a,0x0b,0x0c,0x0d,0x20,0x00

section		.text

; r8 r9 r10 r11 r12 -> temporary parameters registers savers
_ft_atoi_base:
	mov		r8, rdi			; input ptr saver
	mov		r9, rsi			; base ptr saver
	mov		rdi, r9
	call	_ft_strlen		; rdi rcx
	cmp		rax, 0x01
	jbe		.error
	mov		rdx, rax		; base
.check_invalid:
	mov		rdi, r9
	lea		rsi, [.inv]
	call	_ft_checkset	; rdi rsi rcx
	test	rax, rax
	jnz		.error
.check_dup:
	mov		rdi, r9
	call	_ft_checkdup	; rdi rsi
	test	rax, rax
	jnz		.error
.skip_spaces:
	mov		rdi, r8
	lea		rsi, [.spc]
	call	_ft_skipset		; rdi rsi rcx
	push	r12				; callee-saved register
	xor		r10, r10		; neg
	xor		rax, rax
.neg_sign:
	cmp		byte [rdi], 0x2d ; '-'
	jnz		.skip_sign
	inc		r10
	jmp		.inc_ptr
.skip_sign:
	cmp		byte [rdi], 0x2b ; '+'
	jnz		.base_index
.inc_ptr:
	inc		rdi
.base_index:
	mov		r8, rdi
	mov		r11, rax
	mov		rdi, r9
	mov		sil, byte [r8]
	call	_ft_setindex	; rdi rsi rcx
	cmp		rax, -1
	je		.sign
	mov		r12, rax
	mov		rax, r11
	mov		rdi, r8
.convert:
	mov		r11, rdx
	mul		rdx
	mov		rdx, r11
	add		rax, r12
	jmp		.inc_ptr
.sign:
	mov		rax, r11
	test	r10, r10
	jz		.return
	neg		rax
.return:
	pop		r12
	ret
.error:
	xor		rax, rax
	ret
