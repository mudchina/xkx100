// Room: /d/wudujiao/bianzhai2.c

inherit ROOM;

void create()
{
        set("short", "边寨风情");
        set("long", @LONG
这里已是苗疆地界，只觉得山清水秀，风景与中原大不相同。
走在路上，不时会碰到少男少女在路边田野里载歌载舞，顿觉心
情舒畅，但愿终老此乡。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "east" : __DIR__"bianzhai1",
                "south" : __DIR__"bianzhai3",
        ]));
        set("objects", ([
                 __DIR__"npc/younggirl": 2,
                 __DIR__"npc/youngboy": 1,
        ]));

	set("coor/x", -46010);
	set("coor/y", -81000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}