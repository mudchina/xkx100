// nroad5.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","山路");
        set("long",@LONG
这是一条崎岖的山路，马队到了这里就不能再上去了。山路两旁杂
草从生，路开始越来越难走。
LONG );
        set("exits",([
                "northdown" : __DIR__"nroad6",
                "southup"   : __DIR__"nroad1",
                "westup"    : "/d/npc/m_weapon/lianchuishi",
        ]));
        set("objects",([
                __DIR__"npc/eagle" : 2,
        ]));
        set("outdoors", "xueshan");
	set("coor/x", -30000);
	set("coor/y", -8000);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
