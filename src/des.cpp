#include <iostream>
#include <vector>
#include <algorithm>
#include "../include/des.h"
#include "../include/util.h"

asu::des::des(uint64_t key)
{
  /* initial key schedule calculation */
  for (i = 0; i < 56; i++)
  {

    permuted_choice_1 <<= 1;
    permuted_choice_1 |= (key >> (64 - PC1[i])) & LB64_MASK;
  }

  C = (uint32_t)((permuted_choice_1 >> 28) & 0x000000000fffffff);
  D = (uint32_t)(permuted_choice_1 & 0x000000000fffffff);

  /* Calculation of the 16 keys */
  for (i = 0; i < 16; i++)
  {

    /* key schedule */
    // shifting Ci and Di
    for (j = 0; j < iteration_shift[i]; j++)
    {

      C = 0x0fffffff & (C << 1) | 0x00000001 & (C >> 27);
      D = 0x0fffffff & (D << 1) | 0x00000001 & (D >> 27);
    }

    permuted_choice_2 = 0;
    permuted_choice_2 = (((uint64_t)C) << 28) | (uint64_t)D;

    sub_key[i] = 0;

    for (j = 0; j < 48; j++)
    {
      sub_key[i] <<= 1;
      sub_key[i] |= (permuted_choice_2 >> (56 - PC2[j])) & LB64_MASK;
    }
  }
}

uint64_t asu::des::encrypt(uint64_t input)
{

  /* initial permutation */
  for (i = 0; i < 64; i++)
  {

    init_perm_res <<= 1;
    init_perm_res |= (input >> (64 - IP[i])) & LB64_MASK;
  }
  L = (uint32_t)(init_perm_res >> 32) & L64_MASK;
  R = (uint32_t)init_perm_res & L64_MASK;

  for (i = 0; i < 16; i++)
  {

    /* f(R,k) function */
    s_input = 0;

    for (j = 0; j < 48; j++)
    {

      s_input <<= 1;
      s_input |= (uint64_t)((R >> (32 - E[j])) & LB32_MASK);
    }

    /* 
         * Encryption/Decryption 
         * XORing expanded Ri with Ki
         */

    s_input = s_input ^ sub_key[i];

    /* S-Box Tables */
    for (j = 0; j < 8; j++)
    {
      // 00 00 RCCC CR00 00 00 00 00 00 s_input
      // 00 00 1000 0100 00 00 00 00 00 row mask
      // 00 00 0111 1000 00 00 00 00 00 column mask

      row = (char)((s_input & (0x0000840000000000 >> 6 * j)) >> 42 - 6 * j);
      row = (row >> 4) | row & 0x01;

      column = (char)((s_input & (0x0000780000000000 >> 6 * j)) >> 43 - 6 * j);

      s_output <<= 4;
      s_output |= (uint32_t)(S[j][16 * row + column] & 0x0f);
    }

    f_function_res = 0;

    for (j = 0; j < 32; j++)
    {

      f_function_res <<= 1;
      f_function_res |= (s_output >> (32 - P[j])) & LB32_MASK;
    }

    temp = R;
    R = L ^ f_function_res;
    L = temp;
  }

  pre_output = (((uint64_t)R) << 32) | (uint64_t)L;

  for (int i = 0; i < 64; i++)
  {

    inv_init_perm_res <<= 1;
    inv_init_perm_res |= (pre_output >> (64 - PI[i])) & LB64_MASK;
  }

  return inv_init_perm_res;
}

uint64_t asu::des::decrypt(uint64_t input)
{

  /* initial permutation */
  for (i = 0; i < 64; i++)
  {

    init_perm_res <<= 1;
    init_perm_res |= (input >> (64 - IP[i])) & LB64_MASK;
  }

  L = (uint32_t)(init_perm_res >> 32) & L64_MASK;
  R = (uint32_t)init_perm_res & L64_MASK;

  for (i = 0; i < 16; i++)
  {

    /* f(R,k) function */
    s_input = 0;

    for (j = 0; j < 48; j++)
    {

      s_input <<= 1;
      s_input |= (uint64_t)((R >> (32 - E[j])) & LB32_MASK);
    }

    /* 
         * Encryption/Decryption 
         * XORing expanded Ri with Ki
         */

    s_input = s_input ^ sub_key[15 - i];

    /* S-Box Tables */
    for (j = 0; j < 8; j++)
    {
      // 00 00 RCCC CR00 00 00 00 00 00 s_input
      // 00 00 1000 0100 00 00 00 00 00 row mask
      // 00 00 0111 1000 00 00 00 00 00 column mask

      row = (char)((s_input & (0x0000840000000000 >> 6 * j)) >> 42 - 6 * j);
      row = (row >> 4) | row & 0x01;

      column = (char)((s_input & (0x0000780000000000 >> 6 * j)) >> 43 - 6 * j);

      s_output <<= 4;
      s_output |= (uint32_t)(S[j][16 * row + column] & 0x0f);
    }

    f_function_res = 0;

    for (j = 0; j < 32; j++)
    {

      f_function_res <<= 1;
      f_function_res |= (s_output >> (32 - P[j])) & LB32_MASK;
    }

    temp = R;
    R = L ^ f_function_res;
    L = temp;
  }

  pre_output = (((uint64_t)R) << 32) | (uint64_t)L;

  for (int i = 0; i < 64; i++)
  {

    inv_init_perm_res <<= 1;
    inv_init_perm_res |= (pre_output >> (64 - PI[i])) & LB64_MASK;
  }

  return inv_init_perm_res;
}
