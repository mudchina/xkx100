// Room: /d/wudujiao/langwo.c

inherit ROOM;

void create()
{
        set("short", "狼窝");
        set("long", @LONG
这里是密林中的一个大树洞，里面腥味扑鼻，随处都是吃剩的
兽骨。几只瘦得皮包骨头的饿狼正抖擞精神，似乎要出去觅食了。
LONG
        );

        set("exits", ([
                "out" : __DIR__"milin4",
        ]));
        set("objects", ([
                __DIR__"npc/wolf1": 2,
                __DIR__"npc/wolf2": 1,
        ]));

	set("coor/x", -45000);
	set("coor/y", -80100);
	set("coor/z", -10);
	setup();
        replace_program(ROOM);
}