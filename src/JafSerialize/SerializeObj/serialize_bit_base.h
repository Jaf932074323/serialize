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
#include "serialize_interface.h"
#include "../Endian/manage_endian.h"
#include "../SerializeItem/serialize_user_define.h"

namespace jaf
{
namespace seri
{

// ���л�λ����
// T �����л�������
// len ���л�����
template <typename T, size_t len>
// ���л�����
class SeriBitBase :public ISerialize<T>
{
public:
	using DataType = T; // �����������л����������ͣ�Ϊ�˷������չ
	const static size_t kSeriLen = len;
public:
	// Ĭ�϶�����
	SeriBitBase() : endian_(ManageEndian::GetDefaultEndian())
	{}
	// ����ö��ֵ����
	SeriBitBase(Endian endian) : endian_(ManageEndian::GetEndian(endian))
	{}
	// ָ��������
	SeriBitBase(const jaf::seri::IEndian& endian) : endian_(endian)
	{}

	// ��ȡ���л�����
	inline virtual size_t GetLen(const T& obj) const override
	{
		return len;
	}

protected:
	const jaf::seri::IEndian& endian_; // �������Ķ���
};

}
}