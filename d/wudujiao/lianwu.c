// Room: /d/wudujiao/lianwu.c

inherit ROOM;

void create()
{
        set("short", "练武场");
        set("long", @LONG
这里是院内的练武场，黄土场地上摆放着一些练功的石锁，沙袋。
一个小头目正在指导弟子练武。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "east"  : __DIR__"dating",
                "west"  : __DIR__"damen",
                "south" : __DIR__"nanyuan",
                "north" : __DIR__"beiyuan",
        ]));
        set("objects", ([
                  CLASS_D("wudujiao")+"/jiaotou": 1,
        ]));

	set("coor/x", -44920);
	set("coor/y", -81050);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}