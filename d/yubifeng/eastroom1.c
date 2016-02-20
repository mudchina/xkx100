// /yubifeng/eastroom1.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "剑房");
	set("long", @long
这里原是杜庄主藏剑纳宝之所。数十年来，他在这里穷极山野，一
无所获，这里也就徒有四壁了。
long );
	set("exits", ([
		"west" : __DIR__"zoulang4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 6140);
	set("coor/y", 5190);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
