// Room: /d/chengdu/xijie2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这里是西大街，熙熙攘攘，热闹非凡，两边是鳞立栉比的店铺，五
颜六色的幌子满街飘荡煞是鲜艳。南面有个木匠铺，听说那里的木匠手
艺很是了得。北边则是个杂货铺。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"  : __DIR__"guangchang",
		"west"  : __DIR__"xijie1",
		"south" : __DIR__"mujiangpu",
		"north" : __DIR__"zahuopu",
	]));
	set("objects", ([
		__DIR__"npc/flowergirl" : 1,
		__DIR__"npc/chike" : 1,
	]));

	set("coor/x", -8060);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

