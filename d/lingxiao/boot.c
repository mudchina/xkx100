// Room: /d/lingxiao/boot.c
// Last Modified by winder on Jul. 15 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","山路");
	set("long",@LONG
这里是一座大山的山麓，抬头仰望，山上积雪皑皑，在日光下映得
闪烁生辉。山上云海迷茫，雪峰林立，阳光交辉在白云与飞雪之间，隐
隐能看见有一座城在山顶。路旁有一块木板(sign)。
LONG ); 
	set("item_desc", ([
		"sign": HIG"万古"+HIC"凌霄"+HIW"一羽毛"NOR+"\n"
	]) );
	set("exits",([
		"southeast"  : "/d/xuedao/sroad3",
		"westup"  : __DIR__"sroad1",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 2,
	]));
	set("outdoors", "lingxiao");
	set("coor/x", -31000);
	set("coor/y", -9000);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}

