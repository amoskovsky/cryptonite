/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "EncryptedContentInfo.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/EncryptedContentInfo.c"

static asn_TYPE_member_t asn_MBR_EncryptedContentInfo_1[] = {
    {
        ATF_NOFLAGS, 0, offsetof(struct EncryptedContentInfo, contentType),
        (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)),
        0,
        &ContentType_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "contentType"
    },
    {
        ATF_NOFLAGS, 0, offsetof(struct EncryptedContentInfo, contentEncryptionAlgorithm),
        (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
        0,
        &ContentEncryptionAlgorithmIdentifier_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "contentEncryptionAlgorithm"
    },
    {
        ATF_POINTER, 1, offsetof(struct EncryptedContentInfo, encryptedContent),
        (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
        -1,    /* IMPLICIT tag at current level */
        &EncryptedContent_desc,
        0,    /* Defer constraints checking to the member type */
        0,    /* PER is not compiled, use -gen-PER */
        0,
        "encryptedContent"
    },
};
static const ber_tlv_tag_t EncryptedContentInfo_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_EncryptedContentInfo_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (6 << 2)), 0, 0, 0 }, /* contentType */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 1, 0, 0 }, /* contentEncryptionAlgorithm */
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 2, 0, 0 } /* encryptedContent */
};
static asn_SEQUENCE_specifics_t asn_SPC_EncryptedContentInfo_specs_1 = {
    sizeof(struct EncryptedContentInfo),
    offsetof(struct EncryptedContentInfo, _asn_ctx),
    asn_MAP_EncryptedContentInfo_tag2el_1,
    3,    /* Count of tags in the map */
    0, 0, 0,    /* Optional elements (not needed) */
    -1,    /* Start extensions */
    -1    /* Stop extensions */
};
asn_TYPE_descriptor_t EncryptedContentInfo_desc = {
    "EncryptedContentInfo",
    "EncryptedContentInfo",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,    /* No PER support, use "-gen-PER" to enable */
    0,    /* Use generic outmost tag fetcher */
    EncryptedContentInfo_desc_tags_1,
    sizeof(EncryptedContentInfo_desc_tags_1)
    / sizeof(EncryptedContentInfo_desc_tags_1[0]), /* 1 */
    EncryptedContentInfo_desc_tags_1,    /* Same as above */
    sizeof(EncryptedContentInfo_desc_tags_1)
    / sizeof(EncryptedContentInfo_desc_tags_1[0]), /* 1 */
    0,    /* No PER visible constraints */
    asn_MBR_EncryptedContentInfo_1,
    3,    /* Elements count */
    &asn_SPC_EncryptedContentInfo_specs_1    /* Additional specs */
};

asn_TYPE_descriptor_t *get_EncryptedContentInfo_desc(void)
{
    return &EncryptedContentInfo_desc;
}
