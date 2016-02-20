// wg_dayuan2.c

inherit ROOM;

void create()
{
	set("short", "武馆大院");
	set("long", @LONG
这是武馆前的大院子，馆内的弟子忙碌地进出着，东面上了台阶就
是武馆大厅。
LONG);
	set("outdoors", "wuguan");
	set("no_fight", 1);
	set("exits", ([
		"west" : __DIR__"wg_dayuan",
		"eastup" : __DIR__"wg_dating",
	]));
	set("objects", ([
		__DIR__"npc/wg_zhangfeng" : 1,
		__DIR__"npc/wg_taishandizi" : 1,
		__DIR__"npc/wg_tdhbangzhong" : 1,
	]));
	set("coor/x", 21);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

