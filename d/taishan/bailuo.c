// Room: /d/taishan/bailuo.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "白骡冢");
	set("long", @LONG
红门宫东出跨溪而南是白骡冢。传唐玄宗登泰山时乘白骡，礼毕下
山至此，骡累死，遂封“白骡将军”，并备棺垒石为冢。现冢无存，仅
留石碑，传为白骡冢碑。
LONG );
	set("exits", ([
		"northwest" : __DIR__"mileyuan",
	]));
	set("resource/water",1);
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 420);
	set("coor/y", 540);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
