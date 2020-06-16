; Prototype :	ssize_t ft_write(int fd, const void *buf, size_t n)
; Registers :	none
; Description :	call the write syscall

global		ft_write

section		.text

ft_write:
	mov		rax, 0x0000001
	syscall
	ret
