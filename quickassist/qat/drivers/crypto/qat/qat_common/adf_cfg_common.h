/* SPDX-License-Identifier: (BSD-3-Clause OR GPL-2.0-only) */
/* Copyright(c) 2014 - 2021 Intel Corporation */
#ifndef ADF_CFG_COMMON_H_
#define ADF_CFG_COMMON_H_

#include <linux/types.h>
#include <linux/ioctl.h>

#define ADF_CFG_MAX_STR_LEN 128
#define ADF_CFG_MAX_KEY_LEN_IN_BYTES ADF_CFG_MAX_STR_LEN
#define ADF_CFG_MAX_VAL_LEN_IN_BYTES ADF_CFG_MAX_STR_LEN
#define ADF_CFG_MAX_SECTION_LEN_IN_BYTES ADF_CFG_MAX_STR_LEN
#define ADF_CFG_NULL_TERM_SIZE 1
#define ADF_CFG_BASE_DEC 10
#define ADF_CFG_BASE_HEX 16
#define ADF_CFG_ALL_DEVICES 0xFFFE
#define ADF_CFG_NO_DEVICE 0xFFFF
#define ADF_CFG_AFFINITY_WHATEVER 0xFF
#define MAX_DEVICE_NAME_SIZE 32
#define ADF_MAX_DEVICES (32 * 32)
#define ADF_ARB_NUM 4
#ifdef QAT_UIO
#define ADF_CFG_STORAGE_ENABLED 1
#endif
#define ADF_SSM_WDT_PKE_DEFAULT_VALUE 0x3000000
#define ADF_WDT_TIMER_SYM_COMP_MS 3
#define ADF_MIN_HB_TIMER_MS 200
#ifdef QAT_ESXI
#define ADF_REQUEST_TIMEOUT_DEVIATION_MS 300
#endif
#ifdef QAT_UIO
#define ADF_CFG_MAX_NUM_OF_SECTIONS 16
#define ADF_CFG_MAX_NUM_OF_TOKENS 16
#define ADF_CFG_MAX_TOKENS_IN_CONFIG 8
#define ADF_CFG_RESP_POLL 1
#define ADF_CFG_RESP_EPOLL 2
#define ADF_CFG_DEF_CY_RING_ASYM_SIZE 64
#define ADF_CFG_DEF_CY_RING_SYM_SIZE 512
#define ADF_CFG_DEF_DC_RING_SIZE 512
#define ADF_CFG_MAX_CORE_NUM 256
#define ADF_CFG_MAX_TOKENS ADF_CFG_MAX_CORE_NUM
#define ADF_CFG_MAX_TOKEN_LEN 10
#define ADF_CFG_ACCEL_DEF_COALES 1
#define ADF_CFG_ACCEL_DEF_COALES_TIMER 10000
#define ADF_CFG_ACCEL_DEF_COALES_NUM_MSG 0
#define ADF_CFG_ASYM_SRV_MASK 1
#define ADF_CFG_SYM_SRV_MASK 2
#define ADF_CFG_DC_SRV_MASK 8
#define ADF_CFG_UNKNOWN_SRV_MASK 0
#define ADF_CFG_DEF_ASYM_MASK 0x03
#endif

#define ADF_CFG_MAX_SERVICES 4

#define ADF_CFG_SERV_RING_PAIR_0_SHIFT 0
#define ADF_CFG_SERV_RING_PAIR_1_SHIFT 3
#define ADF_CFG_SERV_RING_PAIR_2_SHIFT 6
#define ADF_CFG_SERV_RING_PAIR_3_SHIFT 9
#define ADF_MAX_SERVICES 3

enum adf_svc_type {
	ADF_SVC_ASYM = 0,
	ADF_SVC_SYM = 1,
	ADF_SVC_DC = 2,
	ADF_SVC_NONE = 3
};

struct adf_pci_address {
	u16 domain_nr;
	u8 bus;
	u8 dev;
	u8 func;
};

enum adf_cfg_service_type {
	NA = 0,
	CRYPTO,
	COMP,
	SYM,
	ASYM,
	USED
};

enum adf_cfg_val_type {
	ADF_DEC,
	ADF_HEX,
	ADF_STR
};

enum adf_device_type {
	DEV_UNKNOWN = 0,
	DEV_DH895XCC,
	DEV_DH895XCCVF,
	DEV_C62X,
	DEV_C62XVF,
	DEV_C3XXX,
	DEV_C3XXXVF,
	DEV_C4XXX,
	DEV_C4XXXVF,
	DEV_D15XX,
	DEV_D15XXVF,
	DEV_4XXX,
	DEV_4XXXVF,
	DEV_VQAT,
};

