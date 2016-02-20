inherit ROOM;

void create()
{
	set("short", "客店");
	set("long", @LONG
这是一家价钱低廉的客店，因为地方偏僻，房客很少。不时有打斗
之声从东南边传来。掌柜早不知躲哪儿去了，屋里见不到一个人。南边
是后院，通往各厢房。
LONG );
        set("no_sleep_room",1);
	set("exits", ([
		"south" : __DIR__"kedian2",
		"northwest" : __DIR__"alley3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -220);
	set("coor/y", 4000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
