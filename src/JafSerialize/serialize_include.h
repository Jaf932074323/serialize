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
// ���л�ͷ�ļ�

// ����
#include "Buffer/write_buffer_interface.h"
#include "Buffer/write_buffer.h"
#include "Buffer/reader_buff_interface.h"
#include "Buffer/reader_buff.h"

// ����
#include "Endian/endian_interface.h"
#include "Endian/endian_base.h"
#include "Endian/endian_big.h"
#include "Endian/endian_little.h"
#include "Endian/manage_endian.h"

// ���л�����
#include "SerializeObj/serialize_interface.h"
#include "SerializeObj/serialize_base.h"
#include "SerializeItem/serialize_integer.h"
#include "SerializeItem/serialize_piece.h"
#include "SerializeItem/serialize_float.h"
#include "SerializeItem/serialize_vector.h"
#include "SerializeItem/serialize_array.h"
#include "SerializeItem/serialize_user_define.h"

// ���л�λ����
#include "SerializeItem/SddBit/SddBoolBit.h"

// ���л�����
#include "SerializeObj/serialize_base.h"
#include "SerializeObj/serialize_bit_base.h"

// ����
#include "macro_serialize.h"
#include "macro_serialize_bit.h"
