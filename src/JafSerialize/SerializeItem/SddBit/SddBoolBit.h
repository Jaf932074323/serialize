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
#include "serialize_bit_interface.h"
#include <assert.h>

namespace jaf
{
namespace seri
{
class SeriBitBool :public ISerializeBit<bool>
{
public:
	SeriBitBool(size_t bit_index) :byte_index_(bit_index / 8), byte_bit_index_(bit_index % 8)
	{
	}

	~SeriBitBool()
	{
	}
	// �ӻ������ж�ȡλ����
	// pBuff ������
	// nLength �������ܳ���
	// �ɹ�����true,ʧ�ܷ���false
	virtual bool Serialize(char* buff, size_t len, const bool& obj) const override
	{
		assert(len * 8 > (byte_index_ * 8 + byte_bit_index_)); // ����������Ҫ�㹻��
		char* p = buff + byte_index_; // �ҵ�Ҫ���л����ַ���ַ

		char c = 0x01 << byte_bit_index_;
		if (obj)
		{
			*p |= c;
		}
		else
		{
			char c = 0x01 << byte_bit_index_;
			c = ~c;
			*p &= c;
		}

		return true;
	}
	// ��λ����д�뵽������
	// pBuff ������
	// nLength �������ܳ���
	// �ɹ�����true,ʧ�ܷ���false
	virtual bool Deserialize(const char* buff, size_t len, bool& obj) const override
	{
		assert(len * 8 > (byte_index_ * 8 + byte_bit_index_)); // ����������Ҫ�㹻��
		const char* p = buff + byte_index_; // �ҵ�Ҫ�����л����ַ���ַ

		char c = 0x01 << byte_bit_index_;
		c &= *p;
		obj = (bool)c;

		return true;
	}

protected:
	size_t byte_index_; // �ֽ�����
	size_t byte_bit_index_; // �ֽڵ�λ����
};

}
} // namespace jaf

