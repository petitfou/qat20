/*
 * Automatically generated by asn1_compiler.  Do not edit
 *
 * ASN.1 parser for qat_rsaprivkey
 */
#ifdef QAT_PKE_OLD_SUPPORTED
#include <linux/version.h>
#if KERNEL_VERSION(4, 4, 0) <= LINUX_VERSION_CODE
#include <linux/asn1_decoder.h>

extern const struct asn1_decoder qat_rsaprivkey_decoder;

int qat_rsa_get_d(void *context, size_t hdrlen, unsigned char tag, const
		  void *value, size_t vlen);
int qat_rsa_get_e(void *context, size_t hdrlen, unsigned char tag, const
		  void *value, size_t vlen);
int qat_rsa_get_n(void *context, size_t hdrlen, unsigned char tag, const
		  void *value, size_t vlen);
#endif
#endif
