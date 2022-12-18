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
#include <vector>
#include "../SerializeObj/serialize_interface.h"

namespace jaf
{
namespace seri
{

// 序列化vector类型对象
// ItemType元素类型
// Size 长度变量
template<typename ItemType>
class SeriVector :public ISerialize<std::vector<ItemType>>
{
public:
	// 序列化vector元素的对象
	SeriVector(const ISerialize<ItemType>& seri_item)
		: seri_item_(seri_item)
	{
	}
	// 序列化vector元素的对象
	SeriVector(ISerialize<ItemType>&& seri_item)
		: seri_item_(std::move(seri_item))
	{
	}

	// 获取包长度
	virtual size_t GetLen(const std::vector<ItemType>& var) const override
	{
		size_t size = 0;
		size_t vec_size = var.size();
		for (size_t i = 0; i < vec_size; ++i)
		{
			size += seri_item_.GetLen(var[i]);
		}
		return size;
	}

	// 序列化
	virtual void Serialize(IWriteBuffer& write_buffer, const std::vector<ItemType>& var) const override
	{
		size_t vec_size = var.size();
		for (size_t i = 0; i < vec_size; ++i)
		{
			seri_item_.Serialize(write_buffer, var[i]);
		}
	}

	// 反序列化
	virtual bool Deserialize(IReaderBuff& read_buffer, std::vector<ItemType>& var) const override
	{
		size_t vec_size = var.size();
		for (size_t i = 0; i < vec_size; ++i)
		{
			if (!seri_item_.Deserialize(read_buffer, var[i]))
			{
				return false;
			}
		}
		return true;
	}

protected:
	const ISerialize<ItemType>& seri_item_; // 序列化类型对象
};

}
}
