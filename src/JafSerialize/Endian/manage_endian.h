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
#include <assert.h>
#include "endian_base.h"
#include "endian_little.h"
#include "endian_big.h"

namespace jaf
{
namespace seri
{

	// 管理端序
	class ManageEndian
	{
	public:
		// 获取端序
		static IEndian& GetEndian(Endian endian)
		{
			assert(endian == Endian::Endian_Big || endian == Endian::Endian_little);

			switch (endian)
			{
			case jaf::seri::Endian::Endian_Big:
				return GetBigEndian();
			case jaf::seri::Endian::Endian_little:
				return GetLittleEndian();
			default:
				return GetDefaultEndian();
			}
		}
		// 获取大端
		static BigEndian& GetBigEndian()
		{
			static BigEndian big_endian_; // 大端
			return big_endian_;
		}
		// 获取小端
		static LittleEndian& GetLittleEndian()
		{
			static LittleEndian little_endian_; // 小端
			return little_endian_;
		}
		// 获取默认端序
		static IEndian& GetDefaultEndian()
		{
			static IEndian* default_endian_ = *GetDefaultEndianInterior(); // 获取默认端序地址
			assert(default_endian_ != nullptr);
			return *default_endian_;
		}
		// 设置默认端序
		static void SetDefaultEndian(Endian endian)
		{
			static IEndian** default_endian_ = GetDefaultEndianInterior(); // 获取默认端序地址
			switch (endian)
			{
			case jaf::seri::Endian::Endian_Big:
				*default_endian_ = &GetBigEndian();
				break;
			case jaf::seri::Endian::Endian_little:
				*default_endian_ = &GetLittleEndian();
				break;
			default:
				break;
			}
		}

	private:
		// 内部获取默认端序
		static IEndian** GetDefaultEndianInterior()
		{
			static IEndian* default_endian_ = &GetLittleEndian(); // 默认端序	
			assert(default_endian_ != nullptr);
			return &default_endian_;
		}
	};

}
}

