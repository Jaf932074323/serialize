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
#include <vector>
#include <gtest/gtest.h>
#include "JafSerialize/serialize_include.h"

struct Data
{
	int a = 0;
	short b = 0;
};

struct VecData
{
	unsigned count = 0;
	std::vector<Data> data_group;
};


class SeriData :public jaf::seri::SeriBase<Data>
{
	JAF_SERI
	(
		CHILD(data.a, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.b, jaf::seri::SeriInteger<short>(endian_))
	);
};

class SeriVecData :public jaf::seri::SeriBase<VecData>
{
	SeriData seri_data_;
	JAF_SERI
	(
		CHILD(data.count, jaf::seri::SeriInteger<unsigned>(endian_))
		, USER(nullptr, nullptr, [](jaf::IReaderBuff&, VecData& data)->bool {data.data_group.resize(data.count); return true; }) // 反序列化时，设置vector的长度
		, CHILD(data.data_group, jaf::seri::SeriVector<Data>(seri_data_))
	);
};

TEST(seri_vector, vector)
{
	Data para;
	para.a = 100;
	para.b = 1000;

	VecData vec_para_1;
	VecData vec_para_2;
	vec_para_1.count = 2;
	vec_para_1.data_group.resize(2);
	vec_para_1.data_group[0].a = 100;
	vec_para_1.data_group[0].b = 1000;
	vec_para_1.data_group[1].a = 101;
	vec_para_1.data_group[1].b = 1001;

	SeriVecData seri_vec_data;
	seri_vec_data.GetLen(vec_para_1);
	jaf::WriteBuffer write_buffer;
	seri_vec_data.Serialize(write_buffer, vec_para_1);
	jaf::ReaderBuff read_buffer(write_buffer.Data(), write_buffer.GetWriteLen());
	seri_vec_data.Deserialize(read_buffer, vec_para_2);

	ASSERT_EQ(vec_para_1.count, vec_para_2.count);
	ASSERT_EQ(vec_para_1.data_group.size(), vec_para_2.data_group.size());
	size_t para_group_count =
		vec_para_1.data_group.size() < vec_para_2.data_group.size()
		? vec_para_1.data_group.size() : vec_para_2.data_group.size();
	for (size_t i = 0; i < para_group_count; ++i)
	{
		ASSERT_EQ(vec_para_1.data_group[i].a, vec_para_2.data_group[i].a);
		ASSERT_EQ(vec_para_1.data_group[i].b, vec_para_2.data_group[i].b);
	}
}
