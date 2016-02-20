// Room: /d/xingxiu/riyuedong1.c
// Last Modified by winder on Apr. 25 2001
inherit ROOM;
void create()
{
	set("short", "日月洞口");
	set("long", @LONG
这里是星宿海的尽头。说是海，其实是片湖泊和沼泽，地形十分险
恶。方圆几百里都是一望无际的湖泊和沼泽，当地牧羊人就称之为“海
”。这里左右两厢通向星宿海的深处，北边是一座小石山，星宿派总舵
日月洞便设在这里，洞口立着一个铜制牌子(paizi)。
LONG);
	set("exits", ([
		"north"     : __DIR__"riyuedong",
		"west"      : __DIR__"xxh4",
		"east"      : __DIR__"xxh3",
		"northwest" : __DIR__"xxhb2",
		"northeast" : __DIR__"xxhb1",
		"southdown" : __DIR__"huangdi",
	]));
	set("item_desc", ([
		"paizi" : "
	     星宿海福地
	     日月洞洞天。\n",
	]));
	set("objects", ([
		CLASS_D("xingxiu")+"/anran" : 1,
		CLASS_D("xingxiu")+"/first" : 1,
		__DIR__"npc/gushou" : 1,
		__DIR__"npc/haoshou" : 1,
		__DIR__"npc/boshou" : 1,
	]) );
	set("valid_startroom","1");
	set("coor/x", -50000);
	set("coor/y", 20300);
	set("coor/z", 100);
	set("outdoors", "xingxiu");
	setup();
	"/clone/board/xingxiu_b"->foo();
	replace_program(ROOM);
}

