global		_main

extern		_ft_new_list
extern		_printf

default		rel

section		.data
.input1: db	"test",0
.print1: db	"ft_new_list",10,0
.print2: db	"list : %p %s",10,0

section		.text

_main:
.test1:
	sub		rsp, 0x08
	lea		rdi, [.input1]
	call	_ft_new_list
	push	rax
	lea		rdi, [.print1]
	sub		rsp, 0x08
	call	_printf
	add		rsp, 0x08
	lea		rdi, [.print2]
	pop		rsi
	mov		rdx, [rsi]
	call	_printf
	add		rsp, 0x08
	xor		rax, rax
	ret
