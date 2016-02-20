//cave.c

inherit ROOM;

void create()
{
	set("short", "湖心小洞");
	set("long",
	     "这里是潭中的一个小洞，里面零零落落的有几块石头。\n"
	);
	set("objects" , ([
		__DIR__"item/stone" : 1,
	]) );
	set("coor/x", -1510);
	set("coor/y", -1020);
	set("coor/z", -40);
	setup();
	replace_program(ROOM);
}
