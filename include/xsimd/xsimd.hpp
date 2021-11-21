/***************************************************************************
 * Copyright (c) Johan Mabille, Sylvain Corlay, Wolf Vollprecht and         *
 * Martin Renou                                                             *
 * Copyright (c) QuantStack                                                 *
 * Copyright (c) Serge Guelton                                              *
 *                                                                          *
 * Distributed under the terms of the BSD 3-Clause License.                 *
 *                                                                          *
 * The full license is in the file LICENSE, distributed with this software. *
 ****************************************************************************/

#ifndef XSIMD_HPP
#define XSIMD_HPP

#if defined(__GNUC__)
#define XSIMD_NO_DISCARD __attribute__((warn_unused_result))
#else
#define XSIMD_NO_DISCARD
#endif

#if defined(__GNUC__)
#define XSIMD_INLINE inline __attribute__((always_inline))
#elif defined(_MSC_VER)
#define XSIMD_INLINE inline __forceinline
#else
#define XSIMD_INLINE inline
#endif

#include "arch/xsimd_scalar.hpp"
#include "memory/xsimd_aligned_allocator.hpp"
#include "types/xsimd_batch.hpp"
#include "types/xsimd_batch_constant.hpp"
#include "types/xsimd_traits.hpp"

// This include must come last
#include "types/xsimd_api.hpp"
#endif
