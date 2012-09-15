/* drivers/misc/mdniemod.c
 *
 * sharpness tweaks by hardcore
 * made module by gokhanmoral
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/init.h>
#include <linux/device.h>
#include <linux/kallsyms.h>
#ifdef CONFIG_HAS_EARLYSUSPEND
#include <linux/earlysuspend.h>
#endif
#include "mdnie_table_c1m0.h"
#include "mdnie_table_c1m0_hardcore.h"

//backed up data to restore while unloading the module
static struct mdnie_tunning_info backup_etc_table[CABC_MAX][OUTDOOR_MAX][TONE_MAX];
static struct mdnie_tunning_info backup_tunning_table[CABC_MAX][MODE_MAX][SCENARIO_MAX];
static unsigned short backup_tune_camera[sizeof(tune_camera)];
static unsigned short backup_tune_camera_outdoor[sizeof(tune_camera_outdoor)];

#define apply_mdnie_tweak(structname)					\
	tmp = (void *)kallsyms_lookup_name(#structname); \
	if(tmp>0) {\
		memcpy(backup_##structname, tmp, sizeof(structname)); \
		memcpy(tmp, hardcore_##structname, sizeof(structname)); \
	}

#define reset_mdnie_tweak(structname)					\
	tmp = (void *)kallsyms_lookup_name(#structname); \
	if(tmp>0) \
		memcpy(tmp, backup_##structname,sizeof(structname));

static void force_update_mdnie(void)
{
	struct mdnie_info *gm_g_mdnie;
	void (*gm_set_mdnie_value)(struct mdnie_info *mdnie, u8 force);
	gm_g_mdnie = *((void **)kallsyms_lookup_name("g_mdnie"));
	gm_set_mdnie_value = (void (*)(struct mdnie_info*, u8))
			kallsyms_lookup_name("set_mdnie_value");
	(*gm_set_mdnie_value)(gm_g_mdnie, 1);
}

static int __init mdniemod_init(void)
{
	void *tmp;

	pr_info("Applying mDNIe sharpness tweaks...\n");
	apply_mdnie_tweak(tune_camera);
	apply_mdnie_tweak(tune_camera_outdoor);
	apply_mdnie_tweak(tunning_table);
	apply_mdnie_tweak(etc_table);
	force_update_mdnie();
	return 0;
}

static void __exit mdniemod_exit(void)
{
	void *tmp;

	pr_info("Restoring mDNIe stock values...\n");
	reset_mdnie_tweak(tune_camera);
	reset_mdnie_tweak(tune_camera_outdoor);
	reset_mdnie_tweak(tunning_table);
	reset_mdnie_tweak(etc_table);
	force_update_mdnie();
}

module_init( mdniemod_init );
module_exit( mdniemod_exit );

MODULE_AUTHOR("Gokhan Moral <gm@alumni.bilkent.edu.tr>");
MODULE_DESCRIPTION("mdnie sharpness tweaks by hardcore");
MODULE_LICENSE("GPL");
