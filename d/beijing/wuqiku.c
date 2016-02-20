inherit ROOM;

void create()
{
	set("short", "武器库");
	set("long", @LONG
这里是武器库，架上摆满了各种武器，任由武士门挑选。
LONG );
	set("exits", ([
		"east" : __DIR__"kang2",
	]));
	set("objects", ([
		"/d/city/obj/zhubang" : 2,
		"/d/city/obj/duanjian" : 1,
		WEAPON_DIR"sword/zhujian" : 1,
		WEAPON_DIR"changjian" : 1,
		WEAPON_DIR"changbian" : 1,
		WEAPON_DIR"gangdao" : 1,
		WEAPON_DIR"whip/fuchen" : 1,
	]));
	set("coor/x", -181);
	set("coor/y", 4090);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
