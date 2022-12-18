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
#include "test_spread_seri_macro_head.h"

class SeriPara_5 :public jaf::seri::SeriBase<Para>
{
	JAF_SERI_PREPARE();
	JAF_SERI_FUN_N
	(
		CHILD(data.a, jaf::seri::SeriInteger<int64_t>(endian_), seri_child_0_)
		, CHILD(data.b, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.c, jaf::seri::SeriInteger<short>(endian_), seri_child_2_)
	)
	(
		CHILD(data.a, jaf::seri::SeriInteger<int64_t>(endian_), seri_child_0_)
		, CHILD(data.b, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.c, jaf::seri::SeriInteger<short>(endian_), seri_child_2_)
	);
	JAF_SERI_IMPLEMENT_INTERFACE();
};

TEST(spread_seri_macro, _5)
{
    Para para1, para2;
	para1.a = 100;
	para1.b = 10;
	para1.c = 1;
	SeriPara_5 seri_para;

    size_t seri_data_len = seri_para.GetLen(para1);
    ASSERT_EQ(seri_data_len, 14);

	jaf::WriteBuffer write_buffer;
    seri_para.Serialize(write_buffer, para1);
    ASSERT_EQ(write_buffer.GetWriteLen(), 14);

	jaf::ReaderBuff read_buffer(write_buffer.Data(), write_buffer.GetWriteLen());
    bool deserialize_result = seri_para.Deserialize(read_buffer, para2);
    ASSERT_TRUE(deserialize_result);
	ASSERT_EQ(para1.a, para2.a);
	ASSERT_EQ(para1.b, para2.b);
	ASSERT_EQ(para1.c, para2.c);
}
