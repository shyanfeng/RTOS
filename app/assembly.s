  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

.global  testFunc
.extern dummy

  .section  .text.testFunc
  .type  testFunc, %function
testFunc:/*
 movs	r0, #0x12
 movs	r1, #0x14
 movs	r2, #0x24
 ldr	r3, =#0x1234face
 movw.w r4, 0x1234
 movt.w r4, 0xface
 push	{r0}
 push   {r1}
 push	{r2}
 push	{r0,r1}
 push	{r1,r0}
 pop	{r0}
 pop	{r0,r1}
 pop	{r0}
 pop    {r1,r0}
 stmdb sp!,{r0,r1,r2}
 ldmia sp!,{r0,r1,r2}
 push	{lr}
 movs	r0, #12
 bl		dummy
 pop	{lr}
 bx		lr
*/
