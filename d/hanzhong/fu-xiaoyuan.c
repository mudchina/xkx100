// fu-xiaoyuan 富家小院
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "富家小院");
        set("long", @LONG
这是进门后的一个小院落。西面是一道侧门，东面是一扇月
形门好象通往花厅，北面是大门，南面就是大堂了。几个穷汉正
垂头丧气地站在小院中，可能是因为缴不起租被抓来了。
LONG
        );
        set("outdoors", "hanzhong");
        set("exits", ([
                "north" : __DIR__"fu-damen",
                "south" : __DIR__"fu-datang",
                "west" : __DIR__"fu-cemen",
                "east" : __DIR__"fu-huating",
        ]));
        set("objects", ([
                __DIR__"npc/poorman" : 2,
        ]));

	set("coor/x", -3130);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}