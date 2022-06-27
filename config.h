#define CONFIG_KERNFS 1
#define CONFIG_SYSCTL 1
#define CONFIG_PCI_DIRECT 1
#define CONFIG_SYSFS 1
#define CONFIG_PROC_PID_ARCH_STATUS 1
#define CONFIG_PROC_PAGE_MONITOR 1
#define CONFIG_PROC_SYSCTL 1
#define CONFIG_PROC_FS 1
#define CONFIG_FILE_LOCKING 1
#define CONFIG_IO_WQ 1
#define CONFIG_ARCH_HAS_COPY_MC 1
#define CONFIG_ARCH_HAS_UACCESS_FLUSHCACHE 1
#define CONFIG_ARCH_HAS_PMEM_API 1
#define CONFIG_ARCH_STACKWALK 1
#define CONFIG_STACK_HASH_ORDER 20
#define CONFIG_COREDUMP 1
#define CONFIG_BLOCK 1
#define CONFIG_KERNEL_GZIP 1
#define CONFIG_SG_POOL 1
#define CONFIG_OUTPUT_FORMAT "elf64-x86-64"
#define CONFIG_CPUMASK_OFFSTACK 1
#define CONFIG_GENERIC_IOMAP 1
#define CONFIG_GENERIC_PCI_IOMAP 1
#define CONFIG_HAS_IOPORT_MAP 1
#define CONFIG_HAS_IOMEM 1
#define CONFIG_GENERIC_STRNLEN_USER 1
#define CONFIG_GENERIC_STRNCPY_FROM_USER 1
#define CONFIG_BINARY_PRINTF 1
#define CONFIG_CHECK_SIGNATURE 1
#define CONFIG_SGL_ALLOC 1
#define CONFIG_CRC32_SLICEBY8 1
#define CONFIG_GENERIC_GETTIMEOFDAY 1
#define CONFIG_SWIOTLB 1
#define CONFIG_NEED_DMA_MAP_STATE 1
#define CONFIG_NEED_SG_DMA_LENGTH 1
#define CONFIG_HAS_DMA 1
#define CONFIG_DEBUG_BUGVERBOSE 1 
#define CONFIG_DEBUG_MEMORY_INIT 1 
#define CONFIG_HARDLOCKUP_CHECK_TIMESTAMP 1
#define CONFIG_PRINTK_TIME 1
#define CONFIG_STACKTRACE 1
#define CONFIG_HAVE_EBPF_JIT 1
#define CONFIG_ARCH_DMA_ADDR_T_64BIT 1
#define CONFIG_ARCH_USE_CMPXCHG_LOCKREF 1
#define CONFIG_ARCH_HAS_FAST_MULTIPLIER 1
#define CONFIG_ARCH_USE_SYM_ANNOTATIONS 1
#define CONFIG_SRCU 1
#define CONFIG_CRYPTO_HASH 1
#define CONFIG_HAVE_HARDENED_USERCOPY_ALLOCATOR 1
#define CONFIG_DEFAULT_TCP_CONG "cubic"
#define CONFIG_AF_UNIX_OOB 1
#define CONFIG_UNIX 1
#define CONFIG_NET_FLOW_LIMIT 1
#define CONFIG_NET_RX_BUSY_POLL 1
#define CONFIG_RFS_ACCEL 1
#define CONFIG_INET 1
#define CONFIG_SERIAL_8250_RUNTIME_UARTS 4
#define CONFIG_SERIAL_8250_NR_UARTS 4
#define CONFIG_SERIAL_8250_CONSOLE 1
#define CONFIG_SERIAL_EARLYCON 1
#define CONFIG_VT_HW_CONSOLE_BINDING 1
#define CONFIG_UNIX98_PTYS 1
#define CONFIG_HW_CONSOLE 1
#define CONFIG_VT_CONSOLE_SLEEP 1
#define CONFIG_CONSOLE_TRANSLATIONS 1
#define CONFIG_VT_CONSOLE 1
#define CONFIG_NET 1
#define CONFIG_SERIAL_CORE_CONSOLE 1
#define CONFIG_CLKEVT_I8253 1
#define CONFIG_CLKSRC_I8253 1
#define CONFIG_CONSOLE_LOGLEVEL_QUIET 4
#define CONFIG_MESSAGE_LOGLEVEL_DEFAULT 4
#define CONFIG_CONSOLE_LOGLEVEL_DEFAULT 7
#define CONFIG_RCU_CPU_STALL_TIMEOUT 21
#define CONFIG_RCU_EXP_CPU_STALL_TIMEOUT 0
#define CONFIG_HAVE_SYSCALL_TRACEPOINTS 1
#define CONFIG_PANIC_ON_OOPS_VALUE 0
#define CONFIG_PANIC_TIMEOUT 0
#define CONFIG_IO_DELAY_0X80 1
#define CONFIG_UNWINDER_ORC 1
#define CONFIG_PCIEASPM 1
#define CONFIG_VGA_ARB_MAX_GPUS 16
#define CONFIG_VGA_ARB 1
#define CONFIG_PCI_QUIRKS 1
#define CONFIG_PCI_DOMAINS 1
#define CONFIG_PCI 1
#define CONFIG_DMI_SCAN_MACHINE_NON_EFI_FALLBACK 1
#define CONFIG_FIRMWARE_MEMMAP 1
#define CONFIG_VIRTIO_PCI_LEGACY 1
#define CONFIG_GENERIC_CPU_AUTOPROBE 1
#define CONFIG_DEVTMPFS_MOUNT 1
#define CONFIG_DEVTMPFS 1
#define CONFIG_AS_TPAUSE 1
#define CONFIG_RCU_STALL_COMMON 1
#define CONFIG_TREE_SRCU 1
#define CONFIG_SRCU 1
#define CONFIG_TREE_RCU 1
#define CONFIG_SPARSE_IRQ 1
#define CONFIG_IRQ_FORCED_THREADING 1
#define CONFIG_GENERIC_IRQ_RESERVATION_MODE 1
#define CONFIG_GENERIC_IRQ_MATRIX_ALLOCATOR 1
#define CONFIG_IRQ_DOMAIN_HIERARCHY 1
#define CONFIG_IRQ_DOMAIN 1
#define CONFIG_HARDIRQS_SW_RESEND 1
#define CONFIG_GENERIC_IRQ_MIGRATION 1
#define CONFIG_GENERIC_PENDING_IRQ 1
#define CONFIG_GENERIC_IRQ_EFFECTIVE_AFF_MASK 1
#define CONFIG_GENERIC_IRQ_SHOW 1
#define CONFIG_GENERIC_IRQ_PROBE 1
#define CONFIG_SCHED_HRTICK 1
#define CONFIG_HZ 1000
#define CONFIG_HIGH_RES_TIMERS 1
#define CONFIG_CONTEXT_TRACKING 1
#define CONFIG_NO_HZ_FULL 1
#define CONFIG_NO_HZ_COMMON 1
#define CONFIG_TICK_ONESHOT 1
#define CONFIG_GENERIC_CLOCKEVENTS 1
#define CONFIG_GENERIC_CLOCKEVENTS_MIN_ADJUST 1
#define CONFIG_GENERIC_CLOCKEVENTS_BROADCAST 1
#define CONFIG_GENERIC_CMOS_UPDATE 1
#define CONFIG_POSIX_CPU_TIMERS_TASK_WORK 1
#define CONFIG_GENERIC_TIME_VSYSCALL 1
#define CONFIG_CLOCKSOURCE_WATCHDOG_MAX_SKEW_US 1000
#define CONFIG_CLOCKSOURCE_VALIDATE_LAST_CYCLE 1
#define CONFIG_CLOCKSOURCE_WATCHDOG 1
#define CONFIG_ARCH_CLOCKSOURCE_INIT 1
#define CONFIG_QUEUED_SPINLOCKS 1
#define CONFIG_RWSEM_SPIN_ON_OWNER 1
#define CONFIG_MUTEX_SPIN_ON_OWNER 1
#define CONFIG_INLINE_WRITE_UNLOCK_IRQ 1
#define CONFIG_INLINE_WRITE_UNLOCK 1
#define CONFIG_INLINE_READ_UNLOCK_IRQ 1
#define CONFIG_INLINE_READ_UNLOCK 1
#define CONFIG_INLINE_SPIN_UNLOCK_IRQ 1
#define CONFIG_DYNAMIC_SIGFRAME 1
#define CONFIG_PREEMPT 1
#define CONFIG_SECRETMEM 1
#define CONFIG_ARCH_HAS_PTE_SPECIAL 1
#define CONFIG_VM_EVENT_COUNTERS 1
#define CONFIG_ZONE_DMA32 1
#define CONFIG_ZONE_DMA 1
#define CONFIG_ARCH_HAS_PTE_DEVMAP 1
#define CONFIG_ARCH_HAS_VM_GET_PAGE_PROT 1
#define CONFIG_ARCH_HAS_CACHE_LINE_SIZE 1
#define CONFIG_GENERIC_EARLY_IOREMAP 1
#define CONFIG_HAVE_SETUP_PER_CPU_AREA 1
#define CONFIG_NEED_PER_CPU_PAGE_FIRST_CHUNK 1
#define CONFIG_NEED_PER_CPU_EMBED_FIRST_CHUNK 1
#define CONFIG_DEFAULT_MMAP_MIN_ADDR 4096
#define CONFIG_VIRT_TO_BUS 1
#define CONFIG_PHYS_ADDR_T_64BIT 1
#define CONFIG_ARCH_ENABLE_SPLIT_PMD_PTLOCK 1
#define CONFIG_SPLIT_PTLOCK_CPUS 4
#define CONFIG_SPARSEMEM_EXTREME 1
#define CONFIG_SPARSEMEM 1
#define CONFIG_ARCH_HAS_PARANOID_L1D_FLUSH 1
#define CONFIG_ARCH_SUPPORTS_DEBUG_PAGEALLOC 1
#define CONFIG_HAVE_PREEMPT_DYNAMIC_CALL 1
#define CONFIG_HAVE_STATIC_CALL_INLINE 1
#define CONFIG_HAVE_STATIC_CALL 1
#define CONFIG_ARCH_HAS_MEM_ENCRYPT 1
#define CONFIG_HAVE_ARCH_PREL32_RELOCATIONS 1
#define CONFIG_STRICT_KERNEL_RWX 1
#define CONFIG_ARCH_HAS_STRICT_KERNEL_RWX 1
#define CONFIG_RANDOMIZE_KSTACK_OFFSET 1
#define CONFIG_ARCH_MMAP_RND_BITS 28
#define CONFIG_ARCH_MMAP_RND_BITS_MAX 32
#define CONFIG_ARCH_MMAP_RND_BITS_MIN 28
#define CONFIG_HAVE_EXIT_THREAD 1
#define CONFIG_HAVE_ARCH_MMAP_RND_BITS 1
#define CONFIG_ARCH_HAS_ELF_RANDOMIZE 1
#define CONFIG_PGTABLE_LEVELS 4
#define CONFIG_HAVE_IRQ_EXIT_ON_IRQ_STACK 1
#define CONFIG_MODULES_USE_ELF_RELA 1
#define CONFIG_SLUB 1
#define CONFIG_X86_VMX_FEATURE_NAMES 1
#define CONFIG_CONFIG_IA32_FEAT_CTL 1
#define CONFIG_X86_DEBUGCTLMSR 1
#define CONFIG_X86_MINIMUM_CPU_FAMILY 64
#define CONFIG_X86_CMOV 1
#define CONFIG_X86_CMPXCHG64 1
#define CONFIG_X86_TSC 1
#define CONFIG_X86_L1_CACHE_SHIFT 6
#define CONFIG_X86_INTERNODE_CACHE_SHIFT 6
#define CONFIG_CPU_SUP_AMD 1
#define CONFIG_RPS 1
#define CONFIG_FW_LOADER 1
#define GENERIC_CPU_VULNERABILITIES 1
#define CONFIG_VGA_CONSOLE 1
#define CONFIG_RANDOM_TRUST_CPU 1
#define CONFIG_BPF 1
#define CONFIG_EARLY_PRINTK 1
#define CONFIG_DUMMY_CONSOLE_ROWS 25
#define CONFIG_DUMMY_CONSOLE_COLUMNS 80
#define CONFIG_DUMMY_CONSOLE 1
#define CONFIG_HAVE_CONTEXT_TRACKING_OFFSTACK 1
#define CONFIG_HAVE_CONTEXT_TRACKING 1
#define CONFIG_HAVE_ARCH_WITHIN_STACK_FRAMES 1
#define CONFIG_HAVE_ARCH_SECCOMP_FILTER 1
#define CONFIG_HAVE_CMPXCHG_DOUBLE 1
#define CONFIG_HAVE_CMPXCHG_LOCAL 1
#define CONFIG_HAVE_ARCH_JUMP_LABEL_RELATIVE 1
#define CONFIG_HAVE_PERF_USER_STACK_DUMP 1
#define CONFIG_HAVE_PERF_REGS 1
#define CONFIG_HAVE_MIXED_BREAKPOINTS_REGS 1
#define CONFIG_HAVE_HW_BREAKPOINT 1
#define CONFIG_ARCH_WANTS_DYNAMIC_TASK_STRUCT 1
#define CONFIG_HAVE_ARCH_THREAD_STRUCT_WHITELIST 1
#define CONFIG_ARCH_HAS_SET_DIRECT_MAP 1
#define CONFIG_ARCH_HAS_SET_MEMORY 1
#define CONFIG_GENERIC_SMP_IDLE_THREAD 1
#define CONFIG_HAVE_ARCH_TRACEHOOK 1
#define CONFIG_TRACE_IRQFLAGS_SUPPORT 1
#define CONFIG_HAVE_NMI 1
#define CONFIG_HAVE_IOREMAP_PROT 1
#define CONFIG_ARCH_USE_BUILTIN_BSWAP 1
#define CONFIG_HAVE_EFFICIENT_UNALIGNED_ACCESS 1
#define CONFIG_GENERIC_ENTRY 1
#define CONFIG_HOTPLUG_SMT 1
#define CONFIG_NR_CPUS_RANGE_BEGIN 2
#define CONFIG_NR_CPUS_RANGE_END 512
#define CONFIG_NR_CPUS_DEFAULT 64
#define CONFIG_NR_CPUS 64
#define CONFIG_ARCH_MHP_MEMMAP_ON_MEMORY_ENABLE 1
#define CONFIG_ARCH_RANDOM 1
#define CONFIG_ARCH_SPARSEMEM_DEFAULT 1
#define CONFIG_ARCH_SPARSEMEM_ENABLE 1
#define CONFIG_ARCH_USES_PG_UNCACHED 1
#define CONFIG_CC_HAS_IBT 1
#define CONFIG_PHYSICAL_ALIGN 0x200000
#define CONFIG_PHYSICAL_START 0x1000000
#define CONFIG_LEGACY_VSYSCALL_NONE 1
#define CONFIG_PARAVIRT_CLOCK 1
#define CONFIG_MMU_GATHER_RCU_TABLE_FREE 1
#define CONFIG_ARCH_CPUIDLE_HALTPOLL 1
#define CONFIG_DMI 1
#define CONFIG_KVM_GUEST 1
#define CONFIG_PARAVIRT 1
#define CONFIG_MMU_GATHER_TABLE_FREE 1
#define CONFIG_HYPERVISOR_GUEST 1
#define CONFIG_X86_HV_CALLBACK_VECTOR 1
#define CONFIG_HOTPLUG_CPU 1
#define CONFIG_HPET_TIMER 1
#define CONFIG_ISA_DMA_API 1
#define CONFIG_MODIFY_LDT_SYSCALL 1
#define CONFIG_MTRR 1
#define CONFIG_SCHED_SMT 1
#define CONFIG_X86_16BIT 1
#define CONFIG_X86_DIRECT_GBPAGES 1
#define CONFIG_X86_ESPFIX64 1
#define CONFIG_X86_IO_APIC 1
#define CONFIG_X86_LOCAL_APIC 1
#define CONFIG_X86_PAT 1
#define CONFIG_X86_UMIP 1
#define CONFIG_X86_VSYSCALL_EMULATION 1
#define CONFIG_VT 1
#define CONFIG_HAVE_IRQ_TIME_ACCOUNTING 1
#define CONFIG_TTY 1
#define CONFIG_NLATTR 1
#define CONFIG_GENERIC_NET_UTILS 1
#define CONFIG_HAVE_MOD_ARCH_SPECIFIC 1
#define CONFIG_HAVE_ARCH_SOFT_DIRTY 1
#define CONFIG_HAVE_ARCH_HUGE_VMALLOC 1
#define CONFIG_HAVE_ARCH_HUGE_VMAP 1
#define CONFIG_HAVE_ARCH_TRANSPARENT_HUGEPAGE_PUD 1
#define CONFIG_HAVE_ARCH_TRANSPARENT_HUGEPAGE 1
#define CONFIG_HAVE_MOVE_PMD 1
#define CONFIG_HAVE_MOVE_PUD 1
#define CONFIG_64BIT 1
#define CONFIG_ARCH_HAS_CPU_RELAX 1
#define CONFIG_ARCH_HIBERNATION_POSSIBLE 1
#define CONFIG_ARCH_MAY_HAVE_PC_FDC 1
#define CONFIG_ARCH_SUPPORTS_UPROBES 1
#define CONFIG_ARCH_SUSPEND_POSSIBLE 1
#define CONFIG_AUDIT_ARCH 1
#define CONFIG_CC_HAS_SLS 1
#define CONFIG_FIX_EARLYCON_MEM 1
#define CONFIG_GENERIC_BUG_RELATIVE_POINTERS 1
#define CONFIG_GENERIC_BUG 1
#define CONFIG_GENERIC_CALIBRATE_DELAY 1
#define CONFIG_GENERIC_ISA_DMA 1
#define CONFIG_INSTRUCTION_DECODER 1
#define CONFIG_LOCKDEP_SUPPORT 1
#define CONFIG_MMU 1
#define CONFIG_THREAD_INFO_IN_TASK 1
#define CONFIG_SMP 1
#define CONFIG_LOG_CPU_MAX_BUF_SHIFT 1
#define CONFIG_ARCH_WANT_BATCHED_UNMAP_TLB_FLUSH 1
#define CONFIG_STACKTRACE_SUPPORT 1
#define CONFIG_X86_64_SMP 1
#define CONFIG_ARCH_HAS_SYSCALL_WRAPPER 1
#define CONFIG_PERF_EVENTS 1
#define CONFIG_HAVE_UNSTABLE_SCHED_CLOCK 1
#define CONFIG_ARCH_HAS_SYNC_CORE_BEFORE_USERMODE 1
#define CONFIG_X86_64 1
#define CONFIG_X86_FEATURE_NAMES 1
#define CONFIG_X86_MPPARSE 1
#define CONFIG_X86 1
