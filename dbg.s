
; lldb doesn't support asm debug from c file
; this main asm programm is only for 

global		_main

extern		_to_test_function
extern		_printf

default		rel ; load for 64 bits mac os - no PIE warning

section		.data
.input: db	"test",10,0
.print: db	"%i",10,0

section		.text

_main:
	; load for 64 bits mac os - no PIE warning
	lea		rdi, [.input] 
	call	_to_test_function
	; load for 64 bits mac os - no PIE warning
	lea		rdi, [.print]
	mov		rsi, rax
	; align stack for function who use MMX
	sub		rsp, 0x08
	call	_printf
	add		rsp, 0x08
	xor		rax, rax
	ret
