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
����:�ڴ��ȡ��
ͨ��������ܹ��ȽϷ���Ĵ��ڴ��ж�ȡ
**************************************************************************/
#include "reader_buff_interface.h"
#include <assert.h>
//#include "SddException.h"

namespace jaf
{
	class ReaderBuff :public IReaderBuff
	{
	public:
		ReaderBuff() {}
		// pBuff Ҫ��ȡ�ڴ�ĵ�ַ
		// nLength Ҫ��ȡ�ڴ�ĳ���
		ReaderBuff(const char* pBuff, size_t nLength)
			:m_pBuff(pBuff), m_nLength(nLength)
		{}
		virtual ~ReaderBuff() {}

		// ������һ��Ҫ����ȡ���ڴ棬���Ҷ�ȡƫ������Ϊ0
		// pBuff �ڴ��ַ
		// nLength �ڴ泤�� ����С��0
		virtual void Attach(const char* pBuff, size_t nLength) override
		{
			assert(pBuff != nullptr);
			m_pBuff = pBuff;
			m_nLength = nLength;
			m_nReadOffset = 0;
		}

		// �Ƴ��������ڴ�
		virtual void Clear() override
		{
			m_pBuff = nullptr;
			m_nLength = 0;
			m_nReadOffset = 0;
		}

		// ���ö�ȡƫ��
		// nOffset ���ö�ȡƫ�� ����С��0�����ܴ����ܳ��ȣ������׳��쳣
		virtual void SetReadOffset(size_t nOffset) override
		{
			if (nOffset >= m_nLength)
			{
				//throw CSddException("ƫ��λ�ô����ڴ��ܳ���.", __FILE__, __LINE__);
			}

			m_nReadOffset = nOffset;
		}
		// ��ȡ��ȡƫ��
		virtual size_t GetReadOffset() override
		{
			return m_nReadOffset;
		}

		// ���ڴ��ж�ȡ����
		// pData Ҫ��ȡ���ݵ��Ķ���ĵ�ַ ����Ϊ��
		// nLength Ҫ��ȡ�ĳ���
		// return �ɹ�����true��ʧ�ܷ���false
		// ��ȡ�ɹ��󣬶�ȡƫ��������ȡ�ĳ��ȣ�ʧ�ܲ���
		virtual bool Read(char* pData, size_t nLength) override
		{
			if (pData == nullptr)
			{
				return false;
			}
			if (nLength > m_nLength - m_nReadOffset)
			{
				// �ڴ����ݳ��Ȳ���
				return false;
			}

			memcpy_s(pData, nLength, m_pBuff + m_nReadOffset, nLength);
			m_nReadOffset += nLength;
			return true;
		}

		// �������Ҫ��ȡ���ַ�
		// nLength Ҫ�����ĳ���
		// return �ɹ�����true��ʧ�ܷ���false
		// �����ɹ��󣬶�ȡƫ��������ȡ�ĳ��ȣ�ʧ�ܲ���
		virtual bool SkipRead(size_t nLength) override
		{
			if (nLength > m_nLength - m_nReadOffset)
			{
				return false;
			}

			m_nReadOffset += nLength;
			return true;
		}

		// �������ڴ�
		// pSeekContent ���������ݵ��׵�ַ
		// nSeekcontentLength ���������ݵĳ���
		// rIndex ���ر����������ݵ������ƫ�ƴ�������
		// �����Ƿ�������
		virtual bool SeekAtOffset(const char* pSeekContent, size_t nSeekContentLength, size_t& rIndex) override
		{
			for (size_t i = m_nReadOffset; i + nSeekContentLength <= m_nLength; ++i)
			{
				size_t j = 0;
				for (; j < nSeekContentLength; ++j)
				{
					if (m_pBuff[i + j] != pSeekContent[j])
					{
						break;
					}
				}
				if (j >= nSeekContentLength)
				{
					rIndex = i - m_nReadOffset;
					return true;
				}
			}

			return false;
		}

	protected:
		const char* m_pBuff = nullptr; // Ҫ��ȡ���ڴ��ַ
		size_t m_nLength = 0; // Ҫ��ȡ���ڴ��ַ�ĳ���
		size_t m_nReadOffset = 0; // ��ȡ����ƫ�ƣ�ÿ�ζ�ȡ���ǳ�ƫ�ƴ���ȡ
	};

} // namespace jaf

