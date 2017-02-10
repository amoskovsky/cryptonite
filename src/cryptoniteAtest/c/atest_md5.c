/*
 * Copyright (c) 2016 PrivatBank IT <acsk@privatbank.ua>. All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */

#include "atest.h"
#include "md5.h"
#include "hmac.h"

HashTestCtx md5_data[] = {
    {
        "00",
        "93B885ADFE0DA089CDF634904FD59F71"
    },
    {
        "0000",
        "C4103F122D27677C9DB144CAE1394A66"
    },
    {
        "000000",
        "693E9AF84D3DFCC71E640E005BDC5E2E"
    },
    {
        "00000000",
        "F1D3FF8443297732862DF21DC4E57262"
    },
    {
        "0000000000",
        "CA9C491AC66B2C62500882E93F3719A8"
    },
    {
        "000000000000",
        "7319468847D7B1AEE40DBF5DD963C999"
    },
    {
        "00000000000000",
        "D310A40483F9399DD7ED1712E0FDD702"
    },
    {
        "0000000000000000",
        "7DEA362B3FAC8E00956A4952A3D4F474"
    },
    {
        "000000000000000000",
        "3F2829B2FFE8434D67F98A2A98968652"
    },
    {
        "00000000000000000000",
        "A63C90CC3684AD8B0A2176A6A8FE9005"
    },
    {
        "0000000000000000000000",
        "74DA4121DC1C0ED2A8E5B0741F824034"
    },
    {
        "000000000000000000000000",
        "8DD6BB7329A71449B0A1B292B5999164"
    },
    {
        "00000000000000000000000000",
        "0B867E53C1D233CE9FE49D54549A2323"
    },
    {
        "0000000000000000000000000000",
        "36DF9540A5EF4996A9737657E4A8929C"
    },
    {
        "000000000000000000000000000000",
        "3449C9E5E332F1DBB81505CD739FBF3F"
    },
    {
        "00000000000000000000000000000000",
        "4AE71336E44BF9BF79D2752E234818A5"
    },
    {
        "0000000000000000000000000000000000",
        "F3C8BDB6B9DF478F227AF2CE61C8A5A1"
    },
    {
        "000000000000000000000000000000000000",
        "FF035BFF2DCF972EE7DFD023455997EF"
    },
    {
        "00000000000000000000000000000000000000",
        "0E6BCE6899FAE841F79024AFBDF7DB1D"
    },
    {
        "0000000000000000000000000000000000000000",
        "441018525208457705BF09A8EE3C1093"
    },
    {
        "000000000000000000000000000000000000000000",
        "2319AC34F4848755A639FD524038DFD3"
    },
    {
        "00000000000000000000000000000000000000000000",
        "DB46E81649D6863B16BD99AB139C865B"
    },
    {
        "0000000000000000000000000000000000000000000000",
        "6B43B583E2B662724B6FBB5189F6AB28"
    },
    {
        "000000000000000000000000000000000000000000000000",
        "1681FFC6E046C7AF98C9E6C232A3FE0A"
    },
    {
        "00000000000000000000000000000000000000000000000000",
        "D28C293E10139D5D8F6E4592AEAFFC1B"
    },
    {
        "0000000000000000000000000000000000000000000000000000",
        "A396C59A96AF3B36D364448C7B687FB1"
    },
    {
        "000000000000000000000000000000000000000000000000000000",
        "65435A5D117AA6B052A5F737D9946A7B"
    },
    {
        "00000000000000000000000000000000000000000000000000000000",
        "1C9E99E48A495FE81D388FDB4900E59F"
    },
    {
        "0000000000000000000000000000000000000000000000000000000000",
        "4AA476A72347BA44C9BD20C974D0F181"
    },
    {
        "000000000000000000000000000000000000000000000000000000000000",
        "862DEC5C27142824A394BC6464928F48"
    },
    {
        "00000000000000000000000000000000000000000000000000000000000000",
        "3861FACEE9EFC127E340387F1936B8FB"
    },
    {
        "0000000000000000000000000000000000000000000000000000000000000000",
        "70BC8F4B72A86921468BF8E8441DCE51"
    },
    {
        "000000000000000000000000000000000000000000000000000000000000000000",
        "099A150E83972A433492A59C2FBE98E0"
    },
    {
        "00000000000000000000000000000000000000000000000000000000000000000000",
        "0B91F1D54F932DC6382DC69F197900CF"
    },
    {
        "0000000000000000000000000000000000000000000000000000000000000000000000",
        "C54104D7894A1941CA710981DA437F9F"
    },
    {
        "000000000000000000000000000000000000000000000000000000000000000000000000",
        "81684C2E68ADE2CD4BF9F2E8A67DD4FE"
    },
    {
        "00000000000000000000000000000000000000000000000000000000000000000000000000",
        "21E2E8FE686ED0003B67D698B1273481"
    },
    {
        "0000000000000000000000000000000000000000000000000000000000000000000000000000",
        "F3A534D52E3FE0C7A85B30CA00CA7424"
    },
    {
        "000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "002D5910DE023EDDCE8358EDF169C07F"
    },
    {
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "FD4B38E94292E00251B9F39C47EE5710"
    },
    {
        "0000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "F5CFD73023C1EEDB6B9569736073F1DD"
    },
    {
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "C183857770364B05C2011BDEBB914ED3"
    },
    {
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "AEA2FA668453E23C431649801E5EA548"
    },
    {
        "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "3E5CEB07F51A70D9D431714F04C0272F"
    },
    {
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "7622214B8536AFE7B89B1C6606069B0D"
    },
    {
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "D898504A722BFF1524134C6AB6A5EAA5"
    },
    {
        "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "0D7DB7FF842F89A36B58FA2541DE2A6C"
    },
    {
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "B203621A65475445E6FCDCA717C667B5"
    },
    {
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "884BB48A55DA67B4812805CB8905277D"
    },
    {
        "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "871BDD96B159C14D15C8D97D9111E9C8"
    },
    {
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "E2365BC6A6FBD41287FAE648437296FA"
    },
    {
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "469AA816010C9C8639A9176F625189AF"
    },
    {
        "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "ECA0470178275AC94E5DE381969ED232"
    },
    {
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "8910E6FC12F07A52B796EB55FBF3EDDA"
    },
    {
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "C9EA3314B91C9FD4E38F9432064FD1F2"
    },
    {
        "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "E3C4DD21A9171FD39D208EFA09BF7883"
    },
    {
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "AB9D8EF2FFA9145D6C325CEFA41D5D4E"
    },
    {
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "2C1CF4F76FA1CECC0C4737CFD8D95118"
    },
    {
        "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "22031453E4C3A1A0D47B0B97D83D8984"
    },
    {
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "A302A771EE0E3127B8950F0A67D17E49"
    },
    {
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "E2A482A3896964675811DBA0BFDE2F0B"
    },
    {
        "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "8D7D1020185F9B09CC22E789887BE328"
    },
    {
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "65CECFB980D72FDE57D175D6EC1C3F64"
    },
    {
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "3B5D3C7D207E37DCEEEDD301E35E2E58"
    },
    {
        "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "1EF5E829303A139CE967440E0CDCA10C"
    },
    {
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "402535C9F22FF836EA91DD12E8B8847B"
    },
    {
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "53553242D57214AAA5726A09B05FE7BC"
    },
    {
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "3287282FA1A1523A294FB018E3679872"
    },
    {
        "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "2F0F98115F17F2869C1F59BA804AF077"
    },
    {
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "AC3B5A19643EE5816A1DF17F2FADAAE3"
    },
    {
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "FA67AB9184F8D574CEF7CD8E0B2F1A78"
    },
    {
        "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "AA6672FE9E8426F8DD570C81095E1476"
    },
    {
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "6E36BA0FE61F7C6334305D61299C04CF"
    },
    {
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "E6B62B76FB2EB2A0E0ADDE0C067DA680"
    },
    {
        "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "2B62A30906A2B8BF3B68ABD2EF9D105B"
    },
    {
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "B79ABF5C5F2244956C7246E9112595CE"
    },
    {
        "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "55712F2F2F21A8321B9EE45D40B89091"
    },
    {
        "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "BBF7C6077962A7C28114DBD10BE947CD"
    },
    {
        "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "9546C10433C45BFB9947449DD8D304DE"
    }
};

