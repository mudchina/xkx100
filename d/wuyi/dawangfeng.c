// Room: /d/wuyi/dawangfeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "大王峰");
	set("long", @LONG
大王峰又称纱帽峰，山形如宦者纱帽，独具王仪而得名。此山为入
武夷第一峰。四周悬崖壁立，上丰下敛，气势雄浑。远远望去，宛若擎
天巨柱，与玉女遥遥相望。石壁上刻有“居高思危”四字赫然在目，令
人触景生情，浮想联翩，直指人心。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"path3",
		"southdown" : __DIR__"path1",
	]));
	set("objects", ([
		"/d/taishan/npc/jian-ke" : 1,
	]));
	set("coor/x", 1390);
	set("coor/y", -4990);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

