; Prototype :	ssize_t ft_write(int fd, const void *buf, size_t n)
; Registers :	none
; Description :	call the write syscall

global		_ft_write

section		.text

_ft_write:
	mov		rax, 0x2000004
	syscall
	ret
