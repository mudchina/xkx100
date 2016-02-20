// wg_dating.c

inherit ROOM;

void create()
{
	set("short", "武馆大厅");
	set("long", @LONG
这里是武馆大厅，正中靠北摆着一张八仙桌，桌上供着关公的神位，
旁边放着两个青瓷花瓶，插着几支孔雀翎，墙上写着大大的一个“武”
字武馆主人早些年在江湖上闯荡，现今洗手隐退，在扬州开起了这间武
馆，往东走是个长廊，一直通向馆主的卧室。
LONG);
	set("exits", ([
		"enter"     : __DIR__"wg_lang5",
		"westdown"  : __DIR__"wg_dayuan2",
		"northdown" : __DIR__"wg_shilu-2",
		"southdown" : __DIR__"wg_shilu-1",
	]));
	set("objects", ([
		__DIR__"npc/wg_chen" : 1,
	]));
	set("coor/x", 31);
	set("coor/y", -40);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
	"/clone/board/wuguan_b"->foo();
}


