// Room: /d/wudujiao/damen.c

inherit ROOM;

void create()
{
        set("short", "五毒教大门");
        set("long", @LONG
这里是一座隐没于山林中的大宅院，高高的围墙，朱红的大门，
好象是一座有钱人家的避暑别院。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "east" : __DIR__"lianwu",
                "west" : __DIR__"wdsl7",
        ]));
        set("objects", ([
                __DIR__"npc/jiaotu": 4,
        ]));

	set("coor/x", -44930);
	set("coor/y", -81050);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}