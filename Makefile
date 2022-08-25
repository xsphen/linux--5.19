MAKEFLAGS := -rR --no-print-directory
CC := gcc

ifeq ("$(origin V)", "command line")
	Q :=
else
	Q := @
endif

$(shell bash -c "mkdir -p \
	      build/{include,mm,block/partitions,init,security,lib/{math,crypto},fs/{iomap,nls,proc,ext2,ramfs,exportfs}} \
	      build/arch/x86/{include,entry/vdso,kernel/{cpu,fpu,apic},mm/pat,events,pci,kvm,lib,boot/compressed} \
	      build/drivers/{base/{power,firmware_loader/builtin},pci/{pcie,msi},clocksource,virtio,char,net,rtc,block,tty/hvc,platform/x86} \
	      build/net/{ipv6,ethernet,ethtool,sched,unix,netlink,core} \
	      build/kernel/{events,sched,entry,bpf,locking,futex,power,printk,dma,irq,rcu,time}")

all: build/arch/x86/boot/bzImage

clean:
	rm -rf build arch/x86/boot/compressed/piggy.S

include = -nostdinc -Iinclude -Iinclude/uapi -Iarch/x86/include -Iarch/x86/include/uapi -I $(subst build/,,$(dir $@)) -I $(dir $@) \
		-Iinclude/generated/uapi -Iarch/x86/include/generated -Iarch/x86/include/generated/uapi \
		-include include/linux/kconfig.h -include include/linux/compiler_types.h -include include/linux/compiler-version.h

CFLAGS := -D__KERNEL__ -fshort-wchar -O1 -mcmodel=kernel -mno-sse -mno-red-zone -fno-stack-protector -fno-PIE \
		-Wno-format-security -Wno-format-truncation -Wno-address-of-packed-member -Wno-pointer-sign \
		-Wno-unused-but-set-variable -Wno-stringop-overflow -Wno-maybe-uninitialized

basetarget = $(subst -,_,$(basename $(notdir $@)))
vmlinux_cflags = $(CFLAGS) $(CFLAGS_$(basename $@).o) -DKBUILD_MODFILE='"$(basename $@)"' -DKBUILD_BASENAME='"$(basetarget)"' \
			-DKBUILD_MODNAME='"$(basetarget)"' -D__KBUILD_MODNAME=kmod_$(basetarget)

x86	:= $(addprefix arch/x86/, \
		$(addprefix entry/, entry_64.o thunk_64.o syscall_64.o common.o \
		$(addprefix vdso/, vma.o extable.o vdso-image-64.o)) \
		$(addprefix lib/, msr.o msr-reg.o msr-reg-export.o hweight.o iomem.o iomap_copy_64.o) \
		$(addprefix events/, core.o probe.o msr.o) \
		$(addprefix mm/, init.o init_64.o fault.o ioremap.o extable.o mmap.o pgtable.o physaddr.o tlb.o cpu_entry_area.o maccess.o pgprot.o \
			$(addprefix pat/, set_memory.o memtype.o)) \
		$(addprefix pci/, i386.o init.o direct.o fixup.o legacy.o irq.o common.o early.o bus_numa.o) \
		$(addprefix kernel/, process_64.o signal.o traps.o idt.o irq.o irq_64.o dumpstack_64.o time.o ioport.o dumpstack.o \
			nmi.o setup.o x86_init.o i8259.o irqinit.o irq_work.o probe_roms.o sys_x86_64.o bootflag.o e820.o \
			quirks.o topology.o kdebugfs.o alternative.o i8253.o hw_breakpoint.o tsc.o tsc_msr.o io_delay.o \
			rtc.o resource.o irqflags.o static_call.o process.o ptrace.o step.o stacktrace.o reboot.o early-quirks.o \
			tsc_sync.o mpparse.o trace_clock.o hpet.o kvm.o kvmclock.o paravirt.o pvclock.o perf_regs.o \
			unwind_orc.o vsmp_64.o head_64.o head64.o ebda.o platform-quirks.o early_printk.o \
			$(addprefix fpu/, init.o bugs.o core.o regset.o signal.o xstate.o) \
			$(addprefix cpu/, cacheinfo.o scattered.o topology.o common.o rdrand.o match.o bugs.o aperfmperf.o cpuid-deps.o \
				umwait.o proc.o capflags.o powerflags.o perfctr-watchdog.o vmware.o hypervisor.o mshyperv.o) \
			$(addprefix apic/, apic.o apic_common.o apic_noop.o ipi.o vector.o hw_nmi.o io_apic.o apic_flat_64.o probe_64.o msi.o)))

