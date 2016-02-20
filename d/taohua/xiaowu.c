inherit ROOM;

void create()
{
	set("short", "仆人房");
	set("long", @LONG
这是专供仆人休息的小屋。屋里放着五六张床，挤挤地占掉了屋子
的一大半地方。屋角很散乱地放了一些日常生活用具。中央放着一张桌
子，上面摆一茶壶和几个杯子。
LONG );
	set("exits", ([
		"north"  : __DIR__"lianwuchang",
	]));
	set("objects", ([
		__DIR__"npc/puren" : 1,
	]) );    

	set_light(0) ;
	set("sleep_room","1") ;
	set("coor/x", 8980);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}