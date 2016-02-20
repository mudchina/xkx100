// Room: /d/lingxiao/wuqi.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "刀剑铺");
	set("long", @LONG
这就是凌霄城的刀剑铺。走进这里，寒气侵体，好象比外面还要冷。
仔细一看，墙上挂满了大大小小、形形色色的刀剑，一柄柄寒光闪闪，
全是上品。店主轩辕苍翼看到有人进来，立刻殷勤地迎上前来。
LONG );
	set("exits", ([
		"east" : __DIR__"iceroad2",
	]));
	set("objects", ([
		__DIR__"npc/xuanyuan": 1,
	]));
	set("no_fight",1);
	set("no_steal",1);
	set("no_beg",1);
	set("coor/x", -31010);
	set("coor/y", -8910);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

