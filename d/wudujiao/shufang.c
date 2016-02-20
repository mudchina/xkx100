// Room: /d/wudujiao/shufang.c

inherit ROOM;

void create()
{
        set("short", "书房");
        set("long", @LONG
这里是教主平时看书的地方，房间不大，只靠窗摆着一张书案，案边
放了几本书，看来是教主经常翻看的。
LONG
        );
        set("exits", ([
                "south" : __DIR__"dating",
        ]));
        set("objects", ([
                 "/clone/book/five_force": 1,
                 "/clone/book/parry_shu": 1,
        ]));

	set("coor/x", -44910);
	set("coor/y", -81040);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}