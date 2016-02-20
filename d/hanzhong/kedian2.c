// kedian2.c
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "客店二楼");
        set("long", @LONG
这是一间很大的客房，陈设十分简陋。靠墙放了十几张小木床，
不少客人正和衣而卧，满屋子都是呼呼的打酣声。西边有张床是空的，
你蹑手蹑脚地走了过去。
LONG
        );
        set("sleep_room", "1");
        set("no_fight", "1");
        set("hotel",1);
        set("no_clean_up", 0);
        set("exits", ([
                "down" : __DIR__"kedian1",
        ]));

	set("coor/x", -3130);
	set("coor/y", 0);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
        if ( dir == "down" ) me->delete_temp("rent_paid");

        return ::valid_leave(me, dir);
}