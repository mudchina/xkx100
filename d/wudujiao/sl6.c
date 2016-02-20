// Room: /d/wudujiao/sl6.c

inherit ROOM;

void create()
{
        set("short", "松树林");
        set("long", @LONG
这里是一片浓密的松树林，前面已经没有了道路，你必须不时砍断
横在你面前的枝桠。林内光线黑暗，静的能听到你自己的心跳声 ，只有
你踩在地上厚厚的松针和枯枝上发出的沙沙声。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "north" : __DIR__"sl1",
                "east" : __DIR__"sl7",
        ]));

	set("coor/x", -44940);
	set("coor/y", -81090);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}