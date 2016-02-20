// fu-damen 富家大门
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "富家大门");
        set("long", @LONG
这里是汉中镇上首富--侯员外家的大门，门上挂着一块大横匾，
上面写着‘侯府’两个大字。门内立着一面朱红的影壁，模模糊糊
好象题着一些诗句之类的东西。几个横眉立眼的家丁正挺胸凸肚地
站在门口耀武扬威，看来这是一家为富不仁的乡绅劣霸。
LONG
        );
        set("exits", ([
                "north" : __DIR__"dongjie",
                "south" : __DIR__"fu-xiaoyuan",
        ]));
        set("objects", ([
                __DIR__"npc/jiading" : 3,
        ]));

	set("coor/x", -3130);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}