// Room: /d/yueyang/yangyaozai.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "杨么寨");
	set("long", @LONG
杨么寨在西山，相传是南宋初年洞庭湖农民起义军领袖杨么兵营的
遗址。山寨三关依旧，寨栅仍在，当可想见当初英雄们气吞万里如虎的
气势和惊天动地的业绩。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"east" : __DIR__"jiuxiangshan",
	]));
	set("coor/x", -1790);
	set("coor/y", 2290);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
