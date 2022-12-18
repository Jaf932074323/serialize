#pragma once
//MIT License
//
//Copyright(c) 2021 Jaf932074323 ������
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
// ���л�����
#include "../SerializeObj/serialize_interface.h"

namespace jaf
{
namespace seri
{

// ���л��������
// ItemTypeԪ������
// size ���鳤��
template<typename ItemType, size_t Size>
class SeriArray :public ISerialize<ItemType[Size]>
{
public:
	using ArrType = ItemType[Size];

	// ���л��������Ͷ���
	// endian �������Ķ���
	// var �����л��Ĳ���
	SeriArray(ISerialize<ItemType>& seri_item)
		: seri_item_(seri_item)
	{
	}

	// ��ȡ������
	virtual size_t GetLen(const ArrType& var) const override
	{
		size_t size = 0;
		for (size_t i = 0; i < Size; ++i)
		{
			size += seri_item_.GetLen(var[i]);
		}
		return size;
	}

	// ���л�
	virtual void Serialize(IWriteBuffer& write_buffer, const ArrType& var) const override
	{
		for (size_t i = 0; i < Size; ++i)
		{
			seri_item_.Serialize(write_buffer, var[i]);
		}
	}

	// �����л�
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
	ISerialize<ItemType>& seri_item_; // ���л����Ͷ���
};

}
}
