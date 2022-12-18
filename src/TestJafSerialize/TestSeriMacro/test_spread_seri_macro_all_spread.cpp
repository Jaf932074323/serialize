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

// 全部展开
class SeriPara_All_Spread :public jaf::seri::SeriBase<Para>
{
private:
	// 获取子项长度模版
	template<size_t Index>
	inline size_t GetChildLen(const DataType& data) const;
	// 序列化子项模版
	template<size_t Index>
	inline void SerializeChild(jaf::IWriteBuffer& write_buffer, const DataType& data) const;
	// 反序列化子项模版
	template<size_t Index>
	inline bool DeserializeChild(jaf::IReaderBuff& read_buffer, DataType& data) const;

	// 定义序列化子项个数
	constexpr static size_t child_count_ = 3;

private:
	// 第0个序列化子对象
	jaf::seri::SeriInteger<int64_t> seri_child_0_ = jaf::seri::SeriInteger<int64_t>(endian_);
	// 获取第0个序列化子对象
	inline const jaf::seri::SeriInteger<int64_t>& GetChild_0() const
	{
		return seri_child_0_;
	}
	// 获取第0个子项序列化长度
	template<>
	inline size_t GetChildLen<0>(const DataType& data) const
	{
		return GetChild_0().GetLen(data.a);
	}
	// 序列化第0个子项
	template<>
	inline void SerializeChild<0>(jaf::IWriteBuffer& write_buffer, const DataType& data) const
	{
		GetChild_0().Serialize(write_buffer, data.a);
	}
	// 反序列化第0个子项
	template<>
	inline bool DeserializeChild<0>(jaf::IReaderBuff& read_buffer, DataType& data) const
	{
		return GetChild_0().Deserialize(read_buffer, data.a);
	}

private:
	// 第1个序列化子对象
	jaf::seri::SeriInteger<int> seri_child_1_ = jaf::seri::SeriInteger<int>(endian_);
	// 获取第1个序列化子对象
	inline const jaf::seri::SeriInteger<int>& GetChild_1() const
	{
		return seri_child_1_;
	}
	template<>
	inline size_t GetChildLen<1>(const DataType& data) const
	{
		return GetChild_1().GetLen(data.b);
	}
	// 序列化第1个子项
	template<>
	inline void SerializeChild<1>(jaf::IWriteBuffer& write_buffer, const DataType& data) const
	{
		GetChild_1().Serialize(write_buffer, data.b);
	}
	// 反序列化第1个子项
	template<>
	inline bool DeserializeChild<1>(jaf::IReaderBuff& read_buffer, DataType& data) const
	{
		return GetChild_1().Deserialize(read_buffer, data.b);
	}

private:
	// 第2个序列化子对象
	jaf::seri::SeriInteger<short> seri_child_2_ = jaf::seri::SeriInteger<short>(endian_);
	// 获取第2个序列化子对象
	inline const jaf::seri::SeriInteger<short>& GetChild_2() const
	{
		return seri_child_2_;
	}
	template<>
	inline size_t GetChildLen<2>(const DataType& data) const
	{
		return GetChild_2().GetLen(data.c);
	}
	// 序列化第2个子项
	template<>
	inline void SerializeChild<2>(jaf::IWriteBuffer& write_buffer, const DataType& data) const
	{
		GetChild_2().Serialize(write_buffer, data.c);
	}
	// 反序列化第2个子项
	template<>
	inline bool DeserializeChild<2>(jaf::IReaderBuff& read_buffer, DataType& data) const
	{
		return GetChild_2().Deserialize(read_buffer, data.c);
	}

public:
	virtual inline size_t GetLen(const DataType& data) const override
	{
		return GetLen(data, std::make_index_sequence<child_count_>());
	}
	virtual inline void Serialize(jaf::IWriteBuffer& write_buffer, const DataType& data) const override
	{
		Serialize(write_buffer, data, std::make_index_sequence<child_count_>());
	}
	virtual inline bool Deserialize(jaf::IReaderBuff& read_buffer, DataType& data) const override
	{
		return Deserialize(read_buffer, data, std::make_index_sequence<child_count_>());
	}

protected:
	template<size_t... Index>
	inline size_t GetLen(const DataType& data, std::index_sequence<Index...>) const
	{
		return (... + GetChildLen<Index>(data));
	}

	template<size_t... Index>
	inline void Serialize(jaf::IWriteBuffer& write_buffer, const DataType& data, std::index_sequence<Index...>) const
	{
		(..., SerializeChild<Index>(write_buffer, data));
	}

	template<size_t... Index>
	inline bool Deserialize(jaf::IReaderBuff& read_buffer, DataType& data, std::index_sequence<Index...>) const
	{
		return (...&&  DeserializeChild<Index>(read_buffer, data));
	}
};

TEST(spread_seri_macro, all_spread)
{
	Para para1, para2;
	para1.a = 100;
	para1.b = 10;
	para1.c = 1;
	SeriPara_All_Spread seri_para;

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
