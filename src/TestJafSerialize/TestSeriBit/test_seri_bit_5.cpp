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
#include "test_seri_bit.h"

// 测试序列化位
class SeriBitData_5 :public jaf::seri::SeriBase<SBitData>
{
	class SeriBit :public jaf::seri::SeriBitBase<SBitData, 1>
	{
		JAF_BIT_SERI_PREPARE();
		JAF_BIT_SERI_FUN_N
		(
			CHILD(data.bool_1, jaf::seri::SeriBitBool(1))
			, CHILD(data.bool_2, jaf::seri::SeriBitBool(2), seri_child_1_)
		)
		(
			CHILD(data.bool_1, jaf::seri::SeriBitBool(1))
			, CHILD(data.bool_2, jaf::seri::SeriBitBool(2), seri_child_1_)
		);
		JAF_BIT_SERI_IMPLEMENT_INTERFACE();
	};

	JAF_SERI
	(
		CHILD(data, SeriBit())
	);
};

TEST(seri_bit, _5)
{
	SBitData data1, data2;
	data1.bool_1 = false;
	data1.bool_2 = true;
	SeriBitData_5 seri_data;

	size_t seri_data_len = seri_data.GetLen(data1);
	ASSERT_EQ(seri_data_len, 1);

	jaf::WriteBuffer write_buffer;
	seri_data.Serialize(write_buffer, data1);
	ASSERT_EQ(write_buffer.GetWriteLen(), 1);

	jaf::ReaderBuff read_buffer(write_buffer.Data(), write_buffer.GetWriteLen());
	bool deserialize_result = seri_data.Deserialize(read_buffer, data2);
	ASSERT_TRUE(deserialize_result);
	ASSERT_EQ(data1.bool_1, data2.bool_1);
	ASSERT_EQ(data1.bool_2, data2.bool_2);
}
