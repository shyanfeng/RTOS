  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

.global  taskSwitch
.global  SysTick_Handler
 
 .extern taskOneStack
 .extern taskTwoStack
 .extern mainTcb
 .extern readyQueue
 .extern runningQueue
 
  .section  .text.taskSwitch
  .type  taskSwitch, %function
taskSwitch:

 /*ldr	r0, =#0x11111111
 ldr	r1, =#0x22222222
 ldr	r2, =#0x33333333
 ldr	r3, =#0x44444444
 ldr	r4, =#0x55555555
 ldr	r5, =#0x66666666
 ldr	r6, =#0x77777777
 ldr	r7, =#0x88888888
 ldr	r8, =#0x99999999
 ldr	r9, =#0xaaaaaaaa
 ldr	r10, =#0xbbbbbbbb
 ldr	r11, =#0xcccccccc
 ldr	r12, =#0xdddddddd
 ldr	lr, =#0xeeeeeeee
 push	{r0}
 b		.
 */
 /*
 movs	r0, #0x11
 movs	r1, #0x22
 movs	r2, #0x33
 movs	r3, #0x44
 movs	r12, #0x55
 movs	lr, #0x66
 b		.
*/

 .align 8
 .type	SysTick_Handler, %function
SysTick_Handler:
 push	{r4-r11}			// Push all neccessary register

 ldr	r0, = runningQueue	// Load mainTcb address into r0
 ldr	r1, [r0]			// Deref r0 and load mainTcb.name address into r1
 ldr	r2, [r1, #4]		// Deref (r1+4) and load mainTcb.sp value into r2
 str	sp, [r1, #4]		// Deref (r1+4) and store mainTcb.sp value into sp

 ldr	r0, = readyQueue	// Load taskOneTcb into r0
 ldr	r1, [r0]			// Deref r0 and load taskOneTcb address into r1
 ldr	r2, [r1, #4]		// Deref (address of sp) and load into r2
 ldr	sp, [r1, #4]

 pop	{r4-r11}
 pop	{r0-r3}
 pop	{r12}
 bx		lr
 //pop	{pc}
 /*
 ldr    r4, [r2, #0]
 ldr    r5, [r2, #4]
 ldr    r6, [r2, #8]
 ldr    r7, [r2, #12]
 ldr    r8, [r2, #16]
 ldr    r9, [r2, #20]
 ldr    r10, [r2, #24]
 ldr    r11, [r2, #28]
 ldr	pc, [r2, #56]
 bx		lr
 */
 /*push 	{r7, lr}
 add	r7, sp, #0
 bl  	HAL_IncTick
 pop 	{r7, pc}*/

