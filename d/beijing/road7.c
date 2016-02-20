inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的、行商
的、赶着大车的马夫、上京赶考的书生，熙熙攘攘，非常热闹。不时还
有两三骑快马从身边飞驰而过，扬起一路尘埃。道路两旁是整整齐齐的
杨树林。
LONG );
	set("exits", ([
		"east"      : __DIR__"road4",
		"northwest" : __DIR__"road6",
	]));
	set("objects", ([
		"/d/huashan/npc/haoke" : 1,
	]));
 	set("outdoors", "huabei");
	set("coor/x", 0);
	set("coor/y", 3200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

