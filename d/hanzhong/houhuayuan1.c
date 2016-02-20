// houhuayuan1.c 后花园
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "后花园");
        set("long", @LONG
这是一片荒废了的花园，本来这里有一片小池塘，养着一些
金鱼之类，现在池塘差不多也干涸了。池塘边立着一座假山，山
上长满了青苔，看来已经很久没有人来过了。
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "west" : __DIR__"houhuayuan",
        ]));
        set("objects", ([
                __DIR__"npc/wugui" : 1,
        ] ));

	set("coor/x", -3110);
	set("coor/y", -60);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}