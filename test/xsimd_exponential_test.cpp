/***************************************************************************
* Copyright (c) 2016, Johan Mabille and Sylvain Corlay                     *
*                                                                          *
* Distributed under the terms of the BSD 3-Clause License.                 *
*                                                                          *
* The full license is in the file LICENSE, distributed with this software. *
****************************************************************************/

#include <fstream>
#include <iostream>

#include "gtest/gtest.h"

#include "xsimd/math/xsimd_exponential.hpp"
#include "xsimd/math/xsimd_logarithm.hpp"
#include "xsimd/memory/xsimd_aligned_allocator.hpp"
#include "xsimd/types/xsimd_types_include.hpp"
#include "xsimd_exponential_test.hpp"

namespace xsimd
{
    template <class T, size_t N, size_t A>
    bool test_exponential(std::ostream& out, const std::string& name)
    {
        simd_exponential_tester<T, N, A> tester(name);
        return test_simd_exponential(out, tester);
    }
}

#if XSIMD_X86_INSTR_SET >= XSIMD_X86_SSE2_VERSION
TEST(xsimd, sse_float_exponential)
{
    std::ofstream out("log/sse_float_exponential.log", std::ios_base::out);
    bool res = xsimd::test_exponential<float, 4, 16>(out, "sse float");
    EXPECT_TRUE(res);
}

TEST(xsimd, sse_double_exponential)
{
    std::ofstream out("log/sse_double_exponential.log", std::ios_base::out);
    bool res = xsimd::test_exponential<double, 2, 16>(out, "sse double");
    EXPECT_TRUE(res);
}
#endif

#if XSIMD_X86_INSTR_SET >= XSIMD_X86_AVX_VERSION
TEST(xsimd, avx_float_exponential)
{
    std::ofstream out("log/avx_float_exponential.log", std::ios_base::out);
    bool res = xsimd::test_exponential<float, 8, 32>(out, "avx float");
    EXPECT_TRUE(res);
}

TEST(xsimd, avx_double_exponential)
{
    std::ofstream out("log/avx_double_exponential.log", std::ios_base::out);
    bool res = xsimd::test_exponential<double, 4, 32>(out, "avx double");
    EXPECT_TRUE(res);
}
#endif
