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
#include <stdint.h>
#include "../Buffer/write_buffer_interface.h"
#include "../Buffer/reader_buff_interface.h"

namespace jaf
{
namespace seri
{

// 序列化接口
// T 被序列化的类型
template <typename T>
class ISerialize
{
public:
	virtual ~ISerialize() {}

	// 获取序列化长度
	virtual size_t GetLen(const T& obj) const = 0;

	// 序列化
	// write_buffer 序列化到的缓冲区
	// obj 被序列化的对象
	virtual void Serialize(IWriteBuffer& write_buffer, const T& obj) const = 0;
	// 反序列化
	// obj 被反序列化的对象
	virtual bool Deserialize(IReaderBuff& read_buffer, T& obj) const = 0;
};

}
}
