/* MIT License
 *
 * Copyright (c) 2016-2020 INRIA, CMU and Microsoft Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#include "Hacl_Streaming_Blake2.h"

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_no_key_create_in */

/*
  State allocation function when there is no key
*/
Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____
*Hacl_Streaming_Blake2_blake2s_32_no_key_create_in()
{
  uint8_t *buf = KRML_HOST_CALLOC((uint32_t)64U, sizeof (uint8_t));
  uint32_t *wv = KRML_HOST_CALLOC((uint32_t)16U, sizeof (uint32_t));
  uint32_t *b = KRML_HOST_CALLOC((uint32_t)16U, sizeof (uint32_t));
  K____uint32_t___uint32_t_ block_state = { .fst = wv, .snd = b };
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____
  s1 = { .block_state = block_state, .buf = buf, .total_len = (uint64_t)0U };
  KRML_CHECK_SIZE(sizeof (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____),
    (uint32_t)1U);
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____
  *p = KRML_HOST_MALLOC(sizeof (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____));
  p[0U] = s1;
  Hacl_Blake2s_32_blake2s_init(block_state.fst,
    block_state.snd,
    (uint32_t)0U,
    NULL,
    (uint32_t)32U);
  return p;
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_no_key_create_in */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_no_key_update */

/*
  Update function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2s_32_no_key_update(
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ *p,
  uint8_t *data,
  uint32_t len
)
{
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ s1 = *p;
  uint64_t total_len = s1.total_len;
  uint32_t sz;
  if (total_len % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    sz = (uint32_t)64U;
  }
  else
  {
    sz = (uint32_t)(total_len % (uint64_t)(uint32_t)64U);
  }
  if (len <= (uint32_t)64U - sz)
  {
    Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ s2 = *p;
    K____uint32_t___uint32_t_ block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)64U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
    }
    uint8_t *buf2 = buf + sz1;
    memcpy(buf2, data, len * sizeof (uint8_t));
    uint64_t total_len2 = total_len1 + (uint64_t)len;
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len2
        }
      );
    return;
  }
  if (sz == (uint32_t)0U)
  {
    Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ s2 = *p;
    K____uint32_t___uint32_t_ block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)64U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
    }
    if (!(sz1 == (uint32_t)0U))
    {
      uint64_t prevlen = total_len1 - (uint64_t)sz1;
      uint32_t nb = (uint32_t)1U;
      uint64_t ite;
      if ((uint32_t)0U == (uint32_t)0U)
      {
        ite = prevlen;
      }
      else
      {
        ite = prevlen + (uint64_t)(uint32_t)64U;
      }
      Hacl_Blake2s_32_blake2s_update_multi((uint32_t)64U,
        block_state1.fst,
        block_state1.snd,
        ite,
        buf,
        nb);
    }
    uint32_t ite0;
    if ((uint64_t)len % (uint64_t)(uint32_t)64U == (uint64_t)0U && (uint64_t)len > (uint64_t)0U)
    {
      ite0 = (uint32_t)64U;
    }
    else
    {
      ite0 = (uint32_t)((uint64_t)len % (uint64_t)(uint32_t)64U);
    }
    uint32_t n_blocks = (len - ite0) / (uint32_t)64U;
    uint32_t data1_len = n_blocks * (uint32_t)64U;
    uint32_t data2_len = len - data1_len;
    uint8_t *data1 = data;
    uint8_t *data2 = data + data1_len;
    uint32_t nb = data1_len / (uint32_t)64U;
    uint64_t ite;
    if ((uint32_t)0U == (uint32_t)0U)
    {
      ite = total_len1;
    }
    else
    {
      ite = total_len1 + (uint64_t)(uint32_t)64U;
    }
    Hacl_Blake2s_32_blake2s_update_multi(data1_len,
      block_state1.fst,
      block_state1.snd,
      ite,
      data1,
      nb);
    uint8_t *dst = buf;
    memcpy(dst, data2, data2_len * sizeof (uint8_t));
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len1 + (uint64_t)len
        }
      );
    return;
  }
  uint32_t diff = (uint32_t)64U - sz;
  uint8_t *data1 = data;
  uint8_t *data2 = data + diff;
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ s2 = *p;
  K____uint32_t___uint32_t_ block_state10 = s2.block_state;
  uint8_t *buf0 = s2.buf;
  uint64_t total_len10 = s2.total_len;
  uint32_t sz10;
  if (total_len10 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len10 > (uint64_t)0U)
  {
    sz10 = (uint32_t)64U;
  }
  else
  {
    sz10 = (uint32_t)(total_len10 % (uint64_t)(uint32_t)64U);
  }
  uint8_t *buf2 = buf0 + sz10;
  memcpy(buf2, data1, diff * sizeof (uint8_t));
  uint64_t total_len2 = total_len10 + (uint64_t)diff;
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____){
        .block_state = block_state10,
        .buf = buf0,
        .total_len = total_len2
      }
    );
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ s20 = *p;
  K____uint32_t___uint32_t_ block_state1 = s20.block_state;
  uint8_t *buf = s20.buf;
  uint64_t total_len1 = s20.total_len;
  uint32_t sz1;
  if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
  {
    sz1 = (uint32_t)64U;
  }
  else
  {
    sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
  }
  if (!(sz1 == (uint32_t)0U))
  {
    uint64_t prevlen = total_len1 - (uint64_t)sz1;
    uint32_t nb = (uint32_t)1U;
    uint64_t ite;
    if ((uint32_t)0U == (uint32_t)0U)
    {
      ite = prevlen;
    }
    else
    {
      ite = prevlen + (uint64_t)(uint32_t)64U;
    }
    Hacl_Blake2s_32_blake2s_update_multi((uint32_t)64U,
      block_state1.fst,
      block_state1.snd,
      ite,
      buf,
      nb);
  }
  uint32_t ite0;
  if
  (
    (uint64_t)(len - diff)
    % (uint64_t)(uint32_t)64U
    == (uint64_t)0U
    && (uint64_t)(len - diff) > (uint64_t)0U
  )
  {
    ite0 = (uint32_t)64U;
  }
  else
  {
    ite0 = (uint32_t)((uint64_t)(len - diff) % (uint64_t)(uint32_t)64U);
  }
  uint32_t n_blocks = (len - diff - ite0) / (uint32_t)64U;
  uint32_t data1_len = n_blocks * (uint32_t)64U;
  uint32_t data2_len = len - diff - data1_len;
  uint8_t *data11 = data2;
  uint8_t *data21 = data2 + data1_len;
  uint32_t nb = data1_len / (uint32_t)64U;
  uint64_t ite;
  if ((uint32_t)0U == (uint32_t)0U)
  {
    ite = total_len1;
  }
  else
  {
    ite = total_len1 + (uint64_t)(uint32_t)64U;
  }
  Hacl_Blake2s_32_blake2s_update_multi(data1_len,
    block_state1.fst,
    block_state1.snd,
    ite,
    data11,
    nb);
  uint8_t *dst = buf;
  memcpy(dst, data21, data2_len * sizeof (uint8_t));
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____){
        .block_state = block_state1,
        .buf = buf,
        .total_len = total_len1 + (uint64_t)(len - diff)
      }
    );
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_no_key_update */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_no_key_finish */

/*
  Finish function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2s_32_no_key_finish(
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ *p,
  uint8_t *dst
)
{
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ scrut = *p;
  K____uint32_t___uint32_t_ block_state = scrut.block_state;
  uint8_t *buf_ = scrut.buf;
  uint64_t total_len = scrut.total_len;
  uint32_t r;
  if (total_len % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    r = (uint32_t)64U;
  }
  else
  {
    r = (uint32_t)(total_len % (uint64_t)(uint32_t)64U);
  }
  uint8_t *buf_1 = buf_;
  KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
  uint32_t wv[(uint32_t)4U * (uint32_t)4U];
  memset(wv, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (uint32_t));
  KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
  uint32_t b[(uint32_t)4U * (uint32_t)4U];
  memset(b, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (uint32_t));
  K____uint32_t___uint32_t_ tmp_block_state = { .fst = wv, .snd = b };
  uint32_t *src_b = block_state.snd;
  uint32_t *dst_b = tmp_block_state.snd;
  memcpy(dst_b, src_b, (uint32_t)16U * sizeof (uint32_t));
  uint64_t prev_len = total_len - (uint64_t)r;
  uint64_t ite;
  if ((uint32_t)0U == (uint32_t)0U)
  {
    ite = prev_len;
  }
  else
  {
    ite = prev_len + (uint64_t)(uint32_t)64U;
  }
  Hacl_Blake2s_32_blake2s_update_last(r,
    tmp_block_state.fst,
    tmp_block_state.snd,
    ite,
    r,
    buf_1);
  Hacl_Blake2s_32_blake2s_finish((uint32_t)32U, dst, tmp_block_state.snd);
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_no_key_finish */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_no_key_free */

/*
  Free state function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2s_32_no_key_free(
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ *s1
)
{
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ scrut = *s1;
  uint8_t *buf = scrut.buf;
  K____uint32_t___uint32_t_ block_state = scrut.block_state;
  uint32_t *wv = block_state.fst;
  uint32_t *b = block_state.snd;
  KRML_HOST_FREE(wv);
  KRML_HOST_FREE(b);
  KRML_HOST_FREE(buf);
  KRML_HOST_FREE(s1);
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_no_key_free */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_no_key_create_in */

/*
  State allocation function when there is no key
*/
Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____
*Hacl_Streaming_Blake2_blake2b_32_no_key_create_in()
{
  uint8_t *buf = KRML_HOST_CALLOC((uint32_t)128U, sizeof (uint8_t));
  uint64_t *wv = KRML_HOST_CALLOC((uint32_t)16U, sizeof (uint64_t));
  uint64_t *b = KRML_HOST_CALLOC((uint32_t)16U, sizeof (uint64_t));
  K____uint64_t___uint64_t_ block_state = { .fst = wv, .snd = b };
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____
  s1 = { .block_state = block_state, .buf = buf, .total_len = (uint64_t)0U };
  KRML_CHECK_SIZE(sizeof (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____),
    (uint32_t)1U);
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____
  *p = KRML_HOST_MALLOC(sizeof (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____));
  p[0U] = s1;
  Hacl_Blake2b_32_blake2b_init(block_state.fst,
    block_state.snd,
    (uint32_t)0U,
    NULL,
    (uint32_t)64U);
  return p;
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_no_key_create_in */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_no_key_update */

/*
  Update function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2b_32_no_key_update(
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ *p,
  uint8_t *data,
  uint32_t len
)
{
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ s1 = *p;
  uint64_t total_len = s1.total_len;
  uint32_t sz;
  if (total_len % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    sz = (uint32_t)128U;
  }
  else
  {
    sz = (uint32_t)(total_len % (uint64_t)(uint32_t)128U);
  }
  if (len <= (uint32_t)128U - sz)
  {
    Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ s2 = *p;
    K____uint64_t___uint64_t_ block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)128U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)128U);
    }
    uint8_t *buf2 = buf + sz1;
    memcpy(buf2, data, len * sizeof (uint8_t));
    uint64_t total_len2 = total_len1 + (uint64_t)len;
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len2
        }
      );
    return;
  }
  if (sz == (uint32_t)0U)
  {
    Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ s2 = *p;
    K____uint64_t___uint64_t_ block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)128U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)128U);
    }
    if (!(sz1 == (uint32_t)0U))
    {
      uint64_t prevlen = total_len1 - (uint64_t)sz1;
      uint32_t nb = (uint32_t)1U;
      uint64_t ite;
      if ((uint32_t)0U == (uint32_t)0U)
      {
        ite = prevlen;
      }
      else
      {
        ite = prevlen + (uint64_t)(uint32_t)128U;
      }
      Hacl_Blake2b_32_blake2b_update_multi((uint32_t)128U,
        block_state1.fst,
        block_state1.snd,
        FStar_UInt128_uint64_to_uint128(ite),
        buf,
        nb);
    }
    uint32_t ite0;
    if ((uint64_t)len % (uint64_t)(uint32_t)128U == (uint64_t)0U && (uint64_t)len > (uint64_t)0U)
    {
      ite0 = (uint32_t)128U;
    }
    else
    {
      ite0 = (uint32_t)((uint64_t)len % (uint64_t)(uint32_t)128U);
    }
    uint32_t n_blocks = (len - ite0) / (uint32_t)128U;
    uint32_t data1_len = n_blocks * (uint32_t)128U;
    uint32_t data2_len = len - data1_len;
    uint8_t *data1 = data;
    uint8_t *data2 = data + data1_len;
    uint32_t nb = data1_len / (uint32_t)128U;
    uint64_t ite;
    if ((uint32_t)0U == (uint32_t)0U)
    {
      ite = total_len1;
    }
    else
    {
      ite = total_len1 + (uint64_t)(uint32_t)128U;
    }
    Hacl_Blake2b_32_blake2b_update_multi(data1_len,
      block_state1.fst,
      block_state1.snd,
      FStar_UInt128_uint64_to_uint128(ite),
      data1,
      nb);
    uint8_t *dst = buf;
    memcpy(dst, data2, data2_len * sizeof (uint8_t));
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len1 + (uint64_t)len
        }
      );
    return;
  }
  uint32_t diff = (uint32_t)128U - sz;
  uint8_t *data1 = data;
  uint8_t *data2 = data + diff;
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ s2 = *p;
  K____uint64_t___uint64_t_ block_state10 = s2.block_state;
  uint8_t *buf0 = s2.buf;
  uint64_t total_len10 = s2.total_len;
  uint32_t sz10;
  if (total_len10 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len10 > (uint64_t)0U)
  {
    sz10 = (uint32_t)128U;
  }
  else
  {
    sz10 = (uint32_t)(total_len10 % (uint64_t)(uint32_t)128U);
  }
  uint8_t *buf2 = buf0 + sz10;
  memcpy(buf2, data1, diff * sizeof (uint8_t));
  uint64_t total_len2 = total_len10 + (uint64_t)diff;
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____){
        .block_state = block_state10,
        .buf = buf0,
        .total_len = total_len2
      }
    );
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ s20 = *p;
  K____uint64_t___uint64_t_ block_state1 = s20.block_state;
  uint8_t *buf = s20.buf;
  uint64_t total_len1 = s20.total_len;
  uint32_t sz1;
  if (total_len1 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len1 > (uint64_t)0U)
  {
    sz1 = (uint32_t)128U;
  }
  else
  {
    sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)128U);
  }
  if (!(sz1 == (uint32_t)0U))
  {
    uint64_t prevlen = total_len1 - (uint64_t)sz1;
    uint32_t nb = (uint32_t)1U;
    uint64_t ite;
    if ((uint32_t)0U == (uint32_t)0U)
    {
      ite = prevlen;
    }
    else
    {
      ite = prevlen + (uint64_t)(uint32_t)128U;
    }
    Hacl_Blake2b_32_blake2b_update_multi((uint32_t)128U,
      block_state1.fst,
      block_state1.snd,
      FStar_UInt128_uint64_to_uint128(ite),
      buf,
      nb);
  }
  uint32_t ite0;
  if
  (
    (uint64_t)(len - diff)
    % (uint64_t)(uint32_t)128U
    == (uint64_t)0U
    && (uint64_t)(len - diff) > (uint64_t)0U
  )
  {
    ite0 = (uint32_t)128U;
  }
  else
  {
    ite0 = (uint32_t)((uint64_t)(len - diff) % (uint64_t)(uint32_t)128U);
  }
  uint32_t n_blocks = (len - diff - ite0) / (uint32_t)128U;
  uint32_t data1_len = n_blocks * (uint32_t)128U;
  uint32_t data2_len = len - diff - data1_len;
  uint8_t *data11 = data2;
  uint8_t *data21 = data2 + data1_len;
  uint32_t nb = data1_len / (uint32_t)128U;
  uint64_t ite;
  if ((uint32_t)0U == (uint32_t)0U)
  {
    ite = total_len1;
  }
  else
  {
    ite = total_len1 + (uint64_t)(uint32_t)128U;
  }
  Hacl_Blake2b_32_blake2b_update_multi(data1_len,
    block_state1.fst,
    block_state1.snd,
    FStar_UInt128_uint64_to_uint128(ite),
    data11,
    nb);
  uint8_t *dst = buf;
  memcpy(dst, data21, data2_len * sizeof (uint8_t));
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____){
        .block_state = block_state1,
        .buf = buf,
        .total_len = total_len1 + (uint64_t)(len - diff)
      }
    );
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_no_key_update */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_no_key_finish */

/*
  Finish function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2b_32_no_key_finish(
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ *p,
  uint8_t *dst
)
{
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ scrut = *p;
  K____uint64_t___uint64_t_ block_state = scrut.block_state;
  uint8_t *buf_ = scrut.buf;
  uint64_t total_len = scrut.total_len;
  uint32_t r;
  if (total_len % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    r = (uint32_t)128U;
  }
  else
  {
    r = (uint32_t)(total_len % (uint64_t)(uint32_t)128U);
  }
  uint8_t *buf_1 = buf_;
  KRML_CHECK_SIZE(sizeof (uint64_t), (uint32_t)4U * (uint32_t)4U);
  uint64_t wv[(uint32_t)4U * (uint32_t)4U];
  memset(wv, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (uint64_t));
  KRML_CHECK_SIZE(sizeof (uint64_t), (uint32_t)4U * (uint32_t)4U);
  uint64_t b[(uint32_t)4U * (uint32_t)4U];
  memset(b, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (uint64_t));
  K____uint64_t___uint64_t_ tmp_block_state = { .fst = wv, .snd = b };
  uint64_t *src_b = block_state.snd;
  uint64_t *dst_b = tmp_block_state.snd;
  memcpy(dst_b, src_b, (uint32_t)16U * sizeof (uint64_t));
  uint64_t prev_len = total_len - (uint64_t)r;
  uint64_t ite;
  if ((uint32_t)0U == (uint32_t)0U)
  {
    ite = prev_len;
  }
  else
  {
    ite = prev_len + (uint64_t)(uint32_t)128U;
  }
  Hacl_Blake2b_32_blake2b_update_last(r,
    tmp_block_state.fst,
    tmp_block_state.snd,
    FStar_UInt128_uint64_to_uint128(ite),
    r,
    buf_1);
  Hacl_Blake2b_32_blake2b_finish((uint32_t)64U, dst, tmp_block_state.snd);
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_no_key_finish */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_no_key_free */

/*
  Free state function when there is no key
*/
void
Hacl_Streaming_Blake2_blake2b_32_no_key_free(
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ *s1
)
{
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ scrut = *s1;
  uint8_t *buf = scrut.buf;
  K____uint64_t___uint64_t_ block_state = scrut.block_state;
  uint64_t *wv = block_state.fst;
  uint64_t *b = block_state.snd;
  KRML_HOST_FREE(wv);
  KRML_HOST_FREE(b);
  KRML_HOST_FREE(buf);
  KRML_HOST_FREE(s1);
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_no_key_free */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_with_key_create_in */

/*
  State allocation function when using a (potentially null) key
*/
Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____
*Hacl_Streaming_Blake2_blake2s_32_with_key_create_in(uint32_t key_size, uint8_t *k1)
{
  uint8_t *buf = KRML_HOST_CALLOC((uint32_t)64U, sizeof (uint8_t));
  uint32_t *wv = KRML_HOST_CALLOC((uint32_t)16U, sizeof (uint32_t));
  uint32_t *b = KRML_HOST_CALLOC((uint32_t)16U, sizeof (uint32_t));
  K____uint32_t___uint32_t_ block_state = { .fst = wv, .snd = b };
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____
  s1 = { .block_state = block_state, .buf = buf, .total_len = (uint64_t)0U };
  KRML_CHECK_SIZE(sizeof (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____),
    (uint32_t)1U);
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____
  *p = KRML_HOST_MALLOC(sizeof (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____));
  p[0U] = s1;
  Hacl_Blake2s_32_blake2s_init(block_state.fst, block_state.snd, key_size, k1, (uint32_t)32U);
  return p;
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_with_key_create_in */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_with_key_update */

/*
  Update function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2s_32_with_key_update(
  uint32_t key_size,
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ *p,
  uint8_t *data,
  uint32_t len
)
{
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ s1 = *p;
  uint64_t total_len = s1.total_len;
  uint32_t sz;
  if (total_len % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    sz = (uint32_t)64U;
  }
  else
  {
    sz = (uint32_t)(total_len % (uint64_t)(uint32_t)64U);
  }
  if (len <= (uint32_t)64U - sz)
  {
    Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ s2 = *p;
    K____uint32_t___uint32_t_ block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)64U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
    }
    uint8_t *buf2 = buf + sz1;
    memcpy(buf2, data, len * sizeof (uint8_t));
    uint64_t total_len2 = total_len1 + (uint64_t)len;
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len2
        }
      );
    return;
  }
  if (sz == (uint32_t)0U)
  {
    Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ s2 = *p;
    K____uint32_t___uint32_t_ block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)64U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
    }
    if (!(sz1 == (uint32_t)0U))
    {
      uint64_t prevlen = total_len1 - (uint64_t)sz1;
      uint32_t nb = (uint32_t)1U;
      uint64_t ite;
      if (key_size == (uint32_t)0U)
      {
        ite = prevlen;
      }
      else
      {
        ite = prevlen + (uint64_t)(uint32_t)64U;
      }
      Hacl_Blake2s_32_blake2s_update_multi((uint32_t)64U,
        block_state1.fst,
        block_state1.snd,
        ite,
        buf,
        nb);
    }
    uint32_t ite0;
    if ((uint64_t)len % (uint64_t)(uint32_t)64U == (uint64_t)0U && (uint64_t)len > (uint64_t)0U)
    {
      ite0 = (uint32_t)64U;
    }
    else
    {
      ite0 = (uint32_t)((uint64_t)len % (uint64_t)(uint32_t)64U);
    }
    uint32_t n_blocks = (len - ite0) / (uint32_t)64U;
    uint32_t data1_len = n_blocks * (uint32_t)64U;
    uint32_t data2_len = len - data1_len;
    uint8_t *data1 = data;
    uint8_t *data2 = data + data1_len;
    uint32_t nb = data1_len / (uint32_t)64U;
    uint64_t ite;
    if (key_size == (uint32_t)0U)
    {
      ite = total_len1;
    }
    else
    {
      ite = total_len1 + (uint64_t)(uint32_t)64U;
    }
    Hacl_Blake2s_32_blake2s_update_multi(data1_len,
      block_state1.fst,
      block_state1.snd,
      ite,
      data1,
      nb);
    uint8_t *dst = buf;
    memcpy(dst, data2, data2_len * sizeof (uint8_t));
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len1 + (uint64_t)len
        }
      );
    return;
  }
  uint32_t diff = (uint32_t)64U - sz;
  uint8_t *data1 = data;
  uint8_t *data2 = data + diff;
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ s2 = *p;
  K____uint32_t___uint32_t_ block_state10 = s2.block_state;
  uint8_t *buf0 = s2.buf;
  uint64_t total_len10 = s2.total_len;
  uint32_t sz10;
  if (total_len10 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len10 > (uint64_t)0U)
  {
    sz10 = (uint32_t)64U;
  }
  else
  {
    sz10 = (uint32_t)(total_len10 % (uint64_t)(uint32_t)64U);
  }
  uint8_t *buf2 = buf0 + sz10;
  memcpy(buf2, data1, diff * sizeof (uint8_t));
  uint64_t total_len2 = total_len10 + (uint64_t)diff;
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____){
        .block_state = block_state10,
        .buf = buf0,
        .total_len = total_len2
      }
    );
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ s20 = *p;
  K____uint32_t___uint32_t_ block_state1 = s20.block_state;
  uint8_t *buf = s20.buf;
  uint64_t total_len1 = s20.total_len;
  uint32_t sz1;
  if (total_len1 % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len1 > (uint64_t)0U)
  {
    sz1 = (uint32_t)64U;
  }
  else
  {
    sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)64U);
  }
  if (!(sz1 == (uint32_t)0U))
  {
    uint64_t prevlen = total_len1 - (uint64_t)sz1;
    uint32_t nb = (uint32_t)1U;
    uint64_t ite;
    if (key_size == (uint32_t)0U)
    {
      ite = prevlen;
    }
    else
    {
      ite = prevlen + (uint64_t)(uint32_t)64U;
    }
    Hacl_Blake2s_32_blake2s_update_multi((uint32_t)64U,
      block_state1.fst,
      block_state1.snd,
      ite,
      buf,
      nb);
  }
  uint32_t ite0;
  if
  (
    (uint64_t)(len - diff)
    % (uint64_t)(uint32_t)64U
    == (uint64_t)0U
    && (uint64_t)(len - diff) > (uint64_t)0U
  )
  {
    ite0 = (uint32_t)64U;
  }
  else
  {
    ite0 = (uint32_t)((uint64_t)(len - diff) % (uint64_t)(uint32_t)64U);
  }
  uint32_t n_blocks = (len - diff - ite0) / (uint32_t)64U;
  uint32_t data1_len = n_blocks * (uint32_t)64U;
  uint32_t data2_len = len - diff - data1_len;
  uint8_t *data11 = data2;
  uint8_t *data21 = data2 + data1_len;
  uint32_t nb = data1_len / (uint32_t)64U;
  uint64_t ite;
  if (key_size == (uint32_t)0U)
  {
    ite = total_len1;
  }
  else
  {
    ite = total_len1 + (uint64_t)(uint32_t)64U;
  }
  Hacl_Blake2s_32_blake2s_update_multi(data1_len,
    block_state1.fst,
    block_state1.snd,
    ite,
    data11,
    nb);
  uint8_t *dst = buf;
  memcpy(dst, data21, data2_len * sizeof (uint8_t));
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____){
        .block_state = block_state1,
        .buf = buf,
        .total_len = total_len1 + (uint64_t)(len - diff)
      }
    );
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_with_key_update */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_with_key_finish */

/*
  Finish function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2s_32_with_key_finish(
  uint32_t key_size,
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ *p,
  uint8_t *dst
)
{
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ scrut = *p;
  K____uint32_t___uint32_t_ block_state = scrut.block_state;
  uint8_t *buf_ = scrut.buf;
  uint64_t total_len = scrut.total_len;
  uint32_t r;
  if (total_len % (uint64_t)(uint32_t)64U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    r = (uint32_t)64U;
  }
  else
  {
    r = (uint32_t)(total_len % (uint64_t)(uint32_t)64U);
  }
  uint8_t *buf_1 = buf_;
  KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
  uint32_t wv[(uint32_t)4U * (uint32_t)4U];
  memset(wv, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (uint32_t));
  KRML_CHECK_SIZE(sizeof (uint32_t), (uint32_t)4U * (uint32_t)4U);
  uint32_t b[(uint32_t)4U * (uint32_t)4U];
  memset(b, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (uint32_t));
  K____uint32_t___uint32_t_ tmp_block_state = { .fst = wv, .snd = b };
  uint32_t *src_b = block_state.snd;
  uint32_t *dst_b = tmp_block_state.snd;
  memcpy(dst_b, src_b, (uint32_t)16U * sizeof (uint32_t));
  uint64_t prev_len = total_len - (uint64_t)r;
  uint64_t ite;
  if (key_size == (uint32_t)0U)
  {
    ite = prev_len;
  }
  else
  {
    ite = prev_len + (uint64_t)(uint32_t)64U;
  }
  Hacl_Blake2s_32_blake2s_update_last(r,
    tmp_block_state.fst,
    tmp_block_state.snd,
    ite,
    r,
    buf_1);
  Hacl_Blake2s_32_blake2s_finish((uint32_t)32U, dst, tmp_block_state.snd);
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_with_key_finish */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2s_32_with_key_free */

/*
  Free state function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2s_32_with_key_free(
  uint32_t key_size,
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ *s1
)
{
  Hacl_Streaming_Functor_state_s__K____uint32_t___uint32_t____ scrut = *s1;
  uint8_t *buf = scrut.buf;
  K____uint32_t___uint32_t_ block_state = scrut.block_state;
  uint32_t *wv = block_state.fst;
  uint32_t *b = block_state.snd;
  KRML_HOST_FREE(wv);
  KRML_HOST_FREE(b);
  KRML_HOST_FREE(buf);
  KRML_HOST_FREE(s1);
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2s_32_with_key_free */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_with_key_create_in */

/*
  State allocation function when using a (potentially null) key
*/
Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____
*Hacl_Streaming_Blake2_blake2b_32_with_key_create_in(uint32_t key_size, uint8_t *k1)
{
  uint8_t *buf = KRML_HOST_CALLOC((uint32_t)128U, sizeof (uint8_t));
  uint64_t *wv = KRML_HOST_CALLOC((uint32_t)16U, sizeof (uint64_t));
  uint64_t *b = KRML_HOST_CALLOC((uint32_t)16U, sizeof (uint64_t));
  K____uint64_t___uint64_t_ block_state = { .fst = wv, .snd = b };
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____
  s1 = { .block_state = block_state, .buf = buf, .total_len = (uint64_t)0U };
  KRML_CHECK_SIZE(sizeof (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____),
    (uint32_t)1U);
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____
  *p = KRML_HOST_MALLOC(sizeof (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____));
  p[0U] = s1;
  Hacl_Blake2b_32_blake2b_init(block_state.fst, block_state.snd, key_size, k1, (uint32_t)64U);
  return p;
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_with_key_create_in */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_with_key_update */

/*
  Update function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2b_32_with_key_update(
  uint32_t key_size,
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ *p,
  uint8_t *data,
  uint32_t len
)
{
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ s1 = *p;
  uint64_t total_len = s1.total_len;
  uint32_t sz;
  if (total_len % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    sz = (uint32_t)128U;
  }
  else
  {
    sz = (uint32_t)(total_len % (uint64_t)(uint32_t)128U);
  }
  if (len <= (uint32_t)128U - sz)
  {
    Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ s2 = *p;
    K____uint64_t___uint64_t_ block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)128U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)128U);
    }
    uint8_t *buf2 = buf + sz1;
    memcpy(buf2, data, len * sizeof (uint8_t));
    uint64_t total_len2 = total_len1 + (uint64_t)len;
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len2
        }
      );
    return;
  }
  if (sz == (uint32_t)0U)
  {
    Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ s2 = *p;
    K____uint64_t___uint64_t_ block_state1 = s2.block_state;
    uint8_t *buf = s2.buf;
    uint64_t total_len1 = s2.total_len;
    uint32_t sz1;
    if (total_len1 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len1 > (uint64_t)0U)
    {
      sz1 = (uint32_t)128U;
    }
    else
    {
      sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)128U);
    }
    if (!(sz1 == (uint32_t)0U))
    {
      uint64_t prevlen = total_len1 - (uint64_t)sz1;
      uint32_t nb = (uint32_t)1U;
      uint64_t ite;
      if (key_size == (uint32_t)0U)
      {
        ite = prevlen;
      }
      else
      {
        ite = prevlen + (uint64_t)(uint32_t)128U;
      }
      Hacl_Blake2b_32_blake2b_update_multi((uint32_t)128U,
        block_state1.fst,
        block_state1.snd,
        FStar_UInt128_uint64_to_uint128(ite),
        buf,
        nb);
    }
    uint32_t ite0;
    if ((uint64_t)len % (uint64_t)(uint32_t)128U == (uint64_t)0U && (uint64_t)len > (uint64_t)0U)
    {
      ite0 = (uint32_t)128U;
    }
    else
    {
      ite0 = (uint32_t)((uint64_t)len % (uint64_t)(uint32_t)128U);
    }
    uint32_t n_blocks = (len - ite0) / (uint32_t)128U;
    uint32_t data1_len = n_blocks * (uint32_t)128U;
    uint32_t data2_len = len - data1_len;
    uint8_t *data1 = data;
    uint8_t *data2 = data + data1_len;
    uint32_t nb = data1_len / (uint32_t)128U;
    uint64_t ite;
    if (key_size == (uint32_t)0U)
    {
      ite = total_len1;
    }
    else
    {
      ite = total_len1 + (uint64_t)(uint32_t)128U;
    }
    Hacl_Blake2b_32_blake2b_update_multi(data1_len,
      block_state1.fst,
      block_state1.snd,
      FStar_UInt128_uint64_to_uint128(ite),
      data1,
      nb);
    uint8_t *dst = buf;
    memcpy(dst, data2, data2_len * sizeof (uint8_t));
    *p
    =
      (
        (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____){
          .block_state = block_state1,
          .buf = buf,
          .total_len = total_len1 + (uint64_t)len
        }
      );
    return;
  }
  uint32_t diff = (uint32_t)128U - sz;
  uint8_t *data1 = data;
  uint8_t *data2 = data + diff;
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ s2 = *p;
  K____uint64_t___uint64_t_ block_state10 = s2.block_state;
  uint8_t *buf0 = s2.buf;
  uint64_t total_len10 = s2.total_len;
  uint32_t sz10;
  if (total_len10 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len10 > (uint64_t)0U)
  {
    sz10 = (uint32_t)128U;
  }
  else
  {
    sz10 = (uint32_t)(total_len10 % (uint64_t)(uint32_t)128U);
  }
  uint8_t *buf2 = buf0 + sz10;
  memcpy(buf2, data1, diff * sizeof (uint8_t));
  uint64_t total_len2 = total_len10 + (uint64_t)diff;
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____){
        .block_state = block_state10,
        .buf = buf0,
        .total_len = total_len2
      }
    );
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ s20 = *p;
  K____uint64_t___uint64_t_ block_state1 = s20.block_state;
  uint8_t *buf = s20.buf;
  uint64_t total_len1 = s20.total_len;
  uint32_t sz1;
  if (total_len1 % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len1 > (uint64_t)0U)
  {
    sz1 = (uint32_t)128U;
  }
  else
  {
    sz1 = (uint32_t)(total_len1 % (uint64_t)(uint32_t)128U);
  }
  if (!(sz1 == (uint32_t)0U))
  {
    uint64_t prevlen = total_len1 - (uint64_t)sz1;
    uint32_t nb = (uint32_t)1U;
    uint64_t ite;
    if (key_size == (uint32_t)0U)
    {
      ite = prevlen;
    }
    else
    {
      ite = prevlen + (uint64_t)(uint32_t)128U;
    }
    Hacl_Blake2b_32_blake2b_update_multi((uint32_t)128U,
      block_state1.fst,
      block_state1.snd,
      FStar_UInt128_uint64_to_uint128(ite),
      buf,
      nb);
  }
  uint32_t ite0;
  if
  (
    (uint64_t)(len - diff)
    % (uint64_t)(uint32_t)128U
    == (uint64_t)0U
    && (uint64_t)(len - diff) > (uint64_t)0U
  )
  {
    ite0 = (uint32_t)128U;
  }
  else
  {
    ite0 = (uint32_t)((uint64_t)(len - diff) % (uint64_t)(uint32_t)128U);
  }
  uint32_t n_blocks = (len - diff - ite0) / (uint32_t)128U;
  uint32_t data1_len = n_blocks * (uint32_t)128U;
  uint32_t data2_len = len - diff - data1_len;
  uint8_t *data11 = data2;
  uint8_t *data21 = data2 + data1_len;
  uint32_t nb = data1_len / (uint32_t)128U;
  uint64_t ite;
  if (key_size == (uint32_t)0U)
  {
    ite = total_len1;
  }
  else
  {
    ite = total_len1 + (uint64_t)(uint32_t)128U;
  }
  Hacl_Blake2b_32_blake2b_update_multi(data1_len,
    block_state1.fst,
    block_state1.snd,
    FStar_UInt128_uint64_to_uint128(ite),
    data11,
    nb);
  uint8_t *dst = buf;
  memcpy(dst, data21, data2_len * sizeof (uint8_t));
  *p
  =
    (
      (Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____){
        .block_state = block_state1,
        .buf = buf,
        .total_len = total_len1 + (uint64_t)(len - diff)
      }
    );
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_with_key_update */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_with_key_finish */

/*
  Finish function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2b_32_with_key_finish(
  uint32_t key_size,
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ *p,
  uint8_t *dst
)
{
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ scrut = *p;
  K____uint64_t___uint64_t_ block_state = scrut.block_state;
  uint8_t *buf_ = scrut.buf;
  uint64_t total_len = scrut.total_len;
  uint32_t r;
  if (total_len % (uint64_t)(uint32_t)128U == (uint64_t)0U && total_len > (uint64_t)0U)
  {
    r = (uint32_t)128U;
  }
  else
  {
    r = (uint32_t)(total_len % (uint64_t)(uint32_t)128U);
  }
  uint8_t *buf_1 = buf_;
  KRML_CHECK_SIZE(sizeof (uint64_t), (uint32_t)4U * (uint32_t)4U);
  uint64_t wv[(uint32_t)4U * (uint32_t)4U];
  memset(wv, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (uint64_t));
  KRML_CHECK_SIZE(sizeof (uint64_t), (uint32_t)4U * (uint32_t)4U);
  uint64_t b[(uint32_t)4U * (uint32_t)4U];
  memset(b, 0U, (uint32_t)4U * (uint32_t)4U * sizeof (uint64_t));
  K____uint64_t___uint64_t_ tmp_block_state = { .fst = wv, .snd = b };
  uint64_t *src_b = block_state.snd;
  uint64_t *dst_b = tmp_block_state.snd;
  memcpy(dst_b, src_b, (uint32_t)16U * sizeof (uint64_t));
  uint64_t prev_len = total_len - (uint64_t)r;
  uint64_t ite;
  if (key_size == (uint32_t)0U)
  {
    ite = prev_len;
  }
  else
  {
    ite = prev_len + (uint64_t)(uint32_t)128U;
  }
  Hacl_Blake2b_32_blake2b_update_last(r,
    tmp_block_state.fst,
    tmp_block_state.snd,
    FStar_UInt128_uint64_to_uint128(ite),
    r,
    buf_1);
  Hacl_Blake2b_32_blake2b_finish((uint32_t)64U, dst, tmp_block_state.snd);
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_with_key_finish */

/* SNIPPET_START: Hacl_Streaming_Blake2_blake2b_32_with_key_free */

/*
  Free state function when using a (potentially null) key
*/
void
Hacl_Streaming_Blake2_blake2b_32_with_key_free(
  uint32_t key_size,
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ *s1
)
{
  Hacl_Streaming_Functor_state_s__K____uint64_t___uint64_t____ scrut = *s1;
  uint8_t *buf = scrut.buf;
  K____uint64_t___uint64_t_ block_state = scrut.block_state;
  uint64_t *wv = block_state.fst;
  uint64_t *b = block_state.snd;
  KRML_HOST_FREE(wv);
  KRML_HOST_FREE(b);
  KRML_HOST_FREE(buf);
  KRML_HOST_FREE(s1);
}

/* SNIPPET_END: Hacl_Streaming_Blake2_blake2b_32_with_key_free */

