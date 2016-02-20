// /d/quanzhen/xiaohebian.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "小河边");
        set("long", @LONG
此处位於终南山角一偏僻处，只见浓荫匝地，花光浮动，周围尽
是叁天古木，颇具幽静之美。不远处的小河由山洞(dong)中涌出的泉
水所形成，淙淙的水声更让你觉得身心顺畅。往北可通往山林深处。
往西可进入山洞中。
LONG
        );
        set("outdoors", "zhongnan");
        set("item_desc", ([
                "dong" : "一个深邃、幽暗、恐怖的小山洞。\n",
        ]));
        set("exits", ([
                "enter" : __DIR__"shandong1",
                "north" : __DIR__"shanlu7",
        ]));

	set("coor/x", -3160);
	set("coor/y", 0);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
