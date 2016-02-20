// Room: /d/yueyang/longwangmiao.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "龙王庙");
	set("long", @LONG
龙王庙建在香炉山上。香炉山原名鸡子山，似形而名。君山为佛之
胜地，山上建有龙王庙，但是凡贱民不能登山朝拜，只能行舟于鸡子山
下，隔山朝拜，烧香祈祷平安。由于天长地久，水石相搏，鸡子山也就
越来越小了，钏灵毓秀，山势形如香炉，人们又经常烧香，所以就称为
香炉山了。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"xianglushan",
	]));
	set("coor/x", -1790);
	set("coor/y", 2260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
