// fu-cemen 富家侧门
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "富家侧门");
        set("long", @LONG
这里是一道小门，可能是由于怕进出不方便而修建的。门虽
然小，但还修饰得人模人样，门上嵌着两个大铜环。几条大狼狗
懒洋洋躺在门边，一看见有人进来就‘汪汪’地乱吠。出了门就
是汉中镇的南街了，进门后是富家的小院。
LONG
        );
        set("exits", ([
                "northwest" : __DIR__"nanjie",
                "east" : __DIR__"fu-xiaoyuan",
        ]));
        set("objects", ([
                __DIR__"npc/wolfdog" : 2,
        ]));
	set("coor/x", -3140);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}