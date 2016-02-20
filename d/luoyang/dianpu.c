// Room: /d/luoyang/dianpu.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "店铺");
	set("long",  @LONG
这里是一家专门售卖唐三彩的店铺。传说洛阳的唐三彩非常出名，
拿到京城去卖常常供不应求。经历了多年的战乱，店主似乎只注意生意
而不再关心当前局势如何，但求能在这乱世之中保住这一间店铺。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"southroad",
		"north" :  __DIR__"westroad",
	]));
	set("objects",  ([  /*  sizeof()  ==  2  */
		__DIR__"npc/dianzhu" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -600);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
