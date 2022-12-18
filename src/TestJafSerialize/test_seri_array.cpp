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
// 测试序列化数组
struct SArray
{
	int arr[10] = { 0 };
};

class SeriArray :public jaf::seri::SeriBase<SArray>
{
	jaf::seri::SeriInteger<int> seri_int = jaf::seri::SeriInteger<int>(endian_);
	JAF_SERI
	(
		CHILD(data.arr, (jaf::seri::SeriArray<int, 10>(seri_int)))
	);
};

TEST(seri_array, array)
{
	SArray data1, data2;
	for (size_t i = 0; i < 10; ++i)
	{
		data1.arr[i] = i;
	}
	SeriArray seri_data;

	size_t seri_data_len = seri_data.GetLen(data1);
	ASSERT_EQ(seri_data_len, 40);

	jaf::WriteBuffer write_buffer;
	seri_data.Serialize(write_buffer, data1);
	ASSERT_EQ(write_buffer.GetWriteLen(), 40);

	jaf::ReaderBuff read_buffer(write_buffer.Data(), write_buffer.GetWriteLen());
	bool deserialize_result = seri_data.Deserialize(read_buffer, data2);
	ASSERT_TRUE(deserialize_result);

	for (size_t i = 0; i < 10; ++i)
	{
		ASSERT_EQ(data1.arr[i], data2.arr[i]);
	}
}

