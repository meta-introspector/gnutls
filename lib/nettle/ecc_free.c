/* LibTomCrypt, modular cryptographic library -- Tom St Denis
 *
 * LibTomCrypt is a library that provides various cryptographic
 * algorithms in a highly modular and flexible manner.
 *
 * The library is free for all purposes without any express
 * guarantee it works.
 *
 * Tom St Denis, tomstdenis@gmail.com, http://libtom.org
 */

/* Implements ECC over Z/pZ for curve y^2 = x^3 + ax + b
 *
 * All curves taken from NIST recommendation paper of July 1999
 * Available at http://csrc.nist.gov/cryptval/dss.htm
 */
#include "ecc.h"

/**
  @file ecc_free.c
  ECC Crypto, Tom St Denis
*/

/**
  Free an ECC key from memory
  @param key   The key you wish to free
*/
void
ecc_free (ecc_key * key)
{
  assert (key != NULL);
  mp_clear_multi (&key->pubkey.x, &key->pubkey.y, &key->pubkey.z, &key->k,
                  &key->prime, &key->order, &key->Gx, &key->Gy, NULL);
}

/* $Source: /cvs/libtom/libtomcrypt/src/pk/ecc/ecc_free.c,v $ */
/* $Revision: 1.6 $ */
/* $Date: 2007/05/12 14:32:35 $ */
