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
#include <stdint.h>
#include "../Buffer/write_buffer_interface.h"
#include "../Buffer/reader_buff_interface.h"

namespace jaf
{
namespace seri
{

// ���л��ӿ�
// T �����л�������
template <typename T>
class ISerialize
{
public:
	virtual ~ISerialize() {}

	// ��ȡ���л�����
	virtual size_t GetLen(const T& obj) const = 0;

	// ���л�
	// write_buffer ���л����Ļ�����
	// obj �����л��Ķ���
	virtual void Serialize(IWriteBuffer& write_buffer, const T& obj) const = 0;
	// �����л�
	// obj �������л��Ķ���
	virtual bool Deserialize(IReaderBuff& read_buffer, T& obj) const = 0;
};

}
}
