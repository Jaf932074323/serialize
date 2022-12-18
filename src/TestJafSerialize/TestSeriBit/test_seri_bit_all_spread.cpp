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
class SeriBitData_All_Spread :public jaf::seri::SeriBase<SBitData>
{
	class SeriBit :public jaf::seri::SeriBitBase<SBitData, 1>
	{
	private:
		// 序列化子项模版
		template<size_t Index>
		inline void SerializeChild(char* buff, const DataType& data) const;
		// 反序列化子项模版
		template<size_t Index>
		inline bool DeserializeChild(const char* buff, DataType& data) const;

		// 定义序列化子项个数
		constexpr static size_t child_count_ = 2;

	private:
		// 第0个序列化子对象
		jaf::seri::SeriBitBool seri_child_0_ = jaf::seri::SeriBitBool(1);
		// 获取第0个序列化子对象
		inline const jaf::seri::SeriBitBool& GetChild_0() const
		{
			return seri_child_0_;
		}
		// 序列化第0个子项
		template<>
		inline void SerializeChild<0>(char* buff, const DataType& data) const
		{
			GetChild_0().Serialize(buff, kSeriLen, data.bool_1);
		}
		// 反序列化第0个子项
		template<>
		inline bool DeserializeChild<0>(const char* buff, DataType& data) const
		{
			return GetChild_0().Deserialize(buff, kSeriLen, data.bool_1);
		}
	private:
		// 第1个序列化子对象
		jaf::seri::SeriBitBool seri_child_1_ = jaf::seri::SeriBitBool(2);
		// 获取第1个序列化子对象
		inline const jaf::seri::SeriBitBool& GetChild_1() const
		{
			return seri_child_1_;
		}
		// 序列化第1个子项
		template<>
		inline void SerializeChild<1>(char* buff, const DataType& data) const
		{
			GetChild_1().Serialize(buff, kSeriLen, data.bool_2);
		}
		// 反序列化第1个子项
		template<>
		inline bool DeserializeChild<1>(const char* buff, DataType& data) const
		{
			return GetChild_1().Deserialize(buff, kSeriLen, data.bool_2);
		}

	public:
		virtual inline void Serialize(jaf::IWriteBuffer& write_buffer, const DataType& data) const override
		{
			Serialize(write_buffer, data, std::make_index_sequence<child_count_>());
		}
		virtual inline bool Deserialize(jaf::IReaderBuff& read_buffer, DataType& data) const override
		{
			return Deserialize(read_buffer, data, std::make_index_sequence<child_count_>());
		}

	private:
		// 序列化
		// write_buffer 序列化到的缓冲区
		// obj 被序列化的对象
		template<size_t... Index>
		inline void Serialize(jaf::IWriteBuffer& write_buffer, const DataType& data, std::index_sequence<Index...>) const
		{
			char arr_[kSeriLen] = { (char)0x00 };
			(..., SerializeChild<Index>(arr_, data));
			write_buffer.Write(arr_, kSeriLen);
		}
		// 反序列化
		// read_buffer 反序列化到的缓冲区
		// obj 被反序列化的对象
		template<size_t... Index>
		inline bool Deserialize(jaf::IReaderBuff& read_buffer, DataType& data, std::index_sequence<Index...>) const
		{
			char arr_[kSeriLen] = { (char)0x00 };
			if (!read_buffer.Read(arr_, kSeriLen))
			{
				return false;
			}
			return (...&&  DeserializeChild<Index>(arr_, data));
		}
	};

	JAF_SERI
	(
		CHILD(data, SeriBit())
	);
};

TEST(seri_bit, all_spread)
{
	SBitData data1, data2;
	data1.bool_1 = false;
	data1.bool_2 = true;
	SeriBitData_All_Spread seri_data;

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
