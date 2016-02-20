// /kaifeng/wroad2.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
开封府内西面的主要交通要道，街道两边店铺林立，行人车马如梭。
商贩的吆喝，市民与小贩的讨价还价喧闹无比。西面就是延庆观，东面
可以上到角楼。
LONG);
	set("objects", ([
		__DIR__"npc/qigai" : 1,
	]));
	set("outdoors", "kaifeng");
	set("exits", ([
		"west"   : __DIR__"yanqing",
		"eastup" : __DIR__"jiaolou1",
		"north"  : __DIR__"wroad3",
		"south"  : __DIR__"wroad1",
	]));

	setup();
	replace_program(ROOM);
}