static HmacTestCtx md5_hmac_test_text[] = {
    {
        "Hi There",
        "0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b0b",
        "9294727a3638bb1c13f48ef8158bfc9d",
    },
    {
        "Test With Truncation",
        "0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c0c",
        "56461ef2342edc00f9bab995690efd4c",
    },
    {
        "Test Using Larger Than Block-Size Key - Hash Key First",
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
        "6b1ab7fe4bd7bf8f0b62e6ce61b9d0cd",
    },
    {
        "Test Using Larger Than Block-Size Key and Larger Than One Block-Size Data",
        "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
        "6f630fad67cda0ee1fb1f562db3aa53e",
    }
};

static void test_md5_core(HashTestCtx *test_data)
{
    ByteArray *data = ba_alloc_from_le_hex_string(test_data->data);
    ByteArray *expected = ba_alloc_from_le_hex_string(test_data->hash);
    ByteArray *actual = NULL;
    Md5Ctx *ctx = NULL;

    ctx = md5_alloc();
    ASSERT_RET_OK(md5_update(ctx, data));
    ASSERT_RET_OK(md5_final(ctx, &actual));

    CHECK_EQUALS_BA(expected, actual);

cleanup:

    BA_FREE(data, expected, actual);
    md5_free(ctx);
}

static void test_md5_hmac_core(HmacTestCtx *test_data)
{
    ByteArray *data = ba_alloc_from_str(test_data->data);
    ByteArray *key = ba_alloc_from_le_hex_string(test_data->key);
    ByteArray *expected = ba_alloc_from_le_hex_string(test_data->expected);
    ByteArray *actual = NULL;
    HmacCtx *ctx = NULL;

    ASSERT_NOT_NULL(ctx = hmac_alloc_md5());
    ASSERT_RET_OK(hmac_init(ctx, key));
    ASSERT_RET_OK(hmac_update(ctx, data));
    ASSERT_RET_OK(hmac_final(ctx, &actual));

    CHECK_EQUALS_BA(expected, actual);

cleanup:

    BA_FREE(data, expected, actual, key);
    hmac_free(ctx);
}

void atest_md5(void)
{
    size_t err_count = error_count;

    ATEST_CORE(md5_data, test_md5_core, sizeof(HashTestCtx));
    ATEST_CORE(md5_hmac_test_text, test_md5_hmac_core, sizeof(HmacTestCtx));

    if (err_count == error_count) {
        msg_print_atest("MD5", "[hash, hmac]", "OK");
    } else {
        msg_print_atest("MD5", "", "FAILED");
    }
}
