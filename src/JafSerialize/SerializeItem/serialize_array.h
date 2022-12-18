#pragma once
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
// 序列化数组
#include "../SerializeObj/serialize_interface.h"

namespace jaf
{
namespace seri
{

// 序列化数组对象
// ItemType元素类型
// size 数组长度
template<typename ItemType, size_t Size>
class SeriArray :public ISerialize<ItemType[Size]>
{
public:
	using ArrType = ItemType[Size];

	// 序列化整数类型对象
	// endian 处理端序的对象
	// var 被序列化的参数
	SeriArray(ISerialize<ItemType>& seri_item)
		: seri_item_(seri_item)
	{
	}

	// 获取包长度
	virtual size_t GetLen(const ArrType& var) const override
	{
		size_t size = 0;
		for (size_t i = 0; i < Size; ++i)
		{
			size += seri_item_.GetLen(var[i]);
		}
		return size;
	}

	// 序列化
	virtual void Serialize(IWriteBuffer& write_buffer, const ArrType& var) const override
	{
		for (size_t i = 0; i < Size; ++i)
		{
			seri_item_.Serialize(write_buffer, var[i]);
		}
	}

	// 反序列化
	virtual bool Deserialize(IReaderBuff& read_buffer, ArrType& var) const override
	{
		for (size_t i = 0; i < Size; ++i)
		{
			if (!seri_item_.Deserialize(read_buffer, var[i]))
			{
				return false;
			}
		}
		return true;
	}

protected:
	ISerialize<ItemType>& seri_item_; // 序列化类型对象
};

}
}
