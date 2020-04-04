global		_main

extern		_ft_atoi_base
extern		_printf

default		rel

section		.data
.input1: db	"10010",0
.base1: db	"01",0
.input2: db	"  -123yx",0
.base2: db	"0123456789",0
.print: db	"%i",10,0

section		.text

_main:
.test1:
	sub		rsp, 0x08
	lea		rdi, [.input1]
	lea		rsi, [.base1]
	call	_ft_atoi_base
	lea		rdi, [.print]
	mov		rsi, rax
	call	_printf
	add		rsp, 0x08
.test2:
	sub		rsp, 0x08
	lea		rdi, [.input2]
	lea		rsi, [.base2]
	call	_ft_atoi_base
	lea		rdi, [.print]
	mov		rsi, rax
	call	_printf
	add		rsp, 0x08
	xor		rax, rax
	ret
