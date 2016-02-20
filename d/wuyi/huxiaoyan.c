// Room: /d/wuyi/huxiaoyan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "虎啸岩");
	set("long", @LONG
这里是武夷山屈指可数的独具泉天趣的佳境之一。所谓「虎啸」出
于古时有仙，曾骑虎啸于岩上的典故。虎啸岩上有个巨洞每当山风掠过
该洞，该洞就会发出近似虎啸之声。声小之时，只能穿耳闪过，宏亮之
时，却可声震群山，令人毛骨悚然。抵达虎啸岩下，抬头望岩，首先映
入眼帘是「虎溪灵洞」四个大字高勒岩壁，向来往的游人提示：危崖高
耸，岌岌可危，幽深景观，虎啸神奇。李纲游览虎啸岩，题诗：「昔年
雕虎啸幽岩，千里清风皱碧潭。」
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"north"   : __DIR__"jingtai",
		"south"   : __DIR__"path6",
		"southup" : __DIR__"tiancheng",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1390);
	set("coor/y", -5030);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

