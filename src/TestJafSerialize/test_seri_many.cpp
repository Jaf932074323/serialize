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
#include <gtest/gtest.h>
#include "JafSerialize/serialize_include.h"
// 测试序列化大量子项

struct SData
{
	int para_1 = 0;
	int para_2 = 0;
	int para_3 = 0;
	int para_4 = 0;
	int para_5 = 0;
	int para_6 = 0;
	int para_7 = 0;
	int para_8 = 0;
	int para_9 = 0;
	int para_10 = 0;
	int para_11 = 0;
	int para_12 = 0;
	int para_13 = 0;
	int para_14 = 0;
	int para_15 = 0;
	int para_16 = 0;
	int para_17 = 0;
	int para_18 = 0;
	int para_19 = 0;
	int para_20 = 0;
	int para_21 = 0;
	int para_22 = 0;
	int para_23 = 0;
	int para_24 = 0;
	int para_25 = 0;
	int para_26 = 0;
	int para_27 = 0;
	int para_28 = 0;
	int para_29 = 0;
	int para_30 = 0;
	int para_31 = 0;
	int para_32 = 0;
	int para_33 = 0;
	int para_34 = 0;
	int para_35 = 0;
	int para_36 = 0;
	int para_37 = 0;
	int para_38 = 0;
	int para_39 = 0;
	int para_40 = 0;
	int para_41 = 0;
	int para_42 = 0;
	int para_43 = 0;
	int para_44 = 0;
	int para_45 = 0;
	int para_46 = 0;
	int para_47 = 0;
	int para_48 = 0;
	int para_49 = 0;
	int para_50 = 0;
	int para_51 = 0;
	int para_52 = 0;
	int para_53 = 0;
	int para_54 = 0;
	int para_55 = 0;
	int para_56 = 0;
	int para_57 = 0;
	int para_58 = 0;
	int para_59 = 0;
	int para_60 = 0;
	int para_61 = 0;
	int para_62 = 0;
	int para_63 = 0;
	int para_64 = 0;
	int para_65 = 0;
	int para_66 = 0;
	int para_67 = 0;
	int para_68 = 0;
	int para_69 = 0;
	int para_70 = 0;
	int para_71 = 0;
	int para_72 = 0;
	int para_73 = 0;
	int para_74 = 0;
	int para_75 = 0;
	int para_76 = 0;
	int para_77 = 0;
	int para_78 = 0;
	int para_79 = 0;
	int para_80 = 0;
	int para_81 = 0;
	int para_82 = 0;
	int para_83 = 0;
	int para_84 = 0;
	int para_85 = 0;
	int para_86 = 0;
	int para_87 = 0;
	int para_88 = 0;
	int para_89 = 0;
	int para_90 = 0;
	int para_91 = 0;
	int para_92 = 0;
	int para_93 = 0;
	int para_94 = 0;
	int para_95 = 0;
	int para_96 = 0;
	int para_97 = 0;
	int para_98 = 0;
	int para_99 = 0;
	int para_100 = 0;
	int para_101 = 0;
	int para_102 = 0;
	int para_103 = 0;
	int para_104 = 0;
	int para_105 = 0;
	int para_106 = 0;
	int para_107 = 0;
	int para_108 = 0;
	int para_109 = 0;
	int para_110 = 0;
	int para_111 = 0;
	int para_112 = 0;
	int para_113 = 0;
	int para_114 = 0;
	int para_115 = 0;
	int para_116 = 0;
	int para_117 = 0;
	int para_118 = 0;
	int para_119 = 0;
	int para_120 = 0;
	int para_121 = 0;
	int para_122 = 0;
	int para_123 = 0;
	int para_124 = 0;
	int para_125 = 0;
};

// 使用宏的最终效果
class SeriSData :public jaf::seri::SeriBase<SData>
{
	JAF_SERI
	(
		CHILD(data.para_1, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_2, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_3, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_4, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_5, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_6, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_7, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_8, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_9, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_10, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_11, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_12, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_13, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_14, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_15, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_16, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_17, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_18, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_19, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_20, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_21, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_22, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_23, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_24, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_25, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_26, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_27, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_28, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_29, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_30, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_31, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_32, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_33, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_34, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_35, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_36, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_37, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_38, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_39, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_40, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_41, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_42, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_43, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_44, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_45, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_46, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_47, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_48, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_49, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_50, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_51, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_52, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_53, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_54, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_55, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_56, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_57, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_58, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_59, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_60, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_61, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_62, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_63, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_64, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_65, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_66, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_67, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_68, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_69, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_70, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_71, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_72, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_73, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_74, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_75, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_76, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_77, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_78, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_79, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_80, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_81, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_82, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_83, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_84, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_85, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_86, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_87, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_88, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_89, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_90, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_91, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_92, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_93, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_94, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_95, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_96, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_97, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_98, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_99, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_100, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_101, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_102, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_103, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_104, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_105, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_106, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_107, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_108, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_109, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_110, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_111, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_112, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_113, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_114, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_115, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_116, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_117, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_118, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_119, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_120, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_121, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_122, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_123, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_124, jaf::seri::SeriInteger<int>(endian_))
		, CHILD(data.para_125, jaf::seri::SeriInteger<int>(endian_))

	);
};


