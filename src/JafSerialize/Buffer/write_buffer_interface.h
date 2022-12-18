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
/**************************************************************************
����:������
����:����������
**************************************************************************/

namespace jaf
{
	class IWriteBuffer
	{
	public:
		IWriteBuffer(void) {};
		~IWriteBuffer(void) {};

		// ��� �ͷ��ڴ桢����Ѷ��ֽڵ�
		virtual void Clear() = 0;

		// ԤԼnSize�ռ�,����д���ֽ� �û������ܹ���д��nSize���ֽ�
		// ������������ʱ�����·��������ڴ�ռ䣬���ܹ���ȡnSize���ֽ�
		// ��ʹ�ô洢���û��ṩ���ڴ�ʱ��������������������false
		// nSize ҪԤԼ�ռ�Ĵ�С
		virtual void Reserve(size_t nSize) = 0;

		// ��չ�������ռ�
		// ��չ������������������nCapacity���ֽڴ�С��������������ʱ�����·��������ڴ�ռ䣬���ܹ��ٴ�ȡnSize���ֽ�
		// ��ʹ�ô洢���û��ṩ���ڴ�ʱ��������������������false
		// nCapacity Ҫ��չ��Ŀ���С��С
		virtual void ExtendCapacity(size_t nCapacity) = 0;

		// ��ȡ��д���ֽ�����
		virtual size_t GetWriteLen() const = 0;

		// ��ȡ��������ַ
		virtual const char* Data() const = 0;

	public:
		// д�����ݵ���������
		// pData Ҫд�����ĵ�ַ ����Ϊ��
		// nLength Ҫд��ĳ���
		virtual void Write(const char* pData, size_t nLength) = 0;

		// �ظ�д��ͬһ���ַ�����������
		// c Ҫд����ַ�
		// nLength Ҫд���ַ��ĸ���
		// return �ɹ�����true��ʧ�ܷ���false
		virtual void WriteChar(char c, size_t nLength) = 0;

	public:
		// ɾ��ǰָ������
		// nLength Ҫɾ���ĳ���,������Ȳ�����ȫ��ɾ��
		virtual void PopFront(size_t nLength) = 0;
		// ɾ����ָ������
		// nLength Ҫɾ���ĳ���,������Ȳ�����ȫ��ɾ��
		virtual void PopBack(size_t nLength) = 0;

		// �������ڴ�
		// pSeekContent ���������ݵ��׵�ַ
		// nSeekcontentLength ���������ݵĳ���
		// rIndex ���ر����������ݵ�����
		// �����Ƿ�������
		virtual bool SeekFront(const char* pSeekContent, size_t nSeekContentLength, size_t& rIndex) = 0;
	};

} // namespace jaf

