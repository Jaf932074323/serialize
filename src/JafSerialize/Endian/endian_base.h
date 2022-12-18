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
#include "endian_interface.h"

namespace jaf
{
namespace seri
{
// �������л�����
class EndianBase :public IEndian
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

protected:
	// ��ȡ��������
	static inline Endian HostEndian()
	{
		static Endian endian = HostEndianInter();
		return endian;
	}

	// ת���ֽ��� ���תС�ˣ�С��ת���
	static void ChangeEndian(char* var_addr, size_t var_len)
	{
		char c;
		size_t change_time = var_len / 2; // ��������
		for (size_t i = 0; i < change_time; ++i)
		{
			c = var_addr[i];
			var_addr[i] = var_addr[var_len - 1 - i];
			var_addr[var_len - 1 - i] = c;
		}
	}

private:
	// ��ȡ��������
	static Endian HostEndianInter()
	{
		unsigned short number = 0x0001;
		if (*(unsigned char*)&number == 0x01)
		{
			return Endian::Endian_little;
		}
		else
		{
			return Endian::Endian_Big;
		}
	}
};

}
}