TEST(seri_many, many)
{
	SData data1, data2;
	data1.para_1 = 1;
	data1.para_2 = 2;
	data1.para_3 = 3;
	data1.para_4 = 4;
	data1.para_5 = 5;
	data1.para_6 = 6;
	data1.para_7 = 7;
	data1.para_8 = 8;
	data1.para_9 = 9;
	data1.para_10 = 10;
	data1.para_11 = 11;
	data1.para_12 = 12;
	data1.para_13 = 13;
	data1.para_14 = 14;
	data1.para_15 = 15;
	data1.para_16 = 16;
	data1.para_17 = 17;
	data1.para_18 = 18;
	data1.para_19 = 19;
	data1.para_20 = 20;
	data1.para_21 = 21;
	data1.para_22 = 22;
	data1.para_23 = 23;
	data1.para_24 = 24;
	data1.para_25 = 25;
	data1.para_26 = 26;
	data1.para_27 = 27;
	data1.para_28 = 28;
	data1.para_29 = 29;
	data1.para_30 = 30;
	data1.para_31 = 31;
	data1.para_32 = 32;
	data1.para_33 = 33;
	data1.para_34 = 34;
	data1.para_35 = 35;
	data1.para_36 = 36;
	data1.para_37 = 37;
	data1.para_38 = 38;
	data1.para_39 = 39;
	data1.para_40 = 40;
	data1.para_41 = 41;
	data1.para_42 = 42;
	data1.para_43 = 43;
	data1.para_44 = 44;
	data1.para_45 = 45;
	data1.para_46 = 46;
	data1.para_47 = 47;
	data1.para_48 = 48;
	data1.para_49 = 49;
	data1.para_50 = 50;
	data1.para_51 = 51;
	data1.para_52 = 52;
	data1.para_53 = 53;
	data1.para_54 = 54;
	data1.para_55 = 55;
	data1.para_56 = 56;
	data1.para_57 = 57;
	data1.para_58 = 58;
	data1.para_59 = 59;
	data1.para_60 = 60;
	data1.para_61 = 61;
	data1.para_62 = 62;
	data1.para_63 = 63;
	data1.para_64 = 64;
	data1.para_65 = 65;
	data1.para_66 = 66;
	data1.para_67 = 67;
	data1.para_68 = 68;
	data1.para_69 = 69;
	data1.para_70 = 70;
	data1.para_71 = 71;
	data1.para_72 = 72;
	data1.para_73 = 73;
	data1.para_74 = 74;
	data1.para_75 = 75;
	data1.para_76 = 76;
	data1.para_77 = 77;
	data1.para_78 = 78;
	data1.para_79 = 79;
	data1.para_80 = 80;
	data1.para_81 = 81;
	data1.para_82 = 82;
	data1.para_83 = 83;
	data1.para_84 = 84;
	data1.para_85 = 85;
	data1.para_86 = 86;
	data1.para_87 = 87;
	data1.para_88 = 88;
	data1.para_89 = 89;
	data1.para_90 = 90;
	data1.para_91 = 91;
	data1.para_92 = 92;
	data1.para_93 = 93;
	data1.para_94 = 94;
	data1.para_95 = 95;
	data1.para_96 = 96;
	data1.para_97 = 97;
	data1.para_98 = 98;
	data1.para_99 = 99;
	data1.para_100 = 100;
	data1.para_101 = 101;
	data1.para_102 = 102;
	data1.para_103 = 103;
	data1.para_104 = 104;
	data1.para_105 = 105;
	data1.para_106 = 106;
	data1.para_107 = 107;
	data1.para_108 = 108;
	data1.para_109 = 109;
	data1.para_110 = 110;
	data1.para_111 = 111;
	data1.para_112 = 112;
	data1.para_113 = 113;
	data1.para_114 = 114;
	data1.para_115 = 115;
	data1.para_116 = 116;
	data1.para_117 = 117;
	data1.para_118 = 118;
	data1.para_119 = 119;
	data1.para_120 = 120;
	data1.para_121 = 121;
	data1.para_122 = 122;
	data1.para_123 = 123;
	data1.para_124 = 124;
	data1.para_125 = 125;


	SeriSData seri_data;

	size_t seri_data_len = seri_data.GetLen(data1);
	ASSERT_EQ(seri_data_len, 125 * 4);

	jaf::WriteBuffer write_buffer;
	seri_data.Serialize(write_buffer, data1);
	ASSERT_EQ(write_buffer.GetWriteLen(), 125 * 4);

	jaf::ReaderBuff read_buffer(write_buffer.Data(), write_buffer.GetWriteLen());
	bool deserialize_result = seri_data.Deserialize(read_buffer, data2);
	ASSERT_TRUE(deserialize_result);

	ASSERT_EQ(data1.para_1, data2.para_1);
	ASSERT_EQ(data1.para_2, data2.para_2);
	ASSERT_EQ(data1.para_3, data2.para_3);
	ASSERT_EQ(data1.para_4, data2.para_4);
	ASSERT_EQ(data1.para_5, data2.para_5);
	ASSERT_EQ(data1.para_6, data2.para_6);
	ASSERT_EQ(data1.para_7, data2.para_7);
	ASSERT_EQ(data1.para_8, data2.para_8);
	ASSERT_EQ(data1.para_9, data2.para_9);
	ASSERT_EQ(data1.para_10, data2.para_10);
	ASSERT_EQ(data1.para_11, data2.para_11);
	ASSERT_EQ(data1.para_12, data2.para_12);
	ASSERT_EQ(data1.para_13, data2.para_13);
	ASSERT_EQ(data1.para_14, data2.para_14);
	ASSERT_EQ(data1.para_15, data2.para_15);
	ASSERT_EQ(data1.para_16, data2.para_16);
	ASSERT_EQ(data1.para_17, data2.para_17);
	ASSERT_EQ(data1.para_18, data2.para_18);
	ASSERT_EQ(data1.para_19, data2.para_19);
	ASSERT_EQ(data1.para_20, data2.para_20);
	ASSERT_EQ(data1.para_21, data2.para_21);
	ASSERT_EQ(data1.para_22, data2.para_22);
	ASSERT_EQ(data1.para_23, data2.para_23);
	ASSERT_EQ(data1.para_24, data2.para_24);
	ASSERT_EQ(data1.para_25, data2.para_25);
	ASSERT_EQ(data1.para_26, data2.para_26);
	ASSERT_EQ(data1.para_27, data2.para_27);
	ASSERT_EQ(data1.para_28, data2.para_28);
	ASSERT_EQ(data1.para_29, data2.para_29);
	ASSERT_EQ(data1.para_30, data2.para_30);
	ASSERT_EQ(data1.para_31, data2.para_31);
	ASSERT_EQ(data1.para_32, data2.para_32);
	ASSERT_EQ(data1.para_33, data2.para_33);
	ASSERT_EQ(data1.para_34, data2.para_34);
	ASSERT_EQ(data1.para_35, data2.para_35);
	ASSERT_EQ(data1.para_36, data2.para_36);
	ASSERT_EQ(data1.para_37, data2.para_37);
	ASSERT_EQ(data1.para_38, data2.para_38);
	ASSERT_EQ(data1.para_39, data2.para_39);
	ASSERT_EQ(data1.para_40, data2.para_40);
	ASSERT_EQ(data1.para_41, data2.para_41);
	ASSERT_EQ(data1.para_42, data2.para_42);
	ASSERT_EQ(data1.para_43, data2.para_43);
	ASSERT_EQ(data1.para_44, data2.para_44);
	ASSERT_EQ(data1.para_45, data2.para_45);
	ASSERT_EQ(data1.para_46, data2.para_46);
	ASSERT_EQ(data1.para_47, data2.para_47);
	ASSERT_EQ(data1.para_48, data2.para_48);
	ASSERT_EQ(data1.para_49, data2.para_49);
	ASSERT_EQ(data1.para_50, data2.para_50);
	ASSERT_EQ(data1.para_51, data2.para_51);
	ASSERT_EQ(data1.para_52, data2.para_52);
	ASSERT_EQ(data1.para_53, data2.para_53);
	ASSERT_EQ(data1.para_54, data2.para_54);
	ASSERT_EQ(data1.para_55, data2.para_55);
	ASSERT_EQ(data1.para_56, data2.para_56);
	ASSERT_EQ(data1.para_57, data2.para_57);
	ASSERT_EQ(data1.para_58, data2.para_58);
	ASSERT_EQ(data1.para_59, data2.para_59);
	ASSERT_EQ(data1.para_60, data2.para_60);
	ASSERT_EQ(data1.para_61, data2.para_61);
	ASSERT_EQ(data1.para_62, data2.para_62);
	ASSERT_EQ(data1.para_63, data2.para_63);
	ASSERT_EQ(data1.para_64, data2.para_64);
	ASSERT_EQ(data1.para_65, data2.para_65);
	ASSERT_EQ(data1.para_66, data2.para_66);
	ASSERT_EQ(data1.para_67, data2.para_67);
	ASSERT_EQ(data1.para_68, data2.para_68);
	ASSERT_EQ(data1.para_69, data2.para_69);
	ASSERT_EQ(data1.para_70, data2.para_70);
	ASSERT_EQ(data1.para_71, data2.para_71);
	ASSERT_EQ(data1.para_72, data2.para_72);
	ASSERT_EQ(data1.para_73, data2.para_73);
	ASSERT_EQ(data1.para_74, data2.para_74);
	ASSERT_EQ(data1.para_75, data2.para_75);
	ASSERT_EQ(data1.para_76, data2.para_76);
	ASSERT_EQ(data1.para_77, data2.para_77);
	ASSERT_EQ(data1.para_78, data2.para_78);
	ASSERT_EQ(data1.para_79, data2.para_79);
	ASSERT_EQ(data1.para_80, data2.para_80);
	ASSERT_EQ(data1.para_81, data2.para_81);
	ASSERT_EQ(data1.para_82, data2.para_82);
	ASSERT_EQ(data1.para_83, data2.para_83);
	ASSERT_EQ(data1.para_84, data2.para_84);
	ASSERT_EQ(data1.para_85, data2.para_85);
	ASSERT_EQ(data1.para_86, data2.para_86);
	ASSERT_EQ(data1.para_87, data2.para_87);
	ASSERT_EQ(data1.para_88, data2.para_88);
	ASSERT_EQ(data1.para_89, data2.para_89);
	ASSERT_EQ(data1.para_90, data2.para_90);
	ASSERT_EQ(data1.para_91, data2.para_91);
	ASSERT_EQ(data1.para_92, data2.para_92);
	ASSERT_EQ(data1.para_93, data2.para_93);
	ASSERT_EQ(data1.para_94, data2.para_94);
	ASSERT_EQ(data1.para_95, data2.para_95);
	ASSERT_EQ(data1.para_96, data2.para_96);
	ASSERT_EQ(data1.para_97, data2.para_97);
	ASSERT_EQ(data1.para_98, data2.para_98);
	ASSERT_EQ(data1.para_99, data2.para_99);
	ASSERT_EQ(data1.para_100, data2.para_100);
	ASSERT_EQ(data1.para_101, data2.para_101);
	ASSERT_EQ(data1.para_102, data2.para_102);
	ASSERT_EQ(data1.para_103, data2.para_103);
	ASSERT_EQ(data1.para_104, data2.para_104);
	ASSERT_EQ(data1.para_105, data2.para_105);
	ASSERT_EQ(data1.para_106, data2.para_106);
	ASSERT_EQ(data1.para_107, data2.para_107);
	ASSERT_EQ(data1.para_108, data2.para_108);
	ASSERT_EQ(data1.para_109, data2.para_109);
	ASSERT_EQ(data1.para_110, data2.para_110);
	ASSERT_EQ(data1.para_111, data2.para_111);
	ASSERT_EQ(data1.para_112, data2.para_112);
	ASSERT_EQ(data1.para_113, data2.para_113);
	ASSERT_EQ(data1.para_114, data2.para_114);
	ASSERT_EQ(data1.para_115, data2.para_115);
	ASSERT_EQ(data1.para_116, data2.para_116);
	ASSERT_EQ(data1.para_117, data2.para_117);
	ASSERT_EQ(data1.para_118, data2.para_118);
	ASSERT_EQ(data1.para_119, data2.para_119);
	ASSERT_EQ(data1.para_120, data2.para_120);
	ASSERT_EQ(data1.para_121, data2.para_121);
	ASSERT_EQ(data1.para_122, data2.para_122);
	ASSERT_EQ(data1.para_123, data2.para_123);
	ASSERT_EQ(data1.para_124, data2.para_124);
	ASSERT_EQ(data1.para_125, data2.para_125);

}
