// Room: /d/wudujiao/xiaodian.c

inherit ROOM;

void create()
{
        set("short", "路边小店");
        set("long", @LONG
这是一家山野小店，供应一些食物和时鲜山货。这里行人稀
少，大概一天也没几个人路过这里，老板娘把店开在这里恐怕是
要赔了。店内进是一间客房，行人累了可以进去休息。
LONG
        );

        set("exits", ([
                "east" : __DIR__"shanlu1",
                "west" : __DIR__"neijin",
        ]));
        set("objects", ([
                __DIR__"npc/sun": 1,
        ]));

	set("coor/x", -45010);
	set("coor/y", -79000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}