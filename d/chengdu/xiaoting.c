// Room: /d/chengdu/xiaoting.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "小亭");
	set("long",@LONG
这里是个修筑精致的小亭，游人们到了这里，总喜欢进来乘凉，这
里凉风习习，且可抚览府河美景，不亦快哉！
LONG
	);
	set("outdoors", "chengdu");
	set("exits", ([
		"southwest" : __DIR__"funanhe2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8030);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}


