/*
 * Copyright (C) 2010-2012 Free Software Foundation, Inc.
 *
 * Author: Brad Hards
 *
 * Based on certder.c, written by Simon Josefsson
 *
 * This file is part of GnuTLS.
 *
 * GnuTLS is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * GnuTLS is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GnuTLS.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "gnutls/gnutls.h"
#include "gnutls/x509.h"
#include "utils.h"

void doit(void)
{
	int ret;
	unsigned char der[] = {
		0x30, 0x82, 0x03, 0x00, 0x30, 0x82, 0x01, 0xec, 0xa0, 0x03,
		0x02, 0x01, 0x02, 0x02, 0x10, 0xbd, 0x76, 0xdf, 0x42, 0x47,
		0x0a, 0x00, 0x8d, 0x47, 0x3e, 0x74, 0x3f, 0xa1, 0xdc, 0x8b,
		0xbd, 0x30, 0x09, 0x06, 0x05, 0x2b, 0x0e, 0x03, 0x02, 0x1d,
		0x05, 0x00, 0x30, 0x2d, 0x31, 0x2b, 0x30, 0x29, 0x06, 0x03,
		0x55, 0x04, 0x03, 0x13, 0x22, 0x77, 0x00, 0x32, 0x00, 0x6b,
		0x00, 0x38, 0x00, 0x72, 0x00, 0x32, 0x00, 0x2e, 0x00, 0x6d,
		0x00, 0x61, 0x00, 0x74, 0x00, 0x77, 0x00, 0x73, 0x00, 0x2e,
		0x00, 0x6e, 0x00, 0x65, 0x00, 0x74, 0x00, 0x00, 0x00, 0x30,
		0x1e, 0x17, 0x0d, 0x31, 0x30, 0x30, 0x34, 0x32, 0x38, 0x31,
		0x31, 0x34, 0x31, 0x35, 0x34, 0x5a, 0x17, 0x0d, 0x31, 0x31,
		0x30, 0x34, 0x32, 0x38, 0x31, 0x31, 0x34, 0x31, 0x35, 0x34,
		0x5a, 0x30, 0x2d, 0x31, 0x2b, 0x30, 0x29, 0x06, 0x03, 0x55,
		0x04, 0x03, 0x13, 0x22, 0x77, 0x00, 0x32, 0x00, 0x6b, 0x00,
		0x38, 0x00, 0x72, 0x00, 0x32, 0x00, 0x2e, 0x00, 0x6d, 0x00,
		0x61, 0x00, 0x74, 0x00, 0x77, 0x00, 0x73, 0x00, 0x2e, 0x00,
		0x6e, 0x00, 0x65, 0x00, 0x74, 0x00, 0x00, 0x00, 0x30, 0x82,
		0x01, 0x22, 0x30, 0x0d, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86,
		0xf7, 0x0d, 0x01, 0x01, 0x01, 0x05, 0x00, 0x03, 0x82, 0x01,
		0x0f, 0x00, 0x30, 0x82, 0x01, 0x0a, 0x02, 0x82, 0x01, 0x01,
		0x00, 0xaa, 0xd7, 0x32, 0x26, 0xd7, 0xfc, 0x69, 0x57, 0x4a,
		0x55, 0x08, 0x2b, 0x97, 0xc1, 0x5b, 0x90, 0xfd, 0xe8, 0xf5,
		0xf7, 0x9e, 0x7d, 0x34, 0xce, 0xe9, 0xbb, 0x38, 0xa0, 0x9f,
		0xec, 0x84, 0x86, 0x3e, 0x47, 0x2e, 0x71, 0xd7, 0xc3, 0xbf,
		0x89, 0xf3, 0x80, 0xb5, 0x77, 0x80, 0xd3, 0xb0, 0x56, 0x6b,
		0x9c, 0xf4, 0xd3, 0x42, 0x2b, 0x26, 0x01, 0x5c, 0x42, 0xef,
		0xf6, 0x51, 0x5a, 0xaa, 0x55, 0x6b, 0x30, 0xd3, 0x2c, 0xdc,
		0xde, 0x36, 0x4d, 0xdd, 0xf3, 0x5f, 0x59, 0xba, 0x57, 0xd8,
		0x39, 0x0f, 0x5b, 0xd3, 0xe1, 0x34, 0x39, 0x22, 0xaa, 0x71,
		0x10, 0x59, 0x7a, 0xec, 0x9f, 0x1a, 0xf5, 0xa9, 0x40, 0xd6,
		0x7b, 0x32, 0x5f, 0x19, 0x85, 0xc0, 0xfd, 0xa6, 0x6c, 0x32,
		0x58, 0xdc, 0x7c, 0x07, 0x42, 0x36, 0xd0, 0x57, 0x78, 0x63,
		0x60, 0x92, 0x1d, 0x1f, 0x9d, 0xbd, 0xcc, 0xd7, 0xe3, 0x1a,
		0x57, 0xdb, 0x70, 0x80, 0x89, 0x36, 0x39, 0x01, 0x71, 0x5a,
		0x2a, 0x05, 0x25, 0x13, 0x80, 0xf8, 0x49, 0x48, 0x5f, 0x06,
		0xd0, 0xcb, 0x2c, 0x58, 0x9a, 0xe7, 0x8b, 0x6d, 0x17, 0x2c,
		0xb2, 0x97, 0x2c, 0x15, 0xc9, 0x73, 0x6d, 0x8f, 0x4f, 0xf3,
		0xf1, 0xb9, 0x70, 0x3f, 0xcb, 0x5f, 0x80, 0x85, 0x8b, 0xdf,
		0xd2, 0x05, 0x95, 0x1c, 0xe4, 0x37, 0xee, 0xd2, 0x62, 0x49,
		0x08, 0xdf, 0xf6, 0x02, 0xec, 0xe6, 0x9a, 0x37, 0xfc, 0x21,
		0x7a, 0x98, 0x12, 0x1d, 0x79, 0xbf, 0xc7, 0x0f, 0x0a, 0x20,
		0xf8, 0xef, 0xa5, 0xc6, 0x0e, 0x94, 0x5e, 0x17, 0x94, 0x12,
		0x42, 0xfe, 0xd7, 0x22, 0xbd, 0x31, 0x27, 0xc7, 0xdb, 0x4a,
		0x4e, 0x95, 0xe2, 0xc1, 0xdd, 0xe8, 0x0f, 0x7d, 0x1d, 0xe4,
		0xfd, 0xb1, 0x27, 0x7b, 0xc1, 0x71, 0xfe, 0x27, 0x47, 0x89,
		0xf4, 0xfc, 0x84, 0xa5, 0x57, 0x5d, 0x21, 0x02, 0x03, 0x01,
		0x00, 0x01, 0x81, 0x11, 0x00, 0xbd, 0x8b, 0xdc, 0xa1, 0x3f,
		0x74, 0x3e, 0x47, 0x8d, 0x00, 0x0a, 0x47, 0x42, 0xdf, 0x76,
		0xbd, 0x82, 0x11, 0x00, 0xbd, 0x8b, 0xdc, 0xa1, 0x3f, 0x74,
		0x3e, 0x47, 0x8d, 0x00, 0x0a, 0x47, 0x42, 0xdf, 0x76, 0xbd,
		0x30, 0x09, 0x06, 0x05, 0x2b, 0x0e, 0x03, 0x02, 0x1d, 0x05,
		0x00, 0x03, 0x82, 0x01, 0x01, 0x00, 0xa7, 0xb0, 0x66, 0x75,
		0x14, 0x7e, 0x7d, 0xb5, 0x31, 0xec, 0xb2, 0xeb, 0x90, 0x80,
		0x95, 0x25, 0x59, 0x0f, 0xe4, 0x15, 0x86, 0x2d, 0x9d, 0xd7,
		0x35, 0xe9, 0x22, 0x74, 0xe7, 0x85, 0x36, 0x19, 0x4f, 0x27,
		0x5c, 0x17, 0x63, 0x7b, 0x2a, 0xfe, 0x59, 0xe9, 0x76, 0x77,
		0xd0, 0xc9, 0x40, 0x78, 0x7c, 0x31, 0x62, 0x1e, 0x87, 0x1b,
		0xc1, 0x19, 0xef, 0x6f, 0x15, 0xe6, 0xce, 0x74, 0x84, 0x6d,
		0xd6, 0x3b, 0x57, 0xd9, 0xa9, 0x13, 0xf6, 0x7d, 0x84, 0xe7,
		0x8f, 0xc6, 0x01, 0x5f, 0xcf, 0xc4, 0x95, 0xc9, 0xde, 0x97,
		0x17, 0x43, 0x12, 0x70, 0x27, 0xf9, 0xc4, 0xd7, 0xe1, 0x05,
		0xbb, 0x63, 0x87, 0x5f, 0xdc, 0x20, 0xbd, 0xd1, 0xde, 0xd6,
		0x2d, 0x9f, 0x3f, 0x5d, 0x0a, 0x27, 0x40, 0x11, 0x5f, 0x5d,
		0x54, 0xa7, 0x28, 0xf9, 0x03, 0x2e, 0x84, 0x8d, 0x48, 0x60,
		0xa1, 0x71, 0xa3, 0x46, 0x69, 0xdb, 0x88, 0x7b, 0xc1, 0xb6,
		0x08, 0x2d, 0xdf, 0x25, 0x9d, 0x32, 0x76, 0x49, 0x0b, 0xba,
		0xab, 0xdd, 0xc3, 0x00, 0x76, 0x8a, 0x94, 0xd2, 0x25, 0x43,
		0xf0, 0xa9, 0x98, 0x65, 0x94, 0xc7, 0xdd, 0x7c, 0xd4, 0xe2,
		0xe8, 0x33, 0xe2, 0x9a, 0xe9, 0x75, 0xf0, 0x0f, 0x61, 0x86,
		0xee, 0x0e, 0xf7, 0x39, 0x6b, 0x30, 0x63, 0xe5, 0x46, 0xd4,
		0x1c, 0x83, 0xa1, 0x28, 0x79, 0x76, 0x81, 0x48, 0x38, 0x72,
		0xbc, 0x3f, 0x25, 0x53, 0x31, 0xaa, 0x02, 0xd1, 0x9b, 0x03,
		0xa2, 0x5c, 0x94, 0x21, 0xb3, 0x8e, 0xdf, 0x2a, 0xa5, 0x4c,
		0x65, 0xa2, 0xf9, 0xac, 0x38, 0x7a, 0xf9, 0x45, 0xb3, 0xd5,
		0xda, 0xe5, 0xb9, 0x56, 0x9e, 0x47, 0xd5, 0x06, 0xe6, 0xca,
		0xd7, 0x6e, 0x06, 0xdb, 0x6e, 0xa7, 0x7b, 0x4b, 0x13, 0x40,
		0x3c, 0x12, 0x76, 0x99, 0x65, 0xb4, 0x54, 0xa1, 0xd8, 0x21,
		0x5c, 0x27
	};

	gnutls_datum_t derCert = { der, sizeof(der) };

	gnutls_x509_crt_t cert;

	int result;
	unsigned char expectedId[] = { 0xbd, 0x8b, 0xdc, 0xa1, 0x3f, 0x74,
				       0x3e, 0x47, 0x8d, 0x00, 0x0a, 0x47,
				       0x42, 0xdf, 0x76, 0xbd };

	char buf[17];
	size_t buf_size;

	ret = global_init();
	if (ret < 0)
		fail("init %d\n", ret);

	ret = gnutls_x509_crt_init(&cert);
	if (ret < 0)
		fail("crt_init %d\n", ret);

	ret = gnutls_x509_crt_import(cert, &derCert, GNUTLS_X509_FMT_DER);
	if (ret < 0)
		fail("crt_import %d\n", ret);

	buf_size = 15;
	result = gnutls_x509_crt_get_issuer_unique_id(cert, buf, &buf_size);
	if (result != GNUTLS_E_SHORT_MEMORY_BUFFER)
		fail("get_issuer_unique_id short error %d\n", result);
	if (buf_size != 16)
		fail("get_issuer_unique_id buf size %d\n", (int)buf_size);

	buf_size = 16;
	result = gnutls_x509_crt_get_issuer_unique_id(cert, buf, &buf_size);
	if (result < 0)
		fail("get_issuer_unique_id %d\n", result);
	if (memcmp(buf, expectedId, buf_size) != 0)
		fail("expected id mismatch for issuer\n");

	buf_size = 15;
	result = gnutls_x509_crt_get_subject_unique_id(cert, buf, &buf_size);
	if (result != GNUTLS_E_SHORT_MEMORY_BUFFER)
		fail("get_subject_unique_id short error %d\n", result);
	if (buf_size != 16)
		fail("get_subject_unique_id buf size %d\n", (int)buf_size);

	buf_size = 16;
	result = gnutls_x509_crt_get_subject_unique_id(cert, buf, &buf_size);
	if (result < 0)
		fail("get_subject_unique_id %d\n", result);
	if (memcmp(buf, expectedId, buf_size) != 0)
		fail("expected id mismatch for subject\n");

	gnutls_x509_crt_deinit(cert);

	gnutls_global_deinit();
}
