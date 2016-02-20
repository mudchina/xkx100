// Room: /xiakedao/shidong2.c

inherit ROOM;

void create()
{
        set("short", "石洞");
        set("long", @LONG
这是一个石洞，四周点着八盏油灯，使得整个房间非常明亮。
山洞中支路甚多，你可要小心，别走错了路。
LONG );
        set("exits", ([
                "east" : __DIR__"shidong3",
                "west" : __FILE__,
                "south" : __FILE__,
                "north" : __DIR__"yingbin",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3080);
	set("coor/y", -22090);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}