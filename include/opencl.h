/**
 * Author......: See docs/credits.txt
 * License.....: MIT
 */

#ifndef _OPENCL_H
#define _OPENCL_H

#include <stdio.h>
#include <errno.h>

static const char CL_VENDOR_AMD[]           = "Advanced Micro Devices, Inc.";
static const char CL_VENDOR_AMD_USE_INTEL[] = "GenuineIntel";
static const char CL_VENDOR_APPLE[]         = "Apple";
static const char CL_VENDOR_INTEL_BEIGNET[] = "Intel";
static const char CL_VENDOR_INTEL_SDK[]     = "Intel(R) Corporation";
static const char CL_VENDOR_MESA[]          = "Mesa";
static const char CL_VENDOR_NV[]            = "NVIDIA Corporation";
static const char CL_VENDOR_POCL[]          = "The pocl project";

static const char ST_0000[] = "Initializing";
static const char ST_0001[] = "Autotuning";
static const char ST_0002[] = "Running";
static const char ST_0003[] = "Paused";
static const char ST_0004[] = "Exhausted";
static const char ST_0005[] = "Cracked";
static const char ST_0006[] = "Aborted";
static const char ST_0007[] = "Quit";
static const char ST_0008[] = "Bypass";

char *strstatus (const uint devices_status);

void load_kernel (const char *kernel_file, int num_devices, size_t *kernel_lengths, const u8 **kernel_sources);
void writeProgramBin (char *dst, u8 *binary, size_t binary_size);

int gidd_to_pw_t (opencl_ctx_t *opencl_ctx, hc_device_param_t *device_param, const u64 gidd, pw_t *pw);

int choose_kernel (opencl_ctx_t *opencl_ctx, hc_device_param_t *device_param, const user_options_t *user_options, const rules_ctx_t *rules_ctx, hashconfig_t *hashconfig, const uint attack_exec, const uint attack_mode, const uint opts_type, const salt_t *salt_buf, const uint highest_pw_len, const uint pws_cnt, const uint fast_iteration);
int run_kernel (const uint kern_run, opencl_ctx_t *opencl_ctx, hc_device_param_t *device_param, const uint num, const uint event_update, const uint iteration, hashconfig_t *hashconfig, const user_options_t *user_options);
int run_kernel_mp (const uint kern_run, opencl_ctx_t *opencl_ctx, hc_device_param_t *device_param, const uint num);
int run_kernel_tm (opencl_ctx_t *opencl_ctx, hc_device_param_t *device_param);
int run_kernel_amp (opencl_ctx_t *opencl_ctx, hc_device_param_t *device_param, const uint num);
int run_kernel_memset (opencl_ctx_t *opencl_ctx, hc_device_param_t *device_param, cl_mem buf, const uint value, const uint num);
int run_kernel_bzero (opencl_ctx_t *opencl_ctx, hc_device_param_t *device_param, cl_mem buf, const size_t size);

int run_copy (opencl_ctx_t *opencl_ctx, hc_device_param_t *device_param, hashconfig_t *hashconfig, const user_options_t *user_options, const user_options_extra_t *user_options_extra, const uint pws_cnt);

int run_cracker (opencl_ctx_t *opencl_ctx, hc_device_param_t *device_param, hashconfig_t *hashconfig, hashes_t *hashes, const user_options_t *user_options, const user_options_extra_t *user_options_extra, const rules_ctx_t *rules_ctx, const uint pws_cnt);

int opencl_ctx_init (opencl_ctx_t *opencl_ctx, const user_options_t *user_options);
void opencl_ctx_destroy (opencl_ctx_t *opencl_ctx);

int opencl_ctx_devices_init (opencl_ctx_t *opencl_ctx, const user_options_t *user_options);
void opencl_ctx_devices_destroy (opencl_ctx_t *opencl_ctx);

int opencl_session_begin (opencl_ctx_t *opencl_ctx, const hashconfig_t *hashconfig, const hashes_t *hashes, const rules_ctx_t *rules_ctx, const user_options_t *user_options, const user_options_extra_t *user_options_extra, const folder_config_t *folder_config, const bitmap_ctx_t *bitmap_ctx, const tuning_db_t *tuning_db);
int opencl_session_destroy (opencl_ctx_t *opencl_ctx);

#endif // _OPENCL_H
