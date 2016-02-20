// Room: /d/taishan/xiaodongtian.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "小洞天");
	set("long", @LONG
红门宫东北深涧内，就是小洞天。这里片石如几，厚五尺，方圆丈
许。此处一壑曲绕，清溪碧潭，山林涧草，森森蔓蔓，别有洞天。南侧
有明代知泰安州事甘应甲题、范广书“小洞天”。谷底断崖层叠，横瀑
飞流，自北而南有柳条、饮马、石峡三湾。谷侧多圆柱形铁黑色巨石，
横断面层层包裹，似枯木年轮，上刻“醉心”。
LONG );
	set("exits", ([
		"southwest" : __DIR__"hongmen",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 410);
	set("coor/y", 560);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
