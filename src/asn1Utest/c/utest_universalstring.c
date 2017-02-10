/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "utest_asn1.h"

static UniversalString_t *test_universalstring_create(void)
{
    uint8_t encode[54] = {
        0x1c, 0x34,
        0x00, 0x00, 0x00, 0x54, 0x00, 0x00, 0x00, 0x65,
        0x00, 0x00, 0x00, 0x73, 0x00, 0x00, 0x00, 0x74,
        0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x6d,
        0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x73,
        0x00, 0x00, 0x00, 0x73, 0x00, 0x00, 0x00, 0x61,
        0x00, 0x00, 0x00, 0x67, 0x00, 0x00, 0x00, 0x65,
        0x00, 0x00, 0x00, 0x2e
    };

    UniversalString_t *universalstring = NULL;

    ASN_EXECUTE(ber_decode(0, &UniversalString_desc, (void *)&universalstring, encode, sizeof(encode)));

    ASSERT_NOT_NULL(universalstring);
cleanup:
    return universalstring;
}

void test_universalstring_alloc_free(void)
{
    UniversalString_t *universalstring = NULL;

    ASSERT_ASN_ALLOC(universalstring);
    ASSERT_NOT_NULL(universalstring);
cleanup:

    ASN_FREE(&UniversalString_desc, universalstring);
}

void test_universalstring_der_encode(void)
{
    ByteArray *actual = NULL;
    ByteArray *expected = NULL;
    uint8_t exp[54] = {
        0x1c, 0x34,
        0x00, 0x00, 0x00, 0x54, 0x00, 0x00, 0x00, 0x65,
        0x00, 0x00, 0x00, 0x73, 0x00, 0x00, 0x00, 0x74,
        0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x6d,
        0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x73,
        0x00, 0x00, 0x00, 0x73, 0x00, 0x00, 0x00, 0x61,
        0x00, 0x00, 0x00, 0x67, 0x00, 0x00, 0x00, 0x65,
        0x00, 0x00, 0x00, 0x2e
    };

    UniversalString_t *universalstring = NULL;

    universalstring = test_universalstring_create();
    ASSERT_NOT_NULL(universalstring);
    ASSERT_NOT_NULL(expected = ba_alloc_from_uint8(exp, sizeof(exp)));

    ASSERT_RET_OK(asn_encode_ba(&UniversalString_desc, universalstring, (void *)&actual));
    ASSERT_NOT_NULL(actual);

    ASSERT_EQUALS_BA(expected, actual);

cleanup:
    BA_FREE(expected, actual);
    ASN_FREE(&UniversalString_desc, universalstring);
}

void test_universalstring_uper_encode(void)
{
    asn_enc_rval_t ret;
    uint8_t actual[424] = {0};
    uint8_t expected[424] = {
        0x0d,
        0x00, 0x00, 0x00, 0x54, 0x00, 0x00, 0x00, 0x65,
        0x00, 0x00, 0x00, 0x73, 0x00, 0x00, 0x00, 0x74,
        0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x6d,
        0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x73,
        0x00, 0x00, 0x00, 0x73, 0x00, 0x00, 0x00, 0x61,
        0x00, 0x00, 0x00, 0x67, 0x00, 0x00, 0x00, 0x65,
        0x00, 0x00, 0x00, 0x2e, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    UniversalString_t *universalstring = NULL;

    universalstring = test_universalstring_create();
    ASSERT_NOT_NULL(universalstring);

    ret = uper_encode_to_buffer(&UniversalString_desc, universalstring, (void *)actual, sizeof(actual));
    ASSERT_NOT_NULL(actual);

    ASSERT_TRUE(sizeof(expected) == ret.encoded);
    ASSERT_EQUALS(expected, actual, sizeof(expected));
cleanup:

    ASN_FREE(&UniversalString_desc, universalstring);
}

void test_universalstring_uper_decode(void)
{
    uint8_t encode[424] = {
        0x0d,
        0x00, 0x00, 0x00, 0x54, 0x00, 0x00, 0x00, 0x65,
        0x00, 0x00, 0x00, 0x73, 0x00, 0x00, 0x00, 0x74,
        0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x6d,
        0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x73,
        0x00, 0x00, 0x00, 0x73, 0x00, 0x00, 0x00, 0x61,
        0x00, 0x00, 0x00, 0x67, 0x00, 0x00, 0x00, 0x65,
        0x00, 0x00, 0x00, 0x2e, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    UniversalString_t *actual = NULL;
    UniversalString_t *expected = NULL;
    asn_dec_rval_t ret;

    expected = test_universalstring_create();
    ASSERT_NOT_NULL(expected);

    ret = uper_decode(0, &UniversalString_desc, (void *)&actual, encode, sizeof(encode), 0, 0);

    ASSERT_TRUE(ret.code == RET_OK);
    ASSERT_NOT_NULL(actual);

    ASSERT_TRUE(asn_equals(&UniversalString_desc, expected, actual));

cleanup:
    ASN_FREE(&UniversalString_desc, expected);
    ASN_FREE(&UniversalString_desc, actual);
}

void test_universalstring_xer_decode(void)
{
    uint8_t encode[48] = {
        0x3c, 0x55, 0x6e, 0x69, 0x76, 0x65, 0x72, 0x73,
        0x61, 0x6c, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67,
        0x3e, 0x54, 0x65, 0x73, 0x74, 0x20, 0x6d, 0x65,
        0x73, 0x73, 0x61, 0x67, 0x65, 0x2e, 0x3c, 0x2f,
        0x55, 0x6e, 0x69, 0x76, 0x65, 0x72, 0x73, 0x61,
        0x6c, 0x53, 0x74, 0x72, 0x69, 0x6e, 0x67, 0x3e
    };

    UniversalString_t *actual = NULL;
    UniversalString_t *expected = NULL;
    asn_dec_rval_t ret;

    expected = test_universalstring_create();
    ASSERT_NOT_NULL(expected);

    ret = xer_decode(0, &UniversalString_desc, (void *)&actual, encode, sizeof(encode));

    ASSERT_TRUE(ret.code == RET_OK);
    ASSERT_NOT_NULL(actual);

    ASSERT_TRUE(asn_equals(&UniversalString_desc, expected, actual));

cleanup:
    ASN_FREE(&UniversalString_desc, expected);
    ASN_FREE(&UniversalString_desc, actual);
}

void utest_universalstring(void)
{
    PR("%s\n", __FILE__);

    test_universalstring_alloc_free();
    test_universalstring_uper_encode();
    test_universalstring_der_encode();
    test_universalstring_uper_decode();
    test_universalstring_xer_decode();
}
