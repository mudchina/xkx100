// Room: /d/wudujiao/beiyuan.c

inherit ROOM;

void create()
{
        set("short", "北院");
        set("long", @LONG
这里是北院，院子里静悄悄的。北面有一个厨房，远远飘来一
股饭香，想是该开饭了。
LONG
        );
        set("outdoors", "wudujiao");
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"bingqi",
                "south" : __DIR__"lianwu",
                "north" : __DIR__"chufang",
        ]));

	set("coor/x", -44920);
	set("coor/y", -81040);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}