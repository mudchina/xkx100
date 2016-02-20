// Room: /d/qilian/yongchang.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "永昌");
	set("long", @LONG
永昌以北是一片大沙漠，再往北就是蒙古了，永昌就建在这戈壁滩
上。孤零零一座城堡独立沙中，一股凄凉之情不由在你心中油然而生。
LONG );
	set("outdoors", "qilian");
	set("no_clean_up", 0);
	set("exits", ([
		"southup" : __DIR__"zhutishan",
	]));
	set("coor/x", -5000);
	set("coor/y", 11000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}