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

namespace jaf
{
namespace seri
{
// ���л�λ�ӿ�
// T �����л�������
template <typename T>
class ISerializeBit
{
public:
	ISerializeBit() {};
	virtual ~ISerializeBit() {};

public:
	// �ӻ������ж�ȡλ����
	// pBuff ������
	// nLength �������ܳ���
	// �ɹ�����true,ʧ�ܷ���false
	virtual bool Serialize(char* buff, size_t len, const T& obj) const = 0;
	// ��λ����д�뵽������
	// pBuff ������
	// nLength �������ܳ���
	// �ɹ�����true,ʧ�ܷ���false
	virtual bool Deserialize(const char* buff, size_t len, T& obj) const = 0;

};

}
} // namespace jaf

