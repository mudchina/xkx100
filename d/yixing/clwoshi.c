// /d/yixing/clwoshi.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "卧室");
	set("long", @LONG
室内陈设甚是奢华，极大的床边有张朱漆书桌，桌旁两张椅子，上
铺锦垫。床前罗帐低垂，隐约看见床上似乎无人。窗前的香炉中青烟袅
袅，你只觉置身于一个香喷喷，软绵绵的神仙洞府。
LONG );
	set("exits", ([
		"south" : __DIR__"clxiaoting",
	]));
	set("objects",([
		__DIR__"npc/cl_shijian" : 1,
	]));
	setup();

	replace_program(ROOM);
}
