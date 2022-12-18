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
����:���������洢�ֽ�
�ṩ��һ��Ĭ��ջ���ֽ����ȴ洢��Ĭ��ջ�С�
��ʹ���߲�ָ���洢��ʽʱ����Ҫ�洢���ֽڴ�����С��Ĭ��ջ���ȣ�Ĭ�ϴ洢�����ջ�С�
������Ĭ��ջ����ʱ���洢�ڶ�̬�����ڴ��С�
**************************************************************************/
#include <memory.h>
#include "write_buffer_interface.h"

namespace jaf
{
	const size_t g_nAllotMemoryUnit = 32; // ����ռ�ʱ�������ֵ�ı�������
	const size_t g_nDefaultStackLen = 32; // Ĭ��ջ����

	// ������
	class WriteBuffer :public IWriteBuffer
	{
	protected:
		// �ֽڴ洢λ��
		enum class E_STORE_SITE
		{
			E_STORE_SITE_STACK = 0, // �洢��Ĭ��ջ��
			E_STORE_SITE_DYNAMIC = 1 // �洢�ڶ�̬�ڴ���
		};
	public:
		WriteBuffer(void) :
			m_eStoreSite(E_STORE_SITE::E_STORE_SITE_STACK)
			, m_nCapacity(g_nDefaultStackLen)
			, m_pBuffer(m_arrBufferStack)
			, m_nWriteByteLen(0)
		{
			memset(m_arrBufferStack, 0, g_nDefaultStackLen);
		}

		~WriteBuffer(void)
		{
			Clear();
		}

		// ��� �ͷŶ����ڴ桢����Ѷ���д�ֽڵ�
		virtual void Clear() override
		{
			ReleaseAllotMemory();
			m_eStoreSite = E_STORE_SITE::E_STORE_SITE_STACK;
			m_pBuffer = m_arrBufferStack;
			m_nCapacity = g_nDefaultStackLen;

			m_nWriteByteLen = 0;
		}

		// ԤԼnSize�ռ�,����д���ֽ� �û������ܹ���д��nSize���ֽ�
		// ������������ʱ�����·��������ڴ�ռ䣬���ܹ���ȡnSize���ֽ�
		// ��ʹ�ô洢���û��ṩ���ڴ�ʱ��������������������false
		// nSize ҪԤԼ�ռ�Ĵ�С
		// return �ɹ�����true��ʧ�ܷ���false
		virtual void Reserve(size_t nSize) override
		{
			// ����ռ��Ѿ��㹻����ֱ�ӷ���true
			ExtendCapacity(m_nWriteByteLen + nSize);
		}

		// ��չ�������ռ䣬��ԭ����д��ĳ����£�
		// ��չ����������nCapacity���ֽڴ�С��������������ʱ�����·��������ڴ�ռ䣬���ܹ��ٴ�ȡnSize���ֽ�
		// ��ʹ�ô洢���û��ṩ���ڴ�ʱ��������������������false
		// nCapacity Ҫ��չ��Ŀ���С
		// return �ɹ�����true��ʧ�ܷ���false
		virtual void ExtendCapacity(size_t nCapacity) override
		{
			// ����ռ��Ѿ��㹻����ֱ�ӷ���
			if (nCapacity <= m_nCapacity)
			{
				return;
			}

			// ����Ҫ����ռ��С������ռ�ʱҪ��kAllotMemoryUnit�ı������з���
			size_t nTotalCapacity = (nCapacity / g_nAllotMemoryUnit + 1) * g_nAllotMemoryUnit;
			nTotalCapacity *= 2; // ÿ�ζ����һ�������������ظ�����

			char* pBuff = nullptr;
			try
			{
				pBuff = new char[nTotalCapacity]; // ���붯̬�ڴ�
			}
			catch (const std::bad_alloc& e)
			{
				std::string str = e.what();
			}

			memcpy(pBuff, m_pBuffer, m_nWriteByteLen); // ���Ѿ�д��Ĳ��ֿ�������
			ReleaseAllotMemory(); // ��ԭ��������ڴ�ռ��ͷŵ�
			m_pBuffer = pBuff; // ������ָ��ָ���·�����ڴ�ռ�
			m_nCapacity = nTotalCapacity;
			m_eStoreSite = E_STORE_SITE::E_STORE_SITE_DYNAMIC;

			return;
		}

