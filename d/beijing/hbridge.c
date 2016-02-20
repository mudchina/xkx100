inherit ROOM;
int do_out(string arg);

void create()
{
        set("short", "筒子桥");
        set("long", @LONG
这是一座破旧的石桥，桥下是护城河缓缓的流水。水看上去很清，
这里是进皇宫后门的必经之路。
LONG);
        set("outdoors", "beijing");
        set("exits", ([
                "north" : __DIR__"di_anmen",
                "south" : "/d/huanggong/jingshan",
        ]));
	set("no_clean_up", 0);
	set("coor/x", -250);
	set("coor/y", 5270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
