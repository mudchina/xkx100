// Room: /d/fuzhou/rongcheng2.c
// Date: Feb.14.1998 by Java
inherit ROOM;

void create()
{
	set("short", "榕城驿二楼");
	set("long", @LONG
这是一间很大的客房，陈设十分简陋。靠墙放了十几张小木床，不
少客人正和衣而卧，满屋子都是呼呼的打酣声。你看到西边有张床是空
的，就蹑手蹑脚地走了过去。
LONG );
	set_light(0);
	set("sleep_room", "1");
	set("no_fight", "1");
	set("hotel",1);
	set("no_clean_up", 0);
	set("exits", ([
	    "down" : __DIR__"rongcheng",
	]));
	set("coor/x", 1850);
	set("coor/y", -6290);
	set("coor/z", 10);
	setup();
}
int valid_leave(object me, string dir)
{
	if ( dir == "out" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}
