// majiu.c 马厩
inherit ROOM;
void create()
{
        set("short", "马棚");
        set("long", @LONG
这是个大马棚，支起来的帐篷有十多丈长，里面拴着几百匹骏马。马
虽多，却是安安分分的，偶尔有几声嘶叫声，看来草原族的驯马之术的确
高明。一堆人正在旁边和马棚主人商讨价钱，看他们的服饰好象是从遥远
的波斯而来。
LONG);
        set("resource/water", 1);
        set("exits", ([
            "north" : __DIR__"caoyuan1",
            "east" : __DIR__"hsk",            
        ]));
        set("objects", ([
                    __DIR__"npc/xiaoxiang" : 1,
                    "/d/xingxiu/npc/trader" : 2
        ])); 
        set("outdoors", "hasake");        
        setup();
        replace_program(ROOM);
}
