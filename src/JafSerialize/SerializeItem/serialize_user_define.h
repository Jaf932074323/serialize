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
#include <functional>
#include "../SerializeObj/serialize_interface.h"

namespace jaf
{
namespace seri
{

// 用户自定义序列化动作
// T 元素类型
template<typename T>
class SeriUserDefine :public ISerialize<T>
{
public:
	// 用户自定义序列化动作
	// get_len_fun 用户自定义获取包长度函数 为空时自动返回0
	// serialize_fun 用户自定义序列化函数 为空时自动执行空操作
	// deserialize_fun 用户自定义反序列化函数 为空时自动执行空操作并返回true
	SeriUserDefine(const std::function<size_t(const T&)>& get_len_fun = [](const T&) {return 0; }
	, const std::function<void(IWriteBuffer&, const T&)>& serialize_fun = [](IWriteBuffer&, const T&) {return; }
	, const std::function<bool(IReaderBuff&, T&)>& deserialize_fun = [](IReaderBuff&, T&) {return true; }
		)
	{
		if (get_len_fun)
		{
			get_len_fun_ = get_len_fun;
		}
		if (serialize_fun)
		{
			serialize_fun_ = serialize_fun;
		}
		if (deserialize_fun)
		{
			deserialize_fun_ = deserialize_fun;
		}
	}

	// 获取包长度
	virtual size_t GetLen(const T& var) const override
	{
		return get_len_fun_(var);
	}

	// 序列化
	virtual void Serialize(IWriteBuffer& write_buffer, const T& var) const override
	{
		serialize_fun_(write_buffer, var);
	}

	// 反序列化
	virtual bool Deserialize(IReaderBuff& read_buffer, T& var) const override
	{
		return deserialize_fun_(read_buffer, var);
	}

protected:
	std::function<size_t(const T&)> get_len_fun_ = [](const T&) {return 0; }; // 用户自定义获取长度功能
	std::function<void(IWriteBuffer&, const T&)> serialize_fun_ = [](IWriteBuffer&, const T&) {return; }; // 用户自定义序列化功能
	std::function<bool(IReaderBuff&, T&)> deserialize_fun_ = [](IReaderBuff&, T&) {return true; }; // 用户自定义反序列化功能

};

}
}
