#ifndef __ASM_OFFSETS_H__
#define __ASM_OFFSETS_H__
/*
 * DO NOT MODIFY.
 *
 * This file was generated by Kbuild
 */


#define KVM_STEAL_TIME_preempted 16 /* offsetof(struct kvm_steal_time, preempted) */

#define pt_regs_bx 40 /* offsetof(struct pt_regs, bx) */
#define pt_regs_cx 88 /* offsetof(struct pt_regs, cx) */
#define pt_regs_dx 96 /* offsetof(struct pt_regs, dx) */
#define pt_regs_sp 152 /* offsetof(struct pt_regs, sp) */
#define pt_regs_bp 32 /* offsetof(struct pt_regs, bp) */
#define pt_regs_si 104 /* offsetof(struct pt_regs, si) */
#define pt_regs_di 112 /* offsetof(struct pt_regs, di) */
#define pt_regs_r8 72 /* offsetof(struct pt_regs, r8) */
#define pt_regs_r9 64 /* offsetof(struct pt_regs, r9) */
#define pt_regs_r10 56 /* offsetof(struct pt_regs, r10) */
#define pt_regs_r11 48 /* offsetof(struct pt_regs, r11) */
#define pt_regs_r12 24 /* offsetof(struct pt_regs, r12) */
#define pt_regs_r13 16 /* offsetof(struct pt_regs, r13) */
#define pt_regs_r14 8 /* offsetof(struct pt_regs, r14) */
#define pt_regs_r15 0 /* offsetof(struct pt_regs, r15) */
#define pt_regs_flags 144 /* offsetof(struct pt_regs, flags) */

#define saved_context_cr0 200 /* offsetof(struct saved_context, cr0) */
#define saved_context_cr2 208 /* offsetof(struct saved_context, cr2) */
#define saved_context_cr3 216 /* offsetof(struct saved_context, cr3) */
#define saved_context_cr4 224 /* offsetof(struct saved_context, cr4) */
#define saved_context_gdt_desc 266 /* offsetof(struct saved_context, gdt_desc) */



#define TASK_threadsp 1688 /* offsetof(struct task_struct, thread.sp) */

#define pbe_address 0 /* offsetof(struct pbe, address) */
#define pbe_orig_address 8 /* offsetof(struct pbe, orig_address) */
#define pbe_next 16 /* offsetof(struct pbe, next) */

#define TDX_MODULE_rcx 0 /* offsetof(struct tdx_module_output, rcx) */
#define TDX_MODULE_rdx 8 /* offsetof(struct tdx_module_output, rdx) */
#define TDX_MODULE_r8 16 /* offsetof(struct tdx_module_output, r8) */
#define TDX_MODULE_r9 24 /* offsetof(struct tdx_module_output, r9) */
#define TDX_MODULE_r10 32 /* offsetof(struct tdx_module_output, r10) */
#define TDX_MODULE_r11 40 /* offsetof(struct tdx_module_output, r11) */

#define TDX_HYPERCALL_r10 0 /* offsetof(struct tdx_hypercall_args, r10) */
#define TDX_HYPERCALL_r11 8 /* offsetof(struct tdx_hypercall_args, r11) */
#define TDX_HYPERCALL_r12 16 /* offsetof(struct tdx_hypercall_args, r12) */
#define TDX_HYPERCALL_r13 24 /* offsetof(struct tdx_hypercall_args, r13) */
#define TDX_HYPERCALL_r14 32 /* offsetof(struct tdx_hypercall_args, r14) */
#define TDX_HYPERCALL_r15 40 /* offsetof(struct tdx_hypercall_args, r15) */

#define BP_scratch 484 /* offsetof(struct boot_params, scratch) */
#define BP_secure_boot 492 /* offsetof(struct boot_params, secure_boot) */
#define BP_loadflags 529 /* offsetof(struct boot_params, hdr.loadflags) */
#define BP_hardware_subarch 572 /* offsetof(struct boot_params, hdr.hardware_subarch) */
#define BP_version 518 /* offsetof(struct boot_params, hdr.version) */
#define BP_kernel_alignment 560 /* offsetof(struct boot_params, hdr.kernel_alignment) */
#define BP_init_size 608 /* offsetof(struct boot_params, hdr.init_size) */
#define BP_pref_address 600 /* offsetof(struct boot_params, hdr.pref_address) */

#define PTREGS_SIZE 168 /* sizeof(struct pt_regs) */
#define TLB_STATE_user_pcid_flush_mask 22 /* offsetof(struct tlb_state, user_pcid_flush_mask) */
#define CPU_ENTRY_AREA_entry_stack 4096 /* offsetof(struct cpu_entry_area, entry_stack_page) */
#define SIZEOF_entry_stack 4096 /* sizeof(struct entry_stack) */
#define MASK_entry_stack -4096 /* (~(sizeof(struct entry_stack) - 1)) */
#define TSS_sp0 4 /* offsetof(struct tss_struct, x86_tss.sp0) */
#define TSS_sp1 12 /* offsetof(struct tss_struct, x86_tss.sp1) */
#define TSS_sp2 20 /* offsetof(struct tss_struct, x86_tss.sp2) */

#endif
