.data
	.align 16
	zeros: .byte 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

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
	movdqa (%eax),%xmm0
	movdqa (%esi),%xmm1
	psubb %xmm1,%xmm0
	movdqa (zeros),%xmm1
	pcmpgtb %xmm1,%xmm0
	movdqa %xmm0,(%edi)
	addl $16,%eax
	addl $16,%esi
	addl $16,%edi
	jmp for
end_for:


# El final de la rutina ya esta programado

	emms	# Instruccion necesaria si os equivocais y usais MMX
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
