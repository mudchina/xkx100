// Room: /d/yueyang/kedian2.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "牡丹楼二楼");
	set("long", @LONG
你正走在牡丹楼二楼的走廊上，可以听到从客房里不时地呼呼的打
酣声，一阵高过一阵。不时有睡意朦胧的旅客进进出出，到楼下的掌柜
处付了钱再上来睡觉。
LONG );
	set("exits", ([
		"down"  : __DIR__"kedian",
		"enter" : __DIR__"kedian3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1400);
	set("coor/y", -2280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
