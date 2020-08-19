// *****************************************************************************
//
// Copyright (c) 2014, Southwest Research Institute® (SwRI®)
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of Southwest Research Institute® (SwRI®) nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// *****************************************************************************

#include <boost/random/mersenne_twister.hpp>
#include <gtest/gtest.h>
#include <swri_math_util/random.h>

#ifdef BOOST_1_46
namespace boost_random = boost;
#else
namespace boost_random = boost::random;
#endif

TEST(RandomTests, GetUniformRandomSample)
{
  boost_random::mt19937 gen;

  std::vector<int32_t> sample;
  swri_math_util::GetUniformRandomSample<boost_random::mt19937>(gen, 0, 100, 10, sample);
  
  EXPECT_EQ(10, sample.size());
  
  swri_math_util::GetUniformRandomSample<boost_random::mt19937>(gen, 0, 100, 90, sample);
  EXPECT_EQ(90, sample.size());
}

TEST(RandomTests, RandomGenerator)
{
  swri_math_util::RandomGenerator gen;
  
  std::vector<int32_t> sample;
  gen.GetUniformRandomSample(0, 100, 10, sample);
  
  EXPECT_EQ(10, sample.size());
  
  gen.GetUniformRandomSample(0, 100, 90, sample);
  EXPECT_EQ(90, sample.size());
}

// Run all the tests that were declared with TEST()
int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
