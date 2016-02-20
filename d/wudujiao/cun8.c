// Room: /d/wudujiao/cun8.c

inherit ROOM;

void create()
{
        set("short", "村东口");
        set("long", @LONG
这里是小村的东头。因为暴雨刚过，地上一片泥泞，路非常不好走。顺
着这条路一直向东走一两个时辰就可到青石坪了，那里是这附近最大的镇子。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "northwest" : __DIR__"cun7",
        ]));

	set("coor/x", -44930);
	set("coor/y", -81020);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}