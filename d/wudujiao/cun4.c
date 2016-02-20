// Room: /d/wudujiao/cun4.c

inherit ROOM;

void create()
{
        set("short", "小村");
        set("long", @LONG
走在小村的石板路上，两旁都是用青石砌成的房屋。村子里静悄悄的，
看不到行人，偶尔传来一两声狗叫。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "northeast" : __DIR__"cun5",
                "southeast" : __DIR__"cun6",
                "west" : __DIR__"cun3",
                "north" : __DIR__"minju3",
        ]));
        set("objects", ([
                __DIR__"npc/boy": 2,
        ]));


	set("coor/x", -44960);
	set("coor/y", -81010);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}