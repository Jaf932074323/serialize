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
#include <memory>
#include "../SerializeObj/serialize_interface.h"
#include "../Endian/endian_interface.h"

namespace jaf
{
namespace seri
{
// ���л�һ������ �������ֽ���
template<typename DataType>
class SeriPiece :public ISerialize<DataType>
{
public:
	// ���л��������Ͷ���
	// endian �������Ķ���
	// var �����л��Ĳ���
	SeriPiece()
	{
	}

	// ��ȡ������
	virtual size_t GetLen(const DataType& var) const override
	{
		return sizeof(var);
	}

	// ���л�
	virtual void Serialize(IWriteBuffer& write_buffer, const DataType& var) const override
	{
		write_buffer.Write((const char*)&var, sizeof(var));
	}

	// �����л�
	virtual bool Deserialize(IReaderBuff& read_buffer, DataType& var) const override
	{
		return read_buffer.Read((char*)&var, sizeof(var));
	}

};

}
}
