// Room: /d/suzhou/hehuating.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "荷花厅");
	set("long", @LONG
荷花厅的主建筑面阔三间，宽敝高爽，厅名取宋时朱熹：“一水方
涵碧，千林以变红”之诗意。厅前宽广的平台依临荷池，为夏日赏荷纳
凉胜处，故称“荷花厅”。厅后有花台庭院，叠石种树，自成一景。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"liuyuan",
		"west"  : __DIR__"gumujiaohe",
	]));
	set("coor/x", 830);
	set("coor/y", -1040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
