.text
	.align 4
	.globl procesar
	.type	procesar, @function
procesar:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi

# Aqui has de introducir el codigo
	movl 8(%ebp),%eax
	movl 12(%ebp),%esi
	movl 16(%ebp),%edi
	movl 20(%ebp),%ebx
	imul %ebx,%ebx
	addl %eax,%ebx
for: 	
	cmp %ebx,%eax
	jge end_for
	movb (%eax),%cl
	sub (%esi),%cl
if:	cmpb $0,%cl
	je end_if
	movb $255,%cl
end_if:	
	movb %cl,(%edi)
	incl %eax
	incl %esi
	incl %edi
	jmp for
end_for:

# El final de la rutina ya esta programado

	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
