// Room: /d/wudujiao/zhushe.c

inherit ROOM;

void create()
{
        set("short", "竹舍");
        set("long", @LONG
这是一间竹子搭成的房子，虽然简陋但却被主人收拾的干干净
净。一个羽扇纶巾，相貌清雅的文士正坐在案边闲看三国，听见
脚步声不由抬起头来。
LONG
        );

        set("exits", ([
                "north" : __DIR__"caoping",
        ]));
        set("objects", ([
                __DIR__"npc/zhuge": 1,
        ]));

	set("coor/x", -44000);
	set("coor/y", -78140);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}