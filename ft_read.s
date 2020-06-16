; Prototype :	ssize_t ft_read(int fd, void *buf, size_t n)
; Registers :	none
; Description :	call the read syscall

global		ft_read

section		.text

ft_read:
	mov		rax, 0x0000000
	syscall
	ret
