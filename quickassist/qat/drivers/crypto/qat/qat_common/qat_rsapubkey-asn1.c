/*
 * Automatically generated by asn1_compiler.  Do not edit
 *
 * ASN.1 parser for qat_rsapubkey
 */
#ifdef QAT_PKE_OLD_SUPPORTED
#include <linux/version.h>
#if KERNEL_VERSION(4, 4, 0) <= LINUX_VERSION_CODE
#include <linux/asn1_ber_bytecode.h>
#include "qat_rsapubkey-asn1.h"

enum qat_rsapubkey_actions {
	ACT_qat_rsa_get_e = 0,
	ACT_qat_rsa_get_n = 1,
	NR__qat_rsapubkey_actions = 2
};

static const
asn1_action_t qat_rsapubkey_action_table[NR__qat_rsapubkey_actions] = {
	[0] = qat_rsa_get_e,
	[1] = qat_rsa_get_n,
};

static const unsigned char qat_rsapubkey_machine[] = {
	/* RsaPubKey */
	[0] = ASN1_OP_MATCH,
	[1] = _tag(UNIV, CONS, SEQ),
	[2] =  ASN1_OP_MATCH_ACT,		/* n */
	[3] =  _tag(UNIV, PRIM, INT),
	[4] =  _action(ACT_qat_rsa_get_n),
	[5] =  ASN1_OP_MATCH_ACT,		/* e */
	[6] =  _tag(UNIV, PRIM, INT),
	[7] =  _action(ACT_qat_rsa_get_e),
	[8] = ASN1_OP_END_SEQ,
	[9] = ASN1_OP_COMPLETE,
};

const struct asn1_decoder qat_rsapubkey_decoder = {
	.machine = qat_rsapubkey_machine,
	.machlen = sizeof(qat_rsapubkey_machine),
	.actions = qat_rsapubkey_action_table,
};
#endif
#endif
