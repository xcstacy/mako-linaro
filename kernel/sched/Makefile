ifdef CONFIG_FUNCTION_TRACER
CFLAGS_REMOVE_clock.o = -pg
endif

obj-y += core.o clock.o idle_task.o
obj-y += fair.o rt.o deadline.o stop_task.o 
obj-$(CONFIG_SMP) += cpupri.o cpudeadline.o
obj-$(CONFIG_SCHED_AUTOGROUP) += auto_group.o
obj-$(CONFIG_SCHEDSTATS) += stats.o
obj-$(CONFIG_SCHED_DEBUG) += debug.o


