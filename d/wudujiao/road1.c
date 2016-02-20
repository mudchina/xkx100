// Room: /d/wudujiao/road1.c

inherit ROOM;

void create()
{
        set("short", "黄土大道");
        set("long", @LONG
这是一条向南的黄土大道，两旁是一片片绿油油的水田
和悠闲的牧童。大道上人流熙熙攘攘，过往的行人顶着炎炎烈
日满头大汗的匆匆赶路，似乎并无心欣赏这优美的田园风光。
LONG
        );
        set("outdoors", "wudujiao");
	set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"road2",
                "north" : "/d/dali/luyuxi",
        ]));

	set("coor/x", -45000);
	set("coor/y", -76000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}