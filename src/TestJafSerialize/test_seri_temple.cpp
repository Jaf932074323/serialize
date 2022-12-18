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
#pragma once
#include <gtest/gtest.h>
#include "JafSerialize/serialize_include.h"

template <typename T1, typename T2>
struct TempData
{
	T1 para1;
	T2 para2;
};

template <typename T1, typename T2>
class SeriTempData :public jaf::seri::SeriBase<TempData<T1, T2>>
{
	using DataType = TempData<T1, T2>; // 重命名被序列化的数据类型，为了方便宏扩展
	JAF_SERI
	(
		CHILD(data.para1, jaf::seri::SeriInteger<T1>(endian_))
		, CHILD(data.para2, jaf::seri::SeriInteger<T2>(endian_))
	);
};

TEST(seri_temp, temp)
{
	TempData<int, short> data_1;
	TempData<int, short> data_2;
	data_1.para1 = 1;
	data_1.para2 = 1;

	SeriTempData<int, short> seri_temp_data;
	jaf::WriteBuffer write_buffer;
	seri_temp_data.Serialize(write_buffer, data_1);
	jaf::ReaderBuff read_buffer(write_buffer.Data(), write_buffer.GetWriteLen());
	seri_temp_data.Deserialize(read_buffer, data_2);

	ASSERT_EQ(data_1.para1, data_2.para1);
	ASSERT_EQ(data_1.para2, data_2.para2);
}
