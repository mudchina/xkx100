// Room: /d/lingxiao/ting.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM; 
#include <ansi.h>
void create()
{
	set("short", "戏梅亭");
	set("long",@LONG 
这里是凌霄城的戏梅亭，是凌霄城主白自在平时最喜欢来的地方。
从这里俯瞰群山，披襟当风，只觉万里江山，不如金樽一醉。在厅柱上
刻着一句诗(poem)，是白老爷子酒后性至，仗剑所留。但有人却说白老
爷子生平最是好名，这样说是自己打自己嘴巴，可也没人正直到敢在白
老爷子面前讥讽半句。
LONG);
	set("exits", ([
		"west" : __DIR__"meiroad3",
	])); 
	set("objects", ([ 
		__DIR__"obj/ban" : 3,
	])); 
	set("item_desc", ([
		"poem" : "忍把浮名，换了浅酌低唱。\n",
	]) );
	set("outdoors", "lingxiao");
	set("coor/x", -30980);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

