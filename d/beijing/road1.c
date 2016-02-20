inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的、行商
的、赶着大车的马夫、上京赶考的书生，熙熙攘攘，非常热闹。不时还
有两三骑快马从身边飞驰而过，扬起一路尘埃。道路两旁是整整齐齐的
杨树林。西边就是京城东门。东北方是一条小路。
LONG );
	set("exits", ([
		"west"      : __DIR__"dongmen",
		"southeast" : __DIR__"road2",
		"northeast" : __DIR__"zhuang1",
	]));
	set("objects",([
		"/d/taishan/npc/tiao-fu" : 1,
	]));
 	set("outdoors", "huabei");
	set("coor/x", -160);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

