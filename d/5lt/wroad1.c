// Room: /d/5lt/wroad1.c

inherit ROOM;

void create()
{
        set("short", "碎石路");
        set("long", @LONG
这是一个繁华的村子，一派欣欣向荣的景象。你走在一条东西向的
碎石路上，南边新开了间铺子，据说出售的都是稀罕的物件，北边有间
风格独特的民间工艺店，货架上摆放的都是一等一的工艺品。
LONG);
        set("exits", ([ /* sizeof() == 4 */
            "north" : __DIR__"gongyidian",
            "south" : __DIR__"xiaopuzi",
            "west"  : __DIR__"wroad2",
            "east"  : __DIR__"center",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "5lt");
	set("coor/x", -160);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}