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
#include "../Buffer/write_buffer_interface.h"
#include "../Buffer/reader_buff_interface.h"

namespace jaf
{
namespace seri
{
	// 端序枚举
	enum class Endian
	{
		Endian_Big = 0, // 大端
		Endian_little = 1, // 小端
	};

	// 端序序列化接口
	class IEndian
	{
	public:
		// 序列化一个参数
		// write_buffer 序列化成为的缓存
		// var_addr 被序列化参数的地址
		// var_len 被序列化参数的长度
		virtual void Serialize(IWriteBuffer& write_buffer, const char* var_addr, size_t var_len) const = 0;
		// 反序列化一个参数
		// read_buffer 被反序列化的缓存
		// var_addr 反序列化得到参数的地址
		// var_len 反序列化得到参数的长度
		virtual bool Deserialize(IReaderBuff& read_buffer, char* var_addr, size_t var_len) const = 0;
	};
}
}

