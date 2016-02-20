// fu-zhangfang 帐房
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "帐房");
        set("long", @LONG
这里是侯员外家的帐房。屋内青砖铺地，进门处横摆着一张桌
子，一个管家正坐在桌后，小眼睛不住地跟着你转，好象又在打什
么坏主意。
LONG
        );
        set("exits", ([
                "east" : __DIR__"fu-datang",
        ]));
        set("objects", ([
                __DIR__"npc/guanjia" : 1,
        ]));

	set("coor/x", -3140);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}