block	:= $(addprefix block/, bdev.o fops.o bio.o elevator.o blk-core.o blk-sysfs.o blk-flush.o blk-settings.o \
		blk-ioc.o blk-map.o blk-merge.o blk-timeout.o blk-lib.o blk-mq.o blk-mq-tag.o blk-stat.o \
		blk-mq-sysfs.o blk-mq-cpumap.o 	blk-mq-sched.o ioctl.o genhd.o ioprio.o badblocks.o partitions/core.o \
		blk-rq-qos.o disk-events.o blk-ia-ranges.o blk-mq-pci.o blk-mq-virtio.o)

drivers := $(addprefix drivers/, block/virtio_blk.o net/loopback.o clocksource/i8253.o \
		$(addprefix virtio/, virtio.o virtio_ring.o virtio_pci_modern_dev.o virtio_pci_modern.o virtio_pci_common.o) \
		$(addprefix tty/, tty_io.o n_tty.o tty_ioctl.o tty_ldisc.o tty_buffer.o tty_port.o tty_mutex.o tty_ldsem.o \
			tty_baudrate.o tty_jobctrl.o n_null.o hvc/hvc_console.o) \
		$(addprefix rtc/, lib.o rtc-mc146818-lib.o) \
		$(addprefix char/, mem.o random.o misc.o virtio_console.o) \
		$(addprefix pci/, access.o bus.o probe.o host-bridge.o remove.o pci.o pci-driver.o search.o pci-sysfs.o rom.o \
			setup-res.o irq.o vpd.o setup-bus.o vc.o mmap.o setup-irq.o proc.o \
			$(addprefix msi/, pcidev_msi.o msi.o irqdomain.o)) \
		$(addprefix base/, component.o core.o bus.o dd.o syscore.o driver.o class.o platform.o cpu.o firmware.o \
			init.o map.o devres.o attribute_container.o transport_class.o topology.o container.o property.o \
			cacheinfo.o swnode.o devtmpfs.o \
			$(addprefix firmware_loader/, main.o builtin/main.o)))

fs	:= $(addprefix fs/, open.o read_write.o file_table.o super.o char_dev.o stat.o exec.o pipe.o namei.o fcntl.o \
		ioctl.o readdir.o select.o dcache.o inode.o attr.o bad_inode.o file.o filesystems.o namespace.o \
		seq_file.o xattr.o libfs.o fs-writeback.o pnode.o splice.o sync.o utimes.o d_path.o stack.o fs_struct.o \
		statfs.o fs_pin.o nsfs.o fs_types.o fs_context.o fs_parser.o fsopen.o init.o kernel_read_file.o \
		remap_range.o buffer.o direct-io.o mpage.o proc_namespace.o anon_inodes.o locks.o binfmt_script.o binfmt_elf.o \
		$(addprefix ramfs/, inode.o file-mmu.o) \
		$(addprefix iomap/, trace.o iter.o buffered-io.o direct-io.o fiemap.o seek.o) \
		$(addprefix ext2/, balloc.o dir.o file.o ialloc.o inode.o ioctl.o namei.o super.o symlink.o) \
		$(addprefix proc/, task_mmu.o inode.o root.o base.o generic.o array.o fd.o proc_tty.o cmdline.o \
			consoles.o cpuinfo.o devices.o interrupts.o loadavg.o meminfo.o stat.o uptime.o util.o \
			version.o softirqs.o namespaces.o self.o thread_self.o proc_net.o))

init	:= $(addprefix init/, main.o version.o noinitramfs.o calibrate.o init_task.o do_mounts.o)

kernel	:= $(addprefix kernel/, fork.o exec_domain.o panic.o cpu.o exit.o softirq.o resource.o sysctl.o capability.o \
		ptrace.o user.o signal.o sys.o umh.o workqueue.o pid.o task_work.o extable.o params.o kthread.o \
		sys_ni.o nsproxy.o notifier.o ksysfs.o cred.o reboot.o async.o range.o smpboot.o ucount.o regset.o \
		groups.o irq_work.o power/qos.o bpf/core.o static_call.o static_call_inline.o iomem.o up.o platform-feature.o \
		$(addprefix sched/, core.o fair.o build_policy.o build_utility.o) \
		$(addprefix locking/, mutex.o semaphore.o rwsem.o percpu-rwsem.o rtmutex_api.o) \
		$(addprefix printk/, printk.o printk_safe.o printk_ringbuffer.o) \
		$(addprefix irq/, irqdesc.o handle.o manage.o spurious.o resend.o chip.o dummychip.o devres.o autoprobe.o \
			irqdomain.o proc.o matrix.o msi.o) \
		$(addprefix rcu/, update.o sync.o srcutiny.o tiny.o) \
		$(addprefix entry/, common.o syscall_user_dispatch.o) \
		$(addprefix time/, time.o timer.o hrtimer.o timekeeping.o ntp.o clocksource.o jiffies.o timer_list.o timeconv.o timecounter.o \
			alarmtimer.o posix-stubs.o clockevents.o tick-common.o tick-broadcast.o tick-oneshot.o tick-sched.o vsyscall.o) \
		$(addprefix futex/, core.o syscalls.o pi.o requeue.o waitwake.o) \
		$(addprefix events/, core.o ring_buffer.o callchain.o hw_breakpoint.o))

