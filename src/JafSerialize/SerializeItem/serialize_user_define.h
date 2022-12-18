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
#include <functional>
#include "../SerializeObj/serialize_interface.h"

namespace jaf
{
namespace seri
{

// �û��Զ������л�����
// T Ԫ������
template<typename T>
class SeriUserDefine :public ISerialize<T>
{
public:
	// �û��Զ������л�����
	// get_len_fun �û��Զ����ȡ�����Ⱥ��� Ϊ��ʱ�Զ�����0
	// serialize_fun �û��Զ������л����� Ϊ��ʱ�Զ�ִ�пղ���
	// deserialize_fun �û��Զ��巴���л����� Ϊ��ʱ�Զ�ִ�пղ���������true
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

	// ��ȡ������
	virtual size_t GetLen(const T& var) const override
	{
		return get_len_fun_(var);
	}

	// ���л�
	virtual void Serialize(IWriteBuffer& write_buffer, const T& var) const override
	{
		serialize_fun_(write_buffer, var);
	}

	// �����л�
	virtual bool Deserialize(IReaderBuff& read_buffer, T& var) const override
	{
		return deserialize_fun_(read_buffer, var);
	}

protected:
	std::function<size_t(const T&)> get_len_fun_ = [](const T&) {return 0; }; // �û��Զ����ȡ���ȹ���
	std::function<void(IWriteBuffer&, const T&)> serialize_fun_ = [](IWriteBuffer&, const T&) {return; }; // �û��Զ������л�����
	std::function<bool(IReaderBuff&, T&)> deserialize_fun_ = [](IReaderBuff&, T&) {return true; }; // �û��Զ��巴���л�����

};

}
}
