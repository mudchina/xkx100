// /guanwai/huandi2.c

inherit ROOM;

void create()
{
	set("short", "荒路");
	set("long", @LONG
这里是城东的一条荒路，路旁杂乱地长着齐膝的荒草，远近荒无一
人。两旁干枯的老树上落满了成群的乌鸦，凄凉的鸣叫声在荒野上远远
传去，一派凄凉的景象。
LONG );
	set("exits", ([
		"southwest" : __DIR__"huandi1",
		"enter"     : __DIR__"shanshenmiao",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	set("coor/x", 6080);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}