lib	:= $(addprefix lib/, bcd.o sort.o parser.o debug_locks.o random32.o bust_spinlocks.o kasprintf.o bitmap.o \
		scatterlist.o list_sort.o uuid.o iov_iter.o clz_ctz.o bsearch.o find_bit.o llist.o memweight.o kfifo.o \
		percpu-refcount.o rhashtable.o once.o refcount.o usercopy.o errseq.o bucket_locks.o generic-radix-tree.o \
		lockref.o sbitmap.o string_helpers.o hexdump.o kstrtox.o iomap.o pci_iomap.o iomap_copy.o devres.o \
		syscall.o nlattr.o strncpy_from_user.o strnlen_user.o net_utils.o sg_pool.o bitrev.o \
		$(addprefix math/, div64.o gcd.o lcm.o int_pow.o int_sqrt.o reciprocal_div.o) \
		$(addprefix crypto/, chacha.o blake2s.o blake2s-generic.o blake2s-selftest.o))

mm	:= $(addprefix mm/, highmem.o memory.o mincore.o mlock.o mmap.o mmu_gather.o mprotect.o mremap.o msync.o \
		page_vma_mapped.o pagewalk.o pgtable-generic.o rmap.o vmalloc.o filemap.o mempool.o oom_kill.o \
		fadvise.o maccess.o page-writeback.o folio-compat.o readahead.o swap.o truncate.o vmscan.o shmem.o \
		util.o mmzone.o vmstat.o backing-dev.o mm_init.o percpu.o slab_common.o compaction.o vmacache.o \
		interval_tree.o list_lru.o workingset.o debug.o gup.o mmap_lock.o page_alloc.o init-mm.o memblock.o \
		sparse.o slub.o early_ioremap.o secretmem.o)

net	:= $(addprefix net/, devres.o socket.o ipv6/addrconf_core.o ethernet/eth.o \
		$(addprefix ethtool/, ioctl.o common.o) \
		$(addprefix sched/, sch_generic.o sch_mq.o) \
		$(addprefix unix/, af_unix.o garbage.o scm.o) \
		$(addprefix netlink/, af_netlink.o genetlink.o policy.o) \
		$(addprefix core/, sock.o request_sock.o skbuff.o datagram.o stream.o scm.o gen_stats.o gen_estimator.o \
			net_namespace.o secure_seq.o flow_dissector.o dev.o dev_addr_lists.o dst.o netevent.o neighbour.o \
			rtnetlink.o utils.o link_watch.o filter.o sock_diag.o dev_ioctl.o tso.o sock_reuseport.o \
			fib_notifier.o xdp.o flow_offload.o gro.o net-sysfs.o net-procfs.o))

security:= $(addprefix security/, commoncap.o min_addr.o)

objs = $(addprefix build/, $(x86) $(block) $(drivers) $(fs) $(init) $(kernel) $(lib) $(mm) $(net) $(security))
$(objs): c_flags = $(vmlinux_cflags)

lib_lib	:= $(addprefix lib/, ctype.o string.o vsprintf.o cmdline.o rbtree.o radix-tree.o timerqueue.o xarray.o idr.o \
		extable.o sha1.o irq_regs.o argv_split.o flex_proportions.o ratelimit.o show_mem.o is_single_threaded.o \
		plist.o decompress.o kobject_uevent.o earlycpio.o seq_buf.o siphash.o dec_and_lock.o nmi_backtrace.o \
		nodemask.o win_minmax.o memcat_p.o buildid.o dump_stack.o kobject.o klist.o logic_pio.o bug.o)
lib_x86	+= $(addprefix arch/x86/lib/, delay.o misc.o cmdline.o cpu.o usercopy_64.o usercopy.o getuser.o putuser.o \
		memcpy_64.o pc-conf-reg.o copy_mc.o copy_mc_64.o insn.o inat.o insn-eval.o csum-partial_64.o csum-copy_64.o \
		csum-wrappers_64.o clear_page_64.o copy_page_64.o memmove_64.o memset_64.o copy_user_64.o cmpxchg16b_emu.o)
libs	:= $(addprefix build/, $(lib_lib) $(lib_x86))
$(libs): c_flags = $(vmlinux_cflags)

$(foreach i, x86 block drivers fs init kernel lib mm net security lib_lib lib_x86, $(eval $i: $(addprefix build/, $($i))))

