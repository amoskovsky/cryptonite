/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#ifndef    _Certificate_H_
#define    _Certificate_H_


#include "asn_application.h"

/* Including external dependencies */
#include "TBSCertificate.h"
#include "AlgorithmIdentifier.h"
#include "BIT_STRING.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Certificate */
typedef struct Certificate {
    TBSCertificate_t     tbsCertificate;
    AlgorithmIdentifier_t     signatureAlgorithm;
    BIT_STRING_t     signature;

    /* Context for parsing across buffer boundaries */
    asn_struct_ctx_t _asn_ctx;
} Certificate_t;

/* Implementation */
extern asn_TYPE_descriptor_t Certificate_desc;
CRYPTONITE_EXPORT asn_TYPE_descriptor_t *get_Certificate_desc(void);

#ifdef __cplusplus
}
#endif

#endif
