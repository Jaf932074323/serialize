//MIT License
//
//Copyright(c) 2021 Jaf932074323 姜安富
//
//Permission is hereby granted, free of charge, to any person obtaining a copy
//of this softwareand associated documentation files(the "Software"), to deal
//in the Software without restriction, including without limitation the rights
//to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
//copies of the Software, and to permit persons to whom the Software is
//furnished to do so, subject to the following conditions :
//
//The above copyright noticeand this permission notice shall be included in all
//copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//SOFTWARE.
#include <gtest/gtest.h>
#include "JafSerialize/serialize_include.h"

struct SFloatData
{
	float float_ = 0;
	double double_ = 0;
};

// 测试序列化浮点数
class SeriFloatData :public jaf::seri::SeriBase<SFloatData>
{
	JAF_SERI
	(
		CHILD(data.float_, jaf::seri::SeriFloat())
		, CHILD(data.double_, jaf::seri::SeriDouble())
	);
};

TEST(seri_float, float)
{
	SFloatData data1, data2;
	data1.float_ = 100;
	data1.double_ = 1000;
	SeriFloatData seri_data;

	size_t seri_data_len = seri_data.GetLen(data1);
	ASSERT_EQ(seri_data_len, 12);

	jaf::WriteBuffer write_buffer;
	seri_data.Serialize(write_buffer, data1);
	ASSERT_EQ(write_buffer.GetWriteLen(), 12);

	jaf::ReaderBuff read_buffer(write_buffer.Data(), write_buffer.GetWriteLen());
	bool deserialize_result = seri_data.Deserialize(read_buffer, data2);
	ASSERT_TRUE(deserialize_result);
	ASSERT_EQ(data1.float_, data2.float_);
	ASSERT_EQ(data1.double_, data2.double_);
}