build/%.o: %.c
	@echo "  CC     " $@
	$(Q) $(CC) $(include) $(c_flags) -c -o $@ $<

build/%.o: %.S
	@echo "  AS     " $@
	$(Q) $(CC) $(include) $(c_flags) -D__ASSEMBLY__ -c -o $@ $<

build/%.lds: %.lds.S
	@echo "  LDS    " $@
	$(Q) gcc -E $(include) -P -Ux86 -D__ASSEMBLY__ -DLINKER_SCRIPT -o $@ $<

CFLAGS_build/arch/x86/kernel/irq.o := -I arch/x86/kernel/../include/asm/trace
CFLAGS_build/arch/x86/mm/fault.o := -I arch/x86/kernel/../include/asm/trace

setup_objs := $(addprefix build/arch/x86/boot/, bioscall.o cmdline.o header.o main.o memory.o pm.o pmjump.o regs.o)
$(setup_objs): c_flags := -m16 -Os -DDISABLE_BRANCH_PROFILING -D__DISABLE_EXPORTS -march=i386 -mregparm=3 -ffreestanding -fno-pic \
			-fno-stack-protector -Wno-address-of-packed-member -D_SETUP -D__KERNEL__
setup_objs: $(filter-out build/arch/x86/boot/header.o, $(setup_objs))

build/arch/x86/boot/bzImage: build/arch/x86/boot/setup.bin build/arch/x86/boot/vmlinux.bin build/vmlinux
	@echo "  BUILD  " $@
	$(Q) arch/x86/boot/tools/build build/arch/x86/boot/setup.bin build/arch/x86/boot/vmlinux.bin build/arch/x86/boot/zoffset.h $@

build/arch/x86/boot/vmlinux.bin: build/arch/x86/boot/compressed/vmlinux
	@echo "  OBJCOPY" $@
	$(Q) objcopy -O binary -R .note -R .comment -S $< $@

build/arch/x86/boot/zoffset.h: build/arch/x86/boot/compressed/vmlinux
	@echo "  ZOFFSET" $@
	$(Q) nm $< | sed -n -e 's/^\([0-9a-fA-F]*\) [a-zA-Z] \(startup_32\|startup_64\|efi32_stub_entry\|efi64_stub_entry\|efi_pe_entry\|efi32_pe_entry\|input_data\|kernel_info\|_end\|_ehead\|_text\|z_.*\)$$/\#define ZO_\2 0x\1/p' > $@

build/arch/x86/boot/header.o: build/arch/x86/boot/zoffset.h

build/arch/x86/boot/setup.elf: arch/x86/boot/setup.ld $(setup_objs)
	@echo "  LD     " $@
	$(Q) ld -m elf_i386 -T $^ -o $@

build/arch/x86/boot/setup.bin: build/arch/x86/boot/setup.elf
	@echo "  OBJCOPY" $@
	$(Q) objcopy -O binary $< $@

vmlinux_objs = $(addprefix build/arch/x86/boot/compressed/, head_64.o misc.o string.o cmdline.o \
			piggy.o ident_map_64.o pgtable_64.o)
$(vmlinux_objs): c_flags := -fPIE -ffreestanding -fno-stack-protector -Wno-address-of-packed-member -Wno-pointer-sign \
			-D__DISABLE_EXPORTS -include include/linux/hidden.h -D__KERNEL__
vmlinux_objs: $(filter-out build/arch/x86/boot/compressed/piggy.o build/arch/x86/boot/compressed/misc.o, $(vmlinux_objs))

build/arch/x86/boot/compressed/vmlinux: build/arch/x86/boot/compressed/vmlinux.lds $(vmlinux_objs)
	@echo "  LD     " $@
	$(Q) ld -m elf_x86_64 --no-ld-generated-unwind-info --no-dynamic-linker -T $^ -o $@

build/arch/x86/boot/compressed/vmlinux.bin: build/vmlinux
	@echo "  OBJCOPY" $@
	$(Q) objcopy -R .comment -S $< $@

build/arch/x86/boot/compressed/vmlinux.bin.gz: build/arch/x86/boot/compressed/vmlinux.bin
	@echo "  GZIP   " $@
	$(Q) cat $< | gzip -n -f -9 > $@

arch/x86/boot/compressed/piggy.S: build/arch/x86/boot/compressed/vmlinux.bin.gz
	@echo "  MKPIGGY" $@
	$(Q) arch/x86/boot/compressed/mkpiggy $< > $@

build/vmlinux: build/arch/x86/kernel/vmlinux.lds $(objs) $(libs)
	@echo "  LD     " $@
	$(Q) ld -m elf_x86_64 -z max-page-size=0x200000 --script=build/arch/x86/kernel/vmlinux.lds -o $@ --whole-archive $(objs) --no-whole-archive --start-group $(libs) --end-group
