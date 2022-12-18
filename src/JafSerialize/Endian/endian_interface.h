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
#include "../Buffer/write_buffer_interface.h"
#include "../Buffer/reader_buff_interface.h"

namespace jaf
{
namespace seri
{
	// ����ö��
	enum class Endian
	{
		Endian_Big = 0, // ���
		Endian_little = 1, // С��
	};

	// �������л��ӿ�
	class IEndian
	{
	public:
		// ���л�һ������
		// write_buffer ���л���Ϊ�Ļ���
		// var_addr �����л������ĵ�ַ
		// var_len �����л������ĳ���
		virtual void Serialize(IWriteBuffer& write_buffer, const char* var_addr, size_t var_len) const = 0;
		// �����л�һ������
		// read_buffer �������л��Ļ���
		// var_addr �����л��õ������ĵ�ַ
		// var_len �����л��õ������ĳ���
		virtual bool Deserialize(IReaderBuff& read_buffer, char* var_addr, size_t var_len) const = 0;
	};
}
}