		// ��ȡ��д���ֽ���
		virtual size_t GetWriteLen() const override
		{
			return m_nWriteByteLen;
		}

		// ��ȡ��������ַ
		virtual const char* Data() const override
		{
			return m_pBuffer;
		}

	public:
		// д�����ݵ�������
		// pData Ҫд�����ĵ�ַ ����Ϊ��
		// nLength Ҫд��ĳ���
		// return �ɹ�����true��ʧ�ܷ���false
		virtual void Write(const char* pData, size_t nLength) override
		{
			if (nullptr == pData)
			{
				//throw CSddException(("д����ڴ��ַΪ��."), __FILE__, __LINE__);
			}

			Reserve(nLength);

			memcpy(m_pBuffer + m_nWriteByteLen, pData, nLength);
			m_nWriteByteLen += nLength;
		}

		// �ظ�д��ͬһ���ַ�����������
		// c Ҫд����ַ�
		// nLength Ҫд���ַ��ĸ���
		// return �ɹ�����true��ʧ�ܷ���false
		virtual void WriteChar(char c, size_t nLength) override
		{
			Reserve(nLength);

			memset(m_pBuffer + m_nWriteByteLen, c, nLength);
			m_nWriteByteLen += nLength;
		}

	public:
		// ɾ��ǰָ������
		// nLength Ҫɾ���ĳ���,������Ȳ�����ȫ��ɾ��
		virtual void PopFront(size_t nLength) override
		{
			if (nLength >= m_nWriteByteLen)
			{
				m_nWriteByteLen = 0;
				return;
			}

			if (nLength == 0)
			{
				return;
			}

			m_nWriteByteLen = m_nWriteByteLen - nLength;
			for (size_t i = 0; i < m_nWriteByteLen; ++i)
			{
				m_pBuffer[i] = m_pBuffer[i + nLength];
			}
		}
		// ɾ����ָ������
		// nLength Ҫɾ���ĳ���,������Ȳ�����ȫ��ɾ��
		virtual void PopBack(size_t nLength) override
		{
			if (nLength >= m_nWriteByteLen)
			{
				m_nWriteByteLen = 0;
			}

			m_nWriteByteLen = m_nWriteByteLen - nLength;
		}


		// �������ڴ�
		// pSeekContent ���������ݵ��׵�ַ
		// nSeekcontentLength ���������ݵĳ���
		// rIndex ���ر����������ݵ�����
		// �����Ƿ�������
		virtual bool SeekFront(const char* pSeekContent, size_t nSeekContentLength, size_t& rIndex) override
		{
			for (size_t i = 0; i < m_nWriteByteLen; ++i)
			{
				size_t j = 0;
				for (; j < nSeekContentLength; ++j)
				{
					if (m_pBuffer[i + j] != pSeekContent[j])
					{
						break;
					}
				}
				if (j >= nSeekContentLength)
				{
					rIndex = i;
					return true;
				}
			}

			return false;
		}
	private:
		// �ͷŶ�̬������ڴ�ռ� ������������ͷ����ڴ棬�������ֵ����������д�ֽڵȵȶ�û�������������������������
		void ReleaseAllotMemory()
		{
			// ����洢�ڶ�̬�����ڴ��У���Ҫ�ͷŷ�����ڴ�
			if (E_STORE_SITE::E_STORE_SITE_DYNAMIC == m_eStoreSite)
			{
				delete[] m_pBuffer;
				m_pBuffer = m_arrBufferStack;
			}
		}

	protected:
		// ������ָ��,ָ��洢�ֽڵ��׵�ַ
		// ��ʹ��Ĭ��ջʱ����ָ��Ĭ��ջ�׵�ַ
		// ��ʹ�ö�̬�ڴ�ռ�ʱ��ָ��̬�ڴ��׵�ַ
		char* m_pBuffer = nullptr;
		char m_arrBufferStack[g_nDefaultStackLen]; // Ĭ��ջ
		E_STORE_SITE m_eStoreSite = E_STORE_SITE::E_STORE_SITE_STACK; // �ֽڴ洢λ��

		size_t m_nCapacity = g_nDefaultStackLen; // ������
		size_t m_nWriteByteLen = 0; // �Ѿ�д���ֽڵĳ���
	};

} // namespace jaf
