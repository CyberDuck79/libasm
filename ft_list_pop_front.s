; Prototype : void *ft_list_pop_front(t_list **begin_list)
; Registers : rdi rsi rdx rcx r8 r9 r10 r11
; Description : return the first node and remove it from the list

global		_ft_list_pop_front

extern		_free

section		.text

_ft_list_pop_front:
	mov		rax, [rdi]
	mov		rsi, [rax+8]
	mov		[rdi], rsi
	mov		rsi, rax
	mov		rax, [rsi]
	push	rdi
	push	rax
	sub		rsp, 0x08
	mov		rdi, rsi
	call	_free
	add		rsp, 0x08
	pop		rax
	pop		rdi
	ret
