// Room: /d/baituo/jiudian.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "酒店");
	set("long", @LONG
这里是一家独具特色的酒店，由于地处『白驼山』下，酒店可以供
应风味食品－－蛇肉。许多中原来客都爱来尝尝鲜，所以酒店生意兴隆。
酒店还经营打散装酒的业务。
LONG	);
	set("exits", ([
		"south" : __DIR__"xijie",
	]));
	set("objects",([
		__DIR__"npc/xiaoer" : 1,
	]));
	set("resource/water", 1);
	set("coor/x", -49990);
	set("coor/y", 19990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

