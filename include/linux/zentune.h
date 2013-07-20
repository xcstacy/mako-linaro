#ifndef _LINUX_ZENTUNE_H
#define _LINUX_ZENTUNE_H

#ifdef __KERNEL__

/* CPU Scheduler Related */

#  define sysctl_sched_latency_custom                       3000000ULL;
#  define normalized_sysctl_sched_latency_custom            3000000ULL;
#  define sysctl_sched_min_granularity_custom               300000ULL;
#  define normalized_sysctl_sched_min_granularity_custom    300000ULL;
#  define sched_nr_latency_custom                           10;
#  define sysctl_sched_wakeup_granularity_custom            500000UL;
#  define normalized_sysctl_sched_wakeup_granularity_custom 500000UL;
#  define sysctl_sched_migration_cost_custom                250000UL;
#  define sysctl_sched_cfs_bandwidth_slice_custom           3000UL;

/* MM Related */
#define vm_dirty_ratio_custom 50;
#define dirty_background_ratio_custom 20;

/* CPUFreq Related */
#define DEF_SAMPLING_DOWN_FACTOR_CUSTOM          (10)
#define DEF_FREQUENCY_DOWN_DIFFERENTIAL_CUSTOM   (30)
#define DEF_FREQUENCY_UP_THRESHOLD_CUSTOM        (60)
#define MICRO_FREQUENCY_DOWN_DIFFERENTIAL_CUSTOM (30)
#define MICRO_FREQUENCY_UP_THRESHOLD_CUSTOM      (60)

#endif /* __KERNEL__ */
#endif /* _LINUX_ZENTUNE_H */
