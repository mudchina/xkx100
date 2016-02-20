// Room: /d/suzhou/tulu2.c
// Last Modified by Winder on May. 15 2001

inherit ROOM;

void create()
{
        set("short", "土路");
        set("long",@long
你来到了一条土路上。西南边有条江，远远看去不甚宽阔。往东北
边走可以找到是去苏州的官道。
long);
	set("outdoors", "suzhou");
	set("exits",([
		"northeast" : __DIR__"tulu1",
		"southwest" : __DIR__"jiangbian",
	]));
	set("no_clean_up", 0);
	set("coor/x", 780);
	set("coor/y", -1030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
