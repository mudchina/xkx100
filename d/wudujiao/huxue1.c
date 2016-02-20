// Room: /d/wudujiao/huxue1.c

inherit ROOM;

void create()
{
        set("short", "虎穴");
        set("long", @LONG
这里是个隐藏在密林里的岩洞，里面腥味扑鼻，随处都是吃剩的
兽骨。几只威风凛凛的大老虎正躺在洞口懒懒的晒太阳。
LONG
        );
        set("exits", ([
                "south" : __DIR__"huxue2",
                "out"   : __DIR__"milin7",
        ]));
        set("objects", ([
                __DIR__"npc/laohu": 2,
        ]));

        set("coor/x", -45000);
	set("coor/y", -80000);
	set("coor/z", -10);
	setup();
        replace_program(ROOM);
}

