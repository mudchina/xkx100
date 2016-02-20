// Room: /d/heimuya/didao6.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","秘道尽头");
	set("long", @LONG
你忽觉前方一亮，身前真是别有洞天，前方好想有作花园。不知是
什么地方。
LONG );
	set("exits",([
		"north"     : __DIR__"xiaohuayuan",
		"northdown" : __DIR__"didao4",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3250);
	set("coor/y", 4200);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}