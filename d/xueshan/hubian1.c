//      hubian1.c 湖边小路

inherit ROOM;

void create()
{
        set("short","湖边小路");
        set("long",@LONG
这是圣湖边的小路。路侧的湖水极为清澈。阳光下映着白顶雪山显
出一片蓝幽幽的宁静。
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "east" : __DIR__"hubian2",
                "west" : __DIR__"shenghu",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -30010);
	set("coor/y", -8010);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
