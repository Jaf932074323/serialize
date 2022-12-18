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
#include <memory>
#include "../SerializeObj/serialize_interface.h"
#include "../Endian/endian_interface.h"
#include "../Endian/manage_endian.h"

namespace jaf
{
namespace seri
{
// 序列化整数类型对象
template<typename Integer>
class SeriInteger :public ISerialize<Integer>
{
public:
	// 序列化整数类型对象
	// endian 处理端序的对象
	// var 被序列化的参数
	SeriInteger(const IEndian& endian)
		: endian_(endian)
	{
	}

	// 获取包长度
	virtual size_t GetLen(const Integer& var) const override
	{
		return sizeof(var);
	}

	// 序列化
	virtual void Serialize(IWriteBuffer& write_buffer, const Integer& var) const override
	{
		endian_.Serialize(write_buffer, (const char*)&var, sizeof(var));
	}

	// 反序列化
	virtual bool Deserialize(IReaderBuff& read_buffer, Integer& var) const override
	{
		return endian_.Deserialize(read_buffer, (char*)&var, sizeof(var));
	}

protected:
	const IEndian& endian_; // 处理端序的对象
};

}
}
