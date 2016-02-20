// Room: /d/wudujiao/cun2.c

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
	set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"cun3",
                "south" : __DIR__"minju1",
                "west" : __DIR__"cun1",
        ]));

	set("coor/x", -44980);
	set("coor/y", -81010);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}