struct adf_dev_status_info {
	enum adf_device_type type;
	u32 accel_id;
	u32 instance_id;
#ifdef QAT_UIO
	u32 kpt_achandle;
#endif
	u8 num_ae;
	u8 num_accel;
	u8 num_logical_accel;
	u8 banks_per_accel;
	u8 rings_per_bank;
	u8 state;
	u8 bus;
	u8 dev;
	u8 fun;
	char name[MAX_DEVICE_NAME_SIZE];
	u32 node_id;
	int domain;
};

#define ADF_CFG_HB_DEFAULT_VALUE 500
#define ADF_CFG_HB_COUNT_THRESHOLD 3

enum adf_device_heartbeat_status {
	DEV_HB_UNRESPONSIVE = 0,
	DEV_HB_ALIVE,
	DEV_HB_UNSUPPORTED
};

struct adf_dev_heartbeat_status_ctl {
	u32 device_id;
	enum adf_device_heartbeat_status status;
};

struct adf_dev_miscellaneous_stats {
	u64 misc_counter;
};

#ifdef QAT_ERR_INJECTION_SIM
struct adf_pmisc_write_info {
	u32 accel_id;
	u32 offset;
	u32 value;
};
#endif

#define ADF_CTL_IOC_MAGIC 'a'
#define IOCTL_CONFIG_SYS_RESOURCE_PARAMETERS _IOW(ADF_CTL_IOC_MAGIC, 0, \
		struct adf_user_cfg_ctl_data)
#define IOCTL_STOP_ACCEL_DEV _IOW(ADF_CTL_IOC_MAGIC, 1, \
		struct adf_user_cfg_ctl_data)
#define IOCTL_START_ACCEL_DEV _IOW(ADF_CTL_IOC_MAGIC, 2, \
		struct adf_user_cfg_ctl_data)
#define IOCTL_STATUS_ACCEL_DEV _IOW(ADF_CTL_IOC_MAGIC, 3, uint32_t)
#define IOCTL_GET_NUM_DEVICES _IOW(ADF_CTL_IOC_MAGIC, 4, int32_t)
#define IOCTL_HEARTBEAT_ACCEL_DEV _IOW(ADF_CTL_IOC_MAGIC, 15, \
				struct adf_dev_heartbeat_status_ctl)
#ifdef QAT_HB_FAIL_SIM
#define IOCTL_HEARTBEAT_SIM_FAIL _IOW(ADF_CTL_IOC_MAGIC, 99, uint32_t)
#endif
#ifdef QAT_ERR_INJECTION_SIM
#define IOCTL_WRITE_PMISC  _IOW(ADF_CTL_IOC_MAGIC, 98, \
				struct adf_pmisc_write_info)
#endif
#ifdef QAT_UIO
#define IOCTL_GET_CFG_VAL _IOW(ADF_CTL_IOC_MAGIC, 5, \
				struct adf_user_cfg_ctl_data)
#define IOCTL_RESERVE_RING _IOW(ADF_CTL_IOC_MAGIC, 6, \
				struct adf_user_reserve_ring)
#define IOCTL_RELEASE_RING _IOW(ADF_CTL_IOC_MAGIC, 7, \
				struct adf_user_reserve_ring)
#define IOCTL_ENABLE_RING _IOW(ADF_CTL_IOC_MAGIC, 8, \
				struct adf_user_reserve_ring)
#define IOCTL_DISABLE_RING _IOW(ADF_CTL_IOC_MAGIC, 9, \
				struct adf_user_reserve_ring)
#define IOCTL_RESET_ACCEL_DEV _IOW(ADF_CTL_IOC_MAGIC, 10, \
				struct adf_user_cfg_ctl_data)
#define IOCTL_GET_DEV_REAL_ID _IOW(ADF_CTL_IOC_MAGIC, 17, uint32_t)
#define IOCTL_SLA_GET_CAPS _IOW(ADF_CTL_IOC_MAGIC, 18, struct adf_user_sla_caps)
#define IOCTL_SLA_CREATE _IOW(ADF_CTL_IOC_MAGIC, 19, struct adf_user_sla)
#define IOCTL_SLA_UPDATE _IOW(ADF_CTL_IOC_MAGIC, 20, struct adf_user_sla)
#define IOCTL_SLA_DELETE _IOW(ADF_CTL_IOC_MAGIC, 21, struct adf_user_sla)
#define IOCTL_SLA_GET_LIST _IOW(ADF_CTL_IOC_MAGIC, 22, struct adf_user_slas)
#endif
#endif
