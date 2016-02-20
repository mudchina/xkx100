// Room: /d/yueyang/xijiaochi.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "洗脚池");
	set("long", @LONG
仙人洗脚池在龙口东边岩下，为整块石头凹下而成，传说八仙之一
的吕洞宾曾在此洗脚。雨天积水，池底绿苔清新可人。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"northup" : __DIR__"langyinting",
	]));
	set("coor/x", -1690);
	set("coor/y", 2280);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
